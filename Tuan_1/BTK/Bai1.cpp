// 1. Date (Bắt buộc)
// Thiết kế một lớp được gọi là . Lớp này lưu thông tin của một thời gian gồm 3 số nguyên:
//  (tháng), (ngày) và (năm). Nó có các hàm thành viên để in ra thời gian theo
// các dạng sau đây:
// 22/05/2021
// Ngày 22 Tháng 5, 2021
// Hãy viết 1 chương trình để hoàn thiện lớp này như yêu cầu.
// Lưu ý đầu vào: Không cho phép có giá trị lớn hơn 31 và nhỏ hơn 1. Không cho phép
//  có giá trị lớn hơn 12 và nhỏ hơn 1.

#include <iostream>
using namespace std;

class Thoigian
{
private:
    int ngay;
    int thang;
    int nam;
public:
    void setNgay(int Ngay);
    void setThang(int Thang);
    void setNam(int Nam);
    int getNgay()
    {
        return ngay;
    }
    int getThang()
    {
        return thang;
    }
    int getNam()
    {
        return nam;
    }
    void In()
    {
        cout << ngay << "/" << thang << "/" << nam << endl;
        cout << "Ngay " << ngay << " Thang " << thang << " Nam " << nam << endl;
    };
};

void Thoigian::setNgay(int Ngay)
{
    if (Ngay < 1 && Ngay > 30)
        ngay = Ngay;
}
void Thoigian::setThang(int Thang)
{
    if (Thang < 1 && Thang > 12)
        thang = Thang;
}
void Thoigian::setNam(int Nam)
{
    nam = Nam;
}

int main()
{
    Thoigian tg1;
    tg1.setNgay(2);
    tg1.setThang(4);
    tg1.setNam(2016);
    tg1.In();
    tg1.In();
    return 0;
}