//
// Created by amida on 25/11/2022.
//

#ifndef MVNE_WET1_PLAYERRANK_H
#define MVNE_WET1_PLAYERRANK_H

#endif //MVNE_WET1_PLAYERRANK_H
#include "LinkedList.h"

class PlayerRank{
    int m_playerId;
    int m_goals;
    int m_cards;
    LinkedListNode<int>* m_playerRankNode;
public:
    PlayerRank(int playerId, int goals, int cards, LinkedListNode<int>* playerRankNode);
    ~PlayerRank() = default;
 //   bool operator<(const PlayerRank& playerRank) const;
  //  bool operator==(const PlayerRank& playerRank) const;
  //  int getId() const;
};

friend bool operator>(const Player& player1, const Player player2);