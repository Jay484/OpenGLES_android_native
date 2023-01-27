//
// Created by Dhananjay Jhinkwan on 27/01/23.
//

#include "triangle.h"
#include "base.h"

#define LOG_TAG "libNativeTriangle"

GLuint simpleTriangleProgram;
GLuint vPosition;

GLuint loadShader(GLenum shaderType, const char *shaderSource) {
    GLuint shader = glCreateShader(shaderType);

    if(shader){
        glShaderSource(shader, 1, &shaderSource, nullptr);
        glCompileShader(shader);
        GLint compiled = 0;
        glGetShaderiv(shader, GL_COMPILE_STATUS, &compiled);
        if (!compiled)
        {
            GLint infoLen = 0;
            glGetShaderiv(shader, GL_INFO_LOG_LENGTH, &infoLen);
            if (infoLen)
            {
                char * buf = (char*) malloc(infoLen);
                if (buf)
                {
                    glGetShaderInfoLog(shader, infoLen, NULL, buf);
                    LOG_E(LOG_TAG, "Could not Compile Shader %d:\n%s\n", shaderType, buf);
                    free(buf);
                }
                glDeleteShader(shader);
                shader = 0;
            }
        }
    }

    return shader;
}

GLuint createProgram(const char *vertexSource, const char *fragmentSource) {
    GLuint vertexShader = loadShader(GL_VERTEX_SHADER, vertexSource);
    if(!vertexShader)
        return 0;

    GLuint fragmentShader = loadShader(GL_FRAGMENT_SHADER, fragmentSource);
    if(!fragmentShader)
        return 0;

    GLuint program = glCreateProgram();
    if(program){
        glAttachShader(program, vertexShader);
        glAttachShader(program, fragmentShader);

        glLinkProgram(program);
        GLint linkStatus = GL_FALSE;
        glGetProgramiv(program, GL_LINK_STATUS, &linkStatus);
        if(linkStatus == GL_FALSE){
            GLint bufLength = 0;
            glGetProgramiv(program, GL_INFO_LOG_LENGTH, &bufLength);
            if (bufLength)
            {
                char* buf = (char*) malloc(bufLength);
                if (buf)
                {
                    glGetProgramInfoLog(program, bufLength, NULL, buf);
                    LOG_E(LOG_TAG,"Could not link program:\n%s\n", buf);
                    free(buf);
                }
            }
            glDeleteProgram(program);
            program = 0;
        }
    }
    return program;
}

bool setupGraphics(int width, int height) {
    simpleTriangleProgram = createProgram(
            glVertexShader, glFragmentShader
            );
    if(!simpleTriangleProgram){
        LOG_E(LOG_TAG, "Could not crete program");
        return false;
    }
    vPosition = glGetAttribLocation(simpleTriangleProgram,"vPosition");
    glViewport(0, 0, width, height);
    return true;
}

void renderFrame() {
    glClearColor(0.0F, 0.0F, 0.0F, 1.0F);
    glClear(GL_DEPTH_BUFFER_BIT | GL_COLOR_BUFFER_BIT);
    glUseProgram(simpleTriangleProgram);
    glVertexAttribPointer(
            vPosition,
            2,
            GL_FLOAT,
            GL_FALSE,
            0,
            triangleVertices
            );
    glEnableVertexAttribArray(vPosition);
    glDrawArrays(GL_TRIANGLES, 0, 3);
}
