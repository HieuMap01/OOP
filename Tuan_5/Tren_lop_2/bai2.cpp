#include<iostream>
using namespace std;

class BasicShape
{
    double area;
    virtual double calcArea() const = 0;
protected:
    void setArea() {area = calcArea();}
public:
    double getArea() const {return area;}
    virtual ~ BasicShape(){}
};

class Circle :public BasicShape
{
    double centerX, centerY;
    double radius;
    double calcArea() const {return 3.14 * radius * radius;}
public:
    void setRadius(double r){
        radius = r;
        setArea();
    }
    Circle(double x= 0, double y= 0, double r = 0) {setRadius(r);}
    double getCenterX() const {return centerX;}
    double getCenterY() const {return centerY;}
    double getRadius() const {return radius;}
};

class Rectangle: public BasicShape{
    double length, width;
    double calcArea() const {return length * width;}
public:
    void setLength(double l){
        length = l;
        setArea();
    }
    void setWidth(double w){
        width = w;
        setArea();
    }
    Rectangle(double l, double w): length(l), width(w) {setArea();}
    double getLength() const {return length;}
    double getWidth() const {return width;}
};

int main()
{
    Circle c(5,7,9);
    cout << "Dien tich hinh tron la: " << c.getArea() << endl;
    Rectangle r(5,7);
    cout << "Dien tich hinh chu nhat la: " << r.getArea() << endl;
    BasicShape * b[3] = {new Circle(15,7,3),
                        new Circle(8,12,19), new Rectangle(22,1)};
    for(int i = 0; i < 3; i++){
        cout << b[i]->getArea();
        cout << endl;
    }
    return 0;
}
