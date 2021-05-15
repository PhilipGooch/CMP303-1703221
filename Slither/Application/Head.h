#pragma once
#include <SFML/Graphics.hpp>
#include "Segment.h"

class Head : public Segment
{
public:
	Head(sf::RenderWindow* window, sf::Vector2f position, float radius, sf::Color colour, int ID);
	~Head();

public:
	void update(float deltaTime);
	
private:
	sf::Vector2f lastVelocity_;
	float angle_;
	float lastAngle_;
	float maxAngle_;
};

