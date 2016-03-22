#include <iostream>

#include <StartMenu.hpp>

using namespace std;

const int StartMenu::MAX_PLAYER_COUNT = 4;
const int StartMenu::MIN_PLAYER_COUNT = 2;

const int StartMenu::DEFAULT_PORT_VALUE = 8100;

StartMenu::StartMenu(void (*callback)(int, bool, int)) : QMainWindow(),
	callback(callback),
	central_widget(),
	window_layout(),
	
	player_count_widget(),
	player_count_layout(),
	player_count_label(),
	spinner_and_slider(MAX_PLAYER_COUNT, MIN_PLAYER_COUNT, 1),
	
	server_group_box(),
	server_group_box_layout(),
	
	port_number_widget(),
	port_number_layout(),
	port_number_label(),
	port_number_box(),
	
	start_game_widget(),
	start_game_layout(),
	start_game_button()
{
	setCentralWidget(&central_widget);
	central_widget.setLayout(&window_layout);
	setWindowTitle("Settlers of Catan");
	
	// player count
	window_layout.addWidget(&player_count_widget);
	player_count_widget.setLayout(&player_count_layout);
	player_count_label.setText("Player count:");
	player_count_layout.addWidget(&player_count_label);
	player_count_layout.addWidget(&spinner_and_slider);
	
	// server group box
	window_layout.addWidget(&server_group_box);
	server_group_box.setLayout(&server_group_box_layout);
	server_group_box.setCheckable(true);
	server_group_box.setChecked(false);
	server_group_box.setTitle("Network server");
	
	// port number
	server_group_box_layout.addWidget(&port_number_widget);
	port_number_widget.setLayout(&port_number_layout);
	port_number_layout.addWidget(&port_number_label);
	port_number_layout.addWidget(&port_number_box);
	port_number_label.setText("Port number:");
	port_number_box.setMinimum(1);
	port_number_box.setMaximum(99999);
	port_number_box.setValue(DEFAULT_PORT_VALUE);
	
	// start game button
	window_layout.addWidget(&start_game_widget);
	start_game_widget.setLayout(&start_game_layout);
	start_game_layout.addStretch(30);
	start_game_layout.addWidget(&start_game_button);
	start_game_button.setText("Start Game");
	start_game_layout.addStretch(30);
	
	// signals & slots
	connect(&start_game_button, &QPushButton::clicked, this, &StartMenu::startGameClicked);
}

void StartMenu::startGameClicked(bool checked)
{
	callback(spinner_and_slider.getValue(), server_group_box.isChecked(), port_number_box.value());
}