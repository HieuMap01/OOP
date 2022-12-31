/*
Cho lớp Point minh hoạ một điểm trên mặt phẳng với toạ độ như sau: 
Cho lớp trừu tượng PhepBienDoi, gồm các thành viên sau:  
•Hàm ảo thuần tuý bienDoi nhận một biến tham chiếu Point và biến đổi biến Point đó. 
•Hàm bienDoiMang nhận vào một mảng Point và kích thước mảng, sau đó gọi hàm bienDoi với từng phần tử mảng, 
cuối cùng in ra toạ độ từng phần tử mảng.
Lớp LatNgang(lật theo chiều ngang) kế thừa lớp PhepBienDoi, có : 
•Thuộc tính private: một biến axis kiểu double 
•Override hàm bienDoiđể đổi biến Pointtruyền vào từ toạ độ (x, y)thành toạ độ (2*axis-x, y)Lớp LatDoc(lật theo chiều dọc) kế thừa PhepBienDoi, có : 
•Thuộc tính private: một biến axis kiểu double 
•Override hàm bienDoiđể đổi biến Pointtruyền vàotừ toạ độ (x, y)thành toạ độ (x, 2*axis -y)Lớp PhepDich(phép dịch) kế thừa lớp PhepBienDoi, có: 
•Thuộc tính private: hai biến shift_x, shift_y
•Override hàm bienDoiđể đổi biến Pointtruyền vào từ toạ độ (x, y) thành toạ độ (x + shift_x, y + shift_y)
•Hàm main tạo một mảng P có 3 phần tử Point, rồi tạo một mảng A có 10 phần tử PhepBienDoigồm cả LatNgang, LatDocvà PhepDich, 
sau cùng duyệt mảng A và gọi hàm bienDoiMangtrên mảng P.
*/
#include <iostream>
using namespace std;
class Point{
    public: 
        double x, y; 
        Point (double x, double y) : x(x), y(y) {}
}; 
class PhepBienDoi : public Point{
    virtual void bienDoi(Point & a) =0;
    int bienDoimang(Point a, int size){
        for(int i=0; i<size; i++){
            a [i].bienDoi();
        }
    }
};
class LatDoc : public Point{
    private: 
      double axis;
    public:
    //LatDoc(){} 
    LatDoc( double a){
        axis=a;
    }
    void bienDoi(Point &a){
        a.y=2*axis-y;
    }
};
class LatNgang : public Point{
    private: 
        double axis;
    public:
       // LatNgang(){}  
        LatNgang( double a){
            axis=a;
        }
        void bienDoi(Point &a){
            a.x=2*axis-x;
        }
};
class PhepDich : public Point
{
    private: 
        double shift_x ;
        double shift_y ;
    public:
        PhepDich(){}  
        PhepDich( double a,double b){
            shift_x=a ;
            shift_y=b;
        }
        void bienDoi(Point &a){
            a.x=x+shift_x;
            a.y=y+shift_y;
        }
};
int main()
{
    Point *a[3]={
        new LatDoc(5),
        new LatNgang(6),
        new PhepDich(5,99)
    };
    for(int i=0; i<3; i++){
        a[i]->bienDoi(a);
    }
}