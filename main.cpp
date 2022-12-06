#include "Tree.h"
#include "worldcup23a1.h"
#include "iostream"


int main()
{

    world_cup_t *obj = new world_cup_t();
    StatusType res = obj->add_team(1, 2);
    res = obj->add_player(1, 1, 3, 3, 3, true);
    res = obj->remove_player(1);
    res = res;
    delete obj;
    return 0;
}