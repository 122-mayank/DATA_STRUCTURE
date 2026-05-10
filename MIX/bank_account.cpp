

// coding for the open closed principle

#include<bits/stdc++.h>
using namespace std;

class Product{

    public:
    string name;
    double price;

    Product(string name , double price){
         this -> name = name;
         this -> price = price;
    }

};

class ShoppingCart{

     private:
     vector<Product*>products;

     public:

     void addProduct(Product* p){
         products.push_back(p);
     }

     const vector<Product*>& getProducts(){
          return products;
     }

     void calculateTotal(){
          double total = 0;

          for(auto p : products){
              total = total + p ->price;
          }
        return total;
     }

};

class ShoppingPrinter{

     private:
     ShoppingCart* cart;

     public:
     ShoppingPrinter(ShoppingCart* cart){
         this -> cart = cart;
     }

     void printInvoice(){

         cout <<"Print Invoice\n";

         for(auto p : cart->getProducts()){
               cout << p -> name <<" -$" << p ->price<< endl;
         }

         cout << "Total: $" << cart -> calculateTotal() << endl;

     }

};

class Persistence{

    private:
    ShoppingCart* cart;

    public:
    virtual void save(ShoppingCart* cart) = 0 ;         //pure virtual function     
};

class SQLPersistence{

    public:
    void save(ShoppingCart* cart) override{
           cout <<"Saving Shopping cart to SQL database........"<< endl;
    }
};

class MongoDBPersistence{

    public:
    void save(ShoppingCart* cart) override{
         cout <<"Saving Shopping cart to MongoDb database........."<< endl;
    }
};

class FilePersistence{

    public:
    void save(ShoppingCart* cart) override{
        cout <<"Saving Shopping cart to file database................."<< endl;
    }
};

int main(){

    ShoppingCart* cart = new ShoppingCart();
    cart -> addProduct(new Product("Laptop" , 1500));
    cart -> addProduct(new Product("Mouse" , 50));
    
    ShoppingCartPrinter* printer = new ShoppingCartPrinter(cart);
    printer -> printInvoice();

    Persistence* db = new SQlPersistence();
    Persistence* mongodb = new MongoDBPersistence();
    Persistence* file = new FilePersistence();

    db->save(cart);
    mongodb->save(cart);
    file->save(cart);

    return 0;
}