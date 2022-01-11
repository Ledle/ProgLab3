#include "question.h"

question* qsts(int n, question a, ...) {
	question* q = new question[n];
	question* src = &a;
	memcpy(q, src, sizeof(question) * n);
	return q;
}

question::question() {//конструктор без параметров
	this->text = "";
	this->answer = "";
	this->value = 0;
}
question::question(string text) {//конструктор с одним параметром
	this->text = text;
	this->answer = "";
	this->value = 0;
}
question::question(string text, string answer, int value) {//конструктор со всеми параметрами
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
question question::operator++() {//префиксный
	this->value++;
	return *this;
}
question question::operator++(int) {//постфиксный
	question b = *this;
	this->value++;
	return b;
}
ostream& operator<< (std::ostream& out, const question& q) {
	out << "Text: " << q.text << endl;
	out << "Answer: " << q.answer;
	out << "(" << q.value << " balls)" << endl;
	return out;
}