/*
5. RetailItem Class
Viết một lớp có tên là RetailItem chứa dữ liệu về một mặt hàng trong cửa hàng bán lẻ. 
Lớp phải có các biến thành viên sau:
• description: Một chuỗi chứa mô tả ngắn gọn về mặt hàng.
• unitOnHand: Một int chứa số lượng đơn vị hiện có trong kho
• price: Một double giữ giá bán lẻ của mặt hàng.
Viết một hàm tạo chấp nhận các đối số cho mỗi biến thành viên, 
các hàm setter thích hợp lưu trữ các giá trị trong các biến thành viên này và các hàm getter 
trả về các giá trị trong các biến thành viên này, và hàm print in ra mọi thông tin. Khi bạn đã viết lớp, 
hãy viết một chương trình tạo ra năm đối tượng RetailItem, nhập liệu cho chúng từ bàn phím, rồi hiển thị 
mọi thông tin của từng đối tượng.
*/

#include<iostream>
using namespace std;

class RetailItem{
    string description;
    int unitOnhand;
    double price;
    public:
    void setAll(string des, int uni, double pri){
        description = des;
        unitOnhand = uni;
        price = pri;
    }
    void setDes( string des){
        description = des;
    }
    void setUni(int uni){
        unitOnhand = uni;
    }
    void setPri(double pri){
        price = pri;
    }
    string setDes() const{return description;}
    int setUni() const{return unitOnhand;}
    double setPri() const{return price;}
    void print() const{
        cout << "Mo ta: "<<description <<"\nLuong don vi: "<< unitOnhand <<"\nGia ban le: "<< price << endl;
    }
};
int main(){
    RetailItem re[5];
    for(int i = 0; i<5; i++){
        string des;
        int uni;
        double pri;
        cout << "Nhap mo ta: ";
        cin.ignore();
        getline(cin,des);
        cin >> uni;
        cin >> pri;
        re[i].setAll(des,uni,pri);
    }
    for(int i = 0; i<5; i++){
        re[i].print();
    }
    return 0;
}