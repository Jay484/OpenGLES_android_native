//
// Created by Dhananjay Jhinkwan on 27/01/23.
//

#include "triangle.h"
#include <android/log.h>

#define LOG_TAG "libNativeTriangle"

GLuint simpleTriangleProgram;
GLuint vPosition;

bool triangle::setupGraphics(int width, int height) {
    simpleTriangleProgram = createProgram(
            triangle::glVertexShader, triangle::glFragmentShader
            );
    if(!simpleTriangleProgram){
        LOG_E(LOG_TAG, "Could not crete program");
        return false;
    }
    vPosition = glGetAttribLocation(simpleTriangleProgram,"vPosition");
    glViewport(0, 0, width, height);
    return true;
}

void triangle::renderFrame() {
    glClearColor(0.0F, 0.0F, 0.0F, 1.0F);
    glClear(GL_DEPTH_BUFFER_BIT | GL_COLOR_BUFFER_BIT);
    glUseProgram(simpleTriangleProgram);
    glVertexAttribPointer(
            vPosition,
            2,
            GL_FLOAT,
            GL_FALSE,
            0,
            triangle::triangleVertices
            );
    glEnableVertexAttribArray(vPosition);
    glDrawArrays(GL_TRIANGLES, 0, 3);
}
