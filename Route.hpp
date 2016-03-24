#ifndef SETTLERS_OF_CATAN_ROUTE_H_
#define SETTLERS_OF_CATAN_ROUTE_H_

#include <Catan.hpp>
#include <Node.hpp>
#include <Resource.hpp>

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
	/**
	 * used for ports (though not coast, that's determined by looking at adjacent tiles)
	 */
	Route(int x, int y, Resource resource, int ratio, TileGroup tiles, SettlementGroup settlements, RouteGroup routes);
	
	RouteLevel getLevel() const;
	RouteType getType() const;
	
	/**
	 * used for "constructing" roads & boats
	 * @param type the type of route: road or boat
	 */
	void setLevel(RouteLevel type);
	
	/**
	 * gets the resource provided by this port
	 * @return NONE if this is not a port or a generic port, otherwise the resource that can be traded at this port
	 */
	Resource getPortResource() const;
	/**
	 * the ratio at which resources can be traded at this port
	 * @return -1 if not a port, the number of resource cards that have to be given up to gain another otherwise
	 */
	int getPortRatio() const;
	/**
	 * checks to see if settlements adjacent to this route have access to a port
	 * @return true if this is a coastal route with a port
	 */
	bool isPort() const;
	
private:
	static const int ADJ_TILE_COUNT;
	static const int ADJ_SETTLEMENT_COUNT;
	static const int ADJ_ROUTE_COUNT;
	
	void setupAdjacencies(TileGroup tiles, SettlementGroup settlements, RouteGroup routes);
	
	RouteLevel level;
	
	Resource port_resource;
	int port_ratio;
		
};

#endif // SETTLERS_OF_CATAN_ROUTE_H_