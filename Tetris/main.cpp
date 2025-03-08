#include "Application.h"
#include "pages/MainMenuPage.h"
#include "pages/SettingsPage.h"
#include "pages/PlayPage.h"
#include "pages/GuidePage.h"
#include "pages/ControlsPage.h"

using namespace Tetris;

int main(int argc, char* argv[])
{
	Application app(550, 600);

	app.usePage<MainMenuPage>("main_menu");
	app.usePage<SettingsPage>("settings");
	app.usePage<PlayPage>("play");
	app.usePage<GuidePage>("guide");
	app.usePage<ControlsPage>("controls");

	app.run("main_menu");

	return 0;
}
