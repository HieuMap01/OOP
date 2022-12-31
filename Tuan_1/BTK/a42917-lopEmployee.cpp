/*3. Lớp Employee
a. Viết lớp Employee có các thành viên:
name: Một chuỗi chỉ tên của nhân viên
idNumber: Một biến int chỉ số ID của nhân viên
department: Một chuỗi chỉ bộ phận nhân viên làm việc
position: Một chuỗi chỉ chức danh của nhân viên
Các setter và getter cho từng biến thành viên trên
Hàm tạo mặc định: sẽ đặt chuỗi rỗng cho name, department, position, và đặt 0 cho idNumber.
Hàm tạo nhận 2 tham số gán cho name và idNumber, đồng thời đặt department,position thành chuỗi rỗng
Hàm tạo nhận 4 tham số gán cho name, idNumber, department, position.
b. Viết hàm main tạo mảng 3 đối tượng Employee như bảng, sau đó in ra thông tin
các đối tượng này
*/
#include<iostream>
#include<iomanip>
using namespace std;
class Employee
{
    string name;
    int idNumber;
    string department;
    string position;
public:
    void setName(string n) {name=n;}
    void setIdNumber(int i) {idNumber=i;}
    void setDepartment(string d) {department=d;}
    void setPosition(string p) {position=p;}
    string getName()const {return name;}
    int getIdNumber()const  {return idNumber;}
    string getDepartment()const {return department;}
    string getPosition()const {return position;}
};
int main()
{
    Employee e1;
    e1.setName("Susan Meyers");
    e1.setIdNumber(47899);
    e1.setDepartment("Accounting");
    e1.setPosition("Vice President");
    cout<<"Name"<<setw(20)<<"ID Number"<<setw(20)<<"Department"<<setw(20)<<"Position"<<endl;
    cout<<e1.getName()<<setw(9)<<e1.getIdNumber()<<setw(24)<<e1.getDepartment()<<setw(26)<<e1.getPosition()<<endl;
    return 0;
}
