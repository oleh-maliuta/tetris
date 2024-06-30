#pragma once

#ifndef PAGES_SETTINGSPAGE_H
#define PAGES_SETTINGSPAGE_H

#include "Page.h"

class SettingsPage
	: public Page
{
public:
	SettingsPage(App*);
	~SettingsPage();
	virtual void init() override;
	virtual void clean() override;
	virtual void input() override;
	virtual void update() override;
	virtual void render() override;
};

#endif
