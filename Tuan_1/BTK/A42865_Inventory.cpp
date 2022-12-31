#include <iostream>
using namespace std;
class Inventory{
    int itemNumber = 0;
    int quantity = 0;
    double cost = 0;
    double TotalCost = 0;
    int check1(int i) const{
            if(i < 0) throw "ItemNumber error!";
            return i;
    }
    int check2(int q) const{
        if(q  < 0) throw "Quantity error!";
        return q;
    }
    double check3(double c) const{
        if(c < 0) throw "Cost error!";
        return c;
    }
public:
    void setItemNumber(int INum) {itemNumber = INum;}
    void setQuantity(int q) {quantity = q;}
    void setCost(double c) {cost = c;}
    void setTotalCost() {TotalCost = cost * quantity;}
    int getItemNumber() const {return itemNumber;}
    int getQuantity() const {return quantity;}
    double getCost() const {return cost;}
    double getTotalCost() {return TotalCost;}

    Inventory(){};
    Inventory(int iNum, int q, double c): itemNumber(check1(iNum)), quantity(check2(q)), cost(check3(c)){
            setTotalCost();
        };
};
int main(){
    int itemNumber,quantity;
    double cost;
    cout<<"Nhap vao ma mat hang: "; cin >> itemNumber;
    cout<<"Nhap vao so luong mat hang " << itemNumber << " : "; cin >> quantity;
    cout<<"Nhap vao gia ban buon cua moi don vi hang: "; cin >> cost;
    try{
        Inventory i(itemNumber, quantity, cost);
    }catch(const char * e){
        cout << e;
    }
    Inventory i(itemNumber, quantity,cost);
    cout << "-------------------------------------------" << endl;
    cout<<"Ma mat hang                      : "<< i.getItemNumber()<<endl;
    cout<<"So luong hang co trong kho       : "<< i.getQuantity()<<endl;
    cout<<"Gia ban buon cho moi don vi hang : "<< i.getCost()<<endl;
    cout<<"Tong chi phi ton kho cua mat hang: "<< i.getTotalCost()<<endl;

    return 0;
}