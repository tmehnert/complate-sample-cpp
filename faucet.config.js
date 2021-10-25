"use strict";

let templateDir = "./views";

module.exports = {
    watchDirs: [templateDir],
    js: [{
        source: templateDir + "/index.js",
        target: "./dist/views.js",
        exports: "render",
        esnext: {
            exclude: [ "complate-stream" ]
        },
        jsx: { pragma: "createElement" }
    }]
};