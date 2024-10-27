#include "Application.h"
#include "pages/MainMenuPage.h"
#include "pages/SettingsPage.h"
#include "pages/PlayPage.h"

using namespace Tetris;

int main(int argc, char* argv[])
{
	Application app(600, 600);

	app.usePage<MainMenuPage>("main_menu");
	app.usePage<SettingsPage>("settings");
	app.usePage<PlayPage>("play");

	app.run("main_menu");

	return 0;
}
