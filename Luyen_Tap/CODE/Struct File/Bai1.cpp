/*
7. Inventory Program
Cho cấu trúc có tên HangHoa để lưu trữ dữ liệu về 1 mặt hàng được mô tả như sau:
struct HangHoa
{
	char TenHang[30];		//Tên hàng
	int SoLuong;			//Số lượng
	float BanBuon;		//Giá bán buôn trên 1 đơn vị
};
Yêu cầu: 
Viết chương trình thực hiện:
-	Cho phép người dùng nhập dữ liệu của n mặt hàng với n được nhập vào từ bàn phím
-	Hỏi người dùng nhập vào vị trí muốn hiển thị, sau đó hiển thị thông tin mặt hàng tại vị trí đó gồm: 
Tên hàng, Số lượng, Tổng tiền bán buôn.Trong đó, Tổng tiền bán buôn = Số lượng * Giá bán buôn trên 1 đơn vị.  
-	Ghi thông tin tất cả mặt hàng vào tệp nhị phân có HangHoa.dat
*/

#include<iostream>
using namespace std;
#include<fstream>

struct HangHoa
{
	char TenHang[30];		//Tên hàng
	int SoLuong;			//Số lượng
	float BanBuon;		//Giá bán buôn trên 1 đơn vị
};

int main(){
    int Sl;
    cout << "Nhap so luong mat hang: "; cin >> Sl;
    HangHoa H[Sl];
    for(int i = 0; i<Sl; i++){
        cout << "Nhap mat hang vi tri thu " << i << ": \n";
        cin.ignore();
        cout << "Ten mat hang: "; cin.getline(H[i].TenHang,30) ;
        cout << "So Luong: " ; cin>> H[i].SoLuong ; 
        cout << "Gia ban: " ; cin>> H[i].BanBuon ;
        cout << endl;
    }
    int n;
    cout << "Nhap vi tri ban muon hien thi: "; cin >> n;
    if(n > 0 || n < Sl){
        for(int i = 0; i<Sl; i++){
            if(n == i){
                cout << "Ten: " << H[i].TenHang << endl;
                cout << "So luong: " << H[i].SoLuong << endl;
                cout << "Tong tien ban buon: " << H[i].SoLuong * H[i].BanBuon << endl;
            }
        }
    }
    else cout << "Ko co vi tri nay";
    ofstream out ("HangHoa.dat", ios::binary); 
    if (out){
        out.write(reinterpret_cast< char* > (H), n* sizeof(HangHoa)); 
        out.close(); 
    }
    return 0;
}