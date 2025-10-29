#include <iostream>

using namespace std;
/*

Design the class(es) for the following. Each account has account number and
balance amount. A list of account is to be maintained where one can add and
find account, display information of all accounts. While adding, account number
must be unique. Withdraw object has account number (must exist) and amount
(will not exceed balance amount of corresponding account). Withdraw object will
update the balance of corresponding account in the list. User will be able to
search and view account, add account and withdraw money from the
account. Implement your design. Use friend function wherever required and
again, modify your implementation to avoid friend function.

*/

#define MAX_SIZE 100

class Account {
    private:
        int acc_no;
        float balance;

    public:
        Account() {
            acc_no=0;
            balance=0.0;
        }

        Account(int acc_no, float balance) {
            this->acc_no=acc_no;
            this->balance=balance;
        }
        int getAccountNumber() {
            return acc_no;
        }

        void deposit(float amount) {
            if (amount>0) {
                balance+=amount;
                cout << "amount depositted successfully.\n";
            } else {
                cout << "invalid deposit amount.\n";
            }
        }

        void withdraw(float amount) {
            if (amount<=0) {
                cout << "invalid withdrawl amount.\n";
            } else if (amount>balance) {
                cout << "insufficient balance.\n";
            } else {
                balance-=amount;
                cout << "amount withdrawn succefully.\n";
            }
        } 

        void display() const {
            cout << "Account: " << acc_no << " Balance: " << balance << "\n";
        }
};

class AccountList {

    private:
        Account accounts[MAX_SIZE];
        int count;

        int searchAccount(int acc_no) {
            for (int i=0; i<MAX_SIZE; i++) {
                if (accounts[i].getAccountNumber()==acc_no) {
                    return i;
                }
            }
            return -1;
        }

    public:
        AccountList() {
            count=0;
        }

        void addAccount(int acc_number, float balance) {
            if (searchAccount(acc_number)==-1) {
                Account acc(acc_number, balance);
                accounts[count]=acc;
                count++;
            } else {
                cout << "Account already exists\n";
            }
        }

        void getAccountDetail(int acc_no) {
            int k=searchAccount(acc_no);

            if (k==-1) {
                cout << "account not found.\n";
            } else {
                accounts[k].display();
            }
        }

        void showAllAccounts() {
            cout << "All account details";
            for (int i=0; i<count; i++) {
                accounts[i].display();
            }
        }

        void depositToAccount(int acc_no, float amount) {
            int k=searchAccount(acc_no);

            if (k==-1) {
                cout << "invalid acc no.\n";
            } else {
                accounts[k].deposit(amount);
            }
        }

        void withdrawFromAccount(int acc_no, float amount) {
            int k=searchAccount(acc_no);

            if (k==-1) {
                cout << "invalid acc no.\n";
            } else {
                accounts[k].withdraw(amount);
            }
        }
};

int main () {
    AccountList list;

    while(1) {

        cout << "\n1. Add Account  2. Search Account  3. Withdraw money  4. Deposit Money \n";
        int option, acc;
        float amt;
        cin >> option;

        switch (option) {
            case 1:
                cout << "enter account no: ";
                cin >> acc;
                list.addAccount(acc, 0);
                break;
            case 2:
                cout << "enter account no: ";
                cin >> acc;
                list.getAccountDetail(acc);
                break;
            case 3:
                cout << "enter account no: ";
                cin >> acc;
                cout << "enter amount to withdraw: ";
                cin >> amt;
                list.withdrawFromAccount(acc, amt);
                break;
            case 4:
                cout << "enter account no: ";
                cin >> acc;
                cout << "enter amount to deposit: ";
                cin >> amt;
                list.depositToAccount(acc, amt);
                break;
            default:
                cout << "invalid option\n";
                break;
        }
    }
}