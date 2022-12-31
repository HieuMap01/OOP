/*1. Date (Bắt buộc) 
Thiết kế một lớp được gọi là . Lớp này lưu thông tin của một thời gian gồm 3 số nguyên: 
(tháng), (ngày) và (năm). Nó có các hàm thành viên để in ra thời gian theo 
các dạng sau đây: 
22/05/2021 
Ngày 22 Tháng 5, 2021 
Hãy viết 1 chương trình để hoàn thiện lớp này như yêu cầu. 
Lưu ý đầu vào: Không cho phép có giá trị lớn hơn 31 và nhỏ hơn 1. Không cho phép 
có giá trị lớn hơn 12 và nhỏ hơn 1. 
*/

#include <iostream>
using namespace std;

const string MONTH[12] = 
    {
        "January", "February", "March",
        "April", "May", "June",
        "July", "August", "September",
        "October", "November", "December"
    };

class Date{
    int day, month, year; 
public: 
    Date(int d, int m, int y)
    {
        if (d < 1 || d > 31) throw "Ngay sai\n"; 
        if (m < 1 || m > 12) throw "Thang sai\n";
        day = d; 
        month = m; 
        year = y;  
    }
    void print1() const {
        cout << month << "/" << day << "/" << year << endl;
    }
    void print2() const {
        cout << MONTH[month-1] << " " << day << ", " << year << endl;
    }
    void print3() const {
        cout << day << " " << MONTH[month-1] << " " << year << endl;
    }
};

int main() {
    int ngay, thang, nam;
    cout << "Nhap ngay, thang, nam: "; 
    cin >> ngay >> thang >> nam;
    Date d(ngay, thang, nam); 
    d.print1();
    d.print2();
    d.print3(); 
    return 0;
}