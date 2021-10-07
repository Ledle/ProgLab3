#pragma once
#include <string>
#include <iostream>
using namespace std;
class test;
class group;
class discipline
{
private:
	int ntests, ngroups;
	string name;
	test** tst;
	group** groups;
public:
	discipline();
	discipline(string name);
	int addgroup(group* gr);
	int addtest(test* tst);
	string getname();
	void rename(string name);
	void deltest(string name);
	void delgroup(string name);
	void show();
	void input();
	test* gettest(int n);
	~discipline();
};