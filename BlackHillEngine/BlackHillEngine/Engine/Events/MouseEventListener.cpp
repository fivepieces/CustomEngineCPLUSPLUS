#include "MouseEventListener.h"
#include "../Core/BlackHillEngine.h"

BlackHillEngine* MouseEventListener::engineInstance = nullptr;
int MouseEventListener::mouseX = 0;
int MouseEventListener::mouseY = 0;
int MouseEventListener::prevMouseX = 0;
int MouseEventListener::prevMouseY = 0;
bool MouseEventListener::firstUpdate = true;

MouseEventListener::~MouseEventListener()
{
	engineInstance = nullptr;
}

void MouseEventListener::RegisterEngineObject(BlackHillEngine * engine_)
{
	engineInstance = engine_;
}

void MouseEventListener::Update(SDL_Event e_)
{
	if (e_.type == SDL_MOUSEBUTTONDOWN) {
		UpdateMousePosition();
		NotifyOfMousePressed(e_.button.button);
	}
	else if (e_.type == SDL_MOUSEBUTTONUP) {
		UpdateMousePosition();
		NotifyOfMouseReleased(e_.button.button);
	}
	else if (e_.type == SDL_MOUSEMOTION) {
		UpdateMousePosition();
		NotifyOfMouseMove();
	}
	else if (e_.type == SDL_MOUSEWHEEL) {
		NotifyOfMouseScroll(e_.wheel.y);
	}
}

void MouseEventListener::NotifyOfMousePressed(int buttonType_)
{
	if (engineInstance) {
		engineInstance->NotifyOfMousePressed(mouseX, mouseY);
	}
}

void MouseEventListener::NotifyOfMouseReleased(int buttonType_)
{
	if (engineInstance) {
		engineInstance->NotifyOfMouseReleased(mouseX, mouseY, buttonType_);
	}
}

void MouseEventListener::NotifyOfMouseMove()
{
	if (engineInstance) {
		engineInstance->NotifyOfMouseMove(mouseX, mouseY);
	}
}

void MouseEventListener::NotifyOfMouseScroll(int y_)
{
	if (engineInstance) {
		engineInstance->NotifyOfMouseScroll(y_);
	}
}

glm::vec2 MouseEventListener::GetPreviousMousePosition()
{
	return glm::vec2(prevMouseX, prevMouseY);
}

glm::vec2 MouseEventListener::GetMousePosition()
{
	return glm::vec2(mouseX, mouseY);
}

glm::vec2 MouseEventListener::GetMouseOffset()
{
	//right way
	//return glm::vec2(prevMouseX - mouseX, prevMouseY - mouseY);

	//inverted way
	return glm::vec2(mouseX - prevMouseX, mouseY - prevMouseY);
}

void MouseEventListener::UpdateMousePosition()
{
	int tmpX, tmpY;
	SDL_GetMouseState(&tmpX, &tmpY);
	tmpY = engineInstance->GetScreenSize().y - tmpY;
	if (firstUpdate) {
		prevMouseX = mouseX = tmpX;
		prevMouseY = mouseY = tmpY;
		firstUpdate = false;
	}
	else if (tmpX != mouseX && tmpY != mouseY) {
		prevMouseX = mouseX;
		prevMouseY = mouseY;
		mouseX = tmpX;
		mouseY = tmpY;
	}
}
