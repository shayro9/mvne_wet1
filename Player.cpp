#include "Player.h"

Player::Player(int playerId, int teamId, int gamesPlayed, int goals, int cards, bool goalKeeper) :
    m_playerId(playerId),
    m_teamId(teamId),
    m_gamesPlayed(gamesPlayed),
    m_goals(goals),
    m_cards(cards),
    m_goalKeeper(goalKeeper)
{
    m_playerRank = new PlayerRank(playerId, goals, cards);
    m_groupPlayerRank = new PlayerRank(playerId, goals, cards);

    /*
    m_team = teams.find(teamId);
    m_gamesTeamPlayedBefore = m_team->m_gamesPlayed;
    m_gamesTeamPlayed = &m_team->m_gamesPlayed;
    playersRank.insert;
    */
}

Player::~Player() {
    delete(m_playerRank);
    delete(m_groupPlayerRank);
}

bool operator<(const Player& p1, const Player& p2) {
    if (p1.m_playerId < p2.m_playerId){
        return true;
    }
    return false;
}

bool operator==(const Player &p1, const Player& p2) {
    return p1.m_playerId == p2.m_playerId;
}

bool operator> (const Player &p1, const Player& p2){
    return p2 < p1;
}

bool operator!= (const Player &p1, const Player& p2){
    return !(p1==p2);
}

bool operator<=(const Player &p1, const Player& p2){
    return p1 < p2 || p1 == p2;
}

bool operator>=(const Player &p1, const Player& p2){
    return p2 <= p1;
}

int Player::getId() const{
    return m_playerId;
}

int Player::getGoals() const{
    return m_goals;
}

int Player::getCards() const{
    return m_cards;
}

PlayerRank *Player::getPlayerRank() {
    return m_playerRank;
}

PlayerRank *Player::getGroupPlayerRank() {
    return m_groupPlayerRank;
}

Team *Player::getTeam() {
    return m_team;
}

bool Player::isGoalKeeper() const {
    return m_goalKeeper;
}

void Player::updateStats(int games, int goals, int cards) {
    m_gamesPlayed += games;
    m_goals += goals;
    m_cards += cards;
}

int Player::getGamesPlayed() const {
    return m_gamesPlayed;
}

int Player::getGamesTeamPlayedBefore() const {
    return m_gamesTeamPlayedBefore;
}

void Player::setGamesTeamPlayedBefore(int games) {
    m_gamesTeamPlayedBefore = games;
}

void Player::setTeam(Team *t, int gamesPlayed, int* games) {
    m_team = t;
    m_gamesTeamPlayedBefore = gamesPlayed;
    m_gamesTeamPlayed = games;
}

void Player::updatePlayerRank(PlayerRank *ptr) {
    m_playerRank = ptr;

}

void Player::updateTeamPlayerRank(PlayerRank *ptr) {
    m_groupPlayerRank = ptr;

}
