#include <iostream>
#include "discipline.h"
#include "test.h"
#include "group.h"
#include "question.h"
#include "user.h"
int main()
{
    discipline* d1 = new discipline("Math");
    discipline* d2 = new discipline("Physic");
    discipline* d3 = new discipline("Programming");
    discipline* d4 = new discipline("Economics");
    group* g1 = new group("PI01");
    group* g2 = new group("PI02");
    group* g3 = new group("PI03");
    group* g4 = new group("PI04");
    cout << "groups:"<<endl;
    for (int i=0;i < group::numberof(); i++)
    {
        group::list()[i]->show();
    }
    cout << "disciplines: "<<endl;
    for (int i = 0; i < discipline::numberof(); i++)
    {
        discipline::list()[i]->show();
    }
}