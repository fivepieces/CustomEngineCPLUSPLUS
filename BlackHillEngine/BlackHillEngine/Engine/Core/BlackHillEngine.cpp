#include "BlackHillEngine.h"

std::unique_ptr<BlackHillEngine> BlackHillEngine::engineInstance = nullptr;

BlackHillEngine::BlackHillEngine() : window(nullptr), isRunning(false), fps(120)
{
}


BlackHillEngine::~BlackHillEngine()
{
	Shutdown();
}

BlackHillEngine* BlackHillEngine::GetInstance() {
	if (engineInstance.get() == nullptr) {
		engineInstance.reset(new BlackHillEngine);
	}
	return engineInstance.get();
}


bool BlackHillEngine::Initialize(std::string name_, int width_, int height_) {
	Debug::DebugInit();
	Debug::SetSeverity(MessageType::TYPE_INFO);

	window = new Window();

	if (!window->Initialize(name_, width_, height_)) {
		Debug::FatalError("Window failed to initialize", __FILE__, __LINE__);
		std::cout << "Window failed to initialize" << std::endl;
		Shutdown();
		return isRunning = false;
	}

	//Centers Mouse to the screen
	SDL_WarpMouseInWindow(window->GetWindow(),
		window->GetWidth() / 2,
		window->GetHeight() / 2);

	MouseEventListener::RegisterEngineObject(this);

	ShaderHandler::GetInstance()->CreateProgram("colourShader", 
		"Engine/Shaders/ColourVertexShader.glsl",
		"Engine/Shaders/ColourFragmentShader.glsl");

	ShaderHandler::GetInstance()->CreateProgram("baseShader",
		"Engine/Shaders/VertexShader.glsl",
		"Engine/Shaders/FragmentShader.glsl");

	if (gameInterface) {
		if (!gameInterface->Initialize()) {
			Debug::FatalError("Failed to initialize game interface", __FILE__, __LINE__);
			return isRunning = false;
		}
	}
	Debug::Info("papa bless", __FILE__, __LINE__);
	timer.Start();
	return isRunning = true;

}
void BlackHillEngine::Run() {
	while (isRunning) {
		EventListener::Update();
		timer.UpdateFrameTicks();
		Update(timer.GetDeltaTime());
		Render();
		SDL_Delay(timer.GetSleepTime(fps));
	}

	if (!isRunning) {
		Shutdown();
	}

}
bool BlackHillEngine::GetIsRunning() {
	return isRunning;

}
void BlackHillEngine::Update(const float deltaTime_) {
	//std::cout << "Delta time: " << deltaTime_ << std::endl;
	if (gameInterface) {
		gameInterface->Update(deltaTime_);
	}

}
void BlackHillEngine::Render() {
	glClearColor(0.4f, 0.0f, 0.0f, 0.0f);
	glClear(GL_COLOR_BUFFER_BIT | GL_DEPTH_BUFFER_BIT);

	if (gameInterface) {
		gameInterface->Render();
	}
	//CALL GAME RENDER
	SDL_GL_SwapWindow(window->GetWindow());

}
void BlackHillEngine::Shutdown() {

	delete window;
	window = nullptr;

	delete gameInterface;
	gameInterface = nullptr;

	SDL_Quit();
	exit(0);
}

void BlackHillEngine::SetGameInterface(GameInterface* gameInterface_) {
	gameInterface = gameInterface_;
}


glm::vec2 BlackHillEngine::GetScreenSize() const {
	return glm::vec2(window->GetWidth(), window->GetHeight());
}

void BlackHillEngine::NotifyOfMousePressed(int x_, int y_)
{
}

void BlackHillEngine::NotifyOfMouseReleased(int x_, int y_, int buttonType_)
{
	CollisionHandler::GetInstance()->Update(
		glm::vec2(x_, y_), buttonType_);
}

void BlackHillEngine::NotifyOfMouseMove(int x_, int y_)
{
	Camera::GetInstance()->ProcessMouseMovement(
		MouseEventListener::GetMouseOffset().x,
		MouseEventListener::GetMouseOffset().y

	);
}

void BlackHillEngine::NotifyOfMouseScroll(int y_)
{
	Camera::GetInstance()->ProcessMouseZoom(y_);
}

void BlackHillEngine::ExitGame()
{
	isRunning = false;
}
