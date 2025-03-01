#include<iostream>
#include<string>
#include<vector>
using namespace std;

int balances[4];
vector<string> maxNames(4);
int y;

class bank {
public:
    int searchAccount(string searchName) {
        for (int i = 0; i <= 3; i++) {
            if (searchName == maxNames[i]) {
                return i;
            }
        }
        return -1;
    }

    void performTransactions(int z) {
        string performChoice, operation;
        int amount;
        cout << "Current Balance : ";
        cout << balances[z];

        cout << "\nDo you want to perform operations on your account? (yes/no) : ";
        cin >> performChoice;

        if (performChoice == "yes") {
            cout << "Enter the Operation : ";
            cin >> operation;

            if (operation == "credit") {
                cout << "Enter the Amount : ";
                cin >> amount;
                balances[z] = balances[z] + amount;
                cout << "Current Balance = ";
                cout << balances[z];
            } 
            else if (operation == "debit") {
                cout << "Enter the Amount = ";
                cin >> amount;
                balances[z] = balances[z] - amount;

                if (balances[z] < 0) {
                    cout << "Insufficient balance\nCurrent balance = ";
                    balances[z] = balances[z] + amount;
                    cout << balances[z];
                } 
                else {
                    cout << "Amount Successfully Withdrawn\nCurrent Balance = ";
                    cout << balances[z];
                }
            } 
            else {
                cout << "Invalid input!";
            }
        }
        else {
                cout << "Invalid input!";
            }
    }

    void createAccount() {
        int emptyIndex = -1;
        string name, depositChoice;
        cout << "Account Holder's Name = ";
        cin >> name;

        for (int i = 0; i <= 3; i++) {
            if (name == maxNames[i]) {
                cout << "Account already exist";
                return;
            }
        }

        for (int i = 0; i <= 3; i++) {
            if (maxNames[i].empty()) {
                emptyIndex = i;
                break;  // Fix to prevent overwriting last empty index
            }
        }

        if (emptyIndex == -1) {
            cout << "No space available for new accounts.";
            return;
        }

        cout << "Do you want to credit money in your account? (yes/no) = ";
        cin >> depositChoice;

        if (depositChoice == "yes") {
            maxNames[emptyIndex] = name;
            cout << "Enter the Amount = ";
            cin >> balances[emptyIndex];
            cout << "Current Balance = ";
            cout << balances[emptyIndex];
            return;
        }

        else if (depositChoice == "no") {
            maxNames[emptyIndex] = name;
            return;
        }
        else{
        	cout<<"Invalid input";
		}
    }
};

int main() {
    cout << "Welcome!!!\n";
    cout << "Instructions\n";
    cout << " Type quit when the loop repeats \n";

    while (true) {
        int index;
        char u;
        string choice, an me;
        cout << "\nDo you want to Create a new account? (yes/no) = ";
        cin >> choice;

        bank b1;

        if (choice == "yes") {
            b1.createAccount();
        } 
        else if (choice == "no") {
            cout << "Enter account holder's name to login : ";
            cin >> name;
            
            index = b1.searchAccount(name);

            if (index == -1) {
                cout << "Account not found!!\nPlease create a new account first";
            } 
            if(index != -1) {
            cout << "Do you want to delete a account? (yes/no) :";
            cin >> choice;

          
            if (choice == "yes") {
                balances[index] = 0;
                maxNames[index] = "";

                cout << "Account deleted successfully!\nThank You!!!";
            } 
            else if (choice == "no") {
                b1.performTransactions(index);
            } 
            else {
                cout << "Invalid Input!";
            }
        }
        } 
        else if (choice == "quit") {
            cout << "Thank You!";
        } 
        else {
            cout << "Invalid input! please enter correct input.\n";
        }
    }
    return 0;
}

