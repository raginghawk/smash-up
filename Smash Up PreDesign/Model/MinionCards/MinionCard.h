#pragma once

#include <Card.h>

class ActionCard;

class MinionCard : public Card
		{
	public:
		MinionCard(Player *owner);

#pragma region Members
		virtual bool isMinion();
		virtual bool isAffectable();
		bool hasTalent();

		int printedPower();
		virtual int currentPower();
		virtual int currentPower(MinionCard *card);
		
		std::vector<ActionCard *> actionsOnMinion();		
	
		int powerModification();
#pragma endregion

		void modifyDestroyCount(int modification);
		void modifyCurrentPower(int modification);
		void modifyAffectAbleCount(int modification);

#pragma region Virtual
		virtual void removeAllActions();

		virtual bool fDestroyable();
		virtual bool fDestroyable(MinionCard *card);
		virtual bool destroy();
		virtual bool destroy(MinionCard *card);
		
		virtual bool fPlay(Player *player);
		virtual bool fPlay(Player *player, Base *base);
		virtual void play(Base *base);
		virtual void play(Base *base, MinionCard *card);
				
		virtual bool fMovable(Base *newBase);
		virtual void move(Base *newBase);
		
		virtual void discard();
		virtual void discard(MinionCard *minionCard);
		
		virtual void useTalent(Player *owner, MinionCard *card);

		void returnToOwnersHand();

		static std::vector<MinionCard *> minionsWithPowerLessThan(int limPower, std::vector<MinionCard *> options);
#pragma endregion

	private:
		int _powerModification;
		int _affectableCounter;
		int _destroyProtectionCounter;

	protected:
		bool _talent;
		int _printedPower;
		std::vector<ActionCard *> _actions;
};