#include<iostream>
using namespace std;

class Forum{
    string name, hang;
    virtual string rank() const = 0;
    protected:
        void setInfor(string n){
            name = n;
            hang = rank();
        }
    public:
        virtual void print() const{
            cout << "Ten: " << name << endl 
                 << "Hang: " << hang << endl;
        }
};

class ForumTinhTe : public Forum{
    int year_GN, year_HT;
    string rank() const {
        if(year_HT - year_GN > 3){
            return "Vang";
        }
        else {
            return "Thuong";
        }
    }
    public:
        void setInfor(string n, int GN, int HT){
            year_GN = GN;
            year_HT = HT;
            Forum::setInfor(n);
        }
        ForumTinhTe(string n = "", int GN=0, int HT=0){
            setInfor(n,GN,HT);
        }
        void print() const {
            Forum::print();
            cout << "Nam gia nhap: " << year_GN<< endl;
            cout << "Nam hien tai: " << year_HT<< endl;
        }
}; 

int main(){
    Forum *F[] = {new ForumTinhTe("Hieu",2020,2025), new ForumTinhTe("Ha", 2020,2021)};
    for(int i = 0; i < 2; i++){
        F[i]->print();
    }
    return 0;
}