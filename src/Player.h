#pragma once

#include "Field.h"

class Player
{
public:
	Player();

	virtual void shoot() = 0;
	virtual bool check()const = 0;
	virtual void addEnamyField(const Field * field) = 0;
	void show()const;
	
	void setPlayerField();
	Field* getPlayerField()const;

	void setEnamyField(Field* field);
	Field* getEnamyField()const;

	virtual ~Player() = 0;

private:
	Field* playerField_;
	const Field* enamyField_;
};

