/*

Xây dựng class PhanSo biểu diễn khái niệm phân số trong toán học. 
Class này gồm 2 thuộc tính kiểu số nguyên đại diện cho tử số và mẫu số.
	1. (1 điểm) quá tải (overload) toán tử != (trả lại true nếu 2 phân số có cùng giá trị khi 
    quy ra số thập phân, false trong trường hợp ngược lại) và << (in ra dưới định dạng <tử số>/<mẫu số>, 
    ví dụ "2/3") cho class PhanSo
	2. (1 điểm) viết một hàm static của class PhanSo tên là "Max", 
    hàm này nhận vào 2 biến kiểu PhanSo và trả lại phân số có giá trị lớn hơn

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
        bool operator!= (const phanso & r) const { 
            if(tu == r.tu || mau == r.mau)  return true;
            else return false; 
        }
        friend istream & operator>> (istream & in, phanso & r)
        {
            int x, y; 
            in >> x >> y; 
            r.setAll(x,y); 
            return in;   
        }
        friend ostream & operator<< (ostream & out, const phanso & r)
        {
            out << r.tu << "/" << r.mau ;
            return out; 
        }
        static phanso Max(const phanso & a, const phanso & b){
            int temp_1 = a.tu*b.mau;
            int temp_2 = a.mau*b.tu;
            if(temp_1 < temp_2) return a;
            else return b;
        }
};


int main(){
    cout << double(5)/3;
}