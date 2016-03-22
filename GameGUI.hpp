#ifndef SETTLERS_OF_CATAN_GAMEGUI_H_
#define SETTLERS_OF_CATAN_GAMEGUI_H_

#include <QtGui/QIcon>
#include <QtGui/QPainter>
#include <QtWidgets/QHBoxLayout>
#include <QtWidgets/QPushButton>
#include <QtWidgets/QTabWidget>
#include <QtWidgets/QVBoxLayout>
#include <QtWidgets/QWidget>

class GameGUI : public QWidget
{
public:
	static const int MINIMUM_WIDTH;
	static const int MINIMUM_HEIGHT;
	
	GameGUI();
	
private:
	QVBoxLayout layout;
	
	QTabWidget menu;
	QWidget build_page;
	QWidget trade_page; // also responsible for showing resource cards
	QWidget dev_card_page;
	
	QIcon main_menu_icon;
	QWidget main_menu;
	QHBoxLayout main_menu_layout;
	QPushButton refresh_screen_button;
	QPushButton exit_game_button;
	
};

#endif // SETTLERS_OF_CATAN_GAMEGUI_H_