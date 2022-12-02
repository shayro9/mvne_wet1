#ifndef MVNE_WET1_COMPLETETEAM_H
#define MVNE_WET1_COMPLETETEAM_H

//#include "Team.h"
//#include "List.h"
#include "PlayerRank.h"

class CompleteTeam {
public:
    CompleteTeam(int teamId, int points=0, int goals=0, int cards=0);

    CompleteTeam() = default;
    ~CompleteTeam() = default;
    CompleteTeam(const CompleteTeam& t)=default;
    CompleteTeam& operator=(const CompleteTeam& t)=default;
    LNode<CompleteTeam*>* getCompleteNode() const;

    void addPoints(int amount);

    friend bool operator== (const CompleteTeam&, const CompleteTeam&);
    friend bool operator< (const CompleteTeam&, const CompleteTeam&);

private:
    int m_teamId;
    int m_points;
    int m_goals;
    int m_cards;
    LNode<CompleteTeam*>* m_completeNode;

};

bool operator!= (const CompleteTeam&, const CompleteTeam&);
bool operator>= (const CompleteTeam&, const CompleteTeam&);
bool operator> (const CompleteTeam&, const CompleteTeam&);
bool operator<= (const CompleteTeam&, const CompleteTeam&);

#endif //MVNE_WET1_COMPLETETEAM_H