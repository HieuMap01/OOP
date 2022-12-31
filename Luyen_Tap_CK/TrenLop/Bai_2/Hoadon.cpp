#include<iostream>
using namespace std;

class Hoadon{
    string hoadon, benban, benmua;
    float sotien;
    virtual float tinhtien() const = 0;
    protected: 
        void khoitao(string hd, string bb, string bm){
            hoadon = hd;
            benban = bb;
            benmua = bm;
        }
        void capNhattien(){
                sotien = tinhtien();
            }
    public: 
        virtual void print() const{
            cout <<"Hoa don: "<< hoadon << "\nBen Ban: " << benban << "\nBen mua: " << benmua << "\nSo tien: " << sotien << endl;
        }
        virtual ~ Hoadon(){}
};

class HoaDonNuoc : public Hoadon{
    int thang;
    float sonuoc, dongia;
    float tinhtien()const{
        return sonuoc*dongia;
    }
    public: 
    HoaDonNuoc(string bb, string bm, int t, float sn, float dg){
        Hoadon::khoitao("Hoa don nuoc", bb, bm);
        thang = t;
        sonuoc = sn;
        dongia = dg;
        Hoadon::capNhattien();
    }
    void print() const{
        cout <<"Thang: "<< thang  << endl;
        Hoadon::print();
        cout << "So nuoc: " << sonuoc <<"\nDon gia: "<<  dongia << endl;
    }

};

class HoaDonNetflix : public Hoadon{
    int thang;
    float dongia;
    float tinhtien()const{
        return thang*dongia;
    }
    public: 
    HoaDonNetflix(string bb, string bm, int t, float dg){
        Hoadon::khoitao("Hoa don Netflix", bb, bm);
        thang = t;
        dongia = dg;
        Hoadon::capNhattien();
    }
    void print() const{
        Hoadon::print();
        cout << "Thang: " << thang   <<"\nDon gia: "<<  dongia << endl;
    }

};
int main(){
    int n = 5;
    Hoadon *h[n] = {new HoaDonNuoc("a","b",1,2,3),
                    new HoaDonNuoc("c","f",3,2,3),
                    new HoaDonNuoc("g","e",6,2,3),
                    new HoaDonNetflix("s","a",5,7),
                    new HoaDonNetflix("u","a",5,10)};
    for(int i = 0; i<n; i++){
        cout << i << endl;
        h[i]->print();
    }
    return 0;
}