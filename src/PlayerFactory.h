#pragma once

#include "Player.h"


class PlayerFactory
{
public:
	PlayerFactory();

	Player* getUser()const;
	Player* getComputer()const;

	~PlayerFactory();
};

