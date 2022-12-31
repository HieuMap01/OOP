/*
Circle Class
Viết một lớp Circle có các thành viên sau:
radius: một số double
pi: một số double được khởi tạo với giá trị 3.14159
Hàm tạo mặc định: không làm gì cả
Hàm tạo 1 tham số: nhận một tham số số thực để khởi tạo radius 
Hàm setRadius cập nhật biến radius.
Hàm getRadius lấy giá trị biến radius.
Hàm getArea trả về diện tích hình tròn, biết diện tích = pi*radius*radius
Hàm getDiameter trả về đường kính hình tròn, biết đường kính = 2 * radius
Hàm getCircumference trả về chu vi hình tròn, biết chu vi = 2*pi*radius
Hàm main yêu cầu người dùng nhập bán kính để tạo ra một đối tượng Circle, 
cuối cùng in ra diện tích, đường kính, chu vi đối tượng này
*/

#include<iostream>
using namespace std;

class Circle{
    double radius;
    const double PI = 3.14159;
    public:
    Circle(){}
    Circle(double r){radius = r;}
    void setradius(double r){radius = r;}
    double getradius() const{return radius;}
    double getArea() const{return PI*radius*radius;}
    double getDiameter() const{return 2*radius;}
    double getCircumference() const{return 2*PI*radius;}
};
int main(){
    Circle c;
    double R;
    cout << "Nhap ban kinh: "; cin >> R;
    c.setradius(R);
    cout << "Dien tich: " << c.getArea() << endl
         << "Duong kinh: " << c.getDiameter() << endl
         << "Chu vi: " << c.getCircumference() << endl;
    return 0;
}