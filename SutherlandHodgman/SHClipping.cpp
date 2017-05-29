#include "SHClipping.h"

std::vector<sf::Vector2f> SHClipping::ClipPolygon(const std::vector<sf::Vector2f>& polygon, const std::vector<sf::Vector2f>& clippingPlane)
{
	std::vector<sf::Vector2f> result;
	std::vector<sf::Vector2f> currShape = polygon;

	sf::Vector2f s, e, intersectionPoint;
	
	for (int i = 0; i < clippingPlane.size() - 1; ++i)
	{
		result.clear();
		Edge clipEdge(clippingPlane[i], clippingPlane[i + 1]);
		s = currShape.back();
		for (int j = 0; j < currShape.size(); ++j)
		{
			e = currShape[j];
			//IsOnRight = true means point is "inside" plane
  			if (clipEdge.IsOnRight(s))
			{
				if (!clipEdge.IsOnRight(e))
				{
					/*if (sfmath::RayLineIntersect(sfmath::Ray(clipEdge.start, clipEdge.end- clipEdge.start), s, e, intersectionPoint))
						result.push_back(intersectionPoint);*/
					if (sfmath::InfLineInfLineIntersect(sfmath::Ray(s, e - s), sfmath::Ray(clipEdge.start, clipEdge.end - clipEdge.start), intersectionPoint))
						result.push_back(intersectionPoint);
				}
				else
					result.push_back(e);
			}
			else if (clipEdge.IsOnRight(e))
			{
				if (sfmath::InfLineInfLineIntersect(sfmath::Ray(s, e - s), sfmath::Ray(clipEdge.start, clipEdge.end - clipEdge.start), intersectionPoint))
					result.push_back(intersectionPoint);
				result.push_back(e);
			}
			s = e;
		}

		currShape = result;
	}

	result.clear();
	Edge clipEdge(clippingPlane.back(), clippingPlane[0]);
	s = currShape.back();
	s = currShape.back();
	for (int j = 0; j < currShape.size(); ++j)
	{
		e = currShape[j];
		//IsOnRight = true means point is "inside" plane
		if (clipEdge.IsOnRight(s))
		{
			if (!clipEdge.IsOnRight(e))
			{
				if (sfmath::InfLineInfLineIntersect(sfmath::Ray(s, e - s), sfmath::Ray(clipEdge.start, clipEdge.end - clipEdge.start), intersectionPoint))
					result.push_back(intersectionPoint);
			}
			else
				result.push_back(e);
		}
		else if (clipEdge.IsOnRight(e))
		{
			if (sfmath::InfLineInfLineIntersect(sfmath::Ray(s, e - s), sfmath::Ray(clipEdge.start, clipEdge.end - clipEdge.start), intersectionPoint))
				result.push_back(intersectionPoint);
			result.push_back(e);
		}
		s = e;
	}

	return result;
}