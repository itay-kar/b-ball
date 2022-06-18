#include "League.hpp"

League::League(){};
League::~League(){
    for(auto const &games : league_schedule.getGamesSchedule()){
        for(auto *game : games.second){
            delete game;
        }
    }

    for(auto *team : league_teams){
        delete team;
    }
};
League::League(vector<Team *> teams)
{
    if (teams.size()>MAX_TEAMS)
    {
        throw invalid_argument("Too many teams");
    }
    
    for (auto it = teams.begin(); it != teams.end(); it++)
    {
        for (auto it2 = it; it2 != teams.end(); it2++)
        {
            if (it == it2)
            {
                continue;
            }
            else
            {
                if ((*it)->getName() == (*it2)->getName())
                {
                    throw invalid_argument("Duplicate team names");
                }
            }
        } 
    }
    

    if (teams.size()<MAX_TEAMS)
    {
        for (unsigned int i = teams.size(); i < MAX_TEAMS; i++)
        {
            teams.push_back(new Team(names[i]));
        }
    }
    
    league_teams = move(teams);
    league_schedule = Schedule(league_teams);
};

vector<Team *> &League::getTeams()
{
    return league_teams;
};


void League::startLeague()
{
    map<unsigned int, vector<Game *>> games_schedule = league_schedule.getGamesSchedule();
    for (auto it = games_schedule.begin(); it != games_schedule.end(); it++)
    {
        for (auto game = (*it).second.begin(); game != (*it).second.end(); game++)
        {
            (*game)->startGame();
        }
    }

        sort(league_teams.begin(), league_teams.end(), [](Team *a, Team *b)
         {
        if (a->getWins() == b->getWins())
        {
            return int(a->getPointsFor()-a->getPointsAgainst()) > int(b->getPointsFor()-b->getPointsAgainst());
        }
        return a->getWins() > b->getWins(); });
}

void League::getStats()
{
    cout << "Title map: W-Wins , L-Losses , PF - Points For , PA - Points Against , PD - Points Diff , WS - Win Streak , LS - Loss Streak"<<endl;
    int i=1;
    const int col = 23;
    const int short_col = 7;
    cout << setfill('*') << setw(FIVE * col) << "*" << endl;
    cout << setfill(' ') << fixed;

    cout<< setw(3) << "#" << setw(MAX_GAMES_PER_ROUND+3) << "Team Name"  << setw(col-short_col) << "W" << setw(short_col) << "L" 
    << setw(short_col) << "PF" << setw(short_col) << "PA" << setw(short_col) << "PD" << setw(short_col) 
    << "WS" << setw(short_col) << "LS" << endl;

    cout << setfill('*') << setw(FIVE * col) << "*" << endl;

    for (Team *team : league_teams)
    {
        cout << setfill(' ')<< setw(3) << i++ << "." << setw(team->getName().size()+3) << team->getName() 
        << setw(col-team->getName().size()+3) << team->getWins() 
        << setw(short_col) << team->getLosses() << setw(short_col) << team->getPointsFor() 
        << setw(short_col) << team->getPointsAgainst() << setw(short_col) << int(team->getPointsFor() -team->getPointsAgainst())
        << setw(short_col) << team->getWinsInARow()  << setw(short_col) << team->getLossesInARow() << endl;
    }
    cout << setfill('*') << setw(4 * col-2) << "*" << endl;
};

void League::getLeaders(unsigned int n)
{
    for (unsigned int i = 0; i < n; i++)
    {
        cout << "Leader " << i+1 << ": " << league_teams[i]->getName() << endl;
    }
}

void League::getLongestWS()
{
    Team *team = *max_element(league_teams.begin(), league_teams.end(), [](Team *a, Team *b)
    {
        return a->getWinsInARow() < b->getWinsInARow();
    });

    cout << team->getName() << " has the longest win streak of " << team->getWinsInARow() << " games." << endl;
}

void League::getLongestLS()
{
    Team *team = *max_element(league_teams.begin(), league_teams.end(), [](Team *a, Team *b)
    {
        return a->getLossesInARow() < b->getLossesInARow();
    });

    cout << team->getName() << " has the longest loss streak of " << team->getLossesInARow() << " games." << endl;
}

void League::getMostPointsFor()
{
    Team *team = *max_element(league_teams.begin(), league_teams.end(), [](Team *a, Team *b)
    {
        return a->getPointsFor() < b->getPointsFor();
    });

    cout << team->getName() << " has the most points for of " << team->getPointsFor() << "." << endl;
}

