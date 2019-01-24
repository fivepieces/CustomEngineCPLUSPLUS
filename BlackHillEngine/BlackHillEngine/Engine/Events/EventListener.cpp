#include "EventListener.h"
#include "../Core/BlackHillEngine.h"


void EventListener::Update()
{
	SDL_Event SDLEvent;
	while (SDL_PollEvent(&SDLEvent)) {
		switch (SDLEvent.type) {
		case SDL_QUIT:
			BlackHillEngine::GetInstance()->ExitGame();
			break;
		case SDL_MOUSEBUTTONDOWN:
		case SDL_MOUSEBUTTONUP:
		case SDL_MOUSEMOTION:
		case SDL_MOUSEWHEEL:
			MouseEventListener::Update(SDLEvent);
			break;
		default:
			break;
		}
	}
}





