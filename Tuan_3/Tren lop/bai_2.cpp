/*
Lớp Room mô tả một phòng có biến tên và diện tích, hàm tạo 2 tham số mặc định tên là phòng khách, 
diện tích 10m vuông, một hàm trả về diện tích

Lớp House mô tả một nhà gồm 4 phòng, hàm tạo có tham số và hàm trả về diện tích cả nhà.
Xác định quan hệ giữa House và Room là kiểu gì?
Cài đặt House, Room, rồi demo bằng tạo ra một ngôi nhà, sau đó in ra diện tích cả nhà
*/

#include<iostream>
using namespace std;

class Room{
    string name;
    double dien_tich;
    public:
        Room(string name = "Phong Khach", double dien_tich= 10){
            name = name;
            dien_tich = dien_tich;
        }
        string getName() const{
            return name;
        }
        double getDien_tich() const{
            return dien_tich;
        }
};

class House{
    Room r1, r2, r3, r4;
    public:
        House(Room r1, Room r2, Room r3, Room r4): r1(r1), r2(r2), r3(r3), r4(r4){};
        double getDientich() const {return r1.getDien_tich()+ r2.getDien_tich()+r3.getDien_tich()+r4.getDien_tich();}
};

int main(){
    Room r1("Phong khach", 10), r2("ngu",5), r3("tho", 7), r4("tam", 6);
    // House nha(r1,,r2,r3,r4);
    // cout << 
    return 0;
}