#ifndef OCTSPATIALPARTITION_H
#define OCTSPACIALPARTITION_H

#include "../Rendering/3D/GameObject.h"
#include "../Math/Ray.h"

class OctNode {

private:
	friend class OctSpacialPartition;
	BoundingBox* octBounds;
	OctNode* parent;
	OctNode* children[8];
	std::vector<GameObject*> objectList;
	float size;
	static int childNum;

public:
	enum OctChildren {
		OCT_TLF,
		OCT_BLF,
		OCT_BRF,
		OCT_TRF,
		OCT_TLR,
		OCT_BLR,
		OCT_BRR,
		OCT_TRR
	};
	OctNode(glm::vec3 position_, float size_, OctNode* parent_);
	~OctNode();
	void Octify(int depth);
	OctNode* GetParent();
	OctNode* GetChild(OctChildren type_);
	void AddCollisionObject(GameObject* obj_);
	int GetObjectCount() const;
	bool isLeaf()const;
	BoundingBox* GetBoundingBox() const;
	int GetChildCount() const;
};



class OctSpacialPartition
{
private:
	OctNode * root;
	std::vector<OctNode*> rayIntersectionList;
	void AddObjectToCell(OctNode* cell_,GameObject* obj_);
	void PrepareCollisionQuery(OctNode* cell_, Ray ray_);
public:
	OctSpacialPartition(float worldSize_);
	~OctSpacialPartition();
	void AddObject(GameObject* obj_);
	GameObject* GetCollision(Ray ray_);
};


#endif //!! OCTSPACIALPARTITION_H