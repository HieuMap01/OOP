/*
Sinh viên có thể tự thêm các hàm, tự chọn danh sách tham số, tự đặt chế độ private protected public hợp lý để đảm bảo tính hướng đối tượng (chỉ trừ các thành viên đã nêu rõ private hay protected thì cần giữ nguyên)
Cho lớp trừu tượng NhanVien, gồm các thành viên:  
•	Thuộc tính private: mã nhân viên, lương
•	Hàm ảo thuần tuý tinhLuong nhằm tính ra lương, sẽ được cài ở lớp con
•	Hàm setInfor thiết lập giá trị cho mọi thuộc tính
•	Hàm ảo print in ra mã nhân viên, lương
Lớp NhanVienSanXuat kế thừa NhanVien, có: 
•	Thuộc tính private: số sản phẩm, tiền công một sản phẩm 
•	override tinhLuong trả về tiền lương = số sản phẩm * tiền công một sản phẩm
•	Hàm setInfor thiết lập giá trị cho mọi thuộc tính
•	override hàm print in ra mã nhân viên, lương, số sản phẩm, tiền công một sản phẩm 
Lớp NhanVienVanPhong kế thừa NhanVien, có: 
•	Thuộc tính private: số ngày công, lương cơ bản 
•	override tinhLuong trả về trả về tiền lương bằng số ngày công * lương cơ bản / 30. 
•	Hàm setInfor thiết lập giá trị cho mọi thuộc tính
•	override hàm print in ra mã nhân viên, lương, số ngày công, lương cơ bản
Viết hàm main tạo một mảng 10 phần tử NhanVien, có cả NhanVienSanXuat và NhanVienVanPhong, sau cùng in ra thông tin cả mảng. 


*/

#include<iostream>
#include<math.h>
using namespace std;

class NhanVien{
    string mnv;
    float luong ;
    virtual float TinhLuong() const = 0;
    protected: 
        void setAll(string id){
            mnv =id ;
            luong=TinhLuong();
        }
    public: 
        virtual void print() const{
            cout<<"Id : "<< mnv <<endl<<"Luong : "<< luong <<endl;
        }
        virtual ~ NhanVien () {} 
}; 

class  NhanVienSanXuat: public NhanVien{
    float sosp,tiencong; 
    float TinhLuong() const {return sosp*tiencong ; } 
    public: 
        NhanVienSanXuat (float s , float t ,string id ){ setAll(s,t,id); }
        void setAll(float s, float t,string id){
            sosp = s; 
            tiencong = t; 
            NhanVien:: setAll(id);
        }
        void print() const{
            NhanVien::print();
            cout<<"So sp :"<<sosp<<endl<<"Tien cong moi sp : "<<tiencong<<endl;
        }
};

class NhanVienVanPhong: public NhanVien{
    float ngaycong,luongcb;
    float TinhLuong() const {return (ngaycong* luongcb)/30.0 ; } 
    public:
        NhanVienVanPhong( float n,float l,string id){
            setAll( n,l,id);
        }
        void setAll( float n,float l,string id){
            ngaycong =n;
            luongcb =l;
            NhanVien:: setAll(id);
        }
        void print() const{
            NhanVien::print();
            cout<<"So ngay cong : "<<ngaycong<<endl<<"Luong co ban : "<<luongcb<<endl;
        }
};

int main(){
    int n=4 ;
    NhanVien * p[n] = { new NhanVienSanXuat (3,4,"0123"),new NhanVienSanXuat( 5,7,"4355"),
                        new NhanVienSanXuat (28,23,"3245"),new NhanVienVanPhong( 30,12,"2342"),
    };
    for(int i=0;i<n;i++){
        p[i]->print();
    }
    return 0; 
    }
