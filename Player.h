//
// Created by shayr on 23/11/2022.
//

#ifndef MVNE_WET1_PLAYER_H
#define MVNE_WET1_PLAYER_H


struct Player {
    int m_playerId;
    int m_teamId;
    int m_gamesPlayed;
    int gamesTeamPlayedBefore;
    int m_goals;
    int m_cards;
    bool m_goalKeeper;
    int* gamesTeamPlayed;
};


#endif //MVNE_WET1_PLAYER_H
