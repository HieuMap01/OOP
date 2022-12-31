// Viết lớp Employee có các thành viên:
// name: Một chuỗi chỉ tên của nhân viên
// idNumber: Một biến int chỉ số ID của nhân viên
// department: Một chuỗi chỉ bộ phận nhân viên làm việc
// position:. Một chuỗi chỉ chức danh của nhân viên
// Các hàm setter và getter cho từng biến thành viên trên
// Viết hàm main tạo ra 1 đối tượng Employee như dòng đầu bảng (Susan Meyers) , 
// sau đó in ra thông tin đối tượng này

#include<iostream>
using namespace std;

class Employee{
    string name;
    int idNumber;
    string department;
    string position;
    public:
    // void setInfor(string n, int i, string d, string p){
    //     name = n;
    //     idNumber = i;
    //     department = d;
    //     position = p;
    // }
    void setname(string n){
        name = n;
    }

    void setidNumber(int i){
        idNumber = i;
    }

    void setdeparment( string d){
        department = d;
    }

    void setposition( string p){
        position = p;
    }
    
    string getname() const {
        return name;
    }
    int getidNumber() const {
        return idNumber;
    }
    string getdepartment() const {
        return department;
    }
    string getposition() const {
        return position;
    }
};

int main(){
    Employee k;
    k.setname("Susan Meyers");
    k.setidNumber(47899);
    k.setdeparment("Accounting");
    k.setposition("Vice president");
    cout << k.getname() << " " << k.getidNumber() << " " << k.getdepartment() << " " << k.getposition() << endl;
    return 0;
}