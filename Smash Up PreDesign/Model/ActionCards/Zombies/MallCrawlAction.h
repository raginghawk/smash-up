#pragma once

#include <ActionCard.h>

class MallCrawlAction : public ActionCard
{
public:
	MallCrawlAction(Player *owner);
	virtual void play();
};