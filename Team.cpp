
#include "Team.h"

Team::Team(int teamId, int points, int goals, int cards, int numOfPlayers, int gamesPlayed) : m_teamId(teamId), m_points(points), m_goals(goals),
                                        m_cards(cards), m_numOfPlayers(numOfPlayers), m_gamesPlayed(gamesPlayed), m_players(Tree<Player>()),m_TeamPlayersRank(Tree<PlayerRank>()){

}