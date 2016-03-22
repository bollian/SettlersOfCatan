#ifndef SETTLERS_OF_CATAN_TILE_H_
#define SETTLERS_OF_CATAN_TILE_H_

#include <Node.hpp>

class Tile : public Node
{
public:
	enum TileType {
		SEA,
		BRICK,
		GRAIN,
		LUMBER,
		ORE,
		WOOL
	}
	
	Tile(int x, int y, TileType type);
	
private:
	TileType type;
	
};

#endif // SETTLERS_OF_CATAN_TILE_H_