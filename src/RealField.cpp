#include "RealField.h"


RealField::RealField()
{
}

eCell RealField::getCell(const size_t & x, const size_t & y) const
{
	return cells_[x][y];
}

void RealField::setCell(const size_t & x, const size_t & y, const eCell & cell)
{
	cells_[x][y] = cell;
}

void RealField::setCell(const std::pair<size_t, size_t> coordinate, const eCell & cell)
{
	cells_[coordinate.first][coordinate.second] = cell;
}

size_t RealField::getSize() const
{
	return cells_.size();
}


void RealField::addCells(const std::vector<std::vector<eCell>>& cells)
{
	cells_ = cells;
}

void RealField::addShip(Ship * ship)
{
	ships_.push_back(ship);
}

const std::deque<Ship*>* RealField::getShips() const
{
	return &ships_;
}

RealField::~RealField()
{
}
