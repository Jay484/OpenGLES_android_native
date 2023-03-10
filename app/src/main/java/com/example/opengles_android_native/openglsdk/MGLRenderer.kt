package com.example.opengles_android_native.openglsdk

import android.opengl.GLSurfaceView.Renderer
import javax.microedition.khronos.egl.EGLConfig
import javax.microedition.khronos.opengles.GL10

class MGLRenderer : Renderer {
    override fun onSurfaceCreated(gl: GL10?, config: EGLConfig?) {
    }

    override fun onSurfaceChanged(gl: GL10?, width: Int, height: Int) {
        NativeCode.init(width, height)
    }

    override fun onDrawFrame(gl: GL10?) {
        NativeCode.step()
    }
}