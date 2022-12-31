/*
3.Trivia Game
Trong thử thách lập trình này, bạn sẽ tạo một trò chơi đố đơn giản cho hai người chơi. 
Chương trình sẽ hoạt động như sau:
Mỗi người chơi cần trả lời liên tiếp năm câu hỏi, tổng cộng 2 người trả lời 10 câu hỏi.
Mỗi lần hỏi, chương trình sẽ hiển thị một câu đố kèm 4 đáp án đểchọn, người chơi nhập lựa chọn, 
chương trình hiển thị câu đố tiếp theo. Người 1chơi xong thì đến lượt người 2.
Mỗi câu hỏi chỉ có 1 đáp án đúng. Mỗi lần chọnđúng đáp án thì người chơi được 1 điểm.
Sau khi 2 người chơi xong, chương trình sẽ hiển thị số điểm mà mỗi người chơi kiếm được và 
tuyên bố người thắngtrò chơi.Để cài đặt trò chơi này, hãy thiết kếmột lớp Question chứa dữ liệu 
cho một câu hỏi đố.Lớp Question cần có các biến thành viên sau: q
Một câu hỏi đố
Câu trả lời 1
Câu trảlời 2
Câu trảlời 3
Câu trảlời 4
Số câu trả lời đúng (1, 2, 3 hoặc 4)
Lớp Question cũng cần có hàm tạo và settergetter (sinh viên tự lựa chọn kiểu và số lượng)
*/

#include <iostream>
#include <fstream>
using namespace std;
class Question{
    string questions;
    string answer[4];
    int CorrectNum;
public:
    void setQuestions(string q) {questions = q;}
    void setAnswer1(string ans) {answer[0] = ans;}
    void setAnswer2(string ans) {answer[1] = ans;}
    void setAnswer3(string ans) {answer[2] = ans;}
    void setAnswer4(string ans) {answer[3] = ans;}
    void setCorrectAns(int Correct) {CorrectNum= Correct;}
    string getQuestion() const {return questions;}
    string getAnswer1() const {return answer[0];}
    string getAnswer2() const {return answer[1];}
    string getAnswer3() const {return answer[2];}
    string getAnswer4() const {return answer[3];}
    int getCorrectAns() const {return CorrectNum;}
};
void displayQuestion(Question q){
    cout << q.getQuestion() << endl;
    cout << "ANSWERS: \n";
    cout << q.getAnswer1() << endl
         << q.getAnswer2() << endl
         << q.getAnswer3() << endl
         << q.getAnswer4() << endl;
}
int main(){
    const int NUM_QUESTS = 5;
    int count = 0;
    int Choice_1, Choice_2;
    int Point1 = 0, Point2 = 0;
    Question q[NUM_QUESTS];
    //Question 1:
    q[0].setQuestions("Truong Dai hoc Thang Long duoc thanh lap vao nam nao?");
        q[0].setAnswer1("1. 1978");
        q[0].setAnswer2("2. 1988");
        q[0].setAnswer3("3. 2008");
        q[0].setAnswer4("4. 1980");
        q[0].setCorrectAns(2);
    //Question 2:
    q[1].setQuestions("What is the PI number?");
		q[1].setAnswer1("1. 3.14159");
		q[1].setAnswer2("2. 3.18");
		q[1].setAnswer3("3. 3.15149");
		q[1].setAnswer4("4. 2");
		q[1].setCorrectAns(1);
    //Question 3:
    q[2].setQuestions("What is OOP?");
        q[2].setAnswer1("1. Object Oriented Programming");
        q[2].setAnswer2("2. Oriented Object Programming");
        q[2].setAnswer3("3. Both are Correct");
        q[2].setAnswer4("4. Both are Incorrect");
        q[2].setCorrectAns(1);
        //Question 4:
    q[3].setQuestions("To bao mo đau cho dong bao chi cach mang VN?");
        q[3].setAnswer1("1. A. Người cùng khổ");
        q[3].setAnswer2("2. Nhan Dao");
        q[3].setAnswer3("3. Thanh niên");
        q[3].setAnswer4("4. Đoi song cong nhan");
        q[3].setCorrectAns(3);
        //Question 5:
    q[4].setQuestions("Nam 1929, o Viet Nam ra doi may to chuc cong san?");
        q[4].setAnswer1("1. 1");
        q[4].setAnswer2("2. 2");
        q[4].setAnswer3("3. 3");
        q[4].setAnswer4("4. 4");
        q[4].setCorrectAns(1);
    while(count < NUM_QUESTS){
        cout << "QUESTION " << count + 1 << ":\n";
        displayQuestion(q[count]);
        cout << "Enter the correct answer: \n";
        cout << "Player 1's answer: "; cin >> Choice_1;
        cout << "Player 2's answer: "; cin >> Choice_2;
        if(q[count].getCorrectAns() == Choice_1) Point1++;
        if(q[count].getCorrectAns() == Choice_2) Point2++;
        count++;
        cout << endl;
    }

    cout << "Diem cua 2 nguoi choi la: \n";
    cout << "Player 1: " << Point1 << endl
         << "Player 2: " << Point2 << endl;
    if(Point1 == Point2) cout << "It's a tie!!" << endl;
    if(Point1 > Point2) cout << "Player 1 is winner!!" << endl;
    if(Point1 < Point2) cout << "Player 2 is winner!!" << endl;
    return 0;
}
