#pragma once
#include <string>
#include <iostream>
using namespace std;
class question;
class test
{
private:
	int nres, nquests, * result;
	string name;
	question* quest;
public:
	test();
	test(question questions[], int n, const char* name);
	int addresult(int login, int result);
	void rename(const char* name);
	string getname();
	void show();
	void input();
	question* getquest(int n);
};

