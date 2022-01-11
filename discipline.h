#pragma once
#include <string>
#include <iostream>
#include "object.h"
using namespace std;
class test;
class group;
class discipline : object
{
private:
	int ntests, ngroups;
	string name;
	test** tst;
	group** groups;
	static discipline** disciplines;//������ ���� ���������
	static int ndiscips;//���������� ���� ���������
public:
	discipline();
	discipline(string name);
	discipline(string name, group** groups, int ngroups, test** tests, int ntests);
	int addgroup(group* gr);
	int addtest(test* tst);
	string getname();
	void rename(string name);
	void deltest(string name);
	void delgroup(string name);
	void show();
	void input();
	test* gettest(int n);
	int count();
	static discipline** list();//��������� ������ ���������
	static int numberof();//��������� ���������� ���������
	friend ostream& operator<< (std::ostream& out, const discipline& disc);
private:
	void adddisc(discipline*);//��������������� ������� ��� ���������� � ������
};