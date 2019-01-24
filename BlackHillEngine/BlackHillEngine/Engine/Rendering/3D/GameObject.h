#ifndef GAMEOBJECT_H
#define GAMEOBJECT_H

#include "Model.h"
class GameObject
{
public:
	GameObject(Model* model_);
	GameObject(Model* model_, glm::vec3 position_);
	~GameObject();

	void Update(const float deltaTime_);

	void SetPosition(glm::vec3 position_);
	void SetAngle(float angle_);
	void SetRotation(glm::vec3 rotation_);
	void SetScale(glm::vec3 scale_);
	void SetTag(std::string tag_);
	void SetHit(bool hit_, int buttonType_);

	glm::vec3 GetPosition() const;
	float GetAngle() const;
	glm::vec3 GetRotation() const;
	glm::vec3 GetScale() const;
	BoundingBox GetBoundingBox() const;
	std::string GetTag() const;

private:
	glm::vec3 position;
	float angle;
	glm::vec3 rotation;
	glm::vec3 scale;
	Model* model;
	GLuint modelInstance;
	BoundingBox boundingBox;
	std::string tag;
	bool hit;
};

#endif //!GAMEOBJECT_H