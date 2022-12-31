/*
Viết lớp thuần ảo tên là BasicShape mô tả một hình cơ bản trong hình học,gồm các thành viên:
•1 thuộc tính private là area chưa diện tích của hình.
•hàm getAreatrả lại giá trị của area
•hàm calcArea là hàm thuần ảo chịu trách nhiệm tính diện tích,sẽ được cài đặt ghi đè (override)ở các lớpcon
.Viết lớp Circle(hìnhtròn)kế thừa từ BasicShape có:
•centerX:tọa độ tâm hình tròn trên trục X
•centerY:tọa độ tâm hình tròn trên trục Y
•radius: bán kính hình tròn
•hàm khởi tạo 3 tham số ứng với 3 thuộc tính trên
•getter cho 3 thuộc tính
•cài đặt hàm calcArea thực hiện tính diện tích và trả lại giá trị 
Viết lớp Rectangle(hìnhchữnhật)kế thừa từ BasicShape có:
•thuộc tính dài vàrộng
•hàm khởi tạo 2 tham số ứng với 2 thuộc tính dài và rộng
•getter cho cả 2 thuộc tính
•cài đặt hàm calcArea thực hiện tính diện tích và trả lại giá trị
Viết một chương trình minh họa 3 lớp trên Từ bài 3 đến 5,sinh viên tựchọn danh sách tham số, tự đặt chế độ private protected public hợp lý 
để đảm bảo tính hướng đối tượng; chỉ trừ thành viên mà đề đã nêu rõ private hay protected thì cần làm theo yêu cầu
*/
#include<iostream>
#include<math.h>
using namespace std;

class BasicShape{
    float area;
    virtual float calcArea() const = 0;
    protected: 
        void setArea (){area = calcArea(); }
    public: float getArea() const {return area;}
        virtual ~BasicShape(){} 
}; 

class Circle: public BasicShape{
    float centerX, centerY, radius; 
    float calcArea() const {return 3.14 * radius * radius; } 
    public: 
        Circle (float x = 0, float y = 0, float r = 0){ setAll(x,y,r); }
        void setAll(float x, float y, float r){
            centerX = x; 
            centerY = y; 
            radius = r;
            setArea(); }
        float getX() const {return centerX;}
        float getY() const {return centerY;}
        float getRadius() const { return radius;} 
}; 

class Rectangle: public BasicShape{
    float wight,length;
    float calcArea() const {return wight* length; } 
    public:
        Rectangle( float w=0,float l=0){
            setAll( w,l);
        }
        void setAll( float w=0,float l=0){
            this -> wight=w;
            this -> length =l;
            setArea();
        }
        float getWight() const{ return wight;}
        float getLenght() const { return length;}
};

int main(){
    BasicShape * p = new Circle (3,4,5);
    cout << p->getArea() << endl; 
    BasicShape * p1= new Rectangle( 4,5);
    cout<<p1->getArea()<<endl;
    return 0; 
    }

