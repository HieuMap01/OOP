/*
a)Giả  định mọi biến thành viên lớp cha là private, lớp con tuỳ ý protected hay private 
Viết lớp Ship (tàu thủy)có:•Tên contàu
                            •Năm xuấtxưởng
                            •Một hàm khởi tạo và các hàm set/get
                            •Một hàm ảo tên là print để in ra tên con tàu
Viết classCruiseShip(tàuđulịch) kế thừa từ class Shipcó:
    •Số hành khách tối đa
    •Một hàm khởi tạo và các hàmset/get
    •Hàm print ghi đè(override)hàm print của lớp cha in ra tên con tàu và số hành khách 
Viết lớp CargoShip (tàu hàng) kế thừa class Shipcó:
    •Số tấn hàng chở được
    •Một hàm khởi tạo và các hàmset/get
    •Hàm print ghi đè (override)hàm print của lớp cha in ra tên con tàu và số hàng chở được 
    Sử dụng 3 lớp trên trong một chương trình minh họa đơn giản 
    b)Làm tương tự câu a) nhưng đổi các biến thành viên thành protected
*/
// #include<iostream>
// #include<math.h>
// using namespace std;
// class Ship {
//     string ten; 
//     int nam;
//     public:
//         void setTen ( string ten){ this -> ten=ten; }
//         void setNam( int nam){ this -> nam=nam; }
//         string getTen() const{ return ten; }
//         int getNam() const{ return nam; }
//         virtual void print ()const {
//             cout<<"Ten con tau : "<<ten<<endl<<"Nam : "<<nam<<endl;
//         }
// };

// class CruiseShip : public Ship{
//     int khach;
//     public:
//         void setKhach(int khach){ this -> khach =khach;}
//         int getKhach() const { return khach ;}
//         void print(){
//             Ship::print();
//             cout<<"So hanh khach :"<<khach<<endl;
//         }
// };

// class CargoShip: public Ship{
//     int hang;
//     public:
//         void setHang(int hang){ this -> hang =hang;}
//         int getHang() const { return hang ;}
//         void print(){
//             Ship::print();
//             cout<<"So hang hoa :"<<hang<<endl;
//         }
// };
// int main(){
//     CruiseShip p1 ;
//     p1.setTen("ABC");
//     p1.setNam(2000);
//     p1.setKhach(40);
//     p1.print();
//     CargoShip p2;
//     p2.setTen("XYZ");
//     p2.setNam(2003);
//     p2.setHang(1000);
//     p2.print();
//     return 0;
// }


#include<iostream>
#include<math.h>
using namespace std;
class Ship {
    protected:
        string ten; 
        int nam;
    public:
        void setTen ( string ten){ this -> ten=ten; }
        void setNam( int nam){ this -> nam=nam; }
        string getTen() const{ return ten; }
        int getNam() const{ return nam; }
        virtual void print ()const {
            cout<<"Ten con tau : "<<ten<<endl<<"Nam : "<<nam<<endl;
        }
};

class CruiseShip : public Ship{
    protected:
        int khach;
    public:
        void setKhach(int khach){ this -> khach =khach;}
        int getKhach() const { return khach ;}
        void print(){
            Ship::print();
            cout<<"So hanh khach :"<<khach<<endl;
        }
};

class CargoShip: public Ship{
    protected:
        int hang;
    public:
        void setHang(int hang){ this -> hang =hang;}
        int getHang() const { return hang ;}
        void print(){
            Ship::print();
            cout<<"So hang hoa :"<<hang<<endl;
        }
};
int main(){
    CruiseShip p1 ;
    p1.setTen("ABC");
    p1.setNam(2000);
    p1.setKhach(40);
    p1.print();
    CargoShip p2;
    p2.setTen("XYZ");
    p2.setNam(2003);
    p2.setHang(1000);
    p2.print();
    return 0;
}