#include "App.h"
#include "pages/MainMenuPage.h"
#include "pages/SettingsPage.h"

int main(int argc, char* argv[]) {
	App app(440, 640);

	app.usePage<MainMenuPage>("main_menu");
	app.usePage<SettingsPage>("settings");

	app.run("main_menu");

	return 0;
}
