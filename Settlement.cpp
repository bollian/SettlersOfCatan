#include <Settlement.hpp>

const int Settlement::ADJ_TILE_COUNT = 3;
const int Settlement::ADJ_SETTLEMENT_COUNT = 3;
const int Settlement::ADJ_ROUTE_COUNT = 3;

Settlement::Settlement(int x, int y, TileGroup tiles, SettlementGroup settlements, RouteGroup routes) :
	Node(x, y, ADJ_TILE_COUNT, ADJ_SETTLEMENT_COUNT, ADJ_ROUTE_COUNT),
	
	level(Settlement::EMPTY)
{
	setAdjTile(0, tiles.tile1);
	setAdjTile(1, tiles.tile2);
	setAdjTile(2, tiles.tile3);
	
	setAdjSettlement(0, settlements.settlement1);
	setAdjSettlement(1, settlements.settlement2);
	setAdjSettlement(2, settlements.settlement3);
	
	setAdjRoute(0, routes.route1);
	setAdjRoute(1, routes.route2);
	setAdjRoute(2, routes.route3);
}

Settlement::SettlementLevel Settlement::getLevel() const
{
	return level;
}

void Settlement::setLevel(SettlementLevel level)
{
	this->level = level;
}
