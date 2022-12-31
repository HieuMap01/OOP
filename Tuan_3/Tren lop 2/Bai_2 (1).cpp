/*
3.Falculty & Department
Viết lớp Facultyvà lớp Department lần lượtmô phỏng mộtkhoavà một bộ môn trong trường. 
Lớp Department cần có:
    •Thông tin tên bộ môn, số giáo viên của bộ môn, 
    •Hàm tạo mặc định sinh ra bộ môn có tên và số giáo viên đều null
    •Hàm tạo đủ tham số để khởi tạo các biến thành viên
    •Setter tổng và các hàm getter 
    •Hàm print in ra toàn bộ thông tin bộ môn 
    •Hàm huỷ in ra thông tin đang huỷ bộ môn nào
*/
#include<iostream>
using namespace std;

class Department{
    string name_bm;
    int So_GV;
    public:
        Department(){setInfor("",0);}
        Department(string n, int s){
            name_bm = n;
            So_GV = s;
        }
        void setInfor(string n, int s){
            name_bm = n;
            So_GV = s;
        }
        string getname_bm() const {
            return name_bm;
        }
        int getSo_GV() const{
            return So_GV;
        }
        void print() {
            cout << "Bo mon: " << name_bm << endl;
            cout << "So GV: " << So_GV << endl;
        }
        ~Department(){
            cout << "Bo mon "<< name_bm << "da huy.";
        }

};
/*Lớp Faculty cần có:
    •Tên khoa, 3 bộ môn
    •Hàm tạo mặc định sinh ra khoa có tên khoa, tên 3 bộ môn và số giảng viên 3 bộ môn 
    đều null 
    •Hàm tạo nhập đủ tên khoa, tên các bộ môn và số lượng giảng viên các bộ môn 
    để tạo ra khoa với tên và 3 bộ môn như vậy.
    •Hàm tính tổng số giáo viên của khoa
    •Hàm in ra tên khoa, thông tin mỗi bộ môn, và tổng số giáo viên trong khoa
    •Hàm huỷ in ra đang huỷ khoa nào
    a.Quan hệ giữa Faculty và Department là kiểu gì: 
        liên kết, kết tập, hay hợp thành? 
    b.Nên cài 3 bộ môn trong khoa như mảng biến thường, mảng con trỏ, 
    hay mảng tham chiếu? 
    c.Hãy cài đặt 2 lớp trên và tạo chương trình demo sinh ra một khoa với 
    3 bộ môn rồi in ra thông tin khoa đó.*/
class Faculty{
    string name;
    Department bo_mon[3];
    public:
        Faculty(){ 
            name = "";
        }
        Faculty(string n, string BM[], int num[]){
            name = n;
            for(int i=0; i<3; i++){
                bo_mon[i].setInfor(BM[i],num[i]);
            }
        }
        int getTong_GV(){
            int sum = 0;
            for(int i= 0; i<3;i++){
                sum+=bo_mon[i].getSo_GV();
            }
            return sum;
        }
        void print(){
            cout << "Ten Khoa: " << name << endl;
            for(int i = 0; i<3; i++){
                bo_mon[i].print();
            }
        }
        ~Faculty(){
            cout << "Khoa " << name << " da huy\n";
        }

};

int main(){
    string name[3] = {"ta","ti","te"};
    int num[3] = {3,4,5};
    Faculty f("CNTT",name,num);
    f.print();
    return 0;
}