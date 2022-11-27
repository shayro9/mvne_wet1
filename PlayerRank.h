//
// Created by amida on 25/11/2022.
//

#ifndef MVNE_WET1_PLAYERRANK_H
#define MVNE_WET1_PLAYERRANK_H

#endif //MVNE_WET1_PLAYERRANK_H

class PlayerRank{
    int m_playerId;
    int m_goals;
    int m_cards;
public:
    PlayerRank(int playerid, int goals, int cards);
    ~PlayerRank() = default;
    bool operator<(const PlayerRank& playerRank) const;
    bool operator==(const PlayerRank& playerRank) const;
};

friend bool operator>(const Player& player1, const Player player2);