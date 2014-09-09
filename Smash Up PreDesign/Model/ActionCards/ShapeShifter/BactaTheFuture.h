#pragma once

#include <ActionCard.h>

class BactaTheFuture : public ActionCard
{
public:
	BactaTheFuture(Player *owner);
	virtual void play();
	virtual bool fPlay(Player *player);
};