#ifndef BLACKHILLENGINE_H
#define BLACKHILLENGINE_H

#include "Window.h"
#include "Timer.h"
#include "Debug.h"
#include "GameInterface.h"
#include "../Rendering/3D/Triangle.h"
#include "../Rendering/3D/Square.h"
#include "../Rendering/3D/Cube.h"
#include "../Graphics/ShaderHandler.h"
#include "../Graphics/TextureHandler.h"
#include "../Camera/Camera.h"
#include "../Rendering/3D/GameObject.h"
#include "../Events/EventListener.h"
#include "../Rendering/SceneGraph.h"
#include <memory>

class BlackHillEngine
{
public:

	BlackHillEngine(const BlackHillEngine&) = delete;
	BlackHillEngine(BlackHillEngine&&) = delete;
	BlackHillEngine& operator=(const BlackHillEngine&) = delete;
	BlackHillEngine& operator=(BlackHillEngine&&) = delete;

	bool Initialize(std::string name_, int width_, int height_);
	void Run();
	bool GetIsRunning();
	void SetGameInterface(GameInterface* gameInterface_);
	

	static BlackHillEngine* GetInstance();

	glm::vec2 GetScreenSize() const;

	void NotifyOfMousePressed(int x_, int y_);
	void NotifyOfMouseReleased(int x_, int y_, int buttonType_);
	void NotifyOfMouseMove(int x_, int y_);
	void NotifyOfMouseScroll(int y_);
	void ExitGame();
private:
	BlackHillEngine();
	~BlackHillEngine();

	void Update(const float deltaTime_);
	void Render();
	void Shutdown();

	Window* window;
	Timer timer;
	GameInterface* gameInterface;


	static std::unique_ptr<BlackHillEngine> engineInstance;
	friend std::default_delete<BlackHillEngine>;

	bool isRunning;
	unsigned int fps;
};

#endif //!BLACKHILLENGINE_H

