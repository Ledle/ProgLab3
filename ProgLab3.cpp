#include <iostream>
#include "discipline.h"
#include "test.h"
#include "group.h"
#include "question.h"
#include "user.h"
int main()
{
	discipline disc("Math");
	test t(qsts(4, question("2+2", "4", 2), question("9+7", "16", 3), question("5*3", "15", 4), question("18/3", "6", 5)), 4, "Test 1");
	disc.addtest(&t);
	group PI("PI");
	user sergey(5613, 112233, "Sergey");
	user john(9852, 541234, "John");
	PI.adduser(&sergey);
	PI.adduser(&john);
	PI.adddisc(&disc);
	disc.gettest(0)->addresult(sergey.getlogin(), 50);
	PI.show();
	putchar('\n');
	disc.show();
	putchar('\n');
	disc.gettest(0)->show();
	putchar('\n');
	PI.getstudent(0)->show();
	putchar('\n');
	printf_s("Add result in \"Test 1\"\n");
	disc.gettest(0)->addresult(john.getlogin(), 80);
	disc.gettest(0)->show();
	printf_s("Rename Sergey to Dima, John to Dave,PI to IB, Test 1 to Old Test 1,Math to Algebra:\n");
	sergey.rename("Dima");
	john.rename("Dave");
	disc.rename("Algebra");
	PI.rename("IB");
	disc.gettest(0)->rename("Old Test 1");
	PI.show();
	putchar('\n');
	disc.show();
	putchar('\n');
	disc.gettest(0)->show();
	putchar('\n');
	PI.getstudent(0)->show();
	putchar('\n');
	discipline kidmath("KidMath");
	printf_s("Delete Dave:\n");
	PI.delstudent(1);
	disc.show();
	printf_s("Delete \"Algebra\" from \"IB\" and add \"KidMath\":\n");
	PI.deldisc("Algebra");
	PI.adddisc(&kidmath);
	PI.show();
	printf_s("Move Dima to new group \"IBK\"\n");
	group ibk("IBK");
	sergey.getgroup()->delstudent(sergey.getlogin());
	sergey.changegroup(&ibk);
	ibk.show();
	printf_s("Delete \"PI\" from \"Algebra\"\n");
	disc.delgroup(PI.getname());
	disc.show();
	printf_s("Change question 1 in \"Old Test 1\"\n");
	disc.gettest(0)->getquest(0)->change("This question", "is changed", 99);
	disc.gettest(0)->show();
	printf_s("Delete \"Old Test 1\" from \"Algebra\"\nBefore:\n");
	disc.show();
	disc.deltest("Old Test 1");
	printf_s("After:\n");
	disc.show();
	discipline discip;
	discip.input();
	test t1,t2;
	t1.input();
	t2.input();
	discip.addtest(&t1);
	discip.addtest(&t2);
	discip.gettest(0)->show();
	question newquest;
	newquest.input();
	discip.gettest(0)->getquest(0)->change(newquest.gettext(), newquest.getanswer(), newquest.getvalue());
	discip.gettest(0)->show();
	group pi03;
	pi03.input();
	pi03.show();
	user student;
	student.input();
	pi03.adduser(&student);
	pi03.show();
}