#include "test.h"
#include "question.h"

test::test() {
	this->name = "";
	this->quest;
	this->nquests = 0;
	this->result = new int[1];
	this->nres = 0;
}
test::test(question questions[], int n, const char* name) {
	this->name = name;
	this->quest = new question[n];
	memcpy(this->quest, questions, sizeof(question) * n);
	this->nquests = n;
	this->result = new int[1];
	this->nres = 0;
}
void test::rename(const char* name) {
	this->name = name;
}
int test::addresult(int login, int result) {
	int* buf = new int[this->nres * 2 + 2];
	memcpy(buf, this->result, sizeof(int) * (this->nres) * 2);
	buf[this->nres * 2] = login;
	buf[this->nres * 2 + 1] = result;
	this->nres++;
	delete[] this->result;
	this->result = buf;
	return this->nres - 1;
}
string test::getname() {
	return this->name;
}
void test::show() {
	printf_s("Test %s", this->name.c_str());
	putchar('\n');
	if (this->nquests > 0) {
		printf_s(" Questions:\n");
		for (int i = 0; i < this->nquests; i++) {
			printf_s("  %d)Question: %s\n   Answer: %s(%d points)\n", i, (this->quest[i].gettext()).c_str(), (this->quest[i].getanswer()).c_str(), this->quest[i].getvalue());
		}
	}
	if (this->nres > 0) {
		printf_s(" Results:\n");
		for (int i = 0; i < this->nres; i++) {
			printf_s("  %d) Login: %d Result: %d\n", i, this->result[i * 2], this->result[i * 2 + 1]);
		}
	}
}
void test::input() {
	printf_s("Enter name of test: ");
	getline(cin, this->name);
	printf_s("Enter number of questions: ");
	scanf_s("%d", &this->nquests);
	while (getchar() != '\n');
	if (this->quest != NULL) {
		delete this->quest;
	}
	this->quest = new question[this->nquests];
	for (int i = 0; i < this->nquests; i++) {
		this->quest[i].input();
	}
}
question* test::getquest(int n) {
	return this->quest + n;
}
test::~test() {
	if (this->result != NULL) {
		delete[] this->result;
	}
}