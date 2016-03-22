#include <GameGUI.hpp>

const int GameGUI::MINIMUM_WIDTH = 300;
const int GameGUI::MINIMUM_HEIGHT = 300;
	
GameGUI::GameGUI() : QWidget(),
	layout(),
	
	menu(),
	build_page(),
	trade_page(),
	dev_card_page(),
	
	main_menu_icon("/home/calcifer/Documents/code/C++/SettlersOfCatan/resources/gear.png"),
	main_menu(),
	main_menu_layout(),
	refresh_screen_button(),
	exit_game_button()
{
	setWindowTitle("Settlers of Catan");
	setMinimumWidth(MINIMUM_WIDTH);
	setMinimumHeight(MINIMUM_HEIGHT);
	setLayout(&layout);
	
	// add the different pages to the menu
	layout.addWidget(&menu);
	menu.addTab(&build_page, "Build");
	menu.addTab(&trade_page, "Trade");
	menu.addTab(&dev_card_page, "Development Cards");
	menu.addTab(&main_menu, main_menu_icon, "Menu");
	
	main_menu.setLayout(&main_menu_layout);
	main_menu_layout.addWidget(&refresh_screen_button);
	refresh_screen_button.setText("Refresh Screen");
	main_menu_layout.addWidget(&exit_game_button);
	exit_game_button.setText("Exit Game");
}
