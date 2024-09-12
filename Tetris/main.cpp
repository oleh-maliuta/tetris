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
		app_settings["vertical_sync"] == "1",
		440,
		640,
		App::Location::MAIN_MENU);

	std::map<App::Location, Page*> pages;
	pages[App::Location::MAIN_MENU] = new MainMenuPage(&app);
	pages[App::Location::SETTINGS] = new SettingsPage(&app);

	pages[app.getCurrentLocation()]->init();

	while (app.getRunning())
	{
		int frame_time = (1000 / app.getFps());
		int delay_time = frame_time - SDL_GetTicks() - app.getLastFrameTime();

		if (delay_time > 0 && delay_time <= frame_time) {
			SDL_Delay(delay_time);
		}

		app.setDeltaTime((static_cast<float>(SDL_GetTicks()) / app.getLastFrameTime()) / 1000.0f);
		app.setLastFrameTime(SDL_GetTicks());

		pages[app.getPreviousLocation()]->exec();

		if (app.getCurrentLocation() != app.getPreviousLocation()) {
			pages[app.getPreviousLocation()]->clean();
			pages[app.getCurrentLocation()]->init();
			app.setPreviousLocation(app.getCurrentLocation());
		}
	}

	pages[app.getPreviousLocation()]->clean();

	for (auto& el : pages) {
		delete el.second;
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
