// Boneroller
// A dice rolling app by AJP
//
// v 1.0.0

// Improvements needed:
// Improve color scheme

#include <iostream>
using namespace std;

#define BOLDRED     "\033[1m\033[31m"
#define BOLDYELLOW  "\033[1m\033[33m"
#define BOLDGREEN   "\033[1m\033[32m"
#define RESET   "\033[0m"

int dnumber;
int snumber;
int roll;
int modifier;
int result;
int total;

int main() {

    cout << BOLDGREEN << "How many dice? : " << RESET;
    cin >> dnumber;

    cout << endl;
    cout << BOLDGREEN << "How many sides? : " << RESET;
    cin >> snumber;

    cout << endl;
    cout << BOLDGREEN << "Modifier? : " << RESET;
    cin >> modifier;
    cout << endl;

    roll = ((rand() % snumber) +1);  // this current roll variable only rolls 1 dice according to side #

    for (int i = 0; i < dnumber; i++)
    {
        roll = ((rand() % snumber) +1);
        cout << roll << " ";

        if (snumber == 20 && roll == 1)
            cout << BOLDRED << " - Botch!" << RESET;
        if (snumber == 20 && roll == snumber)
            cout << BOLDGREEN << " - Critical!" << RESET;

        cout << endl;
        result = result + roll;
    }
    result = result + modifier;

    if (result < 0) // no negative results
        result = 1;

    total = result + total; // update the total

    // results
    cout << endl;
    cout << "Rolled " << dnumber << " " << snumber << "-sided dice then added " << modifier << endl;
    cout << "\n Result: " << BOLDRED << result << RESET << endl;

    cout << " Current total: " << BOLDYELLOW << total << RESET << endl;
    cout << endl;

    int menu;
    cout << " ENTER 1 to " << BOLDGREEN << "ROLL AGAIN" << RESET << endl;
    cout << " ENTER 2 to " << BOLDYELLOW << "RESET" << RESET << endl;
    cout << " ENTER 3 to " << BOLDRED << "EXIT" << RESET << endl;
    cout << "\n ENTER : ";
    cin >> menu;

    switch(menu)
    {
        case 1:
            modifier = 0;
            system("clear");
            main();
            break;
        case 2:
            total = 0;
            modifier = 0;
            system("clear");
            main();
            break;
        case 3:
            system("clear");
            break;
        default:
            system("clear");
            break;
    }

    return 0;
}