void League::getMostPointsAgainst()
{
    Team *team = *max_element(league_teams.begin(), league_teams.end(), [](Team *a, Team *b)
    {
        return a->getPointsAgainst() < b->getPointsAgainst();
    });

    cout << team->getName() << " has the most points against of " << team->getPointsAgainst() << "." << endl;
};

void League::getMostPointsDiff()
{
    Team *team = *max_element(league_teams.begin(), league_teams.end(), [](Team *a, Team *b)
    {
        return int(a->getPointsFor() - a->getPointsAgainst()) < int(b->getPointsFor() - b->getPointsAgainst());
    });

    cout << team->getName() << " has the most points difference of " << int(team->getPointsFor() - team->getPointsAgainst()) << "." << endl;
};

void League::getLastPlace()
{
    Team *team = *min_element(league_teams.begin(), league_teams.end(), [](Team *a, Team *b)
    {
        if (a->getWins() == b->getWins())
        {
            return int(a->getPointsFor()-a->getPointsAgainst()) < int(b->getPointsFor()-b->getPointsAgainst());
        }
        return a->getWins() < b->getWins();
    });

    cout << team->getName() << " is the last place team." << endl;
};

void League::getFirstPlace()
{
    cout << league_teams[0]->getName() << " is the first place team." << endl;
};

void League::getRoundResults(unsigned int round)
{
cout << "Round " << round << " Results:" << endl;
   auto games = league_schedule.getGamesSchedule().at(round);
   for_each(games.begin(), games.end(), [](Game *game)
   {
       cout << game->getHome()->getName() << " " << game->getHomeScore() << " - " << game->getAwayScore() << " " << game->getAway()->getName() << endl;
   });
   
};

void League::getRoundWithMostPoints()
{
    unsigned int  max = 0;
    unsigned int  round = 0;
    unsigned int points = 0;
    for (unsigned int i = 0; i < league_schedule.getGamesSchedule().size(); i++)
    {
        points = 0;
        auto games = league_schedule.getGamesSchedule().at(i);
        for(Game *game : games)
        {
            points += game->getHomeScore() + game->getAwayScore();
        }
        if (points > max)
        {
            max = points;
            round = i;
        }
    }

    cout << "Round " << round << " had the most points with " << max << " Points Scored." << endl;
}

void League::getTeamResults(Team *team){
    for (unsigned int i = 0; i < league_schedule.getGamesSchedule().size(); i++)
    {
        auto games = league_schedule.getGamesSchedule().at(i);
        for(Game *game : games)
        {
            if (game->getHome() == team)
            {
                cout << "Round " << i << ": "<< "\033[1;32m" << game->getHome()->getName() << " " << game->getHomeScore() <<"\033[0m"<< " - " << game->getAwayScore() << " " << game->getAway()->getName() << endl;
            }

            else if (game->getAway() == team)
            {
                cout << "Round " << i << ": " << game->getHome()->getName() << " " << game->getHomeScore() << " - " << "\033[1;32m" << game->getAwayScore()<< " " << game->getAway()->getName() << "\033[0m"  << endl;
        }
    }
}
};

void League::getTeamRoundResults(Team *team, unsigned int round)
{
    auto games = league_schedule.getGamesSchedule().at(round);
    for(Game *game : games)
    {
             if (game->getHome() == team)
            {
                cout << "Round " << round << ": "<< "\033[1;32m" << game->getHome()->getName() << " " << game->getHomeScore() <<"\033[0m"<< " - " << game->getAwayScore() << " " << game->getAway()->getName() << endl;
            }

            else if (game->getAway() == team)
            {
                cout << "Round " << round << ": " << game->getHome()->getName() << " " << game->getHomeScore() << " - " << "\033[1;32m" << game->getAwayScore()<< " " << game->getAway()->getName() << "\033[0m"  << endl;
        }
    }
}

void League::printLeague(){
    cout << "League: " << "NBB" << endl;
    cout << "Teams: " << endl;
    for_each(league_teams.begin(), league_teams.end(), [](Team *team)
    {
        cout << team->getName() << endl;
    });
    cout << "Schedule: " << endl;
    league_schedule.printSchedule();
}

   void League::printTeam(Team *team){
    cout << "Team: " << team->getName() << endl;
    cout << "Wins: " << team->getWins() << endl;
    cout << "Losses: " << team->getLosses() << endl;
    cout << "Points For: " << team->getPointsFor() << endl;
    cout << "Points Against: " << team->getPointsAgainst() << endl;
    cout << "Wins in a Row: " << team->getWinsInARow() << endl;
    cout << "Losses in a Row: " << team->getLossesInARow() << endl;
}

void League::printSchedule(){
    league_schedule.printSchedule();
}