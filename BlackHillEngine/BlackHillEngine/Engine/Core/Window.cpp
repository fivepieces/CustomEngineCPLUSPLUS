#include "Window.h"



Window::Window() :window(nullptr)
{

}


Window::~Window()
{
	Shutdown();
}

bool Window::Initialize(std::string name_, int width_, int height_) {

	//if SDL didnt initialize properly, dont do anything else
	if (SDL_Init(SDL_INIT_VIDEO) < 0) {
		Debug::FatalError("Failed to initialize SDL", __FILE__, __LINE__);
		return false;
	}
	width = width_;
	height = height_;
	window = SDL_CreateWindow(name_.c_str(), SDL_WINDOWPOS_CENTERED, SDL_WINDOWPOS_CENTERED, width, height, SDL_WINDOW_OPENGL);

	if (!window) {
		Debug::FatalError("Failed to create window", __FILE__, __LINE__);
		return false;
	}

	context = SDL_GL_CreateContext(window);

	SetAttributes();

	GLenum err = glewInit();
	if (err != GLEW_OK) {
		Debug::FatalError("Failed to initialize GLEW", __FILE__, __LINE__);
		return false;
	}

	glEnable(GL_DEPTH_TEST);

	glViewport(0, 0, width, height);
	std::cout << "OpenGL version: " << glGetString(GL_VERSION) << std::endl;
	return true;
}

void Window::Shutdown() {
	SDL_GL_DeleteContext(context);
	SDL_DestroyWindow(window);
	window = nullptr;

}

int Window::GetWidth() {
	return width;
}

int Window::GetHeight() {
	return height;
}
SDL_Window* Window::GetWindow() const {
	return window;
}

void Window::SetAttributes()
{
	SDL_GL_SetAttribute(SDL_GL_CONTEXT_PROFILE_MASK, SDL_GL_CONTEXT_PROFILE_CORE);
	SDL_GL_SetAttribute(SDL_GL_CONTEXT_MAJOR_VERSION, 3);
	SDL_GL_SetAttribute(SDL_GL_CONTEXT_MINOR_VERSION, 3);
	SDL_GL_SetAttribute(SDL_GL_DOUBLEBUFFER, 1);
	SDL_GL_SetAttribute(SDL_GL_DEPTH_SIZE, 32);

	SDL_GL_SetSwapInterval(1);

	glewExperimental = GL_TRUE;
}
