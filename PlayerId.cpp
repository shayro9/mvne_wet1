#include "PlayerId.h"

PlayerId::PlayerId(Player &player) :
    m_playerId(player.getId())
{
    m_player = &player;
}

PlayerId::PlayerId(int id) :
    m_playerId(id),
    m_player(nullptr)
{}

bool operator== (const PlayerId& id1, const PlayerId& id2){
    if(id1.m_playerId == id2.m_playerId)
        return true;
    return false;
}

bool operator< (const PlayerId& id1, const PlayerId& id2){
    if(id1.m_playerId < id2.m_playerId)
        return true;
    return false;
}

Player *PlayerId::getPlayer() {
    return m_player;
}

PlayerId::~PlayerId() {

}

void PlayerId::setPlayer(Player *player) {
    m_player = player;
}

bool operator> (const PlayerId& id1, const PlayerId& id2){
    return id2 < id1;
}

bool operator!= (const PlayerId& id1, const PlayerId& id2)
{
    return !(id1==id2);
}

bool operator<= (const PlayerId& id1, const PlayerId& id2)
{
    return id1 < id2 || id1 == id2;
}

bool operator>= (const PlayerId& id1, const PlayerId& id2)
{
    return id2 <= id1;
}
