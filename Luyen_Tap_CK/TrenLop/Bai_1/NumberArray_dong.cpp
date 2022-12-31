#include<iostream>
using namespace std;

class NumberArray{
    int size;
    double *a;
    public:
        NumberArray(int s, double v){
            size = s;
            a = new double[size];
            for(int i = 0; i<size; i++){
                a[i] = v;
            }
        }
        ~NumberArray(){delete[]a;}
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
        void print() const{
            cout << size << endl;
            for(int i = 0; i<size; i++){
                cout << a[i] << " ";
            }
        }
};
 int main(){
    NumberArray a(5, 2.5);
    cout << a.getSize() << endl << a.get(3) << endl << a.getMax() << endl;
 }