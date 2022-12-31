#include <iostream>
using namespace std ;
class FuelGauge {
    double nhienLieu ; 
public:
    FuelGauge(double nhienLieu) : nhienLieu(nhienLieu) {}
    double getNhienLieu() const {
        return nhienLieu ; 
    } 
FuelGauge operator++ (int) {
    if (nhienLieu < 15) {
        FuelGauge temp = *this ;
        nhienLieu++ ; 
        return temp ;
    }
    return *this  ;

}
FuelGauge operator-- (int) {
    if (nhienLieu > 0) {
        FuelGauge temp = *this ;
        nhienLieu-- ; 
        return temp ;
    }
    return *this  ;

}  

};
class Odometer{
    double dam ; 
    FuelGauge & f ;
public:
    Odometer(double dam,FuelGauge & f): dam(dam),f(f) {}
    double getDam() const {
        return dam ;
    }
    Odometer operator++ (int) {
    if (dam == 999.999) {
        dam = 0 ; 
        return *this  ;
    }
    else {
        Odometer temp = * this ;
        dam++ ; 
        return temp ; 
    }
    
}
    void khaNang() {
        (*this)++ ;
         f-- ;
    }
};
int main() {
    FuelGauge f(9) ;
    Odometer o(999.999,f) ;
    // do xang cho xe
    // f++ ; 
    // cout << f.getNhienLieu() ;
    for (int i = 0 ; i < 2 ; i ++) {
        // cout <<"dds" ;
        o.khaNang() ;
        if (f.getNhienLieu() == 0 ){
            cout << "Xe het xang\n" ;
            break;
        }
        cout << f.getNhienLieu() << "  " << o.getDam() << endl ;  
    }
}
