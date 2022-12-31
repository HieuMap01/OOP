#include<iostream>
using namespace std;


const int n = 4;
enum quy{ quy1, quy2, quy3, quy4 };

enum BP{dong,tay,nam,bac};

struct Department{
    string name;
    float sale[n], sum, avg;
};

void input(Department & d){
    cout << "Doanh so 4 quy cua bo phan "
    << d.name << ": \n";
    for (int i = quy1; i <= quy4; i++) {
    cin >> d.sale[i];
    d.sum += d.sale[i];
    }
    d.avg = d.sum / n;
    cout << endl;
}

void output (const Department & d){
    cout << d.name << endl;
    for (int i = quy1; i <= quy4; i++)
    cout << d.sale[i] << " ";
    cout << endl;
    cout << d.sum << endl << d.avg
    << endl << endl;
}

int main (){
    Department a[] = {{"Dong"}, {"Tay"},
    {"Nam"}, {"Bac"}};
    for (int i = dong; i<=tay; i++)
    input (a[i]);
    cout << endl;
    for (int i = dong; i<=tay; i++)
    output (a[i]);
    return 0;
}


// void input(Department & d){
//     cout << "Doanh so 4 quy cua bo phan "
//     << d.name << ": \n";
//     for (int i = 0; i < n; i++) {
//     cin >> d.sale[i];
//     d.sum += d.sale[i];
//     }
//     d.avg = d.sum / n;
//     cout << endl;
// }

// void output (const Department & d){
//     cout << d.name << endl;
//     for (int i = 0; i < n; i++)
//     cout << d.sale[i] << " ";
//     cout << endl;
//     cout << d.sum << endl << d.avg
//     << endl << endl;
// }