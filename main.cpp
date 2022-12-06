#include "Tree.h"
#include "worldcup23a1.h"
#include "iostream"


int main()
{

    SECTION("simple add player")
    {
        world_cup_t *obj = new world_cup_t();
        StatusType res = obj->add_team(1, 2);
        REQUIRE(res == StatusType::SUCCESS);
        res = obj->add_player(1, 1, 3, 3, 3, false);
        REQUIRE(res == StatusType::SUCCESS);
        delete obj;
    }

    SECTION("simple add goal keeper player")
    {
        world_cup_t *obj = new world_cup_t();
        StatusType res = obj->add_team(2, 2);
        REQUIRE(res == StatusType::SUCCESS);
        res = obj->add_player(1, 2, 3, 3, 3, true);
        REQUIRE(res == StatusType::SUCCESS);
        delete obj;
    }

    SECTION("add player with negative id")
    {
        world_cup_t *obj = new world_cup_t();
        StatusType res = obj->add_team(2, 2);
        REQUIRE(res == StatusType::SUCCESS);
        res = obj->add_player(-1, 2, 3, 3, 3, true);
        REQUIRE(res == StatusType::INVALID_INPUT);
        delete obj;
    }

    SECTION("add player with negative team id")
    {
        world_cup_t *obj = new world_cup_t();
        StatusType res = obj->add_team(2, 2);
        REQUIRE(res == StatusType::SUCCESS);
        res = obj->add_player(1, -2, 3, 3, 3, true);
        REQUIRE(res == StatusType::INVALID_INPUT);
        delete obj;
    }

    SECTION("add player with negative games")
    {
        world_cup_t *obj = new world_cup_t();
        StatusType res = obj->add_team(2, 2);
        REQUIRE(res == StatusType::SUCCESS);
        res = obj->add_player(1, 2, -3, 3, 3, true);
        REQUIRE(res == StatusType::INVALID_INPUT);
        delete obj;
    }

    SECTION("add player with 0 id")
    {
        world_cup_t *obj = new world_cup_t();
        StatusType res = obj->add_team(2, 2);
        REQUIRE(res == StatusType::SUCCESS);
        res = obj->add_player(0, 2, 3, 3, 3, true);
        REQUIRE(res == StatusType::INVALID_INPUT);
        delete obj;
    }

    SECTION("add player with 0 team id")
    {
        world_cup_t *obj = new world_cup_t();
        StatusType res = obj->add_team(1, 2);
        REQUIRE(res == StatusType::SUCCESS);
        res = obj->add_player(1, 0, 3, 3, 3, true);
        REQUIRE(res == StatusType::INVALID_INPUT);
        delete obj;
    }

    SECTION("add player with negative cards")
    {
        world_cup_t *obj = new world_cup_t();
        StatusType res = obj->add_team(1, 2);
        REQUIRE(res == StatusType::SUCCESS);
        res = obj->add_player(1, 2, 3, 3, -3, true);
        REQUIRE(res == StatusType::INVALID_INPUT);
        delete obj;
    }

    SECTION("add player with 0 games and positive goals")
    {
        world_cup_t *obj = new world_cup_t();
        StatusType res = obj->add_team(1, 2);
        REQUIRE(res == StatusType::SUCCESS);
        res = obj->add_player(1, 2, 0, 3, 0, true);
        REQUIRE(res == StatusType::INVALID_INPUT);
        delete obj;
    }

    SECTION("add player with 0 games and positive cards")
    {
        world_cup_t *obj = new world_cup_t();
        StatusType res = obj->add_team(1, 2);
        REQUIRE(res == StatusType::SUCCESS);
        res = obj->add_player(1, 2, 0, 0, 3, true);
        REQUIRE(res == StatusType::INVALID_INPUT);
        delete obj;
    }

    SECTION("add player with 0 games and positive goals and cards")
    {
        world_cup_t *obj = new world_cup_t();
        StatusType res = obj->add_team(1, 2);
        REQUIRE(res == StatusType::SUCCESS);
        res = obj->add_player(1, 2, 0, 3, 3, true);
        REQUIRE(res == StatusType::INVALID_INPUT);
        delete obj;
    }

    SECTION("add player with 0 id and 0 team id")
    {
        world_cup_t *obj = new world_cup_t();
        StatusType res = obj->add_team(1, 2);
        REQUIRE(res == StatusType::SUCCESS);
        res = obj->add_player(0, 0, 3, 3, 3, true);
        REQUIRE(res == StatusType::INVALID_INPUT);
        delete obj;
    }

    SECTION("add player with many zeroes")
    {
        world_cup_t *obj = new world_cup_t();
        StatusType res = obj->add_team(1, 2);
        REQUIRE(res == StatusType::SUCCESS);
        res = obj->add_player(0, 2, 0, 0, 0, true);
        REQUIRE(res == StatusType::INVALID_INPUT);
        delete obj;
    }

    SECTION("add player with zero all")
    {
        world_cup_t *obj = new world_cup_t();
        StatusType res = obj->add_team(1, 2);
        REQUIRE(res == StatusType::SUCCESS);
        res = obj->add_player(0, 0, 0, 0, 0, true);
        REQUIRE(res == StatusType::INVALID_INPUT);
        delete obj;
    }

    SECTION("add player that exists")
    {
        world_cup_t *obj = new world_cup_t();
        StatusType res = obj->add_team(1, 2);
        REQUIRE(res == StatusType::SUCCESS);
        res = obj->add_player(1, 1, 3, 3, 3, true);
        REQUIRE(res == StatusType::SUCCESS);
        res = obj->add_player(1, 1, 3, 3, 3, true);
        REQUIRE(res == StatusType::FAILURE);
        delete obj;
    }

    SECTION("add player with team that doesn't exist")
    {
        world_cup_t *obj = new world_cup_t();
        StatusType res = obj->add_team(1, 2);
        REQUIRE(res == StatusType::SUCCESS);
        res = obj->add_player(1, 1, 3, 3, 3, true);
        REQUIRE(res == StatusType::SUCCESS);
        res = obj->add_player(4, 4, 4, 4, 4, true);
        REQUIRE(res == StatusType::FAILURE);
        delete obj;
    }

    SECTION("add teams and players - segel test")
    {
        world_cup_t *obj = new world_cup_t();
        StatusType res = obj->add_team(1, 10000);
        REQUIRE(res == StatusType::SUCCESS);
        res = obj->add_team(2, 20000);
        REQUIRE(res == StatusType::SUCCESS);
        res = obj->add_team(3, 30000);
        REQUIRE(res == StatusType::SUCCESS);
        res = obj->add_team(4, 40000);
        REQUIRE(res == StatusType::SUCCESS);
        res = obj->add_player(1001, 1, 10, 0, 0, false);
        REQUIRE(res == StatusType::SUCCESS);
        res = obj->add_player(1002, 1, 10, 0, 0, false);
        REQUIRE(res == StatusType::SUCCESS);
        res = obj->add_player(1003, 1, 10, 0, 0, false);
        REQUIRE(res == StatusType::SUCCESS);
        res = obj->add_player(1004, 1, 10, 0, 2, false);
        REQUIRE(res == StatusType::SUCCESS);
        res = obj->add_player(1005, 1, 10, 0, 0, false);
        REQUIRE(res == StatusType::SUCCESS);
        res = obj->add_player(1006, 1, 10, 4, 3, false);
        REQUIRE(res == StatusType::SUCCESS);
        res = obj->add_player(1007, 1, 10, 0, 0, false);
        REQUIRE(res == StatusType::SUCCESS);
        res = obj->add_player(1008, 1, 10, 0, 0, true);
        REQUIRE(res == StatusType::SUCCESS);
        res = obj->add_player(1009, 1, 10, 0, 0, false);
        REQUIRE(res == StatusType::SUCCESS);
        res = obj->add_player(1010, 1, 10, 0, 0, false);
        REQUIRE(res == StatusType::SUCCESS);
        res = obj->add_player(1011, 1, 10, 0, 0, false);
        REQUIRE(res == StatusType::SUCCESS);
        res = obj->add_player(1012, 1, 10, 0, 0, false);
        REQUIRE(res == StatusType::SUCCESS);

        res = obj->add_player(2001, 2, 20, 0, 0, false);
        REQUIRE(res == StatusType::SUCCESS);
        res = obj->add_player(2002, 2, 20, 0, 0, false);
        REQUIRE(res == StatusType::SUCCESS);
        res = obj->add_player(2003, 2, 20, 0, 0, false);
        REQUIRE(res == StatusType::SUCCESS);
        res = obj->add_player(2004, 2, 20, 0, 0, false);
        REQUIRE(res == StatusType::SUCCESS);
        res = obj->add_player(2005, 2, 20, 0, 0, false);
        REQUIRE(res == StatusType::SUCCESS);
        res = obj->add_player(2006, 2, 20, 0, 0, false);
        REQUIRE(res == StatusType::SUCCESS);
        res = obj->add_player(2007, 2, 20, 0, 0, false);
        REQUIRE(res == StatusType::SUCCESS);
        res = obj->add_player(2008, 2, 20, 6, 4, true);
        REQUIRE(res == StatusType::SUCCESS);
        res = obj->add_player(2009, 2, 20, 0, 0, false);
        REQUIRE(res == StatusType::SUCCESS);
        res = obj->add_player(2010, 2, 0, 0, 0, false);
        REQUIRE(res == StatusType::SUCCESS);
        res = obj->add_player(2011, 2, 20, 0, 0, false);
        REQUIRE(res == StatusType::SUCCESS);

        res = obj->add_player(3001, 3, 30, 0, 0, false);
        REQUIRE(res == StatusType::SUCCESS);
        res = obj->add_player(3002, 3, 30, 0, 0, false);
        REQUIRE(res == StatusType::SUCCESS);
        res = obj->add_player(3003, 3, 30, 0, 0, false);
        REQUIRE(res == StatusType::SUCCESS);
        res = obj->add_player(3004, 3, 30, 0, 0, false);
        REQUIRE(res == StatusType::SUCCESS);
        res = obj->add_player(3005, 3, 30, 2, 0, false);
        REQUIRE(res == StatusType::SUCCESS);
        res = obj->add_player(3006, 3, 30, 0, 0, false);
        REQUIRE(res == StatusType::SUCCESS);
        res = obj->add_player(3007, 3, 30, 0, 0, false);
        REQUIRE(res == StatusType::SUCCESS);
        res = obj->add_player(3008, 3, 30, 0, 0, false);
        REQUIRE(res == StatusType::SUCCESS);
        res = obj->add_player(3009, 3, 30, 0, 2, false);
        REQUIRE(res == StatusType::SUCCESS);
        res = obj->add_player(3010, 3, 30, 0, 0, true);
        REQUIRE(res == StatusType::SUCCESS);
        res = obj->add_player(3011, 3, 30, 0, 0, true);
        REQUIRE(res == StatusType::SUCCESS);

        res = obj->add_player(4001, 4, 2, 1, 2, false);
        REQUIRE(res == StatusType::SUCCESS);
        res = obj->add_player(4002, 4, 2, 2, 2, false);
        REQUIRE(res == StatusType::SUCCESS);

        delete obj;
    }

    SECTION("simple remove player")
    {
        world_cup_t *obj = new world_cup_t();
        StatusType res = obj->add_team(1, 2);
        REQUIRE(res == StatusType::SUCCESS);
        res = obj->add_player(1, 1, 3, 3, 3, true);
        REQUIRE(res == StatusType::SUCCESS);
        res = obj->remove_player(1);
        REQUIRE(res == StatusType::SUCCESS);
        delete obj;
    }

    SECTION("remove player that doesn't exist")
    {
        world_cup_t *obj = new world_cup_t();
        StatusType res = obj->remove_player(1);
        REQUIRE(res == StatusType::FAILURE);
        delete obj;
    }

    SECTION("remove player twice")
    {
        world_cup_t *obj = new world_cup_t();
        StatusType res = obj->add_team(1, 2);
        REQUIRE(res == StatusType::SUCCESS);
        res = obj->add_player(1, 1, 3, 3, 3, true);
        REQUIRE(res == StatusType::SUCCESS);
        res = obj->remove_player(1);
        REQUIRE(res == StatusType::SUCCESS);
        res = obj->remove_player(1);
        REQUIRE(res == StatusType::FAILURE);
        delete obj;
    }

    SECTION("remove player with negative id")
    {
        world_cup_t *obj = new world_cup_t();
        StatusType res = obj->remove_player(-1);
        REQUIRE(res == StatusType::INVALID_INPUT);
        delete obj;
    }

    SECTION("remove player with 0 id")
    {
        world_cup_t *obj = new world_cup_t();
        StatusType res = obj->remove_player(0);
        REQUIRE(res == StatusType::INVALID_INPUT);
        delete obj;
    }

    SECTION("add teams and players - segel test - remove at random stages")
    {
        world_cup_t *obj = new world_cup_t();
        StatusType res = obj->add_team(1, 10000);
        REQUIRE(res == StatusType::SUCCESS);
        res = obj->add_team(2, 20000);
        REQUIRE(res == StatusType::SUCCESS);
        res = obj->add_team(3, 30000);
        REQUIRE(res == StatusType::SUCCESS);
        res = obj->add_team(4, 40000);
        REQUIRE(res == StatusType::SUCCESS);
        res = obj->add_player(1001, 1, 10, 0, 0, false);
        REQUIRE(res == StatusType::SUCCESS);
        res = obj->add_player(1002, 1, 10, 0, 0, false);
        REQUIRE(res == StatusType::SUCCESS);
        res = obj->add_player(1003, 1, 10, 0, 0, false);
        REQUIRE(res == StatusType::SUCCESS);
        res = obj->add_player(1004, 1, 10, 0, 2, false);
        REQUIRE(res == StatusType::SUCCESS);
        res = obj->add_player(1005, 1, 10, 0, 0, false);
        REQUIRE(res == StatusType::SUCCESS);
        res = obj->add_player(1006, 1, 10, 4, 3, false);
        REQUIRE(res == StatusType::SUCCESS);
        res = obj->add_player(1007, 1, 10, 0, 0, false);
        REQUIRE(res == StatusType::SUCCESS);
        res = obj->remove_player(1007);
        REQUIRE(res == StatusType::SUCCESS);
        res = obj->remove_player(1002);
        REQUIRE(res == StatusType::SUCCESS);
        res = obj->add_player(1008, 1, 10, 0, 0, true);
        REQUIRE(res == StatusType::SUCCESS);
        res = obj->add_player(1009, 1, 10, 0, 0, false);
        REQUIRE(res == StatusType::SUCCESS);
        res = obj->add_player(1010, 1, 10, 0, 0, false);
        REQUIRE(res == StatusType::SUCCESS);
        res = obj->add_player(1011, 1, 10, 0, 0, false);
        REQUIRE(res == StatusType::SUCCESS);
        res = obj->remove_player(1001);
        REQUIRE(res == StatusType::SUCCESS);
        res = obj->add_player(1012, 1, 10, 0, 0, false);
        REQUIRE(res == StatusType::SUCCESS);

        res = obj->add_player(2001, 2, 20, 0, 0, false);
        REQUIRE(res == StatusType::SUCCESS);
        res = obj->add_player(2002, 2, 20, 0, 0, false);
        REQUIRE(res == StatusType::SUCCESS);
        res = obj->add_player(2003, 2, 20, 0, 0, false);
        REQUIRE(res == StatusType::SUCCESS);
        res = obj->add_player(2004, 2, 20, 0, 0, false);
        REQUIRE(res == StatusType::SUCCESS);
        res = obj->add_player(2005, 2, 20, 0, 0, false);
        REQUIRE(res == StatusType::SUCCESS);
        res = obj->remove_player(1011);
        REQUIRE(res == StatusType::SUCCESS);
        res = obj->add_player(2006, 2, 20, 0, 0, false);
        res = obj->add_player(2007, 2, 20, 0, 0, false);
        res = obj->add_player(2008, 2, 20, 6, 4, true);
        res = obj->add_player(2009, 2, 20, 0, 0, false);
        res = obj->remove_player(2001);
        res = obj->add_player(2010, 2, 0, 0, 0, false);
        res = obj->add_player(2011, 2, 20, 0, 0, false);
        res = obj->remove_player(2010);

        res = obj->add_player(3001, 3, 30, 0, 0, false);
        res = obj->add_player(3002, 3, 30, 0, 0, false);
        res = obj->add_player(3003, 3, 30, 0, 0, false);
        res = obj->add_player(3004, 3, 30, 0, 0, false);
        res = obj->add_player(3005, 3, 30, 2, 0, false);
        res = obj->add_player(3006, 3, 30, 0, 0, false);
        res = obj->add_player(3007, 3, 30, 0, 0, false);
        res = obj->add_player(3008, 3, 30, 0, 0, false);
        res = obj->add_player(3009, 3, 30, 0, 2, false);
        res = obj->add_player(3010, 3, 30, 0, 0, true);
        res = obj->add_player(3011, 3, 30, 0, 0, true);
        res = obj->remove_player(3011);
        res = obj->remove_player(3008);
        res = obj->remove_player(3002);
        res = obj->remove_player(3010);
        res = obj->remove_player(3009);
        res = obj->remove_player(3005);
        res = obj->remove_player(3004);
        res = obj->remove_player(3006);
        res = obj->remove_player(3007);
        res = obj->remove_player(3001);
        res = obj->remove_player(3003);

        res = obj->add_player(4001, 4, 2, 1, 2, false);
        res = obj->add_player(4002, 4, 2, 2, 2, false);

        delete obj;
    }
    return 0;
}