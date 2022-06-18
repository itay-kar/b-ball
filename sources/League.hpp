#pragma once
#include <vector>
#include <map>
#include <set>
#include <algorithm>
#include <iomanip>
#include <iostream>
using namespace std;

#include "Game.hpp"
#include "Schedule.hpp"
#include "Team.hpp"
using namespace b_ball;

const vector<string> names = {"Net Rippers",
                            "Basket Hounds",
                            "D-Fence",
                            "Upcourt Funk Me Up",
                            "Spare Balls",
                            "Balls to the Wall",
                            "The Ball Boyz",
                            "Travelers",
                            "Jazz Me Up",
                            "Droolers and Dribblers",
                            "Shattered Backboards",
                            "Dunkin Dads",
                            "Lay Up Lay Down",
                            "Tipped Off",
                            "Slammed Dunk",
                            "Ball Hogz",
                            "Nose Pick and Roll",
                            "On Da Rebound",
                            "Net Positive",
                            "Pointing Guards"};

const unsigned int MAX_GAMES_PER_ROUND = 10;
const unsigned int FIVE = 5;
namespace b_ball
{
    class League
    {
    private:
        vector<Team *> league_teams;
        Schedule league_schedule;
        
        public:
        League(); 
        ~League();
        League(vector<Team *> teams);
        vector<Team *>& getTeams();
        void startLeague();
        void getStats();
        void getLeaders(unsigned int n);
        void getLongestWS();
        void getLongestLS();
        void getMostPointsFor();
        void getMostPointsAgainst();
        void getMostPointsDiff();
        void getFirstPlace();
        void getLastPlace();
        void getRoundWithMostPoints();
        void getRoundResults(unsigned int round);
        void getTeamRoundResults(Team *team,unsigned int round);
        void getTeamResults(Team *team);
        void printLeague();
        void printSchedule();
        static void printTeam(Team *team);
    };
}