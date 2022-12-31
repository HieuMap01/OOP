/*
1. FeetInches (tiếp) 
a.	Viết lại các toán tử (+, =, +=, ==, ++, -- tiền tố hậu tố) dưới dạng hàm bạn bè  
b.	Viết thêm các toán tử sau, tự chọn dạng viết (hàm thành viên hay hàm bạn bè)  
    •	Toán tử quan hệ !=, <, <=, giúp so sánh một FeetInches có khác, nhỏ hơn, nhỏ hơn hay bằng một 
    FeetInches khác hay không. Gợi ý: có thể viết các toán tử này tận dụng lẫn nhau 
    •	Toán tử - giữa 2 đối tượng FeetInches và trả về một đối tượng FeetInches.  
    VD: 5 feet 3 inch trừ 3 feet 5 inch sẽ ra đối tượng FeetInches có giá trị là 1 feet 10 inch.  
    •	Toán tử >> vớt từ dòng nhập 2 số nguyên và cập nhật ra đối tượng FeetInches hợp lệ. 
    •	Toán tử << in ra màn hình thông tin đối tượng FeetInches dạng như:  5 feet 3 inches 
    •	Hàm đổi thông tin feet inch trong đối tượng sang chiều dài dạng cm (làm tròn số nguyên) 
    •	Hàm tạo chuyển số cm nguyên thành chiều dài feet inch (làm tròn feet và inch nguyên) 
*/

#include <iostream>
#include <math.h>
#include<fstream>
using namespace std;
class FeetInches{
    private:
        int feet;                        
        int inches;                     
        void simplify();           
    public:
        FeetInches(int f = 0, int i = 0){
            feet = f;
            inches = i;
            simplify();
        }
        FeetInches(const FeetInches &obj){
            feet = obj.feet;
            inches = obj.inches;
        }
        void setFeet(int f){
            feet = f;
        }
        void setInches(int i){
            inches = i;
             simplify();
        }
        FeetInches multiply(const FeetInches &);
        int getFeet() const { return feet; };
        int getInches() const{ return inches; };

        friend FeetInches operator+ (const FeetInches & left,const FeetInches & right){
            FeetInches temp;
            temp.inches = left.inches + right.inches;
            temp.feet = left.feet + right.feet;
            temp.simplify();
            return  temp;
        }            
        FeetInches operator = (const FeetInches & right){
            this->inches =  right.inches;
            this->feet =  right.feet;
            this->simplify();
            return *this;
        }            
        friend FeetInches operator- (const FeetInches & left,const FeetInches & right){
             FeetInches temp;
            temp.inches = left.inches - right.inches;
            temp.feet = left.feet - right.feet;
            temp.simplify();
            return temp;
        }         
                                   
        friend FeetInches  operator-- (FeetInches & right){
             --(right.inches);
             ++right.feet;
            right.simplify();
            return right;
        }   
        friend FeetInches operator-- (FeetInches & right,int){
            FeetInches temp = right;
            right.inches--;
            right.feet--;
            right.simplify();
            return temp;
        }                              
        friend FeetInches  operator++ (FeetInches & right){
             ++(right.inches);
             ++right.feet;
            right.simplify();
            return right;
        }                              
        friend FeetInches operator++ (FeetInches & right,int){
            FeetInches temp = right;
            right.inches++;
            right.feet++;
            right.simplify();
            return temp;
        }   
        
        friend FeetInches  operator+=( FeetInches & left,const FeetInches & right){
            left.inches += right.inches;
            left.feet += right.feet;
            return left;
        }

        friend bool operator==(const FeetInches & left,const FeetInches & right){
            return left.inches == right.inches && left.feet == right.feet;
        }

        bool operator> (const FeetInches & right){
            bool status;
            if (this->feet > right.feet){
                status = true;
            }else if (this->feet == right.feet && this->inches > right.inches){
                status = true;
            }else{
                status = false;
            }
            return status;
        }               
        bool operator< (const FeetInches & right){
            bool status;
            if (feet < right.feet){
                status = true;
            }else if (feet == right.feet && inches < right.inches){
                status = true;
            }else{
                status = false;
            }
            return status;
        }                
        // bool operator== (const FeetInches & right){
        //     bool status;
        //     if (feet == right.feet && inches == right.inches){
        //         status = true;
        //     }else{
        //         status = false;
        //     }
        //     return status;
        // }                 
        bool operator>= (const FeetInches & right){
            bool status;
            if (feet >= right.feet){
                return true;
            }else if (feet == right.feet && inches >= right.inches){
                status = true;
            }else{
                status = false;
            }
            return status;
        }                
        bool operator<= (const FeetInches & right){
            bool status;
            if (feet <= right.feet){
                status = true;
            }else if (feet == right.feet && inches <= right.inches){
                status = true;
            }else{
                status = false;
            }
            return status;
        }                  
        bool operator!= (const FeetInches & right){
            bool status;
            if (feet != right.feet){
                status = true;
            }else if (feet == right.feet && inches != right.inches){
                status = true;
            }else{
                status = false;
            }
            return status;
        }              
        friend ostream & operator << (ostream & strm, const FeetInches & obj){
            strm << obj.feet << " feet, " << obj.inches << " inches";
            return strm;
        }
        friend istream &operator >> (istream & strm, FeetInches & obj){
            cout << "Feet: ";
            strm >> obj.feet;
            cout << "Inches: ";
            strm >> obj.inches;
            obj.simplify();
            return strm;
        }
        int doiSangCm (const FeetInches & l ) {
            int temp = round(l.feet * 30.4 + l.inches * 2.54) ;
            return temp ; 
        }
};
void FeetInches::simplify(){
    if (inches >= 12){
        feet += (inches / 12);
        inches = inches % 12;
    }else if (inches < 0){
        feet -= ((abs(inches) / 12) + 1);
        inches = 12 - (abs(inches) % 12);
    }
}
FeetInches FeetInches::multiply(const FeetInches &right){
    FeetInches temp;
    temp.inches = ((feet * 12 + inches) * (right.feet * 12 + right.inches));
    temp.inches /= 12;
    temp.simplify();
    return temp;
}
int main(){
    FeetInches first(15, 4);
    FeetInches second = first;   
    FeetInches third, fourth;
    cout << first << " * " << second << " = ";
    cout << first.multiply(second) << " \n";
    cout << "Nhap them khoang cach bang feet va inches:\n";
    cin >> third;
    cout << "Nhap them khoang cach bang feet va inches:\n";
    cin >> fourth;
    cout <<third << " * " << fourth << " = ";
    cout << (third.multiply(fourth)) << endl;
    FeetInches f1(3, 14);
    FeetInches f2(10, 16);
    FeetInches f3;
    f3 = f1 + f2;
    FeetInches f4 = f1;
    FeetInches f5(f2);
    FeetInches f6;
    f2+=f3;
    //f1++;//hậu tố
    ++f1;//tiền tố
    cout << f1.getFeet() << " " << f1.getInches() << endl;
    cout << f3.getFeet() << " " << f3.getInches() << endl;
    cout << f4.getFeet() << " " << f4.getInches() << endl;
    cout << f2.getFeet() << " " << f2.getInches() << endl;
    return 0;
}