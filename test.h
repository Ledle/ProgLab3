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
	test& operator= (const test &src);
};

