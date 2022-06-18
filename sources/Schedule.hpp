#pragma once
#include <map>
#include <vector>
using namespace std;

#include "Game.hpp"
#include "Team.hpp"
namespace b_ball
{
    class Schedule
    {
    private:
        map<unsigned int, vector<Game *>> games_schedule;
        vector<Team*> *league_teams;
    
    public:
        Schedule();
        Schedule(vector<Team *> teams);
        void setSchedule();
        Game* getGame(unsigned int round, Team *home, Team *away);
        map<unsigned int, vector<Game *>> &getGamesSchedule();
        Game* getNextGame();
        Game* getLastGame();
        Game* getNextGame(Team *team);
        void printSchedule();
        void printGames(int round);
        void printTeamGames(Team* team);
    };
};
