#include<iostream>
using namespace std;

class VienPhi{
    double CPtrongdienBH;
    double CPNgoaidienBH;
    double tile;
    public: 
        VienPhi(double in, double out, double tl){
            CPtrongdienBH = in;
            CPNgoaidienBH = out;
            tile = tl;
        }
        double vienphi() const {
            return (CPtrongdienBH + CPNgoaidienBH) - (CPtrongdienBH *tile/100.0);
        }
        void print() const{
            cout << CPtrongdienBH << " " << CPNgoaidienBH << " " << tile;
            cout << (CPtrongdienBH + CPNgoaidienBH) - (CPtrongdienBH *tile/100.0);
        }
        bool operator > (VienPhi r){
            return vienphi() > r.vienphi();
        }
};