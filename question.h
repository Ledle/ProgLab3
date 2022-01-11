#pragma once
#include <string>
#include <iostream>
#include "object.h"
using namespace std;
class question : object
{
private:
	string text, answer;
	int value;
public:
	question();
	question(string text);
	question(string text, string answer, int value);
	void change(string text, string answer, int value);
	string gettext();
	string getanswer();
	int getvalue();
	void show();
	void input();
	question operator+(int n);
	question operator++(int);
	question operator++();
	friend ostream& operator<< (std::ostream& out, const question& q);
};

question* qsts(int n, question a, ...);