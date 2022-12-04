#include "Tree.h"
#include "worldcup23a1.h"
#include "iostream"

int main()
{
    StatusType status;
    world_cup_t* worldCup = new world_cup_t();
    for (int i = 1; i < 3; ++i) {
        status = worldCup->add_team(i,10*i/3);
    }

<<<<<<< HEAD
  //  for (int i = 0; i < 50; ++i) {
   //     status = worldCup->add_player(i,i%2 + 1,i%3,i%5,i%4,(i/3)%2);
 //   }
    status = worldCup->add_player(21, 1, 1, 1, 20, true);
    status = worldCup->add_player(25, 1, 1, 1, 20, true);
    status = worldCup->add_player(3, 2, 1, 1, 5, false);
    status = worldCup->add_player(4, 2, 1, 1, 1, true);
    status = worldCup->add_player(5, 1, 1, 2, 5, false);
    status = worldCup->add_player(6, 2, 1, 2, 4, true);
    status = worldCup->add_player(24, 2, 1, 2, 3, true);
    status = worldCup->add_player(7, 2, 1, 2, 2, true);
    status = worldCup->add_player(8, 1, 1, 2, 1, true);
    status = worldCup->add_player(9, 2, 1, 5, 30, true);
    status = worldCup->add_player(10, 1, 1, 5, 29, true);
    status = worldCup->add_player(11, 1, 1, 5, 28, true);
    status = worldCup->add_player(12, 1, 1, 5, 27, true);
    status = worldCup->add_player(51, 1, 1, 6, 40, true);
    status = worldCup->add_player(52, 1, 1, 6, 40, true);
    status = worldCup->add_player(53, 1, 1, 6, 40, true);
    status = worldCup->add_player(54, 1, 1, 6, 10, true);
    status = worldCup->add_player(60, 1, 1, 6, 5, true);
    status = worldCup->add_player(70, 1, 1, 6, 4, true);
    status = worldCup->add_player(100, 1, 1, 8, 6, true);
    status = worldCup->add_player(80, 2, 1, 10, 7, true);
    status = worldCup->add_player(90, 2, 1, 10, 7, true);
    status = worldCup->add_player(91, 2, 1, 10, 7, true);
    status = worldCup->add_player(92, 2, 1, 10, 7, true);
    status = worldCup->add_player(93, 2, 1, 10, 7, true);
    status = worldCup->add_player(94, 2, 1, 10, 7, true);
    status = worldCup->add_player(95, 2, 1, 10, 7, true);
    status = worldCup->add_player(96, 2, 1, 10, 7, true);
    status = worldCup->add_player(97, 2, 1, 10, 7, true);
    status = worldCup->add_player(98, 2, 1, 10, 7, true);
    status = worldCup->add_player(99, 2, 1, 10, 7, true);
    status = worldCup->add_player(101, 2, 1, 10, 7, true);
    status = worldCup->add_player(102, 2, 1, 10, 7, true);
    status = worldCup->add_player(106, 2, 1, 10, 7, true);
    status = worldCup->add_player(61, 3, 1, 10, 7, true);
    status = worldCup->add_player(61, 3, 1, 10, 7, true);
    status = worldCup->add_player(62, 3, 1, 10, 7, true);
    status = worldCup->add_player(63, 3, 1, 10, 7, true);
    status = worldCup->add_player(64, 3, 1, 10, 7, true);
    status = worldCup->add_player(65, 3, 1, 10, 7, true);
    status = worldCup->add_player(66, 3, 1, 10, 7, true);
    status = worldCup->add_player(67, 3, 1, 10, 7, true);
    status = worldCup->add_player(68, 3, 1, 10, 7, true);
    status = worldCup->add_player(69, 3, 1, 10, 7, true);
    status = worldCup->add_player(71, 3, 1, 10, 7, true);
    status = worldCup->add_player(72, 3, 1, 10, 7, true);
    status = worldCup->add_player(73, 3, 1, 10, 7, true);
    status = worldCup->add_player(74, 3, 1, 10, 7, true);
    status = worldCup->add_player(75, 3, 1, 10, 7, true);
    status = worldCup->add_player(76, 3, 1, 10, 7, true);

    int x = worldCup->knockout_winner(1, 3).ans();


    return 0;
    /*
=======
=======
>>>>>>> 707bf0c584abfe67f974a045ef8d5308baa74433
    for (int i = 0; i < 50; ++i) {
        status = worldCup->add_player(i,i%2 + 1,i%3,i%5,i%4,(i/3)%2);
    }

    for (int i = 0; i < 50; ++i) {
        status = worldCup->update_player_stats(i,i/4,i%4,i%6);
    }

    for (int i = 0; i < 50; ++i) {
        status = worldCup->remove_player(i/2);
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
    delete(worldCup);
    status = status;
    /*
    status = worldCup->unite_teams(1,2,2);
    //status = worldCup->add_player(3, 1, 1, 1, 1, true);
    //int x = worldCup->get_top_scorer(-1).ans();*/
    return 0;
}
