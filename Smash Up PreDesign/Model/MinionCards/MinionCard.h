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
		void modifyDestoryCount(int modification);
		void modifyCurrentPower(int modification);
		void modifyAffectAbleCount(int modification);
		virtual void destroy();
		virtual void destroy(MinionCard *card);
		virtual bool fPlay(Player *player);
		virtual void play(Base *base, MinionCard *card);
		virtual void play(Base *base);
		virtual void play();
		virtual void play(MinionCard *minion, ActionCard *action);
		virtual bool fUpdate(UpdateVisibilityFlags *flags);
		virtual void update(Base *base);
		virtual void update(UpdateVisibilityFlags *minionCard);
		virtual void move(Base *newBase, Base *oldBase);
		virtual void discard();
		virtual void useTalent(Player *owner, MinionCard *card);

	private:
		int _powerModification;
		int _destoryProtectionCounter;
		int _affectableCounter;

	protected:
		int _printedPower;
		std::vector<ActionCard *> _actions;
		bool _talent;
};