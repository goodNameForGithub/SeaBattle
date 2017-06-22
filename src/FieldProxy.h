#pragma once

#include "Field.h"

class FieldProxy :
	public Field
{
public:
	FieldProxy();

	virtual eCell getCell(const size_t& x, const size_t& y)const;//
	virtual void setCell(const size_t& x, const size_t& y, const eCell& cell);
	virtual void setCell(const std::pair<size_t, size_t> coordinate, const eCell& cell);
	virtual size_t getSize()const = 0;
	virtual void addCells(const std::vector<std::vector<eCell>>& cells);
	virtual void addShip(Ship* ship);
	virtual const std::deque<Ship*>* getShips()const;//
	//virtual void show()const;

	virtual ~FieldProxy();
};

