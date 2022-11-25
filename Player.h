//
// Created by shayr on 23/11/2022.
//

#ifndef MVNE_WET1_PLAYER_H
#define MVNE_WET1_PLAYER_H


class Player {
    int m_playerId;
    int m_teamId;
    int m_gamesPlayed;
    int m_gamesTeamPlayedBefore;
    int m_goals;
    int m_cards;
    bool m_goalKeeper;
    int* m_gamesTeamPlayed;

public:
    Player(int playerId, int teamId, int gamesPlayed, int goals, int cards, bool goalKeeper);
};


#endif //MVNE_WET1_PLAYER_H
