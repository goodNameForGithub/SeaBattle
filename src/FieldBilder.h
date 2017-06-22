#pragma once

#include "RealField.h"

enum eFieldBilderType
{
	RANDOM, 
	CUSTOM
};


class FieldBilder
{
public:
	FieldBilder(const eFieldBilderType & fieldBilderType);

	virtual Field* getField() = 0;
	virtual void buildEmprtyField() = 0;
	virtual void buildShip(const eTypeOfShip& typeOfShip) = 0;
	
	void setFieldBilderType(const eFieldBilderType & fieldBilderType);
	eFieldBilderType getFieldBilderType()const;

	virtual ~FieldBilder() = 0;

private:
	eFieldBilderType fieldBilderType_;

};

