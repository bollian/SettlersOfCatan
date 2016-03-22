cmake_minimum_required(VERSION 2.8.11)

set(CMAKE_INCLUDE_CURRENT_DIR ON)
set(CMAKE_AUTOMOC ON)

find_package(Qt5Core)
find_package(Qt5Gui)
find_package(Qt5Widgets)

set(CMAKE_CXX_FLAGS "${CMAKE_CXX_FLAGS} -std=c++11")

set(SOURCES
	Catan.cpp
	StartMenu.cpp
	SpinnerAndSlider.cpp
	GameGUI.cpp
	Route.cpp
	Settlement.cpp
	Tile.cpp
	Player.cpp
	Node.cpp
	NotImplementedException.cpp)

add_executable(SettlersOfCatan ${SOURCES})

target_link_libraries(SettlersOfCatan Qt5::Core)
target_link_libraries(SettlersOfCatan Qt5::Gui)
target_link_libraries(SettlersOfCatan Qt5::Widgets)
