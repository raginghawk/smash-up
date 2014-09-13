#include <vector>
#include <map>

class Player;
class MinionCard;
class ActionCard;
class Event;


class Base
{
public:
	Base(std::vector<Player *>players);
	~Base();
#pragma region Members
	std::vector<MinionCard *> &minionsOnBase(); // TODO refactor to remove onBase... its a function of the base unneeded details
	std::vector<ActionCard *> &actionsOnBase();
	std::vector<MinionCard *> minionsFromPlayer(Player *player);
	std::vector<MinionCard *> minionsFromPlayerWithPowerLessThan(Player *player, int limPower);
	std::vector<MinionCard *> minionsWithPowerLessThan(int limPower);
	void modifyPower(int modification, Player *owner);
	Event * baseDidScore();
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
	Event * _baseDidScore;
	std::vector<MinionCard *> _minionsOnBase;
	std::vector<ActionCard *> _actionsOnBase;
	std::map<Player *, int> _powerModification;

	std::vector<MinionCard *> Base::minionsWithPowerLessThan(int limPower, std::vector<MinionCard *> options);
};