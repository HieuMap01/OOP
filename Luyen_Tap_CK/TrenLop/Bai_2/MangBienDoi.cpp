#include<iostream>
using namespace std;


class MangBienDoi{
    string ten;
    double a[100];
    int size;
    virtual int bienDoi(int f) const = 0;
    protected:
        void ganten(string t){
            ten = t;
        }
    public:
        void ganMang(int b[], int n){
            size = n;
            if(size > 100)
                size = 100;
            for(int i = 0; i<size; i++)
                a[i] = b[i];
        }
        void lamBiendoi(){
            for(int i = 0; i<size; i++){
                a[i]=bienDoi(a[i]);
            }
        }
        virtual void hienthi()const{
            cout << ten << " " << size << endl;
            for(int i = 0; i<size; i++){
                cout << a[i] << " ";
            }
            cout << endl;
        }
        virtual ~MangBienDoi(){};
};

class MangTinhTien : public MangBienDoi{
    int x;
    int bienDoi(int i)const{return i+x;}
    public:
        MangTinhTien(double x){
            ganten("Mang tinh tien");
            this->x = x;
        }
        void hienthi()const{
            MangBienDoi::hienthi();
            cout << x << endl;
        }
};

class MangNhiPhan : public MangBienDoi{
    int bienDoi(int i)const{
        if(i % 2 == 0) return 0;
        return 1;
    }
    public:
        MangNhiPhan(){
            ganten("Mang Nhi phan");
        }
};

int main(){
    int n = 20;
    int b[] = {1,2,3,4,5,6,7,8,9,10,11,12,13,14,15,16,17,18,19,20};
    MangBienDoi *arr[] = {new MangTinhTien(5), new MangNhiPhan(), 
                        new MangTinhTien(10), new MangNhiPhan(),
                        new MangTinhTien(4)};
    int m = 20;
    for(int i = 0; i < n; i++){
        arr[i]->ganMang(b,m);
        arr[i]->lamBiendoi();}
    for(int i = 0; i < n; i++){
        arr[i]->hienthi();
    }
    return 0;
}