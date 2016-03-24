#ifndef SETTLERS_OF_CATAN_TILE_H_
#define SETTLERS_OF_CATAN_TILE_H_

#include <Node.hpp>
#include <Resource.hpp>

class Tile : public Node
{
public:
	enum TileType {
		SEA,
		BRICK,
		GRAIN,
		LUMBER,
		ORE,
		WOOL,
		DESERT
	};
	
	struct TileGroup {
		Tile* tile1;
		Tile* tile2;
		Tile* tile3;
		Tile* tile4;
		Tile* tile5;
		Tile* tile6;	
	};
	
	struct SettlementGroup {
		Settlement* settlement1;
		Settlement* settlement2;
		Settlement* settlement3;
		Settlement* settlement4;
		Settlement* settlement5;
		Settlement* settlement6;
	};
	
	struct RouteGroup {
		Route* route1;
		Route* route2;
		Route* route3;
		Route* route4;
		Route* route5;
		Route* route6;
	};
	
	Tile(int x, int y, TileType type, int dice, TileGroup tiles, SettlementGroup settlements, RouteGroup routes);
	
	TileType getType() const;
	static Resource convertTileTypeToResource(TileType type);
	int getDiceValue() const;
	/**
	 * checks to see if this tile has the robber
	 * @return true if the robber is here, false otherwise
	 */
	bool hasRobber() const;
	/**
	 * used to add/remove the robber from this tile
	 * @param has_robber set to true if the robber is supposed to be on this tile
	 */
	void setRobber(bool has_robber);
	
private:
	static const int ADJ_TILE_COUNT;
	static const int ADJ_SETTLEMENT_COUNT;
	static const int ADJ_ROUTE_COUNT;
	
	TileType type;
	int dice_value;
	bool robber;
	
};

#endif // SETTLERS_OF_CATAN_TILE_H_