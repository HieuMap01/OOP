// VD: Cấp phát động và hàm tạo Lớp Cat đang có 4 hàm tạo (0, 1, 2,3 tham số)
// nThêm vào mỗi hàm tạo này một lệnh in ra thông báo đang ở hàm tạo nàonMain sinh ra 4 
// biến con trỏ Cat, cấp phát động bằng 4 loại hàm tạo, sau đó thông qua con trỏ lấy thông 
// tin của từng con mèo in ra, sau cùng cập nhật lại thông tin của 1 con, 
// rồi in ra thông tin mới này. 
/*
#include<iostream>
using namespace std;

class Cat{
    string name ;
    int age;
    float weight;
    public:
    Cat(){setInfor("Bibi", 1, 2); cout << "Ham tao mac dinh\n";}
    Cat (string name){setInfor(name, 1, 2); cout << "Ham tao 1 tham so\n";}
    Cat(string n, int a){setInfor(n, a, 2); cout << "Ham tao 2 tham so\n";}
    Cat(string n, int a, float w){setInfor(n, a, w); cout << "Ham tao 3 tham so\n";}
    //Cat (string name, int age, float weight): name(name), age(age), weight (weight){}
    void setInfor(string n, int a, float w){
    name = n;
    age = a;
    weight = w;
    }
    string getName() const { return name; }
    int getAge() const { return age; }
    float getWeight() const { return weight; }
    void meow() const {}
    int chaseMouse(int n) const { return 0; }
    
};

int main(){
    Cat *c1 = new Cat,
        *c2 = new Cat("tom"),
        *c3 = new Cat("tam",2),
        *c4 = new Cat("tim",3,4);
    cout << c1->getName() << " " << c1->getAge() << " " << c1->getWeight() << endl;
    cout << c2->getName() << " " << c2->getAge() << " " << c2->getWeight() << endl;
    cout << c3->getName() << " " << c3->getAge() << " " << c3->getWeight() << endl;
    cout << c4->getName() << " " << c4->getAge() << " " << c4->getWeight() << endl;
    c1->setInfor("dog", 4, 6);
    cout << c1->getName() << " " << c1->getAge() << " " << c1->getWeight() << endl;
    return 0;
}
*/

// VD: Giải phóng và hàm huỷ
// Thêm vào hàm huỷ lớp Cat một lệnh in ra thông báo đang ở hàm huỷ
// Viết hàm inputCat nhận vào 1 biến Cat, không trả về và không làm gì nViết hàm main sinh ra 1 biến 
// Cat để truyền vào gọi hàm inputCat, sau đó sinh ra 1 con trỏ Cat, cấp phát động bằng hàm 
// tạo nào đó, sau đó delete con trỏ này


#include<iostream>
using namespace std;

class Cat{
    string name ;
    int age;
    float weight;
    public:
    Cat(){setInfor("Bibi", 1, 2); cout << "Ham tao mac dinh\n";}
    Cat (string name){setInfor(name, 1, 2); cout << "Ham tao 1 tham so\n";}
    Cat(string n, int a){setInfor(n, a, 2); cout << "Ham tao 2 tham so\n";}
    Cat(string n, int a, float w){setInfor(n, a, w); cout << "Ham tao 3 tham so\n";}
    ~Cat(){cout << "Ham huy\n";}
    void setInfor(string n, int a, float w){
    name = n;
    age = a;
    weight = w;
    }
    string getName() const { return name; }
    int getAge() const { return age; }
    float getWeight() const { return weight; }
    void meow() const {}
    int chaseMouse(int n) const { return 0; }
    
};

void inputCat(Cat c){}

int main(){
    Cat c;
    inputCat(c);
    Cat *c1 = new Cat;
    delete c1;
    return 0;
}
