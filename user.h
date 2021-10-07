#pragma once
#include <string>
#include <iostream>
using namespace std;
class group;
class user
{
private:
	int login, password;
	string name;
	group* grp;
public:
	user();
	user(int login, int password, string name);
	void rename(string name);
	void changepass(int password);
	void changegroup(group* gr);
	void show();
	void input();
	string getname();
	int getlogin();
	group* getgroup();
	~user();
};

