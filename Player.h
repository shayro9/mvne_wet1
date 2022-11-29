//
// Created by shayr on 23/11/2022.
//

#ifndef MVNE_WET1_PLAYER_H
#define MVNE_WET1_PLAYER_H
//#include "Tree.h"
//#include "Team.h"
//#include "PlayerRank.h"
//#include "worldcup23a1.h"

class Player {
    int m_playerId;
    int m_teamId;
    int m_gamesPlayed;
    int m_gamesTeamPlayedBefore;
    int m_goals;
    int m_cards;
    bool m_goalKeeper;
    int* m_gamesTeamPlayed;
    PlayerRank* m_playerRank;
    PlayerRank* m_groupPlayerRank;
    Team* m_team;



public:
    Player(int playerId, int teamId, int gamesPlayed, int goals, int cards, bool goalKeeper);
    ~Player() = default;
   // bool operator<(const Player& player) const;
  //  bool operator==(const Player& player) const;

};

friend bool operator>(const Player& player1, const Player player2);

#endif //MVNE_WET1_PLAYER_H
