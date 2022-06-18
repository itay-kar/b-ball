#include "Team.hpp"

namespace b_ball
{
    string Team::getName()
    {
        return name;
    }

    double Team::getTeamTalent()
    {
        return team_talent;
    }

    void Team::print() const
    {
        cout << "Team: " << name << endl;
        cout << "Team Talent: " << team_talent << endl;
    }

    Team::Team(string name):name(move(name))
    {
        team_talent = 1.00 / rand();
    };

    void Team::updateWins() { wins++; };
    void Team::updatePointsFor(unsigned int points) { points_for += points; };
    void Team::updatePointsAgainst(unsigned int points) { points_against += points; };
    void Team::updateWinStreak()
    {
        loss_streak = 0;
        win_streak += 1;
        if (win_streak > wins_in_a_row)
        {
            wins_in_a_row = win_streak;
        }
    };

    void Team::updateLossStreak()
    {
        win_streak = 0;
        loss_streak += 1;
        if (loss_streak > losses_in_a_row)
        {
            losses_in_a_row = loss_streak;
        }
    };

    unsigned int Team::getWins() const { return wins; };
    unsigned int Team::getLosses() const { return ROUNDS - wins; };
    unsigned int Team::getPointsFor() const { return points_for; };
    unsigned int Team::getPointsAgainst() const { return points_against; };
    unsigned int Team::getWinsInARow() const { return wins_in_a_row; };
    unsigned int Team::getLossesInARow() const { return losses_in_a_row; };
    bool Team::operator==(const Team &other) const
    {
        return name == other.name;
    }
}