#include "user.h"
#include "group.h"
user::user() {//конструктор без параметров
	this->name = "";
	this->login = 0;
	this->password = 0;
}
user::user(string name) {//конструктор с одним параметром
	this->name = name; 
	this->login = 0;
	this->password = 0;
}
user::user(int login, int password, string name) {//конструктор со всеми параметрами
	this->name = name;
	this->login = login;
	this->password = password;
}
void user::rename(string name) {
	this->name = name;
}
void user::changepass(int password) {
	this->password = password;
}
void user::show() {
	printf_s("User %s:\n", this->name.c_str());
	printf_s(" Login: %d Password: %d\n", this->login, this->password);
}
void user::input() {
	printf_s("Enter name of user: ");
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
int user::getpass() {
	return this->password;
}