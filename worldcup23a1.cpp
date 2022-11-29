#include "worldcup23a1.h"
#include "Tree.h"
#include "Player.h"
#include "PlayerRank.h"
#include "Team.h"
#include "PlayerId.h"
#include "CompleteTeam.h"

world_cup_t::world_cup_t() : numOfPlayers(0), teams(Tree<Team>()), playersRank(Tree<PlayerRank>()), playersId(Tree<PlayerId>),
                             completeTeams(Tree<CompleteTeam>())
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
        if (completeTeams.find(teamId) != nullptr){
            CompleteTeam* complete_to_remove = completeTeams.find(teamId);
            completeTeams.remove(*complete_to_remove);
        }
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
        Player new_player = Player(playerId, teamId, gamesPlayed, goals, cards, goalKeeper); // add games team played before
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
    if (goalKeeper){
        currTeam->m_numOfGoalkeepers++;
    }
    if ((currTeam->m_numOfPlayers >= 11) && (currTeam->m_numOfGoalkeepers >= 1) && (completeTeams.find(currTeam) ==
            nullptr)){
        CompleteTeam* new_completeTeam = new CompleteTeam(currTeam->m_teamId, currTeam->m_points, currTeam->m_goals, currTeam->m_cards);
        currTeam->m_completeTeam = new_completeTeam;
        completeTeams.insert(new_completeTeam);
    }

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

    PlayerId *currPlayer = playersId.find(playerId);
    bool is_goalkeeper = false;
    if (currPlayer->m_player->m_goalKeeper){
        is_goalkeeper = true;
    }
    Team* currTeam = currPlayer->m_player->m_team;
    int currGoals = currPlayer->m_player->m_goals;
    int currCards = currPlayer->m_player->m_cards;
    try
    {
        playersRank.remove(currPlayer->m_player->m_playerRank);
        currPlayer->m_player->m_team->m_TeamPlayersRank.remove(currPlayer->m_player->m_groupPlayerRank);
        currPlayer->m_player->m_team->m_players.remove(currPlayer->m_player);
        playerId.remove(currPlayer);
    }
    catch (const std::bad_alloc &)
    {
        return StatusType::ALLOCATION_ERROR;
    }
    currTeam->m_numOfPlayers--;
    currTeam->m_cards -= currCards;
    currTeam->m_goals -= currGoals;
    if (is_goalkeeper){
        currTeam->m_numOfGoalkeepers--;
    }
    if ((currTeam->m_numOfPlayers < 11) || (currTeam->m_numOfGoalkeepers < 1) || (currTeam->m_completeTeam != nullptr)){
        CompleteTeam* currComplete = currTeam->m_completeTeam;
        completeTeams.remove(currComplete);
    }

	return StatusType::SUCCESS;
}

StatusType world_cup_t::update_player_stats(int playerId, int gamesPlayed,
                                        int scoredGoals, int cardsReceived)
{
	// TODO: Your code goes here
    Player* currPlayer = (playersId.find(playerId)->)m_player);
    currPlayer->m_gamesPlayed += gamesPlayed;
    currPlayer->m_goals += scoredGoals;
    currPlayer->m_cards += cardsReceived;
    currPlayer->m_team->m_goals += scoredGoals;
    currPlayer->m_team->m_cards += cardsReceived;

    PlayerRank* currPlayerRank = currPlayer->m_playerRank;
    playersRank.remove(currPlayerRank);
    PlayerRank* new_playerRank = new PlayerRank(playerId, currPlayer->m_goals, currPlayer->m_cards);
    playersRank.insert(new_playerRank);
    currPlayer->m_playerRank = new_playerRank;
    PlayerRank* currTeamPlayerRank = currPlayer->m_groupPlayerRank;
    currPlayer->m_team->m_TeamPlayersRank.remove(currTeamPlayerRank);
    PlayerRank* new_teamPlayerRank = new PlayerRank(playerId, currPlayer->m_goals, currPlayer->m_cards);
    currPlayer->m_team->m_TeamPlayersRank.insert(new_teamPlayerRank);
    currPlayer->m_groupPlayerRank = new_teamPlayerRank;

    //add exceptions

    return StatusType::SUCCESS;
}

