// Xây dựng lớp khoảng cách có 2 biến: cm, mm, có 1 hàm tạo nhận vào số cm, mm
// 1 cm 12 mm -> 2cm 2mm
// viết toán tử ++ tiền tố hậu tố với ý nghĩa tăng số mm lên 1.

#include<iostream>
using namespace std;

class KhoangCach{
    int cm, mm;
    public:
    KhoangCach(int c, int m){
        int tmp = 10* c + m;
        cm = tmp/10;
        mm = tmp%10;
        }
    KhoangCach operator++ (){
        mm++;
        if(mm == 10){
            cm += 1;
            mm = 0;
        }
        // cm += mm/10;
        // mm %= 10;
        return *this;
    }
    KhoangCach operator++ (int){
        KhoangCach tmp = *this;
        mm++;
        if(mm == 10){
            cm += 1;
            mm = 0;
        }
        return tmp;
    }
    int getcm() const{return cm;}
    int getmm() const{return mm;}
};

int main(){
    KhoangCach k(12,9);
    k++;
    cout << k.getcm() << " " << k.getmm();
}
