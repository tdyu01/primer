#pragma once
#include <glew\glew.h>
#include <string>

using namespace std;

class CGLS_Program
{
private:
	GLuint _fragmentShaderID;
	GLuint _vertexShaderID;
	GLuint _programID;
	int _numAttribute;

	void compileShader(const string& shaderpath, GLuint id);
public:
	CGLS_Program();
	~CGLS_Program();

	void compileShaders(const string& vertexShaderFilePath, const string& fragmentShaderFilePath);
	void linkerShader();
	void addAttribute();
	void use();
	void unuse();

};

