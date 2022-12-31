// Xây dựng lớp khoảng cách có 2 biến: cm, mm, có 1 hàm tạo nhận vào số cm, mm

#include <iostream>
#include <fstream>
using namespace std;

class KhoangCach{
    int cm, mm;
    void change(int c, int m){
    int tmp = 10* c + m;
    cm = tmp/10;
    mm = tmp%10;
    }
    public:
        KhoangCach(int c = 0, int m = 0){
            change(c,m);
        }
    //Nạp chồng các toán tử sau cho lớp Khoảng cách:
    //>> một khoảng cách: sẽ vớt từ dòng nhập 2 số nguyên để gán cho cm, mm
    friend istream & operator>> (istream & in, KhoangCach & r){
        in >> r.mm >> r.cm;
        r.change(r.cm,r.mm);
        return in;
    }
    // << một khoảng cách: sẽ in ra số cm, mm của khoảng cách đó
    friend ostream & operator>> (ostream & out, KhoangCach & r){
        out << r.cm << "cm\n";
        out << r.mm << "mm";
        return out;
    }
};

int main(){
    KhoangCach k;
    cout << "Nhap lan luot mm cm: ";
    cin >> k;
}