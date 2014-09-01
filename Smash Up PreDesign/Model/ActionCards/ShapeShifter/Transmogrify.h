#pragma once

#include <ActionCard.h>

class Transmogrify : public ActionCard
{
public:
	Transmogrify(Player *owner);
	virtual void play();
};