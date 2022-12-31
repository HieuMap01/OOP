/*
Viết lớp Employee có các thuộc tính: 
    tên, mã số, ngày thuê, tiền lương hàng tháng. 
    Viết một/nhiều hàm tạo, setter, getter phù hợp.
Viết lớp ProductionWorker kế thừa Employee có thêm các thuộc tính: 
    ca làm việc, mức lương theo giờ, số giờ làm việc trong tháng. 
    Ca làm việc có giá trị bằng 1 nếu hiểu là ca ngày, bằng 2 nếu là ca đêm. 
    Nếu ca đêm thì lương thực lĩnh sẽ bằng lương theo giờ tăng thêm 50%. 
    Viết một/ nhiều hàm tạo, setter, getter phù hợp.
Cả 2 lớp tự chọn biến private, protected phù hợp
*/

#include<iostream>
using namespace std;

class Employee{
        string name, maso, ngay_thue;
        int tien_luong;
    public:
        Employee(string n ="", string m="", string ng="", int t=0): name(n), maso(m), ngay_thue(ng), tien_luong(t){}
        void setName(string n){
            name = n;
        }
        void setMaso(string m){
            maso = m;
        }
        void setNgay_thue(string ng){
            ngay_thue = ng;
        }
        void setTien_luong(int t){
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
                 << "Tien luong: " << tien_luong << endl;
        }
        
};
/*
Viết lớp ProductionWorker kế thừa Employee có thêm các thuộc tính: 
    ca làm việc, mức lương theo giờ, số giờ làm việc trong tháng. 
    Ca làm việc có giá trị bằng 1 nếu hiểu là ca ngày, bằng 2 nếu là ca đêm. 
    Nếu ca đêm thì lương thực lĩnh sẽ bằng lương theo giờ tăng thêm 50%. 
    Viết một/ nhiều hàm tạo, setter, getter phù hợp.
*/
class ProductionWorker: public Employee{
        int ca, h_thang;
        double luong_h;
        void setTien_luong(){
            int AM = 1, PM = 2;
            double rate = 1;
            if(ca == PM)
        }
    public:
        ProductionWorker(){}
        void setLuong_h(double l){
            luong_h = l;
        }
        void setHthang(int h){
            h_thang = h;
        }
};
