#pragma once

#include <Card.h>

class ActionCard;

class MinionCard : public Card
		{
	public:
		MinionCard(Player *owner);
#pragma region Members
		virtual bool isMinion();
		std::vector<ActionCard *> actionsOnMinion();
		int printedPower();
		virtual int currentPower();
		virtual bool isAffectable();
		bool hasTalent();
#pragma endregion
		virtual void removeAllActions();

		virtual void destory();
		virtual void play(Base *base);
		virtual void play();
		virtual void play(MinionCard *minion);
		virtual void move(Base *newBase, Base *oldBase);
		virtual void discard();
		virtual void useTalent(Player *owner);
	protected:
		int _printedPower;
		std::vector<ActionCard *> _actions;
		bool _talent;
};