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

# tweak this if you want to use different folders, or more folders, to store your source code in.
env.Append(CPPPATH=["src/"])
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