#include<iostream>
using namespace std;

int test(int n){
    if(n<2){
        return n;
    }
    else{
        return (test(n - 1) + test(n-2));
    }
}

int main(){
    int n;
    cout << "Nhap vao N: "; cin >> n;
    cout << "KQ: " << test(n);
    return 0;
}