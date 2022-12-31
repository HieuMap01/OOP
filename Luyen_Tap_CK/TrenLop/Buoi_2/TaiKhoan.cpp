#include<iostream>
#include<math.h>
using namespace std;

class TaiKhoan{
    double tien_bd;
    int thoihan;
    double laisuat;
    double check(double i){
        if(i<0) throw "Loi";
        return i;
    }
    public:
    TaiKhoan(double t, int th, double ls){
        if(th<0) throw "loi";
        tien_bd = check(t);
        thoihan = th;
        laisuat = check(ls);
    }
    void print() const{
        cout << tien_bd << " " << thoihan << " " << laisuat << endl;
        cout << "So tien du tinh nhan duoc: " << tien_bd*pow(1 + laisuat/100.0, thoihan) << "$\n\n";
    }
    TaiKhoan & operator+=(int i){
        thoihan += i;
        return *this;   
    }
};

int main(){
    TaiKhoan T(12.343,20,6);
    T.print();
    T+=5;
    T.print();
    return 0;
}