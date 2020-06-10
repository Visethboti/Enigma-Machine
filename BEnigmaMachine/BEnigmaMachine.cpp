// HisterEnigmaMachine.cpp : This file contains the 'main' function. Program execution begins and ends there.
//

#include "pch.h"
#include <iostream>

#include <string>
#include "BEnigmaMachineManager.h"

using namespace std;

int main()
{
	BEnigmaMachineManager bEM;
	//bEM.printStatus();
	//bEM.printDebug();

	//bEM.encrytStr("PSYK");
	//bEM.printStatus();

	bEM.printMenu();



	/* 
	string s = "ab c d ef g";
	cout << s << endl;

	s.erase(2, 1);

	while (s.find(' ') != string::npos) {
		cout << "found" << endl;
		s.erase(s.find(' '), 1);
		cout << s << endl;
	}

	cout << s << endl;

	
	string s = "ABC";
	char temp;
	cout << s << endl;
	for (int i = 1; i < 4; i++) {
		temp = s.at(2);
		s.pop_back();
		s = temp + s;

		cout << s << endl;
	}
	*/
	
}