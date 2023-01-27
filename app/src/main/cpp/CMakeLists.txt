# For more information about using CMake with Android Studio, read the
# documentation: https://d.android.com/studio/projects/add-native-code.html

# Sets the minimum version of CMake required to build the native library.

cmake_minimum_required(VERSION 3.18.1)

# Declares and names the project.

project("opengles_android_native")

# Creates and names a library, sets it as either STATIC
# or SHARED, and provides the relative paths to its source code.
# You can define multiple libraries, and CMake builds them for you.
# Gradle automatically packages shared libraries with your APK.

add_library( # Sets the name of the library.
        opengles_android_native

        # Sets the library as a shared library.
        SHARED

        # Provides a relative path to your source file(s).
        base/native-lib.cpp
        triangle/triangle.cpp
        )


# Specifies libraries CMake should link to your target library. You
# can link multiple libraries, such as libraries you define in this
# build script, prebuilt third-party libraries, or system libraries.

target_link_libraries( # Specifies the target library.
        opengles_android_native

        # Links the target library to the log library
        # included in the NDK.
        android
        EGL
        GLESv2
        log
        m
        )

include_directories(vender/glm triangle base)