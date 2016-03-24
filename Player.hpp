#ifndef SETTLERS_OF_CATAN_PLAYER_H_
#define SETTLERS_OF_CATAN_PLAYER_H_

#include <map>
#include <vector>

#include <Catan.hpp>
#include <ProgressCard.hpp>
#include <Resource.hpp>
#include <VictoryPointCard.hpp>

using namespace std;

class Player
{
public:
	enum Color {
		WHITE,
		RED,
		ORANGE,
		BLUE,
		GREEN,
		BROWN
	};
	
	Player(Color color);
	
	Color getColor() const;
	
	int getResourceCardCount(Resource resource) const;
	int getProgressCardCount(ProgressCard card_type) const;
	int calculateVictoryPoints() const;
	
	/**
	 * tells the player to collect resource cards for a dice roll
	 * @param dice_value the value of the dice roll
	 */
	void rollValue(int dice_value);
	
	/**
	 * add a route to the player's list of routes, used for constructing roads & boats
	 * @param new_route the route to add
	 */
	void placeRoute(Route* new_route);
	
	/**
	 * add a settlement to the player's list of settlements, used for constructing settlements & cities
	 * @param new_settlement the settlement to add
	 */
	void placeSettlement(Settlement* new_settlement);
	
	/**
	 * add a development card to the players hand
	 * @param card which development card to add
	 */
	void drawProgressCard(ProgressCard card);
	
	int getLongestRoadLength();
	int getPlayedKnightCount();
	
private:
	Color color;
	
	vector<Route*> routes;
	vector<Settlement*> settlements;
	
	// card counts
	map<Resource, int> resource_counts;
	map<ProgressCard, int> progress_card_counts;
	vector<VictoryPointCard*> victory_point_cards;
	
	// track your longest road & the number of knights you've played
	int longest_road_length;
	int played_knight_count;
	
};

#endif // SETTLERS_OF_CATAN_PLAYER_H_
