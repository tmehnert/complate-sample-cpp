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
#include "errorcontroller.h"
#include <sstream>

using namespace std;
using namespace httplib;

/* Very hacky, but should help the user to find the error */
void ErrorController::error500(const Request&, Response& res, exception& e) {
  /* Just to give you a hint, where you can solve the problem */
  stringstream ss;
  ss << "<!DOCTYPE html>"
     << "<html>"
     << "<head>"
     << "<title>Oh no!</title>"
     << R"(<meta charSet="UTF-8">)"
     << R"(<link rel="stylesheet" href="https://cdn.jsdelivr.net/npm/bootstrap@5.1.3/dist/css/bootstrap.min.css" integrity="sha384-1BmE4kWBq78iYhFldvKuhfTAU6auU8tT94WrHftjDbrCEXSU1oBoqyl2QvZ6jIW3" crossOrigin="anonymous">)"
     << "<head>"
     << "<body>"
     << R"(<nav class="navbar navbar-dark bg-dark p-2">)"
     << R"(<a class="navbar-brand" target="_blank" href="https://github.com/tmehnert/complate-sample-cpp">complate-sample-cpp</a>)"
     << "</nav>"
     << R"(<main class="container mt-5">)"
     << "<h1>Oh no! Looks like an error in JSX</h1>"
     << R"(<div class="alert alert-danger" role="alert">)" << e.what() << "</div>"
     << "<p>Your 'npm start' output may also help you.</p>"
     << "</body>"
     << "</html>";
  res.body = ss.str();
  res.status = 500;
  res.set_header("Content-Type", "text/html");
}
