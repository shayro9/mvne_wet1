#ifndef MVNE_WET1_PLAYER_H
#define MVNE_WET1_PLAYER_H

#include "PlayerRank.h"
//#include "Team.h"

class Team;
class PlayerId;

class Player {
public:
    Player(int playerId, int teamId, int gamesPlayed, int goals, int cards, bool goalKeeper);
    Player(int id);
    ~Player();
    Player() = default;
    Player& operator=(const Player& p);

    int getId() const;
    int getGoals() const;
    int getCards() const;
    bool isGoalKeeper() const;
    int getGamesPlayed() const;
    int getGamesTeamPlayedBefore() const;

    void setGamesTeamPlayedBefore(int games);

    PlayerRank* getPlayerRank();
    PlayerId* getPlayerId();

    void setPlayerRank(PlayerRank* playerRank);
    void setTeamPlayerRank(PlayerRank* ptr);
    void setPlayerId(PlayerId *id);

    void clearRankPointers();

    PlayerRank* getGroupPlayerRank();
    Team* getTeam();
    void setTeam(Team* t, int gamesPlayed, int *games);
    void setTeamPointer(Team* t);

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
    PlayerId* m_Id;
    Team* m_team;
};

bool operator!= (const Player&, const Player&);
bool operator>= (const Player&, const Player&);
bool operator> (const Player&, const Player&);
bool operator<= (const Player&, const Player&);

#endif //MVNE_WET1_PLAYER_H
