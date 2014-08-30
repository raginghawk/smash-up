#include <vector>

class Player;
class MinionCard;
class ActionCard;


class Base
{
public:
	Base();
#pragma region Members
	std::vector<MinionCard *> minionsOnBase();
	std::vector<ActionCard *> actionsOnBase();
	void modifyPower(int modification, Player *owner);
#pragma endregion
	void moveMinion(MinionCard *minion);
	void playMinion(MinionCard *minion);
	void destroyMinion(MinionCard *minion);
	void removeMinion(MinionCard *minion);
private:
	std::vector<MinionCard *> _minionsOnBase;
	std::vector<ActionCard *> _actionsOnBase;
	std::vector<int> _powerModification;
};