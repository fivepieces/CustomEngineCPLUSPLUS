#ifndef MODEL_H
#define MODEL_H

#include "Mesh.h"
#include <glm/gtc/matrix_transform.hpp>
#include "LoadOBJModel.h"

class Model
{
public:
	Model(const std::string& objPath_,
		const std::string& matPath_,
		GLuint shaderProgram_);
	~Model();
	void Render(Camera* camera_);
	void AddMesh(Mesh* mesh_);
	GLuint CreateInstance(glm::vec3 position_,
		float angle_, glm::vec3 rotation_,
		glm::vec3 scale_);
	void UpdateInstance(GLuint index_,
		glm::vec3 position_,
		float angle_, glm::vec3 rotation_,
		glm::vec3 scale_);
	glm::mat4 GetTranform(GLuint index_) const;
	BoundingBox GetBoundingBox();
	GLuint GetShader();
	
private:
	std::vector<Mesh*> subMeshes;
	GLuint shaderProgram;
	glm::mat4 GetTransform(glm::vec3 position_,
		float angle_, glm::vec3 rotation_,
		glm::vec3 scale_) const;
	void LoadModel();
	std::vector<glm::mat4> modelInstances;
	LoadOBJModel* obj;
	BoundingBox boundingBox;
};

#endif // !MODEL_H