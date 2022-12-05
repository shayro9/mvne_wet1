#include "CompleteTeam.h"

CompleteTeam::CompleteTeam(int teamId, int points, int goals, int cards) :
    m_teamId(teamId),
    m_points(points),
    m_goals(goals),
    m_cards(cards),
    m_completeNode(nullptr)
{}

bool operator==(const CompleteTeam &ct1, const CompleteTeam &ct2) {
    return ct1.m_teamId == ct2.m_teamId;
}

bool operator<(const CompleteTeam &ct1, const CompleteTeam &ct2) {
    return ct1.m_teamId < ct2.m_teamId;
}

LNode<CompleteTeam> *CompleteTeam::getCompleteNode() const {
    return m_completeNode;
}

int CompleteTeam::getScore() const {
    return m_points + m_goals - m_cards;
}

void CompleteTeam::addPoints(int amount) {
    m_points += amount;

}

int CompleteTeam::getId() const {
    return m_teamId;
}

int CompleteTeam::getPoints() const {
    return m_points;
}

void CompleteTeam::setCompleteTeamNode(LNode<CompleteTeam> *node) {
    m_completeNode = node;
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
