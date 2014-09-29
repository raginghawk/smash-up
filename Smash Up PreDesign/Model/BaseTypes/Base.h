#include <vector>
#include <map>

class Player;
class MinionCard;
class ActionCard;
class Event;
enum Faction;

class Base
{
public:
	Base(std::vector<Player *>players);
	~Base();
#pragma region Members
	std::vector<MinionCard *> &minionsOnBase(); // TODO refactor to remove onBase... its a function of the base unneeded details
	std::vector<ActionCard *> &actionsOnBase();
	std::vector<MinionCard *> minionsFromPlayer(Player *player);
	std::vector<MinionCard *> otherPlayersMinions(Player *player);
	std::vector<MinionCard *> minionsFromPlayerWithPowerLessThan(Player *player, int limPower);
	std::vector<MinionCard *> minionsWithPowerLessThan(int limPower);
	std::vector<MinionCard *> minionsOfFaction(Faction faction);

	void modifyPower(int modification, Player *player);
	int powerModification(Player *player);

	Event * baseDidScore();
	int breakingPoint;
#pragma endregion
	void moveCard(MinionCard *minion);
	void moveCard(ActionCard *minion);
	void removeCard(MinionCard *minion);
	void removeCard(ActionCard *minion);

	void playMinion(MinionCard *minion);
	void destroyMinion(MinionCard *minion);

	void setPlayableMinionForOtherPlayers(Player *player, bool playable);
	void setPlaybleFromDiscardForPlayer(Player *player, bool playableFromDiscards);

	bool isBreaking();
	void discardBase(); /* This happens when a base scores. Everything on it has discard called*/
	void scoreBase();

	int currentPowerOnBase();
private:
	Event * _baseDidScore;
	std::vector<MinionCard *> _minionsOnBase;
	std::vector<ActionCard *> _actionsOnBase;
	std::map<Player *, int> _powerModification;
	std::map<Player *, bool> _minionPlayable;
	std::map<Player *, bool> _playableFromDiscards;

	std::vector<MinionCard *> Base::minionsWithPowerLessThan(int limPower, std::vector<MinionCard *> options);
};