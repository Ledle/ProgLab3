#pragma once
class test;
class question;
class group;
class discipline {
private:
	int ntests,ngroups;
	char* name;
	test** tst;
	group** groups;
public:
	discipline();
	discipline(const char* name);
	int addgroup(group* gr);
	int addtest(test* tst);
	void rename(const char* name);
	void deltest(int numbertest);
	void delgroup(int numbergroup);
	void show();
};
class question {
private:
	char* text, * answer;
	int value;
public:
	question();//ввод в консоль
	question(const char* text, const char* answer, int value);
	void change(const char* text, const char* answer, int value);
	void show();
};
class test {
private:
	int nres, nquests, * result;
	char* name;
	question quest;
	discipline discip;
public:
	test();//ввод в консоль
	test(question questions[], discipline* disc, int n, const char* name);
	int addresult(int login, int result);
	void rename(const char* name);
	void show();
};
class user {
private:
	int login, password;
	char* name;
	group* grp;
public:
	user();//ввод в консоль
	user(int login, int password, const char* name);
	void rename(const char* name);
	void changepass(int password);
	void changegroup(group* gr);
	void show();
};
class group {
private:
	user** students;
	discipline** disciplines;
	int nstudents, ndiscips;
	char* name;
public:
	group();
	group(const char* name);
	void adddisc(discipline* disc);
	void adduser(user* student);
	void rename(const char* name);
	void deldisc(int numberdiscip);
	void delstudent(int numberuser);
	void show();
};