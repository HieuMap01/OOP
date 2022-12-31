/*5. Inventory Bins:
Viết chương trình mô phỏng các thùng hàng tồn trong kho. Mỗi thùng hàng tồn chứa các bộ phận cùng loại nên có thể 
mô hình hoá bằng các thông tin sau:
• Thông tin về loại bộ phận được giữ trong thùng
• Thông tin về số lượng các bộ phận đó.
Main sẽ khai báo 1 mảng gồm 10 thùng, và khởi tạo mảng với dữ liệu sau:
Mô tả bộ phận     Số bộ phận trong thùng
Van                       10
Vòng bi                   5
Ống lót                   15
Khớp nối                  21
Mặt bích                  7
Bánh răng                 5
Vỏ hộp số                 5
Máy kẹp chân không        25
Cáp                       18
Que                       12
Ngoaì ra cần viết thêm các hàm sau:
• AddParts: tăng số bộ phận trong một thùng nào đó thêm một số nào đó (ví dụ tăng thêm 1,2,3,4 … bộ phận)
• RemoveParts: giảm số bộ phận trong một thùng nào đó bớt đi một số nào đó (ví dụ giảm đi 1,2,3,4 … bộ phận)
Sau khi khai báo mảng, main sẽ chạy vòng lặp thực hiện các bước sau:
• Đầu tiên hiển thị mỗi thùng chứa loại bộ phận nào và có bao nhiêu bộ phận đó.
• Sau đó hỏi người dùng muốn thoát khỏi chương trình hay muốn chọn một thùng để xử lý.
o Nếu chọn thoát thì thoát chương trình.
o Nếu chọn một thùng, người dùng có thể thêm các bộ phận vào thùng đó hoặc xóa các bộ phận khỏi thùng đó.
• Sau đó, vòng lặp lặp lại, lại hiển thị dữ liệu các thùng trên màn hình.
Xác thực đầu vào: Không thùng nào có thể chứa nhiều hơn 30 bộ phận. 
Ngoài ra, không chấp nhận các giá trị âm cho số bộ phận được thêm vào hoặc bị xóa đi
*/

#include <iostream>
#include <iomanip>
using namespace std;
struct InventoryBins{
    string tenbophan;
    int soluong;
};
enum options {ADD_PARTS = 1, REMOVE_PARTS = 2, QUIT = 3};
void AddParts(InventoryBins & a, int x){
    if(a.soluong < 0 || a.soluong > 30) cout << "ERROR!!\n";
    else{
        a.soluong += x;
        if(a.soluong > 30) cout << "Overloaded!!\n";
        else
            cout << "Thung sau khi them: \n";
            cout << a.tenbophan << "   " << a.soluong << endl;
    }
}

void RemoveParts (InventoryBins & a, int x) {
    if(a.soluong < 0 || a.soluong > 30) cout << "ERROR!!\n";
    else {
        a.soluong -= x;
        if(a.soluong > 30) cout << "Overloaded!!\n";
        else
            cout << "Thung sau khi giam: \n";
            cout << a.tenbophan << "   " << a.soluong << endl;
    }
}

void Menu (int & choice){
    cout << "-----------------------------" << endl;
    cout << "1. Them bo phan.\n"
         << "2. Giam bo phan.\n"
         << "3. Thoat chuong trinh.\n";
         
    cout << "-----------------------------" << endl;
    do{
        cout << "Nhap yeu cau ban muon thuc hien (1-3): ";
        cin >> choice;
    }while(choice < ADD_PARTS || choice > QUIT);
}

int main(){
    int choice;
    const int N = 10;
    InventoryBins a[10] = {{"Van",10}, {"Vong bi",5}, {"Ong lot",15},
                           {"Khop noi",21}, {"Mat bich",7}, {"Banh rang",5},
                           {"Vo hop so",5}, {"May kep chan khong",25}, {"Cap",18}, {"Que",12}};

    cout << left << setw(25) << "Ten bo phan" << "So luong" <<endl;
    for(int i = 0; i < N; i++)
        cout << left << setw(25) << a[i].tenbophan << a[i].soluong << endl;
    while(1){
        Menu(choice);
        switch(choice){
            case ADD_PARTS: 
                int i, n;
                cout << "Nhap thung bo phan muon them: "; cin >> i;
                cout << "Nhap so luong: "; cin >> n;
                AddParts(a[i-1],n);
                break;
            case REMOVE_PARTS:
                int j, x;
                cout << "Nhap thung bo phan muon giam: "; cin >> j;
                cout << "Nhap so luong: "; cin >> x;
                RemoveParts(a[j-1], x);
                break;
            case QUIT: cout << "Thoat chuong trinh thanh cong!!\n"; exit(0);
            defaut: cout << "Lua chon trong khoang 1-5!\n";
        }
    }
    return 0;
}
