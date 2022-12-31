#include<iostream>
using namespace std ; 

class banhang{
    int thang , doanhthu , chiphi , loinhuan ; 
    int getLoiNhuan(){
        loinhuan = doanhthu - chiphi ; 
        return loinhuan ; 
    }
    static int sum_dt ; 
public: 
    banhang(int m , int d, int c){
        setinfor(m,d,c) ; 
        getLoiNhuan() ;
    }
    void setinfor(int m , int d, int c){
        thang = m ; doanhthu = d ; chiphi = c ;
        sum_dt += doanhthu ; 
        getLoiNhuan() ; 
    }
    friend ostream & operator << (ostream & out,const banhang & r ) {
        cout << "Thang: " << r.thang << endl 
             << "doanh thu: " << r.doanhthu << endl
             << "Chi phi: " << r.chiphi << endl 
             << "Loi nhuan: " << r.loinhuan << endl ;  
    }
    static int getsumdt() {
        return sum_dt ; 
    }
};
int banhang :: sum_dt = 0 ; 
int main(){
    banhang a(2,30,30) ;
    banhang b(5,60,60);
    banhang c(6,80,80); 
    cout << a  ; 
    cout << banhang ::getsumdt() << endl ; 
}