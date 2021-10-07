#include "discipline.h"
#include "group.h"
#include "test.h"

discipline::discipline() {
	this->name = "";
	this->groups = new group*;
	this->tst = new test*;
	this->ntests = 0;
	this->ngroups = 0;
}
discipline::discipline(string name) {
	this->name = name;
	this->groups = new group*;
	this->tst = new test*;
	this->ntests = 0;
	this->ngroups = 0;
}
int discipline::addgroup(group* gr) {
	bool f = false;
	int i;
	for (i = 0; i < this->ngroups; i++) {
		if (this->groups[i]->getname() == gr->getname()) {
			f = true;
			break;
		}
	}
	if (f) { return i; }
	group** buf = new group * [this->ngroups + 1];
	memcpy(buf, this->groups, sizeof(group*) * this->ngroups);
	delete this->groups;
	this->groups = buf;
	this->groups[this->ngroups] = gr;
	this->ngroups++;
	gr->adddisc(this);
	return this->ngroups;
}
int discipline::addtest(test* tst) {
	test** buf = new test * [this->ntests + 1];
	memcpy(buf, this->tst, sizeof(test*) * this->ntests);
	delete this->tst;
	this->tst = buf;
	this->tst[this->ntests] = tst;
	this->ntests++;
	return this->ntests;
}
void discipline::rename(string name) {
	this->name = name;
}
void discipline::deltest(string name) {
	int numbertest = -1;
	for (int i = 0; i < this->ntests; i++) {
		if (name == this->tst[i]->getname()) {
			numbertest = i;
			break;
		}
	}
	if (numbertest != -1) {
		this->ntests--;
		for (int i = numbertest; i < this->ntests; i++) {
			this->tst[i] = this->tst[i + 1];
		}
		test** buf = new test * [this->ntests];
		memcpy(buf, this->tst, sizeof(test*) * this->ntests);
		delete this->tst;
		this->tst = buf;
	}
}
void discipline::delgroup(string name) {
	int numbergroup = -1;
	group* g;
	for (int i = 0; i < this->ngroups; i++) {
		if (name == this->groups[i]->getname()) {
			numbergroup = i;
			break;
		}
	}
	if (numbergroup != -1) {
		g = this->groups[numbergroup];
		this->ngroups--;
		for (int i = numbergroup; i < this->ngroups; i++) {
			this->groups[i] = this->groups[i + 1];
		}
		group** buf = new group * [this->ngroups];
		memcpy(buf, this->groups, sizeof(group*) * this->ngroups);
		delete this->groups;
		this->groups = buf;
		g->deldisc(this->name);
	}
}
void discipline::show() {
	printf_s("Discipline %s:\n", this->name.c_str());
	if (this->ngroups > 0) {
		printf_s(" Groups:\n");
		for (int i = 0; i < this->ngroups; i++) {
			printf_s("  %d) %s\n", i, this->groups[i]->getname().c_str());
		}
	}
	if (this->ntests >= 0) {
		printf_s(" Tests: %d\n", this->ntests);
	}
}
void discipline::input() {
	printf_s("Enter name of discipline: ");
	getline(cin, this->name);
}
test* discipline::gettest(int n) {
	return this->tst[n];
}
string discipline::getname() {
	return this->name;
}
discipline::~discipline() {
	if (this->groups != NULL) {
		for (int i = 0; i <= this->ngroups; i++) {
			this->groups[i]->deldisc(this->name);
			delete[] this->groups;
		}
	}
	if (this->tst != NULL) {
		delete[] this->tst;
	}
}