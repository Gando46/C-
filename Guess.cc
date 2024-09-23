#include <iostream>
#include <stdlib.h>    
#include <vector>
using namespace std;

struct user {
    string username;
    string password;
    double monney;
};

void login(const vector<user>& accounts, int& logged_in_index) {
    user input;
    bool found = false;
    cout << "USERNAME: ";
    cin >> input.username;

    for (int i = 0; i < accounts.size(); ++i) {
        if (accounts[i].username == input.username) {
            found = true;
            cout << "PASSWORD: ";
            cin >> input.password;

            if (accounts[i].password == input.password) {
                cout << "LOGIN COMPLETED!" << endl;
                logged_in_index = i; 
            } else {
                cout << "INCORRECT PASSWORD, TRY AGAIN." << endl;
            }
            break; 
        }
    }

    if (!found) {
        cout << "USER NOT FOUND" << endl;
    }
}

void registration(vector<user>& accounts) {
    bool good = false;
    string username, password;
    while(!good) {
        cout << "CHOOSE A USERNAME: ";
        cin >> username;
        good = true; 
        for(int i = 0; i < accounts.size(); ++i) {
            if(accounts[i].username == username) {
                cout << "USERNAME ALREADY TAKEN! TRY ANOTHER ONE!" << endl;
                good = false; 
                break;
            }
        }
    }
    cout << "CHOOSE A PASSWORD: ";
    cin >> password;
    
    user new_user;
    new_user.username = username;
    new_user.password = password;
    new_user.monney = 0; 
    accounts.push_back(new_user);
    
    cout << "USER " << new_user.username << " CREATED SUCCESSFULLY!" << endl;
}

int main() {
    vector<user> accounts;
    bool res = false;
    int logged_in_index = -1; 
    
    while(logged_in_index == -1) {
        cout << "DO YOU WANT TO REGISTER? (1) OR DO YOU WANT TO LOGIN? (2)" << endl;
        int a;
        cin >> a;
        if(a == 1) {
            registration(accounts);
        }
        else if(a == 2) {
            login(accounts, logged_in_index);
        }
    }

    bool loosing = false;
    while(!loosing) {

        string username = accounts[logged_in_index].username;
        double& macc = accounts[logged_in_index].monney; 
        
        cout << "WELCOME BACK " << username << "!!!" << endl;
        cout << "YOUR CURRENT MONEY IS " << macc << "€" << endl;
        cout << "WHAT DO YOU WANT TO DO?" << endl;
        cout << "  1. PLAY GUESSING GAME" << endl;
        cout << "  2. INSERT MONEY" << endl;
        cout << "  3. LEAVE" << endl;

        int decision;
        cin >> decision;
        
        if(decision == 1) {

            cout << "LET'S PLAY THEN!" << endl;
            cout << "SELECT THE RANGE (WHICH WILL INFLUENCE THE MULTIPLIER)" << endl;
            int a, b;
            cout << "FROM: ";
            cin >> a;
            cout << "TO: ";
            cin >> b;
            cout << endl;
            
            int random = a + (rand() % (b - a + 1)); 
            
            cout << "HOW MUCH ARE YOU BETTING?" << endl;
            double money;
            cin >> money;
            
            if(money > macc) {
                cout << "NOT ENOUGH MONEY!" << endl;
                continue;
            }
            
            macc -= money;
            double multiplier = 1 + ((b - a) / 10.0); 
            
            cout << "ENTER YOUR NUMBER: ";
            int number;
            cin >> number;
            
            if(number == random) {
                cout << "CONGRATULATIONS!! YOU WON!!" << endl;
                double win_amount = money * multiplier;
                macc += win_amount;
                cout << win_amount << "€ HAS BEEN ADDED TO YOUR ACCOUNT!" << endl;
            } else {
                cout << "YOU LOSE. BETTER LUCK NEXT TIME!" << endl;
            }
        }
        else if(decision == 2) {

            cout << "HOW MUCH MONEY DO YOU WANT TO DEPOSIT?" << endl;
            double money;
            cin >> money;
            macc += money;
            cout << money << "€ ADDED TO YOUR ACCOUNT!" << endl;
        }
        else if(decision == 3) {
            cout << "SEE YOU NEXT TIME!" << endl;
            break;
        }
    }

    return 0;
}
