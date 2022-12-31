/*
1.5.Lớp Inventory
Thiết kếlớp Inventorychứa thông tin vềmặt hàng trong kho. Lớp có các thành viên sau:
    itemNumber: số int chứa mã mặt hàng
    quantity: số int lưu số lượng mặt hàng đó đang có trong kho
    cost: số double lưug iá bán buôn cho mỗi đơn vị của mặt hàng
    TotalCost: số double nắm giữ tổng phí tồn kho của mặt hàng (được tính theo sốlượng nhân với chi phí).
    Hàm tạo mặc định: đặt tất cả các biến thành viên thành 0.
    Hàm tạo thứ hai:nhận vào 3 tham số để cập nhật cho itemNumber,quantityvàcost, 
        sau đó hàmnày nêngọi tớisetTotalCost
    setItemNumber: nhận vào 1 tham số để cập nhật cho itemNumber.
    setQuantity: nhận vào 1 tham số để cập nhật cho quantity.
    setCost: nhận vào 1 tham số để cập nhật cho cost.
    setTotalCost: tính tổng phí tồn kho theocông thức (cost* quantity) rồilưu vào TotalCost.
    getItemNumber:Trả về giá trị itemNumber.
    getQuantity:Trả về giá trị quantity
    getCost: Trả về giá trịcost.
    getTotalCost:Trả về giá trị TotalCost
    Sau đó demo các chức năng của lớp trong một chương trình.
    Xác thực đầu vào: Không chấp nhận itemNumber, quantity, costâm
*/
#include<iostream>
using namespace std;

class Inventory{
    int itemNumber, quantity;
    double cost, TotalCost;
    public:
    Inventory(){
        itemNumber = 0;
        quantity = 0;
        cost = 0;
        TotalCost = 0;
    }
    Inventory(int it, int q, double c){
        itemNumber = it;
        quantity = q;
        cost = c;
        setTotalCost(q,c);
    }
    /*setItemNumber: nhận vào 1 tham số để cập nhật cho itemNumber.
    setQuantity: nhận vào 1 tham số để cập nhật cho quantity.
    setCost: nhận vào 1 tham số để cập nhật cho cost.
    setTotalCost: tính tổng phí tồn kho theocông thức (cost* quantity) rồilưu vào TotalCost.*/
    void setitemNumber(int i){itemNumber = i;}
    void setquantity(int q){quantity = q;}
    void setcost(double c){cost = c;}
    void setTotalCost(double q, double c){
        TotalCost = c * q;
    }
    /*getItemNumber:Trả về giá trị itemNumber.
    getQuantity:Trả về giá trị quantity
    getCost: Trả về giá trịcost.
    getTotalCost:Trả về giá trị TotalCost*/
    int getitemNumber() const {return itemNumber;}
    int getquantity() const {return quantity;}
    double getcost() const {return cost;}
    double getTotalCost() const{return TotalCost;}
};

// Sau đó demo các chức năng của lớp trong một chương trình.
// Xác thực đầu vào: Không chấp nhận itemNumber, quantity, costâm

int main(){
    Inventory i;
    /*itemNumber: số int chứa mã mặt hàng
    quantity: số int lưu số lượng mặt hàng đó đang có trong kho
    cost: số double lưug iá bán buôn cho mỗi đơn vị của mặt hàng
    TotalCost: số double nắm giữ tổng phí tồn kho của mặt hàng (được tính theo sốlượng nhân với chi phí).*/
    int itemNumber, quantity;
    double cost, TotalCost;
    do{
    cout << "Nhap Ma mat hang: "; cin >> itemNumber;
    }
    while(itemNumber < 0);
    do{
    cout << "Nhap so luong mat hang trong kho: "; cin >> quantity;
    }
    while(quantity < 0);
    do{
    cout << "Gia ban cho moi don vi mat hang: "; cin >> cost;
    }
    while(itemNumber < 0);
    i.setitemNumber(itemNumber);
    i.setquantity(quantity);
    i.setcost(cost);
    i.setTotalCost(quantity, cost);
    cout << "---------Hien Thi---------\n"
         << "Ma mat hang: " << i.getitemNumber() << endl
         << "So luong mat hang: " << i.getquantity() << endl
         << "Gia ban: " << i.getcost() << endl
         << "Tong chi phi: " << i.getTotalCost() << endl;
    return 0;
}