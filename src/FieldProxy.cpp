#include "FieldProxy.h"


FieldProxy::FieldProxy()
{
}

eCell FieldProxy::getCell(const size_t & x, const size_t & y) const
{
	return eCell();
}

void FieldProxy::setCell(const size_t & x, const size_t & y, const eCell & cell)
{
}

void FieldProxy::setCell(const std::pair<size_t, size_t> coordinate, const eCell & cell)
{
}

void FieldProxy::addCells(const std::vector<std::vector<eCell>>& cells)
{
}

void FieldProxy::addShip(Ship * ship)
{
}

const std::deque<Ship*>* FieldProxy::getShips() const
{
	return nullptr;
}


FieldProxy::~FieldProxy()
{
}
