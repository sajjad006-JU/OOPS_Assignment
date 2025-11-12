/*
Design a BALANCE class with account number, balance and date of last update.
Consider a TRANSACTION class with account number, date of transaction,
amount and transaction type (W for withdrawal and D for deposit). If it is
withdrawal then check whether the amount is available or not. Transaction
object will make necessary update in the BALANCE class.

*/

class Balance {
    private:
        int acount_number;
        float balance;
        char* last_update_date;
    
    public:
        float checkBalance() {
            return acount_number;
        }
};

class Transaction {
    private:
        int acount_number;
        char* transaction_date;
        float amount;
        char transaction_type;
    
    public:
        Transaction(int account_number, )
};

int main () {

}