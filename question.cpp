#include "question.h"

question* qsts(int n, question a, ...) {
	question* q = new question[n];
	question* src = &a;
	memcpy(q, src, sizeof(question) * n);
	return q;
}

question::question() {
	this->text = "";
	this->answer = "";
	this->value = 0;
}
question::question(string text, string answer, int value) {
	this->text = text;
	this->answer = answer;
	this->value = value;
}
void question::input() {
	cout << "Enter question: ";
	getline(cin, this->text);
	cout << "Enter answer: ";
	getline(cin, this->answer);
	cout << "Enter number of points: ";
	cin >> this->value;
	while (getchar() != '\n');
}
void question::change(string text, string answer, int value) {
	this->text = text;
	this->answer = answer;
	this->value = value;
}
void question::show() {
	cout << "Text: " << this->text << endl;
	cout << "Answer: " << this->answer;
	cout << "(" << this->value << " balls)" << endl;
}
string question::gettext() {
	return this->text;
}
string question::getanswer() {
	return this->answer;
}
int question::getvalue() {
	return this->value;
}
question question::operator+(int n) {
	this->value += n;
	return *this;
}
question question::operator++() {
	this->value++;
	return *this;
}
question question::operator++(int) {
	question b = *this;
	this->value++;
	return b;
}