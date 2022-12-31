// Thiết kế một lớp có tên là Date có các thành viên sau:
// Các biến thành viên month, day và year để biểu diễn một ngày trong năm
// Một hàm tạo nhận 3 tham số cập nhật cho 3 biến thành viên
// Viết hàm main tạo 1 đối tượng Date.
// Xác thực đầu vào sử dụng hàm tiện ích kiểm tra ngoại lệ: 
// Không chấp nhận các giá trị cho day lớn hơn 31 hoặc nhỏ hơn 1. 
// Không chấp nhận các giá trị cho month lớn hơn 12 hoặc nhỏ hơn 1.
#include<iostream>
using namespace std;

class Date{
    int month, day, year;
    inline int check_day(int d) const{
        if (d>31 || d<1) throw("Ngay sai.");
        return d;
    }
    inline int check_month(int m) const{
        if (m>12 || m<1) throw("Thang sai.");
        return m;
    }
    public:
    Date(int d, int m, int y)
    : day(check_day(d)), month(check_month(m)), year(y){}
};

int main(){
    try
    {
        int day, month, year;
        cout << "Nhap lan luot day, month, year:";
        cin >> day >> month >> year;
        Date date(day,month,year);
    }
    catch(const char * e)
    {
        cout << e;
    }
    cout <<endl;
    cout << "Chuong trinh BT.\n";
    return 0;
}