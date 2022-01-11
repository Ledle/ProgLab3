#include "teacher.h"
#include "discipline.h"

teacher::teacher() :user() {}
teacher::teacher(string name) : user(name) {}
teacher::teacher(int login, int password, string name) : user(login, password, name) {}
void teacher::show() {
	printf_s("Teacher %s:\n", this->name.c_str());
	if (this->discips != NULL) {
		printf_s(" Disciplines:\n");
		for (int i = 0; i < ndiscips; i++) {
			printf_s("  %s\n", this->discips[i]->getname().c_str());
		}
	}
	printf_s(" Login: %d\n", this->login);
}
discipline** teacher::getdiscips() {
	return discips;
}
void teacher::adddisc(discipline* disc) {
	bool f = false;
	int i;
	for (i = 0; i < this->ndiscips; i++) {
		if (this->discips[i]->getname() == disc->getname()) {
			f = true;
			break;
		}
	}
	if (f) { return; }
	discipline** buf = new  discipline * [this->ndiscips + 1];
	memcpy(buf, this->discips, sizeof(discipline*) * (this->ndiscips));
	buf[this->ndiscips] = disc;
	delete this->discips;
	this->discips = buf;
	this->ndiscips++;
}
void teacher::deldisc(discipline* disc) {
	discipline* d;
	int numberdiscip = -1;
	for (int i = 0; i < this->ndiscips; i++) {
		if (disc == this->discips[i]) {
			numberdiscip = i;
			break;
		}
	}
	if (numberdiscip != -1) {
		d = this->discips[numberdiscip];
		this->ndiscips--;
		for (int i = numberdiscip; i < this->ndiscips; i++) {
			this->discips[i] = this->discips[i + 1];
		}
		discipline** buf = new discipline * [this->ndiscips];
		memcpy(buf, this->discips, sizeof(discipline*) * this->ndiscips);
		d->delgroup(this->name);
		delete this->discips;
		this->discips = buf;
	}
}
void teacher::input() {//перегрузка с вызовом родительского метода
	user::input();
	char str[128];
	printf_s("Enter discipline: ");
	scanf_s("%d", str);
	while (getchar() != '\n');
	string name(str);
	int i=-1;
	for (i = 0; i < discipline::numberof(); i++) {
		if (discipline::list()[i]->getname() == name) {
			break;
		}
	}
	discipline* disc;
	if (i == -1) {
		disc = new discipline(name);
	}
	else {
		disc = discipline::list()[i];
	}
	delete[] discips;
	discips = new discipline*[2];
	discips[0] = disc;
}
ostream& operator<< (std::ostream& out, const teacher& t) {
	out << "Teacher: " << t.name << endl;
	if (t.discips != NULL) {
		out << " Disciplines:\n";
		for (int i = 0; i < t.ndiscips; i++) {
			out << "  " << t.discips[i]->getname() << "\n";
		}
	}
	out << " Login: "<<t.login <<"\n";
	return out;
}