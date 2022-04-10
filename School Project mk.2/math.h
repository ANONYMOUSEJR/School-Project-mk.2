#pragma once
#pragma warning( push ) // Disabling warnings Link: https://www.fluentcpp.com/2019/08/30/how-to-disable-a-warning-in-cpp/.
#pragma warning( disable : 26495 ) // 4244

#include <iostream>
#include <chrono>
#include <thread>
#include <algorithm>

using namespace std;
using namespace chrono;
using namespace this_thread;


class math {
private:
	unsigned short pts = 0;

public:
	unsigned short questAmount;
	int diff; // implement a check so that the program checks that the input val is an int...
	//int* choice = new int[diff]; remove if needed.
	short arrEasy[4] = { 1, 2, 5, 10 }, secondVar, ans, studAns;
	bool bDiff = false;

	void questProc() {
	start:
		system("cls");

		cout << "How hard do you want the questtions to be?" << endl;
		cout << "(The harder you choose, the larger the numbers you'll have to calculate)" << endl;
		cout << "1) EASY" << endl;
		cout << "2) MEDIUM" << endl;
		cout << "3) HARD" << endl;
		cout << "4) CALCULATOR MODE LOL" << endl << "~> ";
		cin >> diff;

		switch (diff) {
		case 1:
			system("cls");
			cout << "EASY MODE ACTIVATED" << endl;
			break;

		case 2:
			system("cls");
			cout << "MEDIUM MODE ACTIVATED" << endl;
			break;

		case 3:
			system("cls");
			cout << "HARD MODE ACTIVATED" << endl;
			break;

		case 4:
			system("cls");
			cout << "CALCULATOR MODE ACTIVATED" << endl;
			break;

		default:
			system("cls");
			cout << "INPUTED VAL IS EITHER NOT AN INT OR ISN'T IN THE LIST"; // Checks only the starting int ignores the rest...
			sleep_for(0.5s); cout << "."; sleep_for(0.5s); cout << "."; sleep_for(0.5s); cout << "."; sleep_for(0.5s);
			bDiff = true;
			goto start;
			//break;


			//if (diff != 1 && diff != 2 && diff != 3 && diff != 4) { goto start; } // Try making this more optimised, get rid of the if statement and get on with your life...
		
		}

		// The following creates the question according to the set difficulty.
		srand(time(NULL)); // Initializing random seed.
		switch (diff) {
		case 1: // Easy Mode:
			system("cls");
			random_shuffle(&arrEasy[0], &arrEasy[4]); // For first var.
			secondVar = rand() % 10 + 1; // Rand number from 1 to 10 (for second var).
			ans = arrEasy[0] * secondVar;
			cout << arrEasy[0] << " * " << secondVar << " = ?" << endl << "~> ";
			cin >> studAns;
			break;

		default:
			break;
		}

		// The following checks if ans is correct.

		if (studAns == ans && bDiff == false) {
			cout << "WELL DONE!" << endl;
			pts++;
			cout << "You have gained a point, Totaling: " << pts;
			if (pts == 1) {
				cout << " Point in total." << endl;
			}
			else {
				cout << " Points in total." << endl;
			}
		}
		else if (studAns != ans/* && bDiff == false*/) {
			cout << "WRONG, CORRECT ANSWER WAS: " << ans << endl;
			cout << "You have gained no points" << endl;
		}
	}
};

#pragma warning ( pop )