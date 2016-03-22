#ifndef SETTLERS_OF_CATAN_CATAN_H_
#define SETTLERS_OF_CATAN_CATAN_H_

#include <cstdio>
#include <stdexcept>

// this is where the circular dependencies end
class Player;
class Settlement;
class Tile;
class Route;

#define THROW_OUT_OF_RANGE char message[1023];\
	snprintf(message, 1023, "Index out of range in %s::%s", __FILE__, __func__);\
	throw out_of_range(message);

namespace Utils
{
	/**
	 * checks to see if a value is between two other values
	 * @param  value the value to check
	 * @param  min   the minimum value, inclusive
	 * @param  max   the maximum value, exclusive
	 * @return       true if value is between min and max
	 */
	bool valueInZone(int value, int min, int max);
}

#endif // SETTLERS_OF_CATAN_CATAN_H_