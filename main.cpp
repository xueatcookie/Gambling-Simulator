
#include <iostream>
#include <cstdlib>
#include <ctime>
#include <algorithm>
#include <string>
#include <cctype>
#include <random>
using namespace std;

int PlayerMoney = 100;
int Gnumber;

void ftn() {
    cout << endl << "[PRESS ENTER]" << endl;
    cin.get();
}

void next() {
    cin.get();
}

// Checks whether an input contains only digits
bool IsNumber(string input) {
    if (input.empty() || input.length() > 9) {
        return false;
    }

    for (char c : input) {
        if (c < '0' || c > '9') {
            return false;
        }
    }

    return true;
}

// Reads a number without causing infinite loops
int GetNumber() {
    string input;

    while (true) {
        if (!(cin >> input)) {
            return -1;
        }

        if (IsNumber(input)) {
            return stoi(input);
        }

        cout << endl << "INVALID NUMBER" << endl;
        cout << "Enter another number: ";
    }
}

void CoinFlipG() {
    while (true) {
        int a = 0;
        string coinguess;
        string coinresult = "tails";

        cout << "How much do you want to bet:" << endl;
        a = GetNumber();

        if (a == -1) {
            return;
        }

        while (a > PlayerMoney || a <= 0) {
            cout << endl << "INVALID BET" << endl;
            cout << "Your balance is $" << PlayerMoney << endl;
            cout << "Enter another bet: ";
            a = GetNumber();

            if (a == -1) {
                return;
            }
        }

        cout << "Heads or Tails?" << endl;
        cout << "Key your guess here:" << endl;

        if (!(cin >> coinguess)) {
            return;
        }

        for (char &c : coinguess) {
            c = tolower(c);
        }

        while (coinguess != "tails" && coinguess != "heads") {
            cout << endl << "INVALID GUESS" << endl;
            cout << "You can guess 'Heads' or 'Tails'" << endl;
            cout << "Enter another guess: ";

            if (!(cin >> coinguess)) {
                return;
            }

            for (char &c : coinguess) {
                c = tolower(c);
            }
        }

        static random_device rd;
        static mt19937 rng(rd());

        if (rng() % 2 == 0) {
            coinresult = "heads";
        }

        cout << "The result is: " << coinresult << endl;

        if (coinguess == coinresult) {
            cout << "You have doubled your money!" << endl;
            cout << "$" << PlayerMoney << " ---> "
                 << "$" << PlayerMoney + a;

            PlayerMoney += a;
        }
        else {
            cout << "You have lost your money!" << endl;
            cout << "$" << PlayerMoney << " ---> "
                 << "$" << PlayerMoney - a;

            PlayerMoney -= a;
        }

        if (PlayerMoney <= 0 || PlayerMoney >= 10000) {
            return;
        }

        int option = 0;

        while (option != 1 && option != 2) {
            cout << endl << endl;
            cout << "[1] Play Again" << endl;
            cout << "[2] Main Menu" << endl;

            option = GetNumber();

            if (option == -1) {
                return;
            }

            if (option != 1 && option != 2) {
                cout << endl << "[INVALID NUMBER]" << endl;
            }
        }

        if (option == 2) {
            cout << endl << endl;
            return;
        }
    }
}

void Roulette() {
    while (true) {
        string end;
        string playerguess;
        int a = 0;

        static random_device rd;
        static mt19937 gen(rd());
        uniform_int_distribution<int> dist(0, 36);

        int result = dist(gen);

        if (result == 0) {
            end = "green";
        }
        else if (result <= 18) {
            end = "black";
        }
        else {
            end = "white";
        }

        cout << "How much do you want to bet:" << endl;
        a = GetNumber();

        if (a == -1) {
            return;
        }

        while (a > PlayerMoney || a <= 0) {
            cout << endl << "INVALID BET" << endl;
            cout << "Your balance is $" << PlayerMoney << endl;
            cout << "Enter another bet: ";
            a = GetNumber();

            if (a == -1) {
                return;
            }
        }

        cout << endl;
        cout << "Place your guess, Black, White or Green" << endl;
        cout << "Out of 37 chances, 18 is black, "
             << "18 is white and 1 is green" << endl;
        cout << "Place your bet here:";

        if (!(cin >> playerguess)) {
            return;
        }

        for (char &c : playerguess) {
            c = tolower(c);
        }

        while (playerguess != "black" &&
               playerguess != "white" &&
               playerguess != "green") {

            cout << endl << "INVALID BET" << endl;
            cout << "You can guess 'Black' or 'White' or 'green'" << endl;
            cout << "Enter another guess: ";

            if (!(cin >> playerguess)) {
                return;
            }

            for (char &c : playerguess) {
                c = tolower(c);
            }
        }

        cout << "The result is: " << result
             << " (" << end << ")" << endl;

        // Green must be checked first
        if (playerguess == end && playerguess == "green") {
            cout << "You Are So Lucky" << endl;
            cout << "You Have Seven Times Your Money Now!" << endl;
            cout << "$" << PlayerMoney << " ---> "
                 << "$" << PlayerMoney + a * 6;

            PlayerMoney += a * 6;
        }
        else if (playerguess == end) {
            cout << "You have doubled your money!" << endl;
            cout << "$" << PlayerMoney << " ---> "
                 << "$" << PlayerMoney + a;

            PlayerMoney += a;
        }
        else {
            cout << "You have lost your money!" << endl;
            cout << "$" << PlayerMoney << " ---> "
                 << "$" << PlayerMoney - a;

            PlayerMoney -= a;
        }

        if (PlayerMoney <= 0 || PlayerMoney >= 10000) {
            return;
        }

        int option = 0;

        while (option != 1 && option != 2) {
            cout << endl << endl;
            cout << "[1] Play Again" << endl;
            cout << "[2] Main Menu" << endl;

            option = GetNumber();

            if (option == -1) {
                return;
            }

            if (option != 1 && option != 2) {
                cout << endl << "[INVALID NUMBER]" << endl;
            }
        }

        if (option == 2) {
            cout << endl << endl;
            return;
        }
    }
}

void CallGames() {
    while (true) {
        cout << "Balance:" << endl;
        cout << "$" << PlayerMoney << " - "
             << "$" << 10000 - PlayerMoney
             << " left to $10000" << endl << endl;

        cout << "Games:" << endl;
        cout << "[1]Coin flip - (Double your money)" << endl;
        cout << "[2]Roulette - (Double your money OR Have 10 times the amount)";

        cout << endl << "[ENTER NUMBER]" << endl;

        Gnumber = GetNumber();

        if (Gnumber == -1) {
            return;
        }

        if (Gnumber == 1) {
            CoinFlipG();
        }
        else if (Gnumber == 2) {
            Roulette();
        }
        else {
            cout << endl << "[INVALID NUMBER]" << endl;
        }

        if (PlayerMoney <= 0 || PlayerMoney >= 10000) {
            return;
        }
    }
}

int main() {
    cout << "Welcome To The Casino" << endl;
    cout << "Try to win, $10000" << endl;
    cout << "With $100";

    ftn();
    CallGames();

    return 0;
}
