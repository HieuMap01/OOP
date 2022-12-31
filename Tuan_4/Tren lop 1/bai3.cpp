#include<iostream>
using namespace std;

class GradedActivity{
    private:
    double score;
    public:
        GradedActivity(double s = 0): score(s){}
        void setScore(double s){score = s;}
        double getScore() const { return score;}
        char DiemChu(){
            if(score > 90) return 'A';
            else if(score > 80) return 'B';
            else if(score > 70) return 'C';
            else if(score > 60) return 'D';
            else return 'F';
        }
};

class FinalExam: public GradedActivity{
    private:
    int so_cau;
    int cau_sai;
    public:
        FinalExam(int s, int c){
            so_cau = s;
            cau_sai = c;
        }
        void setSo_cau(int s){
            so_cau = s;
        }
        void setcau_sai(int c){
            cau_sai = c;
        }
        void diem(){
            double diem;
            diem = 100 / so_cau;
            setScore((100 - (diem*cau_sai)));
        }
        int getSo_cau() const{
            return so_cau;
        }
        int getCauSai() const{
            return cau_sai;
        }
};
int main(){
    FinalExam F(20,5);
    cout << F.getScore() << " " << F.DiemChu();
    return 0;
}