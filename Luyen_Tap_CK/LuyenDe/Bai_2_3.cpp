/*
Cho lớp trừu tượng MangBienDoi (mảng biến đổi) , gồm các thành viên:  
•	Biến private: biến ten chỉ tên mảng, mảng số nguyên a chứa nhiều nhất 100 phần tử, biến size chỉ số phần tử mảng
•	Hàm ganTen sẽ cập nhật biến ten
•	Hàm ảo thuần tuý bienDoi nhận một số nguyên, trả về giá trị được biến đổi từ số đó, hàm sẽ được cài ở lớp con.
•	Hàm ganMang nhận một mảng số nguyên b  kích thước n, và gán n phần tử đầu mảng b này cho mảng a như sau: 
void ganMang(int b[], int n){ // gán mảng
     size = n;
     if (size > 100)
         size = 100; 
     for (int i = 0; i < size; i++)
         a[i] = b[i];
}	
•	Hàm lamBienDoi sẽ gọi hàm bienDoi trên từng phần tử mảng a để biến đổi cả mảng 
•	Hàm hienThi in ra tên mảng, số phần tử, và toàn bộ mảng
Lớp MangTinhTien (mảng tịnh tiến) ứng với các mảng được biến đổi nhờ tăng mọi phần tử thêm một số cho trước. 
Lớp này kế thừa lớp MangBienDoi, có tên mảng mặc định là “Mang tinh tien” và gồm các thành viên sau:  
•	Một biến số nguyên x, để private, được xác định ngay khi tạo đối tượng
•	Ghi đè hàm bienDoi lớp cha để nhận vào một số, trả về số đó cộng x. 
•	Ghi đè hàm hienThi lớp cha để lần lượt in ra tên mảng, số phần tử, toàn bộ mảng và biến x
(0.5 điểm) Lớp MangNhiPhan (mảng nhị phân) ứng với các mảng được biến đổi nhờ thay mọi giá trị chẵn thành 0 và mọi giá trị lẻ thành 1. 
Lớp này kế thừa MangBienDoi, có tên mảng mặc định là “Mang nhi phan” và gồm các thành viên sau:  
•	Ghi đè hàm bienDoi lớp cha để nhận vào một số nguyên, trả về 0 nếu số đó chẵn, 1 nếu số đó lẻ
Viết hàm main tạo mảng arr có tính đa hình gồm 5 phần tử MangBienDoi, sao cho gồm cả MangTinhTien và MangNhiPhan. 
Sau đó tạo một mảng gồm 20 số nguyên, rồi với từng phần tử của mảng arr, dùng hàm ganMang gán mảng 20 số vào bên trong phần tử, 
sau đó biến đổi các mảng nhờ hàm lamBienDoi. Cuối cùng, in ra thông tin cả mảng arr dùng hàm hienThi
*/

#include<iostream>
using namespace std;

class MangBienDoi{
    string ten;
    int a[100], size;
    virtual int bienDoi(int a) const = 0;
    protected:
        void ganten(string t){
            ten = t;
        }
    public:
        void ganMang(int b[], int n){ // gán mảng
            size = n;
            if (size > 100)
                size = 100; 
            for (int i = 0; i < size; i++)
                a[i] = b[i];
        }
        void lamBienDoi(){
            for(int i = 0; i<size; i++)
                a[i] = bienDoi(a[i]);
        }
        virtual void hienthi() const {
            cout << ten << " " << size << endl;
            for(int i = 0; i<size; i++){
                cout << a[i] << " ";
            }
            cout << endl;
        }
        virtual ~MangBienDoi(){}
};
/*
Lớp MangTinhTien (mảng tịnh tiến) ứng với các mảng được biến đổi nhờ tăng mọi phần tử thêm một số cho trước. 
Lớp này kế thừa lớp MangBienDoi, có tên mảng mặc định là “Mang tinh tien” và gồm các thành viên sau:  
•	Một biến số nguyên x, để private, được xác định ngay khi tạo đối tượng
•	Ghi đè hàm bienDoi lớp cha để nhận vào một số, trả về số đó cộng x. 
•	Ghi đè hàm hienThi lớp cha để lần lượt in ra tên mảng, số phần tử, toàn bộ mảng và biến x
(0.5 điểm) Lớp MangNhiPhan (mảng nhị phân) ứng với các mảng được biến đổi nhờ thay mọi giá trị chẵn thành 0 và mọi giá trị lẻ thành 1. 
Lớp này kế thừa MangBienDoi, có tên mảng mặc định là “Mang nhi phan” và gồm các thành viên sau:  
•	Ghi đè hàm bienDoi lớp cha để nhận vào một số nguyên, trả về 0 nếu số đó chẵn, 1 nếu số đó lẻ
*/
class MangTinhTien:public MangBienDoi{
    int x;
    int bienDoi(int i) const{
        return i+x;
    }
    public:
        MangTinhTien(int x){
            this->x = x;
            ganten("Mang tinh tien");
        }
        void hienthi() const {
            MangBienDoi :: hienthi();
            cout << x << endl;
        }
};
class MangNhiPhan:public MangBienDoi{
    int x;
    int bienDoi(int i) const{
        if(i%2==0) return 0;
        else return 1;
    }
    public:
        MangNhiPhan(){
            ganten("Mang Nhi phan.");
        }
};
/*
Viết hàm main tạo mảng arr có tính đa hình gồm 5 phần tử MangBienDoi, sao cho gồm cả MangTinhTien và MangNhiPhan. 
Sau đó tạo một mảng gồm 20 số nguyên, rồi với từng phần tử của mảng arr, dùng hàm ganMang gán mảng 20 số vào bên trong phần tử, 
sau đó biến đổi các mảng nhờ hàm lamBienDoi. Cuối cùng, in ra thông tin cả mảng arr dùng hàm hienThi
*/
int main(){
    int n = 5;
    MangBienDoi *arr[] = {new MangTinhTien(6), new MangTinhTien(9), new MangTinhTien(3),
                          new MangNhiPhan(), new MangNhiPhan()};
    int m = 20;
    int b[] = {1,2,3,4,5,6,7,8,9,10,11,12,13,14,15,16,17,18,19,20};
    for(int i = 0; i < n; i++){
        arr[i]->ganMang(b,m);
        arr[i]->lamBienDoi();
    }
    for(int i = 0; i<n; i++){
        arr[i]->hienthi();
    }
}