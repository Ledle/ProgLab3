#include "user.h"
#include "group.h"
user::user() {
	this->name = "";
	this->login = 0;
	this->password = 0;
	this->grp = NULL;
}
user::user(int login, int password, string name) {
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