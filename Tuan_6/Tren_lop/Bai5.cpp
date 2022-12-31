#include<iostream>
using namespace std;

struct TKKH
{
    string name;
    string SDT;
    double SDTK;
    string NTT;
};
const int n = 2;
void input( TKKH & t){
    cout << "Name: "; getline(cin,t.name);
    cout << "SDT: "; getline(cin,t.SDT);
    cout << "SDTK: "; cin >> t.SDTK;
    cout << "NTT: ";cin.ignore(); getline(cin,t.NTT);
}

void input( TKKH  t[]){
    cin.ignore();
    for(int i = 0; i < n; i++){
        cout << "ID " << i+1 << endl;
        input(t[i]);
    }
}

void revison(TKKH t[]){
    int id;
    cout << "Nhap thu tu muon thay doi: ";
    do{ 
        cin >> id;
    }
    while(id<0||id>n);
    input(t[id]);
}

void listAcc(const TKKH t[]){
    for(int i = 0; i < n; i++){
        cout << "ID: " << i+1 << endl;
        cout << "Name: "<< t[i].name << endl;
        cout << "SDT: "<< t[i].SDT << endl;
        cout << "SDTK: "<< t[i].SDTK << endl;
        cout << "NTT: "<< t[i].NTT << endl;
    }

}

void menu(TKKH t[]){
    cout << "-------MENU-------\n"
         << "1. Nhap cac TK\n"
         << "2. Sua thong tin tk\n"
         << "3. Hien Thi DSTK\n"
         << "4. Thoat CT\n";
    int n;
    do
       { cout << "Nhap Lua chon(1-5): "; cin >> n;}
    while (n<1||n>4);
    switch(n)
    {
    case 1: input(t);
        break;
    case 2: revison(t);
        break;
    case 3: listAcc(t);
        break;
    default: cout << "Thoat CT.............";
        exit(0);
    }
}

int main(){
    TKKH t[n];
    while(true){
        menu(t);
    }
    return 0;
}