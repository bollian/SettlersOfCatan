#ifndef SETTLERS_OF_CATAN_SETTLEMENT_H_
#define SETTLERS_OF_CATAN_SETTLEMENT_H_

#include <Catan.hpp>
#include <Node.hpp>

class Settlement : public Node
{
public:
	enum SettlementLevel {
		EMPTY,
		SETTLEMENT,
		CITY	
	};
	
	struct TileGroup {
		Tile* tile1;
		Tile* tile2;
		Tile* tile3;	
	};
	
	struct SettlementGroup {
		Settlement* settlement1;
		Settlement* settlement2;
		Settlement* settlement3;
	};
	
	struct RouteGroup {
		Route* route1;
		Route* route2;
		Route* route3;
	};
	
	Settlement(int x, int y, TileGroup tiles, SettlementGroup settlements, RouteGroup routes);
	
	/**
	 * determine the current level of 3 different levels of settlement
	 * @return an enum of EMPTY, SETTLEMENT, OR CITY
	 */
	SettlementLevel getLevel() const;
	/**
	 * change the settlement level; is used for construction
	 * @param level the new desired settlement level
	 */
	void setLevel(SettlementLevel level);
	
private:
	static const int ADJ_TILE_COUNT;
	static const int ADJ_SETTLEMENT_COUNT;
	static const int ADJ_ROUTE_COUNT;
	
	int x;
	int y;
	
	SettlementLevel level;
	
};

#endif // SETTLERS_OF_CATAN_SETTLEMENT_H_