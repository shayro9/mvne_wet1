#ifndef MVNE_WET1_PLAYER_H
#define MVNE_WET1_PLAYER_H

#include "PlayerRank.h"
class Team;

class Player {
public:
    Player(int playerId, int teamId, int gamesPlayed, int goals, int cards, bool goalKeeper);
    ~Player();
    Player() = default;

    int getId() const;
    int getGoals() const;
    int getCards() const;
    bool isGoalKeeper() const;
    int getGamesPlayed() const;
    int getGamesTeamPlayedBefore() const;

    void setGamesTeamPlayedBefore(int games);

    PlayerRank* getPlayerRank();
    PlayerRank* getGroupPlayerRank();
    Team* getTeam();
    void setTeam(Team* t, int gamesPlayed, int *games);

    void updateStats(int games, int goals, int cards);

    friend bool operator<(const Player&, const Player&);
    friend bool operator==(const Player&, const Player&);

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
<<<<<<< HEAD



public:
    Player(int playerId, int teamId, int gamesPlayed, int goals, int cards, bool goalKeeper, int* gamesTeamPlayed, );
    ~Player() = default;
   // bool operator<(const Player& player) const;
  //  bool operator==(const Player& player) const;

=======
>>>>>>> acf01eaccbadcaa739718bec82a278eb66e6964b
};

bool operator!= (const Player&, const Player&);
bool operator>= (const Player&, const Player&);
bool operator> (const Player&, const Player&);
bool operator<= (const Player&, const Player&);

#endif //MVNE_WET1_PLAYER_H
