#include <iostream> 
#include <ctime> 
#include <cstdlib>
using namespace std;
/*
Nhớ lại lớp Cat đang có 4 hàm tạo (0, 1, 2,3 tham số)
Thêm vào mỗi hàm tạo này một lệnh in ra thông báo đang ở hàm tạo nào
Viết hàm main sinh ra 4 biến con trỏ Cat, cấp phát động bằng 4 loại hàm tạo, sau đó thông qua con trỏ lấy
 thông tin của từng con mèo in ra, cập nhật lại thông tin của 1 con, rồi in ra thông tin mới. 
*/

// class Cat{
//     string name; 
//     int age; 
//     float weight; 
//     bool chase() const { return rand() % 2; }
// public:  
//     Cat(){setInfor("Bibi", 1, 2); cout << "Ham tao mac dinh\n"; }
//     Cat (string name){ setInfor(name, 1, 2); cout << "Ham tao 1 tham so\n";  }
//     Cat(string n, int a){ setInfor(n, a, 2); cout << "Ham tao 2 tham so\n"; }
//     Cat(string n, int a, float w){ setInfor(n, a, w); cout << "Ham tao 3 tham so\n"; }

//     void setInfor(string n, int a, float w){ 
//         name = n;  
//         age = a;
//         weight = w;
//     } 

//     string getName() const { return name; } 
//     int getAge() const { return age; } 
//     float getWeight() const { return weight; }
//     void meow() const {} 
//     int chaseMouse(int n) const; 
// };

// int Cat::chaseMouse(int n) const {
//     int count = 0; 
//     for (int i = 0; i<n; i++)
//         count += chase(); 
//     return count; 
// }  

// int main(){
//     Cat *c1 = new Cat, 
//         *c2 = new Cat("Tom"), 
//         *c3 = new Cat("Mimi", 2), 
//         *c4 = new Cat ("Toto", 3, 4); 
    // cout << c1->getName() << " " << c1->getAge() << " " << c1->getWeight() << endl; 
//     cout << c2->getName() << " " << c2->getAge() << " " << c2->getWeight() << endl; 
//     cout << c3->getName() << " " << c3->getAge() << " " << c3->getWeight() << endl; 
//     cout << c4->getName() << " " << c4->getAge() << " " << c4->getWeight() << endl; 
//     c1->setInfor("Karl", 4, 5); 
//     cout << c1->getName() << " " << c1->getAge() << " " << c1->getWeight() << endl; 
//     return 0; 
// }

/*
    Thêm vào hàm huỷ lớp Cat một lệnh in ra thông báo đang ở hàm huỷ
    Viết hàm inputCat nhận vào 1 biến Cat, không trả về và không làm gì 
    Viết hàm main sinh ra 1 biến Cat để truyền vào gọi hàm inputCat, sau đó sinh ra 1 con trỏ Cat, 
    cấp phát động bằng hàm tạo nào đó, sau đó delete con trỏ này
*/

// class Cat{
//     string name; 
//     int age; 
//     float weight; 
//     bool chase() const { return rand() % 2; }
// public:  
//     Cat(){setInfor("Bibi", 1, 2); cout << "Ham tao mac dinh\n"; }
//     Cat (string name){ setInfor(name, 1, 2); cout << "Ham tao 1 tham so\n";  }
//     Cat(string n, int a){ setInfor(n, a, 2); cout << "Ham tao 2 tham so\n"; }
//     Cat(string n, int a, float w){ setInfor(n, a, w); cout << "Ham tao 3 tham so\n"; }
//     ~Cat(){ cout << "Ham huy\n"; }
//     void setInfor(string name, int a, float w){ 
//         this->name = name;  // what is "this"? 
//         age = a;
//         weight = w;
//     } 
//     string getName() const { return name; } 
//     int getAge() const { return age; } 
//     float getWeight() const { return weight; }
//     void meow() const {} 
//     int chaseMouse(int n) const; 
// };

// int Cat::chaseMouse(int n) const {
//     int count = 0; 
//     for (int i = 0; i<n; i++)
//         count += chase(); 
//     return count; 
// }  
// void inputCat(Cat c){ }
// int main(){
//     Cat c; 
//     inputCat(c); 
//     Cat *c1 = new Cat;
//     delete c1;  
//     return 0; 
// }

