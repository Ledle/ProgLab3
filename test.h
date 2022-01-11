#pragma once
#include <string>
#include <iostream>
#include "object.h"
using namespace std;
class question;
class test : object
{
private:
	int nres, nquests, * result;
	string name;
	question* quest;
public:
	test();
	test(string name);
	test(question questions[], int n, string name);
	test(test& src);
	int addresult(int login, int result);
	void rename(string name);
	string getname();
	void show();
	void input();
	question* getquest(int n);
	question& getquest1(int n);
	friend ostream& operator<< (std::ostream& out, const test& t);
};

