/*Hinh3D & HinhHop & HinhCau
Cho lớp trừu tượng Hinh3D, gồm các thành viên:
Các thuộc tính private: thể tích, màu sắc
Hàm ảo thuần tuý tinhThetich nhằm tính thể tích, sẽ được cài ở lớp con
Hàm setInfor thiết lập giá trị cho mọi thuộc tính cần thiết
Hàm ảo print in ra thể tích, màu sắc
Lớp  HinhHop kế thừa Hinh3D, có:
Các thuộc tính private: 3 cạnh a, b, c
override hàm tinhThetich để trả về thể tích hình hộp là a * b * c
Hàm setInfor thiết lập giá trị cho mọi thuộc tính cần thiết
override hàm print in ra ba cạnh, thể tích, màu sắc.
Lớp HinhCau kế thừa Hinh3D, có:
Các thuộc tính private: bán kính r
override hàm tinhThetich để trả về thể tích hình cầu là 4/3* pi * r * r * r với pi = 3.14
Hàm setInfor thiết lập giá trị cho mọi thuộc tính cần thiết
override hàm print in ra bán kính r, thể tích, màu sắc.
Viết hàm main tạo một mảng 10 Hinh3D, có cả HinhHop hay HinhCau, cuối cùng in ra thông tin cả mảng.
*/
#include<iostream>
using namespace std;
class Hinh3D
{
    double volume;
    string color;
    virtual double calcVolume() const = 0;
protected:
    void setInfor(string c){
        volume = calcVolume();
        color=c;
    }
public:
    double getVolume() const{return volume;}
    string getColor() const{return color;}
    virtual void print()const
    {
        cout << "The tich: "<< volume << endl << "Mau Sac: "<< color << endl;
    }
    virtual ~Hinh3D(){}
};

class HinhHop:public Hinh3D
{
    double a,b,c;
    double caclVolume()const {return a*b*c;}
public:
    void setInfor(double a,double b,double c,string co)
    {
        this->a=a;
        this->b=b;
        this->c=c;
        Hinh3D::setInfor(co);
    }
    HinhHop(double a,double b,double c,string co){setInfor(a,b,c,co);}
    double getA() const {return a;}
    double getB() const {return b;}
    double getB() const {return c;}
    virtual void print ()const{
        Hinh3D::print();
        cout<<a<<endl<<b<<endl<<c<<endl;
    }
};

class HinhCau: public Hinh3D
{
    double r;
    double caclVolume()const {return 3.14*4/3*r*r*r;}
public:
    void setInfor(double r1,string c)
    {
        this->r=r1;
        Hinh3D::setInfor(c);
    }
    HinhCau(double r1,string c){setInfor(r1,c);}
    double getR() const{return r;}
    virtual void print ()const{
        Hinh3D::print();
        cout<<r<<endl;
    }
};

int main()
{
    int n=2;
    //Hinh3D *a[]={new HinhHop(3,4,5,"Red"),new HinhCau(2,"Vang")};
    // for(int i=0;i<n;i++){
    //     a[i]->print();
    // }
    return 0;
}



