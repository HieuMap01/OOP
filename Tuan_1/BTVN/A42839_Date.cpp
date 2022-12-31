/*
4.Lớp Date
Thiết kế một lớp có tên là Date có các thành viên sau:
    Các biến thành viên month, day và year để biểu diễn một ngày trong năm
    Lớp cũng cần 3 hàm thành viên để in ra ngày tron gnăm dưới 3 dạng sau
        12/25/2014
        December 25, 2014
        25 December 2014
    Cuối cùng, viết hàm main để demo các hàm trên (tạo đối tượng và gọi hàm thành viên)
    Xác thực đầu vào:Không chấp nhận các giá trị cho day lớn hơn 31 hoặc nhỏ hơn 1.
    Không chấp nhận các giá trị cho month lớn hơn 12 hoặc nhỏ hơn 1.
*/
#include <iostream>
using namespace std;

class Date
{
    int month, day, year;
public:
    void setInfor(int m, int d, int y)
    {
        month = m;
        day = d;
        year = y;
    }
    int getday() const { return day; }
    int getmonth() const { return month; }
    int getyear() const { return year; }
    void displayDateInfor_1()
    {
        cout << getmonth() << "/" << getday() << "/" << getyear() << endl;
    }
    string getMonthString(int month)
    {
        string month_string[12] = {
            "January",
            "February",
            "March",
            "April",
            "May",
            "June",
            "July",
            "August",
            "September",
            "October",
            "November",
            "December",
        };
        return month_string[month-1];
    }
    void displayDateInfor_2()
    {
        cout << getMonthString(getmonth()) << " " << getday() << ", " << getyear() << endl;
    }
    void displayDateInfor_3()
    {
        cout << getday() << " " << getMonthString(getmonth()) << " " << getyear() << endl;
    }
};

int main()
{
    int month, day, year;
    Date d;
    do
    {
        cout << "Nhap ngay: ";
        cin >> day;
    } while (day > 31 || day < 1);
    do
    {
        cout << "Nhap thang: ";
        cin >> month;
    } while (month > 31 || month < 1);
    cout << "Nhap Nam: ";
    cin >> year;
    d.setInfor(month, day, year);
    cout << "---------Hien thi---------\n";
    d.displayDateInfor_1();
    d.displayDateInfor_2();
    d.displayDateInfor_3();
    return 0;
}