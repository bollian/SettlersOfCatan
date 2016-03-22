#include <Catan.hpp>
#include <Node.hpp>

using namespace std;

Node::Node(int x, int y, int adj_tile_count, int adj_settlement_count, int adj_route_count) :
	x(x),
	y(y),
	
	owner(nullptr),
	
	adj_tile_count(adj_tile_count),
	adj_settlement_count(adj_settlement_count),
	adj_route_count(adj_route_count),
	
	adj_tiles(new Tile*[adj_tile_count]),
	adj_settlements(new Settlement*[adj_settlement_count]),
	adj_routes(new Route*[adj_route_count])
{
	int i;
	for (i = 0; i < adj_tile_count; ++i)
	{
		adj_tiles[i] = nullptr;
	}
	
	for (i = 0; i < adj_settlement_count; ++i)
	{
		adj_settlements[i] = nullptr;
	}
	
	for (i = 0; i < adj_route_count; ++i)
	{
		adj_routes[i] = nullptr;
	}
}

Node::~Node()
{
	delete[] adj_tiles;
	delete[] adj_settlements;
	delete[] adj_routes;
}

int Node::getX() const
{
	return x;
}

int Node::getY() const
{
	return y;
}

Player* Node::getOwner() const
{
	return owner;
}

int Node::getAdjTileCount() const
{
	return adj_tile_count;
}

int Node::getAdjSettlementCount() const
{
	return adj_settlement_count;
}

int Node::getAdjRouteCount() const
{
	return adj_route_count;
}

Tile* Node::getAdjTile(int index) const
{
	if (Utils::valueInZone(index, 0, getAdjTileCount()))
	{
		return adj_tiles[index];
	}
	THROW_OUT_OF_RANGE
}

Settlement* Node::getAdjSettlement(int index) const
{
	if (Utils::valueInZone(index, 0, getAdjSettlementCount()))
	{
		return adj_settlements[index];
	}
	THROW_OUT_OF_RANGE
}

Route* Node::getAdjRoute(int index) const
{
	if (Utils::valueInZone(index, 0, getAdjRouteCount()))
	{
		return adj_routes[index];
	}
	THROW_OUT_OF_RANGE
}

void Node::setOwner(Player* player)
{
	this->owner = player;
}

void Node::setAdjTile(int index, Tile* tile)
{
	if (Utils::valueInZone(index, 0, getAdjTileCount()))
	{
		adj_tiles[index] = tile;
	}
	THROW_OUT_OF_RANGE
}

void Node::setAdjSettlement(int index, Settlement* settlement)
{
	if (Utils::valueInZone(index, 0, getAdjSettlementCount()))
	{
		adj_settlements[index] = settlement;
	}
	THROW_OUT_OF_RANGE
}

void Node::setAdjRoute(int index, Route* route)
{
	if (Utils::valueInZone(index, 0, getAdjRouteCount()))
	{
		adj_routes[index] = route;
	}
	THROW_OUT_OF_RANGE
}
