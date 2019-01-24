#include"Core/BlackHillEngine.h"
#include "../Game/Game.h"

int main(int argc, char* argv[]) {

	BlackHillEngine::GetInstance()->SetGameInterface(new Game());

	BlackHillEngine::GetInstance()->Initialize("BlackHillEngine", 800, 600);
	BlackHillEngine::GetInstance()->Run();


	return 0;
}