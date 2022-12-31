/*
Viết lớp Employee có các thành viên:
name: Một chuỗi chỉ tên của nhân viên
idNumber: Một biến int chỉ số ID của nhân viên
department: Một chuỗi chỉ bộ phận nhân viên làm việc
position:. Một chuỗi chỉ chức danh của nhân viên
Các hàm setter và getter cho từng biến thành viên trên
Hàm tạo mặc định: sẽ đặt chuỗi rỗng cho name, department, position, và đặt 0 cho idNumber.
Hàm tạo nhận 2 tham số gán cho name và idNumber, đồng thời đặt department, positionthành chuỗi rỗng
Hàm tạo nhận 4 tham số gán cho name, idNumber, department, position.
b.Viết hàm main tạo mảng 3 đối tượng Employeenhư bảng, sau đó in ra thông tin các đối tượng này
*/
#include<iostream>
#include<iomanip>
using namespace std;

class Employee{
    string name;
    int idNumber;
    string department;
    string position;
    public:
        void setname(string n){ name = n;}
        void setidNumber(int i){idNumber = i;}
        void setdepartment(string d){department = d;}
        void setposition(string p){position = p;}
        string getname() const{return name;}
        int getidNumber() const{return idNumber;}
        string getdepartment() const{return department;}
        string getposotion() const{return position;}
    
        Employee()
        {
            name = "";
            idNumber = 0;
            department = "";
            position = "";
        }

        Employee(string Name, int IdNuber)
        {
            name = Name;
            idNumber = IdNuber;
            department = "";
            position = "";
        }

        Employee(string Name, int IdNumber, string Department, string Position)
        {
            name = Name;
            idNumber = IdNumber;
            department = Department;
            position = Position;
        }
};
const int l = 20;
void save(Employee &e, string n, int id, string d, string p){
    e.setname(n);
    e.setidNumber(id);
    e.setdepartment(d);
    e.setposition(p);
}

void input(const Employee &e){
    cout << left << setw(l) << e.getname() << setw(l) << e.getidNumber() << setw(l) << e.getdepartment()
                 << setw(l) << e.getposotion() << endl;
}

int main(){
    Employee susan, mark, joy;
    save(susan, "Susan Meyers", 47899, "Accounting", "Vice President");
    save(mark, "Mark Jones", 39119, "IT", "Programmer");
    save(joy, "Joy Rogers", 81774, "Manufacturing", "Engineer");
    cout << left << setw(l) << "Name" << setw(l) << "ID Number"
                 << setw(l) << "Department" << setw(l) << "Position" <<endl;
    input(susan);
    input(mark);
    input(joy);
    return 0;
}