/*
Thêm biến tĩnh count đếm số mèo đã sinh ra 
Đổi hàm inputCat thành nhập vào một con mèo và trả về chính con đó

*/

// class Cat{
//     string name; 
//     int age; 
//     float weight; 
//     bool chase() const { return rand() % 2; }
// public:  
//     static int count;
//     Cat(){
//         setInfor("Bibi", 1, 2); 
//         // cout << "Ham tao mac dinh\n"; 
//         count++;
//     }
//     Cat (string name){ 
//         setInfor(name, 1, 2); 
//         cout << "Ham tao 1 tham so\n";
//         count++;  
//     }
//     Cat(string n, int a){ 
//         setInfor(n, a, 2); 
//         cout << "Ham tao 2 tham so\n"; 
//         count++;
//     }
//     Cat(string n, int a, float w){ 
//         setInfor(n, a, w); 
//         cout << "Ham tao 3 tham so\n"; 
//         count++;
//     }
//     void setInfor(string n, int a, float w){ 
//         name = n; 
//         age = a;
//         weight = w;
//     } 
//     string getName() const { return name; } 
//     int getAge() const { return age; } 
//     float getWeight() const { return weight; }
//     void meow() const {} 
//     int chaseMouse(int n) const; 
//     int getCount() const {return count; }
// };
// void inputCat (Cat c){
//     cout << Cat::count << endl; 
// }
// int Cat::count = 0; 
// int main(){
//     Cat c1; 
//     cout << c1.count << endl; 
//     cout << Cat::count << endl; 
//     Cat * c2 = new Cat; 
//     cout << Cat::count << endl; 
//     inputCat(c1); 
//     cout << Cat::count << endl; 
//     delete c2; 
//     cout << Cat::count << endl; 
// }

// int Cat::chaseMouse(int n) const {
//     int count = 0; 
//     for (int i = 0; i<n; i++)
//         count += chase(); 
//     return count; 
// } 
// Cat inputCat(Cat c){
//     cout << c.getCount() << endl; 
//     return c;
// } 
// int main(){
//     Cat c1; 
//     cout << c1.getCount() << endl; 
//     Cat * pC2 = new Cat; 
//     cout << pC2->getCount() << endl; 
//     cout << c1.getCount() << endl;
//     inputCat(c1); 
//     cout << pC2->getCount() << endl; 
//     cout << c1.getCount() << endl;
//     delete pC2; 
//     cout << c1.getCount() << endl; 
//     return 0; 
// }

/*
Thêm hàm tĩnh getCount trả về số mèo đã sinh ra 
Trong main in ra số mèo như bài trước bằng cách gọi hàm này qua lớp thay vì đối tượng
*/

// class Cat{
//     string name; 
//     int age; 
//     float weight; 
//     bool chase() const { return rand() % 2; }
//     static int count; 
// public:  
//     Cat(){
//         setInfor("Bibi", 1, 2); 
//         cout << "Ham tao mac dinh\n"; 
//         count++;
//     }
//     Cat (string name){ 
//         setInfor(name, 1, 2); 
//         cout << "Ham tao 1 tham so\n";
//         count++;  
//     }
//     Cat(string n, int a){ 
//         setInfor(n, a, 2); 
//         cout << "Ham tao 2 tham so\n"; 
//         count++;
//     }
//     Cat(string n, int a, float w){ 
//         setInfor(n, a, w); 
//         cout << "Ham tao 3 tham so\n"; 
//         count++;
//     }
//     void setInfor(string n, int a, float w){ 
//         name = n; 
//         age = a;
//         weight = w;
//     } 
//     string getName() const { return name; } 
//     int getAge() const { return age; } 
//     float getWeight() const { return weight; }
//     void meow() const {} 
//     int chaseMouse(int n) const; 
//     static int getCount() {return count; }
// };

// int Cat::count = 0; 

// int Cat::chaseMouse(int n) const {
//     int count = 0; 
//     for (int i = 0; i<n; i++)
//         count += chase(); 
//     return count; 
// }

// Cat inputCat(Cat c){
//     cout << Cat::getCount() << endl;
//     return c;
// } 
// int main(){
//     Cat c1;  
//     cout << Cat::getCount() << endl; 
//     Cat * pC2 = new Cat; 
//     cout << Cat::getCount() << endl; 
//     inputCat(c1); 
//     cout << Cat::getCount() << endl; 
//     delete pC2; 
//     cout << Cat::getCount() << endl;  
//     return 0; 
// }

