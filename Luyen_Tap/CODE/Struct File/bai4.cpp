/*
Corporate Sales
Cho cấu trúc có tên ChiNhanh để lưu trữ dữ liệu của một chi nhánh công ty như sau:
struct ChiNhanh
{
	char TenChiNhanh[30];		//Tên chi nhánh
	float DoanhSoQuy1;			//Doanh số quý 1
	floar DoanhSoQuy2;			//Doanh số quý 2
	float DoanhSoQuy3;			//Doanh số quý 3
	float DoanhSoQuy4;			//Doanh số quý 4
};
Yêu cầu: 
Viết chương trình thực hiện: 
-	Viết chương trình cho phép người dùng nhập vào thông tin của N chi nhánh (N nhập từ bàn phím).
-	Đọc và in ra màn hình tên chi nhánh có Doanh số cả năm lớn nhất (Doanh số cả năm bằng tổng doanh số 4 quý). 
-	Ghi thông tin tất cả các chi nhánh vào tệp nhị phân có tên ChiNhanh.dat. 

*/

#include <iostream>
#include <fstream>
using namespace std;
struct ChiNhanh
{
	char TenChiNhanh[30];		//Tên chi nhánh
	float DoanhSoQuy1;			//Doanh số quý 1
	float DoanhSoQuy2;			//Doanh số quý 2
	float DoanhSoQuy3;			//Doanh số quý 3
	float DoanhSoQuy4;			//Doanh số quý 4
};
int main() {
	int n; 
	cout << "Nhap n: "; cin >> n;
	cin.ignore();
	ChiNhanh a[n];
    int sum[n];
	for (int i = 0; i < n; i++) {
		cout << "Nhap ten chi nhanh: "; cin.getline(a[i].TenChiNhanh, 30);
		cout << "Nhap doanh so quy 1: "; cin >> a[i].DoanhSoQuy1;
		cout << "Nhap doanh so quy 2: "; cin >> a[i].DoanhSoQuy2;
		cout << "Nhap doanh so quy 3: "; cin >> a[i].DoanhSoQuy3;
		cout << "Nhap doanh so quy 4: "; cin >> a[i].DoanhSoQuy4;
		cin.ignore();
        sum[i] = a[i].DoanhSoQuy1 + a[i].DoanhSoQuy2 + a[i].DoanhSoQuy3 + a[i].DoanhSoQuy4;
		cout << endl;
	}
	int max = sum[0], k=0;
	for (int i = 0; i < n; i++) {
        if(max <= sum[i]){
            max = sum[i];
            k = i;
        }
	}
    cout << "Chi nhanh co doanh so lon nhat la: " << a[k].TenChiNhanh << "\nDoanh so la: " << max << endl;
    ofstream out ("chinhanh.dat", ios::binary); 
    if (out){
        out.write(reinterpret_cast<char*> (a), n * sizeof(ChiNhanh)); 
        out.close(); 
    }
	return 0;
}