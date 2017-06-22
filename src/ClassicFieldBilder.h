#pragma once

#include <vector>

#include "FieldBilder.h"

class ClassicFieldBilder : public FieldBilder
{
public:
	ClassicFieldBilder(const eFieldBilderType & fieldBilderType = eFieldBilderType::RANDOM);

	virtual Field* getField();
	virtual void buildEmprtyField();
	virtual void buildShip(const eTypeOfShip& typeOfShip);

	~ClassicFieldBilder();

private:
	const static size_t fieldSize;
	Field * field_;
	bool isShipFitInField(const Ship & ship)const;
	bool isShipTouchAnotherShip(const Ship & ship)const;
	bool isCorrectCoordinate(const size_t & x, const size_t y)const;
	Ship* createRandomShip(const eTypeOfShip& typeOfShip)const;
	Ship* createCustomShip(const eTypeOfShip& typeOfShip)const;
	//void showMessageIncorrectPosition()const;
};