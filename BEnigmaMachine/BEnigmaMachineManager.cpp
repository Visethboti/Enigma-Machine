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

string BEnigmaMachineManager::encrytStr(string inputStr) {
	string result = "";

	// Input a char at a time into the enigma machine from the input string
	for (int i = 0; i < inputStr.length(); i++) {
		result += enigmaMachine1.encypt(inputStr.at(i));
	}

	// Return the ecypted string
	return result;
}


void BEnigmaMachineManager::printMenu() {
	int menuInput, rotor1num, rotor2num, rotor3num, rotor1pos, rotor2pos, rotor3pos, reflectorType;
	string userMenuInput;
	string userInputStr;
	string existingPlugboardChar;
	bool goodToGo;

	do {
		// Print Main Menu with Options
		cout << "====|Welcome to My Enigma Machine!|====" << endl
			<< "1. Setup enigma settings" << endl
			<< "2. Encryt" << endl
			<< "3. Print properties and status" << endl
			<< "4. Reset enigma settings" << endl
			<< "5. Setup and use plugboard" << endl
			<< "6. Quit." << endl
			<< "- Choice: ";

		// Get user input of those options
		cin >> userMenuInput;
		cout << endl;

		// Check and make sure the user input are 1-5
		if (userMenuInput != "1" && userMenuInput != "2" && userMenuInput != "3" && userMenuInput != "4" && userMenuInput != "5" && userMenuInput != "6") {
			cout << "Incorrect Value, please choose option 1 to 5." << endl;
		}
		else {
			// Execute each code blog accordingly to the option choosen (1 to 5 from main menu)
			switch (userMenuInput[0]) {
			case '1':
				// Get User input of 7 properties (the three rotor Num and Position and reflector type)
				cout << "- Setup Enigma settings" << endl
					<< "- Rotor 1 Number (1-5): ";
				cin >> rotor1num;
				cout << "- Rotor 2 Number (1-5): ";
				cin >> rotor2num;
				cout << "- Rotor 3 Number (1-5): ";
				cin >> rotor3num;

				cout << "- Rotor 1 Position (1-26): ";
				cin >> rotor1pos;
				cout << "- Rotor 2 Position (1-26): ";
				cin >> rotor2pos;
				cout << "- Rotor 3 Position (1-26): ";
				cin >> rotor3pos;

				cout << "- Reflector Type(1-5): ";
				cin >> reflectorType;

				// Use the user inputs of those 7 properties and setup the enigma
				enigmaMachine1.enigmaSetup(rotor1num, rotor2num, rotor3num, rotor1pos, rotor2pos, rotor3pos, reflectorType);
				cout << endl << "EnigmaMachine setting are all set" << endl;
				break;
			case '2':
				// Ask user to enter a string to encypt
				cout << "> Enter a sentence below to encypt." << endl
					<< "- String to encypt: ";
				// Get User input string
				cin.ignore();
				getline(cin, userInputStr);

				// Return to menu if user input an empty string (no input) 
				if (userInputStr == "") {
					cout << endl << "> You entered an empty string. No string was encypted" << endl;
					cout << "> Returning to Menu." << endl << endl;
					break;
				}

				// Remove all white space in the user input string
				if (userInputStr.find(' ') != string::npos) {
					int index = userInputStr.find(' ');;
					do {
						userInputStr.erase(index, 1);
						index = userInputStr.find(' ');
					} while (index != string::npos);
				}

				//Capitalize all characters in the user input string
				for (int i = 0; i < userInputStr.length(); i++) {
					userInputStr[i] = toupper(userInputStr[i]);
				}

				// Check if user input sth else beside letters
				if (!isLetters(userInputStr)) {
					cout << "Please enter letter (ABC...XYZ) only." << endl;
					break;
				}

				// Encypt the String
				cout << "Encyted string is: " << encrytStr(userInputStr) << endl << endl;
				break;
			case '3':
				// Print the status (All rotors and reflector num position left right..etc)
				printStatus();
				break;
			case '4':
				enigmaMachine1.enigmaSetup(1, 2, 3, 1, 1, 1, 1);
				cout << endl << "> Enigma Settings are resetted." << endl << endl;
				break;
			case '5':
				cout << "==|Plugboard Setting|==" << endl
					<< "1. Setup plugboard." << endl
					<< "2. Turn on or off plugboard feature. (Using Plugboard: "<< enigmaMachine1.getUsePlugBoard() << ")" << endl
					<< "3. Reset plugboard." << endl
					<< "4. Exit to main menu."
					<< "- Choice: ";
				cin >> userInputStr;
				if (userInputStr != "1" && userInputStr != "2" && userInputStr != "3" && userInputStr != "4") {
					cout << "> Incorrect Input. Returning to menu..." << endl << endl;
					break;
				}
				else {
					switch (userInputStr[0]) {
					case '1':
						cout << "Enter two char as a pair to be connected in the Plug Board (e.g \'AZ\', \'BG\'..etc)" << endl;
						// Reset the plug board
						enigmaMachine1.resetPlugBoard();

						// Turn on plug board feature.
						enigmaMachine1.setUsePlugBoard(true);

						// Prompt User to enter 10 pairs, check each user input and ask again if incorrect input.
						for (int i = 1; i <= 10; i++) {
							existingPlugboardChar = enigmaMachine1.getAllExistingPairs();
							do {
								cout << "Pair " << i << " - ";
								cin >> userInputStr;

								//Capitalize all characters in the user input string
								for (int i = 0; i < userInputStr.length(); i++) {
									userInputStr[i] = toupper(userInputStr[i]);
								}

								if (!isLetters(userInputStr)) {
									cout << "Please enter letters (ABC...XYZ) only. Enter another pair." << endl;
									goodToGo = false;
								}
								else if (userInputStr.length() > 2 || userInputStr.length() == 1) {
									cout << "Incorrect Input. Please Enter a pair (\'AZ\', \'BG\'...etc)." << endl;
									goodToGo = false;
								}
								else if (userInputStr[0] == userInputStr[1]) {
									cout << "Plug board cannot connect a character to itself. Enter another pair." << endl;
									goodToGo = false;
								}
								// Find if the first character already existed as a pair in the plug board
								else if (existingPlugboardChar.find(userInputStr[0]) != string::npos) {
									cout << "\'" << userInputStr[0] << "\' already paired with another character. Enter another pair." << endl;
									goodToGo = false;
								}
								// Find if the second character already existed as a pair in the plug board
								else if (existingPlugboardChar.find(userInputStr[1]) != string::npos) {
									cout << "\'" << userInputStr[1] << "\' already paired with another character. Enter another pair." << endl;
									goodToGo = false;
								}
								else
									goodToGo = true;
							} while (!goodToGo);

							enigmaMachine1.setPlugBoardPair(userInputStr);
						}
						break;
					case '2':
						cout << "setting plugboard feature ";
						if (enigmaMachine1.getUsePlugBoard()) {
							cout << "OFF" << endl;
							enigmaMachine1.setUsePlugBoard(false);
						}
						else {
							cout << "ON" << endl;
							enigmaMachine1.setUsePlugBoard(true);
						}
						break;
					case '3':
						enigmaMachine1.resetPlugBoard();
						cout << "All plugboard pairs have been remove. Plugboard feature is turned OFF." << endl;
						break;
					case '4':
						cout << "- Returning to main menu..." << endl << endl;
					default:
						break;
					}
				}
				break;
			case '6':
				cout << endl << "Quiting..." << endl << endl;
				cout << "Thanks for using my Enigma Machine." << endl;
				exit(0);
				break;
			default:
				cout << "Incorrect Value, please choose option 1 to 5." << endl;
				break;
			}
		}
	} while (true);
}


// Check user input method
bool BEnigmaMachineManager::isLetters(string inputStr) {
	string letters = "ABCDEFGHIJKLMNOPQRSTUVWXYZ";
	for (int i = 0; i < inputStr.length(); i++) {
		// Return false if that character does not exist in letter (ABCD...XYZ)
		if (letters.find(inputStr[i]) == string::npos)
			return false;
	}
	return true;
}