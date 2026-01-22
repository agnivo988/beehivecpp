#include <glad/glad.h>
#include <GLFW/glfw3.h>
#include <glm/glm.hpp>
#include <glm/gtc/matrix_transform.hpp>
#include "../include/shader.h"
#include "../include/camera.h"
#include <vector>
#include <iostream>

extern void generateHexPrism(std::vector<float>&);
extern glm::vec3 beePosition(int, float);

int main()
{
    glfwInit();
    glfwWindowHint(GLFW_CONTEXT_VERSION_MAJOR,3);
    glfwWindowHint(GLFW_CONTEXT_VERSION_MINOR,3);
    glfwWindowHint(GLFW_OPENGL_PROFILE,GLFW_OPENGL_CORE_PROFILE);

    GLFWwindow* window = glfwCreateWindow(800,600,"BeeHive3D",0,0);
    glfwMakeContextCurrent(window);
    if (!gladLoadGL(glfwGetProcAddress))
{
    std::cout << "Failed to initialize GLAD\n";
    return -1;
}

    glEnable(GL_DEPTH_TEST);

    Shader shader("shaders/vertex.glsl","shaders/fragment.glsl");
    Camera cam;

    std::vector<float> hiveVerts;
    generateHexPrism(hiveVerts);

    unsigned VAO,VBO;
    glGenVertexArrays(1,&VAO);
    glGenBuffers(1,&VBO);

    glBindVertexArray(VAO);
    glBindBuffer(GL_ARRAY_BUFFER,VBO);
    glBufferData(GL_ARRAY_BUFFER,hiveVerts.size()*4,hiveVerts.data(),GL_STATIC_DRAW);
    glVertexAttribPointer(0,3,GL_FLOAT,0,3*4,(void*)0);
    glEnableVertexAttribArray(0);

    while(!glfwWindowShouldClose(window))
    {
        float t = glfwGetTime();
        glClearColor(0.1f,0.1f,0.15f,1);
        glClear(GL_COLOR_BUFFER_BIT|GL_DEPTH_BUFFER_BIT);

        shader.use();
        glm::mat4 proj = glm::perspective(glm::radians(45.0f),800.f/600.f,0.1f,100.f);
        glm::mat4 view = cam.getView();

        // Draw hive cells
        for(int x=-2;x<=2;x++)
        for(int y=-2;y<=2;y++){
            glm::mat4 model=glm::translate(glm::mat4(1),{x*1.1f,y*1.1f,0});
            shader.setMat4("MVP",proj*view*model);
            shader.setVec3("color",{1.0f,0.8f,0.2f});
            glBindVertexArray(VAO);
            glDrawArrays(GL_TRIANGLES,0,hiveVerts.size()/3);
        }

        // Draw bees
        for(int i=0;i<10;i++){
            glm::vec3 p = beePosition(i,t);
            glm::mat4 model = glm::translate(glm::mat4(1),p);
            model = glm::scale(model,{0.2f,0.2f,0.2f});
            shader.setMat4("MVP",proj*view*model);
            shader.setVec3("color",{0,0,0});
            glDrawArrays(GL_TRIANGLES,0,hiveVerts.size()/3);
        }

        glfwSwapBuffers(window);
        glfwPollEvents();
    }
    glfwTerminate();
}
