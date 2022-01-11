#include <iostream>
#include "discipline.h"
#include "test.h"
#include "group.h"
#include "question.h"
#include "user.h"
int main()
{
	discipline* discips[2][2];
    discips[0][0] = new discipline("Math");
    discips[0][1] = new discipline("Physics");
    discips[1][0] = new discipline("English");
    discips[1][1] = new discipline("Philosophy");
    group* groups[2];
    groups[0] = new group("PS");
    groups[1] = new group("PI");
    user* users[2][3];
    users[0][0] = new user(00,00,"Andrey");
    users[0][1] = new user(01,01,"Sergey");
    users[0][2] = new user(02,02,"Ivan");
    users[1][0] = new user(10,10,"John");
    users[1][1] = new user(11,11,"Marty");
    users[1][2] = new user(12,12,"Kyle");
    question* questions[16];
    string quest, answer;
    for (int i = 0; i < 16; i++)
    {
        quest = to_string(i) + "+" + to_string(i * 2);
        answer = to_string(i + i * 2);
        questions[i] = new question(quest, answer, i + 5);
    }
    test* tests[2];
    question quests[8];
    for (int i = 0; i < 2; i++)
    {
        for (int j = 0; j < 8; j++)
        {
            quests[j] = *questions[j + 8 * i];
        }
        tests[i] = new test(quests,8, "Test #" + to_string(i + 1));
    }
    for (int i = 0; i < 2; i++)
    {
        for (int j = 0; j < 3; j++)
        {
            groups[i]->adduser(users[i][j]);
        }
        for (int j = 0; j < 2; j++)
        {
            groups[i]->adddisc(discips[i][j]);
        }
    }
    groups[0]->show();
    groups[1]->show();
}