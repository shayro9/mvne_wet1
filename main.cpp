#include "Tree.h"
#include "worldcup23a1.h"
#include "iostream"

int main()
{
    StatusType status;
    world_cup_t* worldCup = new world_cup_t();
    for (int i = 1; i < 3; ++i) {
        status = worldCup->add_team(1,10*i/3);
    }

    for (int i = 0; i < 2; ++i) {
        status = worldCup->add_player(1,i%2 + 1,i%3,i%5,i%4,(i/3)%2);
    }

    delete(worldCup);
    status = status;
    /*
    for (int i = 0; i < 50; ++i) {
        status = worldCup->update_player_stats(i,i/4,i%4,i%6);
    }

    for (int i = 0; i < 50; ++i) {
        status = worldCup->play_match(i%2 + 1,(i+1)%2 + 1);
        output_t<int> result1 = worldCup->get_team_points(1);
        output_t<int> result2 = worldCup->get_team_points(2);
        std::cout << i << " _ " << result1.ans() << "\n";
        std::cout << i << " _ " << result2.ans() << "\n";
    }

    for (int i = 0; i < 50; ++i) {
        output_t<int> result = worldCup->get_num_played_games(i);
        result.ans();
    }
    status = worldCup->unite_teams(1,2,2);
    //status = worldCup->add_player(3, 1, 1, 1, 1, true);
    //int x = worldCup->get_top_scorer(-1).ans();*/
    return 0;
}
