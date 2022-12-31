#include<iostream>
using namespace std;

class GradedActivity {
    double score; 
    public:
        GradedActivity(double s = 0): score(s) {}
        void setScore(double s) { score = s; }
        double getScore() const { return score; }
        char getLetterGrade() const
        {
            char letterGrade; // 
            if (score > 90) letterGrade = 'A';
            else if (score > 80) letterGrade = 'B';
            else if (score > 70) letterGrade = 'C';
            else if (score > 60) letterGrade = 'D';
            else letterGrade = 'F';
            return letterGrade; 
        } 
};

class CurveActivity: public GradedActivity{
    double rawScore;
    double rate;
    public:
    CurveActivity(double s, double r): GradedActivity(s), rawScore(s), rate(r){getScore(s);}
        void setrate(double r){
            rate = r;
        }
        void setScore(double s){
            rawScore = s;
           GradedActivity::setScore(rawScore * rate) ;
        }
        int getRawscore() const {
            return rawScore;
        }
        double getRate() const {
            return rate;
        }
    
};

int main(){
    GradedActivity G(8);
    cout << G.getScore() << endl;
    CurveActivity C(8, 1.1);
    cout << G.getScore();
}