#include<iostream>
using namespace std;

const int n = 3;

struct Inventory_Bins{
    string name_BP;
    int So_BP;
};

void AddParts(Inventory_Bins & I, int i){
    I.So_BP +=i ;
}

void RemoveParts(Inventory_Bins & I, int i){
    I.So_BP -= i;
}


int main(){
    Inventory_Bins I[10]={{"van", 10}, {"Vong bi", 5}, {"Ong lot", 15}, {"Khop noi", 21},
                          {"mat bich", 7},{"Banh rang", 5},{"vo hop so", 5},{"May kep chan khong", 25},
                          {"Cap", 18},{"Que", 18}};
    for(int i = 0; i < n; i++){               
        cout << I[i].name_BP << ":    " << I[i].So_BP << endl;
    }
    AddParts(I[3],5);
    cout << I[3].name_BP << ":    " << I[3].So_BP << endl;
    RemoveParts(I[5],2);
    cout << I[5].name_BP << ":    " << I[5].So_BP << endl;
    // Inventory_Bins I[n];
    // input(I);
    // output(I);
    return 0;
}

// void input(Inventory_Bins I[]){
//     for(int i = 0; i < n; i++){
//         cout << "Ten bo phan: " ; getline(cin,I[i].name_BP);
//         cout << "Nhap so luong: "; cin >> I[i].So_BP;
//         cin.ignore();
//     }
// }

// void output(Inventory_Bins I[]){
//     for(int i = 0; i < n; i++){
//     cout << I[i].name_BP << ":     " << I[i].So_BP << endl;
//     }
// }