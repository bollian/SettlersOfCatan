#ifndef SETTLERS_OF_CATAN_STARTMENU_H_
#define SETTLERS_OF_CATAN_STARTMENU_H_

#include <QtWidgets/QLabel>
#include <QtWidgets/QHBoxLayout>
#include <QtWidgets/QGroupBox>
#include <QtWidgets/QMainWindow>
#include <QtWidgets/QPushButton>
#include <QtWidgets/QSpacerItem>
#include <QtWidgets/QVBoxLayout>

#include <SpinnerAndSlider.hpp>

class StartMenu : public QMainWindow
{
	Q_OBJECT
public:
	static const int MAX_PLAYER_COUNT;
	static const int MIN_PLAYER_COUNT;
	
	static const int DEFAULT_PORT_VALUE;
	
	StartMenu(void (*callback)(int, bool, int));
	
private:
	void (*callback)(int, bool, int);
	
	QWidget central_widget;
	QVBoxLayout window_layout;
	
	QWidget player_count_widget;
	QHBoxLayout player_count_layout;
	QLabel player_count_label;
	SpinnerAndSlider spinner_and_slider;
	
	QGroupBox server_group_box;
	QVBoxLayout server_group_box_layout;
	
	QWidget port_number_widget;
	QHBoxLayout port_number_layout;
	QLabel port_number_label;
	QSpinBox port_number_box;
	
	QWidget start_game_widget;
	QHBoxLayout start_game_layout;
	QPushButton start_game_button;
	
private slots:
	void startGameClicked(bool checked);
	
};

#endif // SETTLERS_OF_CATAN_STARTMENU_H_
