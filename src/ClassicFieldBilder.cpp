#include <iostream>
#include <ctime>

#include "ClassicFieldBilder.h"



ClassicFieldBilder::ClassicFieldBilder(const eFieldBilderType & fieldBilderType) :
	FieldBilder(fieldBilderType), field_(nullptr)
{
}

Field* ClassicFieldBilder::getField()
{
	Field* field = field_;
	field_ = nullptr;
	return field;
}


void ClassicFieldBilder::buildEmprtyField()
{
	using std::vector;
	field_ = new RealField();
	vector<eCell> cellsRow(fieldSize, eCell::EMPTY);
	vector<vector<eCell>> cellsField(fieldSize, cellsRow);
	field_->addCells(cellsField);
}

void ClassicFieldBilder::buildShip(const eTypeOfShip& typeOfShip)
{
	const std::deque<Ship*>* ships = field_->getShips();
	Ship* ship = nullptr;
	bool correctShip;

	do
	{
		if (ship != nullptr)
			delete ship;
		if (getFieldBilderType() == eFieldBilderType::RANDOM)
		{
			ship = createRandomShip(typeOfShip);
		}
		else
		{
			ship = createCustomShip(typeOfShip);
		}
		if (ships->size() > 0)
		{
			if (isShipTouchAnotherShip(*ship))
			{
				correctShip = false;
			}
			else
			{
				correctShip = true;
			}
		}
		if (isShipFitInField(*ship))
		{
			correctShip = true;
		}
		else
		{
			correctShip = false;
		}
	} while (!correctShip);

	field_->addShip(ship);

	std::pair<size_t, size_t> coordinate = ship->getCoordinate();
	for (size_t i = 0; i < ship->getTypeOfShip(); ++i)
	{
		field_->setCell(coordinate, eCell::UNDAMAGED);
		if (ship->getDirection() == eDirection::DOWN)
		{
			++(coordinate.second);
		}
		else
		{
			++(coordinate.first);
		}
	}
}

ClassicFieldBilder::~ClassicFieldBilder()
{
	if (field_ != nullptr)
		delete field_;
}

bool ClassicFieldBilder::isShipFitInField(const Ship & ship) const
{
	std::pair<size_t, size_t> coordinate = ship.getCoordinate();

	switch (ship.getDirection())
	{
	case eDirection::DOWN:
		if (coordinate.first < fieldSize &&
			(coordinate.second + ship.getTypeOfShip()) < fieldSize)
			return true;
		break;

	case eDirection::RIGHT:
		if (coordinate.second < fieldSize &&
			(coordinate.first + ship.getTypeOfShip()) < fieldSize)
			return true;
		break;

	default:
		break;
	}
	return false;
}

bool ClassicFieldBilder::isShipTouchAnotherShip(const Ship & ship) const
{
	std::pair<size_t, size_t> coordinate = ship.getCoordinate();

	for (size_t i = 0; i < ship.getTypeOfShip(); ++i)
	{
		if (isCorrectCoordinate(coordinate.first + 1, coordinate.second) &&
			field_->getCell(coordinate.first + 1, coordinate.second) != eCell::EMPTY) return true;

		if (isCorrectCoordinate(coordinate.first + 1, coordinate.second + 1) &&
			field_->getCell(coordinate.first + 1, coordinate.second + 1) != eCell::EMPTY) return true;

		if (isCorrectCoordinate(coordinate.first + 1, coordinate.second - 1) &&
			field_->getCell(coordinate.first + 1, coordinate.second - 1) != eCell::EMPTY) return true;

		if (isCorrectCoordinate(coordinate.first, coordinate.second + 1) &&
			field_->getCell(coordinate.first, coordinate.second + 1) != eCell::EMPTY) return true;

		if (isCorrectCoordinate(coordinate.first, coordinate.second - 1) &&
			field_->getCell(coordinate.first, coordinate.second - 1) != eCell::EMPTY) return true;

		if (isCorrectCoordinate(coordinate.first - 1, coordinate.second + 1) &&
			field_->getCell(coordinate.first - 1, coordinate.second + 1) != eCell::EMPTY) return true;

		if (isCorrectCoordinate(coordinate.first - 1, coordinate.second) &&
			field_->getCell(coordinate.first - 1, coordinate.second) != eCell::EMPTY) return true;

		if (isCorrectCoordinate(coordinate.first - 1, coordinate.second - 1) &&
			field_->getCell(coordinate.first - 1, coordinate.second - 1) != eCell::EMPTY) return true;

		if (ship.getDirection() == eDirection::DOWN)
		{
			++(coordinate.second);
		}
		else if (ship.getDirection() == eDirection::RIGHT)
		{
			++(coordinate.first);
		}
	}

	return false;
}

bool ClassicFieldBilder::isCorrectCoordinate(const size_t & x, const size_t y) const
{
	if (0 <= x && x < fieldSize && 0 <= y && y < fieldSize)
		return true;
	else
		return false;
}

Ship* ClassicFieldBilder::createRandomShip(const eTypeOfShip& typeOfShip) const
{
	srand(time(0));
	size_t x, y;
	eDirection direction;

	x = rand() % fieldSize;
	y = rand() % fieldSize;

	switch (rand() % (sizeof(eDirection) / sizeof(int)))
	{
	case eDirection::DOWN:
		direction = eDirection::DOWN;
		break;

	case eDirection::RIGHT:
		direction = eDirection::RIGHT;
		break;

	default:
		direction = eDirection::RIGHT;
		break;
	}

	return new Ship(x, y, typeOfShip, direction);
}

Ship* ClassicFieldBilder::createCustomShip(const eTypeOfShip & typeOfShip) const
{
	using std::cin;
	using std::cout;
	using std::endl;

	size_t x, y;
	eDirection direction;

	cout << "Enter pisition: ";
	const size_t nSimbols = 2;
	char xy[nSimbols];
	cin.get(xy, nSimbols);

	x = xy[0] - 'a';
	y = xy[1];

	cout << "\nEnter direction(r/d): ";
	char userDirection;
	cin >> userDirection;
	switch (userDirection)
	{
	case 'r':
		direction = eDirection::RIGHT;
		break;

	case 'd':
		direction = eDirection::DOWN;
		break;

	default:
		direction = eDirection::RIGHT;
		break;
	}

	return new Ship(x, y, typeOfShip, direction);
}

//bool ClassicFieldBilder::isShipFitInField(const size_t & x, const size_t & y, const eTypeOfShip & typeOfShip, const eDirection & direction) const
//{
//	
//	return false;
//}

const size_t ClassicFieldBilder::fieldSize = 10;