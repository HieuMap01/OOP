#include<iostream>
using namespace std;

class Shape{
    double area;
    public:
        void setArea(double a){
            area = a;
        }
        double getArea() const {
            return area;
        }
};

class Cirle: public Shape{
    double R;
    const double PI = 3.14;
    public:
        void setR(double r){
            R = r;
            setArea(PI*R*R);
        }
        double getR() const{
            return R;
        }
};

int main(){
    Shape s;
    s.setArea(12.3);
    cout << "Dien tich: "<< s.getArea() << endl;
    Cirle c;
    c.setR(12);
    cout << "Ban kinh: "<< c.getR()<< endl;
    cout << "Dien tich: "<< c.getArea()<< endl;

}