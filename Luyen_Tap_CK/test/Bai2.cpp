/*
Cho lớp trừu tượng HoaDon (hoá đơn) , gồm các thành viên:  
•	Biến private: tên hoá đơn (xâu), bên A (bên bán - xâu), bên B (bên mua - xâu), số tiền thanh toán (số thực)
•	Hàm khoiTao sẽ cập nhật các biến tên hoá đơn, bên A, bên B
•	Hàm ảo thuần tuý tinhTien trả về số tiền thanh toán, hàm này được ghi đè ở lớp con
•	Hàm capNhatTien cập nhật biến số tiền thanh toán bằng hàm tinhTien
•	Hàm hienThi in ra tên hoá đơn, bên A, bên B, số tiền thanh toán
Lớp HoaDonNuoc (hoá đơn nước) kế thừa HoaDon, có tên hoá đơn mặc định là “Hoa don Nuoc”, gồm các thành viên: 
•	Biến private: tháng tính hoá đơn (số nguyên), số nước (số thực), đơn giá (số thực)
•	Ghi đè hàm tinhTien lớp cha, trả về số tiền thanh toán = số nước * đơn giá 
•	Ghi đè hàm hienThi lớp cha để in ra lần lượt tháng tính hoá đơn, tên hoá đơn, bên A, bên B, số tiền thanh toán, số nước, đơn giá 
Lớp HoaDonNetflix kế thừa HoaDon, có tên hoá đơn mặc định là “Hoa don Netflix”, gồm các thành viên:  
•	Biến private: số tháng (số nguyên), đơn giá (số thực)
•	Ghi đè hàm tinhTien lớp cha, trả về số tiền thanh toán = số tháng* đơn giá
•	Ghi đè hàm hienThi lớp cha để in ra lần lượt tên hoá đơn, bên A, bên B, số tiền thanh toán, số tháng, đơn giá 
Viết hàm main tạo một mảng có tính đa hình gồm 5 phần tử HoaDon, sao cho gồm cả HoaDonNuoc và HoaDonNetflix, 
sau đó gọi hàm hienThi trên cả mảng. 
*/
#include<iostream>
using namespace std;

class Hoadon{
    string ten, A, B;
    float tien;
    virtual float tinhtien() const = 0;
    protected:
        void Khoitao(string t, string a, string b){
            ten = t; 
            A = a;
            B = b;
        }
        void CapnhatTien() {
            tien = tinhtien();
        }
    public:
        virtual void Hienthi() const{
            cout << ten << " "<< A << " "<< B << " "<< tien << endl;
        }
        virtual ~Hoadon(){}
};

class HoadonNuoc: public Hoadon{
    int thang;
    float nuoc, dongia;
    float tinhtien() const{
        return nuoc * dongia;
    }
    public: 
        HoadonNuoc(string a, string b, int t, float n, float d){
            Khoitao("Hoa Don Nuoc", a, b);
            thang = t;
            nuoc = n;
            dongia = d;
            CapnhatTien();
        }
        void Hienthi() const{
            cout << thang << endl ;
            Hoadon :: Hienthi();
            cout << nuoc << " " << dongia << endl;
        }
};
class HoadonNetflix: public Hoadon{
    int thang;
    float dongia;
    float tinhtien() const{
        return thang * dongia;
    }
    public: 
        HoadonNetflix(string a, string b, int t, float n, float d){
            Khoitao("Hoa Don NetFlix", a, b);
            thang = t;
            dongia = d;
            CapnhatTien();
        }
        void Hienthi() const{
            Hoadon :: Hienthi();
            cout << thang << " " << dongia << endl;
        }
};

//Viết hàm main tạo một mảng có tính đa hình gồm 5 phần tử HoaDon, sao cho gồm cả HoaDonNuoc và HoaDonNetflix, 
// sau đó gọi hàm hienThi trên cả mảng.

int main(){
    int n = 5;
    Hoadon *a[] = {new HoadonNuoc("a", "b", 12, 20,25), new HoadonNuoc("c", "s", 4, 10,25), 
                   new HoadonNuoc("s", "j", 12, 2,25), new HoadonNetflix("a", "b", 12,25), 
                   new HoadonNetflix("a", "b", 12,25)};
    for(int i = 0; i<n; i++){
        a[i]->HienThi();
    }
}