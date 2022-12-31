/*
Cho lớp trừu tượng Hinh3D, gồm các thành viên: 
    Các thuộc tính private: thể tích, màu sắc
    Hàm ảo thuần tuý tinhThetich nhằm tính thể tích, sẽ được cài ở lớp con
    Hàm setInfor thiết lập giá trị cho mọi thuộc tính cần thiết
    Hàm ảo print in ra thể tích, màu sắc
Lớp HinhCau kế thừa Hinh3D, có:
    Các thuộc tính private: bán kính r
    override hàm tinhThetich để trả về thể tích hình cầu là 4/3* pi * r * r * r với pi = 3.14
    Hàm setInfor thiết lập giá trị cho mọi thuộc tính cần thiết
    override hàm print in ra bán kính r, thể tích, màu sắc.
Viết hàm main tạo một mảng 10 Hinh3D, có cả HinhHop hay HinhCau, cuối cùng in ra thông tin cả mảng.
*/
#include<iostream>
using namespace std;

class Hinh3D{
    double the_tich;
    string color;
    virtual double Tinhthetich() const = 0;
    protected:
        void SetALL(string color){
            the_tich = Tinhthetich();
            this->color = color;
        }
    public:
        virtual void print() const{
            cout << "The tich: " << the_tich << endl << "Mau sac: " << color << endl;
        }
        virtual ~ Hinh3D() {}
};
/*Lớp  HinhHop kế thừa Hinh3D, có:
    Các thuộc tính private: 3 cạnh a, b, c
    override hàm tinhThetich để trả về thể tích hình hộp là a * b * c
    Hàm setInfor thiết lập giá trị cho mọi thuộc tính cần thiết
    override hàm print in ra ba cạnh, thể tích, màu sắc.
*/
class HinhHop: public Hinh3D{
    double a, b, c;
    double Tinhthetich()const{return a*b*c;}
    public:
        void setALL(string color, double a, double b, double c){
            this-> a = a;
            this-> b = b;
            this-> c = c;
            Hinh3D::SetALL(color);
        }
        HinhHop(string color, double a, double b, double c){setALL(color, a, b, c);}
        void print() const{
            Hinh3D::print();
            cout << "Do dai 3 cach: " << a << " " << b << " " << c << endl;
        }
        
};
class HinhCau: public Hinh3D{
    double r;
    double Tinhthetich()const{return ((4/3)*(3.14*r*r*r));}
    public:
        void setALL(string color, double r){
            this-> r = r;
            Hinh3D::SetALL(color);
        }
        HinhCau(string color, double r){setALL(color, r);}
        void print() const{
            Hinh3D::print();
            cout << "Ban kinh " << r<< endl;
        }
};

int main(){
    int n=2;
    Hinh3D * r[]={ new HinhHop("red",2,3,4),new HinhCau("blue",5)};
    for(int i=0;i<n;i++){
        r[i]->print();
    }
    return 0;
}