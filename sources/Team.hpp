#pragma once
#include <string>
#include <iostream>
using namespace std;

const int MAX_TEAMS = 20;
const int ROUNDS = 38;

namespace b_ball
{
    class Team
    {
    public:
        Team(string name);
        string getName();
        bool operator==(const Team &other) const;
        double getTeamTalent();
        void print() const;
        void updateWins();
        void updateWinStreak();
        void updateLossStreak();
        void updatePointsFor(unsigned int points);
        void updatePointsAgainst(unsigned int points);
        unsigned int getWins() const;
        unsigned int getLosses() const;
        unsigned int getPointsFor() const;
        unsigned int getPointsAgainst() const;
        unsigned int getWinsInARow() const;
        unsigned int getLossesInARow() const;

    private:
        string name;
        double team_talent=0;
        unsigned int wins=0;
        unsigned int points_for=0;
        unsigned int points_against=0;
        unsigned int win_streak=0;
        unsigned int loss_streak=0;
        unsigned int wins_in_a_row=0;
        unsigned int losses_in_a_row=0;
    };
}