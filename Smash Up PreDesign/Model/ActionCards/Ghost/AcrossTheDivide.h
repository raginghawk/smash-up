#pragma once

#include <ActionCard.h>

class AcrossTheDivide : public ActionCard
{
public:
	AcrossTheDivide::AcrossTheDivide(Player *owner);
	virtual void play();
};