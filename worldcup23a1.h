// 
// 234218 Data Structures 1.
// Semester: 2023A (winter).
// Wet Exercise #1.
// 
// Recommended TAB size to view this file: 8.
// 
// The following header file contains all methods we expect you to implement.
// You MAY add private methods and fields of your own.
// DO NOT erase or modify the signatures of the public methods.
// DO NOT modify the preprocessors in this file.
// DO NOT use the preprocessors in your other code files.
// 

#ifndef WORLDCUP23A1_H_
#define WORLDCUP23A1_H_

#include "wet1util.h"
#include "Tree.h"
#include "Player.h"
#include "PlayerId.h"
#include "PlayerRank.h"
#include "Team.h"
#include "CompleteTeam.h"
//#include "List.h"

class world_cup_t {
private:
    int numOfPlayers;
    Tree<Team> teams;
    Tree<PlayerRank> playersRank;
    Tree<PlayerId> playersId;
    Tree<CompleteTeam> completeTeams;
    List<PlayerRank> playerRankList;
    List<CompleteTeam> completeTeamList;


public:
	// <DO-NOT-MODIFY> {
	
	world_cup_t();
	virtual ~world_cup_t()=default;
	
	StatusType add_team(int teamId, int points);
	
	StatusType remove_team(int teamId);
	
	StatusType add_player(int playerId, int teamId, int gamesPlayed,
	                      int goals, int cards, bool goalKeeper);
	
	StatusType remove_player(int playerId);
	
	StatusType update_player_stats(int playerId, int gamesPlayed,
	                                int scoredGoals, int cardsReceived);
	
	StatusType play_match(int teamId1, int teamId2);
	
	output_t<int> get_num_played_games(int playerId);
	
	output_t<int> get_team_points(int teamId);
	
	StatusType unite_teams(int teamId1, int teamId2, int newTeamId);
	
	output_t<int> get_top_scorer(int teamId);
	
	output_t<int> get_all_players_count(int teamId);
	
	StatusType get_all_players(int teamId, int *const output);
	
	output_t<int> get_closest_player(int playerId, int teamId);
	
	output_t<int> knockout_winner(int minTeamId, int maxTeamId);
	
	// } </DO-NOT-MODIFY>
};

//is it allowed?
bool isComplete(node<Team>* t);

template <class T>
void mergeSort(T* array1, T* array2, T* output, int n, int m)
{
    int k = 0, j = 0;
    while (k < n && j < m) {
        if (array1[k] < array2[j]) {
            output[k + j] = array1[k];
            k++;
        } else {
            output[k + j] = array2[j];
            j++;
        }
    }
    if (k >= n)
        for (; j < m; ++j) {
            output[k + j] = array2[j];
        }
    else
        for (; k < n; ++k) {
            output[k + j] = array1[k];
        }
}

template<class T>
node<T>* sortedArray2Tree(T *input, int start, int end) {
    if(start > end)
        return nullptr;

    int mid = (start + end)/2;
    try {
        node<T> *root = new node<T>();
        root->data = input[mid];
        root->l = sortedArray2Tree(input,start,mid - 1);
        root->r = sortedArray2Tree(input,mid + 1, end);
        return root;
    }
    catch (std::bad_alloc& e) {
        throw e;
    }
}

void updatePlayerIdPointers(node<Player>* player, int num);

void updateTeamPlayerRankPointers(node<Player>* player, int num);

#endif // WORLDCUP23A1_H_
