// Viết helper chase() mô phỏng bắt 1 con chuột, quy tắc như cũ, hàm trả về true nếu bắt được, false nếu không

// Dùng chase() để viết lại chaseMouse
#include<iostream>
#include<time.h>
#include<stdlib.h>
using namespace std;

class cat{
    string name;
    int age ;
    float weight;
    bool chase() const{
        return rand() % 2;
    }
    public:
    void setInfor(string n, int a, float w) {
        name = n;
        age = a;
        weight = w;
    }
    string getname() const {
        return name;
        }
    int getage() const{
        return age;
    }
    float getweight() const{
        return weight;
    }
    void meow();
    int chaseMouse(int) const; 
};
 
void cat::meow(){
    cout << "Meow, I am " << name << endl;
}
int cat::chaseMouse(int n) const{
    int tmp, cout = 0;
    for(int i=0; i<n; i++){
        cout += chase();
    }
    return cout;
}
int main(){
    srand(time(0));
    cat r;
    cout <<"Ten meo: " << r.getname() << endl 
         << "Tuoi: " << r.getage() << endl 
         << "Can nang: " << r.getweight()<< endl;
    r.setInfor("Tom",2,3);
    cout << "Ten Moi: \n";
    cout <<"Ten meo: " << r.getname() << endl 
         << "Tuoi: " << r.getage() << endl 
         << "Can nang: " << r.getweight()<< endl;
    r.meow();
    int n;
    cout << "Nhap so chuot can bat: " ; cin >> n;
    cout << r.chaseMouse(n);
    return 0;
}