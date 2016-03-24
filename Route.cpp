#include <stdexcept>

#include <NotImplementedException.hpp>
#include <Route.hpp>
#include <Tile.hpp>

using namespace std;

const int Route::ADJ_TILE_COUNT = 2;
const int Route::ADJ_SETTLEMENT_COUNT = 2;
const int Route::ADJ_ROUTE_COUNT = 4;
	
Route::Route(int x, int y, TileGroup tiles, SettlementGroup settlements, RouteGroup routes) : Node(x, y, ADJ_TILE_COUNT, ADJ_SETTLEMENT_COUNT, ADJ_ROUTE_COUNT),
	level(Route::EMPTY),
	
	port_resource(Resource::NONE),
	port_ratio(-1)
{
	setupAdjacencies(tiles, settlements, routes);
}

Route::Route(int x, int y, Resource resource, int ratio, TileGroup tiles, SettlementGroup settlements, RouteGroup routes) :
	Node(x, y, ADJ_TILE_COUNT, ADJ_SETTLEMENT_COUNT, ADJ_ROUTE_COUNT),
	
	level(Route::EMPTY),
	
	port_resource(resource),
	port_ratio(ratio)
{
	setupAdjacencies(tiles, settlements, routes);
}

void Route::setupAdjacencies(TileGroup tiles, SettlementGroup settlements, RouteGroup routes)
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
	int adj_sea_count = 0;
	
	Tile* tile;
	for (int i = 0; i < ADJ_TILE_COUNT; ++i) {
		tile = getAdjTile(i);
		if (tile == nullptr || tile->getType() == Tile::SEA) {
			++adj_sea_count;
		}
	}
	
	switch (adj_sea_count) {
	case 0:
		return Route::LAND;
	case 1:
		return Route::COAST;
	case 2:
		return Route::SEA;
	default:
		throw logic_error("Calculated impossible number of adjacent sea tiles");
	}
}

Resource Route::getPortResource() const
{
	return port_resource;
}

int Route::getPortRatio() const
{
	return port_ratio;
}

bool Route::isPort() const
{
	return getType() == RouteType::COAST && port_ratio != -1;
}