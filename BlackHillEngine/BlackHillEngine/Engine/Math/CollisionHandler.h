#ifndef COLLISIONHANDLER_H
#define COLLISIONHANDLER_H

#include "../Rendering/3D/GameObject.h"
#include "../Core/BlackHillEngine.h"
#include "CollisionDetection.h"
#include "Ray.h"
#include "../Core/OctSpacialPartition.h"

class CollisionHandler
{
public:
	CollisionHandler(const CollisionHandler&) = delete;
	CollisionHandler(CollisionHandler&&) = delete;
	CollisionHandler& operator=(const CollisionHandler&) = delete;
	CollisionHandler& operator=(CollisionHandler&&) = delete;

	static CollisionHandler* GetInstance();
	void Initialize(float worldSize_);
	void AddObject(GameObject* go_);
	void Update(glm::vec2 mousePosition_, int buttonType_);
private:
	CollisionHandler();
	~CollisionHandler();

	static std::unique_ptr<CollisionHandler> collisionInstance;
	friend std::default_delete<CollisionHandler>;


	static std::vector<GameObject*> previousCollisions;
	static std::vector<GameObject*> colliders;
	OctSpacialPartition* scenePartition;
};

#endif //!!COLLISIONHANDLER_H

