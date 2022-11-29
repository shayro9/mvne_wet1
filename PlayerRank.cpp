//
// Created by amida on 25/11/2022.
//
#include "PlayerRank.h"

PlayerRank::PlayerRank(int playerId, int goals, int cards) : m_playerId(playerId), m_goals(goals), m_cards(cards){}

bool PlayerRank::operator<(const PlayerRank &playerRank) const {
    if (m_goals < playerRank.m_goals){
        return true;
    }
    if (m_goals > playerRank.m_goals){
        return false;
    }
    else{
        if(m_cards > playerRank.m_cards) {
            return true;
        }
        if(m_cards < playerRank.m_cards){
            return false;
        }
        else{
            if(m_playerId < playerRank.m_playerId){
                return true;
            }
            if((m_playerId > playerRank.m_playerId) || (m_playerId == playerRank.m_playerId)){
                return false;
            }
        }
    }
PlayerRank::getId(){
        return m_playerId;
    }

}