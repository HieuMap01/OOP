// nSửa lại định nghĩa lớp sao cho giả sử khi sinh ra mọi con mèo đều mặc định tên “Bibi”,
//  1 tuổi và nặng 2 kg
// nViết hàm main tạo một con mèo, in ra thông tin, sau đó thay đổi tên, tuổi, cân nặng, in ra thông tin mới,
//  cho con mèo kêu, và bảo nó bắt một số chuột nhập từ bàn phím, in ra số chuột mèo bắt được


#include<iostream>
#include<time.h>
#include<stdlib.h>
using namespace std;

class cat{
    string name = "Bili";
    int age = 1;
    float weight = 2;

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
    srand(time(0));
    int tmp, cout = 0;
    for(int i=0; i<n; i++){
        tmp = rand()%2;
        if(tmp == 1) cout++;
    }
    return cout;
}
int main(){
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
    cout << "so chuot meo bat duoc: " << r.chaseMouse(n);
    return 0;
}