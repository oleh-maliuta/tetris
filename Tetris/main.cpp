#include <map>
#include <fstream>
#include <iostream>
#include "App.h"
#include "pages/MainMenuPage.h"
#include "pages/SettingsPage.h"

static bool get_app_settings(std::map<std::string, std::string>& result);

int main(int argc, char* argv[]) {
	std::map<std::string, std::string> app_settings;
	get_app_settings(app_settings);

	App app(
		app_settings["app_version"],
		std::stoi(app_settings["fps"]),
		440,
		640);

	MainMenuPage main_menu(&app);
	SettingsPage settings(&app);

	main_menu.init();

	while (app.getRunning())
	{
		int frame_time = (1000 / app.getFps());
		int delay_time = frame_time - SDL_GetTicks() - app.getLastFrameTime();

		if (delay_time > 0 && delay_time <= frame_time) {
			SDL_Delay(delay_time);
		}

		app.setDeltaTime((static_cast<float>(SDL_GetTicks()) / app.getLastFrameTime()) / 1000.0f);
		app.setLastFrameTime(SDL_GetTicks());

		switch (app.getCurrentLocation())
		{
		case App::MAIN_MENU:
			main_menu.exec();
			break;
		case App::SETTINGS:
			settings.exec();
			break;
		}

		if (app.getCurrentLocation() != app.getPreviousLocation()) {
			switch (app.getPreviousLocation())
			{
			case App::MAIN_MENU:
				main_menu.clean();
				break;
			case App::SETTINGS:
				settings.clean();
				break;
			}

			switch (app.getCurrentLocation())
			{
			case App::MAIN_MENU:
				main_menu.init();
				break;
			case App::SETTINGS:
				settings.init();
				break;
			}

			app.setPreviousLocation(app.getCurrentLocation());
		}
	}

	switch (app.getCurrentLocation())
	{
	case App::MAIN_MENU:
		main_menu.clean();
		break;
	case App::SETTINGS:
		settings.clean();
		break;
	}

	return 0;
}

static bool get_app_settings(std::map<std::string, std::string>& result) {
	std::ifstream app_settings_file("app_settings.txt");

	if (!app_settings_file.is_open()) {
		std::cerr << "Unable to open file";
		return false;
	}

	std::string delimiter = ":";
	std::string line;

	while (std::getline(app_settings_file, line)) {
		size_t del_pos = line.find(delimiter);

		std::string key = line.substr(0, del_pos);
		std::string value = line.substr(del_pos + 1, line.length() - 1);

		result[key] = value;
	}

	app_settings_file.close();
	return true;
}
