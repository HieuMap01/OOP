#include<iostream>
using namespace std;

struct MovieData
{
    string tieude, daodien;
    int NPH, TGC;

};

void print(MovieData M){
    cout << "Tieu de: " << M.tieude << endl
         << "daodien: " << M.daodien << endl
         << "Nam PH: " << M.NPH << endl
         << "TGC : " << M.TGC << endl;
}

    
int main(){
    MovieData b1 = {"John Wick", "Chad Stahelski", 2014, 102},
         b2 = {"John Wick: Chapter 4", "Chad Stahelski", 2023};
    print(b1);
    print(b2);
    
    return 0;
}