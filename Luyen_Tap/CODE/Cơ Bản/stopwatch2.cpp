#include<iostream>
using namespace std ; 

class Stopwatch {
    int m , s , ms ;  
    void normalize(){     
        s+= ms/1000;     
        ms%= 1000;     
        m+= s/60;     
        s%= 60; 
    }

public:
    Stopwatch(int phut = 0, int giay = 0, int miligiay = 0)  {
        setInfor(phut,giay,miligiay) ; 
        normalize() ; 
    };  
    void setInfor(int phut, int giay , int miligiay){
        m = phut ; s = giay ; ms = miligiay ; 
        normalize() ; 
    }
    void setMS(int miligiay) {
        ms = miligiay ; 
        normalize() ; 
    }
    float  getsecond () const {
        return m *60 + s + ms ; 
    }
    void print() const {
        cout << m << ":" << s << "," << ms << endl ; 
    }
};

int main(){
    int  phut, giay,miligiay ; 
    cout << "Nhap vao phut" ; cin >> phut ; 
    cout << "Nhap vao giay" ; cin >> giay ; 
    cout << "Nhap vao miligiay" ; cin >> miligiay ; 
    Stopwatch a(phut,giay,miligiay); 
    a.print() ; 
    int temp ; 
    cout << "Nhap so giay ban muon thay doi: " ; cin >> temp ; 
    a.setMS(temp) ;
    a.print() ;  
    return 0 ;
}