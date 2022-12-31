/*
Viết chương trình mô phỏng các thùng hàng tồn trong kho. 
Mỗi thùng hàng tồn chứa các bộ phận cùng loại nên có thể mô hình hoá bằng các thông tin sau: 
    •Thông tin về loại bộ phận được giữ trong thùng
    •Thông tin về số lượng các bộ phận đó.
 Main sẽ khai báo 1 mảng gồm 10 thùng, và khởi tạo mảngvới dữ liệu sau:
            Mô tả bộ phận        Số bộ phận trong thùng
            Van                  10
            Vòng bi              5
            Ống lót              15
            Khớp nối             21
            Mặt bích             7
            Bánh răng            5
            Vỏ hộp số            5
            Máy kẹp chân không   25
            Cáp                  18
            Que                  12
Ngoaì ra cầnviếtthêmcác hàm sau: 
    •AddParts: tăng số bộ phận trong một thùng nào đó thêm một số nà ođó (ví dụ tăng thêm 1,2,3,4 ... bộ phận)
    •RemoveParts: giảm số bộ phận trong một thùng nào đó bớtđimột số nàođó (ví dụ giảm đi 1,2,3,4 ... bộ phận)
    Sau khi khai báo mảng, main sẽ chạy vòng lặp thực hiện các bước sau: 
    •Đầu tiên hiển thị mỗi thùng chứa loại bộ phận nào và có bao nhiêu bộ phận đó.
    •Sau đó hỏi người dùng muốn thoát khỏi chương trình hay muốn chọn một thùng để xử lý. 
    Nếu chọn thoát thì thoát chương trình. 
    Nếuchọnmột thùng, người dùng có thể thêm các bộ phận vào thùng đó hoặc xóa các bộ phận khỏi thùng đó. 
    •Sau đó, vòng lặp lặp lại, lạihiển thị dữ liệu cácthùng trên màn hình.
    Xác thực đầu vào:Không thùng nào có thể chứa nhiều hơn 30 bộ phận. 
Ngoài ra, không chấp nhận các giá trị âm cho số bộ phận được thêm vào hoặc bị xóa đi.
*/
#include<iostream>
#include<iomanip>
using namespace std;

struct Inventory_Bins{
    string name;
    int sl;
};
void AddParts( Inventory_Bins & I,int n){
    if(I.sl < 0 ||I.sl > 30) cout<<"Loi\n";
    else {
        I.sl += n;
        if(I.sl > 30) cout<<"Vuot qua suc chua\n";
        else{
            cout<<"Sau khi them\n";
            cout<<setw(20)<<I.name<<setw(5)<<I.sl<<endl;
        }
    }
}

void removeParts (Inventory_Bins & I,int n) {
    if(n > I.sl || I.sl < 0 || I.sl>30) cout<<"Loi\n";
    else {
        I.sl -= n;
        if(I.sl>30) cout<<"Vuot qua suc chua.\n";
        cout<<"Sau khi giam.\n";
        cout<<setw(20)<<I.name<<setw(5)<<I.sl<<endl;
    }
}


void menu(Inventory_Bins I[]){
    int c;
    cout << "\n---------Menu---------\n";
    cout<<"1 .Them so bo phan.\n"
        <<"2. Giam so bo phan. \n"
        <<"3. Thoat. \n";
    cout<<"Nhap lua chon(1-3): ";
    do{
        cin>>c;
    }
    while(c<1||c>3);
    while(true){
        switch (c){
            case 1: 
                int i,n;
                cout<<"Nhap vi tri muon them: "; cin>>i;
                cout << "Nhap so luong: "; cin>>n;
                AddParts(I[i],n);
                break;
            case 2:
                int j,m;
                cout<<"Nhap vi tri muon giam: "; cin >> j;
                cout << "Nhap so luong:"; cin>>m;
                removeParts(I[j-1],m);
                break;
            default: cout<<"Thoat CT...\n"; exit(0);
        }
    }
}

int main(){
    int c;
    Inventory_Bins a []={{"Van",10}, {"Vong bi",5}, {"Ong lot",15},
                    {"Khop noi",21}, {"Mat bich",7}, {"Banh rang",5},
                    {"Vo hop so",5}, {"May kep chan khong",25}, {"Cap",18}, {"Que",12}};
    cout<<left<<setw(20)<<"Mo ta bo phan"<<setw(5)<<"So luong"<<endl;
    for(int i=0;i<10;i++){
        cout<<left<<setw(20)<<a[i].name<<setw(5)<<a[i].sl<<endl;
    }
    menu(a);
    return 0;
}
