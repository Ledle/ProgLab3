#pragma once
#include "user.h"
class discipline;
class teacher : public user
{
private:
	discipline** discips = new discipline*;
	int ndiscips=0;
public:
	teacher();
	teacher(string name);
	teacher(int login, int password, string name);
	teacher(int login, int password, string name, discipline* disc);
	void show();
	discipline** getdiscips();
	void adddisc(discipline* disc);
	void deldisc(discipline* disc);
	void input();
	friend ostream& operator<< (std::ostream& out, const teacher& st);
};