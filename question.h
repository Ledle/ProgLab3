#pragma once
#include <string>
#include <iostream>
using namespace std;
class question
{
private:
	string text, answer;
	int value;
public:
	question();
	question(string text, string answer, int value);
	void change(string text, string answer, int value);
	string gettext();
	string getanswer();
	int getvalue();
	void show();
	void input();
};

question* qsts(int n, question a, ...);