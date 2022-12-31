// nViết các hàm tạo sau cho lớp Cat:
// qKhông tham số, gán tên là tên Bibi, 1 tuổi, nặng 2kg bằng 3 cách: gọi setter tổng, 
// danh sách khởi tạo, và đối số mặc định
// qcó 3 tham số khởi tạo name, age, weight
// qcó 2 tham số khởi tạo name, age; còn weight gán bằng 2
// qcó 1 tham số khởi tạo name, còn name, weight gán bằng 1 và 2

#include<iostream>
#include<time.h>
#include<stdlib.h>
using namespace std;

class cat{
    string name;
    int age ;
    float weight;

    public:
    // goi khong gian so
    cat (){
        setInfor("Bili",1,2);
    }

    // cat (): name("Bili"), age(1), weight(2){}

    // cat (){
    //     name = "Bili";
    //     age = 1;
    //     weight = 2;
    // }
    
    // cat(string n = "Bili", int a = 1, float w = 2){
    //     setInfor("Bili",1,2);
    // }

    cat (string n){
        // this --> name = name
        setInfor(n,1,2);
    }

    cat (string n, int a){
        setInfor(n,a,2);
    }

    cat (string n, int a, float w){
        setInfor(n,a,w);
    }

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