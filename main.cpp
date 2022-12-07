#include "Tree.h"
#include "worldcup23a1.h"
#include "iostream"


int main()
{

    world_cup_t *obj = new world_cup_t();
    StatusType res = obj->add_team(1, 10000);
    (res == StatusType::SUCCESS);
    res = obj->add_team(2, 20000);
    (res == StatusType::SUCCESS);
    res = obj->add_team(3, 30000);
    (res == StatusType::SUCCESS);
    res = obj->add_team(4, 40000);
    (res == StatusType::SUCCESS);
    res = obj->add_player(1001, 1, 10, 0, 0, false);
    (res == StatusType::SUCCESS);
    res = obj->add_player(1002, 1, 10, 0, 0, false);
    (res == StatusType::SUCCESS);
    res = obj->add_player(1003, 1, 10, 0, 0, false);
    (res == StatusType::SUCCESS);
    res = obj->add_player(1004, 1, 10, 0, 2, false);
    (res == StatusType::SUCCESS);
    res = obj->add_player(1005, 1, 10, 0, 0, false);
    (res == StatusType::SUCCESS);
    res = obj->add_player(1006, 1, 10, 4, 3, false);
    (res == StatusType::SUCCESS);
    res = obj->add_player(1007, 1, 10, 0, 0, false);
    (res == StatusType::SUCCESS);
    res = obj->remove_player(1007);
    (res == StatusType::SUCCESS);
    res = obj->remove_player(1002);
    (res == StatusType::SUCCESS);
    res = obj->add_player(1008, 1, 10, 0, 0, true);
    (res == StatusType::SUCCESS);
    res = obj->add_player(1009, 1, 10, 0, 0, false);
    (res == StatusType::SUCCESS);
    res = obj->add_player(1010, 1, 10, 0, 0, false);
    (res == StatusType::SUCCESS);
    res = obj->add_player(1011, 1, 10, 0, 0, false);
    (res == StatusType::SUCCESS);
    res = obj->remove_player(1001);
    (res == StatusType::SUCCESS);
    res = obj->add_player(1012, 1, 10, 0, 0, false);
    (res == StatusType::SUCCESS);

    res = obj->add_player(2001, 2, 20, 0, 0, false);
    (res == StatusType::SUCCESS);
    res = obj->add_player(2002, 2, 20, 0, 0, false);
    (res == StatusType::SUCCESS);
    res = obj->add_player(2003, 2, 20, 0, 0, false);
    (res == StatusType::SUCCESS);
    res = obj->add_player(2004, 2, 20, 0, 0, false);
    (res == StatusType::SUCCESS);
    res = obj->add_player(2005, 2, 20, 0, 0, false);
    (res == StatusType::SUCCESS);
    res = obj->remove_player(1011);
    (res == StatusType::SUCCESS);
    res = obj->add_player(2006, 2, 20, 0, 0, false);
    (res == StatusType::SUCCESS);
    res = obj->add_player(2007, 2, 20, 0, 0, false);
    (res == StatusType::SUCCESS);
    res = obj->add_player(2008, 2, 20, 6, 4, true);
    (res == StatusType::SUCCESS);
    res = obj->add_player(2009, 2, 20, 0, 0, false);
    (res == StatusType::SUCCESS);
    res = obj->remove_player(2001);
    (res == StatusType::SUCCESS);
    res = obj->add_player(2010, 2, 0, 0, 0, false);
    (res == StatusType::SUCCESS);
    res = obj->add_player(2011, 2, 20, 0, 0, false);
    (res == StatusType::SUCCESS);
    res = obj->remove_player(2010);
    (res == StatusType::SUCCESS);

    res = obj->add_player(3001, 3, 30, 0, 0, false);
    (res == StatusType::SUCCESS);
    res = obj->add_player(3002, 3, 30, 0, 0, false);
    (res == StatusType::SUCCESS);
    res = obj->add_player(3003, 3, 30, 0, 0, false);
    (res == StatusType::SUCCESS);
    res = obj->add_player(3004, 3, 30, 0, 0, false);
    (res == StatusType::SUCCESS);
    res = obj->add_player(3005, 3, 30, 2, 0, false);
    (res == StatusType::SUCCESS);
    res = obj->add_player(3006, 3, 30, 0, 0, false);
    (res == StatusType::SUCCESS);
    res = obj->add_player(3007, 3, 30, 0, 0, false);
    (res == StatusType::SUCCESS);
    res = obj->add_player(3008, 3, 30, 0, 0, false);
    (res == StatusType::SUCCESS);
    res = obj->add_player(3009, 3, 30, 0, 2, false);
    (res == StatusType::SUCCESS);
    res = obj->add_player(3010, 3, 30, 0, 0, true);
    (res == StatusType::SUCCESS);
    res = obj->add_player(3011, 3, 30, 0, 0, true);

    (res == StatusType::SUCCESS);
    res = obj->remove_player(3011);
    (res == StatusType::SUCCESS);
    res = obj->remove_player(3008);
    (res == StatusType::SUCCESS);
    res = obj->remove_player(3002);
    (res == StatusType::SUCCESS);
    res = obj->remove_player(3010);
    (res == StatusType::SUCCESS);
  //  res = obj->remove_player(3009);
    (res == StatusType::SUCCESS);
    res = obj->remove_player(3005);
    (res == StatusType::SUCCESS);
    res = obj->remove_player(3004);
    (res == StatusType::SUCCESS);
 //   res = obj->remove_player(3006);
    (res == StatusType::SUCCESS);
    res = obj->remove_player(3007);
    (res == StatusType::SUCCESS);
    res = obj->remove_player(3001);
    (res == StatusType::SUCCESS);
    res = obj->remove_player(3003);
    (res == StatusType::SUCCESS);

    res = obj->add_player(4001, 4, 2, 1, 2, false);
    (res == StatusType::SUCCESS);
    res = obj->add_player(4002, 4, 2, 2, 2, false);
    (res == StatusType::SUCCESS);

    delete obj;
    return 0;
}