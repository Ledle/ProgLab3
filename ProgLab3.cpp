#include <iostream>
#include "object.h"
#include "discipline.h"
#include "test.h"
#include "group.h"
#include "question.h"
#include "user.h"
#include "student.h"
#include "teacher.h"
#include "guest.h"
int main()
{
	teacher t = teacher("Kolya");
	cout << t;
	student s = student("Sasha");
	cout << s;
	guest g = guest();
	g = s;
	user* u = new student(111,546,"Gosha");
	u->show();
	u = new user(112, 545, "Gena");
	u->show();
}