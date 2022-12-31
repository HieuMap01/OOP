#include<iostream>
using namespace std;

struct book
{
    string name, tg;
    int NXB;
    string NHXB;
};

    
int main(){
    book b1 = {"Lord of the rings", "J.R.R. Tolkien", 1954, "Allen & Unwin"},
         b2 = {"Truyền kỳ mạn lục", "Nguyễn Dữ"};
    cout << "Ten: " << b1.name << endl
         << "Tac gia: " << b1.tg << endl
         << "Nam XB: " << b1.NXB << endl
         << "Nha XB: " << b1.NHXB << endl;
    cout << "Ten: " << b2.name << endl
         << "Tac gia: " << b2.tg << endl
         << "Nam XB: " << b2.NXB << endl
         << "Nha XB: " << b2.NHXB << endl;
    return 0;
}