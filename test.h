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
	test(question questions[], int n, string name);
	int addresult(int login, int result);
	void rename(string name);
	string getname();
	void show();
	void input();
	question* getquest(int n);
	test operator+(question	q);
};

