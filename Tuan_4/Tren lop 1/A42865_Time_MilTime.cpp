/*5. Time & MilTime
Cho hai dạng lưu trữ thời gian là dạng chuẩn và dạng quân đội với quy tắc như sau:
• 4h 5 phút 20 giây trong dạng chuẩn sẽ lưu thành bộ ba số 4, 5, 20 ứng với giờ phút giây,
còn trong dạng quân đội sẽ lưu thành bộ chỉ có hai số 405, 20 ứng với “giờ quân đội” và giây.
Lớp Time có khai báo và cài đặt như sau:
Viết class MilTime kế thừa từ class Time ở trên, cho phép nhập vào thời gian dạng quân đội và chuyển thành dữ liệu giờ dạng chuẩn.
• Lớp MilTime có các thành viên sau:
• Biến milHour: chứa giờ dạng quân đội. vd giờ 1630 dạng quân đội nghĩa là 16h30 phút trong thực tế.
• Biến milSec: giây dạng quân đội thì chứa giây giống hệt dạng chuẩn
• Hàm tạo: cần chấp nhận đối số cho giờ và giây ở dạng quân đội. 
Các thông tin này sẽ chuyển về dạng chuẩn lưu trong các biến của lớp Time.
• setTime: chấp nhận đối số ở dạng quân đội lưu vào milHour và milSec. 
Các thông tin này sẽ chuyển về dạng chuẩn lưu trong các biến của lớp Time.
• getHour: trả về giờ dạng quân đội.
• getStandHr: trả về giờ dạng chuẩn
Viết chương trình demo class này đòi người dùng nhập vào thời gian dạng quân đội sau đó hiển thị cả thời gian dạng chuẩn lẫn dạng quân đội.
Xác thực đầu vào: Với lớp Time, sinh viên cần tự xác định tiêu chuẩn đầu vào phù hợp. 
Với lớp MilTime, không chấp nhận giờ lớn hơn 2359 hay nhỏ hơn 0, cũng không chấp nhận giây lớn hơn 60 hay nhỏ hơn 0.
*/
#include <iostream> 
using namespace std; 
class Time{
protected:
    int hour;
    int min;
    int sec;
public:
    Time(): hour(0), min(0), sec(0){}
    Time(int h, int m, int s): hour(h), min(m), sec(s){}
    int getHour() const {return hour;}
    int getMin() const {return min;}
    int getSec() const {return sec;}
    void Print() const {
        cout << hour << " " << min << " " << sec << endl;
    }
};
class MilTime : public Time{
protected:
    int milHour, milSec;
    int checkMilHour(int mh) const{
        if(mh < 0 || mh > 2359) throw "Gio quan doi sai\n";
        return mh;
    }
    int checkMilSec(int ms) const{
        if(ms < 0 || ms > 60) throw "Giay sai\n";
        return ms;
    }
    int checkMin(int m) const{
        if(m < 0 || m > 60) throw "Phut sai\n";
        return m;
    }
public:
    void setTime(int mh, int ms){
        milHour = checkMilHour(mh);
        milSec  = checkMilSec(ms);
        sec = milSec;
        min = checkMin(mh % 100);
        hour = mh / 100;
    }
    MilTime(int mh, int ms) {setTime(mh, ms);}
    int getHour() const {return milHour;}
    int getStandHr() const {return hour;}
    void Print() const {
        Time:: Print();
        cout << milHour << " " << milSec << endl;
    }
};

int main(){   
    Time t1(16, 30, 15);
    t1.Print();
    MilTime t2(1630, 15);
    t2.Print();
    return 0;
}
