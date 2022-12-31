/*
Cho lớp trừu tượng NhanVien, gồm các thành viên:  
•Thuộc tính private: mã nhân viên, lương
•Hàm ảo thuần tuý tinh Luong nhằm tính ra lương, sẽ được cài ở lớp con
•Hàm setAll thiết lập giá trị cho mọi thuộc tínhcần thiết
•Hàm ảo print in ra mã nhân viên, lương
Lớp NhanVienSanXuat kế thừa NhanVien, có: 
•Thuộc tính private: số sản phẩm, tiền công một sản phẩm 
•override tinhLuongtrả về tiền lương = số sản phẩm * tiền công một sản phẩm
•Hàm setAllthiết lập giá trị cho mọi thuộc tínhcần thiết
•override hàm printin ra mã nhân viên, lương, số sản phẩm, tiền công một sản phẩm 
Lớp NhanVienVanPhongkế thừa NhanVien, có: 
•Thuộc tính private: số ngày công, lương cơ bản •override tinh Luongtrả về trả về tiền lương bằng số ngày công* lương cơ bản / 30. 
•Hàm setAllthiết lập giá trị cho mọi thuộc tínhcần thiết
•overridehàm print in ra mã nhân viên, lương, số ngày công, lương cơ bản
Viết  hàm  main  tạo  một  mảng 10  phần  tử NhanVien,  có  cả NhanVienSanXuat và NhanVienVanPhong, sau cùng in ra thông tin cả mảng. 
*/
#include<iostream>
#include<math.h>
using namespace std;

class NhanVien{
    string id;
    float luong ;
    virtual float Payroll() const = 0;
    protected: 
        void setLuong (){luong = Payroll(); }
        void setAll(string id =" ",float luong =0){
            this-> id =id ;
            this -> luong=luong;
        }
    public: 
        float getLuong() const {return luong ;}
        virtual void print() const{
            cout<<"Id : "<<id<<endl<<"Luong : "<<luong<<endl;
        }
        virtual ~ NhanVien () {} 
}; 

class  NhanVienSanXuat: public NhanVien{
    float sosp,tiencong; 
    float Payroll() const {return sosp*tiencong ; } 
    public: 
        NhanVienSanXuat (float s , float t ,string id ){ setAll(s,t,id); }
        void setAll(float s, float t,string id){
            sosp = s; 
            tiencong = t; 
            NhanVien:: setAll(id);
            setLuong(); 
        }
        void print() const{
            NhanVien::print();
            cout<<"So sp :"<<sosp<<endl<<"Tien cong moi sp : "<<tiencong<<endl;
        }
};

class NhanVienVanPhong: public NhanVien{
    float ngaycong,luongcb;
    float Payroll() const {return (ngaycong* luongcb)/30.0 ; } 
    public:
        NhanVienVanPhong( float n,float l,string id){
            setAll( n,l,id);
        }
        void setAll( float n,float l,string id){
            this -> ngaycong =n;
            this -> luongcb =l;
            NhanVien:: setAll(id);
            setLuong();
        }
        void print() const{
            NhanVien::print();
            cout<<"So ngay cong : "<<ngaycong<<endl<<"Luong co ban : "<<luongcb<<endl;
        }
};

int main(){
    int n=10 ;
    NhanVien * p[n] = { new NhanVienSanXuat (3,4,"P00"),new NhanVienSanXuat( 5,7,"P111"),
                        new NhanVienSanXuat (7,8,"P22"),new NhanVienSanXuat( 6,7,"P333"),
                        new NhanVienSanXuat (3,4,"P444"),new NhanVienVanPhong( 3,4,"P00"),
                        new NhanVienVanPhong (5,7,"P11"),new NhanVienVanPhong( 7,8,"P22"),
                        new NhanVienVanPhong (6,7,"P33"),new NhanVienVanPhong( 3,4,"P44")
    };
    for(int i=0;i<n;i++){
        p[i]->print();
    }
    return 0; 
    }
