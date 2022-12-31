#include<iostream>
using namespace std;

class cat{
    string name;
    int age;
    float weight;

    public:
    void setname();
    void setage();
    void setweight();

    string getname() const;
    int getage() const;
    float getweight() const;

    void meow();
    int chaseMouse(int); 
};

int main(){
    return 0;
}