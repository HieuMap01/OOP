/*
2.	Employee & ShiftSupervisor  
•Viết lớp ShiftSupervisor (đốc công) cũng kế thừa lớp Employee, lớp này có thêm các biến: 
    số tháng làm việc thực tế trong năm, lương cả năm (tính bằng số tháng làm trong năm nhân lương tháng), 
    tiền thưởng cả năm nếu làm đủ 12 tháng. Viết một hay nhiều 
    hàm tạo, các setter getter phù hợp, và hàm getBonus trả về tiền thưởng thực lĩnh; 
    biết rằng tiền thưởng thực lĩnh bằng tiền thưởng cả năm này/12 * số tháng làm việc thực tế. 
•Viết main tạo ra đối tượng Emloyee, và ShiftSupervisor. 
    Sau đó in ra thông tin các đối tượng này + tiền lương tháng của Employee, 
    tiền lương và tiền thưởng thực lĩnh theo năm của ShiftSupervisor.  
*/

#include<iostream>
using namespace std;


class Employee{
        string name, maso, ngay_thue;
        int tien_luong;
    public:
        Employee(string n ="", string m="", string ng="", int t=0){setInfor(n,m,ng,t);}
        void setInfor(string n , string m, string ng, int t){
            name = n;
            maso = m;
            ngay_thue = ng;
            tien_luong = t;
        }
        string getName() const {return name;}
        string getMaso() const {return maso;}
        string getNgay_thue() const {return ngay_thue;}
        int getTien_luong() const {return tien_luong;}
        void print() const{
            cout << "Ten: " << name << endl
                 << "Ma so: " << maso << endl
                 << "Ngay thue: " << ngay_thue << endl
                 << "Tien luong thang: " << tien_luong << endl;
        }
        
};
/*
•Viết lớp ShiftSupervisor (đốc công) cũng kế thừa lớp Employee, lớp này có thêm các biến: 
    số tháng làm việc thực tế trong năm, lương cả năm (tính bằng số tháng làm trong năm nhân lương tháng), 
    tiền thưởng cả năm nếu làm đủ 12 tháng. Viết một hay nhiều 
    hàm tạo, các setter getter phù hợp, và hàm getBonus trả về tiền thưởng thực lĩnh; 
    biết rằng tiền thưởng thực lĩnh bằng tiền thưởng cả năm này/12 * số tháng làm việc thực tế. 
*/
class ShiftSupervisor: public Employee{
    int thang;
    int luong_cn;
    int tien_thuong;
    int tt_tl;
    
    public:
        ShiftSupervisor(){}
        ShiftSupervisor(string n, string m, string ng, int t, int th, int tt){
            setInfor(n,m,ng,t,th,tt);
        }
        void setInfor(string n , string m, string ng,int t, int th, int tt){
            thang = th;
            luong_cn = t*th;
            tt_tl = tt;
            thang == 12 ? tien_thuong = tt : tien_thuong = 0;
            Employee :: setInfor(n,m,ng,t);
        }
        int getThang()const{return thang;}
        int getLuong_CN()const{return luong_cn;}
        int getTienThuong()const{return tien_thuong;}

        int getBonus()const{ 
            return (tt_tl/12)*thang;
        }
        void print() const{
            Employee :: print();
            cout << "So thang lam viec: " << thang << endl
                 << "Tien luong CN: " << luong_cn << endl
                 << "Tien thuong: " << tien_thuong << endl
                 << "Tien luong thuc linh: " << getBonus() << endl << endl;
        }
};
int main(){
    ShiftSupervisor S("Bui Minh Hieu", "A42839", "07/06/2022", 7000000, 11, 1200000);
    S.print();
    ShiftSupervisor Sh("Bui Minh Hieu", "A42839", "07/06/2022", 7000000, 12, 1200000);
    Sh.print();
    return 0;
}