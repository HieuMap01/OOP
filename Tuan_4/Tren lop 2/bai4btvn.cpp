#include <iostream>
using namespace std;

class GradedActivity
{
private:
    double score;
public:
    GradedActivity(){score=0.0;}
    GradedActivity(double s){score=s;}
    void setScore(double s){score=s;}
    double getScore(){return score;}
    char getLetterGrade() const
    {
        char letterGrade;
        if (score > 89) letterGrade = 'A';
        else if (score > 79) letterGrade = 'B';
        else if (score > 69) letterGrade = 'C';
        else if (score > 59) letterGrade = 'D';
        else letterGrade = 'F';
        return letterGrade;
    }
};

class Essay: public GradedActivity
{
private:
    int nguphap;
    int chinhta;
    int dodai;
    int noidung;
public:
    Essay(){nguphap=0;chinhta=0;dodai=0;noidung=0;}
    Essay(int ng, int ch, int dod, int nd){nguphap=ng;chinhta=ch;dodai=dod;noidung=nd;}
    void setInfo(int ng, int ch, int dod, int nd){nguphap=ng;chinhta=ch;dodai=dod;noidung=nd;}
    int getNguphap(){if (nguphap>30) return 30;else return nguphap;}
    int getChinhta(){if (chinhta>20) return 20;else return chinhta;}
    int getDodai(){if (dodai>20) return 20;else return dodai;}
    int getNoidung(){if (noidung>30) return 30;else return noidung;}
    double getTotalScore()
    {
        double totalScore;
        totalScore = getNguphap()+getChinhta()+getDodai()+getNoidung();
        GradedActivity::setScore(totalScore);
        return totalScore;
    }
    
    void print()
    {
        cout<<"Ngu phap: "<<getNguphap()<<endl;
        cout<<"Chinh ta: "<<getChinhta()<<endl;
        cout<<"Do dai: "<<getDodai()<<endl;
        cout<<"Noi dung: "<<getNoidung()<<endl;
        cout<<"Diem tong: "<<getTotalScore()<<endl;
        cout<<"Diem chu: "<<getLetterGrade()<<endl;
    }
};
int main()
{
    Essay e;
    e.setInfo(30,20,40,90);
    e.print();
    return 0;
}



