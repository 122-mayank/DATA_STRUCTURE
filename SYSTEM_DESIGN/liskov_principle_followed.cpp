#include<iostream>
#include<vector>
#include<typeinfo>
#include<stdexcept>

using namespace std;

class DepositOnlyAccount{
     
    public:
    virtual void deposit(double amount) = 0;
};

class WithdrawableAccount : public DepositOnlyAccount{
  
     public:
     virtual void withdraw(double amount) = 0;
};

class SavingAccount : public WithdrawableAccount{

    private:
    double balance;

    public:
    SavingAccount(){
         balance = 0;
    }

   void deposit(double amount) override{
         balance = balance + amount;
         cout <<"Deposited: "<< amount <<" in Savings Account . New Balance: "<< balance << endl;
    }

    void withdraw(double amount) override{
         if(balance >= amount){
             balance =- amount;
             cout <<"Withdraw: "<< amount <<" from Savings Account. New Balance: "<< balance << endl;
         }
         else{
            cout <<"Insufficient funds in Savings Accounts!\n";
         }

    }
};

class CurrentAccount : public WithdrawableAccount{

     private:
    double balance;

    public:
    CurrentAccount(){
        balance = 0;
    }

    void deposit(double amount)override{
         balance += amount;
         cout <<"Deposited "<< amount << " in current Account. New Balance: "<< balance << endl;
    }
    void withdraw(double amount)override{
         if(balance >= amount){
             balance =-amount;
             cout <<"Withdraw: "<< amount <<" from Current Account. New Balance: "<< balance << endl;
         }
         else{
            cout <<"Insufficient funds in Current Accounts!\n";
         }
    }
};

class FixedTermAccount : public DepositOnlyAccount{

    private:
    double balance;


    public:
    FixedTermAccount(){
         balance = 0;
    }


    void deposit(double amount){
         balance = balance + amount;
         cout <<"Deposited: "<<amount <<" in fixed Term Account.New Balance: "<< balance << endl;
    }
};

class BankClient{
    
    private:
    vector<WithdrawableAccount*>withdrawAccounts;
    vector<DepositOnlyAccount*>depositAccounts;

    public:
    BankClient(vector<WithdrawableAccount*>withdrawAccounts,
         vector<DepositOnlyAccount*>depositAccounts){

         this -> withdrawAccounts = withdrawAccounts;
         this -> depositAccounts = depositAccounts;
    }

    void processTransactions(){
        
        for(WithdrawableAccount* acc : withdrawAccounts){
               acc ->deposit(1000);
               acc->withdraw(500);
        }

        for(DepositOnlyAccount* acc : depositAccounts){
            acc->deposit(1000);
        }
    }

};

int main(){

    vector<WithdrawableAccount*>withdrawableAccounts;
    withdrawableAccounts.push_back(new SavingAccount());
    withdrawableAccounts.push_back(new CurrentAccount());

    vector<DepositOnlyAccount*>depositOnlyAccounts;
    depositOnlyAccounts.push_back(new FixedTermAccount());

    BankClient* client = new BankClient(withdrawableAccounts , depositOnlyAccounts);
    client ->processTransactions();

    return 0;

}

