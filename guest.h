#pragma once
#include "student.h"
class guest : public student
{
public:
    guest();
    guest(string name);
    void changegroup(string) = delete;
    void changepass(int) = delete;
    group* getgroup() = delete;
    guest& operator=(student st);
};