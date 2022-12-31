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
    temp.inches = inches + right.inches;
    temp.feet = feet + right.feet;
    temp.simplify();
    return temp;
} 
//nạp chồng toán tử 2 ngôi - phép bang
FeetInches FeetInches::operator= (const FeetInches &right)
{
    *this = right;
    feet = right.feet;
    inches = right.inches;
    return *this;
} 
//nạp chồng toán tử 2 ngôi - phép +=
FeetInches FeetInches::operator+= (int &n)
{
    inches += n;
    feet += n;
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
    simplify();
    return *this;
} 
// hau to.
FeetInches FeetInches::operator++(int)
{
    FeetInches tmp = *this;
    inches++;
    simplify();
    return tmp;
} 

int main(){
    FeetInches f1(3, 14), f2(1, -2);
    FeetInches f3 = f1 + f2, f4 = f1;
    int i=10;
    f2+=i;
    cout << f1.getFeet() << " feet " << "  " << f1.getInches() << " inches " << endl;
    cout << f2.getFeet() << " feet " << "  " << f2.getInches() << " inches " << endl;
    cout << f3.getFeet() << " feet " << "  " << f3.getInches() << " inches " << endl;
    cout << f4.getFeet() << " feet " << "  " << f4.getInches() << " inches " << endl;
    if(f1 == f4) cout << "True.\n";
    else cout << "False.\n";
    return 0;
}