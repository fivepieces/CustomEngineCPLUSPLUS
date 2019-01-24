#include "Cube.h"



Cube::Cube(GLuint shaderProgram_, GLuint textureID_) : Model(shaderProgram_)
{
	Vertex v;
	std::vector<Vertex> vertexList;
	v.position = glm::vec3(-1.0f, -1.0f, -1.0f);
	v.normal = glm::vec3(0.0f, 0.0f, -1.0f);
	v.textCoords = glm::vec2(0.0f, 0.0f);
	vertexList.push_back(v);
	v.position = glm::vec3(1.0f, -1.0f, -1.0f);
	v.normal = glm::vec3(0.0f, 0.0f, -1.0f);
	v.textCoords = glm::vec2(1.0f, 0.0f);
	vertexList.push_back(v);
	v.position = glm::vec3(1.0f, 1.0f, -1.0f);
	v.normal = glm::vec3(0.0f, 0.0f, -1.0f);
	v.textCoords = glm::vec2(1.0f, 1.0f);
	vertexList.push_back(v);

	v.position = glm::vec3(1.0f, 1.0f, -1.0f);
	v.normal = glm::vec3(0.0f, 0.0f, -1.0f);
	v.textCoords = glm::vec2(1.0f, 1.0f);
	vertexList.push_back(v);
	v.position = glm::vec3(-1.0f, 1.0f, -1.0f);
	v.normal = glm::vec3(0.0f, 0.0f, -1.0f);
	v.textCoords = glm::vec2(0.0f, 1.0f);
	vertexList.push_back(v);
	v.position = glm::vec3(-1.0f, -1.0f, -1.0f);
	v.normal = glm::vec3(0.0f, 0.0f, -1.0f);
	v.textCoords = glm::vec2(0.0f, 0.0f);
	vertexList.push_back(v);
	AddMesh(new Mesh(&vertexList, textureID_, shaderProgram_));

	vertexList.clear();
	vertexList.shrink_to_fit();

	v.position = glm::vec3(-1.0f, -1.0f, 1.0f);
	v.normal = glm::vec3(0.0f, 0.0f, 1.0f);
	v.textCoords = glm::vec2(0.0f, 0.0f);
	vertexList.push_back(v);
	v.position = glm::vec3(1.0f, -1.0f, 1.0f);
	v.normal = glm::vec3(0.0f, 0.0f, 1.0f);
	v.textCoords = glm::vec2(1.0f, 0.0f);
	vertexList.push_back(v);
	v.position = glm::vec3(1.0f, 1.0f, 1.0f);
	v.normal = glm::vec3(0.0f, 0.0f, 1.0f);
	v.textCoords = glm::vec2(1.0f, 1.0f);
	vertexList.push_back(v);

	v.position = glm::vec3(1.0f, 1.0f, 1.0f);
	v.normal = glm::vec3(0.0f, 0.0f, 1.0f);
	v.textCoords = glm::vec2(1.0f, 1.0f);
	vertexList.push_back(v);
	v.position = glm::vec3(-1.0f, 1.0f, 1.0f);
	v.normal = glm::vec3(0.0f, 0.0f, 1.0f);
	v.textCoords = glm::vec2(0.0f, 1.0f);
	vertexList.push_back(v);
	v.position = glm::vec3(-1.0f, -1.0f, 1.0f);
	v.normal = glm::vec3(0.0f, 0.0f, 1.0f);
	v.textCoords = glm::vec2(0.0f, 0.0f);
	vertexList.push_back(v);
	AddMesh(new Mesh(&vertexList, textureID_, shaderProgram_));

	vertexList.clear();
	vertexList.shrink_to_fit();

	v.position = glm::vec3(-1.0f, 1.0f, 1.0f);
	v.normal = glm::vec3(-1.0f, 0.0f, 0.0f);
	v.textCoords = glm::vec2(0.0f, 0.0f);
	vertexList.push_back(v);
	v.position = glm::vec3(-1.0f, 1.0f, -1.0f);
	v.normal = glm::vec3(-1.0f, 0.0f, 0.0f);
	v.textCoords = glm::vec2(1.0f, 0.0f);
	vertexList.push_back(v);
	v.position = glm::vec3(-1.0f, -1.0f, -1.0f);
	v.normal = glm::vec3(-1.0f, 0.0f, 0.0f);
	v.textCoords = glm::vec2(1.0f, 1.0f);
	vertexList.push_back(v);

	v.position = glm::vec3(-1.0f, -1.0f, -1.0f);
	v.normal = glm::vec3(-1.0f, 0.0f, 0.0f);
	v.textCoords = glm::vec2(1.0f, 1.0f);
	vertexList.push_back(v);
	v.position = glm::vec3(-1.0f, -1.0f, 1.0f);
	v.normal = glm::vec3(-1.0f, 0.0f, 0.0f);
	v.textCoords = glm::vec2(0.0f, 1.0f);
	vertexList.push_back(v);
	v.position = glm::vec3(-1.0f, 1.0f, 1.0f);
	v.normal = glm::vec3(-1.0f, 0.0f, 0.0f);
	v.textCoords = glm::vec2(0.0f, 0.0f);
	vertexList.push_back(v);
	AddMesh(new Mesh(&vertexList, textureID_, shaderProgram_));

	vertexList.clear();
	vertexList.shrink_to_fit();

	v.position = glm::vec3(1.0f, 1.0f, 1.0f);
	v.normal = glm::vec3(1.0f, 0.0f, 0.0f);
	v.textCoords = glm::vec2(0.0f, 0.0f);
	vertexList.push_back(v);
	v.position = glm::vec3(1.0f, 1.0f, -1.0f);
	v.normal = glm::vec3(1.0f, 0.0f, 0.0f);
	v.textCoords = glm::vec2(1.0f, 0.0f);
	vertexList.push_back(v);
	v.position = glm::vec3(1.0f, -1.0f, -1.0f);
	v.normal = glm::vec3(1.0f, 0.0f, 0.0f);
	v.textCoords = glm::vec2(1.0f, 1.0f);
	vertexList.push_back(v);

	v.position = glm::vec3(1.0f, -1.0f, -1.0f);
	v.normal = glm::vec3(1.0f, 0.0f, 0.0f);
	v.textCoords = glm::vec2(1.0f, 1.0f);
	vertexList.push_back(v);
	v.position = glm::vec3(1.0f, -1.0f, 1.0f);
	v.normal = glm::vec3(1.0f, 0.0f, 0.0f);
	v.textCoords = glm::vec2(0.0f, 1.0f);
	vertexList.push_back(v);
	v.position = glm::vec3(1.0f, 1.0f, 1.0f);
	v.normal = glm::vec3(1.0f, 0.0f, 0.0f);
	v.textCoords = glm::vec2(0.0f, 0.0f);
	vertexList.push_back(v);
	AddMesh(new Mesh(&vertexList, textureID_, shaderProgram_));

	vertexList.clear();
	vertexList.shrink_to_fit();

	v.position = glm::vec3(-1.0f, -1.0f, -1.0f);
	v.normal = glm::vec3(0.0f, -1.0f, 0.0f);
	v.textCoords = glm::vec2(0.0f, 0.0f);
	vertexList.push_back(v);
	v.position = glm::vec3(1.0f, -1.0f, -1.0f);
	v.normal = glm::vec3(0.0f, -1.0f, 0.0f);
	v.textCoords = glm::vec2(1.0f, 0.0f);
	vertexList.push_back(v);
	v.position = glm::vec3(1.0f, -1.0f, 1.0f);
	v.normal = glm::vec3(0.0f, -1.0f, 0.0f);
	v.textCoords = glm::vec2(1.0f, 1.0f);
	vertexList.push_back(v);

	v.position = glm::vec3(1.0f, -1.0f, 1.0f);
	v.normal = glm::vec3(0.0f, -1.0f, 0.0f);
	v.textCoords = glm::vec2(1.0f, 1.0f);
	vertexList.push_back(v);
	v.position = glm::vec3(-1.0f, -1.0f, 1.0f);
	v.normal = glm::vec3(0.0f, -1.0f, 0.0f);
	v.textCoords = glm::vec2(0.0f, 1.0f);
	vertexList.push_back(v);
	v.position = glm::vec3(-1.0f, -1.0f, -1.0f);
	v.normal = glm::vec3(0.0f, -1.0f, 0.0f);
	v.textCoords = glm::vec2(0.0f, 0.0f);
	vertexList.push_back(v);
	AddMesh(new Mesh(&vertexList, textureID_, shaderProgram_));

	vertexList.clear();
	vertexList.shrink_to_fit();

	v.position = glm::vec3(-1.0f, 1.0f, -1.0f);
	v.normal = glm::vec3(0.0f, 1.0f, 0.0f);
	v.textCoords = glm::vec2(0.0f, 0.0f);
	vertexList.push_back(v);
	v.position = glm::vec3(1.0f, 1.0f, -1.0f);
	v.normal = glm::vec3(0.0f, 1.0f, 0.0f);
	v.textCoords = glm::vec2(1.0f, 0.0f);
	vertexList.push_back(v);
	v.position = glm::vec3(1.0f, 1.0f, 1.0f);
	v.normal = glm::vec3(0.0f, 1.0f, 0.0f);
	v.textCoords = glm::vec2(1.0f, 1.0f);
	vertexList.push_back(v);

	v.position = glm::vec3(1.0f, 1.0f, 1.0f);
	v.normal = glm::vec3(0.0f, 1.0f, 0.0f);
	v.textCoords = glm::vec2(1.0f, 1.0f);
	vertexList.push_back(v);
	v.position = glm::vec3(-1.0f, 1.0f, 1.0f);
	v.normal = glm::vec3(0.0f, 1.0f, 0.0f);
	v.textCoords = glm::vec2(0.0f, 1.0f);
	vertexList.push_back(v);
	v.position = glm::vec3(-1.0f, 1.0f, -1.0f);
	v.normal = glm::vec3(0.0f, 1.0f, 0.0f);
	v.textCoords = glm::vec2(0.0f, 0.0f);
	vertexList.push_back(v);
	AddMesh(new Mesh(&vertexList, textureID_, shaderProgram_));

	vertexList.clear();
	vertexList.shrink_to_fit();
}


Cube::~Cube()
{
}
