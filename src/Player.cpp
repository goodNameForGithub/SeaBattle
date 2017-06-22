#include "Player.h"
#include "ClassicFieldBilder.h"

Player::Player(): playerField_(nullptr), enamyField_(nullptr)
{
}


void Player::show() const
{
	if(playerField_ != nullptr)
		playerField_->show();
	if(enamyField_ != nullptr)
		enamyField_->show();
}

void Player::setPlayerField()
{
	ClassicFieldBilder classicFieldBilder;
	classicFieldBilder.buildEmprtyField();
	classicFieldBilder.buildShip(eTypeOfShip::FOUR_DECKER);
	classicFieldBilder.buildShip(eTypeOfShip::THREE_DECKER);
	classicFieldBilder.buildShip(eTypeOfShip::THREE_DECKER);
	classicFieldBilder.buildShip(eTypeOfShip::TWO_DECKER);
	classicFieldBilder.buildShip(eTypeOfShip::TWO_DECKER);
	classicFieldBilder.buildShip(eTypeOfShip::TWO_DECKER);
	classicFieldBilder.buildShip(eTypeOfShip::SINGL_DECKER);
	classicFieldBilder.buildShip(eTypeOfShip::SINGL_DECKER);
	classicFieldBilder.buildShip(eTypeOfShip::SINGL_DECKER);
	classicFieldBilder.buildShip(eTypeOfShip::SINGL_DECKER);
	playerField_ = classicFieldBilder.getField();
}

Player::~Player()
{
}
