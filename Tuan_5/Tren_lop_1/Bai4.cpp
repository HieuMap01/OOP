/*
a. Các biến lớp cha đều để private
Viết lớp Ship (tàu thủy) có:
Tên con tàu
Năm xuất xưởng
Một hàm khởi tạo và các hàm set/get
Một hàm ảo tên là print để in ra tên con tàu

Viết chương trình minh họa đơn giản 3 lớp trên
*/

#include<iostream>
using namespace std;

class Ship{
    string name;
    int year;
    public:
        Ship(string n="", int y=0){
            setInfor(n,y);
        }
        void setInfor(string n, int y){
            name = n;
            year = y;
        }
        string getName() const{return name;}
        int getYear() const {return year;}
        virtual void print() const {
            cout <<"Ten con tau: " << getName() << endl ;
        }
};

/*
Viết class CruiseShip (tàu đu lịch) kế thừa từ class Ship có:
Số hành khách tối đa
Một hàm khởi tạo và các hàm set/get
Hàm print ghi đè (override) hàm print của lớp cha in ra tên con tàu và số hành khách
*/

class CruiseShip: public Ship{
    int so_hk;
    public:
        CruiseShip(string n="",int y=0, int s = 0):Ship(n,y),so_hk(s){}
        // void setSohk(int s){
        //     so_hk = s;
        // }
        int getSohk() const{
            return so_hk;
        }
        void print() const {
            Ship :: print();
            cout << "So hanh khach: " << so_hk << endl;
        }
};

/*
Viết lớp CargoShip (tàu hàng) kế thừa class Ship có:
Số tấn hàng chở được
Một hàm khởi tạo và các hàm set/get
Hàm print ghi đè (override)  hàm print của lớp cha in ra tên con tàu và số hàng chở được
*/

class CargoShip: public Ship{
    int so_t;
    public:
        CargoShip(string n="",int y=0, int s = 0):Ship(n,y),so_t(s){}
        // void setSot(int s){
        //     so_t = s;
        // }
        int getSot() const{
            return so_t;
        }
        void print() const {
            Ship :: print();
            cout << "So tan hang: " << so_t << endl;
        }
};

int main(){
    Ship *s = new CruiseShip("ABC", 1999, 250);
    Ship *s1 = new CargoShip("DEF", 1957, 100);
    s->print();
    s1->print();
    delete s;
    delete s1;
    return 0;
}
