#include "discipline.h"
#include "group.h"
#include "test.h"
int discipline::ndiscips = 0;
discipline** discipline::disciplines = new discipline*;
discipline::discipline() {//??????????? ??? ??????????
	this->name = "";
	this->groups = new group*;
	this->tst = new test*;
	this->ntests = 0;
	this->ngroups = 0;
	adddisc(this);
}
discipline::discipline(string name) {//??????????? ? ????? ??????????
	this->name = name;
	this->groups = new group*;
	this->tst = new test*;
	this->ntests = 0;
	this->ngroups = 0;
	adddisc(this);
}
discipline::discipline(string name, group** groups, int ngroups, test** tests, int ntests) {//??????????? ?? ????? ???????????
	this->name = name;
	this->groups = new group*[ngroups];
	this->tst = new test*[ntests];
	this->ntests = ntests;
	this->ngroups = ngroups;
	adddisc(this);
}
int discipline::addgroup(group* gr) {
	if (gr == NULL) {
		throw invalid_argument("?????? ?? ?????? ???? ???????");
	}
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
	if (tst == NULL) {
		throw invalid_argument("?????? ?? ?????? ???? ???????");
	}
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
	if (n > ntests || n < 0) {
		throw out_of_range("???????? ????? ?????");
	}
	return this->tst[n];
}
string discipline::getname() {
	return this->name;
}
int discipline::count() {
	int cnt=0;
	group* buf;
	discipline *dscs[128];
	bool f;
	dscs[cnt++] = this;
	for (int i = 0; i < cnt; i++) {
		for (int j = 0; j < dscs[i]->ngroups; j++) {
			buf = dscs[i]->groups[j];
			for (int k = 0; k < buf->ndiscips; k++) {
				f = true;
				for (int z = 0; z < cnt; z++) {
					if (buf->disciplines[k]->name == dscs[z]->name) {
						f = false;
						break;
					}
				}
				if (f) {
					dscs[cnt++] = buf->disciplines[k];
				}
			}
		}
	}
	return cnt;
}
int discipline::numberof() {
	return ndiscips;
}
discipline** discipline::list() {
	return disciplines;
}
void discipline::adddisc(discipline* disc) {
	if (disc == NULL) {
		throw invalid_argument("?????? ?? ?????? ???? ???????");
	}
	discipline** buf = new discipline*[ndiscips];
	memcpy(buf, disciplines, sizeof(discipline*) * ndiscips);
	ndiscips++;
	disciplines = new discipline * [ndiscips];
	memcpy(disciplines, buf, sizeof(discipline*) * ndiscips);
	disciplines[ndiscips - 1] = disc;
}
ostream& operator<< (std::ostream& out, const discipline& disc) {
	out << "Discipline "<<disc.name<<":\n";
	if (disc.ngroups > 0) {
		out << " Groups:\n";
		for (int i = 0; i < disc.ngroups; i++) {
			out << "  "<<i<<")  "<<disc.groups[i]->getname()<<"\n";
		}
	}
	if (disc.ntests >= 0) {
		out << " Tests: "<<disc.ntests<<"\n";
	}
	return out;
}