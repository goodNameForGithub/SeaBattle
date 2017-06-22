#include "Ship.h"



Ship::Ship(const size_t & x, const size_t & y, 
	eTypeOfShip typeOfShip, eDirection direction, 
	eStatus status): x_(x), y_(y),
	typeOfShip_(typeOfShip), direction_(direction),
	status_(status)
{
}

void Ship::setCoordinate(const size_t & x, const size_t & y)
{
	x_ = x;
	y_ = y;
}

std::pair<size_t, size_t> Ship::getCoordinate() const
{
	return std::pair<size_t, size_t>(x_, y_);
}

void Ship::setTypeOfShip(const eTypeOfShip & typeOfShip)
{
	typeOfShip_ = typeOfShip;
}

eTypeOfShip Ship::getTypeOfShip() const
{
	return typeOfShip_;
}

void Ship::setDirection(eDirection & direction)
{
	direction_ = direction;
}

eDirection Ship::getDirection() const
{
	return direction_;
}

void Ship::setStatus(const eStatus & status)
{
	status_ = status;
}

eStatus Ship::getStatus() const
{
	return status_;
}

Ship::~Ship()
{
}
