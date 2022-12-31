/*
Viết lớp Shape3D mô tả hình 3D, có các thành viên:
    Biến volume chỉ thể tích, với setter và getter cho nó
Viết lớp Cube mô tả hình hộp vuông, kế thừa Shape3D và bổ sung:
    Biến size chỉ độ dài cạnh hình hộp, với setter và getter cho nó
Viết main demo 2 lớp trên:
Tạo biến Shape3D, đặt thể tích, rồi in ra thể tích
Tạo biến Cube, đặt độ dài cạnh, in ra độ dài cạnh và thể tích hình
*/


#include<iostream>
using namespace std;

class Shape3D{
    double valume;
    public:
        Shape3D(double v = 0): valume(v){}
        void setValume(double v){
            valume = v;
        }
        double getValume()const { return valume;}
        void print() const{
            cout << valume << endl;
        }
};

class Cube: public Shape3D{
    double size;
    void setValume(){Shape3D :: setValume(size*size*size);}
    public:
        void setSize(double s){
            size = s;
            setValume();
        }
        Cube(double s = 0){setSize(s);}
        double getSize()const{ return size;}
        void print() const{
            Shape3D::print();
            cout << size << endl;
        }

};

int main(){
    Shape3D s(5);
    //s.setValume(5);
    cout << s.getValume() << endl;
    Cube c(10);
    //c.setValume(10);
    cout << c.getValume();
    return 0;
}