/*
Viết hàm tạo sao chép cho lớp Cat 
Cập nhật lại chương trình đếm số mèo sinh ra để đảm bảo count đếm được mọi con mèo sinh ra 
kể cả những con mèo sao chép
Tạo một hàm inputCat nhập vào một con mèo và trả về chính con mèo đó
Tạo hàm main sinh 1 đối tượng mèo, 1 con mèo cấp phát động, truyền con mèo vào hàm inputCat
Thể hiện số mèo sinh ra sau từng bước 

*/

// class Cat{
//     string name; 
//     int age; 
//     float weight; 
//     bool chase() const { return rand() % 2; }
//     static int count; 
// public:  
//     Cat(){
//         setInfor("Bibi", 1, 2); 
//         cout << "Ham tao mac dinh\n"; 
//         count++;
//     }
//     Cat (string name){ 
//         setInfor(name, 1, 2); 
//         cout << "Ham tao 1 tham so\n";
//         count++;  
//     }
//     Cat(string n, int a){ 
//         setInfor(n, a, 2); 
//         cout << "Ham tao 2 tham so\n"; 
//         count++;
//     }
//     Cat(string n, int a, float w){ 
//         setInfor(n, a, w); 
//         cout << "Ham tao 3 tham so\n"; 
//         count++;
//     }
//     Cat (const Cat & r)
//     // cách 1 để khởi tạo tham số
//     // : name (r.name), age(r.age), weight(r.weight)
//     {

//         // cách 2
//         // setInfor (r.name, r.age, r.weight); 

//         // cách 3
//         // name = r.name; 
//         // age = r.age; 
//         // weight = r.weight; 

//         // cách 4
//         *this = r; 
//         cout << "Ham tao sao chep\n"; 
//         count++; 
//     }
//     void setInfor(string n, int a, float w){ 
//         name = n; 
//         age = a;
//         weight = w;
//     } 
//     string getName() const { return name; } 
//     int getAge() const { return age; } 
//     float getWeight() const { return weight; }
//     void meow() const {} 
//     int chaseMouse(int n) const; 
//     static int getCount() {return count; }



// int Cat::count = 0; 

// int Cat::chaseMouse(int n) const {
//     int count = 0; 
//     for (int i = 0; i<n; i++)
//         count += chase(); 
//     return count; 
// }

// const Cat & inputCat(Cat c){
//     cout << Cat::getCount() << endl; 
//     return c;
// } 
// int main(){
//     Cat c1; 
//     cout << Cat::getCount() << endl; 
//     Cat * p1 = new Cat; 
//     cout << Cat::getCount() << endl; 
//     inputCat(c1); 
//     cout << Cat::getCount() << endl; 
//     return 0; 
// }

/*
Viết toán tử cộng 2 con mèo, trả về một con mèo có tên và tuổi giống con mèo toán hạng trái (con mèo đầu tiên)
còn cân nặng bằng tổng cân của 2 con mèo 
Viết hàm main thử sinh 2 con mèo, cộng chúng rồi in ra tên, tuổi, cân nặng của con mèo kết quả 
// */

// class Cat{
//     string name; 
//     int age; 
//     float weight; 
//     bool chase() const { return rand() % 2; }
//     static int count; 
// public:  
//     Cat(){
//         setInfor("Bibi", 1, 2); 
//         // cout << "Ham tao mac dinh\n"; 
//         count++;
//     }
//     Cat (string name){ 
//         setInfor(name, 1, 2); 
//         // cout << "Ham tao 1 tham so\n";
//         count++;  
//     }
//     Cat(string n, int a){ 
//         setInfor(n, a, 2); 
//         // cout << "Ham tao 2 tham so\n"; 
//         count++;
//     }
//     Cat(string n, int a, float w){ 
//         setInfor(n, a, w); 
//         // cout << "Ham tao 3 tham so\n"; 
//         count++;
//     }
//     Cat (const Cat & r)
//     {
//         setInfor (r.name, r.age, r.weight); 
//         // cout << "Ham tao sao chep\n"; 
//         count++; 
//     }
//     void setInfor(string n, int a, float w){ 
//         name = n; 
//         age = a;
//         weight = w;
//     } 
//     string getName() const { return name; } 
//     int getAge() const { return age; } 
//     float getWeight() const { return weight; }
//     void meow() const {} 
//     int chaseMouse(int n) const; 
//     static int getCount() {return count; }

