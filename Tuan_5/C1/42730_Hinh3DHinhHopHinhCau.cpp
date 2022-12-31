/*
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
#include<math.h>
using namespace std;
class Hinh3D{
    float volume;
    string color;
    virtual float TheTich() const = 0;
    protected: 
        void setInfor(string c=""){
            volume =TheTich();
            this-> color=c;
        }
        public:
        virtual void print() const{
            cout<<"The tich : "<<volume <<endl<<"Mau sac : "<<color<<endl;
        }
        virtual ~ Hinh3D() {}
}; 
class HinhHop: public Hinh3D{
    float a,b,c ; 
    float TheTich() const {return a*b*c; } 
    
    public: 
        HinhHop (float x, float y, float r ,string color) { setInfor(x,y,r,color); }
        void setInfor(float x, float y, float r,string color){
            a = x; 
            b = y; 
            c = r;
            Hinh3D::setInfor(color); 
        }
        void print() const{
            Hinh3D::print();
            cout<<"Cac canh cua hinh hcn : "<<a<<" "<<b<<" "<<c<<endl;
        }
}; 
const float pi=3.14;
class HinhCau: public Hinh3D{
    float radius;
    protected:
        float TheTich() const {return 4/3* pi*radius*radius*radius; } 
    public:
        void setInfor(float r ,string color){
            Hinh3D::setInfor(color); 
            this-> radius=r;
        }
    HinhCau(float r,string color){ setInfor(r,color);}
    void print() const{
        Hinh3D::print();
        cout<<"Banh kinh : "<<radius;
    }
};
int main(){
   int n=2;
    Hinh3D * r[]={ new HinhHop(2,4,5,"Do"),new HinhCau(2,"xanh")};
    for(int i=0;i<n;i++){
        r[i]->print();
    }
    return 0;
}