StatusType world_cup_t::play_match(int teamId1, int teamId2)
{
	// TODO: Your code goes here

    if ((teamId1 <= 0) || (teamId2 <= 0) || (teamId1 == teamId2)){
        return StatusType::INVALID_INPUT;
    }
    Team* team1 = teams.find(teamId1);
    Team* team2 = teams.find(teamId2);
    if ((team1 == nullptr) || (team2 == nullptr)){
        return StatusType::FAILURE;
    }
    if ((team1->m_completeTeam == nullptr) || (team2->m_completeTeam == nullptr)){
        return StatusType::FAILURE;
    }
    if ((team1->m_points + team1->m_goals - team1->m_cards) == (team2->m_points + team2->m_goals - team2->m_cards)){
        team1->m_points++;
        team2->m_points++;
        if (team1->m_completeTeam != nullptr){
            team1->m_completeTeam->m_points++;
        }
        if (team2->m_completeTeam != nullptr){
            team2->m_completeTeam->m_points++;
        }
    }
    if ((team1->m_points + team1->m_goals - team1->m_cards) > (team2->m_points + team2->m_goals - team2->m_cards)){
        team1->m_points += 3;
        if (team1->m_completeTeam != nullptr){
            team1->m_completeTeam->m_points += 3;
        }
    }
    else{
        team2->m_points += 3;
        if (team2->m_completeTeam != nullptr){
            team2->m_completeTeam->m_points += 3;
        }
    }
    team1->m_gamesPlayed++;
    team2->m_gamesPlayed++;


	return StatusType::SUCCESS;
}

output_t<int> world_cup_t::get_num_played_games(int playerId)
{
	// TODO: Your code goes here
    if (playerId <= 0){
        return StatusType::INVALID_INPUT;
    }
    if (playersId.find(playerId) == nullptr){
        return StatusType::FAILURE;
    }

    PlayerId* currId = playersId.find(playerId);
    Player* currPlayer = currId->m_player;


	return currPlayer->m_gamesPlayed + currPlayer->m_team->m_gamesPlayed - currPlayer->m_gamesTeamPlayedBefore;
}

output_t<int> world_cup_t::get_team_points(int teamId)
{
	// TODO: Your code goes here

    if (teamId <= 0){
        return StatusType::INVALID_INPUT;
    }
    if (teams.find(teamId) == nullptr){
        return StatusType::FAILURE;
    }
    Team* currTeam = teams.find(teamId);
	return currTeam->m_points;
}

StatusType world_cup_t::unite_teams(int teamId1, int teamId2, int newTeamId)
{
	// TODO: Your code goes here
	return StatusType::SUCCESS;
}

output_t<int> world_cup_t::get_top_scorer(int teamId)
{
	// TODO: Your code goes here
    if (teamId == 0){
        return StatusType::INVALID_INPUT;
    }
    if (teamId < 0) {
        if (numOfPlayers == 0) {
            return StatusType::FAILURE;
        }
        else {
            PlayerRank *maxPlayer = playersRank.getMax();
            return maxPlayer->m_playerId;
        }
    }
    if (teamId > 0){
        Team* currTeam = teams.find(teamId);
        if (currTeam == nullptr){
            return StatusType::FAILURE;
        }
        else if (currTeam->m_numOfPlayers == 0){
            return StatusType::FAILURE;
        }
        else{
            PlayerRank* maxPlayer = currTeam->m_TeamPlayersRank.getMax();
            return maxPlayer->m_playerId;
        }

    }

	return 2008;
}

output_t<int> world_cup_t::get_all_players_count(int teamId)
{
	// TODO: Your code goes here
    if (teamId == 0){
        return StatusType::INVALID_INPUT;
    }
    if (teamId < 0){
        return numOfPlayers;
    }

    Team* team = teams.find(teamId);
    if (team == nullptr){
        return StatusType::FAILURE;
    }
    //return success
    return team->m_numOfPlayers;

    //static int i = 0;
    //return (i++==0) ? 11 : 2;

}

StatusType world_cup_t::get_all_players(int teamId, int *const output)
{
	// TODO: Your code goes here
    if ((output == nullptr) || (teamId == 0)){
        return StatusType::INVALID_INPUT;
    }

    if (teamId > 0){
        Team* currTeam = teams.find(teamId);
        if (currTeam == nullptr){
            return StatusType::FAILURE;
        }
        else if (currTeam->m_numOfPlayers == 0){
            return StatusType::FAILURE;
        }
        playersRank.inOrder(output, 0);


    }



  //  output[0] = 4001;
  //  output[1] = 4002;
//	return StatusType::SUCCESS;
}

output_t<int> world_cup_t::get_closest_player(int playerId, int teamId)
{
	// TODO: Your code goes here
    if ((teamId <= 0) || (playerId <= 0)){
        return StatusType::INVALID_INPUT;
    }
    if (numOfPlayers == 1){
        return StatusType::FAILURE;
    }
    Team* currTeam = teams.find(teamId);
    if (currTeam == nullptr){
        return StatusType::FAILURE;
    }
    else {
        Player *currPlayer = currTeam->m_players.find(playerId);
        if (currPlayer == nullptr) {
            return StatusType::FAILURE;
        }
        else{
            if ()
        }
    }



	return 1006;
}

output_t<int> world_cup_t::knockout_winner(int minTeamId, int maxTeamId)
{
	// TODO: Your code goes here
	return 2;
}

