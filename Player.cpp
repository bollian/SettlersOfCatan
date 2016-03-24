#include <NotImplementedException.hpp>
#include <Player.hpp>
#include <Route.hpp>
#include <Settlement.hpp>
#include <Tile.hpp>

Player::Player(Color color) :
	color(color),
	
	routes(),
	settlements(),
	
	resource_counts(),
	progress_card_counts(),
	victory_point_cards(), // initializes to a zero-length vector
	
	longest_road_length(0),
	played_knight_count(0)
{
	// zero out all card counts
	resource_counts.emplace(Resource::BRICK, 0);
	resource_counts.emplace(Resource::GRAIN, 0);
	resource_counts.emplace(Resource::LUMBER, 0);
	resource_counts.emplace(Resource::ORE, 0);
	resource_counts.emplace(Resource::WOOL, 0);
	
	progress_card_counts.emplace(ProgressCard::KNIGHT, 0);
	progress_card_counts.emplace(ProgressCard::ROAD_BUILDING, 0);
	progress_card_counts.emplace(ProgressCard::YEAR_OF_PLENTY, 0);
	progress_card_counts.emplace(ProgressCard::MONOPOLY, 0);
}

Player::Color Player::getColor() const
{
	return color;
}
	
int Player::getResourceCardCount(Resource resource) const
{
	return resource_counts.at(resource);
}

int Player::getProgressCardCount(ProgressCard card_type) const
{
	return progress_card_counts.at(card_type);
}

int Player::calculateVictoryPoints() const
{
	int points = 0;
	
	for (int i = 0; i < settlements.size(); ++i) {
		switch (settlements[i]->getLevel()) {
		case Settlement::SETTLEMENT:
			points += 1;
			break;
		case Settlement::CITY:
			points += 2;
			break;
		default:
			// no city or settlement, no points (should never happen)
			break;
		}
	}
	
	points += victory_point_cards.size();
	
	// need to compare road length & played knight count to other players
	throw NotImplementedException(__FILE__, __func__);
	
	return points;
}

void Player::rollValue(int dice_value)
{
	int adj_tile_count;
	Resource resource;
	Tile* tile;
	
	for (int i = 0; i < settlements.size(); ++i) {
		adj_tile_count = settlements[i]->getAdjTileCount();
		
		for (int k = 0; i < adj_tile_count; ++k) {
			tile = settlements[i]->getAdjTile(k);
			if (!tile->hasRobber() && tile->getDiceValue() == dice_value)
			{
				// get the type of tile and convert it to a resource
				resource = Tile::convertTileTypeToResource(tile->getType());
				
				switch (settlements[i]->getLevel()) {
				case Settlement::SETTLEMENT:
					resource_counts.at(resource) += 1;
					break;
				case Settlement::CITY:
					resource_counts.at(resource) += 2;
					break;
				default:
					// no city or settlement, no points (should never happen)
					break;
				}
			}
		}
	}
}

void Player::placeRoute(Route* new_route)
{
	routes.push_back(new_route);
	
	// needs to check longest road length
	throw NotImplementedException(__FILE__, __func__);
}

void Player::placeSettlement(Settlement* new_settlement)
{
	settlements.push_back(new_settlement);
}

void Player::drawProgressCard(ProgressCard card)
{
	++progress_card_counts.at(card);
}

int Player::getLongestRoadLength()
{
	return longest_road_length;
}

int Player::getPlayedKnightCount()
{
	return played_knight_count;
}
