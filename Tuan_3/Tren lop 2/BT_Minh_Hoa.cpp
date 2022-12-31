#include<iostream>
using namespace std;

int main(){
    int num,r,sum=0,temp;
    cout << "Nhap so nguyen can kiem tra:";
    cin >> num;
    if(num<1000) cout << "No";
    else
    {
    for(temp=num;num!=0;num=num/10){
         r=num%10;
         sum=sum*10+r;
    }
    if(temp==sum)
         cout <<"YES";
    else
         cout <<"NO";
    }
}
