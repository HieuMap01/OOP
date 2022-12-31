#include<iostream>
#include<math.h>
using namespace std;

class Danso{
    int ds_ht;
    double tile_S;
    double tile_T;
    double check(double i){
        if(i<0) throw "Loi";
        return i;
    }
    public:
    Danso(int d, double s, double t){
        if(d<0) throw "loi";
        ds_ht = check(d);
        tile_S = check(s);
        tile_T = check(t);
    }
    void print(int n) const{
        int tmp = ds_ht*pow(1+(tile_S - tile_T)/100,n);
        if(tmp<0)tmp = 0;
        cout << tmp;
    }
    Danso operator+(Danso d){
        return Danso(ds_ht+d.ds_ht, (tile_S + d.tile_S)/2, (tile_T + d.tile_T)/2);   
    }
};