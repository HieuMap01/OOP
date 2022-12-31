/*Viết một lớp khuôn mẫu có biến và hàm cho trước, biết có 1 hàm trong lớp cần 2 tham số kiểu. 
Sau đó viết main kiểm tra lớp với các kiểu khác nhau
Ví dụ: 
Xây dựng lớp template TamGiac dùng để định nghĩa tổng quát đối với các kiểu dữ liệu bên trong lớp. 
Trong lớp này có chứa 3 thuộc tính dạng số và có cùng kiểu dữ liệu với nhau, đại diện cho 3 cạnh của tam giác.
- Viết các cấu tử, các phương thức đặt và lấy giá trị thuộc tính. 
- Viết hai phương thức lấy chu vi và lấy diện tích của hình tam giác với kiểu giá trị trả về của hai phương thức này 
có thể khác với kiểu dữ liệu của thuộc tính.
- Viết hàm main minh họa bằng các sử dụng lớp template TamGiac với các kiểu dữ liệu khác nhau. 
*/

#include<iostream>
#include<math.h>
using namespace std;

template<class T, class U>
class tamgiac{
    T a, b, c;
    public: 
    tamgiac(T A, T B, T C){
        a = A;
        b = B;
        c = C;
    }
    void setA(T A){a=A;}
    void setB(T B){b=B;}
    void setC(T C){c=C;}
    void setall(T A, T B, T C){
        a = A;
        b = B;
        c = C;
    }
    T getA() const {return a;}
    T getB() const {return b;}
    T getC() const {return c;}
    U chuvi() const {
        return a + b + c;
    }
    U dientich() const {
        return U(sqrt((a+b+c)*(a+b-c)*(b+c-a)*(a+c-b)))/U(4);
    }
};

int main(){
    tamgiac<int, float> a(3,4,5);
    cout << a.chuvi() << " " << a.dientich() << endl;
    tamgiac<float, double> b(3.5,4.5,5.5);
    cout << b.chuvi() << " "<< b.dientich() << endl;
    return 0;
}
