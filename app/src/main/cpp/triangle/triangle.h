//
// Created by Dhananjay Jhinkwan on 27/01/23.
//

#pragma once

#include <base.h>
namespace triangle {
    static const char glVertexShader[] =
            "attribute vec4 vPosition;\n"
            "void main()\n"
            "{\n"
            "  gl_Position = vPosition;\n"
            "}\n";

    static const char glFragmentShader[] =
            "precision mediump float;\n"
            "void main()\n"
            "{\n"
            "  gl_FragColor = vec4(1.0, 0.0, 0.0, 1.0);\n"
            "}\n";
    const GLfloat triangleVertices[] = {
            0.0f, 0.5f,
            -0.5f, -0.5f,
            0.5f, -0.5f
    };


    bool setupGraphics(int width, int height);

    void renderFrame();
}