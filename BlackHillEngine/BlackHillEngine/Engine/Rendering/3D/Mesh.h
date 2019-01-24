#ifndef MESH_
#define MESH_

#include <glew.h>
#include <vector>
#include <glm/glm.hpp>
#include <glm/gtc/type_ptr.hpp>
#include "../../Camera/Camera.h"
#include "../../Core/Debug.h"
#include "../../Graphics/MaterialHandler.h"

struct Vertex {
	glm::vec3 position;
	glm::vec3 normal;
	glm::vec2 textCoords;
};

struct SubMesh {
	std::vector<Vertex> vertexList;
	std::vector<GLuint> indices;
	Material material;
};


class Mesh
{
public:
	Mesh(SubMesh subMesh, GLuint shaderProgram_);
	~Mesh();
	void Render(Camera* camera_, std::vector<glm::mat4> instances_);
private:
	GLuint VAO, VBO;
	void GenerateBuffers();
	SubMesh subMesh;
	GLuint shaderProgram;
	GLuint modelLoc;
	GLuint viewLoc;
	GLuint projLoc;
	GLuint viewPositionLoc, lightPosLoc, lightAmbientLoc, lightDiffuseLoc, lightColourLoc;
	GLuint diffuseMapLoc, shininessLoc, transparencyLoc, ambientLoc, diffuseLoc, specularLoc;
};


#endif //!MESH_H



