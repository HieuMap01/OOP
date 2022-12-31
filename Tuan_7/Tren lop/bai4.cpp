/*
Cho cấu trúc có tên SinhVien để lưu trữ dữ liệu sau về thông tin sinh viên như sau:
struct SinhVien 
{
       char MaSinhVien[6];            //Mã sinh viên
       char HoTen[30];                    //Họ tên
       int SoTinChi;                          //Số tín chỉ tích lũy
       float DiemTB;                        //Điểm trung bình 
};
Yêu cầu: 
Viết chương trình thực hiện:
Cho phép người dùng nhập vào n thông tin sinh viên với n nhập từ bàn phím. Hiển thị thông tin 
thống kê sinh viên ví dụ như sau:
    Số tín chỉ tích lũy trung bình của tất cả sinh viên: 60 
    Số sinh viên có tín chỉ nhỏ hơn 20: 15 
Ghi tất cả thông tin sinh viên vào tệp nhị phân có tên SinhVien.dat.
*/

#include<iostream>
#include<fstream>
using namespace std;

struct SinhVien 
{
       char MaSinhVien[6];            //Mã sinh viên
       char HoTen[30];                    //Họ tên
       int SoTinChi;                          //Số tín chỉ tích lũy
       float DiemTB;                        //Điểm trung bình 
};
int main(){
    int n; 
    cout << "n: "; cin >>n; 
    SinhVien a[n]; 
    int sum = 0, count = 0;  
    for (int i = 0; i<n; i++){
        cout << i << ": "; 
        cin.ignore(); 
        cin.getline(a[i].MaSinhVien, 6); 
        cin.getline(a[i].HoTen, 30); 
        cin >> a[i].SoTinChi >> a[i].DiemTB; 
        sum += a[i].SoTinChi; 
        if (a[i].SoTinChi < 20) count++; 
    }
    cout << "So tin chi trung binh cua moi sinh vien: " << sum/n << endl; 
    cout << "So sinh vien co so tin nho hon 20: " << count << endl; 
    ofstream out ("SinhVien.dat", ios::binary); 
    if (out){
        out.write(reinterpret_cast< char* > (a), n* sizeof(SinhVien)); 
        out.close(); 
    }
}
