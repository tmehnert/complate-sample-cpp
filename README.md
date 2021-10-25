# complate-sample-cpp

*- Sample project for using [complate-cpp](https://github.com/tmehnert/complate-cpp)*

[![Build](https://github.com/tmehnert/complate-sample-cpp/actions/workflows/build.yml/badge.svg)](https://github.com/tmehnert/complate-sample-cpp/actions/workflows/build.yml)
[![License](https://img.shields.io/badge/License-Apache%202.0-blue.svg)](LICENSE)

## User Guide

For a detailed description how to use complate-cpp checkout out
the [User Guide](https://github.com/tmehnert/complate-cpp/blob/main/USER_GUIDE.md).

## Run the example

To run this example, run the following commands. It will start a local webserver on [localhost](http://localhost:8080/)
and serve a profile example. If you want to play around a bit, look at the [views/profile.jsx](views/profile.jsx)
file, this is the view which is rendered. Because of this example uses a ReEvaluatingRenderer, you can edit the view and
see your changes right after refreshing your browser, with no need to restart the application itself.

```shell
# Install dependencies
sudo apt install -y build-essential git cmake nodejs npm

# Clone repository
git clone https://github.com/tmehnert/complate-sample-cpp.git
cd complate-sample-cpp

# Build example
cmake -B build
cmake --build build -j4

# Run in another terminal and keep npm start running
npm install
npm start

# Run the example
build/src/complate-sample
```

### Dependencies

* [complate-cpp](https://github.com/tmehnert/complate-cpp), Apache 2.0 (fetched via CMake)
* [cpp-httplib](https://github.com/yhirose/cpp-httplib), MIT License (fetched via CMake)

#### Dev dependencies

* Node.js
* CMake >= 3.14 required

## License

complate-sample-cpp is Open Source software released under the [Apache 2.0 license](LICENSE).
