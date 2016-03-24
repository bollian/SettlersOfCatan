#include <Tile.hpp>

const int Tile::ADJ_TILE_COUNT = 6;
const int Tile::ADJ_SETTLEMENT_COUNT = 6;
const int Tile::ADJ_ROUTE_COUNT = 6;

Tile::Tile(int x, int y, TileType type, int dice, TileGroup tiles, SettlementGroup settlements, RouteGroup routes) :
	Node(x, y, ADJ_TILE_COUNT, ADJ_SETTLEMENT_COUNT, ADJ_ROUTE_COUNT),
	
	type(type),
	dice_value(dice),
	robber(false)
{
	setAdjTile(0, tiles.tile1);
	setAdjTile(1, tiles.tile2);
	setAdjTile(2, tiles.tile3);
	setAdjTile(3, tiles.tile4);
	setAdjTile(4, tiles.tile5);
	setAdjTile(5, tiles.tile6);
	
	setAdjSettlement(0, settlements.settlement1);
	setAdjSettlement(1, settlements.settlement2);
	setAdjSettlement(2, settlements.settlement3);
	setAdjSettlement(3, settlements.settlement4);
	setAdjSettlement(4, settlements.settlement5);
	setAdjSettlement(5, settlements.settlement6);
	
	setAdjRoute(0, routes.route1);
	setAdjRoute(1, routes.route2);
	setAdjRoute(2, routes.route3);
	setAdjRoute(3, routes.route4);
	setAdjRoute(4, routes.route5);
	setAdjRoute(5, routes.route6);
}

Tile::TileType Tile::getType() const
{
	return type;
}

Resource Tile::convertTileTypeToResource(TileType type)
{
	switch (type) {
	case TileType::BRICK:
		return Resource::BRICK;
	case TileType::GRAIN:
		return Resource::GRAIN;
	case TileType::LUMBER:
		return Resource::LUMBER;
	case TileType::ORE:
		return Resource::ORE;
	case TileType::WOOL:
		return Resource::WOOL;
	case TileType::SEA:
	case TileType::DESERT:
		return Resource::NONE;
	}
}

int Tile::getDiceValue() const
{
	return dice_value;
}

bool Tile::hasRobber() const
{
	return robber;
}

void Tile::setRobber(bool has_robber)
{
	robber = has_robber;
}
