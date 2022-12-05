#include "Player.h"

Player::Player(int playerId, int teamId, int gamesPlayed, int goals, int cards, bool goalKeeper) :
    m_playerId(playerId),
    m_teamId(teamId),
    m_gamesPlayed(gamesPlayed),
    m_goals(goals),
    m_cards(cards),
    m_goalKeeper(goalKeeper),
   // m_gamesTeamPlayedBefore(gamesTeamPlayedBefore),
    m_gamesTeamPlayed(nullptr),
    m_playerRank(nullptr),
    m_groupPlayerRank(nullptr),
    m_Id(nullptr),
    m_team(nullptr)
{
    /*
    m_playerRank = new PlayerRank(playerId, goals, cards);
    m_groupPlayerRank = new PlayerRank(playerId, goals, cards);
    */
}

Player::~Player() {
    clearRankPointers();
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

PlayerRank* Player::getPlayerRank() {
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

void Player::setTeamPlayerRank(PlayerRank *ptr) {
    m_groupPlayerRank = ptr;
    m_groupPlayerRank->connectPointer();
}

void Player::setPlayerRank(PlayerRank *playerRank) {
    m_playerRank = playerRank;
    m_playerRank->connectPointer();
}

void Player::clearRankPointers() {
    if(m_playerRank) {
        if (m_playerRank->getConnectedPointers() == 1)
            delete (m_playerRank);
        else
            m_playerRank->reducePointers();
    }
    if(m_groupPlayerRank) {
        if (m_groupPlayerRank->getConnectedPointers() == 1)
            delete (m_groupPlayerRank);
        else
            m_groupPlayerRank->reducePointers();
    }
}

Player &Player::operator=(const Player &p) {
    if(this == &p)
        return *this;

    m_playerId = p.m_playerId;
    m_teamId = p.m_teamId;
    m_gamesPlayed = p.m_gamesPlayed;
    m_gamesTeamPlayedBefore = p.m_gamesTeamPlayedBefore;
    m_goals = p.m_goals;
    m_cards = p.m_cards;
    m_goalKeeper = p.m_goalKeeper;

    m_gamesTeamPlayed = p.m_gamesTeamPlayed;
    m_team = p.m_team;
    m_Id = p.m_Id;

    if(p.m_groupPlayerRank)
        this->setTeamPlayerRank(p.m_groupPlayerRank);
    if(p.m_playerRank)
        this->setPlayerRank(p.m_playerRank);

    return *this;
}

PlayerId *Player::getPlayerId() {
    return m_Id;
}

void Player::setPlayerId(PlayerId *id) {
    m_Id = id;
}

