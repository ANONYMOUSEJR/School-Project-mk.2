#pragma once

#include <iostream>
#include <iostream>
#include <chrono>
#include <thread>
#include <algorithm>
#include <string>
#include <stdlib.h>

using namespace std;
using namespace chrono;
using namespace this_thread;


class math{
public:
	bool terminate = false;
	int diff;
	string diffStr;
	short secondVar, bet, pts, ans, studAns;
	short arrEasy[5] = {0, 1, 2, 5, 10 }; // For Easy.
	short arrMed[10] = {1, 2, 3, 4, 5, 6, 7, 8, 9, 10}; // For Medium.
	short arrHard[12] = {1, 2, 3, 4, 5, 6, 7, 8, 9, 10, 11, 12}; // For Hard.
	short arrCalc[12] = {13, 14, 15, 16, 17, 18, 19, 20, 21, 22, 23, 24}; // For Calculator.


	void questProc() {

		system("cls");

		diff = 0;
		cout << "How hard do you want the question(s) to be?" << endl;
		cout << "(The harder you choose, the larger the numbers you'll have to calculate)" << endl;
		cout << "(Also choosing a harder difficulty will have a higher risk/reward)" << endl;
		cout << "1) EASY [Gain/Loss 1 Point]" << endl;
		cout << "2) MEDIUM [Gain/Loss 5 Points]" << endl;
		cout << "3) HARD [Gain/Loss 10 Points]" << endl;
		cout << "4) CALCULATOR MODE LOL [Gain/Loss 15 Points]" << endl << "~> ";
		cin >> diff;

		// Func to convert the input into a string.
		diffStr = to_string(diff);

		// Func to test if the input was an int.
		for (unsigned int i = 0; i < diffStr.length(); i++) {
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
			cout << "EASY MODE ACTIVATED";
			sleep_for(0.25s); cout << "."; sleep_for(0.25s); cout << "."; sleep_for(0.25s); cout << "."; sleep_for(0.25s);
			break;

		case 2:
			system("cls");
			cout << "MEDIUM MODE ACTIVATED";
			sleep_for(0.25s); cout << "."; sleep_for(0.25s); cout << "."; sleep_for(0.25s); cout << "."; sleep_for(0.25s);
			break;

		case 3:
			system("cls");
			cout << "HARD MODE ACTIVATED";
			sleep_for(0.25s); cout << "."; sleep_for(0.25s); cout << "."; sleep_for(0.25s); cout << "."; sleep_for(0.25s);
			break;

		case 4:
			system("cls");
			cout << "CALCULATOR MODE ACTIVATED";
			sleep_for(0.25s); cout << "."; sleep_for(0.25s); cout << "."; sleep_for(0.25s); cout << "."; sleep_for(0.25s);
			break;

		default:
		def:
			system("cls");
			cout << "GIVEN VALUE IS EITHER NOT AN INTEGER OR ISN'T IN THE LIST, TRY AGAIN";
			sleep_for(0.25s); cout << "."; sleep_for(0.25s); cout << "."; sleep_for(0.25s); cout << "."; sleep_for(0.25s);
			terminate = true;
		}
	}

	void questAsk() {
		// The following creates the question according to the set difficulty.
		srand(static_cast<unsigned int>(time(NULL))); // Initializing random seed.
		switch (diff) {
		case 1: // Easy Mode:
			system("cls");
			random_shuffle(&arrEasy[0], &arrEasy[4]); // For first var.
			secondVar = rand() % 10 + 1; // Rand number from 1 to 10 (for second var).
			ans = arrEasy[0] * secondVar;
			cout << arrEasy[0] << " * " << secondVar << " = ?" << endl << "~> ";
			cin >> studAns;
			break;

		case 2: // Medium Mode:
			system("cls");
			random_shuffle(&arrMed[0], &arrMed[10]); // For first var.
			secondVar = rand() % 10 + 1; // Rand number from 1 to 10 (for second var).
			ans = arrMed[0] * secondVar;
			cout << arrMed[0] << " * " << secondVar << " = ?" << endl << "~> ";
			cin >> studAns;
			break;

		case 3: // Hard Mode:
			system("cls");
			random_shuffle(&arrHard[0], &arrHard[12]); // For first var.
			secondVar = rand() % 12 + 1; // Rand number from 1 to 10 (for second var).
			ans = arrHard[0] * secondVar;
			cout << arrHard[0] << " * " << secondVar << " = ?" << endl << "~> ";
			cin >> studAns;
			break;

		case 4: // Calculator mode:
			system("cls");
			random_shuffle(&arrCalc[0], &arrCalc[12]); // For first var.
			secondVar = rand() % 24 + 1; // Rand number from 1 to 10 (for second var).
			ans = arrCalc[0] * secondVar;
			cout << arrCalc[0] << " * " << secondVar << " = ?" << endl << "~> ";
			cin >> studAns;
			break;
		}
		
		// The following checks if ans is correct and rewards or punishes accordingly.
		if (studAns == ans) {
			switch (diff) {
			case 1:
				cout << "WELL DONE!" << endl; 
				pts++; 
				cout << "You have GAINED a point!";
				break;

			case 2:
				cout << "WELL DONE!" << endl; 
				pts += 5; 
				cout << "You have GAINED Five points!";
				break;

			case 3:
				cout << "WELL DONE!" << endl; 
				pts += 10; 
				cout << "You have GAINED Ten points!";
				break;

			case 4:
				cout << "WELL DONE!" << endl; 
				pts += 15; 
				cout << "You have GAINED Fifteen points!";
				break;

			}
			
		}

		else if (studAns != ans) {
			switch (diff) {
			case 1:
				cout << "WRONG, the correct answer was: " << ans << endl; 
				pts--; 
				cout << "You have LOST a point!" << endl;
				break;

			case 2:
				cout << "WRONG, the correct answer was: " << ans << endl; 
				pts -= 5; 
				cout << "You have LOST Five points!" << endl;
				break;

			case 3:
				cout << "WRONG, the correct answer was: " << ans << endl; 
				pts -= 10; 
				cout << "You have LOST Ten points!" << endl;
				break;

			case 4:
				cout << "WRONG, the correct answer was: " << ans << endl; 
				pts -= 15; 
				cout << "You have LOST Fifteen points!" << endl;
				break;
			}
		}
		sleep_for(0.5s); cout << "."; sleep_for(0.5s); cout << "."; sleep_for(0.5s); cout << "."; sleep_for(0.5s);
	}

	void getBet() {
		system("cls");
		cout << "What do you think your score will be by the end of this game? (Be mindful of what difficulty you chose, as well as how many questions you'll answer.)" << endl << "~> ";
		cin >> bet;
	}

	void betProc() {
		system("cls");
		if (bet < pts) {
			cout << "Congrats, you've outdone yourself by " << pts - bet << " Points!" << endl << "Have a cookie :3";
			cout << endl << endl << "BTW your score was: " << pts << " points.";
		}
		else if (bet > pts) {
			cout << "Pity, you missed your mark by just " << bet - pts << " Points!" << endl << "Better luck next time <3";
			cout << endl << endl << "BTW your score was: " << pts << " points.";
		}
		else if (bet == pts) {
			cout << "Bravo, you where spot on!";
			cout << endl << endl << "BTW your score was: " << pts << " points.";
		}
	}

	/*friend void operator << (ostream& out, math& m) {
		out << m.pts;
	}*/ // My attempt at overloading the operator. (link: https://www.youtube.com/watch?v=wElBXMmgWzM)
};
