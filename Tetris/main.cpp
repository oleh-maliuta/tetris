#include "App.h"
#include "pages/MainMenuPage.h"
#include "pages/SettingsPage.h"

int main(int argc, char* argv[]) {
	App app;
	MainMenuPage main_menu(&app);
	SettingsPage settings(&app);
	main_menu.init();

	while (app.isRunning)
	{
		int frame_time = (1000 / app.fps);
		int delay_time = frame_time - SDL_GetTicks() - app.lastFrameTime;
		if (delay_time > 0 && delay_time <= frame_time) {
			SDL_Delay(delay_time);
		}

		float delta_time = (
			static_cast<float>(SDL_GetTicks()) / app.lastFrameTime)
			/ 1000.0f;
		app.lastFrameTime = SDL_GetTicks();

		switch (app.currentLocation)
		{
		case App::MAIN_MENU:
			main_menu.exec();
			break;
		case App::SETTINGS:
			settings.exec();
			break;
		}

		if (app.currentLocation != app.previousLocation) {
			switch (app.previousLocation)
			{
			case App::MAIN_MENU:
				main_menu.clean();
				break;
			case App::SETTINGS:
				settings.clean();
				break;
			}

			switch (app.currentLocation)
			{
			case App::MAIN_MENU:
				main_menu.init();
				break;
			case App::SETTINGS:
				settings.init();
				break;
			}

			app.previousLocation = app.currentLocation;
		}
	}

	main_menu.clean();
	settings.clean();
	return 0;
}
