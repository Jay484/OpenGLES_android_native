package com.example.opengles_android_native.openglsdk

import android.content.Context
import android.opengl.GLSurfaceView

class MGLSurfaceView(context: Context) : GLSurfaceView(context) {

    init {
        setEGLConfigChooser(redSize, greenSize, blueSize, alphaSize, depthSize, stencilSize)
        setEGLContextClientVersion(3)
        setRenderer(MGLRenderer())
    }

    companion object{
        val redSize = 8
        val greenSize = 8
        val blueSize = 8
        val alphaSize = 8
        val depthSize = 16
        val sampleSize = 4
        val stencilSize = 0
        val value = IntArray(1)
    }

}