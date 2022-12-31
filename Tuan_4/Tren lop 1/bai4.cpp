#include<iostream>
using namespace std;

class Cat{

    string name;
    int age;
    float weight;
    public:
        Cat(){ setInfor("Bibi", 1, 2); }
        Cat(string n){ setInfor(n, 1, 2); }
        Cat(string n, int a){ setInfor(n, a, 2); }
        Cat(string n, int a, float w){ setInfor(n, a, w); }
        Cat (const Cat & r) { setInfor (r.name, r.age, r.weight); }
        void setInfor(string n, int a, float w){
            name = n;
            age = a;
            weight = w;
        }
        string getName() const { return name; }
        int getAge() const { return age; }
        float getWeight() const { return weight; }
        void meow() const { cout << "Meow, I am " << name << endl; }
        void print1() const{
            cout << name << " " << age << " " << weight << endl;
        }

};

class ScottishFold: public Cat{
    string kieu_long;
    public:

    ScottishFold(string l){kieu_long = l;}
    // ham tao con co ham tao cha
    ScottishFold(): Cat("Tony",2,2), kieu_long("dai"){}
    ScottishFold(): Cat("Tony",3,5), kieu_long("ngan"){}
    ScottishFold(string l): Cat("Clark Kent",2,2), kieu_long(l){}
    ScottishFold(string l, string n): Cat(n), kieu_long(l){}
    ScottishFold(string l, string n, int a, double w): Cat(n,a,w), kieu_long(l){}
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
    // void print(){
    //     //Cat::printCat();
    //     cout << name << " " << age << " " << weight << endl;
    //     cout<< kieu_long;
    // }
};

int main(){
    
    ScottishFold c("ngan");
    c.setInfor("Tony Stark", 2, 4);
    c.print();

    return 0;
}