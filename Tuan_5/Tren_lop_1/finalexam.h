
#ifndef FINALEXAM_H
#define FINALEXAM_H
#include "gradedactivity.h"


class FinalExam : public GradedActivity 
{
    int numQuestion;       // tổng số câu đề thi
    int numMissed;         // tổng số câu sai
    
    void setScore() { 
        // tính điểm rồi đặt cho biến score lớp cha
        double tmp = 100 - (numMissed * 100.0/numQuestion); 
        GradedActivity::setScore(tmp); 
    }
public:
    void setInfor(int question, int missed){
        numQuestion = question;
        numMissed = missed;
        setScore(); 
    } 

    FinalExam(int question = 0, int missed = 0)
    { setInfor(question, missed); } 
 
    double getNumQuestion() const { return numQuestion; }
    int getNumMissed() const { return numMissed; }
};

#endif


// #ifndef FINALEXAM_H
// #define FINALEXAM_H
// #include "gradeactivity.h"


// class FinalExam : public GradedActivity  // kế thừa GradeActivity
// {
// private:
//     int numQuestion;       // số câu hỏi
//     double pointEach;      // điểm cho từng câu hỏi
//     int numMissed;         // số câu trả lời sai
// public:
//     FinalExam()
//     : numQuestion(0), pointEach(0), numMissed(0){}

//     FinalExam(int question, int missed)
//     : numQuestion(question), numMissed(missed)
//     { set(question, missed); } 

//     void set(int question, int missed){
//         numQuestion = question;
//         pointEach = 100.0 / question; 
//         numMissed = missed;
//         double numericScore = 100.0 - (missed * pointEach); // điểm thi
//         setScore(numericScore); 
//     }     
//     double getNumQuestion() const{ return numQuestion; }
//     double getPointEach() const { return pointEach; }
//     int getNumMissed() const { return numMissed; }
// };

// #endif
