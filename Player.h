#ifndef MVNE_WET1_PLAYER_H
#define MVNE_WET1_PLAYER_H

#include "Team.h"
#include "PlayerRank.h"

class Player {
public:
    Player(int playerId, int teamId, int gamesPlayed, int goals, int cards, bool goalKeeper);
    ~Player() = default;

    int getId() const;
    int getGoals() const;
    int getCards() const;
    bool isGoalKeeper() const;

    PlayerRank* getPlayerRank();
    PlayerRank* getGroupPlayerRank();
    Team* getTeam();
   // bool operator<(const Player& player) const;
  //  bool operator==(const Player& player) const;
private:
    int m_playerId;
    int m_teamId;
    int m_gamesPlayed;
    int m_gamesTeamPlayedBefore;
    int m_goals;
    int m_cards;
    bool m_goalKeeper;
    int* m_gamesTeamPlayed;
    PlayerRank* m_playerRank;
    PlayerRank* m_groupPlayerRank;
    Team* m_team;
};

friend bool operator>(const Player& player1, const Player player2);

#endif //MVNE_WET1_PLAYER_H
