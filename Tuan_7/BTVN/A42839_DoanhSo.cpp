/*
Doanh số chi nhánh 
Viết struct CorpSale lưu các dữ liệu sau của một chi nhánh công ty:
    •Tên chi nhánh (chẳng hạn như Đông, Tây, Bắc hoặc Nam)
    •Doanh số 4 quý 
Tạo 4 chi nhánh tên Đông, Tây, Nam, Bắc, nhập nốt dữ liệu còn lại từ bàn phím. Rồi ghi dữ liệu mọi chi nhánh vào một tệp.
Sau đó lại đọc dữ liệu trong tệp, từ đó tính toán và hiển thị các số liệu sau:
    •Tổng doanh thu của công ty cho mỗi quý
    •Tổng doanh thu hàng năm cho từng chi nhánh
    •Tổng doanh thu hàng năm của công ty
    •Doanh số trung bình hàng quý cho các chi nhánh
    •Quý cao nhất và quý thấp nhất của tập đoàn 
*/


#include <iostream>
#include <fstream>
using namespace std;

const int n = 4;

struct CorpSale
{
	string Namecn;
	float DoanhSoQuy1;			
	float DoanhSoQuy2;		
	float DoanhSoQuy3;			
	float DoanhSoQuy4;		
};

int main() {
	CorpSale a[n], b[n];
    string name[4]={"Dong", "Tay", "Nam", "Bac"};
	for (int i = 0; i < n; i++) {
        a[i].Namecn = name[i];
		cout << "Nhap doanh so cho chi nhanh phia " << a[i].Namecn << endl;
		cout << "Nhap doanh so quy 1: "; cin >> a[i].DoanhSoQuy1;
		cout << "Nhap doanh so quy 2: "; cin >> a[i].DoanhSoQuy2;
		cout << "Nhap doanh so quy 3: "; cin >> a[i].DoanhSoQuy3;
		cout << "Nhap doanh so quy 4: "; cin >> a[i].DoanhSoQuy4;
		cout << endl;
	}
    string namefile;
    cout << "Nhap vao ten file muon ghi: "; cin >> namefile; 
    ofstream out (namefile,ios::binary); 
    if (!out){
        cout << "Loi!\n";
    }
    else{
        out.write(reinterpret_cast<char*> (a), n * sizeof(CorpSale)); 
        out.close();
    }
    ifstream in(namefile,ios::binary);
    if(!in){
        cout << "loi\n";
    }
    else{
        float sum[n];
        float sumQ1 = 0, sumQ2 = 0,sumQ3 = 0,sumQ4 = 0, tongds = 0;
        in.read(reinterpret_cast <char*> (b), n * sizeof(CorpSale)); 
        in.close();
        for (int i = 0; i < n; i++) {
            sum[i] = b[i].DoanhSoQuy1 + b[i].DoanhSoQuy2 + b[i].DoanhSoQuy3 + b[i].DoanhSoQuy4;
            sumQ1 += b[i].DoanhSoQuy1;
            sumQ2 += b[i].DoanhSoQuy2;
            sumQ3 += b[i].DoanhSoQuy3;
            sumQ4 += b[i].DoanhSoQuy4;
	    }
        float quy[4] = {sumQ1,sumQ2,sumQ3,sumQ4};
        for (int i = 0; i < n; i++) {
            cout << "Tong doanh thu cho quy"<< i+1 << " la: " << quy[i] << endl;
        }
        cout << "\n\tTong doanh thu cho tung chi nhanh lan luot la: \n";
        for (int i = 0; i < n; i++) {
            cout << b[i].Namecn << ": " << sum[i] << endl;
            tongds += sum[i];
        } 
        cout << "\nTong doanh so hang nam cua cong ty: " << tongds << endl;
        for (int i = 0; i < n; i++) {
            cout << "Doanh so TB cho chi nhanh " << b[i].Namecn << " la: " << sum[i]/4 << endl;
        }
        float min, max = min = quy[0];
        int iMin = 0, Imax = 0;
        for (int i = 0; i < n; i++) {
            if(max <= quy[i]){
                max = quy[i];
                Imax = i;
            }
            if(min >= quy[i]){
                min = quy[i];
                iMin = i;
            }
        }
        cout << "Quy cao nhat la quy " << Imax + 1 << " voi doanh so la: " << max << endl;
        cout << "Quy thap nhat la quy " << iMin + 1 << " voi doanh so la: " << min << endl;
    }
	return 0;
}