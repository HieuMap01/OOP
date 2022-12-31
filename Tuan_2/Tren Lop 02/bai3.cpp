
#include<iostream>
using namespace std;

class Cat{
    string name;
    int age;
    float weight;
    bool chase() const { return rand() % 2; }
    public:
        Cat(){setInfor("Bibi", 1, 2); /*cout << "Ham tao mac dinh\n";*/ }
        Cat (string name){ setInfor(name, 1, 2); cout << "Ham tao 1 tham so\n"; }
        Cat(string n, int a){ setInfor(n, a, 2); cout << "Ham tao 2 tham so\n"; }
        Cat(string n, int a, float w){ setInfor(n, a, w); cout << "Ham tao 3 tham so\n"; }
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
        // viết operator += một con mèo với số nguyên làm cho mèo đó béo lên chừng đó cân
        Cat &operator+= (float &n){
            weight += n;
            return *this;
        }
        //viết toán tử == so sánh cân nặng 2 con mèo
        // bool operator== (float & n){
        //     return weight == n;
        // }
        bool operator== (Cat n){
            return this -> weight == n.weight;
        }

        // 2-12a: Lớp Cat: nạp chồng toán tử ++ tiền tố và hậu tố tăng cân mèo lên gấp đôi
        // Tien to
        Cat operator++ (){
            weight*=2;
            return *this;
        }
        // Hau to
        Cat operator++ (int){
            Cat tmp = *this;
            weight*=2;
            return tmp;
        }
        
    };


int Cat::chaseMouse(int n) const {
    int count = 0;
    for (int i = 0; i<n; i++)
    count += chase();
    return count;
}

int main(){
    Cat c("tom",3,5), c1("tim",3,5);
    float a = 10;
    c += a;
    cout << c.getName() << " " << c.getAge() << " " << c.getWeight() << endl;
    c == c1;
    return 0;
}