/*
2. Employee (Bắt buộc) 
Hãy viết 1 lớp có tên là (nhân viên) có các biến thành viên sau: 
: 1 chuỗi ký tự lưu tên của nhân viên. 
: 1 số nguyên lưu số ID của nhân viên (mã nhân viên) 
: 1 chuỗi ký tự lưu tên của phòng ban - nơi nhân viên đó làm việc 
: 1 chuỗi ký tự lưu vị trí làm việc của nhân viên (job title). 
Lớp này phải có các cấu tử (hàm tạo) sau: 
1 cấu tử cho phép nhập các giá trị sau làm đối số và gán chúng vào các biến thành viên 
thích hợp: tên nhânh viên, ID nhân viên, phòng ban và vị trí. 
1 cấu tử cho phép nhập các giá trị sau làm đối số và gán chúng vào các biến thành viên 
thích hợp: tên nhânh viên, ID nhân viên. Trường và sẽ được gán 
bởi 1 chuỗi rỗng (""). 
1 cấu tử mặc định sẽ gán các chuỗi rỗng ("") vào các biến thành viên , 
, và 0 cho biến thành viên . 
Hãy viết các hàm phù hợp để lưu giá trị của các biến thành viên ở trên và các hàm có thể gán 
hoặc trả về giá trị của chúng (set/get). Sau đó, hãy viết 1 chương trình tạo 3 đối tượng 
lưu thông tin theo dữ liệu sau: 
*/

#include <iostream>
#include <iomanip>
using namespace std;

class Employee
{
	string name, department, position; 
	int idNumber;
public:
    void setName(string name) { this->name = name; } // this giúp phân biệt các biến trùng tên
	void setDepartment(string dept) { department = dept; }
	void setPosition(string pos) { position = pos; }
    void setIdNumber(int id) { idNumber = id; }

    // hàm tạo mặc định
	Employee()  // thứ tự khởi tạo giống thứ tự khai báo biến ở trên 
    : name(""), department(""), position(""), idNumber(0) {} 

	// hàm tạo 2 tham số
    Employee(string name, int id) 
    : name(name), department(""), position(""), idNumber(id) {} 

    // hàm tạo 4 tham số 
    Employee(string name, string dept, string pos, int id)  	 
	: name(name),  department(dept), position(pos), idNumber(id){} 

	string getName() const { return name; }
	int getIdNumber() const { return idNumber; }
	string getDepartment() const { return department; }
	string getPosition() const { return position; }    
};

//--------------------------------- CHẠY THỬ LỚP -----------------------------------------

const int l = 20; 	

void print (const Employee & e)	// tham chiếu hằng vừa không tốn phí copy vừa tránh thay đổi biến
{
	cout << setw(l) << e.getName() << setw(l) << e.getIdNumber() 
        << setw(l) << e.getDepartment() << setw(l) << e.getPosition() << endl; 
}

int main()
{	
	const int n = 3; 
    Employee a[] = {Employee("Susan Mayers", "Accounting", "Vice president", 47899), 
                    Employee("Mark Jones", "IT", "Programmer", 39119),
	                Employee("Joy Rogers", "Manufacturing", "Engineer", 81774)};

	cout << left << setw(l) << "Name" << setw(l) << "ID Number" 
        << setw(l) << "Department" << setw(l) << "Position" << endl;
	for (int i = 0; i < n; i++)
       print(a[i]); 

	return 0;
}