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
                             completeTeams(Tree<CompleteTeam>()), playerRankList(List<PlayerRank>()), completeTeamList(List<CompleteTeam>())
{
	// TODO: Your code goes here
}

/*
world_cup_t::~world_cup_t()
{
	// TODO: Your code goes here
}
 */


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
        Player* new_player = new Player(playerId, teamId, gamesPlayed, goals, cards, goalKeeper);
        PlayerRank* new_player_rank = new PlayerRank(playerId,goals,cards);
        PlayerRank* new_player_group_rank = new PlayerRank(playerId,goals,cards);

        Team* new_player_team = &teams.find(teamId)->data;
        new_player->setTeam(new_player_team,new_player_team->getGamesPlayed(),new_player_team->getGamesPlayedPoint());

        node<PlayerRank>* prevInList = playersRank.findMaxSmaller(*new_player_rank);
        if (prevInList != nullptr){
            playerRankList.insertAfter(prevInList->data.getPlayerNode(), *new_player_rank);

        }
        else{
            playerRankList.insertFront(*new_player_rank);
        }
        new_player_rank->setPlayerNode(playerRankList.getLastAdded());
        new_player_group_rank->setPlayerNode(playerRankList.getLastAdded());
        playersRank.insert(*new_player_rank);
        Player* temp = new_player_team->addPlayer(new_player,new_player_group_rank);
        PlayerId* playerId1 = new PlayerId(*temp);
        playersId.insert(*playerId1);
        temp->setPlayerRank(new_player_rank);
        temp->setTeamPlayerRank(new_player_group_rank);
        temp->setPlayerId(&playersId.find(*playerId1)->data);


        delete(new_player);
        delete(playerId1);
        numOfPlayers++;


        if (new_player_team->isComplete() && (completeTeams.find(teamId) == nullptr)){
            CompleteTeam* new_completeTeam =
                    new CompleteTeam(teamId,new_player_team->getPoints(),new_player_team->getGoals(),new_player_team->getCards());

            completeTeams.insert(*new_completeTeam);
            node<CompleteTeam>* prevConInList = completeTeams.findMaxSmaller(*new_completeTeam);
            if (prevConInList != nullptr && completeTeamList.getSize() > 0) {
                completeTeamList.insertAfter(prevConInList->data.getCompleteNode(), completeTeams.find(*new_completeTeam)->data);
            } else{
                completeTeamList.insertFront(completeTeams.find(*new_completeTeam)->data);
            }
            completeTeams.find(*new_completeTeam)->data.setCompleteTeamNode(completeTeamList.getLastAdded());
            new_player_team->setCompleteTeamPointer(&completeTeams.find(*new_completeTeam)->data);
            delete(new_completeTeam);
        }
    }
    catch (const std::bad_alloc &)
    {
        return StatusType::ALLOCATION_ERROR;
    }
	return StatusType::SUCCESS;
}

