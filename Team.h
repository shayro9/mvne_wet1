#ifndef MVNE_WET1_TEAM_H
#define MVNE_WET1_TEAM_H

#include "Tree.h"
#include "PlayerRank.h"
#include "Player.h"

class Team {
public:
    explicit Team(int teamId, int points, int goals = 0, int cards = 0, int numOfPlayers = 0, int gamesPlayed = 0);
    Team(int teamId);
    Team() = default;

    void addPlayer(Player* player);
    void removePlayer(Player* player);

    int getId() const;
    int getPoints() const;
    int getGoals() const;
    int getCards() const;
    int getPlayersNum() const;
    int getGamesPlayed() const;
    int getGoalKeepersNum() const;

    Tree<Player>& getPlayers();
    Tree<PlayerRank>& getPlayersRank();

    void updateStats(int goals, int cards);
    void addPoints(int amount);
    void mergeWith(Team &t,int new_Id);

    bool isComplete() const;

    friend bool operator== (const Team&, const Team&);
    friend bool operator< (const Team&, const Team&);

private:
    int m_teamId;
    int m_points;
    int m_goals;
    int m_cards;
    int m_numOfPlayers;
    int m_gamesPlayed;
    int m_numOfGoalkeepers;

    //CompleteTeam* m_completeTeam;

    Tree<Player> m_players;
    Tree<PlayerRank> m_TeamPlayersRank;

};

void UpdateGames(node<Player>* p, int gamePlayedBefore);

bool operator!= (const Team&, const Team&);
bool operator>= (const Team&, const Team&);
bool operator> (const Team&, const Team&);
bool operator<= (const Team&, const Team&);

#endif //MVNE_WET1_TEAM_H
