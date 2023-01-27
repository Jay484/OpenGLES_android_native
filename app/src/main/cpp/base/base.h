//
// Created by Dhananjay Jhinkwan on 27/01/23.
//

#ifndef OPENGLES_ANDROID_NATIVE_BASE_H
#define OPENGLES_ANDROID_NATIVE_BASE_H

#define LOG_I(LOG_TAG, ...) __android_log_print(ANDROID_LOG_INFO, LOG_TAG, __VA_ARGS__)
#define LOG_E(LOG_TAG,...) __android_log_print(ANDROID_LOG_ERROR, LOG_TAG, __VA_ARGS__)

#endif //OPENGLES_ANDROID_NATIVE_BASE_H
