//
// Created by amida on 25/11/2022.
//
#include "PlayerRank.h"

PlayerRank::PlayerRank(int playerId, int goals, int cards) : m_playerId(playerId), m_goals(goals), m_cards(cards)
{
    //m_playerRankNode = new LinkedListNode<int>(playerId);
}

bool operator<(const PlayerRank &pr1, const PlayerRank &pr2) {
    if (pr1.m_goals < pr2.m_goals){
        return true;
    } else if (pr1.m_goals > pr2.m_goals){
        return false;
    } else{
        if(pr1.m_cards > pr2.m_cards) {
            return true;
        }else if(pr1.m_cards < pr2.m_cards){
            return false;
        }else{
            if(pr1.m_playerId < pr2.m_playerId){
                return true;
            }
            else
                return false;
        }
    }
}

bool operator==(const PlayerRank &pr1, const PlayerRank &pr2){
    if(pr1.m_playerId == pr2.m_playerId)
        return true;
    return false;
}

int PlayerRank::getId() const {
    return m_playerId;
}

PlayerRank::operator int() const {
    return m_playerId;
}

bool operator> (const PlayerRank &pr1, const PlayerRank &pr2){
    return pr2 < pr1;
}

bool operator!= (const PlayerRank &pr1, const PlayerRank &pr2)
{
    return !(pr1==pr2);
}

bool operator<= (const PlayerRank &pr1, const PlayerRank &pr2)
{
    return pr1 < pr2 || pr1 == pr2;
}

bool operator>=(const PlayerRank &pr1, const PlayerRank &pr2)
{
    return pr2 <= pr1;
}

LNode<PlayerRank *> *PlayerRank::getPlayerNode() const {
    return m_playerNode;
}

int PlayerRank::getGoals() const {
    return m_goals;
}

int PlayerRank::getCards() const {
    return m_cards;
}
