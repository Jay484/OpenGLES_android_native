#include <jni.h>
#include <android/log.h>
#include <unistd.h>
#include <base.h>
#include <triangle.h>

#define LOG_TAG "libNative"

extern "C"
JNIEXPORT void JNICALL
Java_com_example_opengles_1android_1native_openglsdk_NativeCode_00024Companion_init(
        JNIEnv *env,
        jobject thiz,
        jint width,
        jint height
        ) {
    LOG_E(LOG_TAG, "Hello error from native!!");
    setupGraphics(width, height);
}

extern "C"
JNIEXPORT void JNICALL
Java_com_example_opengles_1android_1native_openglsdk_NativeCode_00024Companion_step(
        JNIEnv *env,
        jobject thiz
        ) {
    renderFrame();
}
