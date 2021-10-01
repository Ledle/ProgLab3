#include <iostream>
#include <string>
#include "Header.h"
using namespace std;
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
	cout << "(" << this->value << " balls)"<< endl;
}