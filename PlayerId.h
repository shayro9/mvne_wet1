#ifndef MVNE_WET1_PLAYERID_H
#define MVNE_WET1_PLAYERID_H

#include "Player.h"
 class PlayerId{
 public:
    PlayerId(Player &player);
    PlayerId(int id);
    PlayerId() = default;
    ~PlayerId();

    Player* getPlayer();
    void setPlayer(Player* player);

    friend bool operator== (const PlayerId&, const PlayerId&);
    friend bool operator< (const PlayerId&, const PlayerId&);

private:
    int m_playerId;
    Player* m_player;
};

bool operator!= (const PlayerId&, const PlayerId&);
bool operator>= (const PlayerId&, const PlayerId&);
bool operator> (const PlayerId&, const PlayerId&);
bool operator<= (const PlayerId&, const PlayerId&);

#endif //MVNE_WET1_PLAYERID_H