#pragma once
#pragma warning( push ) // Disabling warnings Link: https://www.fluentcpp.com/2019/08/30/how-to-disable-a-warning-in-cpp/.
#pragma warning( disable : 26495 ) // 4244

#include <iostream>
#include <iostream>
#include <conio.h> //overloading operator.
#include <chrono>
#include <thread>
#include <algorithm>
#include <string>

using namespace std;
using namespace chrono;
using namespace this_thread;


class math{
public:
	unsigned short questAmount, pts = 0;
	int diff;
	string diffStr;
	short secondVar, ans, studAns;
	short arrEasy[5] = {0, 1, 2, 5, 10 }; // For Easy.
	short arrMed[11] = {0, 1, 2, 3, 4, 5, 6, 7, 8, 9, 10}; // For Medium.
	short arrHard[12] = {1, 2, 3, 4, 5, 6, 7, 8, 9, 10, 11, 12}; // For Hard.
	short arrCalc[12] = {13, 14, 15, 16, 17, 18, 19, 20, 21, 22, 23, 24}; // For Calculator.

	bool bDiff = false, studInput = false;

	void questProc() {
		// start:
		system("cls");

		cout << "How hard do you want the questions to be?" << endl;
		cout << "(The harder you choose, the larger the numbers you'll have to calculate)" << endl;
		cout << "1) EASY" << endl;
		cout << "2) MEDIUM" << endl;
		cout << "3) HARD" << endl;
		cout << "4) CALCULATOR MODE LOL" << endl << "~> ";
		cin >> diff;

		// Func to convert the input into a string.

		diffStr = to_string(diff);

		// Func to test if the input was an int.

		for (int i = 0; i < diffStr.length(); i++) {
			if (isdigit(diffStr[i]) == false) {
				// Not int.
				goto def;
			}
			else {
				// Int.
				break;
			}
		}

		switch (diff) {
		case 1:
			system("cls");
			cout << "EASY MODE ACTIVATED" << endl;
			sleep_for(0.25s); cout << "."; sleep_for(0.25s); cout << "."; sleep_for(0.25s); cout << "."; sleep_for(0.25s);
			break;

		case 2:
			system("cls");
			cout << "MEDIUM MODE ACTIVATED" << endl;
			sleep_for(0.25s); cout << "."; sleep_for(0.25s); cout << "."; sleep_for(0.25s); cout << "."; sleep_for(0.25s);
			break;

		case 3:
			system("cls");
			cout << "HARD MODE ACTIVATED" << endl;
			sleep_for(0.25s); cout << "."; sleep_for(0.25s); cout << "."; sleep_for(0.25s); cout << "."; sleep_for(0.25s);
			break;

		case 4:
			system("cls");
			cout << "CALCULATOR MODE ACTIVATED" << endl;
			sleep_for(0.25s); cout << "."; sleep_for(0.25s); cout << "."; sleep_for(0.25s); cout << "."; sleep_for(0.25s);
			break;

		default:
		def:
			system("cls");
			cout << "INPUTED VAL IS EITHER NOT AN INT OR ISN'T IN THE LIST, TRY AGAIN";
			sleep_for(0.25s); cout << "."; sleep_for(0.25s); cout << "."; sleep_for(0.25s); cout << "."; sleep_for(0.25s);
			goto end;

		}

		// The following creates the question according to the set difficulty.
		switch (diff) {
		case 1: // Easy Mode:
			system("cls");
			srand(time(NULL)); // Initializing random seed.
			random_shuffle(&arrEasy[0], &arrEasy[4]); // For first var.
			secondVar = rand() % 10 + 1; // Rand number from 1 to 10 (for second var).
			ans = arrEasy[0] * secondVar;
			cout << arrEasy[0] << " * " << secondVar << " = ?" << endl << "~> ";
			cin >> studAns;
			studInput = true;
			break;

		case 2: // Medium Mode:
			system("cls");
			srand(time(NULL)); // Initializing random seed.
			random_shuffle(&arrMed[0], &arrMed[11]); // For first var.
			secondVar = rand() % 10 + 1; // Rand number from 1 to 10 (for second var).
			ans = arrEasy[0] * secondVar;
			cout << arrEasy[0] << " * " << secondVar << " = ?" << endl << "~> ";
			cin >> studAns;
			studInput = true;
			break;

		case 3: // Hard Mode:
			system("cls");
			srand(time(NULL)); // Initializing random seed.
			random_shuffle(&arrHard[0], &arrHard[12]); // For first var.
			secondVar = rand() % 12 + 1; // Rand number from 1 to 10 (for second var).
			ans = arrHard[0] * secondVar;
			cout << arrHard[0] << " * " << secondVar << " = ?" << endl << "~> ";
			cin >> studAns;
			studInput = true;
			break;

		case 4: // Calculator mode:
			system("cls");
			srand(time(NULL)); // Initializing random seed.
			random_shuffle(&arrCalc[0], &arrCalc[12]); // For first var.
			secondVar = rand() % 24 + 1; // Rand number from 1 to 10 (for second var).
			ans = arrHard[0] * secondVar;
			cout << arrHard[0] << " * " << secondVar << " = ?" << endl << "~> ";
			cin >> studAns;
			studInput = true;
			break;

		default:
			break;
		}

	end:

		// The following checks if ans is correct.

		if (studAns == ans && studInput == true) {
			cout << "WELL DONE!" << endl;
			pts++;
			cout << "You have gained a point." << endl << "You now have : " << pts;
			if (pts == 1) {
				cout << " Point in total." << endl;
			}
			else {
				cout << " Points in total." << endl;
			}
			studInput = false;
		}
		else if (studAns != ans && studInput == true) {
			cout << "WRONG, CORRECT ANSWER WAS: " << ans << endl;
			cout << "You have gained no points" << endl;
			studInput = false;
		}

	}
	/*friend void operator << (ostream& out, math& m) {
		out << m.pts;
	}*/ // My attempt at overloading the operator. (link: https://www.youtube.com/watch?v=wElBXMmgWzM)
};

#pragma warning ( pop )