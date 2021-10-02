#include <iostream>
#include <string>
#include "Header.h"
using namespace std;
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
	this->discip = NULL;
	this->quest;
	this->nquests = 0;
	this->result = new int;
	this->nres = 0;
}
test::test(question questions[], discipline* disc, int n, const char* name) {
	this->name = name;
	this->quest = new question [n];
	memcpy(this->quest, questions, sizeof(question) * n);
	this->nquests = n;
	this->discip = disc;
	this->result = NULL;
	this->nres = 0;
}
void test::rename(const char * name) {
	this->name = name;
}
int test::addresult(int login, int result){
	int* buf = new int[this->nres*2 + 2];
	memcpy(buf, this->result, this->nres*2);
	buf[this->nres * 2] = login;
	buf[this->nres * 2 + 1] = result;
	this->nres++;
	delete this->result;
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
	this->grp = gr;
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

group::group() {
	this->name = "";
	this->disciplines = NULL;
	this->students = NULL;
	this->ndiscips = 0;
	this->nstudents = 0;
}
group::group(string name) {
	this->name = name;
	this->disciplines = NULL;
	this->students = NULL;
	this->ndiscips = 0;
	this->nstudents = 0;
}
void group::adddisc(discipline* disc) {
	discipline** buf = new  discipline* [this->ndiscips + 1];
	memcpy(buf, this->disciplines, sizeof(discipline)*(this->ndiscips));
	buf[this->ndiscips] = disc;
	delete this->disciplines;
	this->disciplines = buf;
	this->ndiscips++;
}
void group::adduser(user* student) {
	user** buf = new  user * [this->nstudents + 1];
	memcpy(buf, this->students, sizeof(user) * (this->nstudents));
	buf[this->nstudents] = student;
	delete this->students;
	this->students = buf;
	this->nstudents++;
}
void group::rename(string name) {
	this->name = name;
}
void group::deldisc(int numberdiscip) {
	this->ndiscips--;
	for (int i = numberdiscip; i < this->ndiscips; i++) {
		this->disciplines[i] = this->disciplines[i + 1];
	}
	discipline** buf = new discipline* [this->ndiscips];
	memcpy(buf, this->disciplines, this->ndiscips);
	delete this->disciplines;
	this->disciplines = buf;
}
void group::delstudent(int numberuser) {
	this->nstudents--;
	for (int i = numberuser; i < this->nstudents; i++) {
		this->students[i] = this->students[i + 1];
	}
	user** buf = new user * [this->nstudents];
	memcpy(buf, this->students, this->nstudents);
	delete this->students;
	this->students = buf;
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
	scanf_s("%d", this->nstudents);
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