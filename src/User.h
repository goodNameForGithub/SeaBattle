#pragma once
#include "Player.h"
class User :
	public Player
{
public:
	User();

	virtual void shoot();
	virtual bool check()const;
	virtual void addEnamyField(const Field * field);
	//virtual void show()const;

	virtual ~User();
};

