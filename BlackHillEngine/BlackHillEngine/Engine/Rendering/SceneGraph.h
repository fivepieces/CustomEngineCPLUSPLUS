#ifndef SCENEGRAPH_H
#define SCENEGRAPH_H

#include <memory>
#include <map>
#include <vector>
#include "3D/Gameobject.h"
#include "../Math/CollisionHandler.h"

class SceneGraph
{
public:
	SceneGraph(const SceneGraph&) = delete;
	SceneGraph(SceneGraph&&) = delete;
	SceneGraph& operator=(const SceneGraph&) = delete;
	SceneGraph& operator=(SceneGraph&&) = delete;

	static SceneGraph* GetInstance();
	void AddModel(Model* obj_);
	void AddGameObject(GameObject* go_, std::string name_ = "");
	GameObject* GetGameObject(std::string name_);

	void Update(const float deltaTime_);
	void Render(Camera* camera_);
private:
	SceneGraph();
	~SceneGraph();

	static std::unique_ptr<SceneGraph> sceneGraphInstance;
	friend std::default_delete<SceneGraph>;

	static std::map<GLuint, std::vector<Model* >> sceneModels;
	static std::map<std::string, GameObject*> sceneGameObjects;
};

#endif 