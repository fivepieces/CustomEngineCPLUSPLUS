#include "GameObject.h"



GameObject::GameObject(Model* model_) : position(glm::vec3()), angle(0.0f),
rotation(glm::vec3(0.0f, 1.0f, 0.0f)),
scale(glm::vec3(0.5f)), tag(""), hit("false")
{
	model = model_;
	if (model) {
		modelInstance = model->CreateInstance(position, angle, rotation, scale);
		boundingBox = model->GetBoundingBox();
		boundingBox.transform = model->GetTranform(modelInstance);
	}
	
	
}

GameObject::GameObject(Model* model_, glm::vec3 position_) : position(glm::vec3()), angle(0.0f),
rotation(glm::vec3(0.0f, 1.0f, 0.0f)),
scale(glm::vec3(0.5f)), tag(""), hit("false")
{
	model = model_;
	position = position_;
	if (model) {
		modelInstance = model->CreateInstance(position, angle, rotation, scale);
		boundingBox = model->GetBoundingBox();
		boundingBox.transform = model->GetTranform(modelInstance);
	}
}


GameObject::~GameObject()
{
	/*if (model) {
		delete model;
	}*/
	model = nullptr;
}

void GameObject::Update(const float deltaTime_) {
	SetAngle(angle + 0.005f);
}

void GameObject::SetPosition(glm::vec3 position_) {
	position = position_;
	if (model) {
		model->UpdateInstance(modelInstance, position, angle, rotation, scale);
		boundingBox.transform = model->GetTranform(modelInstance);
	}
}
void GameObject::SetAngle(float angle_) {
	angle = angle_;
	if (model) {
		model->UpdateInstance(modelInstance, position, angle, rotation, scale);
		boundingBox.transform = model->GetTranform(modelInstance);
	}
}
void GameObject::SetRotation(glm::vec3 rotation_) {
	rotation = rotation_;
	if (model) {
		model->UpdateInstance(modelInstance, position, angle, rotation, scale);
		boundingBox.transform = model->GetTranform(modelInstance);
	}
}
void GameObject::SetScale(glm::vec3 scale_) {
	scale = scale_;
	if (model) {
		model->UpdateInstance(modelInstance, position, angle, rotation, scale);
		boundingBox.transform = model->GetTranform(modelInstance);
		boundingBox.minVert *= (scale / 2.0f);
		boundingBox.maxVert *= (scale / 2.0f);
	}
}

void GameObject::SetTag(std::string tag_)
{
	tag = tag_;
}

void GameObject::SetHit(bool hit_, int buttonType_)
{
	hit = hit_;
	if (hit) {
		std::cout << tag << " was hit" << std::endl;
	}
}

glm::vec3 GameObject::GetPosition() const
{
	return position;
}

float GameObject::GetAngle() const
{
	return angle;
}

glm::vec3 GameObject::GetRotation() const
{
	return rotation;
}

glm::vec3 GameObject::GetScale() const
{
	return scale;
}

BoundingBox GameObject::GetBoundingBox() const
{
	return boundingBox;
}

std::string GameObject::GetTag() const
{
	return tag;
}

