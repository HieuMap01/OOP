/*
Cho lớp Pet, gồm các thành viên sau: 
    •Các thuộc tính private: tên, môi trường sống (nước, trên cạn, trong rừng, ...)
    •Hàm setInforthiết lập giá trị cho mọi thuộc tínhcần thiết
    •Hàm ảo print in ra tên, môi trường sống. 
Lớp Cat kế thừa Pet, có các đặc điểm: 
    •Thuộc tính private:độ dài lông (ngắn, dài, vừa)
    •Kiểm tra đảm bảo mèo không thể sống dưới nước
    •Hàm setInfor thiết lập giá trị cho mọi thuộc tínhcần thiết
    •Override hàmprintin ra tên, điều kiện sống, độ dài lông.
Lớp Fish kế thừa lớp Pet, có các đặc điểm:
    •Thuộc tính private: loại cá 
    •Kiểm tra đảm bảo cá không thể sống trong rừng
    •Hàm setInfor thiết lập giá trị cho mọi thuộc tínhcần thiết
    •Override hàmprintin ra tên, điều kiện sống, loại cá. 
Hàm main khởi tạo một mảng 10 phần tử Petcó cả Catvà Fish,duyệt từng phần tử hỏi người dùng muốn tạo ra Cathay Fishrồi khởi tạo tương ứng, 
sau cùng in ra thông tin cả mảng. 
*/
#include<iostream>
#include<string.h>
using namespace std;
class Pet{
    string  name,moitruong;
    protected: 
    void setAll(string n,string  mt){
        name =n;
        moitruong=mt;
    }
    public:
        virtual void print() const{
            cout<<"Ten: " << name << endl << "Moi truong: " << moitruong << endl;
        }
         virtual ~ Pet (){}
};

class Cat: public Pet{
    string  dodai;
    string  check(string moitruong) const{
        if(moitruong =="nuoc") throw "Meo chet \n";
        return moitruong;
    }
    public:
        Cat(string t,string mt,string dodai){
            setAll(t,mt,dodai);
        }
        void setAll(string  t,string  mt,string  dodai){
            Pet::setAll(t,check(mt));
            this->dodai=dodai;
        }
        void print() const{
            Pet::print();
            cout<<"Do dai long : "<<dodai<<endl;
        }
};

class Fish: public Pet{
    string  loai;
    string  checkFish(string  moitruong) const{
        if(moitruong =="rung") throw "Ca chet \n";
        return moitruong;
    }
    public:
        Fish(string t,string mt,string loai){
            setAll(t,mt,loai);
        }
        void setAll(string  t,string  mt,string  loai){
            Pet::setAll(t,checkFish(mt));
            this->loai=loai;
        }
        void print() const{
            Pet::print();
            cout<<"Do dai long : "<<loai<<endl;
        }
};
int main(){
    try {
        Pet * r [2]={new Cat ("Cho","can","dai"),new Fish("chim","nuoc","duc")};
        for(int i = 0;i<2;i++){
            r[i]->print();
        }
        
    } catch ( char const* e){
        cout<<e;
    }
    try {
        Pet * r [2]={new Cat ("Cho","nuoc","ngan"),new Fish("Chim","rung","duc")};
        for(int i = 0;i<2;i++){
            r[i]->print();
        }
    } catch ( char const* e){
        cout<<e;
    }
    return 0;
}