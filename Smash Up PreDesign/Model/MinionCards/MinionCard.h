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
		virtual int currentPower(MinionCard *card);
		virtual bool isAffectable();
		bool hasTalent();
		int powerModification();
#pragma endregion

		virtual void removeAllActions();
	
		void modifyCurrentPower(int modification);
		virtual void destroy();
		virtual void destroy(MinionCard *card);
		virtual void play(Base *base, MinionCard *card);
		virtual void play(Base *base);
		virtual void play();
		virtual void play(MinionCard *minion);
		virtual void move(Base *newBase, Base *oldBase);
		virtual void discard();
		virtual void useTalent(Player *owner, MinionCard *card);

	private:
		int _powerModification;

	protected:
		int _printedPower;
		std::vector<ActionCard *> _actions;
		bool _talent;
};