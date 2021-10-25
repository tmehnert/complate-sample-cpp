/**
 * Copyright 2021 Torsten Mehnert
 *
 *  Licensed under the Apache License, Version 2.0 (the "License");
 *  you may not use this file except in compliance with the License.
 *  You may obtain a copy of the License at
 *
 *      http://www.apache.org/licenses/LICENSE-2.0
 *
 *  Unless required by applicable law or agreed to in writing, software
 *  distributed under the License is distributed on an "AS IS" BASIS,
 *  WITHOUT WARRANTIES OR CONDITIONS OF ANY KIND, either express or implied.
 *  See the License for the specific language governing permissions and
 *  limitations under the License.
 */
#include <complate/core/reevaluatingrenderer.h>
#include <complate/quickjs/quickjsrendererbuilder.h>
#include <complate/core/prototypebuilder.h>

#include <atomic>

#include "httplib.h"
#include "resources.h"
#include "person.h"
#include "errorcontroller.h"

using namespace std;
using namespace complate;

int main() {
  // clang-format-off
  atomic<uint32_t> visits = 0;
  auto bindings = Object{
      {"getProfileVisits", Function{[&visits] { return ++visits; }}}
  };
  auto prototype = PrototypeBuilder<Person>("Person")
      .property("forename", &Person::forename)
      .property("lastname", &Person::lastname)
      .property("email", &Person::email)
      .build();

  auto renderer = ReEvaluatingRenderer(QuickJsRendererBuilder()
      .source(Resources::readViews)
      .bindings(bindings)
      .prototypes({prototype})
      .creator()
  );
  // clang-format on

  httplib::Server server;
  server.set_exception_handler(ErrorController::error500);
  server.Get("/", [&](auto &, auto &res) {
    /* Define some data passed to the view */
    auto person = make_shared<Person>("John", "Doe", "john.doe@example.org");
    Object parameters;
    parameters.emplace("person", Proxy{"Person", person});

    /* Render Greeting, found at (views/greeting.jsx) */
    res.body = renderer.renderToString("Profile", parameters);
    res.status = 200;
    res.set_header("Content-Type", "text/html");
  });

  cout << "Starting server at http://localhost:8080" << endl;
  server.listen("127.0.0.1", 8080);
  return EXIT_SUCCESS;
}
