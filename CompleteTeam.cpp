#include "CompleteTeam.h"

CompleteTeam::CompleteTeam(int teamId, int points, int goals, int cards) :
    m_teamId(teamId),
    m_cards(cards),
    m_goals(goals),
    m_points(points)
{}

CompleteTeam::CompleteTeam(const Team &team)
{
    m_teamId = team.getId();
    m_points = team.getPoints();
    m_goals = team.getGoals();
    m_cards = team.getCards();
}