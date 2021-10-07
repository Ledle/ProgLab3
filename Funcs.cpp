#include <iostream>
#include <string>
#include "Header.h"
using namespace std;

question* qsts(int n, question a, ...) {
	question* q = new question[n];
	question* src = &a;
	memcpy(q, src, sizeof(question) * n);
	return q;
}

question::question() {
	this->text = "";
	this->answer = "";
	this->value = 0;
}
question::question(string text, string answer, int value) {
	this->text = text;
	this->answer = answer;
	this->value = value;
}
void question::input() {
	cout << "Enter question: ";
	getline(cin, this->text);
	cout << "Enter answer: ";
	getline(cin, this->answer);
	cout << "Enter number of points: ";
	cin >> this->value;
	while (getchar() != '\n');
}
void question::change(string text, string answer, int value) {
	this->text = text;
	this->answer = answer;
	this->value = value;
}
void question::show() {
	cout << "Text: " << this->text << endl;
	cout << "Answer: " << this->answer;
	cout << "(" << this->value << " balls)"<< endl;
}
string question::gettext() {
	return this->text;
}
string question::getanswer() {
	return this->answer;
}
int question::getvalue() {
	return this->value;
}

test::test() {
	this->name = "";
	this->quest;
	this->nquests = 0;
	this->result = new int[1];
	this->nres = 0;
}
test::test(question questions[], int n, const char* name) {
	this->name = name;
	this->quest = new question [n];
	memcpy(this->quest, questions, sizeof(question) * n);
	this->nquests = n;
	this->result = new int[1];
	this->nres = 0;
}
void test::rename(const char * name) {
	this->name = name;
}
int test::addresult(int login, int result){
	int* buf = new int[this->nres*2 + 2];
	memcpy(buf, this->result, sizeof(int)*(this->nres)*2);
	buf[this->nres * 2] = login;
	buf[this->nres * 2 + 1] = result;
	this->nres++;
	delete [] this->result;
	this->result = buf;
	return this->nres-1;
}
string test::getname() {
	return this->name;
}
void test::show() {
	printf_s("Test %s", this->name.c_str());
	putchar('\n');
	if (this->nquests > 0) {
		printf_s(" Questions:\n");
		for (int i = 0; i < this->nquests; i++) {
			printf_s("  %d)Question: %s\n   Answer: %s(%d points)\n", i, (this->quest[i].gettext()).c_str(), (this->quest[i].getanswer()).c_str(), this->quest[i].getvalue());
		}
	}
	if (this->nres > 0) {
		printf_s(" Results:\n");
		for (int i = 0; i < this->nres; i++) {
			printf_s("  %d) Login: %d Result: %d\n", i, this->result[i * 2], this->result[i * 2 + 1]);
		}
	}
}
void test::input() {
	printf_s("Enter name of test: ");
	getline(cin, this->name);
	printf_s("Enter number of questions: ");
	scanf_s("%d", &this->nquests);
	while (getchar() != '\n');
	if (this->quest != NULL) {
		delete this->quest;
	}
	this->quest = new question[this->nquests];
	for (int i = 0; i < this->nquests; i++) {
		this->quest[i].input();
	}
}
question* test::getquest(int n) {
	return this->quest+n;
}

user::user() {
	this->name = "";
	this->login = 0;
	this->password = 0;
	this->grp = NULL;
}
user::user(int login, int password,string name) {
	this->name = name;
	this->login = login;
	this->password = password;
	this->grp = NULL;
}
void user::rename(string name) {
	this->name = name;
}
void user::changepass(int password) {
	this->password = password;
}
void user::changegroup(group* gr) {
	group* g;
	if (this->grp != gr) {
		g = this->grp;
		this->grp = gr;
		if (gr != NULL) {
			gr->adduser(this);
		}
		if (g != NULL) { 
			g->delstudent(this->login);
		}
	}
}
void user::show() {
	printf_s("User %s:\n", this->name.c_str());
	if (this->grp != NULL) {
		printf_s(" Group: %s\n", this->grp->getname().c_str());
	}
	printf_s(" Login: %d Password: %d\n", this->login, this->password);
}
void user::input() {
	printf_s("Enter name of student: ");
	getline(cin, this->name);
	printf_s("Enter login: ");
	scanf_s("%d", &login);
	while (getchar() != '\n');
	printf_s("Enter password: ");
	scanf_s("%d", &password);
	while (getchar() != '\n');
}
string user::getname() {
	return this->name;
}
int user::getlogin() {
	return this->login;
}
group* user::getgroup() {
	return this->grp;
}

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
	discipline** buf = new  discipline*[this->ndiscips + 1];
	memcpy(buf, this->disciplines, sizeof(discipline*)*(this->ndiscips));
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
	student->changegroup(this);
	return this->nstudents - 1;
}
void group::rename(string name) {
	this->name = name;
}
void group::deldisc(string name) {
	discipline* d;
	int numberdiscip=-1;
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
	int numberuser=-1;
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
		memcpy(buf, this->students, sizeof(user*)*this->nstudents);
		delete [] this->students;
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