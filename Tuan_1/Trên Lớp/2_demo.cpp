// con trỏ this 

class SomeClass
{
    int num;
public:
    void setNum(int num){ this->num = num; }
};

#include <iostream> 
using namespace std; 
class CpClass  // copying pointer classs - lớp để test việc copy con trỏ
{
    int *p;  
public:
    CpClass(int v=0){ p = new int; *p = v;}
    ~CpClass(){delete p;}
    CpClass(const CpClass & r){ // cần tự viết hàm tạo sao chép 
        p = new int;            // cấp phát vùng nhớ mới cho con trỏ 
        *p = *r.p;              // sao chép dữ liệu thay vì sao chép con trỏ 
    } 
    CpClass operator=(CpClass r){
        *p = *(r.p); 
        return *this;
    }
    int get() const {return *p; }
    void set(int v) {*p = v; }
};

int main(){
    CpClass c1(5); 
    CpClass c2(3); 
    c2 = c1; // có vấn đề nếu ko nạp chồng toán tử = 
    cout << c1.get() << endl; 
    cout << c2.get() << endl; 
    c2.set(7); 
    cout << c1.get() << endl; 
    return 0; 

}




