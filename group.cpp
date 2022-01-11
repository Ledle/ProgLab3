#include "group.h"
#include "discipline.h"
#include "student.h"
int group::ngroups = 0;
group** group::groups = new group*;
group::group() {//конструктор без параметров
	this->name = "";
	this->disciplines = new discipline*;
	this->students = new student*;
	this->ndiscips = 0;
	this->nstudents = 0;
	addgroup(this);
}
group::group(string name) {//конструктор с одним параметром
	this->name = name;
	this->disciplines = new discipline*;
	this->students = new student*;
	this->ndiscips = 0;
	this->nstudents = 0;
	addgroup(this);
}
group::group(string name, student** students, int nstudents, discipline** disciplines, int ndiscips) {//конструктор со всеми параметрами
	this->name = name;
	this->disciplines = new discipline*[ndiscips];
	this->students = new student*[nstudents];
	this->ndiscips = ndiscips;
	this->nstudents = nstudents;
	addgroup(this);
}
int group::adddisc(discipline* disc) {
	if (disc == NULL) {
		throw invalid_argument("Ссылка не должна быть нулевой");
	}
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
int group::adduser(student* stnt) {
	bool f = false;
	int i;
	for (i = 0; i < this->nstudents; i++) {
		if (this->students[i]->getlogin() == stnt->getlogin()) {
			f = true;
			break;
		}
	}
	if (f) { return i; }
	student** buf = new student * [this->nstudents + 1];
	memcpy(buf, this->students, sizeof(student*) * (this->nstudents));
	buf[this->nstudents] = stnt;
	delete this->students;
	this->students = buf;
	this->nstudents++;
	stnt->changegroup(this);//разумное использование this
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
		student** buf = new student * [this->nstudents];
		memcpy(buf, this->students, sizeof(student*) * this->nstudents);
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
	this->students = new student * [this->nstudents];
	for (int i = 0; i < this->nstudents; i++) {
		this->students[i] = new student;
		this->students[i]->input();
	}
}
string group::getname() {
	return this->name;
}
student* group::getstudent(int n) {
	if (n >= this->nstudents) {
		return NULL;
	}
	return this->students[n];
}
int group::numberof() {
	return ngroups;
}
group** group::list() {
	return groups;
}
void group::addgroup(group* disc) {
	if (disc == NULL) {
		throw invalid_argument("Ссылка не должна быть нулевой");
	}
	group** buf = new group * [ngroups];
	memcpy(buf, groups, sizeof(group*) * ngroups);
	ngroups++;
	groups = new group * [ngroups];
	memcpy(groups, buf, sizeof(group*) * ngroups);
	groups[ngroups - 1] = disc;
}
ostream& operator<< (std::ostream& out, const group& gr) {
	out << "Group "<<gr.name<<":\n";
	if (gr.nstudents > 0) {
		for (int i = 0; i < gr.nstudents; i++) {
			out << " "<<i<<") Name:  "<<gr.students[i]->getname()<<" Login: "<<gr.students[i]->getlogin()<<"\n";
		}
	}
	if (gr.ndiscips > 0) {
		out << " Disciplines:\n";
		for (int i = 0; i < gr.ndiscips; i++) {
			out << "  "<<i<<") Discipline: "<<gr.disciplines[i]->getname()<<"\n";
		}
	}
	return out;
}