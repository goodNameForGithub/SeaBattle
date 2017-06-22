#pragma once
#include "Player.h"

class Computer :
	public Player
{
public:
	Computer();

	virtual void shoot();
	virtual bool check()const;
	virtual void addEnamyField(const Field * field);

	virtual ~Computer();
};

