#include<iostream>
using namespace std;

class MangLoc{
    string mota;
    int a[100];
    int size;
    virtual bool thoaMan(int i) const = 0;
    protected:
        void khoitao(string m){
            mota = m;
            size = 0;
        }
    public:
        void them(int i){
            if(thoaMan(i)) {
                a[size] = i;
                size++;
            }
        }
        virtual void hienthi() const{
            cout << mota << " " << size << "\n";
            for(int i = 0; i<size ; i++){
                cout << a[i] << " ";
            }
            cout << endl;
        }
        virtual ~MangLoc(){}
};
class MangLocBoi : public MangLoc{
    int boi;
    virtual bool thoaMan(int i) const{
        return (i%boi==0);
    };
    public:
        MangLocBoi(int n){
            khoitao("Mang loc boi so");
            boi = n;
        }
        void hienthi(){
            MangLoc :: hienthi();
            cout << boi << endl;
        }
};
class ManglocTrongKhoang: public MangLoc{
    float trai, phai;
    virtual bool thoaman(int i) const {
        return (i<=trai && i>phai);
    };
    public:
    ManglocTrongKhoang(float l, float r){
        khoitao("Mang loc Ngoai Khoang");
        trai = l;
        phai = r;
    
    }
    void hienthi() const{
        MangLoc :: hienthi();
        cout << trai << " " << phai << endl;
    }
};

int main(){
    int n = 5;       
    MangLoc *a[] = {new MangLocBoi(3), new MangLocBoi(20),
                    new MangLocBoi(4), new ManglocTrongKhoang(30, 50),
                    new ManglocTrongKhoang(6, 10)};
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