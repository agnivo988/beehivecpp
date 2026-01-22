#include "../include/shader.h"
#include <fstream>
#include <sstream>

Shader::Shader(const char* vPath, const char* fPath)
{
    std::ifstream vFile(vPath), fFile(fPath);
    std::stringstream vStream, fStream;
    vStream << vFile.rdbuf();
    fStream << fFile.rdbuf();

    std::string vCode = vStream.str();
    std::string fCode = fStream.str();
    const char* vSrc = vCode.c_str();
    const char* fSrc = fCode.c_str();

    unsigned vShader = glCreateShader(GL_VERTEX_SHADER);
    glShaderSource(vShader, 1, &vSrc, nullptr);
    glCompileShader(vShader);

    unsigned fShader = glCreateShader(GL_FRAGMENT_SHADER);
    glShaderSource(fShader, 1, &fSrc, nullptr);
    glCompileShader(fShader);

    ID = glCreateProgram();
    glAttachShader(ID, vShader);
    glAttachShader(ID, fShader);
    glLinkProgram(ID);

    glDeleteShader(vShader);
    glDeleteShader(fShader);
}

void Shader::use() { glUseProgram(ID); }

void Shader::setMat4(const std::string& n, const glm::mat4& m) {
    glUniformMatrix4fv(glGetUniformLocation(ID, n.c_str()), 1, GL_FALSE, &m[0][0]);
}

void Shader::setVec3(const std::string& n, const glm::vec3& v) {
    glUniform3fv(glGetUniformLocation(ID, n.c_str()), 1, &v[0]);
}
