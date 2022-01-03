#include <iostream>
#include "discipline.h"
#include "test.h"
#include "group.h"
#include "question.h"
#include "user.h"
int main()
{
	discipline* d = new discipline("Math");
	test* t = new test("Test");
	try {
		d->addtest(NULL);
	}
	catch(exception){
		d->addtest(t);
	}
	d->show();
	d->gettest(0)->show();
	user* u = new user("Ledle");
}