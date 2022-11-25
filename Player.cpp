//
// Created by shayr on 23/11/2022.
//

#include "Player.h"
#include "Team.h"

Player::Player(int playerId, int teamId, int gamesPlayed, int goals, int cards, bool goalKeeper) : m_playerId(playerId), m_teamId(teamId), m_gamesPlayed(gamesPlayed), m_goals(goals),
                                                                    m_cards(cards), m_goalKeeper(goalKeeper){
    Team *currTeam = teams.find(teamId);
    m_gamesTeamPlayedBefore = currTeam->m_gamesPlayed;
    m_gamesTeamPlayed = &currTeam->m_gamesPlayed;
}