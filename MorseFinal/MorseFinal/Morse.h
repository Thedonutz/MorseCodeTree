#pragma once
#include <string>
using namespace std;

class Morse
{
	public:
		Morse(char let, int dat) : letter(let), data(dat) {};

		int getData() { return data; }
		char getLetter() { return letter; }
		string mCode;

		void setCode(string x) { mCode += x; }
		string getCode() { return mCode; }
	private:

		char letter;
		int data;

};