#include <queue>
using namespace std;

#include "Schedule.hpp"

namespace b_ball
{
    Schedule::Schedule():league_teams(nullptr){};
 
    
    Schedule::Schedule(vector<Team *> teams)
    {
        league_teams = &teams;
        setSchedule();
    };

    Game *Schedule::getGame(unsigned int round, Team *home, Team *away)
    {
        for (auto it = games_schedule[round].begin(); it != games_schedule[round].end(); it++)
        {
            if ((*it)->getHome() == home && (*it)->getAway() == away)
            {
                return *it;
            }
        }

        throw invalid_argument("No Game between those teams in this round.");
    };

    void Schedule::printSchedule()
    {
        for (size_t i = 0; i < ROUNDS; i++)
        {
            cout << "Round " << i + 1 << endl;
            for (auto it = games_schedule[i].begin(); it != games_schedule[i].end(); it++)
            {
                (*it)->print();
            }
            cout << endl;
        }
    };

    void Schedule::setSchedule()
    {
        vector<Team *> h_vec1;
        vector<Team *> h_vec2;

        Team *fixed = (*league_teams)[0];
        for (size_t i = 1; i < (*league_teams).size() / 2; i++)
        {
            h_vec1.push_back((*league_teams)[i]);
            h_vec2.push_back((*league_teams)[(*league_teams).size() - i]);
        }

        h_vec2.push_back((*league_teams)[(*league_teams).size() / 2]);

        for (size_t i = 0; i < (*league_teams).size() - 1; i++)
        {
            games_schedule[i].push_back(new Game(fixed, h_vec2[0]));
            games_schedule[((*league_teams).size()-1)*2-(i+1)].push_back(new Game(h_vec2[0], fixed));

            for (size_t t = 1; t < h_vec2.size(); t++)
            {
                games_schedule[i].push_back(new Game(h_vec1[t - 1], h_vec2[t]));
                games_schedule[(((*league_teams).size()-1)*2)-(i+1)].push_back(new Game(h_vec2[t], h_vec1[t - 1]));
            }

            h_vec1.insert(h_vec1.begin(), h_vec2.front());
            h_vec2.erase(h_vec2.begin());
            h_vec2.push_back(h_vec1.back());
            h_vec1.pop_back();
        }
    }

    map<unsigned int, vector<Game *>> &Schedule::getGamesSchedule()
    {
        return games_schedule;
    }

    void Schedule::printTeamGames(Team *team)
    {
        for (size_t i = 0; i < ROUNDS; i++)
        {
            for (auto it = games_schedule[i].begin(); it != games_schedule[i].end(); it++)
            {
                if ((*it)->getHome() == team || (*it)->getAway() == team)
                {
                    (*it)->print();
                }
            }
        }
    }
}