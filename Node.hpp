#ifndef SETTLERS_OF_CATAN_NODE_H_
#define SETTLERS_OF_CATAN_NODE_H_

class Node
{
public:
	~Node();
	
	int getX() const;
	int getY() const;
	Player* getOwner() const;
	
	int getAdjTileCount() const;
	int getAdjSettlementCount() const;
	int getAdjRouteCount() const;
	
	Tile* getAdjTile(int index) const;
	Settlement* getAdjSettlement(int index) const;
	Route* getAdjRoute(int index) const;
	
	void setOwner(Player* player);

protected:
	Node(int x, int y, int adj_tile_count, int adj_settlement_count, int adj_route_count);
	
	void setAdjTile(int index, Tile* tile);
	void setAdjSettlement(int index, Settlement* settlement);
	void setAdjRoute(int index, Route* route);
	
private:
	int x;
	int y;
	
	Player* owner;
	
	// adjacent thingies
	const int adj_tile_count;
	const int adj_settlement_count;
	const int adj_route_count;
	Tile** adj_tiles;
	Settlement** adj_settlements;
	Route** adj_routes;
		
};

#endif // SETTLERS_OF_CATAN_NODE_H_