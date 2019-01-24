#ifndef COLLISIONDETECTION_H
#define COLLISIONDETECTION_H

#include "../Camera/Camera.h"

struct Ray;
struct BoundingBox;

class CollisionDetection
{
public:
	CollisionDetection() = delete;
	CollisionDetection(const CollisionDetection&) = delete;
	CollisionDetection(CollisionDetection&&) = delete;
	CollisionDetection& operator=(const CollisionDetection&) = delete;
	CollisionDetection& operator=(CollisionDetection&&) = delete;

	static Ray ScreenToWorldRay(glm::vec2 mousePosition_,
		glm::vec2 screenSize_);
	static bool RayOBBIntersection(Ray* ray_, BoundingBox* box_);


};

#endif //!! COLLISIONDETECTION_H