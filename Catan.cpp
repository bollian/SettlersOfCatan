#include <iostream>

#include <QtWidgets/QApplication>
#include <QtWidgets/QMainWindow>

#include <Catan.hpp>
#include <GameGUI.hpp>
#include <StartMenu.hpp>

void callback(int players, bool run_server, int port_number);

QApplication* app;
StartMenu* start_menu;
GameGUI* game_gui;

int main(int argc, char** argv)
{
	app = new QApplication(argc, argv);
	start_menu = new StartMenu(&callback);
	
	start_menu->show();
	
	return app->exec();
}

void callback(int players, bool run_server, int port_number)
{
	delete start_menu;
	game_gui = new GameGUI();
	game_gui->show();
	game_gui->showFullScreen();
}

namespace Utils
{
	bool valueInZone(int value, int min, int max)
	{
		return value >= min && value < max;
	}
}