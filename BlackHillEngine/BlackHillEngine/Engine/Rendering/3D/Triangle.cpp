#include "Triangle.h"



Triangle::Triangle(GLuint shaderProgram_, GLuint textureID_) : Model(shaderProgram_)
{
	Vertex v;
	std::vector<Vertex> vertexList;

	v.position = glm::vec3(0.5f, 0.5f, 0.0f);
	v.colour = glm::vec3(1.0f, 0.0f, 0.0f);
	vertexList.push_back(v);

	v.position = glm::vec3(-0.5f, -0.5f, 0.0f);
	v.colour = glm::vec3(0.0f, 1.0f, 0.0f);
	vertexList.push_back(v);

	v.position = glm::vec3(0.5f, -0.5f, 0.0f);
	v.colour = glm::vec3(0.0f, 0.0f, 1.0f);
	vertexList.push_back(v);

	AddMesh(new Mesh(&vertexList, textureID_, shaderProgram_));
}


Triangle::~Triangle()
{
}
