#include "Game.hpp"

namespace b_ball
{
    Game::Game(Team *home, Team *away) : home(home), away(away){};
    Team *Game::getHome()
    {
        return home;
    }
    Team *Game::getAway()
    {
        return away;
    }
    unsigned int Game::getHomeScore() const
    {
        return homeScore;
    }

    void Game::startGame()
    {
        awayScore = (unsigned int)away_points(gen) + (unsigned int)(away->getTeamTalent() * Factor);
        homeScore = (unsigned int)home_points(gen) + (unsigned int)(home->getTeamTalent() * Factor);
        home->updatePointsFor(homeScore);
        away->updatePointsFor(awayScore);
        home->updatePointsAgainst(awayScore);
        away->updatePointsAgainst(homeScore);

        if (!(awayScore == homeScore))
        {
            winner = (homeScore > awayScore) ? home : away;
        }

        else
        {
            unsigned int x = homeScore - (unsigned int)(home->getTeamTalent());
            unsigned int y = awayScore - (unsigned int)(away->getTeamTalent());
            winner = (x > y) ? home : away;
        }

        if (winner == nullptr)
        {
            winner = home;
        }

        winner->updateWins();
        winner->updateWinStreak();
        if (winner == home)
        {
            away->updateLossStreak();
        }
        else
        {
            home->updateLossStreak();
        }
    }

    unsigned int Game::getAwayScore() const
    {
        return awayScore;
    };

    void Game::print() const
    {
        string Winner;
        if (homeScore == 0)
        {
            Winner = "Game not started yet";
        }
        else if (homeScore > awayScore)
        {
            Winner = home->getName();
        }

        else
        {
            Winner = away->getName();
        }

        cout << "Game: "
             << "\033[1;32m" << home->getName() << "\033[0m"
             << " vs "
             << "\033[0;31m" << away->getName() << "\033[0m" << endl;
        // cout << "Date: " << date.tm_mday << "/" << date.tm_mon << "/" << date.tm_year << endl;
        cout << "Home Score: "
             << "\033[0;32m" << homeScore << "\033[0m" << endl;
        cout << "Away Score: "
             << "\033[0;31m" << awayScore << "\033[0m" << endl;
        cout << "Winner = " << Winner << endl;
    };

    Team *Game::getWinner() { return winner; };
} // namespace b_ball
