#include<iostream>
using namespace std;

class vanchuyen{
    string kieuVC, mathang, congty;
    double tien;
    virtual double tinhtien() const = 0;
    protected:
        void khoitao(string kvc, string mh, string ct){
            kieuVC = kvc;
            mathang = mh;
            congty = ct;
        }
        void CapNhatTien(){
            tien = tinhtien();
        }
    public:
        virtual void hienthi() const {
            cout << kieuVC << " " << mathang << " " << congty << " "  << tien << endl ;
        }
        virtual ~vanchuyen(){}
};
class vanchuyenDuongBo: public vanchuyen{
    double quangduong, cannang;
    double tinhtien()const{
        if(quangduong < 5){
            return quangduong * 10.0 * cannang;
        }
        else
            return quangduong * 10.0 * cannang * 1.5;
    }
    public:
    vanchuyenDuongBo(string mh, string ct, double qd, double cn){
        khoitao("Van chuyen duong bo", mh, ct);
        quangduong = qd;
        cannang = cn;
        CapNhatTien();
    }
    void hienthi() const {
        vanchuyen :: hienthi();
        cout << quangduong << " " << cannang << endl;
    }
};
class vanchuyenHangKhong: public vanchuyen{
    double quangduong, giatri;
    double tinhtien()const{
        return quangduong * 10.0 * giatri * 0.1;
    }
    public:
    vanchuyenHangKhong(string mh, string ct, double qd, double gt){
        khoitao("Van chuyen Hang Khong", mh, ct);
        quangduong = qd;
        giatri = gt;
        CapNhatTien();
    }
    void hienthi() const {
        vanchuyen :: hienthi();
        cout << quangduong << " " << giatri << endl;
    }
};

int main(){
    int n = 5;
    vanchuyen *a[] = {new vanchuyenDuongBo("da","hoa toc",100, 12),
                        new vanchuyenDuongBo("thuoc","toc hanh",3, 16),
                        new vanchuyenDuongBo("a","b",50, 3),
                        new vanchuyenHangKhong("da","hoa toc",100, 1200),
                        new vanchuyenHangKhong("thuoc","hoa toc",6, 1250)};
    for(int i = 0; i < n; i++){
        a[i]->hienthi();
    }
    return 0;
}