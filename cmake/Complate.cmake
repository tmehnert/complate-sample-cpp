# Copyright 2021 Torsten Mehnert
#
# Licensed under the Apache License, Version 2.0 (the "License");
# you may not use this file except in compliance with the License.
# You may obtain a copy of the License at
#
#      http://www.apache.org/licenses/LICENSE-2.0
#
#  Unless required by applicable law or agreed to in writing, software
#  distributed under the License is distributed on an "AS IS" BASIS,
#  WITHOUT WARRANTIES OR CONDITIONS OF ANY KIND, either express or implied.
#  See the License for the specific language governing permissions and
#  limitations under the License.
Include(FetchContent)

message("-- Fetching complate...")
FetchContent_Declare(
    complate
    GIT_REPOSITORY https://github.com/tmehnert/complate-cpp.git
    GIT_TAG HEAD
    GIT_SHALLOW 1
)

FetchContent_MakeAvailable(complate)
message("-- Fetching complate - done")