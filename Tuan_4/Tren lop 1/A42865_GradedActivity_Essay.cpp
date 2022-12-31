/*4. GradedActivity & Essay:
Cho lớp GradedActivity mô tả một bài tập chấm điểm gồm các thành viên sau:
• biến score chỉ điểm số của bài tập (điểm trong khoảng [0,100])
• (các) hàm tạo để khởi tạo score
• setter getter cho biến score
• hàm trả về điểm chữ tương ứng điểm số (A,B,C,D,F)
Viết lớp Essay (tiểu luận) kế thừa lớp trên, cần có hàm cho biết điểm số mà sinh viên nhận được
biết thang điểm của tiểu luận là 0 đến 100 và được chia thành 4 mục như sau:
• Ngữ pháp: tối đa 30 điểm
• Chính tả: tối đa 20 điểm
• Độ dài: tối đa 20 điểm
• Nội dung: tối đa 30 điểm
Tự phân tích lớp Essay cần có các thành viên biến, hàm nào, sau đó cài đặt lớp rồi demo
Gợi ý: Học tập cách viết các lớp kế thừa GradedActivity đã học tại lớp, tại đó biến score của lớp
GradedActivity luôn được tính từ một/vài biến thành viên của lớp con.
*/
#include <iostream>
using namespace std;
class GradedActivity{
    double score; 
    public:
        GradedActivity(double s = 0): score(s){}
        void setScore(double s) {score = s;}
        double getScore() const {return score;}
        char getLetterGrade() const {
            char letterGrade; 
            if (score > 89) letterGrade = 'A';
            else if (score > 79) letterGrade = 'B';
            else if (score > 69) letterGrade = 'C';
            else if (score > 59) letterGrade = 'D';
            else letterGrade = 'F';
            return letterGrade; 
        } 
};
class Essay: public GradedActivity{
    double grammar, spelling, length, content;
    double checkGrammar(double gramm) const {
        if(gramm < 0 || gramm > 30) throw "ERROR...Grammar Score invalid!\n";
        return gramm;
    }
    double checkSpelling(double spell) const {
        if(spell < 0 || spell > 20) throw "ERROR...Spelling Score invalid!\n";
        return spell;
    }
    double checkLength(double l) const {
        if(l < 0 || l > 20) throw "ERROR...Length Score invalid!\n";
        return l;
    }
    double checkContent(double cont) const {
        if(cont < 0 || cont > 30) throw "ERROR...Content Score invalid!\n";
        return cont;
    }
    
public:
    
    Essay(): grammar(0), spelling(0), length(0), content(0){}
    Essay(double gramm, double spell, double l, double cont){
        setScore(gramm, spell, l, cont);
    }
    
    void setScore(double gramm, double spell, double l, double cont){
        grammar = checkGrammar(gramm);
        spelling = checkSpelling(spell);
        length = checkLength(l);
        content = checkContent(cont);
        GradedActivity::setScore(gramm + spell + l + cont);
    }
    double getGrammarScore() const {return grammar;}
    double getSpellingScore() const {return spelling;}
    double getLengthScore() const {return length;}
    double getContentScore() const {return content;}
    void Print(){
        cout << "---------------------" << endl;
        cout << "Grammar : " << grammar << endl
             << "Spelling: " << spelling << endl
             << "Length  : " << length << endl
             << "Content : " << content << endl;
        cout << "---------------------" << endl;
        cout << "Total Score: " << getScore() << " --- " << getLetterGrade() << endl;
    }
};
int main(){
    try{
        Essay e(20,20,0,25);
        e.Print();
    }
    catch (const char* e){
        cout << e;
    }
    return 0;   
}