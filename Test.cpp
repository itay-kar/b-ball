#include "../doctest.h"
#include "League.hpp"

TEST_CASE("Checking Functions work")
{
    vector<Team *> teams;
    Team *team1 = new Team("Team1");
    Team *team2 = new Team("Team2");
    Team *team3 = new Team("Team3");
    Team *team4 = new Team("Team4");

    teams.push_back(team1);
    teams.push_back(team2);
    teams.push_back(team3);
    teams.push_back(team4);
    
    League a(teams);

    CHECK_NOTHROW(a.startLeague());
    CHECK_NOTHROW(a.getFirstPlace());
    CHECK_NOTHROW(a.getLastPlace());
    CHECK_NOTHROW(a.getLeaders(3));
    CHECK_NOTHROW(a.getLongestLS());
    CHECK_NOTHROW(a.getLongestWS());
    CHECK_NOTHROW(a.getMostPointsAgainst());
    CHECK_NOTHROW(a.getMostPointsDiff());
    CHECK_NOTHROW(a.getMostPointsFor());
    CHECK_NOTHROW(a.getRoundResults(7));
    CHECK_NOTHROW(a.getRoundWithMostPoints());
    CHECK_NOTHROW(a.getTeamResults(a.getTeams()[4]));
    CHECK_NOTHROW(a.getTeamRoundResults(a.getTeams()[4], 4));
    CHECK_NOTHROW(a.printLeague());
    CHECK_NOTHROW(a.printSchedule());
}

    TEST_CASE("Trying to build a league with too many teams")
    {
        vector<Team *> teams;
        teams.push_back(new Team("Team1"));
        teams.push_back(new Team("Team2"));
        teams.push_back(new Team("Team3"));
        teams.push_back(new Team("Team4"));
        teams.push_back(new Team("Team5"));
        teams.push_back(new Team("Team6"));
        teams.push_back(new Team("Team7"));
        teams.push_back(new Team("Team8"));
        teams.push_back(new Team("Team9"));
        teams.push_back(new Team("Team10"));
        teams.push_back(new Team("Team11"));
        teams.push_back(new Team("Team12"));
        teams.push_back(new Team("Team13"));
        teams.push_back(new Team("Team14"));
        teams.push_back(new Team("Team15"));
        teams.push_back(new Team("Team16"));
        teams.push_back(new Team("Team17"));
        teams.push_back(new Team("Team18"));
        teams.push_back(new Team("Team19"));
        teams.push_back(new Team("Team20"));
        teams.push_back(new Team("Team21"));
        teams.push_back(new Team("Team22"));

        CHECK_THROWS(League a(teams));
    
    // CHECK_NOTHROW(a.printLeague());
}