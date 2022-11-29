#ifndef MVNE_WET1_TEAM_H
#define MVNE_WET1_TEAM_H

#include "Tree.h"
#include "PlayerRank.h"
#include "Player.h"
#include "CompleteTeam.h"

class Team {
public:
    Team(int teamId, int points, int goals = 0, int cards = 0, int numOfPlayers = 0, int gamesPlayed = 0);
    Team(int teamId);
    Team(const Team& t)=default;

    void addPlayer(Player* player);

    int getId() const;
    int getPoints() const;
    int getGoals() const;
    int getCards() const;

    bool isComplete() const;

    friend bool operator== (const Team&, const Team&);
    friend bool operator< (const Team&, const Team&);

protected:
    int m_teamId;
    int m_points;
    int m_goals;
    int m_cards;
private:
    int m_numOfPlayers;
    int m_gamesPlayed;
    int m_numOfGoalkeepers;

    CompleteTeam* m_completeTeam;

    Tree<Player> m_players;
    Tree<PlayerRank> m_TeamPlayersRank;

};

bool operator!= (const Team&, const Team&);
bool operator>= (const Team&, const Team&);
bool operator> (const Team&, const Team&);
bool operator<= (const Team&, const Team&);

#endif //MVNE_WET1_TEAM_H
