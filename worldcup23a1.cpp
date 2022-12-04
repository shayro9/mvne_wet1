#include "worldcup23a1.h"
#include "Tree.h"
#include "Player.h"
#include "PlayerRank.h"
#include "Team.h"
#include "PlayerId.h"
#include "CompleteTeam.h"

#define DRAW 1
#define WIN 3
#define LOSS 0

world_cup_t::world_cup_t() : numOfPlayers(0), teams(Tree<Team>()), playersRank(Tree<PlayerRank>()), playersId(Tree<PlayerId>()),
                             completeTeams(Tree<CompleteTeam>()), playerRankList(List<PlayerRank*>()), completeTeamList(List<CompleteTeam*>())
{
	// TODO: Your code goes here
}

world_cup_t::~world_cup_t()
{
	// TODO: Your code goes here
}


StatusType world_cup_t::add_team(int teamId, int points)
{
    // TODO: Your code goes here
    if ((teamId <= 0) || points < 0 ){
        return StatusType::INVALID_INPUT;
    }
    if (teams.find(teamId) != nullptr){
        return StatusType::FAILURE;
    }
    try
    {
        Team new_team = Team(teamId, points);
        teams.insert(new_team);
    }
    catch (const std::bad_alloc &)
    {  //is it allowed?
        return StatusType::ALLOCATION_ERROR;
    }

	return StatusType::SUCCESS;
}

