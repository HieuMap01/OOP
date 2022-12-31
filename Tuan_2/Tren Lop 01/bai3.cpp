// VD: Nạp chồng phép cộng
// Viết toán tử cộng 2 con mèo, trả về một con mèo có tên và tuổi giống con mèo toán hạng 
// trái(con mèo đầu tiên) còn cân nặng bằng tổng cân của 2 con mèo
// Viết hàm main thử sinh 2 con mèo, cộng chúng rồi in ra tên, tuổi, 
// cân nặng của con mèo kết quả
/*
#include<iostream>
using namespace std;

class Cat{
    
    string name ;
    int age;
    float weight;
    public:
    Cat(){setInfor("Bibi", 1, 2);}
    Cat (string name){setInfor(name, 1, 2);}
    Cat(string n, int a){setInfor(n, a, 2);}
    Cat(string n, int a, float w){setInfor(n, a, w);}
    void setInfor(string n, int a, float w){
        name = n;
        age = a;
        weight = w;
    }
    // Nhưng nếu muốn, ta có thể thử viết hàm tạo sao chép cho lớp Cat 
    // Cat(const Cat &c){
    //     name = c.name;
    //     age = c.age;
    //     weight = c.weight;
    //     cout << "Ham tao sao chep";
    //     catCount++;
    // }
    string getName() const { return name; }
    int getAge() const { return age; }
    float getWeight() const { return weight; }
    void meow() const {}
    int chaseMouse(int n) const { return 0; }
    // Thêm vào lớp Cat một biến count đếm số mèo đã sinh ra
    static int catCount;
    
    // Cong
    Cat operator+ (Cat a){
        weight += a.weight;
        return *this;
    }
};
// Thêm vào lớp Cat một biến count đếm số mèo đã sinh ra
int Cat::catCount = 0;

Cat inputCat(const Cat &c){
    cout << Cat::catCount << endl;
    return c;
}

int main(){
    Cat c("c", 12, 35);
    Cat d("d", 7, 40);
    Cat x = c+d;
    cout << x.getName() << " " << x.getAge() << " " << x.getWeight();
    return 0;
}
*/
//a. Viết toán tử cộng một con mèo và một số nguyên trả về con mèo cùng tên, 
// cùng tuổi, có số cân tăng lên đúng
// số nguyên đó
// Viết hàm main thử sinh 2 con mèo, cộng chúng rồi in ra tên, tuổi, cân nặng của con mèo kết quả
#include<iostream>
using namespace std;

class Cat{
    
    string name ;
    int age;
    float weight;
    public:
    Cat(){setInfor("Bibi", 1, 2);}
    Cat (string name){setInfor(name, 1, 2);}
    Cat(string n, int a){setInfor(n, a, 2);}
    Cat(string n, int a, float w){setInfor(n, a, w);}
    void setInfor(string n, int a, float w){
        name = n;
        age = a;
        weight = w;
    }
    // Nhưng nếu muốn, ta có thể thử viết hàm tạo sao chép cho lớp Cat 
    // Cat(const Cat &c){
    //     name = c.name;
    //     age = c.age;
    //     weight = c.weight;
    //     cout << "Ham tao sao chep";
    //     catCount++;
    // }
    string getName() const { return name; }
    int getAge() const { return age; }
    float getWeight() const { return weight; }
    void meow() const {}
    int chaseMouse(int n) const { return 0; }
    // Thêm vào lớp Cat một biến count đếm số mèo đã sinh ra
    static int catCount;
    
    //a. Cong
    // Cat operator+ (int a){
    //     return Cat(name, age, weight+a);
    // }
 //Viết toán tử cộng mèo với mèo trả về tổng cân 2 mèo
    Cat operator+ (Cat a){
        return Cat(name, age+a.age, weight);
    }
 //Viết toán tử tru mèo với mèo trả về tổng cân 2 mèo
    Cat operator- (Cat a){
        return Cat(name, age-a.age, weight);
    }
};
// Thêm vào lớp Cat một biến count đếm số mèo đã sinh ra
int Cat::catCount = 0;

Cat inputCat(const Cat &c){
    cout << Cat::catCount << endl;
    return c;
}

int main(){
    Cat c("c", 12, 35);
    Cat d("d", 7, 40);
    Cat b = c+d;
    Cat x = c-d;
    cout << "Tru: "<< x.getName() << " " << x.getAge() << " " << x.getWeight();
    cout << "Cong: "<< b.getName() << " " << b.getAge() << " " << b.getWeight();
    return 0;
}