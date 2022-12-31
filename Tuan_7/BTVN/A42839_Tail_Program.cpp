/*
1.Tail Program 
Viết chương trình yêu cầu người dùng nhập tên tệp. Chương trình sẽ hiển thị 10 dòng cuối cùng 
của tệp trên màn hình (“đuôi” của tệp). Nếu tệp có ít hơn 10 dòng, toàn bộ tệp sẽ được hiển thị,
với thông báo cho biết toàn bộ tệp đã được hiển thị. Sau đó tạo một tệp văn bản đơn giản có thể 
dùng để kiểm tra chương trình này
    Gợi ý:dùng hàm seekg, seekp
*/

#include<iostream>
#include<fstream>
using namespace std;

const int k = 10;

int main(){
    string FinName;
    cout << "Nhap ten file can doc: "; cin >> FinName;
    ifstream in;
    in.open(FinName,ios::in);
    if(!in) cout << "Loi khong doc duoc file.";
    else{
        string n; 
        int dem = 0;
        while (getline(in,n)){ dem++;}
        in.clear();
        in.seekg(0, ios::beg);
        if(dem < k){
            while (getline(in,n)){cout << n << endl;}
            cout << "\n \tToan bo tep da duoc hien thi. \n";
        }
        else{ 
            int sodong = dem - k;
            for(int i = 0; i < sodong; i++){
                getline(in,n);
            }
            cout << "\n \tMuoi dong cuoi: \n";
            while (getline(in,n)){cout << n << endl;}
        }
    }
    in.close();
    return 0;
}
