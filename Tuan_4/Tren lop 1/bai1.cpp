#include<iostream>
using namespace std;

class Cat{
    protected:
    string name;
    int age;
    float weight;
    public:
        void setInfor(string n, int a, float w){
        name = n;
        age = a;
        weight = w;
        }
        string getName()const { return name; }
        int getAge() const { return age; }
        float getWeight()const { return weight;}
        void meow() const
        { cout << "Meow, I am " << name << endl;}
        // cach 1
        // void printCat(){
        //     cout << name << " " << age << " " << weight << endl;
        // }
};

class ScottishFold: public Cat{
    string kieu_long;
    public:
    ScottishFold(string l){kieu_long = l;}
    void setKieu_long(string k){
        this->kieu_long = k;
    }
    string getKieu_long() const {
        return kieu_long;
    }
    void doBuddhaPose(){
        cout << "Purr, I am doing a Buddha Pose!";
    }
    // cach 1
    void print(){
        //Cat::printCat();
        cout << name << " " << age << " " << weight << endl;
        cout<< kieu_long;
    }
};

int main(){
    
    ScottishFold c("ngan");
    c.setInfor("Tony Stark", 2, 4);
    c.print();

    return 0;
}