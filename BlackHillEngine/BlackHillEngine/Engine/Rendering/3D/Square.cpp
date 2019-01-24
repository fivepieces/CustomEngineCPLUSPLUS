#include "Square.h"



Square::Square(GLuint shaderProgram_, GLuint textureID_) : Model(shaderProgram_)
{
	Vertex a;
	std::vector<Vertex> vertexList;

	a.position = glm::vec3(-0.5f, 0.5f, 0.0f);
	a.colour = glm::vec3(0.0f, 1.0f, 0.0f);
	vertexList.push_back(a);

	a.position = glm::vec3(0.5f, 0.5f, 0.0f);
	a.colour = glm::vec3(1.0f, 0.0f, 0.0f);
	vertexList.push_back(a);

	a.position = glm::vec3(-0.5f, -0.5f, 0.0f);
	a.colour = glm::vec3(0.0f, 0.0f, 1.0f);
	vertexList.push_back(a);

	AddMesh(new Mesh(&vertexList, textureID_, shaderProgram_));


	//Triangle 2

	/*a.position = glm::vec3(0.5f, -0.5f, 0.0f);
	a.colour = glm::vec3(0.0f, 1.0f, 0.0f);
	vertexList.push_back(a);

	a.position = glm::vec3(-0.5f, -0.5f, 0.0f);
	a.colour = glm::vec3(0.0f, 0.0f, 1.0f);
	vertexList.push_back(a);

	a.position = glm::vec3(0.5f, 0.5f, 0.0f);
	a.colour = glm::vec3(1.0f, 0.0f, 0.0f);
	vertexList.push_back(a);*/

	//Triangle 3

	//a.position = glm::vec3(0.0f, 0.0f, 1.0f);
	//a.colour = glm::vec3(0.0f, 1.0f, 0.0f);
	//vertexList.push_back(a);

	//a.position = glm::vec3(0.0f, 1.0f, 0.0f);
	//a.colour = glm::vec3(0.0f, 0.0f, 1.0f);
	//vertexList.push_back(a);

	//a.position = glm::vec3(1.0f, 0.0f, 0.0f);
	//a.colour = glm::vec3(1.0f, 0.0f, 0.0f);
	//vertexList.push_back(a);
	//

	////trignalge 4
	//a.position = glm::vec3(0.0f, 0.0f, -1.0f);
	//a.colour = glm::vec3(0.0f, 1.0f, 0.0f);
	//vertexList.push_back(a);

	//a.position = glm::vec3(0.0f, -1.0f, 0.0f);
	//a.colour = glm::vec3(0.0f, 0.0f, 1.0f);
	//vertexList.push_back(a);

	//a.position = glm::vec3(-1.0f, 0.0f, 0.0f);
	//a.colour = glm::vec3(1.0f, 0.0f, 0.0f);
	//vertexList.push_back(a);

	//AddMesh(new Mesh(&vertexList, textureID_, shaderProgram_));
}


Square::~Square()
{
}
