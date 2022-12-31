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
#include<iostream>
using namespace std;

const string thang[12] = {
    "01", "02", "03", "04", "05", "06",
    "07", "08", "09", "10", "11", "12"
};

class Date{
    int day, month, year;
    int checkDay(int day){
        if(day<0||day>31)throw "Loi";
        else return day;
    }
    int checkMonth(int month){
        if(month<0||month>12)throw "Loi";
        else return month;
    }
    public:
        Date(int d, int m, int y){
            day = checkDay(d);
            month = checkMonth(m);
            year = y;
        }
        void print_1(){
            cout << day << "/" << thang[month - 1] << "/" << year << endl;
        }
        void print_2(){
            cout <<"Ngay " <<  day << " thang " << thang[month - 1] << " nam " << year << endl;
        }
};

int main(){
    int day, month, year;
    cout << "Nhap ngay thang nam: "; cin >> day >> month >> year;
    Date d(day,month,year);
    d.print_1();
    d.print_2();
}