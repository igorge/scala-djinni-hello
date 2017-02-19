#!/bin/sh
djinni  --idl src/main/idl/hello_world.djinni   \
        --java-out src/main/java/generated/     \
        --jni-out src/main/cpp/generated/jni    \
        --cpp-out src/main/cpp/generated/       \
        --java-package gie                      \
        --cpp-namespace gie \
         --jni-include-prefix "generated/jni/" \
         --jni-include-cpp-prefix "generated/"

