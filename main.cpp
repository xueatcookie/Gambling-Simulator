
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
void CoinFlipG() {
    while (true) {
    int a = 0;
    string coinguess;
    string coinresult = "tails";
    cout << "How much do you want to bet:" << endl;
    cin >> a;
    while (a > PlayerMoney || a <= 0) {
        cout << endl << "INVALID BET" << endl;
        cout << "Your ballance is $" << PlayerMoney << endl;
        cout << "Enter another bet: ";
        cin >> a;
    }
    cout << "Heads or Tails?" << endl;
    cout << "Key your guess here:" << endl;
    cin >> coinguess;
    
    while (coinguess != "tails" && coinguess != "heads") {
        for (char &c : coinguess) {
            c = tolower(c);
        }
        cout << endl << "INVALID GUESS" << endl;
        cout << "You can guess 'Heads' or 'Tails'" << endl;
        cout << "Enter another guess: ";
        cin >> coinguess;
    }
    static random_device rd;
    static mt19937 rng(rd());
    if (rng() % 2 == 0)
    {
        coinresult = "heads";
    }

    cout << "The result is: " << coinresult << endl;

    if (coinguess == coinresult) {
        cout << "You have doubled your money!" << endl;
        cout << "$" << PlayerMoney << " ---> " << "$" << PlayerMoney + a * 2;
        PlayerMoney = PlayerMoney + a * 2;
    }
    else {
        cout << "You have lost your money!" << endl;
        cout << "$" << PlayerMoney << " ---> " << "$" << PlayerMoney - a;
        PlayerMoney = PlayerMoney - a;
    }

    if (PlayerMoney <= 0 || PlayerMoney >= 10000) {
        return;
    }

    int option = 0;
    while (option != 1 && option != 2) {
        cout << endl << endl << "[1] Play Again" << endl;
        cout << "[2] Main Menu" << endl;
        cin >> option;

        if (option != 1 && option != 2) {
            cout << endl << "[INVALID NUMBER]" << endl;
        }
    }

    if (option == 2) {
        cout << endl << endl;;
        return;
    }
    }
}
void CallGames() {
    while (true) {
    cout << "Balance:" << endl << "$" << PlayerMoney << " -" << " $" << 10000 - PlayerMoney << " left to $10000" << endl << endl;
    cout << "Games:" << endl << "[1]Coin flip - (Double your money)" << endl << "[2]Roulette - (Double your money OR Have 10 times the amount)";
    cout << endl << "[ENTER NUMBER]" << endl;
    cin >> Gnumber;
    if (Gnumber == 1){
        CoinFlipG();
    }
    else if (Gnumber == 2){
        
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
    cout << "Welcome To The Casino" << endl << "Try to win, $10000" << endl << "With $100";
    ftn();
    CallGames();
    return 0;
}
