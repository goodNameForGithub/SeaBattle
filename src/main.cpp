#include "PlayerFactory.h"

int main()
{
	PlayerFactory fac;
	Player * user = fac.getUser();
	Player * computer = fac.getComputer();
	user->setPlayerField();
	user->show();
}