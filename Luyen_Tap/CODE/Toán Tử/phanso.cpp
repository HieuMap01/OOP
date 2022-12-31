/*
Xây dựng class PhanSo biểu diễn khái niệm phân số trong toán học. 
Class này gồm 2 thuộc tính kiểu số nguyên đại diện cho tử số và mẫu số, một hàm khởi tạo không tham số (gán cả tử và mẫu là 1) và 
một hàm khởi tạo 2 tham số truyền vào giá trị của tử và mẫu.
	1. (1 điểm) quá tải toán tử + và - hai biến PhanSo (kết quả phải là một PhanSo)
	2. (1 điểm) viết một hàm static của class PhanSo tên là "Min", hàm này nhận vào 2 biến kiểu PhanSo và trả lại phân số có 
    giá trị nhỏ hơn

Chú ý: không bắt buộc viết hàm main
*/

#include<iostream>
using namespace std;

class phanso{
    int tu,mau;
    public:
        phanso(int t = 1, int m = 1){
            setAll(t,m);
        }
        void setAll(int t, int m){
            tu = t;
            mau = m;
        }
        phanso & operator+(const phanso &a){ // qua tai +
            phanso t;
            t.tu = tu*a.mau + a.tu*mau;
            t.mau = mau*a.mau;
            return t;
        }
        phanso & operator-(phanso &a){ // qua tai -
            phanso t;
            t.tu = tu*a.mau - a.tu*mau;
            t.mau = mau*a.mau;
            return t;
        }
        static phanso Min(const phanso & a, const phanso & b){
            int temp_1 = a.tu*b.mau;
            int temp_2 = a.mau*b.tu;
            if(temp_1 > temp_2) return a;
            else return b;
        }
};


int main(){
    cout << double(5)/3;
}