StatusType world_cup_t::remove_player(int playerId)
{
	// TODO: Your code goes here

    if (playerId <= 0){
        return StatusType::INVALID_INPUT;
    }

    PlayerId *currPlayer = &playersId.find(playerId)->data;
    if (currPlayer == nullptr){
        return StatusType::FAILURE;
    }


    bool is_goalkeeper = currPlayer->getPlayer()->isGoalKeeper();
    Team* currTeam = currPlayer->getPlayer()->getTeam();

    try
    {
        PlayerRank temp_rank = *currPlayer->getPlayer()->getPlayerRank();
        Player temp_player = *currPlayer->getPlayer();
        playerRankList.remove(temp_rank.getPlayerNode());
        playersRank.remove(temp_rank);
        playersId.remove(*currPlayer);
        currTeam->removePlayer(&temp_player);

        if (is_goalkeeper){
            currTeam->updateGoalkeepersNum(-1);
        }

        node<CompleteTeam>* currComplete = completeTeams.find(*currTeam->getCompleteTeamPointer());
        if (!currTeam->isComplete() && currComplete){
            CompleteTeam temp_team = currComplete->data;
            completeTeamList.remove(temp_team.getCompleteNode());
            completeTeams.remove(*currTeam->getCompleteTeamPointer());
        }

        numOfPlayers--;
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
    if(playerId <=0 || gamesPlayed < 0 || scoredGoals < 0 || cardsReceived < 0)
        return StatusType::INVALID_INPUT;

    node<PlayerId>* currPlayerId = playersId.find(playerId);
    if(currPlayerId == nullptr)
        return StatusType::FAILURE;

    Player* currPlayer = currPlayerId->data.getPlayer();
    PlayerRank* outdated_player_rank = currPlayer->getPlayerRank();

    currPlayer->updateStats(gamesPlayed,scoredGoals,cardsReceived);
    currPlayer->getTeam()->updateStats(scoredGoals,cardsReceived, 0);

    PlayerRank* newPlayerRank = new PlayerRank(playerId, currPlayer->getGoals(), currPlayer->getCards());
    PlayerRank* newPlayerTeamRank = new PlayerRank(playerId, currPlayer->getGoals(), currPlayer->getCards());
    Team* currTeam = currPlayer->getTeam();

    playerRankList.remove(outdated_player_rank->getPlayerNode());
    playersRank.remove(*outdated_player_rank);
    currTeam->getPlayersRank().remove(*outdated_player_rank);
    currPlayer->clearRankPointers();

    playersRank.insert(*newPlayerRank);
    node<PlayerRank>* added_node = playersRank.find(*newPlayerRank);

    node<PlayerRank>* prevInList = playersRank.findMaxSmaller(*newPlayerRank);
    if (prevInList != nullptr && playerRankList.getSize() > 0){
        playerRankList.insertAfter(prevInList->data.getPlayerNode(), *newPlayerRank);
    }
    else{
        playerRankList.insertFront(*newPlayerRank); //if its the smallest one, creates one node list- should add insert before
    }
    newPlayerRank->setPlayerNode(playerRankList.getLastAdded());
    added_node->data.setPlayerNode(playerRankList.getLastAdded());
    currPlayer->setPlayerRank(newPlayerRank);

    //PlayerRank* currTeamPlayerRank = currPlayer->getGroupPlayerRank();
    currTeam->getPlayersRank().insert(*newPlayerTeamRank);

    currPlayer->setTeamPlayerRank(newPlayerTeamRank);

    //delete(outdated_player_rank);
    //delete(newPlayerRank);

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
    if(newTeamId != teamId1 && newTeamId != teamId2) {
        Team *new_team = &teams.find(newTeamId)->data;
        if(new_team)
            return StatusType::FAILURE;
    }

    if(!team1 || !team2)
        return StatusType::FAILURE;

    try {
        //setup ints
        int points = team1->getPoints() + team2->getPoints();
        int goals = team1->getGoals() + team2->getGoals();
        int cards = team1->getCards() + team2->getCards();
        int players = team1->getPlayersNum() + team2->getPlayersNum();
        int goalKeepers = team1->getGoalKeepersNum() + team2->getGoalKeepersNum();
        int games_played = team1->getGamesPlayed() + team2->getGamesPlayed();

        //TODO : create player array
        Tree<Player>* team1_players = team1->getPlayers();
        Tree<Player>* team2_players = team2->getPlayers();
        const int players1 = team1->getPlayersNum();
        const int players2 = team2->getPlayersNum();
        Player* team1_array = new Player[players1];
        Player* team2_array = new Player[players2];
        Player* merged_player_array = new Player[players1 + players2];
        team1_players->tree2ArrayInOrder(team1_array);
        team2_players->tree2ArrayInOrder(team2_array);
        mergeSort(team1_array,team2_array,merged_player_array,players1,players2);

        Tree<Player>* merged_players = new Tree<Player>(sortedArray2Tree(merged_player_array,0,players1+players2 - 1));
        merged_players->inOrder(updatePlayerIdPointers,0);

        //TODO : create player rank array
        Tree<PlayerRank>* team1_ranks = &team1->getPlayersRank();
        Tree<PlayerRank>* team2_ranks = &team2->getPlayersRank();
        PlayerRank* team1_rank_array = new PlayerRank[players1];
        PlayerRank* team2_rank_array = new PlayerRank[players2];
        PlayerRank* merged_rank_array = new PlayerRank[players1 + players2];
        team1_ranks->tree2ArrayInOrder(team1_rank_array);
        team2_ranks->tree2ArrayInOrder(team2_rank_array);
        mergeSort(team1_rank_array,team2_rank_array,merged_rank_array,players1,players2);

        Tree<PlayerRank>* merged_ranks = new Tree<PlayerRank>(sortedArray2Tree(merged_rank_array,0,players1+players2 - 1));

        Team* new_team = new Team(newTeamId,points,goals,cards,players,games_played,goalKeepers,
                                  merged_players,merged_ranks);

        delete[] team1_array;
        delete[] team2_array;
        delete[] merged_player_array;
        delete[] team1_rank_array;
        delete[] team2_rank_array;
        delete[] merged_rank_array;

        //handle past complete teams
        //TODO : if needed!
        if(team1->isComplete()) {
            completeTeamList.remove(team1->getCompleteTeamPointer()->getCompleteNode());
            completeTeams.remove(teamId1);
        }
        if(team2->isComplete()) {
            completeTeamList.remove(team2->getCompleteTeamPointer()->getCompleteNode());
            completeTeams.remove(teamId2);
        }

        if(new_team->isComplete()) {
            CompleteTeam *new_complete_team = new CompleteTeam(newTeamId, points, goals, cards);
            node<CompleteTeam>* prevComInList = completeTeams.findMaxSmaller(*new_complete_team);
            if (prevComInList != nullptr && completeTeamList.getSize() > 0) {
                completeTeamList.insertAfter(prevComInList->data.getCompleteNode(), *new_complete_team);
            } else{
                completeTeamList.insertFront(*new_complete_team);
            }
            completeTeams.insert(*new_complete_team);
            completeTeams.find(*new_complete_team)->data.setCompleteTeamNode(completeTeamList.getLastAdded());
            new_team->setCompleteTeamPointer(&completeTeams.find(*new_complete_team)->data);
        }
        teams.insert(*new_team);
    }
    catch (const std::bad_alloc &) {
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

    Tree<Player>* currTree = currTeam->getPlayers();
    Player* currPlayer = &currTree->find(playerId)->data;
//     Player* currPlayer = &currTeam->getPlayers().find(playerId)->data;
     //PlayerId* currPlayerId = &playersId.find(playerId)->data; //complexity!!
     //Player* currPlayer = currPlayerId->getPlayer();
    if (currPlayer->getTeam()->getId() != teamId){
        return StatusType::FAILURE;
    }
    PlayerRank* currRank = currPlayer->getPlayerRank();
    if (!currPlayer->getPlayerRank()->getPlayerNode()->m_prev) {
        return currPlayer->getPlayerRank()->getPlayerNode()->m_next->m_data->getId();
    }
    PlayerRank *prevInList = currPlayer->getPlayerRank()->getPlayerNode()->m_prev->m_data;
    if (!currPlayer->getPlayerRank()->getPlayerNode()->m_next){
        return prevInList->getId();
    }
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
    if ((minTeamId <0) || (maxTeamId<0) || (maxTeamId<minTeamId)){
        return StatusType::INVALID_INPUT;
    }

    CompleteTeam *minComplete;
    if (completeTeams.find(minTeamId) != nullptr) {
        minComplete = &completeTeams.find(minTeamId)->data;
        minComplete = minComplete->getCompleteNode()->m_data;
    } else {
        minComplete = &completeTeams.findMinBigger(minTeamId)->data;
        minComplete = minComplete->getCompleteNode()->m_data;
    }
    CompleteTeam *maxComplete;
    if (completeTeams.find(maxTeamId) != nullptr) {
        maxComplete = &completeTeams.find(maxTeamId)->data;
        maxComplete = maxComplete->getCompleteNode()->m_data;
    } else {
        maxComplete = &completeTeams.findMaxSmaller(maxTeamId)->data;
        maxComplete = maxComplete->getCompleteNode()->m_data;

    }
    LNode<CompleteTeam > *minCompleteList = minComplete->getCompleteNode();
    LNode<CompleteTeam > *maxCompleteList = maxComplete->getCompleteNode();
    //LNode<CompleteTeam*>* iter = minCompleteList;
    if (minTeamId == maxTeamId) {
        return minTeamId;
    }
    if (maxComplete < minComplete){
        return StatusType::FAILURE;
    }
    //  List<CompleteTeam> list2 = List(*minCompleteList->m_data, *maxCompleteList->m_data);
    List<CompleteTeam > list;
    CompleteTeam *first = new CompleteTeam(minComplete->getId(), minComplete->getScore());
    list.insertFront(*first);
    LNode<CompleteTeam > *iter = minCompleteList->m_next;
    int cnt = 1;
    while (iter != maxCompleteList->m_next) {
        CompleteTeam *x = new CompleteTeam(iter->m_data->getId(), iter->m_data->getScore());
        list.append(*x);
        iter = iter->m_next;
        cnt++;
    }
    while (list.getHead() != list.getTail()) {
        LNode<CompleteTeam > *it = list.getHead();
        while (it != list.getTail() && it != nullptr) {
            if (it->m_data->getPoints() > it->m_next->m_data->getPoints()) {
                it->m_data->addPoints(it->m_next->m_data->getPoints() + 3);

                delete(it->m_next->m_data);
                list.remove(it->m_next);
                it = it->m_next;

            } else if (it->m_data->getPoints() < it->m_next->m_data->getPoints()) {
                it->m_next->m_data->addPoints(it->m_data->getPoints() + 3);
                //  list.remove(it);
                if (it->m_next->m_next != nullptr) {
                    it = it->m_next->m_next;
                    delete(it->m_prev->m_prev->m_data);
                    list.remove(it->m_prev->m_prev);
                } else {
                    delete(it->m_data);
                    list.remove(it);
                    it = nullptr;
                }


            } else {
                if (it->m_data->getId() > it->m_next->m_data->getId()) {
                    it->m_data->addPoints(it->m_next->m_data->getPoints() + 3);
                    delete(it->m_next->m_data);
                    list.remove(it->m_next);
                    it = it->m_next;

                } else {
                    it->m_next->m_data->addPoints(it->m_data->getPoints() + 3);
                    //  list.remove(it);
                    if (it->m_next->m_next != nullptr) {
                        it = it->m_next->m_next;
                        delete(it->m_prev->m_prev->m_data);
                        list.remove(it->m_prev->m_prev);
                    } else {
                        delete(it->m_data);
                        list.remove(it);
                        it = nullptr;
                    }
                }
            }
        }
    }
    // delete new list and complete teams
    int result = list.getHead()->m_data->getId();
    delete(list.getHead()->m_data);
    return result;

}


bool isComplete(node<Team>* t)
{
    return t->data.isComplete();
}

void updatePlayerIdPointers(node<Player>* player, int num)
{
    player->data.getPlayerId()->setPlayer(&player->data);
}
