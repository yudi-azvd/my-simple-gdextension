#!/usr/bin/env python
import os
import sys

env = SConscript("godot-cpp/SConstruct")

# For the reference:
# - CCFLAGS are compilation flags shared between C and C++
# - CFLAGS are for C-specific compilation flags
# - CXXFLAGS are for C++-specific compilation flags
# - CPPFLAGS are for pre-processor flags
# - CPPDEFINES are for pre-processor defines
# - LINKFLAGS are for linking flags

godot_headers_path = "godot-cpp/godot-headers/"
cpp_bindings_path = "godot-cpp/"
cpp_library = "godot-cpp"

env.Append(CPPPATH=['.', godot_headers_path, 
    cpp_bindings_path + 'include/', 
    cpp_bindings_path + 'include/core/', 
    cpp_bindings_path + 'include/gen/', 
    # Added
    cpp_bindings_path + 'gen/include/',
    cpp_bindings_path + 'gen/include/godot_cpp/classes/',
])


# tweak this if you want to use different folders, or more folders, to store your source code in.
# env.Append(CPPPATH=["src/"])
sources = Glob("src/*.cpp")

if env["platform"] == "macos":
    library = env.SharedLibrary(
        "demo/bin/osx/libmysimplegdextension.{}.framework".format(
            env["platform"],
        ),
        source=sources,
    )
elif env["platform"] == "windows":
    library = env.SharedLibrary(
        "demo/bin/win64/libmysimplegdextension.{}.{}{}".format(env["platform"], env["arch"], env["SHLIBSUFFIX"]),
        source=sources,
    )
else:
    library = env.SharedLibrary(
        "demo/bin/linux/libmysimplegdextension.{}.{}{}".format(env["platform"], env["arch"], env["SHLIBSUFFIX"]),
        source=sources,
    )

Default(library)