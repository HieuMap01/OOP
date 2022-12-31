#include<iostream>
#include<fstream>
#include<algorithm>
using namespace std;
struct CorpSale{
    string name;
    double doanhso[4];
};
int main(){
    CorpSale cp[4]={{"Dong"},{"Tay"},{"Nam"},{"Bac"}};
    for(int i = 0; i<4; i++){
        cout<<"Chi nhanh "<<cp[i].name<<":\n";
        for(int j=0; j<4; j++){
            cout<<"Nhap quy "<<j+1<<": ";
            cin>>cp[i].doanhso[j];
        }
    }
    ofstream out("DoanhSo.dat", ios::binary);
    out.write(reinterpret_cast<char *>(cp), 4*sizeof(CorpSale));
    out.close();
    ifstream in("DoanhSo.dat", ios::binary);
    CorpSale cp2[4];
    in.read(reinterpret_cast<char *>(cp2), 4*sizeof(CorpSale));
    double sumnam_cty=0;
    for(int i = 0; i<4; i++){
        double sumquy = 0;
        cout<<"Tong doanh thu cua cong ty trong quy "<<i+1<<": ";
        for(int j = 0; j<4; j++) sumquy+=cp2[j].doanhso[i];
        cout<<sumquy<<endl;
    }
    cout<<"Tong doanh thu hang nam cho tung chi nhanh:\n";
    for(int i = 0; i<4; i++){
        double sumnam = 0;
        for(int j=0; j<4; j++) sumnam+=cp2[i].doanhso[j];
        cout<<"Chi nhanh "<<cp2[i].name<<" "<<sumnam<<endl;
        sumnam_cty += sumnam;
    }
    cout<<"Tong doanh thu hang nam cua cong ty: "<<sumnam_cty<<endl;
    cout<<"Doanh so trung binh hang quy cho cac chi nhanh: ";

}