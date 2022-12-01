#include "CompleteTeam.h"

CompleteTeam::CompleteTeam(int teamId, int points, int goals, int cards) :
    m_teamId(teamId),
    m_cards(cards),
    m_goals(goals),
    m_points(points)
{}

bool operator==(const CompleteTeam &ct1, const CompleteTeam &ct2) {
    return ct1.m_teamId == ct2.m_teamId;
}

bool operator<(const CompleteTeam &ct1, const CompleteTeam &ct2) {
    return ct1.m_teamId < ct2.m_teamId;
}

bool operator> (const CompleteTeam &ct1, const CompleteTeam &ct2){
    return ct2 < ct1;
}

bool operator!= (const CompleteTeam &ct1, const CompleteTeam &ct2){
    return !(ct1==ct2);
}

bool operator<=(const CompleteTeam &ct1, const CompleteTeam &ct2){
    return ct1 < ct2 || ct1 == ct2;
}

bool operator>=(const CompleteTeam &ct1, const CompleteTeam &ct2){
    return ct2 <= ct1;
}