/*
Stop watch (0) (Đồng hồ bấm giờ)
Thiết kế một lớp được gọi là Đồng hồ bấm giờ. Lớp này lưu thông tin của một thời gian gồm 3 số nguyên:
- giờ (1 giờ bằng 60 phút) 
- phút (1 phút bằng 60 giây) 
- giây
Nó có các hàm thành viên như sau: 
	Hàm normalize là 1 hàm thành viên private có nhiệm vụ chuẩn hóa giá trị của giờ, 
    phút và giây mỗi khi cập nhật hoặc thay đổi giá trị của các biến đó. 
    Hàm này cho sẵn như sau (hour: giờ, minute: phút, second: giây): 

void normalize(){    
    minute+= second/60;
    second%= 60;    
    hour+= minute/60;     
    minute%= 60; 
} 
    Hãy sử dụng hàm này thật hợp lý. 
	Cấu tử sử dụng 3 đối số mặc định đều bằng 0 lần lượt có ý nghĩa như sau và hãy gán chúng vào các biến thành viên thích hợp: giờ, phút, giây.
	Hàm setSecond: Hàm có 1 đối số là 1 số nguyên và gán số này vào biến thành viên đại diện cho số giây.
	Hàm getSecond: Hàm này trả về một số nguyên thể hiện giá trị thời gian theo đơn vị giây. 
    Ví dụ, 5 giờ 30 phút 36 giây thì kết quả hàm này trả về 19836 (19836=5*3600+30*60+36).
	Hàm print cho phép hiển thị ra ngoài màn hình theo định dạng giờ:phút:giây. 
    Ví dụ, nếu là 5 giờ 20 phút 3 giây thì màn hình sẽ hiển thị 5:20:3.
Hãy viết 1 chương trình cho phép: 
    - Người dùng nhập vào số giờ, phút và giây. 
    - Tiếp theo, khởi tạo một biến đối tượng thuộc lớp này dựa trên 3 giá trị vừa nhập. 
    - Hiển thị ra màn hình các giá trị thời gian theo đơn vị giây. - Yêu cầu người nhập vào 1 số đại diện cho số giây. 
Hãy dùng hàm thích hợp để gán số giây này vào đối tượng vừa tạo. Hiển thị đối tượng đó ra màn hình (print).
Lưu ý đầu vào: Chỉ cho phép nhập giá trị vào các biến thành viên như giờ, phút, giây nhận giá trị trong khoảng từ 0 tới 〖10〗^6

*/

#include<iostream>
using namespace std;

class StopWatch{
    int gio, phut, giay;
    public:
    void normalize(){    
        phut+= giay/60;
        giay%= 60;    
        gio+= phut/60;     
        phut%= 60; 
    } 
};

int main(){
    return 0;
}