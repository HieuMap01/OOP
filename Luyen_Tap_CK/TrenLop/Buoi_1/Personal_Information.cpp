/*
4. Personal Information 
Thiết kế 1 lớp có thể lưu các dữ liệu cá nhân như: tên, địa chỉ, tuổi, và số điện thoại. Viết các 
hàm gán và trả về (set/get) phù hợp. Hãy viết chương trình sử dụng lớp này để tạo 3 hồ sơ. 
Một hồ sơ lưu thông tin của bạn, 2 hồ sơ còn lại lưu thông tin của bạn bè hay gia đình của bạn. 

*/


#include <iostream>
using namespace std;

class PersonalInfor{
    string name, address, phone;
    int age;
public:
    // setter tổng
    void setInfor(string n, string ad, string p, int ag){
        name = n;
        address = ad;
        phone = p;
        age = ag;
    }
    
    // Hàm tạo mặc định
    PersonalInfor(){ 
        setInfor("", "", "", 0);
    }

    // Hàm tạo 2 tham số
    PersonalInfor(string name, int age){ 
        setInfor(name, "", "", age);
    }

    // Hàm tạo 4 tham số
    PersonalInfor(string name, string ad, string phone, int age){
        setInfor(name, ad, phone, age);
    }

    // hàm in ra cả 4 biến
    void print() const{
        cout << "Ten: " << name << endl
             << "Dia chi: " << address << endl 
             << "Tuoi: " << age << endl  
             << "Dien thoai: " << phone << endl; 
    }  
};

int main(){
    const int n = 3;
    PersonalInfor a[n] = {  PersonalInfor("A", "So 1 pho A", "012345678",20),
                            PersonalInfor("B",  21), 
                            PersonalInfor() }; // nếu bỏ phần này, C++ cũng tự điền phần thiếu bằng hàm tạo mặc định
    
    for(int i = 0; i < n; i++) 
        a[i].print();
    return 0;
}