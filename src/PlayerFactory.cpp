#include "PlayerFactory.h"
#include "User.h"
#include "Computer.h"

PlayerFactory::PlayerFactory()
{
}

Player * PlayerFactory::getUser() const
{
	return new User();
}

Player * PlayerFactory::getComputer() const
{
	return new Computer();
}


PlayerFactory::~PlayerFactory()
{
}
