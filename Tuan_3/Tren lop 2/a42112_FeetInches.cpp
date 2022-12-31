#include <iostream>
#include <math.h>
using namespace std ; 
class FeetInches {
    int feet;
    int inches;
    void simplify() {
        if(inches >= 12){
            feet += (inches / 12);
            inches = inches % 12;}
        else if (inches < 0){
            feet -= ((abs(inches) / 12) + 1);
            inches = 12-(abs(inches) % 12);}
        }
public:
    //hàm tạo
    FeetInches(int f = 0, int i = 0) { 
        feet = f;
        inches = i;
        simplify(); 
        }
        void setFeet(int f) { 
            feet = f;
        }
        void setInches(int i) { 
            inches = i;
            simplify(); }
        int getFeet() const{ return feet; }
        int getInches() const{ return inches; }
        // FeetInches operator+ ( const FeetInches &right){
        //     FeetInches temp;
        //     temp.inches = inches + right.inches;
        //     temp.feet = feet + right.feet;
        //     temp.simplify();
        //     return temp;
        //     }
        FeetInches  operator = (const FeetInches & r){
            feet = r.feet ; 
            inches = r.inches ;
            return FeetInches(feet,inches) ; 
        }
        // FeetInches operator += (const FeetInches & r){
        //     inches += r.inches  ; 
        //     feet += r.feet ; 
        //     return FeetInches(feet,inches) ; 
        // }
        // bool operator == (const FeetInches & r){
        //     if (feet == r.feet && inches == r.inches) return 1 ;  
        //     return 0  ; 
        
        // }
        // // kieu tien to ???
        // FeetInches  operator ++ () {
        //     feet ++ ; 
        //     inches ++ ; 
        //     return FeetInches(feet,inches)  ; 
             
        // }
        // // kieu hau to 
        // FeetInches  operator ++ (int) {
        //     FeetInches templ = *this ; 
        //     feet++ ; 
        //     inches++ ; 
        //     return FeetInches(templ.feet,templ.inches) ; 
             
        // }
        
        friend  FeetInches  operator + ( const FeetInches & l , const FeetInches & r){
            return FeetInches (l.feet + r.feet , l.inches + r.inches) ; 
            }
        // friend FeetInches  operator = (  FeetInches  r){
           
        // }
        friend  FeetInches  operator += (FeetInches & l , const FeetInches & r){
            l.inches += r.inches  ; 
            l.feet += r.feet ; 
            return FeetInches(l.feet,l.inches) ; 
        }
          friend bool operator == (const FeetInches & l,const FeetInches & r){
            if (l.feet == r.feet && l.inches == r.inches) return 1 ;  
            return 0 ; 
        }
         // kieu tien to ???
        friend  FeetInches  operator ++ (FeetInches & l) {
            l.feet ++ ; 
            l.inches ++ ; 
            return FeetInches(l.feet,l.inches)  ; 
             
        }
        // kieu hau to 
        friend FeetInches  operator ++ (FeetInches & l,int) {
            FeetInches templ (l.feet,l.inches) ;
            l.feet++ ; 
            l.inches++ ; 
            return FeetInches(templ.feet,templ.inches) ; 
             
        }
          // kieu tien to ???
        friend  FeetInches  operator -- (FeetInches & l) {
            l.feet -- ; 
            l.inches -- ; 
            return FeetInches(l.feet,l.inches)  ; 
             
        }
        // kieu hau to 
        friend FeetInches  operator -- (FeetInches & l,int) {
            FeetInches templ (l.feet,l.inches) ;
            l.feet-- ; 
            l.inches-- ; 
            return FeetInches(templ.feet,templ.inches) ; 
             
        }
        friend bool operator != (const FeetInches & l,const FeetInches & r){
            if (l == r) return 0 ;
            return 1 ;
        }
        friend bool operator < (const FeetInches & l,const FeetInches & r){
            if (l != r) 
                if (l.feet < r.feet ) return 1 ; 
                else if  ( l.feet == r.feet) 
                {
                   if (l.inches < r.inches  ) return 1 ;
                   return 0 ; 
                }

        }
        friend bool operator <= (const FeetInches & l,const FeetInches & r){
            if (l < r || l == r) return 1 ; 
            return 0 ;  

        }
        friend  FeetInches  operator - ( const FeetInches & l , const FeetInches & r){
            int temp = l.inches - r.inches ; 
            if (temp >= 0 ) return FeetInches (l.feet - r.feet , temp) ; 
            else return FeetInches (l.feet - r.feet - 1 , 12 + temp) ; 
        }
        friend ostream & operator << (ostream & out , const FeetInches & r) {
            out << r.feet <<" feet " << r.inches <<" inches." ;
            return out ; 
        }
        friend istream & operator >> (istream & in ,  FeetInches & r) {
            in >> r.feet >> r.inches ;
            r.simplify();
            return in ; 
        }
        int doiSangCm (const FeetInches & l ) {
            int temp = round(l.feet * 30.4 + l.inches * 2.54) ;
            return temp ; 

        }
        int doiSangCm (const FeetInches & l ) {
            int temp = round(l.feet * 30.4 + l.inches * 2.54) ;
            return temp ; 

        }
            //ham tao sao chep  
        FeetInches (const FeetInches & r  )  {
            feet = r.feet ;  
            inches = r.inches ; 
        }
        FeetInches multiply (const FeetInches & r) { 
            return FeetInches(feet * r.feet ,inches * r.inches) ;

        }
};
int main () {
    FeetInches i1 (7,15 ) , i2(3,6) ; 
    //FeetInches i2 = i ; 
//    cout << i2.getFeet() << endl ; 
//     cout << (i+=i2).getFeet() << endl ; 
    //cout << (i == i2) ;  
    // tra ve  kieu hau to 
    // cout <<(i++).getFeet() ;
    // cout << i.getFeet() ; 
    // // tra ve tien to
    // cout << (++i).getFeet() ;
    // FeetInches i3 = FeetInches(i) ;
    // cout <<i3.getFeet() ;
    // cout << i.multiply(i).getFeet() <<endl ; 
    //  cout << i.multiply(i).getInches() ;
    ///            bonus

    /* SU DUNG HAM MULTIPLY THAY VI TOAN TU * VI :
     + KHI NHAN 2 INCHES VOI NHAU CO THE SE RA SO LON HON 12 SE VI PHAM CHUAN HOA FEET INCHES 
     --> pHAI SU DUNG HAM MUTIPLY
    */
   
    //cout <<  (i1 - i2).getFeet() << "    " << (i1 - i2).getInches()    ;
    // FeetInches i3 ;  
    // cin >> i3  ;
    // cout << i3 ;
    cout << i1.doiSangCm(i1) ;

}
