/*
3.Tài khoản khách hàng -Customer Accounts
Viết chương trình có cấu trúc dữ liệu về tài khoản khách hàng sau:
    •Tên
    •Địa chỉ
    •Thành phố, Tiểu bang và Zip
    •Số điện thoại
    •Số dư tài khoản
    •Ngày thanh toán cuối cùng
Chương trình cài đặt một danh sách tài khoản dưới dạng một mảng gồm 10 phần tử cấu trúc trên.
Hiển thị menu với các chức năng tương ứng:
    1.Nhập các tài khoản vào mảng; //nhậpdần các cấu trúc từ đầu đến cuối mảng
    2.Sửa đổi thông tin tài khoản; //Hỏi người dùng vị trí muốn sửa.
    Sau đó cho người dùng nhập lại thông tin tài khoản ở vị trí đó.
    Sau khi nhập xong thì gán lại thông tin tương ứng.
    3.Hiển thị danh sách tài khoản; //Hiển thị lầnlượt danh sách cáctài khoản
    4.Tìm kiếm tài khoản; // nhập vào tên người dùng, duyệt qua mảng và tìm tài khoản có tên đó,
    nếu có trả về chỉ số phần tử đó, nếu không có trả về -1.
    5.Thoát khỏi chương trình;// Thoát khỏi chương trình đang thực hiện
 Xác thực đầu vào:Khi nhập dữ liệu cho tài khoản(dù nhập lần đầu hay nhập để sửa),
 hãy đảm bảo người dùng nhập dữ liệu cho tất cả các trườngvà số dư tài khoản không chấp nhận âm.
Chỉ cần dùng kiểm tra do ... while thông thường ở hàm main, không cần dùng ngoại lệ.
*/
#include<iostream>
#include<iomanip>
using namespace std;

const int n=10;
struct Customer_Accounts
{
    string name, address, city;
    string sdt;
    int sodu;
    string ngay;
};

void Input(Customer_Accounts & C){
    cout << "Nhap ten: "; getline(cin,C.name);
        cout << "Nhap dia chi: "; getline(cin,C.address);
        cout << "Nhap thanh pho: "; getline(cin,C.city);
        cout << "Nhap SDT: "; getline(cin,C.sdt);
        cout << "Nhap so du: "; cin >> C.sodu ;
        cout << "Nhap ngay thanh toan cuoi cung: "; cin.ignore(); getline(cin,C.ngay);

}

void Input(Customer_Accounts C[]){
    cin.ignore();
    for(int i = 0; i<n; i++){
        cout << "ID " << i+1 << ": "<<  endl;
        Input(C[i]);
    }
}

void Suadoi(Customer_Accounts C[]){
    int ID;
    cout << "Nhap ID muon thay doi: " ; 
    do{
        cin >> ID;
    }
    while (ID<0||ID>n);
    cin.ignore();
    Input(C[ID]);
}

const int l = 20;
void output(Customer_Accounts C[]){
    cout << setw(5) << left << "ID" << setw(l) << "Name" << setw(l) << "Address" << setw(l) << "City" 
         << setw(l) << "STD" << setw(l) << "So du" << setw(l) << "Date" << endl;
    for (int i = 0; i < n; i++){
        cout << setw(5) << left << i+1 << setw(l) << C[i].name << setw(l) << C[i].address << setw(l) << C[i].city 
             << setw(l) << C[i].sdt << setw(l) << C[i].sodu << setw(l) << C[i].ngay << endl;
    }
}


void search(const Customer_Accounts C[]){
    string ten;
    bool check = 1;
    cin.ignore();
    cout << "Nhap ten nguoi dung: "; getline(cin, ten);
    cout << "ID: "; 
    for(int i = 0; i < n; i++){
        if(C[i].name == ten){
            cout << i+1;
            check = 0;
        }
    }
    if(check != 0) cout << -1;

}

void Menu(Customer_Accounts C[]){
    do{
    int chon;
    cout << "\n----------MENU----------\n";
        cout << "1. Nhap cac thong tin TK.\n"
             << "2. Sua doi thong tin Tk.\n"
             << "3. Hien thi danh sach TK.\n"
             << "4. Tim kiem thong tin TK.\n"
             << "5. Thoat CT.....\n"
             << "Nhap lua chon[1-5]: ";do {cin >> chon;}while(chon<0||chon>5);
        switch (chon)
        {
        case 1: Input(C);
            break;
        case 2: Suadoi(C);
            break;
        case 3: output(C);
            break;
        case 4: search(C);
            break;
        default: cout << "Thoat CT.....";
            exit(0);
        }
    }
    while (1);
}

int main(){
    Customer_Accounts C[n];
    Menu(C);
}

