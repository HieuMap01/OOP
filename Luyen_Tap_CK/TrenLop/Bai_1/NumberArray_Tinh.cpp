#include<iostream>
using namespace std;

class NumberArray{
    int size;
    double a[100];
    public:
        NumberArray(int n){
            if(n<0 && n>100) cout << "Kich thuoc khong hop le\n";
            size = n;
            for(int i = 0; i< size; i++) a[i] = 0;
        }
        int getSize() const {return size;}
        double get(int i){
            if(i>=0 && i<size) return a[i];
            else return -1;
        }
        void set(int i, double x){
            if(i>=0 && i<size) a[i] = x;
            else cout << "khong hop le.\n";
        }
        double getMax() const{
            double max = a[0];
            for(int i = 0; i<size; i++){
                if(max <= a[i]) max = a[i];
            }
            return max;
        }
        double getSum() const{
            double  sum = 0;
            for(int i = 0; i<size; i++){
                sum += a[i];
            }
            return sum;
        }
        void print() const{
            cout << size << endl;
            for(int i = 0; i<size; i++){
                cout << a[i] << " ";
            }
        }
};