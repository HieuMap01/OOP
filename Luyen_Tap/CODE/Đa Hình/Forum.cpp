/*
Sinh viên có thể tự thêm các hàm, tự chọn danh sách tham số, tự đặt chế độ private protected public hợp lý để đảm bảo tính hướng đối tượng (chỉ trừ các thành viên đã nêu rõ private hay protected thì cần giữ nguyên)i

Viết hàm main tạo một mảng 10 Forum, có cả ForumTinhTe hay ForumVnZoom rồi in ra thông tin cả mảng. 

*/
/*

*/
#include<iostream>
using namespace std;
/*
Cho lớp trừu tượng Forum, mô tả một thành viên diễn đàn, lớp gồm các biến và hàm sau: 
•	Thuộc tính private: tên, hạng thành viên (hạng thường, hạng vàng, …), 
•	Hàm ảo thuần tuý rank trả về giá trị hạng thành viên, sẽ được cài ở lớp con
•	Hàm setInfor thiết lập giá trị cho mọi thuộc tính
•	Hàm print ảo in ra tên, hạng thành viên
*/

class Forum{
    string name, hang;
    virtual string rank() const = 0;
    protected:
        void setInfor(string n){
            name = n;
            hang = rank();
        }
    public:
        virtual void print() const{
            cout << "Ten: " << name << endl 
                 << "Hang: " << hang << endl;
        }
};
/*
Lớp ForumTinhTe kế thừa Forum, có: 
•	Thuộc tính private: năm gia nhập, năm hiện tại
•	override hàm rank trả về hạng thành viên theo công thức số năm tham gia > 3 năm thì là hạng vàng, ngược lại là hạng thường.
•	Hàm setInfor thiết lập giá trị cho mọi thuộc tính
•	Override hàm print in ra tên, hạng thành viên, năm gia nhập, năm hiện tạ
*/
class ForumTinhTe : public Forum{
    int year_GN, year_HT;
    string rank() const override{
        if(year_HT - year_GN > 3){
            return "Vang";
        }
        else {
            return "Thuong";
        }
    }
    public:
        void setInfor(string n, int GN, int HT){
            year_GN = GN;
            year_HT = HT;
            Forum::setInfor(n);
        }
        ForumTinhTe(string n = "", int GN=0, int HT=0){
            setInfor(n,GN,HT);
        }
        void print() const override{
            Forum::print();
            cout << "Nam gia nhap: " << year_GN<< endl;
            cout << "Nam hien tai: " << year_HT<< endl;
        }
}; 
/*
Lớp ForumVnZoom kế thừa Forum, có: 
•	Thuộc tính private: số bài đăng
•	override hàm rank trả về hạng thành viên theo công thức < 200 bài là hạng gà con, từ 200 đến <400 bài là dạng gà chọi, còn lại là hạng rìu sắt. 
•	Hàm setInfor thiết lập giá trị cho mọi thuộc tính
•	Override hàm print in ra tên, hạng thành viên, số bài đăng.
*/
class ForumVnZoom: public Forum{
private:
    int sobaidang;
    string rank() const override{
        if(sobaidang < 200) return "Hang ga con";
        else if(sobaidang < 400) return "Hang ga choi";
        else return "Hang riu sat";
    }
public:
    void setInfor(string n, int b){
        sobaidang = b;
        Forum::setInfor(n);
    }
    ForumVnZoom(string n = "", int b = 0) {setInfor(n, b);}
    void print() const override{
       Forum::print();
       cout << "So bai dang: " << sobaidang << endl;
    }
};

int main(){
    Forum *F[] = {new ForumTinhTe("Hieu",2020,2025), new ForumTinhTe("Ha", 2020,2021)};
    for(int i = 0; i < 2; i++){
        F[i]->print();
    }
    Forum *f1 = new ForumVnZoom("John", 500);
    f1 -> print();
    return 0;
}