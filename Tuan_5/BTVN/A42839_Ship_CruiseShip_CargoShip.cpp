/*
1.Ship& CruiseShip & CargoShipa)
Giả định mọi biến thành viên lớp cha là private, 
lớp con tuỳ ý protected hay private Viết lớp Ship (tàu thủy) có:
    • Tên contàu
    • Năm xuấtxưởng
    • Một hàm khởi tạo và các hàm set/get
    • Mộthàm ảo tên là print để in ra tên con tàu 
Viết classCruiseShip (tàuđulịch) kế thừa từ class Ship có:
    • Số hành khách tốiđa
    • Một hàm khởi tạo và các hàmset/get
    • Hàmprintghiđè(override) 
    hàm print của lớp cha in ra tên con tàu và số hành khách 
Viết lớp CargoShip (tàu hàng) kế thừa class Shipcó:
    • Số tấn hàng chởđược•Một hàm khởi tạo và các hàmset/get
    • Hàm print ghi đè(override)hàm print của lớp cha in ra tên con tàu và số hàng chở được 
    Sử dụng 3 lớp trên trong một chương trình minh họa đơn giản
b)Làm tương tự câu a) nhưng đổi các biến thành viên thành protected Hàm thuần ảo và tính đa hình
*/


// #include<iostream>
// using namespace std;

// class Ship{
//     string name;
//     int year;
//     public:
//         Ship(string n="", int y=0){
//             setInfor(n,y);
//         }
//         void setInfor(string n, int y){
//             name = n;
//             year = y;
//         }
//         string getName() const{return name;}
//         int getYear() const {return year;}
//         virtual void print() const {
//             cout <<"Ten con tau: " << getName() << endl ;
//         }
// };

// class CruiseShip: public Ship{
//     int so_hk;
//     public:
//         CruiseShip(string n="",int y=0, int s = 0):Ship(n,y),so_hk(s){}
//         // void setSohk(int s){
//         //     so_hk = s;
//         // }
//         int getSohk() const{
//             return so_hk;
//         }
//         void print() const {
//             Ship :: print();
//             cout << "So hanh khach: " << so_hk << endl;
//         }
// };

// class CargoShip: public Ship{
//     int so_t;
//     public:
//         CargoShip(string n="",int y=0, int s = 0):Ship(n,y),so_t(s){}
//         // void setSot(int s){
//         //     so_t = s;
//         // }
//         int getSot() const{
//             return so_t;
//         }
//         void print() const {
//             Ship :: print();
//             cout << "So tan hang: " << so_t << endl;
//         }
// };

// int main(){
//     Ship *s[] = {new CruiseShip("ABC", 1999, 250), new CargoShip("DEF", 1957, 100)};
//     s[0]->print();
//     s[1]->print();
//     return 0;
// }


//___________B____________

#include<iostream>
using namespace std;

class Ship{
    protected:
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

class CruiseShip: public Ship{
    protected:
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

class CargoShip: public Ship{
    protected:
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
    Ship *s[] = {new CruiseShip("ABC", 1999, 250), new CargoShip("DEF", 1957, 100)};
    s[0]->print();
    s[1]->print();
    return 0;
}
