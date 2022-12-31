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
    /* (Cach 2: dang sai)
    inline int check_day(int d) const{
        if (d>31 || d<1) throw("Ngay sai.");
        return d;
    }
    inline int check_month(int m) const{
        if (m>12 || m<1) throw("Thang sai.");
        return m;
    }
    */
public:
    void setInfor(int m, int d, int y)
    {
        month = m;
        day = d;
        year = y;
    }
    /* (Cach 2: dang sai)
    Date(int d, int m, int y)
    : day(check_day(d)), month(check_month(m)), year(y){}
    */
    int getday() const { return day; }
    int getmonth() const { return month; }
    int getyear() const { return year; }
    void displayDateInfor_1()
    {
        cout << getmonth() << "/" << getday() << "/" << getyear() << endl;
    }
    /* Chuyển đổi số sang chữ cách 1
    string convertMonthToNumber(int month){
        string month_string = "";
        switch (month)
        {
            case 1:
                month_string = "January";
                break;
            case 2:
                month_string = "February";
                break;
            case 3:
                month_string = "March";
                break;
            case 4:
                month_string = "April";
                break;
            case 5:
                month_string = "May";
                break;
            case 6:
                month_string = "June";
                break;
            case 7:
                month_string = "July";
                break;
            case 8:
                month_string = "August";
                break;
            case 9:
                month_string = "September";
                break;
            case 10:
                month_string = "October";
                break;
            case 11:
                month_string = "November";
                break;
            default:
                month_string = "December";
                break;
        }
        return month_string;
    }
    */
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
        /* Chuyển đổi số sang chữ cách 1
        cout << convertMonthToNumber(getmonth()) << " " << getday() << ", " << getyear() << endl;
        */
        cout << getMonthString(getmonth()) << " " << getday() << ", " << getyear() << endl;
    }
    void displayDateInfor_3()
    {
        /* Chuyển đổi số sang chữ cách 1
        cout << getday() << " " << convertMonthToNumber(getmonth()) << " " << getyear() << endl;
        */
        cout << getday() << " " << getMonthString(getmonth()) << " " << getyear() << endl;
    }
};
/* (Cach 2: dang sai)
Date Nhap(){
    int d, m, y;
    Date da;
    try
    {
        cout << "Nhap ngay: "; cin >> d;
        cout << "Nhap thang: "; cin >> m;
        cout << "Nhap nam: "; cin >> y;
        da = Date(d,m,y);
    }
    catch(const char * e)
    {
        Nhap();
    }

    return da;
}
*/

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
    // Date d = Nhap(); (Cach 2: dang sai)
    cout << "---------Hien thi---------\n";
    d.displayDateInfor_1();
    d.displayDateInfor_2();
    d.displayDateInfor_3();
    return 0;
}