#include<iostream>
#include<fstream>
using namespace std;

// int main(){
//     int n; cin >> n;
//     ofstream out("File.dat", ios::binary);
//     out.write(reinterpret_cast <char *> (&n), sizeof(n));
//     out.close();
    
//     int n1; cin >> n1;
//     ifstream in("File.dat", ios::binary);
//     in.read(reinterpret_cast <char *> (&n1), sizeof(n1));
//     in.close();
// }


//A42839
int main(){
    int n=3;
    double d = 1.2;
    bool f = false;
    char c = 'C';
    ofstream out("File.dat", ios::binary);
    out.write(reinterpret_cast <char *> (&n), sizeof(n));
    out.write(reinterpret_cast <char *> (&d), sizeof(d));
    out.write(reinterpret_cast <char *> (&f), sizeof(f));
    out.write((&c), sizeof(c)); // vì nó là kiểu chả sẵn
    
    int a[2] = {10,12};
    out.write(reinterpret_cast <char *> (a), sizeof(a)); // không cần để & là tại vì nó đã là 1 con trỏ

    out.close();

//A42839

    int n1;
    double d1;
    bool f1;
    char c1;
    int a1[10];
    ifstream in("File.dat", ios::binary);
    in.read(reinterpret_cast <char *> (&n1), sizeof(n1));
    in.read(reinterpret_cast <char *> (&d1), sizeof(d1));
    in.read(reinterpret_cast <char *> (&f1), sizeof(f1));
    in.read((&c1), sizeof(c1)); // vì nó là kiểu chả sẵn
    in.read(reinterpret_cast <char *> (a1), sizeof(a1)); // không cần để & là tại vì nó đã là 1 con trỏ
    cout << n1 << " " << d1<< " " << f1<< " " << c1<< " " << a[0] << " " << a[1];
    in.close();
}