#include<iostream>
using namespace std ; 

class DoDai {
    int met , centimet ; 
    void chuanHoa() {
		met = met + centimet / 100;
		centimet = centimet % 100;
	}
    static int count ; 
public:
    DoDai (int m = 0, int cm = 0) : met(m) , centimet(cm) {
        chuanHoa() ; 
        count++ ; 
    }
    friend DoDai operator+ (const DoDai & a ,const  DoDai & b ) {
        DoDai r ; 
        r.met = a.met + b.met ; 
        r.centimet = a.centimet + b.centimet ; 
        r.chuanHoa() ; 
        return r ; 
    }
    friend DoDai Getmax(const DoDai & a, const DoDai &b) ; 
    void print() const {
        cout << met << " " << centimet << endl ; 
    } 
    //test cái hàm tạo
    friend ostream & operator << (ostream & out , const DoDai & r) {
        cout << r.met  << " " << r.centimet ; 
    } 
    //phần này thêm vô để test cái getmax 
};

DoDai Getmax(const DoDai & a, const DoDai &b){
    int temp_1 = a.centimet + a.met*100 ; 
    int temp_2 = b.centimet + b.met*100 ;
    if(temp_1 >= temp_2) return a ;
    else return b ; 
}
int DoDai :: count = 0 ;
int main(){
    DoDai a(3 , 500) ; 
    a.print() ; 
    DoDai b(6,50); 
    b.print() ; 
    cout <<  Getmax(a,b) ; 
    return 0 ;
}