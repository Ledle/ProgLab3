#include <iostream>
#include "discipline.h"
#include "test.h"
#include "group.h"
#include "question.h"
#include "user.h"
int main()
{
	question q("Question", "Answer", 11);
	q.show();
	(q++).show();
	q.show();
	(q + 15).show();
	q.show();
	discipline a[5];
	a[0].rename("A");
	a[1].rename("B");
	a[2].rename("C");
	a[3].rename("D");
	a[4].rename("E");
	group b[5];
	for (int i = 0; i < 5; i++) {
		b[i].adddisc(&(a[i]));
	}
	for (int i = 0; i < 4; i++) {
		b[i].adddisc(&(a[i+1]));
	}
	cout << a[0].count();
}