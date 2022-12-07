#include "Team.h"

Team::Team(int teamId, int points, int goals, int cards, int numOfPlayers, int gamesPlayed) :
    m_teamId(teamId),
    m_points(points),
    m_goals(goals),
    m_cards(cards),
    m_numOfPlayers(numOfPlayers),
    m_gamesPlayed(gamesPlayed),
    m_numOfGoalkeepers(0),
    m_completeTeam(nullptr),
    m_players(Tree<Player>()),
    m_TeamPlayersRank(Tree<PlayerRank>())
{}

Team::Team(int teamId, int points, int goals, int cards, int numOfPlayers, int gamesPlayed, int goalKeepers,
           Tree<Player> *players, Tree<PlayerRank> *ranks) :
        m_teamId(teamId),
        m_points(points),
        m_goals(goals),
        m_cards(cards),
        m_numOfPlayers(numOfPlayers),
        m_gamesPlayed(gamesPlayed),
        m_numOfGoalkeepers(goalKeepers),
        m_players(*players),
        m_TeamPlayersRank(*ranks)
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

Player* Team::addPlayer(Player *player,PlayerRank *playerRank) {
    m_players.insert(*player);
    m_TeamPlayersRank.insert(*playerRank);
    m_numOfPlayers++;
    m_goals += player->getGoals();
    m_cards += player->getCards();
    if(player->isGoalKeeper())
        m_numOfGoalkeepers++;

    return &m_players.find(*player)->data;
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

void Team::removePlayer(Player *player) {
    m_numOfPlayers--;
    m_cards -= player->getCards();
    m_goals -= player->getGoals();
   // m_numOfGoalkeepers -= player->isGoalKeeper();

    m_TeamPlayersRank.remove(*player->getPlayerRank());
    m_players.remove(*player);
}

void Team::updateStats(int goals, int cards, int players) {
    m_goals += goals;
    m_cards += cards;
    m_numOfPlayers += players;
}
void Team::updateGoalkeepersNum(int n){
    m_numOfGoalkeepers += n;
}


void Team::addPoints(int amount) {
    m_points += amount;
   // m_gamesPlayed++;
    if(isComplete())
    {
        m_completeTeam->addPoints(amount);
    }
}

int Team::getPlayersNum() const {
    return m_numOfPlayers;
}

int Team::getGamesPlayed() const {
    return m_gamesPlayed;
}

int Team::getGoalKeepersNum() const {
    return m_numOfGoalkeepers;
}

Tree<Player> *Team::getPlayers() {
    return &m_players;
}

Tree<PlayerRank> &Team::getPlayersRank() {
    return m_TeamPlayersRank;
}

int *Team::getGamesPlayedPoint() {
    return &m_gamesPlayed;
}

CompleteTeam *Team::getCompleteTeamPointer() const {
    return m_completeTeam;
}

void Team::setCompleteTeamPointer(CompleteTeam* ptr)  {
    m_completeTeam = ptr;
}

void Team::addGames(int amount) {
    m_gamesPlayed += amount;
}

void Team::setId(int newId) {
    m_teamId = newId;
}

void Team::nullTreePointers() {
    m_players.nullTree();
    m_TeamPlayersRank.nullTree();
}
void UpdateGames(node<Player>* p, int gamePlayedBefore)
{

    int games_with_team = p->data.getTeam()->getGamesPlayed() - p->data.getGamesTeamPlayedBefore();

    p->data.updateStats(games_with_team,0,0);
    p->data.setGamesTeamPlayedBefore(gamePlayedBefore);
}
