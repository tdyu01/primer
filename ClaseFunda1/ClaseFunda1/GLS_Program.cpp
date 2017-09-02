#include "GLS_Program.h"
#include "Error.h"
#include <fstream>
#include <vector>

void CGLS_Program::compileShader(const string& shaderpath, GLuint id) {
	string fileContent = "";
	string line = "";
	ifstream shaderFile(shaderpath);
	if (shaderFile.fail()) {

	}
	while (getline(shaderFile, line)) {
		fileContent += line + "\n";
	}
	shaderFile.close();
	const char* contents = fileContent.c_str();

	glShaderSource(id, 1, &contents, nullptr);
	glCompileShader(id);

	GLint isCompiled = 0;

	glGetShaderiv(id, GL_COMPILE_STATUS, &isCompiled);
	if (isCompiled == GL_FALSE)
	{
		GLint maxLength = 0;
		glGetShaderiv(id, GL_INFO_LOG_LENGTH, &maxLength);

		// The maxLength includes the NULL character
		std::vector<GLchar> errorLog(maxLength);
		glGetShaderInfoLog(id, maxLength, &maxLength, &errorLog[0]);
		//fatalError("Shaders not compiled" printf("%s", &(errorLog[0])));
		// Provide the infolog in whatever manor you deem best.
		// Exit with failure.
		glDeleteShader(id); // Don't leak the shader.
		return;
	}

}

void CGLS_Program::compileShaders(const string& vertexShaderFilePath, const string& fragmentShaderFilePath) {
	_programID = glCreateProgram();

	_vertexShaderID = glCreateShader(GL_VERTEX_SHADER);

	if (_vertexShaderID == 0) {

	}

	_fragmentShaderID = glCreateShader(GL_FRAGMENT_SHADER);

	if (_fragmentShaderID == 0) {
	}

	compileShader(vertexShaderFilePath, _vertexShaderID);
	compileShader(fragmentShaderFilePath, _fragmentShaderID);
}

void CGLS_Program::linkerShader() {
	glAttachShader(_programID, _vertexShaderID);
	glAttachShader(_programID, _fragmentShaderID);
	glLinkProgram(_programID);

	GLint isLinked = 0;
	glGetProgramiv(_programID, GL_LINK_STATUS, (int *)&isLinked);
	if (isLinked == GL_FALSE)
	{
		GLint maxLength = 0;
		glGetProgramiv(_programID, GL_INFO_LOG_LENGTH, &maxLength);
		//The maxLength includes the NULL character
		std::vector<GLchar> infoLog(maxLength);
		glGetProgramInfoLog(_programID, maxLength, &maxLength, &infoLog[0]);
		//We don't need the program anymore.
		glDeleteProgram(_programID);
		fatalError("Shaders not linked " + printf("%s", &(infoLog[0])));
		//Don't leak shaders either.
		glDeleteShader(_vertexShaderID);
		glDeleteShader(_fragmentShaderID);
		//Use the infoLog as you see fit.
		//In this simple program, we'll just leave
		return;
	}
	//Always detach shaders after a successful link.
	glDetachShader(_programID, _vertexShaderID);
	glDetachShader(_programID, _fragmentShaderID);
	
}
void CGLS_Program::addAttribute() {

}
void CGLS_Program::use() {
	for (int i = 0; i < _numAttribute; i++) {
		glEnableVertexAttribArray(i);
	}
}
void CGLS_Program::unuse() {
	for (int i = 0; i < _numAttribute; i++) {
		glEnableVertexAttribArray(i);
	}
}
CGLS_Program::CGLS_Program(): _programID(0), _fragmentShaderID(0), _vertexShaderID(0), _numAttribute(0)
{
}


CGLS_Program::~CGLS_Program()
{
}
