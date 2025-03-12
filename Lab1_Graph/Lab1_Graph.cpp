#define GLEW_DLL
#define GLFW_DLL

#include "GL\glew.h" 
#include "GLFW\glfw3.h" 
#include <cstdio>

#include <iostream>
int main()
{

    glfwInit();
    if (!glfwInit()) {
        fprintf(stderr, "ERROR: could not start GLFW3.\n");
        return 1;
    }

    glfwWindowHint(GLFW_CONTEXT_VERSION_MAJOR,1);
    glfwWindowHint(GLFW_CONTEXT_VERSION_MINOR,0);
    //glfwWindowHint(GLFW_OPENGL_FORWARD_COMPAT,GL_TRUE);
    //glfwWindowHint(GLFW_OPENGL_PROFILE, GLFW_OPENGL_CORE_PROFILE);

    GLFWwindow* windo;

    windo = glfwCreateWindow(512, 512, "Hello", NULL, NULL);

    glfwMakeContextCurrent(windo);

    glewExperimental = GL_TRUE;

    glewInit();

    while (!glfwWindowShouldClose(windo)) 
    {
        glClearColor(0.5, 0.2, 0.7, 1);
        glClear(GL_COLOR_BUFFER_BIT);

        glColor3f(1.0, 1.0, 1.0);
        glBegin(GL_TRIANGLES);

        // Первый треугольник
        glVertex2f(0.0f, 1.0f); // Левая нижняя точка
        glVertex2f(0.2f, 0.2f); // Правая нижняя точка
        glVertex2f(-0.2f, 0.2f); // Верхняя точка

        glVertex2f(0.0f, -1.0f); // Левая нижняя точка
        glVertex2f(-0.2f, -0.2f); // Правая нижняя точка
        glVertex2f(0.2f, -0.2f);
        
        glVertex2f(1.0f, 0.0f); // Левая нижняя точка
        glVertex2f(0.2f, 0.2f); // Правая нижняя точка
        glVertex2f(0.2f, -0.2f);

        glVertex2f(-1.0f, 0.0f); // Левая нижняя точка
        glVertex2f(-0.2f, -0.2f); // Правая нижняя точка
        glVertex2f(-0.2f, 0.2f);
        glEnd();

        glBegin(GL_QUADS);

        glVertex2f(0.2f, 0.2f); // Левая нижняя точка
        glVertex2f(-0.2f, 0.2f); // Правая нижняя точка
        glVertex2f(-0.2f, -0.2f);
        glVertex2f(0.2f, -0.2f);
        glEnd();

        glfwSwapBuffers(windo);
        glfwPollEvents();
    }

    glfwTerminate();
}
