
#include "Team.h"

Team::Team(int teamId, int points, int goals, int cards, int numOfPlayers, int gamesPlayed) :
    m_teamId(teamId),
    m_points(points),
    m_goals(goals),
    m_cards(cards),
    m_numOfPlayers(numOfPlayers),
    m_gamesPlayed(gamesPlayed),
    m_players(Tree<Player>()),
    m_TeamPlayersRank(Tree<PlayerRank>())
{}

Team::Team(int teamId) :
    Team(teamId,0)
{}

bool operator== (const Team& t1, const Team& t2){
    if(t1.m_teamId == t2.m_teamId)
        return true;
    return false;
}

bool operator< (const Team& t1, const Team& t2){
    if(t1.m_teamId < t2.m_teamId)
        return true;
    return false;
}

bool operator> (const Team& t1, const Team& t2){
    return t2 < t1;
}

bool operator!= (const Team& t1, const Team& t2)
{
    return !(t1==t2);
}

bool operator<=(const Team& t1, const Team& t2)
{
    return t1 < t2 || t1 == t2;
}

bool operator>=(const Team& t1, const Team& t2)
{
    return t2 <= t1;
}

void Team::addPlayer(Player *player) {
    m_players.insert(*player);
    m_TeamPlayersRank.insert(*player->getPlayerRank());
    m_numOfPlayers++;
    m_goals += player->getGoals();
    m_cards += player->getCards();
    if(player->isGoalKeeper())
        m_numOfGoalkeepers++;
}

bool Team::isComplete() const {
    return m_numOfPlayers >= 11 && m_numOfGoalkeepers >= 1;
}

int Team::getId() const {
    return m_teamId;
}

int Team::getPoints() const {
    return m_points;
}

int Team::getGoals() const {
    return m_goals;
}

int Team::getCards() const {
    return m_cards;
}