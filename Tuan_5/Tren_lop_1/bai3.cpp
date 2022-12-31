#include <iostream> 
using namespace std; 

class Animal{
    string name; 
public: 
    Animal(string name = ""): name(name){}
    virtual void speak() const { cout << " Toi la " << name << endl; }
}; 

class Cat: public Animal{
public: 
    Cat(string name = ""): Animal(name){}
    void speak() const {
        cout << "Meow, "; 
        Animal::speak (); 
    }
}; 

class Dog: public Animal{
public: 
    Dog(string name = ""): Animal(name){}
    void speak() const {
        cout << "Woff, "; 
        Animal::speak (); 
    }
}; 

class Duck: public Animal{
public: 
   Duck(string name = ""): Animal(name){}
    void speak() const {
        cout << "Quack, "; 
        Animal::speak (); 
    } 
}; 

int main(){
    // câu a
    // Cat c("Bibi"); 
    // Dog d ("Toto"); 
    // Duck ch ("Chichi"); 
    // c.speak(); 
    // d.speak(); 
    // ch.speak(); 

    // câu b
    // Animal & o1 = c, & o2 = d, & o3 = ch; 
    // o1->speak(); 
    // o2->speak(); 
    // o3->speak();

    // câu c
    Animal  * o1 = new Cat ("Mi"), 
            * o2 = new Dog ("Vang"), 
            * o3 = new Duck("Ken"); 
    o1->speak(); 
    o2->speak(); 
    o3->speak(); 

    // câu d
    // Animal * a[6] = {new Cat ("Bibi"),new Cat ("Toto"),new Cat ("Mimi"),
    //                  new Dog ("Vang"), new Dog ("Xam"), new Duck("Kiki")}; 
    // for (int i = 0; i<6; i++){
    //     a[i]->speak(); 
    // }

    return 0; 
}