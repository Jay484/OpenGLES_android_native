package com.example.opengles_android_native.openglsdk

class NativeCode {

    companion object {
        // Used to load the 'opengles_android_native' library on application startup.
        init {
            System.loadLibrary("opengles_android_native")
        }
        external fun init(width: Int, height: Int)
        external fun step()
    }
}