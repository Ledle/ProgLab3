#pragma once
#include "user.h"
class student : public user
{
private:
	group* grp;
public:
	student();
	student(string name);
	student(int login, int password, string name);
	void show();
	group* getgroup();
	void changegroup(group* gr);
	void input();
	friend ostream& operator<< (std::ostream& out, const student &st);
};