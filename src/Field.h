#pragma once

#include <vector>
#include <deque>

#include "Ship.h"

enum class eCell {
	EMPTY, MISS, DAMAGED, UNDAMAGED
};


class Field
{
public:
	Field();
	
	virtual eCell getCell(const size_t& x, const size_t& y)const = 0 ;
	virtual void setCell(const size_t& x, const size_t& y, const eCell& cell) = 0;
	virtual void setCell(const std::pair<size_t, size_t> coordinate, const eCell& cell) = 0;

	virtual size_t getSize()const = 0;

	virtual void addCells(const std::vector<std::vector<eCell>>& cells) = 0;
	virtual void addShip(Ship* ship) = 0;
	virtual const std::deque<Ship*>* getShips()const = 0;
	virtual void show()const;
	//virtual eStatus getStatus()const;

	virtual ~Field() = 0;
};

