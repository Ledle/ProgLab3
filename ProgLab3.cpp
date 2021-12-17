#include <iostream>
#include "discipline.h"
#include "test.h"
#include "group.h"
#include "question.h"
#include "user.h"
int main()
{
    question* q0 = new question();
    question* q1 = new question("2+20");
    question* qall = new question("2+2", "4", 15);
    question qs[3] = {question("First"),question("Second"),question("Third") };
    test* t0 = new test();
    test* t1 = new test("NameOnly");
    test* tall = new test(qs,3, "AllParms");
    test* tsts[3] = { t0, t1, tall };
    user* u0 = new user();
    user* u1 = new user("Bob");
    user* uall = new user(836, 444, "John");
    user* usrs[] = { u0, u1, uall };
    discipline* d0 = new discipline();
    discipline* d1 = new discipline("JustName");
    discipline* dscps[2] = { d0, d1 };
    group* g0 = new group();
    group* g1 = new group("OnlyName");
    group* gall = new group("AllParms",usrs,3,dscps,2);
    group* groups[3] = { g0, g1, gall };
    discipline* dall = new discipline("AllParms",groups,3, tsts, 3);
    static question* sq0 = new question();
    static question* sq1 = new question("2+20");
    static question* sqall = new question("2+2", "4", 15);
    question sqs[3] = { question("First"),question("Second"),question("Third") };
    static test* st0 = new test();
    static test* st1 = new test("NameOnly");
    static test* stall = new test(sqs, 3, "AllParms");
    test* ststs[3] = { st0, st1, stall };
    static user* su0 = new user();
    static user* su1 = new user("Bob");
    static user* suall = new user(836, 444, "John");
    user* susrs[] = { su0, su1, suall };
    static discipline* sd0 = new discipline();
    static discipline* sd1 = new discipline("JustName");
    discipline* sdscps[2] = { sd0, sd1 };
    static group* sg0 = new group();
    static group* sg1 = new group("OnlyName");
    static group* sgall = new group("AllParms",susrs,3,sdscps,2);
    group* sgroups[3] = { sg0, sg1, sgall };
    static discipline* sdall = new discipline("AllParms", sgroups, 3, tsts, 3);
    test tclone = *tall;
    test* tcopy = new test("copy");
    *tcopy = *tall;
    tall->getquest(0)->change("Not", "Copy", 543);
    tclone.show();
    tcopy->show();
}