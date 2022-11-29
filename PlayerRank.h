//
// Created by amida on 25/11/2022.
//

#ifndef MVNE_WET1_PLAYERRANK_H
#define MVNE_WET1_PLAYERRANK_H

#endif //MVNE_WET1_PLAYERRANK_H
#include "LinkedList.h"

class PlayerRank{
public:
    explicit PlayerRank(int playerId, int goals, int cards);
    ~PlayerRank() = default;
    PlayerRank();
    friend bool operator== (const PlayerRank&, const PlayerRank&);
    friend bool operator< (const PlayerRank&, const PlayerRank&);
  //  int getId() const;

private:
    int m_playerId;
    int m_goals;
    int m_cards;
    LinkedListNode<int>* m_playerRankNode;
};

bool operator!= (const PlayerRank&, const PlayerRank&);
bool operator> (const PlayerRank&, const PlayerRank&);
bool operator<= (const PlayerRank&, const PlayerRank&);
bool operator>= (const PlayerRank&, const PlayerRank&);