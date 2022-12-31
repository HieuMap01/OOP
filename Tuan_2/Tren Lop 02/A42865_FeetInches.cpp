/*3. FeetInches:
Viết lớp FeetInches để lưu thông tin khoảng cách đo theo feet và inches.
Lớp gồm các thành viên:
- biến feet và inches là hai số nguyên.q hàm tạo nhận 2 tham số để cập nhật các biến thành viên trên sau đó quy về dạng chuẩn 12
inches đổi thành 1 feet.
Ví dụ nếu nhận vào 3 feet 14 inches sẽ tạo đối tượng có thông tin 4 feet 2 inches, 
nhập vào 5 feet -2 inches (âm hai inches) sẽ tạo ra đối tượng chứa 4 feet 10 inches.
- Các hàm nạp chồng toán tử sau:
    + Toán tử 2 ngôi: phép +, =, +=, ==
    + Toán tử 1 ngôi: phép ++ kiểu tiền tố và kiểu hậu tố
Viết một chương trình đơn giản demo các khả năng trên.
Khung mã gợi ý cho lớp FeetInches ở dưới đã có sẵn hàm tiện ích simplify() để chuẩn hoá feet và inch, 
cũng sẵn cài đặt cho toán tử +, sinh viên cần tự viết thêm các toán tử còn lại.

Thêm vào FeetInches các thành viên sau:
    + Hàm tạo sao chép nhận vào một đối tượng FeetInches, gán thuộc tính feet và inch bằng giá trị của thuộc tính feet và inch 
    của đối tượng đối số. Kết quả thu một đối tượng mới copy yvhệt đối tượng truyền vào.
    + Hàm multiply nhận đối số là một đối tượng FeetInches. Hàm sẽ lấy các thuộc tính feet và inches của đối tượng đối số
    nhân tương ứng với các thuộc tính feet và inches của đối tượng gọi hàm multiply, 
    sau đó trả về một đối tượng FeetInches có thuộc tính chính là các giá trị tích này.
Bonus 0.5 điểm quá trình:
Tại sao nếu muốn tận dụng lớp FeetInches để tính diện tích (tức là 2 khoảng cách nhân nhau)
thì nên dùng hàm multiply thay vì viết toán tử *?
Hàm multiply thực chất chỉ tính diện tích xấp xỉ, thử sửa lại hàm này để tính diện tích chính xác
*/

#include <iostream>
#include <cstdlib>
#include "FeetInches.h"
using namespace std;
void FeetInches::simplify()
{
	if(inches >= 12)
	{
		feet += inches/12;
		inches = (inches % 12);
	}
	else if(inches < 0)
	{
		feet -= ((abs(inches)/12) + 1);
		inches = 12 - (abs(inches) % 12);
	}
}
// Nạp chồng toán tử 2 ngôi
// Phép +
FeetInches FeetInches::operator+ (const FeetInches & right)
{
	FeetInches temp;
	temp.inches = inches + right.inches;
	temp.feet = feet + right.feet;
	temp.simplify();
	return temp;
}
// Phép =
FeetInches FeetInches::operator= (const FeetInches & right)
{
    *this = right;
    feet = right.feet;
    inches = right.inches;
    return *this;
}
// Phép +=
FeetInches FeetInches::operator+= (const FeetInches & right){
    
}
// Phép ==
bool FeetInches::operator== (const FeetInches & right){
    bool check;
    if(feet == right.feet && inches == right.inches) check = true;
    else check = false;
    return check;
}
// Nạp chồng toán tử 1 ngôi:
FeetInches FeetInches::operator++ (){
    ++inches;
    simplify();
    return *this;
}
FeetInches FeetInches::operator++ (int){
    FeetInches temp = *this;
    inches++;
    simplify();
    return temp;
}
int main()
{

	int feet, inches;
    FeetInches f1(3, 14), f2(1, -2);
    FeetInches f3 = f1 + f2, f4 = f1;
    cout << f1.getFeet() << " feet " << "  " << f1.getInches() << " inches " << endl;
    cout << f3.getFeet() << " feet " << "  " << f3.getInches() << " inches " << endl;
    cout << f4.getFeet() << " feet " << "  " << f4.getInches() << " inches " << endl;
    if(f1 == f4) cout << "True.\n";
    else cout << "False.\n";
    return 0;
}