//     Cat operator+ (Cat r){
        // cách 1
        // Cat c; 
        // c.name = name; 
        // c.age = age; 
        // c.weight = weight + r.weight; 
        // return c;

        // cách 2 
        // string ten = name; 
        // int tuoi = age; 
        // int cannang = weight + r.weight; 
        // Cat c(ten, tuoi, cannang);
        // return c;

        // cách 3
        // string ten = name; 
        // int tuoi = age; 
        // int cannang = weight + r.weight; 
        // return Cat(ten, tuoi, cannang); 

        // cách 4
//         return Cat (name, age, weight + r.weight); 
//     } 
// };

// int Cat::count = 0; 

// int Cat::chaseMouse(int n) const {
//     int count = 0; 
//     for (int i = 0; i<n; i++)
//         count += chase(); 
//     return count; 
// }

// Cat inputCat(Cat c){
//     cout << Cat::getCount() << endl; 
//     return c;
// } 
// int main(){
//     Cat c1 ("Tom", 2, 3), c2("Bibi", 1, 2); 
//     cout << (c1+c2).getName() << " " << (c1+c2).getAge() << " " 
//         << (c1+c2).getWeight() << endl; 
//     return 0; 
// }

/*
    Viết toán tử cộng một con mèo và một số nguyên trả về con mèo cùng tên, cùng tuổi, có số cân tăng lên đúng 
    số nguyên đó
*/

// Viết toán tử cộng hai con mèo và trả về số cân 
// Viết toán tử trừ hai con mèo và trả về hiệu tuổi 
class Cat{
    string name; 
    int age; 
    float weight; 
    bool chase() const { return rand() % 2; }
    static int count; 
public:  
    Cat(){
        setInfor("Bibi", 1, 2); 
        // cout << "Ham tao mac dinh\n"; 
        count++;
    }
    Cat (string name){ 
        setInfor(name, 1, 2); 
        // cout << "Ham tao 1 tham so\n";
        count++;  
    }
    Cat(string n, int a){ 
        setInfor(n, a, 2); 
        // cout << "Ham tao 2 tham so\n"; 
        count++;
    }
    Cat(string n, int a, float w){ 
        setInfor(n, a, w); 
        // cout << "Ham tao 3 tham so\n"; 
        count++;
    }
    Cat (const Cat & r)
    {
        setInfor (r.name, r.age, r.weight); 
        // cout << "Ham tao sao chep\n"; 
        count++; 
    }
    void setInfor(string n, int a, float w){ 
        name = n; 
        age = a;
        weight = w;
    } 
    string getName() const { return name; } 
    int getAge() const { return age; } 
    float getWeight() const { return weight; }
    void meow() const {} 
    int chaseMouse(int n) const; 
    static int getCount() {return count; }

    // Cat operator+ (int r){
    //     return Cat (name, age, weight + r); 
    // } 
    float operator+ (Cat r){
        return weight + r.weight; 
    } 
    int operator- (Cat r){
        return age - r.age; 
    } 
    // viết toán tử = giữa 2 con mèo 
    Cat operator= (Cat r){
            *this = r; 
        name = r.name; 
        age = r.age; 
        weight = r.weight; 
        return *this; 
    }

};


int Cat::count = 0; 

int Cat::chaseMouse(int n) const {
    int count = 0; 
    for (int i = 0; i<n; i++)
        count += chase(); 
    return count; 
}

Cat inputCat(Cat c){
    cout << Cat::getCount() << endl; 
    return c;
} 
int main(){
    // Cat c1 ("Tom", 2, 3), c2 = c1+3;

    Cat c1("Tom", 2, 3), c2; 
    cout << c2.getName() << " " << c2.getAge() << " " << c2.getWeight() << endl; 
    c2 = c1; 
    Cat c3, c4; 
    c4 = c3 = c2; 
    cout << c2.getName() << " " << c2.getAge() << " " << c2.getWeight() << endl; 
    cout << c4.getName() << " " << c4.getAge() << " " << c4.getWeight() << endl; 
    cout << c3.getName() << " " << c3.getAge() << " " << c3.getWeight() << endl; 
    return 0; 
}

