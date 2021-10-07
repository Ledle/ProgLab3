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
	discipline(string name);
	int addgroup(group* gr);
	int addtest(test* tst);
	string getname();
	void rename(string name);
	void deltest(string name);
	void delgroup(string name);
	void show();
	void input();
	test* gettest(int n);
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
	group* getgroup();
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
	int adddisc(discipline* disc);
	int adduser(user* student);
	void rename(string name);
	void deldisc(string name);
	void delstudent(int login);
	void show();
	void input();
	string getname();
	user* getstudent(int n);
};

question* qsts(int n, question a, ...);