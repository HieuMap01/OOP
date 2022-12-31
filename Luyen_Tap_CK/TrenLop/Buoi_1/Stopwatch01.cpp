/*
Stopwatch (3) (Đồng hồ bấm giờ)
Thiết kế một lớp được gọi là Stopwatch (Đồng hồ bấm giờ). Lớp này lưu thông tin của một thời gian gồm 3 số nguyên:
- phút (1 phút bằng 60 giây)
- giây (1 giây bằng 1000 mili giây)
- mili giây
Nó có các hàm thành viên như sau:
Hàm normalize là 1 hàm thành viên private có nhiệm vụ chuẩn hóa giá trị của phút, giây và mili giây mỗi khi 
cập nhật hoặc thay đổi giá trị của các biến đó. Hàm này cho sẵn như sau (m: phút, s: giây, ms: mili giây):
void normalize(){    
s+= ms/1000;    
ms%= 1000;    
m+= s/60;    
s%= 60;
}
Cấu tử sử dụng 3 đối số đại diện lần lượt cho phút, giây và mili giây. Các đối số này được gán vào các 
biến thành viên có ý nghĩa tương ứng. Trong đó, đối số đại diện cho mili giây là đối số mặc định bằng 0.
Hàm getMinute: Hàm này trả về một số thực thể hiện giá trị thời gian theo đơn vị phút. Ví dụ, 
30 phút 30 giây 60 mili giây thì kết quả hàm này trả về 30.501 (30.51=30+0.5+0.001).
Hàm run với 1 đối số là 1 số nguyên x. Hàm này sẽ tăng số mili giây lên x đơn vị.
Hàm print cho phép hiển thị ra ngoài màn hình theo định dạng phút:giây,mili giây. 
Ví dụ, nếu là 5 phút 20 giây và 3 mili giây thì màn hình sẽ hiển thị 5:20,3.
Hãy viết 1 chương trình cho phép:
- Người dùng nhập vào số phút, giây và mili giây.
- Tiếp theo, khởi tạo một biến đối tượng thuộc lớp này dựa trên 3 giá trị vừa nhập.
- Hiển thị ra màn hình các giá trị thời gian theo đơn vị phút.
- Sau đó, khởi tạo 1 vòng for với vòng lặp 20 lần. Ở mỗi lần lặp, sử dụng hàm thành viên run tăng số mili 
giây của biến vừa tạo lên 555 đơn vị rồi hiển thị ra màn hình kết quả mỗi lần tăng.
Lưu ý đầu vào: Chỉ cho phép nhập giá trị vào các biến thành viên như phút, giây và mili giây nhận giá 
trị trong khoảng từ 0 tới 10^6
*/

#include<iostream>
#include<math.h>
using namespace std;

class Stopwatch{
    int m, s, ms;
    void normalize(){    
        s+= ms/1000;    
        ms%= 1000;    
        m+= s/60;    
        s%= 60;
    }
    int check(int i){
        if(i < 0 || i > pow(10,6)) throw "Khong dung yeu cau";
        else return i;
    }
    public:
    Stopwatch(int m1 , int s1 , int ms1 = 0 ){
        m = check(m1);
        s = check(s1);
        ms = check(ms1);
        normalize();
    }
    float getMinute()const{return float(m)+float(s)/60+float(ms)/6000;}
    void run(int x){
        ms+=x;
    }
    void print()const{
        cout << m << ":" << s << ":" << ms << endl;
    }
};


int main(){
    Stopwatch S(20,12,34);
    cout << S.getMinute() << endl;
    for(int i = 0; i< 5; i++){
        S.run(555);
        S.print();
    }
    return 0;
}