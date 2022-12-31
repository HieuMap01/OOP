#include<iostream>
#include<fstream>
using namespace std;
void arrayToFile(string name, int *ptr,  int size){
    ofstream out (name.c_str(), ios::binary);
    out.write(reinterpret_cast<char *> (ptr), size*sizeof(int));
    out.close();
}
void fileToArray(string namef, int *ptr, int size){
    ifstream in(namef.c_str(), ios::binary);
    in.read(reinterpret_cast<char *> (ptr), size*sizeof(int));
    in.close();
    cout<<"Mang trong file: ";
    for (int i=0; i<size; i++) cout<<ptr[i]<<" ";
}
int main(){
    const int n = 3;
    int arr[n]={1,2,3};
    int arr2[n];
    arrayToFile("Array.dat", arr, n);
    fileToArray("Array.dat", arr2, n);
}