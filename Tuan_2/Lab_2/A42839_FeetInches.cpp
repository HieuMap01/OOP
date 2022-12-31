/*
3.FeetInches
Viết lớp FeetInches để lưu thông tin khoảng cách đo theo feet và inches. 
Lớp gồm các thành viên: 
    - biến feet và inches là hai số nguyên. 
    - hàm tạo nhận 2 tham số để cập nhật các biến thành viên trên sau đó quy về dạng chuẩn 12 inches 
    đổi thành 1 feet. Ví dụ nếu nhận vào 3 feet 14 inchessẽ tạo đối tượng có thông tin 4 feet 2 inches, 
    nhập vào 5 feet -2 inches (âm hai inches) sẽ tạo ra đối tượng chứa 4 feet 10 inches. 
    - Các hàm nạp chồng toán tử sau: 
        + Toán tử 2 ngôi: phép +, =, +=, ==
        + Toán tử 1 ngôi: phép ++ kiểu tiền tố và kiểu hậu tố
Viết một chương trình đơn giản demo các khả năng trên. Khung mã gợi ý cho lớp FeetInches ở dưới đã có 
sẵn hàm tiện ích simplify() để chuẩn hoá feet vài nch, cũng sẵn cài đặt cho toán tử +, sinh viên cần 
tự viết thêm các toán tử còn lại.

4.FeetInches(tiếp)
Thêm vào FeetInches các thành viên sau: 
    - Hàm tạo sao chép nhận vào một đối tượng FeetInches,gán thuộc tính feet vài nch bằng giá trị 
    của thuộc tính feet vài nch của đối tượng đối số. Kết quả thu một đối tượng mới copyy hệt đối
    tượng truyền vào.
    - Hàm multiply nhận đối số là một đối tượng FeetInches. Hàm sẽ lấy các thuộc tính feet và inches 
    của đối tượng đối số nhân tương ứng với các thuộc tính feet và inches của đối tượng 
    gọi hàm multiply, sau đó trả về một đối tượng FeetInches có thuộc tính chính là các giá trị tích này. 
Bonus 0.5 điểm quá trình 
    Tại sao nếu muốn tận dụng lớp FeetInchesđểtính diện tích (tức là 2 khoảng cách nhân nhau) 
    thì nên dùng hàm multiply thay vì viết toán tử*? Hàmmultiply thực chất chỉ tính diện tích xấp xỉ, 
    thử sửa lại hàm này để tính diện tích chính xác.
*/
#include <iostream>
#include <cstdlib>  //đểdùng được hàm tính giá trị tuyệt đối abs()
#include "FeetInches.h"
using namespace std; 


void FeetInches::simplify(){
    if(inches >= 12){
        feet += (inches / 12);
        inches = inches % 12;}
    else if(inches < 0){
        feet -= ((abs(inches) / 12) + 1);
        inches = 12-(abs(inches) % 12);}
}
//nạp chồng toán tử 2 ngôi - phép cộng
FeetInches FeetInches::operator+ (const FeetInches &right)
{
    FeetInches temp;
    temp.inches = this->inches + right.inches;
    temp.feet = this->feet + right.feet;
    temp.simplify();
    return temp;
}
//nạp chồng toán tử 2 ngôi - phép bang
FeetInches FeetInches::operator= (const FeetInches &right)
{
    this->feet = right.feet;
    this->inches = right.inches;
    return *this;
} 
//nạp chồng toán tử 2 ngôi - phép +=
FeetInches FeetInches::operator+= (const FeetInches &n)
{
    this->inches += n.inches;
    this->feet += n.feet;
    simplify();
    return *this;
}
//nạp chồng toán tử 2 ngôi - phép ==
bool FeetInches::operator== (const FeetInches & right){
    bool check;
    if(feet == right.feet && inches == right.inches) check = true;
    else check = false;
    return check;
}
// tien to.
FeetInches FeetInches::operator++ ()
{
    inches++;
    feet++;
    simplify();
    return *this;
} 
// hau to.
FeetInches FeetInches::operator++(int)
{
    FeetInches tmp = *this;
    inches++;
    feet++;
    simplify();
    return tmp;
} 

FeetInches FeetInches::operator*(const FeetInches & right)
{
    FeetInches temp;
    temp.inches = this->inches * right.inches;
    temp.feet = this->feet * right.feet;
    temp.simplify();
    return temp;
}
int main(){
    FeetInches f1(3, 14);
    FeetInches f2(10, 16);
    FeetInches f3;
    f3 = f1 + f2;
    FeetInches f4 = f1;
    FeetInches f5(f2);
    FeetInches f6;
    f2+=f3;
    f1++;//hậu tố
    ++f1;//tiền tố
    f6 = f1 * f2;
    cout << f1.getFeet() << " feet " << "  " << f1.getInches() << " inches " << endl;
    cout << f2.getFeet() << " feet " << "  " << f2.getInches() << " inches " << endl;
    cout << f3.getFeet() << " feet " << "  " << f3.getInches() << " inches " << endl;
    cout << f5.getFeet() << " feet " << "  " << f5.getInches() << " inches " << endl;
    cout << f6.getFeet() << " feet " << "  " << f6.getInches() << " inches " << endl;
    if(f1 == f4) cout << "True.\n";
    else cout << "False.\n";
    return 0;
}
