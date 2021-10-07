#pragma once
#include <string>
#include <iostream>
using namespace std;
class user;
class discipline;
class group
{
private:
	user** students;
	discipline** disciplines;
	int nstudents, ndiscips;
	string name;
public:
	group();
	group(string name);
	int adddisc(discipline* disc);
	int adduser(user* student);
	void rename(string name);
	void deldisc(string name);
	void delstudent(int login);
	void show();
	void input();
	string getname();
	user* getstudent(int n);
	~group();
};

