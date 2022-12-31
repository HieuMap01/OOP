/*
1.	Employee & ProductionWorker  
•Viết lớp Employee có các thuộc tính:
    tên, mã số, ngày thuê, tiền lương hàng tháng. 
    Viết một hoặc nhiều hàm khởi tạo và các hàm set/get phù hợp  
•Viết lớp ProductionWorker kế thừa Employee có thêm các thuộc tính: 
    ca làm việc, mức lương theo giờ, số giờ làm việc trong tháng. 
    Ca làm việc có giá trị bằng 1 nếu hiểu là ca ngày, bằng 2 nếu là ca đêm. 
    Nếu ca đêm thì lương thực lĩnh sẽ bằng lương theo giờ tăng thêm 50%. 
Viết một hoặc nhiều hàm khởi tạo và các hàm set/get phù hợp  
•Viết main tạo ra đối tượng Emloyee, ProductionWorker. 
Sau đó in ra thông tin các đối tượng này + tiền lương tháng của Employee, ProductionWorker.  
Bonus: ca làm việc chỉ nhận giá trị 1 hay 2 có thể để là biến kiểu int, hoặc có thể tìm đọc về kiểu enum, 
nếu làm kiểu enum sẽ cộng thêm 0.5 điểm cho bài lab này.  
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
                 << "Tien luong: " << tien_luong << endl;
        }
        
};
/*
Viết lớp ProductionWorker kế thừa Employee có thêm các thuộc tính: 
    ca làm việc, mức lương theo giờ, số giờ làm việc trong tháng. 
    Ca làm việc có giá trị bằng 1 nếu hiểu là ca ngày, bằng 2 nếu là ca đêm. 
    Nếu ca đêm thì lương thực lĩnh sẽ bằng lương theo giờ tăng thêm 50%. 
    Viết một/ nhiều hàm tạo, setter, getter phù hợp.
    Bonus: ca làm việc chỉ nhận giá trị 1 hay 2 có thể để là biến kiểu int, hoặc có thể tìm đọc về kiểu enum, 
nếu làm kiểu enum sẽ cộng thêm 0.5 điểm cho bài lab này.
*/
enum calam {
    AM = 1,
    PM
};
class ProductionWorker: public Employee{
        // int ca = 1, luong_h = 0, h_thang = 0;
        // int compute() const{
        //     return (ca == 2 ? 1.5 : 1) * luong_h * h_thang;
        // }
        int ca = AM, luong_h = 0, h_thang = 0;
        int compute() const{
            return (ca == PM ? 1.5 : 1) * luong_h * h_thang;
        }
    public:
        ProductionWorker(){}
        ProductionWorker(string n , string m, string ng, int c, int lh, int ht){
            setInfor(n,m,ng,c,lh,ht);
        }
        void setInfor(string n , string m, string ng, int c, int lh, int ht){
            ca = c;
            luong_h = lh;
            h_thang = ht;
            Employee :: setInfor(n,m,ng,compute());
        }
        int getCa() const {return ca;}
        int getLuong_h() const {return luong_h;}
        int getH_thang() const {return h_thang;}
        void print(){
            Employee::print();
            cout << "Ca: " << ca << endl
                 << "Luong theo gio: " << luong_h << endl
                 << "So gio lam viec trong thang: " << h_thang << endl;
        }
};

int main(){
    Employee E("Bui Minh Hieu", "A42839", "5/6/2022", 1005);
    // ProductionWorker P("Bui Minh Hieu", "A42839", "5/6/2022", 1, 10, 200);
    // ProductionWorker C("Bui Minh Hieu", "A42839", "5/6/2022", 2, 10, 200);
    ProductionWorker P("Bui Minh Hieu", "A42839", "5/6/2022", AM, 10, 200);
    ProductionWorker C("Bui Minh Hieu", "A42839", "5/6/2022", PM, 10, 200);
    E.print();
    P.print();
    C.print();
    return 0;
    
}