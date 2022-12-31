#include<iostream>
using namespace std ; 

class Month {
    int month , day ;     
    int checkMonth(int k ) {
        if(k < 1 || k > 12 ) throw "Loi\n" ; 
        return k ;
    }
public:
    Month(int m ) {
        month = checkMonth(m) ; 
        if (m == 2 ) day = 28 ; 
        else if((m == 4 ) || (m == 6 ) || (m == 9) || (m == 11)) day = 30 ; 
        else day = 31 ; 
    }
    friend int operator+ (const Month& a , const Month &b ) {
        return (a.day + b.day); 
    }
    friend ostream & operator << (ostream &out ,const Month & r ){
        cout << "thang "<<r.month << "(" << r.day << "ngay)" << endl ; 
    }
};

int main(){
    try {
        Month a(11) ;
        Month b(6) ; 
        cout << a + b << endl; 
        cout << a ; 
    }catch (const char *e) {
        cout << e << endl ; 
    } 
    return 0 ;
}