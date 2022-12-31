// 2. Employee (Bắt buộc)
// Hãy viết 1 lớp có tên là (nhân viên) có các biến thành viên sau:
// : 1 chuỗi ký tự lưu tên của nhân viên.
// : 1 số nguyên lưu số ID của nhân viên (mã nhân viên)
// : 1 chuỗi ký tự lưu tên của phòng ban - nơi nhân viên đó làm việc
// : 1 chuỗi ký tự lưu vị trí làm việc của nhân viên (job title).
// Lớp này phải có các cấu tử (hàm tạo) sau:
// 1 cấu tử cho phép nhập các giá trị sau làm đối số và gán chúng vào các biến thành viên
// thích hợp: tên nhânh viên, ID nhân viên, phòng ban và vị trí.
// 1 cấu tử cho phép nhập các giá trị sau làm đối số và gán chúng vào các biến thành viên
// thích hợp: tên nhânh viên, ID nhân viên. Trường và sẽ được gán
// bởi 1 chuỗi rỗng ("").
// 1 cấu tử mặc định sẽ gán các chuỗi rỗng ("") vào các biến thành viên ,
// , và 0 cho biến thành viên .
// Hãy viết các hàm phù hợp để lưu giá trị của các biến thành viên ở trên và các hàm có thể gán
// hoặc trả về giá trị của chúng (set/get). Sau đó, hãy viết 1 chương trình tạo 3 đối tượng
//  lưu thông tin theo dữ liệu sau:
// Name ID Number Department Position
// Date
// month day year
// day
// month
// Employee
// name
// idNumber
// department
// position
// department position
// name department
// position idNumber
// Employee

#include <iostream>
#include <iomanip>
using namespace std;

class Employee
{
private:
    string name;
    int idNumber;
    string department;
    string position;

public:
    Employee(string Name, int IdNumber, string Department, string Position)
    {
        name = Name;
        idNumber = IdNumber;
        department = Department;
        position = Position;
    }
    Employee(string Name, int IdNuber)
    {
        name = Name;
        idNumber = IdNuber;
        department = "";
        position = "";
    }
    Employee()
    {
        name = "";
        idNumber = 0;
        department = "";
        position = "";
    }
    void setName(string Name)
    {
        name = Name;
    }
    string getName()
    {
        return name;
    }
    void setIdNumber(int IdNumber)
    {
        idNumber = IdNumber;
    }
    int getIdNumber()
    {
        return idNumber;
    }
    void setDepartment(string Department)
    {
        department = Department;
    }
    string getDepartment()
    {
        return department;
    }
    void setPosition(string Position)
    {
        position = Position;
    }
    string getPosition()
    {
        return position;
    }
    void in()
    {
        cout << setw(15) << "Name" << setw(20) << "ID Number" << setw(20) << "Department" << setw(20) << "Position" << endl;
        cout << setfill('-') << setw(75) << "-" << endl;
        cout << setfill(' ') << setw(75) << " " << endl;
    }
    void display()
    {
        cout << setw(15) << name << setw(20) << idNumber << setw(20) << department << setw(20) << position << endl;
    }
};

int main()
{
    Employee n1("Susan Meyers", 47899, "Accounting", "Vice President"), n2("Mark Jones", 39119, "IT", "Programmer"), n3("Joy Rogers", 81774, "Manufacturing", "Engineer");
    n1.in();
    n1.display();
    n2.display();
    n3.display();
    return 0;
}