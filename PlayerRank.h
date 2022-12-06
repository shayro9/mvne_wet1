

#ifndef MVNE_WET1_PLAYERRANK_H
#define MVNE_WET1_PLAYERRANK_H
//#include "LinkedList.h"
#include "List.h"
//#include "CompleteTeam.h"
//#include "Team.h"

class Player;

class PlayerRank{
public:
    PlayerRank(int playerId, int goals=0, int cards=0);
    ~PlayerRank() = default;
    PlayerRank() = default;

    int getId() const;
    int getGoals() const;
    int getCards() const;
    int getConnectedPointers() const;
    void reducePointers();
    void connectPointer();

    LNode<PlayerRank>* getPlayerNode() const;
    Player* getPlayer() const;
    void setPlayerNode(LNode<PlayerRank>* node);
    void setPlayer(Player* player);


    friend bool operator== (const PlayerRank&, const PlayerRank&);
    friend bool operator< (const PlayerRank&, const PlayerRank&);

    operator int() const;
  //  int getId() const;

private:
    int m_playerId;
    int m_goals;
    int m_cards;
    int m_connectedPointers;
    LNode<PlayerRank>* m_playerNode;

    Player* m_player;

    //LinkedListNode<int>* m_playerRankNode;
};

bool operator!= (const PlayerRank&, const PlayerRank&);
bool operator> (const PlayerRank&, const PlayerRank&);
bool operator<= (const PlayerRank&, const PlayerRank&);
bool operator>= (const PlayerRank&, const PlayerRank&);

#endif //MVNE_WET1_PLAYERRANK_H