//
// Created by shayr on 23/11/2022.
//

#ifndef MVNE_WET1_TEAM_H
#define MVNE_WET1_TEAM_H
#include "Tree.h"
#include "PlayerRank.h"
#include "Player.h"
#include "CompleteTeam.h"
class Team {
public:
    Team(int teamId, int points, int goals = 0, int cards = 0, int numOfPlayers = 0, int gamesPlayed = 0);
private:
    int m_teamId;
    int m_points;
    int m_goals;
    int m_cards;
    //ADD players Tree
    int m_numOfPlayers;
    int m_gamesPlayed;
    int m_numOfGoalkeepers;
    CompleteTeam* m_completeTeam;
    Tree<Player> m_players;
    Tree<PlayerRank> m_TeamPlayersRank;
};


#endif //MVNE_WET1_TEAM_H
