#include <iostream>
#include <fstream>
using namespace std;
struct TaiKhoan{
    char HoTen[30];		    //Họ và Tên khách hàng
	char DiaChi[30];		//Địa chỉ
	char DienThoai[10];		//Số điện thoại
	float SoDu;	            //Số dư tài khoản
};
int main(){
    int N;
    cout << "Nhap so luong tai khoan khach hang: "; cin >> N;
    TaiKhoan a[N];  
    for (int i = 0; i < N; i++){
        cout << i + 1 << ": \n"; 
        cin.ignore(); 
        cin.getline(a[i].HoTen, 30); 
        cin.getline(a[i].DiaChi, 30);
        cin.getline(a[i].DienThoai, 10);
        cin >> a[i].SoDu;
    }
    cout << "truoc thay doi\n";
    for(int i = 0; i< N; i++){
        cout << a[i].DiaChi << " " << a[i].DienThoai << " " << a[i].HoTen << " " << a[i].SoDu << endl;
    }

    int i;
    cout << "Nhap vao vi tri can thay doi: ";
    cin >> i;
    cout << "Nhap thong tin can thay doi: \n";
	cin.ignore();
    cin.getline(a[i].HoTen, 30); 
    cin.getline(a[i].DiaChi, 30); 
    cin.getline(a[i].DienThoai, 10);
    cin >> a[i].SoDu;
	cout << "Sau thay doi\n";
    for(int i = 0; i< N; i++){
        cout << a[i].DiaChi << " " << a[i].DienThoai << " " << a[i].HoTen << " " << a[i].SoDu << endl;
    }

    ofstream out ("TaiKhoan.dat", ios::binary); 
    if (out){
        out.write(reinterpret_cast<char*> (a), N * sizeof(TaiKhoan)); 
        out.close(); 
    }
    return 0;
}