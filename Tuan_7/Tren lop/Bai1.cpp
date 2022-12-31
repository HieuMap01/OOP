#include<iostream>
#include<fstream>
using namespace std;
//A42839
// int main(){
//     ifstream fin("SinhVien.txt");
//     ofstream fout("DiemSo.txt");
//     if(!fin) cout << "Loi.";
//     else{
//         string MSV, name;
//         getline(fin,MSV);
//         getline(fin,name);
//         if(!fout) cout << "Loi.";
//         else{
//             fout << MSV << endl << name << endl;
//         }
//         fout.close();
//     }
//     fin.close();
//     return 0;
// }
//A42839 - Bui Minh Hieu
int main(){
    string finname, foutname;
    cout << "Nhap ten file can doc: "; cin >> finname;
    cout << "Nhap ten file can ghi: "; cin >> foutname;
    ifstream fin(finname);
    ofstream fout(foutname);
    if(!fin) cout << "Loi.";
    else{
        double n, sum = 0;
        int dem = 0;
        while(fin>> n){
            sum += n;
            dem++;
        }
        double TB = sum/dem;
        if(!fout) cout << "Loi.";
        else{
            fout << "Tong: " << sum << endl << "So luong: " << dem <<endl << "Gia tri TB: " <<TB;
        }
        fout.close();
    }
    fin.close();
    return 0;
}
