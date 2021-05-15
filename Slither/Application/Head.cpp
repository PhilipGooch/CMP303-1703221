#include "Head.h"

Head::Head(sf::RenderWindow* window, sf::Vector2f position, float radius, sf::Color colour, int ID) :
	Segment(window, position, radius, colour, ID)
{
	parent_ = nullptr;
}

Head::~Head()
{
}

void Head::update(float deltaTime)
{
	lastPosition_.x = position_.x;
	lastPosition_.y = position_.y;

	lastVelocity_.x = velocity_.x;
	lastVelocity_.y = velocity_.y;

	float magnitude = sqrt(pow(velocity_.x, 2) + pow(velocity_.y, 2));
	velocity_ /= magnitude;
	velocity_ *= speed_;

	lastAngle_ = atan2f(lastVelocity_.y, lastVelocity_.x);
	angle_ = atan2f(velocity_.y, velocity_.x) - lastAngle_;

	float pi = 3.141593f;
	if (angle_ < -pi)
		angle_ = pi - (angle_ - pi);
	if (angle_ > pi)
		angle_ = -(pi - (angle_ - pi));

	if (abs(angle_) > maxAngle_)
	{
		velocity_.x = lastVelocity_.x;
		velocity_.y = lastVelocity_.y;

		velocity_ /= magnitude;
		velocity_ *= speed_;
		


		float rotatedX = velocity_.x * cos(maxAngle_ * deltaTime * 0.07f) + velocity_.y * sin(maxAngle_ * deltaTime * 0.07f);
		float rotatedY = velocity_.x * -sin(maxAngle_ * deltaTime * 0.07f) + velocity_.x * cos(maxAngle_ * deltaTime * 0.07f);
		velocity_.x = rotatedX;
		velocity_.y = rotatedY;

	}
	velocity_ *=  (speed_ * deltaTime);
	position_ += velocity_;
	offset_ += velocity_;
}
