#include<bits/stdc++.h>
#include<stdexcept>
using namespace std;

class Account{
    
    public:
    virtual void deposit(double amount) = 0;
    virtual void withdraw(double amount) = 0;
};

class SavingAccount : public Account{
    
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

class CurrentAccount : public Account{

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

class FixedTermAccount : public Account{

    private:
    double balance;

    public:
    FixedTermAccount(){
        balance = 0;
    }

    void deposit(double amount)override{
         balance += amount;
         cout <<"Deposited: "<<amount <<" in fixed Term Account.New Balance: "<< balance << endl;
    }

    void withdraw(double amount){
         throw logic_error("Withdraw not allowed in fixed Term Account!");
    }
};

class BankClient{
    
    private:
    vector<Account*>accounts;

    public:
    BankClient(vector<Account*>accounts){
         this -> accounts = accounts;
    } 

    void processTransactions(){
         for(Account* acc : accounts){
             acc -> deposit(1000);
             
             if(typeid(*acc) == typeid(FixedTermAccount)){
                 cout <<"Skipping withdrawl for fixed term account.\n";
             }
             else{
             try{
                acc -> withdraw(500);
             }
             catch(const logic_error&e){
                   cout <<"Exception: "<< e.what() << endl;
              }
            }
         }
    }

};

int main(){

     vector<Account*>accounts;

     accounts.push_back(new SavingAccount());
     accounts.push_back(new CurrentAccount());
     accounts.push_back(new FixedTermAccount());

     BankClient* client = new BankClient(accounts);
     client -> processTransactions();
     
     return 0;

}