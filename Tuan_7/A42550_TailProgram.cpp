#include<iostream>
#include<fstream>
using namespace std;
int main(){
    string namefile1;
    double n; int count = 0;
    cout<<"Nhap ten tep: "; cin>>namefile1;
    ifstream in(namefile1.c_str());
    if(in){
        while(in>>n){
            // cout<<count<<": ";
            count++;
            // cout<<n<<" ";
        }    
    }
    cout<<count<<endl;
    in.clear();
    in.seekg(0, ios::beg);
    int jump = count - 10;
    if (jump <= 0){
        while (in>>n)
        {
            cout<<n<<" ";
        }
        cout<<"Toan bo tep da duoc hien thi!";
    }   
    else{
        for(int i = 0; i<jump; i++){
            in>>n; //in vàp trước n-10 dòng đầu
            cout<<n<<" ";
        }
        cout<<"\n10 dong cuoi: "<<endl;
        while(in>>n) cout<<n<<" "; //in tiếp 10 dòng cuối
    }
    in.close();
    return 0;
}