//
// Created by shayr on 23/11/2022.
//

#include "Player.h"
#include "Team.h"

Player::Player(int playerId, int teamId, int gamesPlayed, int goals, int cards, bool goalKeeper) : m_playerId(playerId), m_teamId(teamId), m_gamesPlayed(gamesPlayed), m_goals(goals),
                                                                    m_cards(cards), m_goalKeeper(goalKeeper){
    m_team = teams.find(teamId);
    m_gamesTeamPlayedBefore = m_team->m_gamesPlayed;
    m_gamesTeamPlayed = &m_team->m_gamesPlayed;
    m_playerRank = new PlayerRank(playerId, goals, cards);
    playersRank.insert
    m_groupPlayerRank = new PlayerRank(playerId, goals, cards);

}

bool Player::operator<(const Player& player) const {
    if (m_playerId < player.m_playerId){
        return true;
    }
    return false;
}

bool Player::operator==(const Player &player) const {
    return m_playerId == player.m_playerId;
}


bool operator>