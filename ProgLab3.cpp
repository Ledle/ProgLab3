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
}