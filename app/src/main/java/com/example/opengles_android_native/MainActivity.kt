package com.example.opengles_android_native

import androidx.appcompat.app.AppCompatActivity
import android.os.Bundle
import android.util.Log
import com.example.opengles_android_native.openglsdk.MGLSurfaceView

class MainActivity : AppCompatActivity() {
    lateinit var glSurfaceView: MGLSurfaceView

    override fun onCreate(savedInstanceState: Bundle?) {
        super.onCreate(savedInstanceState)
        Log.i(logTag, "Creating new surface view")
        glSurfaceView = MGLSurfaceView(application)
        setContentView(glSurfaceView)
    }

    override fun onPause() {
        super.onPause()
        glSurfaceView.onPause()
    }

    override fun onResume() {
        super.onResume()
        glSurfaceView.onResume()
    }

    companion object{
        private const val logTag = "Graphics Setup"
    }
}