StatusType world_cup_t::remove_team(int teamId)
{
	// TODO: Your code goes here
    if (teamId <= 0){
        return StatusType::INVALID_INPUT;
    }

    Team* to_remove = &teams.find(teamId)->data;
    if ((to_remove == nullptr) || (to_remove->getPlayersNum() != 0)){
        return StatusType::FAILURE;
    }
    try
    {
        //delete players trees in team
        //unecessary because there are no players!!
        CompleteTeam *com_to_remove = &completeTeams.find(teamId)->data;
        if (com_to_remove != nullptr){
            completeTeamList.remove(com_to_remove->getCompleteNode());
            completeTeams.remove(*com_to_remove);
        }

        teams.remove(*to_remove);
        delete(to_remove);
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

    if (playersId.find(playerId) != nullptr || teams.find(teamId) == nullptr){
        return StatusType::FAILURE;
    }

    try
    {

        /*
        Player new_player = Player(playerId, teamId, gamesPlayed, goals, cards, goalKeeper); // add games team played before
        new_player.m_playerRank = new PlayerRank(playerId, goals, cards);
        playersRank.insert(new_player.m_playerRank);
        node<PlayerRank*> curr = playersRank.find(new_player.m_playerRank);
        node<PlayerRank*> prevPlayerRank = curr.findPrev();
        //node<PlayerRank>* nextPlayerRank = curr.findNext();
        playersRankList.insertAfter(prevPlayerRank);
        new_player.m_groupPlayerRank = new PlayerRank(playerId, goals, cards);
        new_player.m_team->m_TeamPlayersRank.insert(*new_player.m_groupPlayerRank);
        players.insert(new_player);
        playersId.insert(new PlayerId(playerId, &new_player));
        */


        Player* new_player = new Player(playerId, teamId, gamesPlayed, goals, cards, goalKeeper); // add games team played before
        Team* new_player_team = &teams.find(teamId)->data;
        new_player->setTeam(new_player_team,new_player_team->getGamesPlayed(),new_player_team->getGamesPlayedPoint());

        playersRank.insert(*new_player->getPlayerRank());
        new_player->getTeam()->addPlayer(new_player);
        playersId.insert(*new_player);

        node<PlayerRank>* prevInList = playersRank.findMaxSmaller(*new_player->getPlayerRank());
        if (prevInList != nullptr){
            playerRankList.insertAfter(prevInList->data.getPlayerNode(), new_player->getPlayerRank());
        }
        else{
            playerRankList.insertFront(new_player->getPlayerRank());
            new_player->setPlayerRank(playerRankList.getHead()->m_data);
        }

    }
    catch (const std::bad_alloc &)
    {
        return StatusType::ALLOCATION_ERROR;
    }

    numOfPlayers++;
    // should be in try catch
    Team curr_team = teams.find(teamId)->data;
    if (curr_team.isComplete() && (completeTeams.find(teamId) == nullptr)){
        CompleteTeam* new_completeTeam = new CompleteTeam(curr_team.getId(),curr_team.getPoints(),curr_team.getGoals(),curr_team.getCards());
        LNode<CompleteTeam*>* prevConInList = completeTeams.findMaxSmaller(*new_completeTeam)->data.getCompleteNode();
        if (prevConInList != nullptr) {
            completeTeamList.insertAfter(prevConInList, new_completeTeam);
        } else{
            completeTeamList.insertFront(new_completeTeam);
        }
        //curr_team.setCompleteTeam(new_completeTeam); //connect Team Pointer to Complete Team
        completeTeams.insert(*new_completeTeam);
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

    PlayerId *currPlayer = &playersId.find(playerId)->data;
    bool is_goalkeeper = currPlayer->getPlayer()->isGoalKeeper();
    Team* currTeam = currPlayer->getPlayer()->getTeam();
    int currGoals = currPlayer->getPlayer()->getGoals();
    int currCards = currPlayer->getPlayer()->getCards();

    try
    {
        playerRankList.remove(currPlayer->getPlayer()->getPlayerRank()->getPlayerNode());
        playersRank.remove(*currPlayer->getPlayer()->getPlayerRank());
        currPlayer->getPlayer()->getTeam()->removePlayer(currPlayer->getPlayer());
        playersId.remove(*currPlayer);
        currTeam->updateStats(-currGoals, -currCards, -1);
        if (is_goalkeeper){
            currTeam->updateGoalkeepersNum(-1);
        }

    }
    catch (const std::bad_alloc &)
    {
        return StatusType::ALLOCATION_ERROR;
    }


    if ((currTeam->getPlayersNum() < 11) || (currTeam->getGoalKeepersNum() < 1) || (currTeam->getCompleteTeamPointer() != nullptr)){
        CompleteTeam* currComplete = currTeam->getCompleteTeamPointer();
        completeTeamList.remove(currComplete->getCompleteNode());
        completeTeams.remove(*currTeam->getCompleteTeamPointer());
        currTeam->setCompleteTeamPointer(nullptr);
    }



	return StatusType::SUCCESS;
}

StatusType world_cup_t::update_player_stats(int playerId, int gamesPlayed,
                                        int scoredGoals, int cardsReceived)
{
	// TODO: Your code goes here
    if(playerId <=0 || gamesPlayed < 0 || scoredGoals < 0 || cardsReceived < 0)
        return StatusType::INVALID_INPUT;

    Player* currPlayer = (playersId.find(playerId)->data.getPlayer());

    currPlayer->updateStats(gamesPlayed,scoredGoals,cardsReceived);
    currPlayer->getTeam()->updateStats(scoredGoals,cardsReceived, 0);


    /*
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
    */
    //add exceptions


    //Player* currPlayer = playersId.find(playerId)->data.getPlayer();
    PlayerRank* currPlayerRank = currPlayer->getPlayerRank();
    playerRankList.remove(currPlayerRank->getPlayerNode());
    playersRank.remove(*currPlayerRank);

    PlayerRank* newPlayerRank = new PlayerRank(playerId, currPlayer->getGoals(), currPlayer->getCards());
    playersRank.insert(*newPlayerRank);
    LNode<PlayerRank*>* prevInList = playersRank.findMaxSmaller(*newPlayerRank)->data.getPlayerNode();
    if (prevInList != nullptr){
        playerRankList.insertAfter(prevInList, newPlayerRank);
    }
    else{
        playerRankList.insertFront(newPlayerRank); //if its the smallest one, creates one node list- should add insert before
    }

    Team* currTeam = currPlayer->getTeam();
    PlayerRank* currTeamPlayerRank = currPlayer->getGroupPlayerRank();
    currTeam->getPlayersRank().remove(*currTeamPlayerRank);
    PlayerRank* newTeamPlayerRank = new PlayerRank(playerId, currPlayer->getGoals(), currPlayer->getCards());
    currTeam->getPlayersRank().insert(*newTeamPlayerRank);

    currPlayer->updateStats(currPlayer->getGamesPlayed(), currPlayer->getGoals(), currPlayer->getCards() );
    currPlayer->updatePlayerRank(newPlayerRank);
    currPlayer->updateTeamPlayerRank(newTeamPlayerRank);
    currPlayer->getTeam()->updateStats(scoredGoals,cardsReceived, 0);

    return StatusType::SUCCESS;
}

StatusType world_cup_t::play_match(int teamId1, int teamId2)
{
	// TODO: Your code goes here

    if ((teamId1 <= 0) || (teamId2 <= 0) || (teamId1 == teamId2)){
        return StatusType::INVALID_INPUT;
    }

    Team* team1 = &teams.find(teamId1)->data;
    Team* team2 = &teams.find(teamId2)->data;

    if ((team1 == nullptr) || (team2 == nullptr)){
        return StatusType::FAILURE;
    }

    if (!team1->isComplete() || !team2->isComplete()){
        return StatusType::FAILURE;
    }

    int score1 = team1->getPoints() + team1->getGoals() - team1->getCards();
    int score2 = team2->getPoints() + team2->getGoals() - team2->getCards();
    if (score1 == score2){
        team1->addPoints(DRAW);
        team2->addPoints(DRAW);
    }
    else if (score1 > score2){
        team1->addPoints(WIN);
        team2->addPoints(LOSS);
    }
    else{
        team1->addPoints(LOSS);
        team2->addPoints(WIN);
    }
    team1->addGames(1);
    team2->addGames(1);
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

    PlayerId* currId = &playersId.find(playerId)->data;
    Player* currPlayer = currId->getPlayer();

    int games_with_team = currPlayer->getTeam()->getGamesPlayed() - currPlayer->getGamesTeamPlayedBefore();
    int games_alone = currPlayer->getGamesPlayed();

	return games_with_team + games_alone;
}

output_t<int> world_cup_t::get_team_points(int teamId)
{
	// TODO: Your code goes here

    if (teamId <= 0){
        return StatusType::INVALID_INPUT;
    }

    Team* currTeam = &teams.find(teamId)->data;
    if (currTeam == nullptr){
        return StatusType::FAILURE;
    }

	return currTeam->getPoints();
}

StatusType world_cup_t::unite_teams(int teamId1, int teamId2, int newTeamId)
{
	// TODO: Your code goes here
    if(teamId1 <= 0 || teamId2 <= 0 || newTeamId <= 0){
        return StatusType::INVALID_INPUT;
    }

    Team* team1 = &teams.find(teamId1)->data;
    Team* team2 = &teams.find(teamId2)->data;
    Team* new_team = &teams.find(newTeamId)->data;

    if(!team1 || !team2 || new_team)
        return StatusType::FAILURE;

    try {
        team1->mergeWith(*team2, newTeamId);
    }
    catch (...) {
        return StatusType::ALLOCATION_ERROR;
    }
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
            return playerRankList.getTail()->m_data->getId();
            //PlayerRank *maxPlayer = &playersRank.getMax()->data;
           // return maxPlayer->getId();
        }
    }
    if (teamId > 0){
        Team* currTeam = &teams.find(teamId)->data;
        if (currTeam == nullptr || currTeam->getPlayersNum() == 0){
            return StatusType::FAILURE;
        }
        else{
            PlayerRank* maxPlayer = &currTeam->getPlayersRank().getMax()->data;
            return maxPlayer->getId();
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

    Team* team = &teams.find(teamId)->data;
    if (team == nullptr){
        return StatusType::FAILURE;
    }

    return team->getPlayersNum();
}

StatusType world_cup_t::get_all_players(int teamId, int *const output)
{

	// TODO: Your code goes here
    if ((output == nullptr) || (teamId == 0)){
        return StatusType::INVALID_INPUT;
    }

    if (teamId > 0){
        Team* currTeam = &teams.find(teamId)->data;
        if (currTeam == nullptr || currTeam->getPlayersNum() == 0){
            return StatusType::FAILURE;
        }
        currTeam->getPlayersRank().tree2IDArrayInOrder(output);
    }
    else{
        playersRank.tree2IDArrayInOrder(output);
    }

	return StatusType::SUCCESS;
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
    Team* currTeam = &teams.find(teamId)->data;
    if (currTeam == nullptr){
        return StatusType::FAILURE;
    }
    //Tree<Player> currTree = currTeam->getPlayers();
  //  Player* curr = currTree.find(playerId);
  //  Player* currPlayer = &currTeam->getPlayers().find(playerId)->data
    PlayerId* currPlayerId = &playersId.find(playerId)->data; //complexity!!
    Player* currPlayer = currPlayerId->getPlayer();
    if (currPlayer->getTeam()->getId() != teamId){
        return StatusType::FAILURE;
    }
    PlayerRank* currRank = currPlayer->getPlayerRank();
    PlayerRank* prevInList = currPlayer->getPlayerRank()->getPlayerNode()->m_prev->m_data;
    PlayerRank* nextInList = currPlayer->getPlayerRank()->getPlayerNode()->m_next->m_data;
    if (abs(prevInList->getGoals() - currRank->getGoals()) < abs(nextInList->getGoals() - currRank->getGoals())){
        return prevInList->getId();
    }
    else if (abs(prevInList->getGoals() - currRank->getGoals()) > abs(nextInList->getGoals() - currRank->getGoals())){
        return nextInList->getId();
    }
    else{
        if (abs(prevInList->getCards() - currRank->getCards()) < (abs(nextInList->getCards() - currRank->getCards()))){
            return prevInList->getId();
        }
        else if (abs(prevInList->getCards() - currRank->getCards()) > (abs(nextInList->getCards() - currRank->getCards()))){
            return nextInList->getId();
        }
        else{
            if (abs(prevInList->getId() - currRank->getId()) < abs(nextInList->getId() - currRank->getId())){
                return prevInList->getId();
            }
            else if (abs(prevInList->getId() - currRank->getId()) > abs(nextInList->getId() - currRank->getId())){
                return nextInList->getId();
            }
            else{
                if (prevInList->getId() > nextInList->getId()){
                    return prevInList->getId();
                }
                else{
                    return nextInList->getId();
                }
            }
        }
    }




    return 1006;
}

output_t<int> world_cup_t::knockout_winner(int minTeamId, int maxTeamId)
{
	// TODO: Your code goes here

   // Team *competing_teams {};
  //  teams.tree2ArrayInOrder(competing_teams,isComplete);

   // Team* minTeam = &teams.find(minTeamId)->data;
   // Team* maxTeam = &teams.find(maxTeamId)->data;

    CompleteTeam* minComplete;
    if (completeTeams.find(minTeamId) != nullptr){
        minComplete = &completeTeams.find(minTeamId)->data;
    }
    else{
        minComplete = &completeTeams.findMinBigger(minTeamId)->data;
    }
    CompleteTeam* maxComplete;
    if (completeTeams.find(maxTeamId) != nullptr){
        maxComplete = &completeTeams.find(maxTeamId)->data;
    }
    else{
        maxComplete = &completeTeams.findMaxSmaller(maxTeamId)->data;
    }
    LNode<CompleteTeam*>* minCompleteList = minComplete->getCompleteNode();
    LNode<CompleteTeam*>* maxCompleteList = maxComplete->getCompleteNode();
    //LNode<CompleteTeam*>* iter = minCompleteList;
    if (minTeamId == maxTeamId){
        return minTeamId;
    }

  //  List<CompleteTeam> list2 = List(*minCompleteList->m_data, *maxCompleteList->m_data);
    List<CompleteTeam*> list;
    CompleteTeam* first = new CompleteTeam(minComplete->getId(), minComplete->getScore());
    list.insertFront(first);
    LNode<CompleteTeam*>* iter = minCompleteList->m_next;
    int cnt = 1;
    while(iter != maxCompleteList->m_next) {
        CompleteTeam* x = new CompleteTeam(iter->m_data->getId(), iter->m_data->getScore());
        list.append(x);
        iter = iter->m_next;
        cnt++;
    }
    while (list.getHead() != list.getTail()){
        LNode<CompleteTeam*>* it = list.getHead();
        while (it != list.getTail() && it != nullptr){
            if (it->m_data->getPoints() > it->m_next->m_data->getPoints()){
                it->m_data->addPoints(it->m_next->m_data->getPoints() + 3);
                list.remove(it->m_next);

            }
            else if(it->m_data->getPoints() < it->m_next->m_data->getPoints()){
                it->m_next->m_data->addPoints(it->m_data->getPoints() + 3);
                list.remove(it);
            }
            else{
                if (it->m_data->getId() > it->m_next->m_data->getId()){
                    it->m_data->addPoints(it->m_next->m_data->getPoints() + 3);
                    list.remove(it->m_next);
                }
                else {
                    it->m_next->m_data->addPoints(it->m_data->getPoints() + 3);
                    list.remove(it);
                }
            }
        }
    }
    // delete new list and complete teams
    return list.getHead()->m_data->getId();








    // List<LNode<CompleteTeam*>*> list;
    /*
    list.insertFront(minCompleteList);
    LNode<CompleteTeam*>* iter = minCompleteList->m_next;
    int r = 1;
    while(iter != maxCompleteList->m_next){
        list.append(iter);
        iter = iter->m_next;
        r++;
    }
    while (list.getHead() != list.getTail()){
       LNode< LNode<CompleteTeam*>*>* it = list.getHead();
       while(it->m_next != nullptr){
           if (it->m_data->m_data->getScore() > it->m_next->m_data->m_data->getScore()){

           }
       }

    }





    int r = 1;
    struct couple{
        int id;
        int score;
    };



    List<couple> list1;
    list1.insertFront();
  //  LNode<CompleteTeam*>* iter = minCompleteList;
    while (iter != maxCompleteList ){

        iter = iter->m_next;
        r++;
    }
    int arr[r][2]; //first in row is id, second play match score







    return 2;
     */

}

bool isComplete(node<Team>* t)
{
    return t->data.isComplete();
}

int abs(int x){
    if (x < 0){
        return -x;
    } else{
        return x;
    }
}
