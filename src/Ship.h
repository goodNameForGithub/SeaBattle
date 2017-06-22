#pragma once

#include <utility>


enum eDirection
{
	RIGHT, DOWN
};

enum eTypeOfShip
{
	SINGL_DECKER = 1, 
	TWO_DECKER = 2, 
	THREE_DECKER = 3, 
	FOUR_DECKER = 4
};

enum class eStatus
{
	UNDAMAGED, DAMAGED, DESTROYED
};

class Ship
{
public:
	Ship(const size_t& x = 0, const size_t& y = 0, 
		eTypeOfShip typeOfShip = eTypeOfShip::FOUR_DECKER, eDirection direction = eDirection::DOWN,
		eStatus status = eStatus::UNDAMAGED);

	void setCoordinate(const size_t& x, const size_t& y);
	std::pair<size_t, size_t> getCoordinate()const;
	
	void setTypeOfShip(const eTypeOfShip & typeOfShip);
	eTypeOfShip getTypeOfShip()const;
	
	void setDirection(eDirection & direction);
	eDirection getDirection()const; 

	void setStatus(const eStatus & status);
	eStatus getStatus()const;
		
	~Ship();

private:
	size_t x_;
	size_t y_;
	eTypeOfShip typeOfShip_;
	eDirection direction_;
	eStatus status_;

};

