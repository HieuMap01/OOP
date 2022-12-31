#include<iostream>
using namespace std;

class Computer{
    string name, color;
    int year;
    int check(int i){
        if(i<0) throw "Loi";
        return i;
    }
    public:
        Computer(string n, string c, int y){
            name = n;
            color = c;
            year = check(y);
        }
        void print() const {
            cout << "Name: " << name << endl;
            cout << "Color: " << color << endl;
            cout << "Nam  SD: " << year << endl;
            int x = 5 * year;
            if(x>100) x=100;
            cout << "Ty le khau hao: " << x << "%\n\n";

        }
        Computer & operator+=(const int & n){
            year+=n;
            if(year < 0) year = 0;
            return *this;
        }

};
int main(){
    Computer C("TUF F15", "Black", 1);
    C.print();
    C+=6;
    C.print();
    return 0;
}