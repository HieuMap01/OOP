#include<iostream>
using namespace std;

class AndPropo;
class OrPropo;

class Propo{
    string sequence;
    bool value;
    public:
        Propo(){}
        Propo(string s = "P", bool v = true): sequence(s), value(v){}
        void setInfor(string s, bool v){
            sequence = s;
            value = v;
        }
        string getSequence(){ return sequence; }
        bool getValue(){ return value;}
        friend AndPropo & operator* (const Propo & r, Propo & l){
            

        }   
        friend OrPropo & operator+ (const Propo & r){
    
        }
};

class AndPropo: public Propo{
    Propo left, right;
    public:
        AndPropo(){}
        AndPropo(Propo l, Propo r){
            setInfor(l, r);
        }
        void setInfor(Propo l, Propo r){

        }
};