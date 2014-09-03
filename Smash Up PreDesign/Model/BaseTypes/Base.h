#include <vector>
#include <map>

class Player;
class MinionCard;
class ActionCard;


class Base
{
public:
	Base(std::vector<Player *>players);
#pragma region Members
	std::vector<MinionCard *> minionsOnBase();
	std::vector<ActionCard *> actionsOnBase();
	void modifyPower(int modification, Player *owner);
	int breakingPoint;
#pragma endregion
	void moveMinion(MinionCard *minion);
	void playMinion(MinionCard *minion);
	void destroyMinion(MinionCard *minion);
	void removeMinion(MinionCard *minion);

	bool isBreaking();
	void discardBase(); /* This happens when a base scores. Everything on it has discard called*/
	void scoreBase();

	int currentPowerOnBase();
private:
	std::vector<MinionCard *> _minionsOnBase;
	std::vector<ActionCard *> _actionsOnBase;
	std::map<Player *, int> _powerModification;
};