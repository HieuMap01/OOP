/* Một Trường có nhiều Khoa, số sinh viên của trường bằng tổng số sinh  
viên của các khoa.
Viết lớp Faculty mô tả một khoa, gồm các thành viên sau
Tên khoa
Số sinh viên của khoa
Biến lưu tổng số sinh viên của cả trường
Hàm tạo 2 tham số là tên khoa và số sinh viên, với đối số mặc định tên khoa là “Kinh te” 
và số sinh viên mặc định là 300.
Các setter getter tuỳ sinh viên chọn
Tạo ra một mảng 5 khoa và khởi tạo với tên khoa và số sinh viên tại dòng lệnh.
Sau đó in ra tổng sinh viên của trường

*/

#include<iostream>
using namespace std;

class Faculty{
    string khoa;
    int So_SV = 0;
    static int Tong_SV;
    public:
        Faculty(string khoa = "Kinh te", int So_SV = 300)
        : khoa(khoa), So_SV(So_SV)
        {
            Tong_SV += So_SV;
        }
        void setInfor(string khoa, int s){
            this-> khoa = khoa;
            Tong_SV = Tong_SV - So_SV + s;
            So_SV = s;
        }

        string getkhoa() const {return khoa;}
        int getSo_SV() const {return So_SV;}
        static int getTong_SV() {return Tong_SV;}

};

int Faculty :: Tong_SV = 0;

int main(){
    int n = 5;
    Faculty F[n] = {
        Faculty("TA",50),
        Faculty("TI",150),
        Faculty("TT",150),
        Faculty("TE",250)};
    

    return 0;
}