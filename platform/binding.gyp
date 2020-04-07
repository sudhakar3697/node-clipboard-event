{
    "targets": [
        {
            "cflags!": ["-fno-exceptions"],
            "cflags_cc!": ["-fno-exceptions"],
            "include_dirs": [
                "<!@(node -p \"require('node-addon-api').include\")"
            ],
            "defines": ["NAPI_DISABLE_CPP_EXCEPTIONS"],
            "conditions": [
                ['OS=="win"', {
                    "sources": ["addon-win.cc"],
                }],
                ['OS=="linux"', {
                    "sources": ["addon-linux.cc"],
                    "libraries": ["-lX11", "-lXfixes"]
                }]
            ]
        }
    ]
}
