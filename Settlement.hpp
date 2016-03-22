#ifndef SETTLERS_OF_CATAN_SETTLEMENT_H_
#define SETTLERS_OF_CATAN_SETTLEMENT_H_

#include <Catan.hpp>

class Settlement
{
public:
	enum SettlementType {
		EMPTY,
		SETTLEMENT,
		CITY	
	};
	
	struct TileTuple {
		Tile* tile1;
		Tile* tile2;
		Tile* tile3;	
	};
	
	struct SettlementTuple {
		Settlement* settlement1;
		Settlement* settlement2;
		Settlement* settlement3;
	};
	
	struct RouteTuple {
		Route* route1;	
		Route* route2;
		Route* route3;
	};
	
	Settlement(int x, int y, TileTuple tiles, SettlementTuple settlements, RouteTuple routes);
	
private:
	int x;
	int y;
	
	SettlementType type;
	Player* owner;
	
	TileTuple tiles;
	SettlementTuple settlements;
	RouteTuple routes;
	
};

#endif // SETTLERS_OF_CATAN_SETTLEMENT_H_