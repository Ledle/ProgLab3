#include "guest.h"
#include <cstdlib>
guest::guest() :student() {
	srand(9886);
	login = rand();
}
guest::guest(string name) : student(name) {
	srand(9886);
	login = rand();
}
guest& guest::operator=(student st) {
	this->login = st.getlogin();
	this->name = st.getname();
	return *this;
}