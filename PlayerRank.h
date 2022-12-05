

#ifndef MVNE_WET1_PLAYERRANK_H
#define MVNE_WET1_PLAYERRANK_H
//#include "LinkedList.h"
#include "List.h"
//#include "CompleteTeam.h"
//#include "Team.h"

class PlayerRank{
public:
    PlayerRank(int playerId, int goals=0, int cards=0);
    ~PlayerRank() = default;
    PlayerRank() = default;

    int getId() const;
    int getGoals() const;
    int getCards() const;

    void setPlayerNode(LNode<PlayerRank>* node);
    LNode<PlayerRank>* getPlayerNode() const;


    friend bool operator== (const PlayerRank&, const PlayerRank&);
    friend bool operator< (const PlayerRank&, const PlayerRank&);

    operator int() const;
  //  int getId() const;

private:
    int m_playerId;
    int m_goals;
    int m_cards;
    LNode<PlayerRank>* m_playerNode;

    //LinkedListNode<int>* m_playerRankNode;
};

bool operator!= (const PlayerRank&, const PlayerRank&);
bool operator> (const PlayerRank&, const PlayerRank&);
bool operator<= (const PlayerRank&, const PlayerRank&);
bool operator>= (const PlayerRank&, const PlayerRank&);

#endif //MVNE_WET1_PLAYERRANK_H