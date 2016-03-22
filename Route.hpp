#ifndef SETTLERS_OF_CATAN_ROUTE_H_
#define SETTLERS_OF_CATAN_ROUTE_H_

#include <Catan.hpp>
#include <Node.hpp>

class Route : public Node
{
public:	
	enum RouteLevel {
		EMPTY,
		ROAD,
		BOAT
	};
	
	enum RouteType {
		LAND,
		COAST,
		SEA
	};
	
	struct TileGroup {
		Tile* tile1;
		Tile* tile2;
	};
	
	struct SettlementGroup {
		Settlement* settlement1;
		Settlement* settlement2;	
	};
	
	struct RouteGroup {
		Route* route1;
		Route* route2;
		Route* route3;
		Route* route4;	
	};
	
	Route(int x, int y, TileGroup tiles, SettlementGroup settlements, RouteGroup routes);
	
	RouteLevel getLevel() const;
	RouteType getType() const;
	
	/**
	 * used for "constructing" roads & boats
	 * @param type the type of route: road or boat
	 */
	void setLevel(RouteLevel type);
	
private:
	static const int ADJ_TILE_COUNT;
	static const int ADJ_SETTLEMENT_COUNT;
	static const int ADJ_ROUTE_COUNT;
	
	RouteLevel level;
		
};

#endif // SETTLERS_OF_CATAN_ROUTE_H_