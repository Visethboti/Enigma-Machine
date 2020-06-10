#include "pch.h"
#include "BEnigmaMachineManager.h"

#include <iostream>
using namespace std;

// Constructor
BEnigmaMachineManager::BEnigmaMachineManager()
{
	enigmaMachine1.enigmaSetup(1,2,3,1,1,1,1);
}

// Print out the status of all the rotors and the reflector
void BEnigmaMachineManager::printStatus() {
	cout << enigmaMachine1.getStatus() << endl;
}


//Debugging Tool
void BEnigmaMachineManager::printDebug() {
	cout << enigmaMachine1.getDebug() << endl;
}

void BEnigmaMachineManager::encrytStr(string inputStr) {
	string result;

	for (int i = 0; i < inputStr.length(); i++) {
		result += enigmaMachine1.encypt(inputStr.at(i));
	}

	cout << "Encyted string is: " << result << endl;
}

void BEnigmaMachineManager::printMenu() {
	int menuInput, rotor1num, rotor2num, rotor3num, rotor1pos, rotor2pos, rotor3pos, reflectorType;
	string userInputStr;

	do {
		cout << "Welcome to My Enigma Machine!" << endl
			<< "1. to setup enigma settings" << endl
			<< "2. to encryt" << endl
			<< "3. to print properties and status" << endl
			<< "4. to reset snigma settings" << endl
			<< "5. to quit." << endl
			<< "Choice: ";
		cin >> menuInput;

		switch (menuInput) {
		case 1:
			cout << "Setup Enigma settings" << endl
				<< "Rotor 1 Number (1-5): ";
			cin >> rotor1num;
			cout << "Rotor 2 Number (1-5): ";
			cin >> rotor2num;
			cout << "Rotor 3 Number (1-5): ";
			cin >> rotor3num;

			cout << "Rotor 1 Position (1-26): ";
			cin >> rotor1pos;
			cout << "Rotor 2 Position (1-26): ";
			cin >> rotor2pos;
			cout << "Rotor 3 Position (1-26): ";
			cin >> rotor3pos;

			cout << "Reflector Type(1-5): ";
			cin >> reflectorType;

			enigmaMachine1.enigmaSetup(rotor1num, rotor2num, rotor3num, rotor1pos, rotor2pos, rotor3pos, reflectorType);
			cout << endl << "EnigmaMachine setting are all set" << endl;
			break;
		case 2:
			cout << "Enter a sentence below to encryt. Please do not include spaces." << endl
				<< "String to encypt: ";
			// Get User input string
			cin.ignore();
			getline(cin, userInputStr);
			cin.clear();

			if (userInputStr.find(' ') != string::npos) {
				int index = userInputStr.find(' ');;
				do {
					userInputStr.erase(index, 1);
					index = userInputStr.find(' ');
				} while (index != string::npos);
			}

			//Capitalize all characters
			for (int i = 0; i < userInputStr.length(); i++) {
				userInputStr[i] = toupper(userInputStr[i]);
			}

			// Encypt the String
			encrytStr(userInputStr);
			break;
		case 3:
			// Print the status (All rotors and reflector num position left right..etc)
			printStatus();
			break;
		case 4:
			enigmaMachine1.enigmaSetup(1, 2, 3, 1, 1, 1, 1);
			break;
		case 5:
			cout << endl << "Quiting..." << endl << endl;
			break;
		default:
			cout << "Incorrect Value, please choose option 1 to 5." << endl;
			break;
		}

	} while (menuInput != 5);
	cout << "Thanks for using my Enigma Machine." << endl;
}