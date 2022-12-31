#include<iostream>
using namespace std;

class Mangloc{
    string mang;
    int a[100];
    int size;
    virtual bool thoaman(int i) const = 0;
    protected:
        void khoitao(string m){
        mang = m;
        size = 0;
    }
    public:
        
        void them(int n){
            if(thoaman(n)){
                a[size] = n;
                size++;
            }
        }
        virtual void hienthi() const{
            cout << mang << " " << size << endl;
            for(int i = 0; i < size; i++){
                cout << a[i] << " ";
            }
            cout << endl;
        }
        virtual ~Mangloc(){}
};

class ManglocChiaHet: public Mangloc{
    int chiahet;
    bool thoaman(int i) const {
        return i%chiahet == 0;
    };
    public:
    ManglocChiaHet(int c){
        khoitao("Mang loc chia het");
        chiahet = c;
    
    }
    void hienthi() const{
        Mangloc :: hienthi();
        cout << chiahet << endl;
    }
};
class Manglocnhohon: public Mangloc{
    int nhohon;
    bool thoaman(int i) const {
        return i<nhohon;
    };
    public:
    Manglocnhohon(int c){
        khoitao("Mang loc chia het");
        nhohon = c;
    
    }
    void hienthi() const{
        Mangloc :: hienthi();
        cout << nhohon << endl;
    }
};

class ManglocUoc: public Mangloc{
    int uoc;
    bool thoaman(int i) const {
        return (uoc%i==0);
    };
    public:
    ManglocUoc(int c){
        khoitao("Mang loc Uoc");
        uoc = c;
    
    }
    void hienthi() const{
        Mangloc :: hienthi();
        cout << uoc << endl;
    }
};
class ManglocNgoaiKhoang: public Mangloc{
    float trai, phai;
    bool thoaman(int i) const {
        return (i<trai||i>=phai);
    };
    public:
    ManglocNgoaiKhoang(float l, float r){
        khoitao("Mang loc Ngoai Khoang");
        trai = l;
        phai = r;
    
    }
    void hienthi() const{
        Mangloc :: hienthi();
        cout << trai << " " << phai << endl;
    }
};



int main(){
    int n = 5;
    //Mangloc *a[] = {new ManglocChiaHet(3), new Manglocnhohon(20),
     //               new ManglocChiaHet(4), new Manglocnhohon(30),
       //             new ManglocChiaHet(6)};
    Mangloc *a[] = {new ManglocUoc(3), new ManglocUoc(20),
                    new ManglocUoc(4), new ManglocNgoaiKhoang(30, 50),
                    new ManglocNgoaiKhoang(6, 10)};
    int m = 20;
    int b[] = {1,2,3,4,5,6,7,8,9,10,11,12,13,14,15,16,17,18,19,20};
    for(int i = 0; i < n; i++){
        for(int j = 0; j < m; j++){
            a[i]->them(b[j]);
        }
    }
    for(int i = 0; i < n; i++){
        a[i]->hienthi();
    }

}