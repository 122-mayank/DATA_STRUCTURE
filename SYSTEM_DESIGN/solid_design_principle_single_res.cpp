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

    // 2 . Violating SRP - Prints invoice (Should be in a separate class)
    void printInvoice(){
         cout <<"Shopping cart Invoice:\n";

         for(auto p : products){
             cout << p->name << " -$" << p -> price<< endl;
         }

         cout << "Total: $" << calculateTotal() << endl;
    }

    // 3. Violating SRP - Saves to Db (Should be in a separate class)
    void saveToDatabase(){
         cout <<"Saving Shopping cart to database........"<< endl;
    }
};

int main(){

    ShoppingCart* cart = new ShoppingCart();
    cart -> addProduct(new Product("Laptop" , 1500));
    cart -> addProduct(new Product("Mouse" , 50));

    cart->printInvoice();
    cart->saveToDatabase();


}