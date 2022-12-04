#include "Tree.h"
#include "worldcup23a1.h"

int main()
{
    StatusType status;
    world_cup_t* worldCup = new world_cup_t();
    for (int i = 1; i < 3; ++i) {
        status = worldCup->add_team(i,10*i/3);
    }
 //   for (int i = 1; i < 3; ++i){
//        status = worldCup->remove_team(i);
 //   }

    for (int i = 0; i < 50; ++i) {
        status = worldCup->add_player(i,i%2 + 1,i%3,i%5,i%4,(i/3)%2);
    }
    status = worldCup->add_player(3, 1, 1, 1, 1, true);
    int x = worldCup->get_top_scorer(-1).ans();
    return 0;
    /*

   Tree<int>* tree = new Tree<int>;
   tree->insert(3);
   tree->insert(4);
   tree->insert(2);
   tree->insert(1);
   tree->insert(0);
   tree->remove(3);
    return 0;*/
}
