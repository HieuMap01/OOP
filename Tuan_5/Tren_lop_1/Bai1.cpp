#include<iostream>
using namespace std;

class Time
{
protected:
    int hour;
    int min;
    int sec;
    public:
        Time(): hour(0), min(0), sec(0){}
        Time(int h, int m, int s): hour(h), min(m), sec(s){}
        int getHour() const{ return hour; }
        int getMin() const { return min; }
        int getSec() const { return sec; }
        void print() const{
        cout << hour << " " << min << " " << sec << endl;
        }
};

class MilTime: public Time{
    protected:
    int milHour, milSec;
    int checkMilHour(int mh) const{
        if(mh < 0 || mh > 2359) throw "Gio sai\n";
        return mh;
    }
    int checkMin(int m) const{
        if(m < 0 || m > 59) throw "Phut sai\n";
        return m;
    }
    int checkMilSec(int ms) const{
        if(ms < 0 || ms > 59) throw "Giay sai\n";
        return ms;
    }
    public:
    void setTime(int mh, int ms){
        milHour = checkMilHour(mh);
        milSec  = checkMilSec(ms);
        sec = milSec;
        min = checkMin(mh % 100);
        hour = mh / 100;
    }
    MilTime(int mh, int ms) {setTime(mh, ms);}
    int getHour() const {return milHour;}
    int getStandHr() const {return hour;}
    void Print() const {
        Time:: print();
        cout << milHour << " " << milSec << endl;
    }
};

int main(){   
    Time t1(12, 23, 12);
    t1.print();
    
    try{
        MilTime t2(1242, 71);
        t2.Print();
    }
    catch (const char* e){
        cout << e;
    }
    return 0;
}

/*
enum TG{
    AM = 1,
    PM
};

class Time12: public Time{
    int hour12;
    int period;
    void convert(){
        period == PM ? hour = hour12 + 12: hour = hour12;
    }
    public:
    Time12(){}
    Time12(int h, int m, int s, int p){
        setInfor(h,m,s,p);
    }
        void setInfor(int h, int m, int s, int p){
            hour12 = h;
            min = m;
            sec = s;
            period = p;
            convert();
        }
        int getHour12() const {return hour12;}
        int getPeriod() const {return period;}
        int getStan() const {return hour;}
        void print() const{
            Time :: print();
            cout << hour12 << " " << min << " " << sec << " " << period<< endl;
        }
};

int main(){
    Time12 T(13, 24, 32, PM);
    T.print();
    return 0;
}
*/