#include <iostream>
#include <iomanip>
using namespace std;
class Circle{
    const double PI = 3.14159;
    double radius = 0;
public:
    Circle(){}
    Circle(double r = 0) {radius = r;}
    void setRadius(double r) {radius = r;}
    double getRadius() {return radius;}
    double getArea() {return PI * radius * radius;}
    double getDiameter() {return 2 * radius;}
    double getCircumference() {return PI * getDiameter();}
};
int main(){
    double r;
    cout << setprecision(2) << fixed;
    cout << "Nhap vao ban kinh hinh tron: ";
    do{
        cin >> r;
    }while(r < 0);
    Circle c(r);
    cout << "Duong kinh hinh tron = " << c.getDiameter() << endl;
    cout << "Dien tich hinh tron  = " << c.getArea() << endl;
    cout << "Chu vi hinh tron     = " << c.getCircumference() << endl;
    return 0;
}