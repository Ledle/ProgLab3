#pragma once
#include <string>
using namespace std;
class test;
class question;
class group;
class discipline {
private:
	int ntests,ngroups;
	string name;
	test** tst;
	group** groups;
public:
	discipline();
	discipline(const char* name);
	int addgroup(group* gr);
	int addtest(test* tst);
	string getname();
	void rename(const char* name);
	void deltest(int numbertest);
	void delgroup(int numbergroup);
	void show();
	void input();
};
class question {
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
class test {
private:
	int nres, nquests, * result;
	string name;
	question* quest;
	discipline* discip;
public:
	test();
	test(question questions[], discipline* disc, int n, const char* name);
	int addresult(int login, int result);
	void rename(const char* name);
	string getname();
	void show();
	void input();
};
class user {
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

};
class group {
private:
	user** students;
	discipline** disciplines;
	int nstudents, ndiscips;
	string name;
public:
	group();
	group(string name);
	void adddisc(discipline* disc);
	void adduser(user* student);
	void rename(string name);
	void deldisc(int numberdiscip);
	void delstudent(int numberuser);
	void show();
	void input();
	string getname();
};