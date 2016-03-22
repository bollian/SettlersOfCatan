#include <NotImplementedException.hpp>
#include <Route.hpp>

const int Route::ADJ_TILE_COUNT = 2;
const int Route::ADJ_SETTLEMENT_COUNT = 2;
const int Route::ADJ_ROUTE_COUNT = 4;
	
Route::Route(int x, int y, TileGroup tiles, SettlementGroup settlements, RouteGroup routes) : Node(x, y, ADJ_TILE_COUNT, ADJ_SETTLEMENT_COUNT, ADJ_ROUTE_COUNT),
	level(Route::EMPTY)
{
	setAdjTile(0, tiles.tile1);
	setAdjTile(1, tiles.tile2);
	
	setAdjSettlement(0, settlements.settlement1);
	setAdjSettlement(1, settlements.settlement2);
	
	setAdjRoute(0, routes.route1);
	setAdjRoute(1, routes.route2);
	setAdjRoute(2, routes.route3);
	setAdjRoute(3, routes.route4);
}

Route::RouteLevel Route::getLevel() const
{
	return level;
}

Route::RouteType Route::getType() const
{
	throw NotImplementedException(__FILE__, __func__);
}