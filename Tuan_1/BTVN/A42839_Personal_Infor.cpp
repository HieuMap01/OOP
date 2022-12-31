/*
2.Lớp Personal Infor 
Thiết kế một lớp Personal Infor chứa thông tin cá nhân, gồm các thành viên sau: 
    Tên kiểu chuỗi, địa chỉ kiểu chuỗi, tuổi kiểu nguyên, và số điện thoại kiểu chuỗi. 
    Một setter tổng cập nhật cả 4 biến thành viên
    Một hàm in ra lần lượt cả 4 biến
    Một cấu tử mặc định gán tên, địa chỉ, số điện thoại là rỗng, tuổi là 0,
    1 cấu tử 2 tham số cập nhật tên và tuổi theo tham số nhập vào, còn gán địa chỉvà số điện thoại là rỗng 
    Một cấu tử 4 tham số cập nhật cho cả 4 biến thành viên, 
Hàm main minh hoạ lớp trên bằng cách tạo ra một mảng 3 đối tượng khởi tạo bằng 3 hàm tạo khác nhau. 
Sau đó in ra mọi thông tin của cả3 đối tượng này.
*/

#include<iostream>
using namespace std;

class Personal_Infor{
    string name;
    string address;
    int age;
    string phone_number;
    public:
    void setInfor(string n, string ad, int a, string p){
        name = n;
        address = ad;
        age = a;
        phone_number = p;
    }
    string getname() const {return name;}
    string getaddress() const {return address;}
    int getage() const{return age;}
    string getphone_number() const {return phone_number;} 
    //Một hàm in ra lần lượt cả 4 biến
    void displayPersonInfor(){
        cout <<"Name: "<< getname() << endl
             <<"Address: "<< getaddress() << endl
             <<"Age: "<< getage() << endl
             <<"Phone: "<<getphone_number() << endl << endl;
    }
    //Một cấu tử mặc định gán tên, địa chỉ, số điện thoại là rỗng, tuổi là 0,
    Personal_Infor(){
        name = "";
        address = "";
        age = 0;
        phone_number = "";
    }
    //1 cấu tử 2 tham số cập nhật tên và tuổi theo tham số nhập vào, còn gán địa chỉvà số điện thoại là rỗng 
    Personal_Infor(string n, int a){
        name = n;
        age = a;
        address = "";
        phone_number = "";
    }
    //Một cấu tử 4 tham số cập nhật cho cả 4 biến thành viên,
    Personal_Infor(string n, int a, string ad, string p){
        name = n;
        age = a;
        address = ad;
        phone_number = p;
    }
};
//Hàm main minh hoạ lớp trên bằng cách tạo ra một mảng 3 đối tượng khởi tạo bằng 3 hàm tạo khác nhau. 
//Sau đó in ra mọi thông tin của cả3 đối tượng này.
int main(){
    Personal_Infor p[3];
    p[0] = Personal_Infor();
    p[1] = Personal_Infor("Hieu", 19);
    p[2] = Personal_Infor("Hieu_1", 20, "BG", "012345");
    for(int i = 0; i < 3; i++){ 
        p[i].displayPersonInfor();
    }
    return 0;
}