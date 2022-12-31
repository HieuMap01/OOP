/*
. Dữ liệu sách 
Cho cấu trúc có tên BookData để lưu trữ thông tin sau về sách như sau:
struct BookData
{
	char TenSach[30]; 		//Tên sách
	char TacGia[30]; 		//Tác giả
	int NamXuatBan;		//Năm xuất bản
	int SoTrang;			//Số trang
	char NhaXuatBan;		//Nhà xuất bản
};
Yêu cầu:
Viết chương trình thực hiện: 
-	Nhập vào 1 mảng kiểu BookData với số lượng n được nhập từ bàn phím 
-	Cho phép người dùng nhập vào 1 năm xuất bản bất kỳ. Sau đó hiển thị thông 
tin những quyển sách xuất bản năm đó. 
-	Ghi thông tin tất cả quyển sách vào tệp nhị phân có tên BookData.dat

*/

#include <iostream>
#include <fstream>
using namespace std;
struct BookData {
    char TenSach[30]; 		//Tên sách
	char TacGia[30]; 		//Tác giả
	int NamXuatBan;		//Năm xuất bản
	int SoTrang;			//Số trang
	char NhaXuatBan[30];		//Nhà xuất bản
};
int main() {
    int n; 
    cout << "Nhap n: "; cin >> n;
    BookData a[n];
    for (int i = 0; i < n; i++) {
        cout << i << endl;
        cin.ignore();
        cout << "Nhap ten sach: "; cin.getline(a[i].TenSach, 30);
        cout << "Nhap ten tac gia: ";cin.ignore(); cin.getline(a[i].TacGia, 30);
        cout << "Nhap nha xuat ban: "; cin.getline(a[i].NhaXuatBan, 30);
        cout << "Nhap nam xuat ban: "; cin >> a[i].NamXuatBan;
        cout << "Nhap so trang: "; cin >> a[i].SoTrang;
        cout << endl;
    }
    int nam; 
    cout << "Nhap nam xuat ban bat ky: "; cin >> nam;
    for (int i = 0; i < n; i++) {
        if(nam == a[i].NamXuatBan) {
        cout << "Ten sach: " << a[i].TenSach << endl
            << "Tac gia: " << a[i].TacGia << endl
            << "Nam xuat ban: " << a[i].NamXuatBan << endl
            << "So trang: " << a[1].SoTrang << endl
            << "Nha xuat ban: " << a[i].NhaXuatBan << endl;
        cout << endl;
        }
    }
    return 0;
}