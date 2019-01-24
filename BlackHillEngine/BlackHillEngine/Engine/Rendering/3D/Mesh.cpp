#include "Mesh.h"



Mesh::Mesh(SubMesh subMesh_, GLuint shaderProgram_)
	:VAO(0), VBO(0)
{
	
	shaderProgram = shaderProgram_;
	subMesh = subMesh_;
	GenerateBuffers();
}


Mesh::~Mesh()
{
	glDeleteVertexArrays(1, &VAO);
	glDeleteBuffers(1, &VBO);
	
}

void Mesh::GenerateBuffers() {
	glGenVertexArrays(1, &VAO);
	glGenBuffers(1, &VBO);

	glBindVertexArray(VAO);
	glBindBuffer(GL_ARRAY_BUFFER, VBO);

	glBufferData(
		GL_ARRAY_BUFFER,
		subMesh.vertexList.size() * sizeof(Vertex),
		&subMesh.vertexList[0],
		GL_STATIC_DRAW);


	//POSITION
	glEnableVertexAttribArray(0);
	glVertexAttribPointer(
		0,
		3,
		GL_FLOAT,
		GL_FALSE,
		sizeof(Vertex),
		(GLvoid*)0);
	
	//NORMAL
	glEnableVertexAttribArray(1);
	glVertexAttribPointer(
		1,
		3,
		GL_FLOAT,
		GL_FALSE,
		sizeof(Vertex),
		(GLvoid*)offsetof(Vertex, normal));

	//TEXT-COORDS
	glEnableVertexAttribArray(2);
	glVertexAttribPointer(
		2,
		2,
		GL_FLOAT,
		GL_FALSE,
		sizeof(Vertex),
		(GLvoid*)offsetof(Vertex, textCoords));


	

	glBindVertexArray(0);
	glBindBuffer(GL_ARRAY_BUFFER, 0);

	modelLoc = glGetUniformLocation(shaderProgram, "model");
	viewLoc = glGetUniformLocation(shaderProgram, "view");
	projLoc = glGetUniformLocation(shaderProgram, "proj");
	viewPositionLoc = glGetUniformLocation(shaderProgram, "viewPosition");
	lightPosLoc = glGetUniformLocation(shaderProgram, "light.lightPos");
	lightAmbientLoc = glGetUniformLocation(shaderProgram, "light.ambient");
	lightDiffuseLoc = glGetUniformLocation(shaderProgram, "light.diffuse");
	lightColourLoc = glGetUniformLocation(shaderProgram, "light.lightColor");

	diffuseMapLoc = glGetUniformLocation(shaderProgram, "material.diffuseMap");
	shininessLoc = glGetUniformLocation(shaderProgram, "material.shininess");
	transparencyLoc = glGetUniformLocation(shaderProgram, "material.transparency");
	ambientLoc = glGetUniformLocation(shaderProgram, "material.ambient");
	diffuseLoc = glGetUniformLocation(shaderProgram, "material.diffuse");
	specularLoc = glGetUniformLocation(shaderProgram, "material.specular");
}

void Mesh::Render(Camera* camera_, std::vector<glm::mat4> instances_) {
	
	//material
	glUniform1i(diffuseMapLoc, 0);
	glActiveTexture(GL_TEXTURE0);
	glBindTexture(GL_TEXTURE_2D, subMesh.material.diffuseMap);

	glUniform1f(shininessLoc, subMesh.material.shininess);
	glUniform1f(transparencyLoc, subMesh.material.transparency);

	glUniform3f(ambientLoc,
		subMesh.material.ambient.x,
		subMesh.material.ambient.y,
		subMesh.material.ambient.z);

	glUniform3f(diffuseLoc,
		subMesh.material.diffuse.x,
		subMesh.material.diffuse.y,
		subMesh.material.diffuse.z);

	glUniform3f(specularLoc,
		subMesh.material.specular.x,
		subMesh.material.specular.y,
		subMesh.material.specular.z);



	//light
	glUniform3f(viewPositionLoc, 
		camera_->GetPosition().x,
		camera_->GetPosition().y,
		camera_->GetPosition().z);
	glUniform3f(lightPosLoc, 
		camera_->GetLightSources()[0]->GetPosition().x, 
		camera_->GetLightSources()[0]->GetPosition().y,
		camera_->GetLightSources()[0]->GetPosition().z);
	glUniform1f(lightAmbientLoc,
		camera_->GetLightSources()[0]->GetAmbient());
	glUniform1f(lightDiffuseLoc,
		camera_->GetLightSources()[0]->GetDiffuse());
	glUniform3f(lightColourLoc,
		camera_->GetLightSources()[0]->GetLightColour().x,
		camera_->GetLightSources()[0]->GetLightColour().y,
		camera_->GetLightSources()[0]->GetLightColour().z);

	glUniformMatrix4fv(viewLoc, 1, GL_FALSE, glm::value_ptr(camera_->GetView()));
	//Camera::GetInstance()->GetView();
	glUniformMatrix4fv(projLoc, 1, GL_FALSE, glm::value_ptr(camera_->GetPerspective()));

	glBindVertexArray(VAO);

	for (int i = 0; i < instances_.size(); i++) {

		glUniformMatrix4fv(modelLoc, 1, GL_FALSE, glm::value_ptr(instances_[i]));

		glDrawArrays(GL_TRIANGLES, 0, subMesh.vertexList.size());
	}
	glBindVertexArray(0);
	glBindTexture(GL_TEXTURE_2D, 0);
}