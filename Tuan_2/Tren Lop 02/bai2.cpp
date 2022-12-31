// viết operator= cho lớp NumberArray
#include<iostream>
using namespace std;

class NumberArray
{
    private:
    int size;
    double * a;
    public:
        NumberArray(int size = 50): size(size), a(new double [size]){}
        ~NumberArray() { delete [] a; }
        NumberArray &operator= (const NumberArray &r){
            size = r.size;
            delete [] a;
            a = new double[size];
            for(int i=0; i<size; i++){
                a[i] = r.a[i];
            }
            return *this;
        }
        void setArray(double b[], int n){
            for(int i =0; i<n; i++){
                a[i] = b[i];
            }
        }
        void print() const {
            for(int i = 0; i<size;i++){
                cout << a[i] <<" ";
            }
            cout << endl;
        }
};

int main(){
    NumberArray a(3),b(5);
    double c[3]={2,3,5}, d[5]={1,4,3,2,6};
    a.setArray(c,3);
    b.setArray(d,5);
    a.print();
    b.print();
    a=b;
    a.print();
    b.print();
    return 0;
}