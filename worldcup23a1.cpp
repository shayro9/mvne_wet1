#include "worldcup23a1.h"
#include "Tree.h"
#include "Player.h"
#include "PlayerRank.h"
#include "Team.h"
#include "PlayerId.h"

world_cup_t::world_cup_t() : numOfPlayers(0), teams(Tree<Team>()), players(Tree<Player>()), playersRank(Tree<PlayerRank>()), playersId(Tree<PlayerId>)
{

	// TODO: Your code goes here
}

world_cup_t::~world_cup_t()
{
	// TODO: Your code goes here
}


StatusType world_cup_t::add_team(int teamId, int points)
{
    if ((teamId <= 0) || points < 0 ){
        return StatusType::INVALID_INPUT;
    }
    if (teams.find(teamId) != nullptr){
        return StatusType::FALIURE;
    }
    try
    {
        Team* new_team = new Team(teamId, points);
        teams.insert(new_team);
    }
    catch (const std::bad_alloc &)
    {  //is it allowed?
        return StatusType::ALLOCATION_ERROR;
    }

	// TODO: Your code goes here
	return StatusType::SUCCESS;
}

StatusType world_cup_t::remove_team(int teamId)
{
	// TODO: Your code goes here
    if (teamId <= 0){
        return StatusType::INVALID_INPUT;
    }

    Team* to_remove = teams.find(teamId);
    if ((to_remove == nullptr) || (to_remove->m_numOfPlayers != 0)){
        return StatusType::FAILURE;
    }
    try
    {
        //delete players trees in team
        teams.remove(*to_remove);
    }
    catch (const std::bad_alloc &)
    {
        return StatusType::ALLOCATION_ERROR;
    }

    return StatusType::SUCCESS;

}

StatusType world_cup_t::add_player(int playerId, int teamId, int gamesPlayed,
                                   int goals, int cards, bool goalKeeper)
{
	// TODO: Your code goes here
    if ((playerId <= 0) || (teamId <= 0) || (gamesPlayed < 0) || (goals < 0) || (cards < 0) ){
        return StatusType::INVALID_INPUT;
    }
    if ( gamesPlayed == 0 && ( goals > 0 || cards > 0)){
        return StatusType::INVALID_INPUT;
    }

    if (players.find(playerId) != nullptr || teams.find(teamId) == nullptr){
        return StatusType::FAILURE;
    }

    try
    {
        Player new_player = Player(playerId, teamId, gamesPlayed, goals, cards, goalKeeper);
        new_player.m_playerRank = new PlayerRank(playerId, goals, cards);
        playersRank.insert(new_player.m_playerRank);
        new_player.m_groupPlayerRank = new PlayerRank(playerId, goals, cards);
        new_player.m_team->m_TeamPlayersRank.insert(*new_player.m_groupPlayerRank);
        players.insert(new_player);
        playersId.insert(new PlayerId(playerId, &new_player));
    }
    catch (const std::bad_alloc &)
    {
        return StatusType::ALLOCATION_ERROR;
    }
    Team* currTeam = teams.find(teamId);
    currTeam->m_numOfPlayers++;
    currTeam->m_goals += goals;
    currTeam->m_cards += cards;
    numOfPlayers++;


	return StatusType::SUCCESS;
}

StatusType world_cup_t::remove_player(int playerId)
{
	// TODO: Your code goes here

    if (playerId <= 0){
        return StatusType::INVALID_INPUT;
    }

    if (playersId.find(playerId) == nullptr){
        return StatusType::FAILURE;
    }

    try
    {
        PlayerId *currPlayer = playersId.find(playerId);
        playersRank.remove(currPlayer->m_player->m_groupPlayerRank);
        currPlayer->m_player->m_team->m_TeamPlayersRank.remove(currPlayer->m_player->m_groupPlayerRank);
        currPlayer->m_player->m_team->m_players.remove(currPlayer->m_player);
        playerId.remove(currPlayer);
    }
    catch (const std::bad_alloc &)
    {
        return StatusType::ALLOCATION_ERROR;
    }

	return StatusType::SUCCESS;
}

StatusType world_cup_t::update_player_stats(int playerId, int gamesPlayed,
                                        int scoredGoals, int cardsReceived)
{
	// TODO: Your code goes here
	return StatusType::SUCCESS;
}

StatusType world_cup_t::play_match(int teamId1, int teamId2)
{
	// TODO: Your code goes here
	return StatusType::SUCCESS;
}

output_t<int> world_cup_t::get_num_played_games(int playerId)
{
	// TODO: Your code goes here
	return 22;
}

output_t<int> world_cup_t::get_team_points(int teamId)
{
	// TODO: Your code goes here
	return 30003;
}

StatusType world_cup_t::unite_teams(int teamId1, int teamId2, int newTeamId)
{
	// TODO: Your code goes here
	return StatusType::SUCCESS;
}

output_t<int> world_cup_t::get_top_scorer(int teamId)
{
	// TODO: Your code goes here
	return 2008;
}

output_t<int> world_cup_t::get_all_players_count(int teamId)
{
	// TODO: Your code goes here
    static int i = 0;
    return (i++==0) ? 11 : 2;
}

StatusType world_cup_t::get_all_players(int teamId, int *const output)
{
	// TODO: Your code goes here
    output[0] = 4001;
    output[1] = 4002;
	return StatusType::SUCCESS;
}

output_t<int> world_cup_t::get_closest_player(int playerId, int teamId)
{
	// TODO: Your code goes here
	return 1006;
}

output_t<int> world_cup_t::knockout_winner(int minTeamId, int maxTeamId)
{
	// TODO: Your code goes here
	return 2;
}

