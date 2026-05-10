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
// 1 . Only responsible for the calculating the price
class ShoppingCart{

    private:
    vector<Product*> products;

    public:
    void addProduct(Product *p){
          products.push_back(p);
    }

    const vector<Product*>& getProducts(){
        return products;
    }

    // 1 . Calculate the total price in cart
    double calculateTotal(){
        
        double total = 0;
        for(auto p: products){
             total = total + p ->price;
        }
        return total;
    }
};

// 2. ShoppingCartPartner : Only responsible for thep printing of invoice
class ShoppingCartPrinter{

    private:
    ShoppingCart* cart;

    public:

    ShoppingCartPrinter(ShoppingCart* cart){
         this -> cart = cart;
    }
   
    void printInvoice(){
         cout <<"Shopping cart Invoice:\n";

         for(auto p :cart->getProducts()){
             cout << p->name << " -$" << p -> price<< endl;
         }

         cout << "Total: $" << cart -> calculateTotal() << endl;
    }
};

// 3 . ShoppingCartStorage: only responsible for the storage in database
class ShoppingCartStorage{

    private:
    ShoppingCart* cart;

    public:
    ShoppingCartStorage(ShoppingCart* cart){
         this -> cart = cart;
    }

    void saveToSQLDatabase(){
         cout <<"Saving Shopping cart to SQL database........"<< endl;
    }

    void saveToMongoDB(){
          cout <<"Saving Shopping cart to MongoDb database........"<< endl;
    }

     void saveToFile(){
          cout <<"Saving Shopping cart to File database........"<< endl;
    }
};

int main(){

    ShoppingCart* cart = new ShoppingCart();
    cart -> addProduct(new Product("Laptop" , 1500));
    cart -> addProduct(new Product("Mouse" , 50));
    
    ShoppingCartPrinter* printer = new ShoppingCartPrinter(cart);
    printer -> printInvoice();

    ShoppingCartStorage* storage = new ShoppingCartStorage(cart);
    storage ->saveToSQLDatabase();

    return 0;
}