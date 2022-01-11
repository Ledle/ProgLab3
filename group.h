#pragma once
#include <string>
#include <iostream>
#include "discipline.h"
using namespace std;
class student;
class discipline;
class group : object
{
private:
	student** students;
	discipline** disciplines;
	int nstudents, ndiscips;
	string name;
	static int ngroups;//���������� �����
	static group** groups;//������ ���� �����
public:
	group();
	group(string name);
	group(string name, student** students,int nstudents,discipline** disciplines, int ndiscips);
	int adddisc(discipline* disc);
	int adduser(student* student);
	void rename(string name);
	void deldisc(string name);
	void delstudent(int login);
	void show();
	void input();
	string getname();
	student* getstudent(int n);
	friend int discipline::count();
	static group** list();//��������� ������ �����
	static int numberof();//��������� ���������� �����
	friend ostream& operator<< (std::ostream& out, const group& gr);
private:
	void addgroup(group*);//��������������� ������� ��� ���������� � ������
};