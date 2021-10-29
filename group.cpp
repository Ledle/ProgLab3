#include "group.h"
#include "discipline.h"
#include "user.h"

group::group() {
	this->name = "";
	this->disciplines = new discipline*;
	this->students = new user*;
	this->ndiscips = 0;
	this->nstudents = 0;
}
group::group(string name) {
	this->name = name;
	this->disciplines = new discipline*;
	this->students = new user*;
	this->ndiscips = 0;
	this->nstudents = 0;
}
int group::adddisc(discipline* disc) {
	bool f = false;
	int i;
	for (i = 0; i < this->ndiscips; i++) {
		if (this->disciplines[i]->getname() == disc->getname()) {
			f = true;
			break;
		}
	}
	if (f) { return i; }
	discipline** buf = new  discipline * [this->ndiscips + 1];
	memcpy(buf, this->disciplines, sizeof(discipline*) * (this->ndiscips));
	buf[this->ndiscips] = disc;
	delete this->disciplines;
	this->disciplines = buf;
	this->ndiscips++;
	disc->addgroup(this);
	return this->ndiscips - 1;
}
int group::adduser(user* student) {
	bool f = false;
	int i;
	for (i = 0; i < this->nstudents; i++) {
		if (this->students[i]->getlogin() == student->getlogin()) {
			f = true;
			break;
		}
	}
	if (f) { return i; }
	user** buf = new  user * [this->nstudents + 1];
	memcpy(buf, this->students, sizeof(user*) * (this->nstudents));
	buf[this->nstudents] = student;
	delete this->students;
	this->students = buf;
	this->nstudents++;
	student->changegroup(this);//разумное использование this
	return this->nstudents - 1;
}
void group::rename(string name) {
	this->name = name;
}
void group::deldisc(string name) {
	discipline* d;
	int numberdiscip = -1;
	for (int i = 0; i < this->ndiscips; i++) {
		if (name == this->disciplines[i]->getname()) {
			numberdiscip = i;
			break;
		}
	}
	if (numberdiscip != -1) {
		d = this->disciplines[numberdiscip];
		this->ndiscips--;
		for (int i = numberdiscip; i < this->ndiscips; i++) {
			this->disciplines[i] = this->disciplines[i + 1];
		}
		discipline** buf = new discipline * [this->ndiscips];
		memcpy(buf, this->disciplines, sizeof(discipline*) * this->ndiscips);
		d->delgroup(this->name);
		delete this->disciplines;
		this->disciplines = buf;
	}
}
void group::delstudent(int login) {
	int numberuser = -1;
	for (int i = 0; i < this->nstudents; i++) {
		if (this->students[i]->getlogin() == login) {
			numberuser = i;
			break;
		}
	}
	if (numberuser != -1) {
		this->students[numberuser]->changegroup(NULL);
		this->nstudents--;
		for (int i = numberuser; i < this->nstudents; i++) {
			this->students[i] = this->students[i + 1];
		}
		user** buf = new user * [this->nstudents];
		memcpy(buf, this->students, sizeof(user*) * this->nstudents);
		delete[] this->students;
		this->students = buf;
	}
}
void group::show() {
	printf_s("Group %s:\n", this->name.c_str());
	if (this->nstudents > 0) {
		for (int i = 0; i < this->nstudents; i++) {
			printf_s(" %d) Name: %s Login: %d\n", i, this->students[i]->getname().c_str(), this->students[i]->getlogin());
		}
	}
	if (this->ndiscips > 0) {
		printf_s(" Disciplines:\n");
		for (int i = 0; i < this->ndiscips; i++) {
			printf_s("  %d) Discipline: %s\n", i, this->disciplines[i]->getname().c_str());
		}
	}
}
void group::input() {
	printf_s("Enter name of group: ");
	getline(cin, this->name);
	printf_s("Enter number of students: ");
	scanf_s("%d", &(this->nstudents));
	while (getchar() != '\n');
	this->students = new user * [this->nstudents];
	for (int i = 0; i < this->nstudents; i++) {
		this->students[i] = new user;
		this->students[i]->input();
	}
}
string group::getname() {
	return this->name;
}
user* group::getstudent(int n) {
	if (n >= this->nstudents) {
		return NULL;
	}
	return this->students[n];
}
