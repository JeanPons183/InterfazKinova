#ifndef ROBOT_H
#define ROBOT_H


#include "qtmetamacros.h"

class Robot
{
public:
    Robot();

private slots:

    void ForwardKinematic();

    void ChecarSingularidad();
};


#endif // ROBOT_H
