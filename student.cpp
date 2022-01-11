#include "student.h"
#include "group.h"

student::student() :user() {}
student::student(string name):user(name) {}
student::student(int login, int password, string name):user(login,password,name) {}
void student::show() {
	printf_s("Student %s:\n", this->name.c_str());
	if (this->grp != NULL) {
		printf_s(" Group: %s\n", this->grp->getname().c_str());
	}
	printf_s(" Login: %d Password: %d\n", this->login, this->password);
}
group* student::getgroup() {
	return this->grp;
}
void student::changegroup(group* gr) {
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
void student::input() {//перегрузка без вызова родительского метода
	printf_s("Enter name of student: ");
	cin >> this->name;
	printf_s("Enter login: ");
	cin >> login;
	printf_s("Enter password: ");
	cin >> password;
}
ostream& operator<< (std::ostream& out, const student& st) {
	out << "Student " << st.name << ":\n";
	if (st.grp != NULL) {
		out << " Group: " << st.grp->getname() << endl;
	}
	out << " Login: "<< st.login <<" Password: " << st.password << endl;
	return out;
}