#pragma once
#include <string>
#include <iostream>
#include "object.h"
using namespace std;
class group;
class user : object
{
protected:
	int login, password;
	string name;
public:
	user();
	user(string name);
	user(int login, int password, string name);
	void rename(string name);
	void changepass(int password);
	void show();
	void input();
	string getname();
	int getlogin();
	int getpass();
};