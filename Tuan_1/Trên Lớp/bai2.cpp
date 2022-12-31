// nsetInforcậpnhậtcảname, age, weightn3 getter choname, age, weightnmeow() in ra“Meow, I am ” + namenchaseMouse() nhậpvàosốchuộtcầnbắt, trảvềsốchuộtbắtđược, biết: qVớimỗichuột, sinhngẫunhiênsố0/1qNếura0 làkhôngbắtđượccon chuộtđó, ra1 làbắtđượcnĐịnhnghĩacáchàmsetInfor, getName, getAge, getWeighttronglớpnĐịnhnghĩacáchàmmeow, chaseMousengoàilớp

#include<iostream>
#include<time.h>
#include<stdlib.h>
using namespace std;

class cat{
    string name;
    int age;
    float weight;

    public:
    void setInfor(string n, int a, float w) {
        name = n;
        age = a;
        weight = w;
    }

    string getname() const {
        return name;
        }
    int getage() const{
        return age;
    }
    float getweight() const{
        return weight;
    }

    void meow();
    int chaseMouse(int) const; 
};
 
void cat::meow(){
    cout << "Meow, I am " << name;
}
int cat::chaseMouse(int n) const{
    srand(time(0));
    int tmp, cout = 0;
    for(int i=0; i<n; i++){
        tmp = rand()%2;
        if(tmp == 1) cout++;
    }
    return cout;
}
int main(){
    return 0;
}