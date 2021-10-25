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
#include "person.h"

#include <utility>

using namespace std;

Person::Person(string forename, string lastname, string email)
    : m_forename(move(forename)),
      m_lastname(move(lastname)),
      m_email(move(email)) {}

const std::string& Person::forename() const { return m_forename; }
const std::string& Person::lastname() const { return m_lastname; }
const std::string& Person::email() const { return m_email; }
