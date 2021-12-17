#pragma once
#include <string>
#include <iostream>
#include "discipline.h"
using namespace std;
class user;
class discipline;
class group
{
private:
	user** students;
	discipline** disciplines;
	int nstudents, ndiscips;
	string name;
	static int ngroups;//количество групп
	static group** groups;//список всех групп
public:
	group();
	group(string name);
	group(string name, user** students,int nstudents,discipline** disciplines, int ndiscips);
	int adddisc(discipline* disc);
	int adduser(user* student);
	void rename(string name);
	void deldisc(string name);
	void delstudent(int login);
	void show();
	void input();
	string getname();
	user* getstudent(int n);
	friend int discipline::count();
	static group** list();//получение списка групп
	static int numberof();//получение количества групп
private:
	void addgroup(group*);//вспомогательная функция для добавления в список
};