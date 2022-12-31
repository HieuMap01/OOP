/*
Cho hai dạng lưu trữ thời gian là dạng chuẩn và dạng quân đội với quy tắc như sau: •4h 5 phút 20 giây trong dạng chuẩn sẽ lưu thành bộ ba số 4, 5, 20 ứng với giờ phút giây, còn trong dạng quân đội sẽ lưu thành bộ chỉ có hai số 405, 20 ứng với “giờ quân đội” và giây. Lớp Time có khai báo và cài đặt như sau: 
*/
#include <iostream>
using namespace std;

class Time
{
protected:
    int hour;
    int min;
    int sec;
public:
    Time(): hour(0), min(0), sec(0){}
    Time(int h, int m, int s) 
    : hour(h), min(m), sec(s){}
    int getHour() const { return hour; }
    int getMin() const { return min; }
    int getSec() const { return sec; }
    
};
/*
Viết class MilTime kế thừa từ class Time ở trên, cho phép nhập vào thời gian dạng quân đội và chuyển thành dữ liệu giờ dạng chuẩn. •Lớp MilTime có các thành viên sau: •Biến milHour: chứa giờ dạng quân đội. vd giờ 1630 dạng quân đội nghĩa là 16h30 phút trong thực tế.  •Biến milSec: giây dạng quân đội thì chứa giây giống hệt dạng chuẩn•Hàm tạo: cần chấp nhận đối số cho giờ và giây ở dạng quân đội. Các thông tin này sẽ chuyển về dạng chuẩn lưu trong các biến của lớp Time. •setTime: chấp nhận đối số ở dạng quân độilưu vào milHour và milSec. Các thông tin này sẽ chuyển về dạng chuẩn lưu trong các biến của lớp Time. •getHour: trả về giờ dạng quân đội. •getStandHr: trả về giờ dạng chuẩnViết chương trình demo class này đòi người dùng nhập vào thời gian dạng quân đội sau đó hiển thị cả thời gian dạng chuẩn lẫn dạng quân đội. Xác thực đầu vào:Với lớp Time, sinh viên cần tự xác định tiêu chuẩn đầu vào phù hợp. Với lớp MilTime, không chấp nhận giờ lớn hơn 2359 hay nhỏ hơn 0, cũng không chấp nhận giây lớn hơn
*/
class MilTime : public Time
{
private:
    int milHour;
    int milSec;
public:
    MilTime(): milHour(0), milSec(0){}
    MilTime(int h, int m, int s) 
    : Time(h, m, s), milHour(h), milSec(s){}
    void setTime(int h, int s)
    {
        milHour = h;
        milSec = s;
        if (h > 2359)
        {
            cout << "gio qua lon" << endl;
        }
        else if (h < 0)
        {
            cout << "Gio qua nho" << endl;
        }
        else
        {
            hour = milHour / 100;
            min = milHour % 100;
            if (min>59)
            {
                hour += 1;
                min = min - 60;
            }
            sec = milSec;
            if (sec > 59)
            {
                min += sec / 60;
                sec = sec % 60;
            }
            
        }
    }
    int getMilHour() const { return milHour; }
    int getMilSec() const { return milSec; }
    void getStandHr()
    {
        cout << "Hour: " << hour << endl;
        cout << "Min: " << min << endl;
        cout << "Sec: " << sec << endl;
    }
    void getMilHr()
    {
        cout << "MilHour: " << milHour << endl;
        cout << "MilSec: " << milSec << endl;
    }
};
int main()
{
    MilTime m1(2190, 0, 60);
    m1.getMilHr();
    m1.setTime(2190,60);
    m1.getStandHr();
    return 0;
}