#include <algorithm>
#include <iostream>
#include <vector>

#include "math.h"
#include "user.h"

using namespace std;
using namespace this_thread;

int main(){
    unsigned short usr = 0, amnt = 0;

    cout << "For the best experience (Full screen) please press [alt key] + [enter key]";
    sleep_for(1s); cout << "."; sleep_for(1.5s); cout << "."; sleep_for(2s); cout << "."; sleep_for(2s);
    system("cls");


    /*
    amount:
    cout << "How many Users are there? (Max: 25)" << endl << "~> ";
    cin >> usr;
    if (usr > 25) {
        cout << "That's too many, try again"; sleep_for(0.25s); cout << "."; sleep_for(0.25s); cout << "."; sleep_for(0.25s); cout << "."; sleep_for(0.25s);
        system("cls");
        goto amount;
    }
    */
    cout << "How many questions do you wish to answer?" << endl << "~> ";
    cin >> amnt;

    //vector<user> st(usr);

    math st;
    st.questProc();
    st.getBet();
    for (unsigned short i = 0; i < amnt; i++) {
        //cout << "User number " << i++ << "What is your name?" << endl << "~> ";
        // st[i].getName(); Outputs a fatal error, no time to trouble shoot.

        st.questAsk();

    }
    st.betProc();

    cout << endl << "You've done a total of " << amnt << " questions!";
    // Fix So that it displays only one user... no time to have multiple...

    /*
    // Populating the temporary array (called "arr"):
    user arr[25];
    copy(st.begin(), st.end(), arr);

    // Sorting from smallest to largest.
    sort(arr, arr + 25);

    system("cls");
    cout << "And now for the score board: ";

    for (unsigned short i = amnt; i != 0; i--) {
        cout << arr[i] << endl;
    }
    */

    return 0;
}