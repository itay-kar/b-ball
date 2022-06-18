#pragma once
#include <time.h>
#include <random>
using namespace std;

#include "Team.hpp"

const int HOME_SCORE = 55;
const int BASE_SCORE = 50;
const int MAX_SCORE = 100;
const int Factor = 10;
namespace b_ball
{
    static double calcMean(double low, double high)
    {
        return (low + high) / 2;
    };

    static double calcDev(int low, int high)
    {
        double dev = 0;
        double sum = 0;
        double mean = calcMean(low, high);
        // cout << "Mean : " << mean << endl;
        for (int i = low; i <= high; i++)
        {
            sum += pow(i - mean, 2);
        }
        // cout << "Dev : " << sqrt(sum / (high - low + 1)) << endl;
        return sqrt(sum / (high - low + 1));
    };

    class Team;
    static random_device r;
    static default_random_engine gen(r());
    static normal_distribution<double> away_points(calcMean(BASE_SCORE, MAX_SCORE), calcDev(BASE_SCORE, MAX_SCORE));
    static normal_distribution<double> home_points(calcMean(HOME_SCORE, MAX_SCORE), calcDev(HOME_SCORE, MAX_SCORE));
    
    class Game
    {
    private:
        Team *home;
        Team *away;
        Team* winner = nullptr;
        unsigned int homeScore = 0;
        unsigned int awayScore = 0;

    public:
        Game(Team *home, Team *away);
        Team *getHome();
        Team *getAway();
        void startGame();
        unsigned int getHomeScore() const;
        unsigned int getAwayScore() const;
        void print() const;
        Team* getWinner();
    };
};