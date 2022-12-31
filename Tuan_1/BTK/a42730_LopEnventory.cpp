/*
Thiết kế lớp Inventory chứa thông tin về mặt hàng trong kho. Lớp có các thành viên sau:
itemNumber:số int chứa mã mặt hàng 
quantity:số int lưu số lượng mặt hàng đó đang có trong kho 
cost:số double lưu giá bán buôn cho mỗi đơn vị của mặt hàng
TotalCost:số double nắm giữ tổng phí tồn kho của mặt hàng (được tính theo sốlượng nhân với chi phí).
Hàm tạo mặc định: đặt tất cả các biến thành viên thành 0.
Hàm tạo thứ hai: nhận vào 3 tham số để cập nhật cho itemNumber,quantity và cost, 
sau đó hàm này nên gọi tới setTotalCost.
setItemNumber:nhậnvào 1 tham số để cập nhật cho itemNumber.
setQuantity:nhận vào 1 tham số để cập nhật cho quantity.
setCost:nhận vào 1 tham số để cập nhật cho cost.
setTotalCost:tính tổng phí tồn kho theo công thức(cost* quantity) rồi lưu vào TotalCost.
getItemNumber:Trả về giá trị itemNumber.
getQuantity:Trả về giá trị quantity.
getCost:Trảvềgiá trịcost.
getTotalCost:Trả về giá trị TotalCost
Sau đó demo các chức năng của lớp trong một chương trình.Xác thực đầu vào: 
Không chấp nhận itemNumber, quantity, cost âm
*/
#include<iostream>
using namespace std;
class Inventory{ 
    int ittemNumber,quantity;
    double cost,TotalCost;
    public:
    Inventory() {
        ittemNumber=0;
        quantity=0;
        cost=0;
        TotalCost=0;
    }
    // void inforInventory (int it, int q, double c){
    //     ittemNumber = it;
    //     quantity = q;
    //     cost = c;
    // }
    void setittemNumber (int ittemNumber) { this ->ittemNumber =ittemNumber ;}
    void setquantity (int quantity ) { this -> quantity = quantity ;}
    void setcost (double cost ) { this -> cost = cost ;}
    void setTotalCost(double t, double q, double c){
        TotalCost = t;
        t = c * q;
    }
    int getitemNumber() const {return ittemNumber;}
    int getquantity() const {return quantity;}
    double getcost() const {return cost;}
    double getTotalCost() const{return TotalCost;}
};
int main(){
    Inventory abc;
    int itemNumber, quantity;
    double cost, TotalCost;
    do{
        cout << "Nhap Ma mat hang: "; cin >> itemNumber;
    } while(itemNumber < 0);
    do{
        cout << "Nhap so luong mat hang trong kho: "; cin >> quantity;
    }while(quantity < 0);
    do{
        cout << "Gia ban cho moi don vi mat hang: "; cin >> cost;
    }while(itemNumber < 0);
    abc.setittemNumber(itemNumber);
    abc.setquantity(quantity);
    abc.setcost(cost);
    abc.setTotalCost(TotalCost, quantity, cost);
    cout << "Ma mat hang: " << abc.getitemNumber() << endl
         << "So luong mat hang: " << abc.getquantity() << endl
         << "Gia ban: " << abc.getcost() << endl
         << "Tong chi phi: " << abc.getTotalCost() << endl;
    return 0;
}