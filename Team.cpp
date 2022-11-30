#include "Team.h"

Team::Team(int teamId, int points, int goals, int cards, int numOfPlayers, int gamesPlayed) :
    m_teamId(teamId),
    m_points(points),
    m_goals(goals),
    m_cards(cards),
    m_numOfPlayers(numOfPlayers),
    m_gamesPlayed(gamesPlayed),
    m_numOfGoalkeepers(0),
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

void Team::removePlayer(Player *player) {
    m_players.remove(*player);
    m_TeamPlayersRank.remove(*player->getPlayerRank());
    m_numOfPlayers--;
    m_cards -= player->getCards();
    m_goals -= player->getGoals();
    m_numOfGoalkeepers -= player->isGoalKeeper();
}

void Team::updateStats(int goals, int cards) {
    m_goals += goals;
    m_cards += cards;
}

void Team::addPoints(int amount) {
    m_points += amount;
    m_gamesPlayed++;
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

void Team::mergeWith(Team &t, int new_Id) {
    //need to delete leftovers team
    m_teamId = new_Id;
    m_points += t.getPoints();
    m_goals += t.getGoals();
    m_cards += t.getCards();
    int team_size = m_numOfPlayers;
    m_numOfPlayers += t.getPlayersNum();
    m_numOfGoalkeepers += t.getGoalKeepersNum();

    //update for every player GamesPlayed and gamesTeamPlayedBefore = this.gamePlayed
    t.getPlayers().inOrder(UpdateGames,m_gamesPlayed);

    m_players.merge(t.getPlayers(),team_size,t.getPlayersNum());
    m_TeamPlayersRank.merge(t.getPlayersRank(),team_size,t.getPlayersNum());
}

Tree<Player> &Team::getPlayers() {
    return m_players;
}

Tree<PlayerRank> &Team::getPlayersRank() {
    return m_TeamPlayersRank;
}

void UpdateGames(node<Player>* p, int gamePlayedBefore)
{

    int games_with_team = p->data.getTeam()->getGamesPlayed() - p->data.getGamesTeamPlayedBefore();

    p->data.updateStats(games_with_team,0,0);
    p->data.setGamesTeamPlayedBefore(gamePlayedBefore);
}
