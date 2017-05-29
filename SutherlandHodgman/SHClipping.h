#ifndef SH_CLIPPING_H
#define SH_CLIPPING_H

#include <SFML\Graphics.hpp>
#include <vector>
#include "Math.h"

/*

	REMINDER:
	SFML positive Y is down, so counter-clockwise is mirrored

*/

class SHClipping
{
public:
	std::vector<sf::Vector2f> ClipPolygon(const std::vector<sf::Vector2f>& polygon, const std::vector<sf::Vector2f>& clippingPlane);

private:
	struct Edge
	{
		Edge(const sf::Vector2f& s, const sf::Vector2f e)
		{
			start = s;
			end = e;
			normal.x = -e.y + s.y;
			normal.y = e.x - s.x;
		}

		bool IsOnRight(sf::Vector2f point)
		{
			return ((point.x - start.x)*(end.y - start.y) - (point.y - start.y)*(end.x - start.x)) > 0;
		}

		sf::Vector2f start, end, normal;
	};
};

#endif