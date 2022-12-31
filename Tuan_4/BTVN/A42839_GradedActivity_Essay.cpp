/* 4
Cho lớp GradedActivity mô tả một bài tập chấm điểm gồm các thành viên sau:  
•	biến score chỉ điểm số của bài tập (điểm trong khoảng [0,100] 
•	(các) hàm tạo để khởi tạo score 
•	setter getter cho biến score  
•	hàm trả về điểm chữ tương ứng điểm số (A,B,C,D,F)  
Viết lớp Essay (tiểu luận) kế thừa lớp  trên, cần có hàm cho biết điểm số mà sinh viên nhận được 
biết thang điểm của tiểu luận là 0 đến 100 và được chia thành 4 mục như sau: 
•	Ngữ pháp: tối đa 30 điểm 
•	Chính tả: tối đa 20 điểm 
•	Độ dài: tối đa 20 điểm 
•	Nội dung: tối đa 30 điểm 
Tự phân tích lớp Essay cần có các thành viên biến, hàm nào, sau đó cài đặt lớp rồi demo 
Gợi ý: Học tập cách viết các lớp kế thừa GradedActivity đã học tại lớp, 
tại đó biến score của lớp GradedActivity luôn được tính từ một/vài biến thành viên của lớp con.  
*/

#include<iostream>
#include<fstream>
using namespace std;

class GradedActivity {
    double score; 
    public:
        GradedActivity() { score = 0.0; }
        GradedActivity(double s){ score = s; }
        void setScore(double s) { score = s; }
        double getScore() const{ return score; }
        char getLetterGrade() const{char letterGrade;
            if(score > 89) letterGrade = 'A';
            else if(score > 79) letterGrade = 'B';
            else if(score > 69) letterGrade = 'C';
            else if(score > 59) letterGrade = 'D';
            else letterGrade = 'F';
            return letterGrade; 
        }      
};
/*
Viết lớp Essay (tiểu luận) kế thừa lớp  trên, cần có hàm cho biết điểm số mà sinh viên nhận được
biết thang điểm của tiểu luận là 0 đến 100 và được chia thành 4 mục như sau: 
•	Ngữ pháp: tối đa 30 điểm 
•	Chính tả: tối đa 20 điểm 
•	Độ dài: tối đa 20 điểm 
•	Nội dung: tối đa 30 điểm 
Tự phân tích lớp Essay cần có các thành viên biến, hàm nào, sau đó cài đặt lớp rồi demo 
Gợi ý: Học tập cách viết các lớp kế thừa GradedActivity đã học tại lớp, 
tại đó biến score của lớp GradedActivity luôn được tính từ một/vài biến thành viên của lớp con.  
*/

class Essay: public GradedActivity{
    double NP, CT, DD, ND;
    public:
        Essay(){};
        Essay(double n = 0,double c = 0,double d = 0,double nd = 0){
            setInfor(n,c,d,nd);
        }
        double checkNP(double np) const {
            if(np < 0 || np > 30) throw "Diem NP khong hop le ....!\n";
            return np;
        }
        double checkCT(double ct) const {
            if(ct < 0 || ct > 20) throw "Diem CT khong hop le ....!\n";
            return ct;
        }
        double checkDD(double dd) const {
            if(dd < 0 || dd > 20) throw "Diem DD khong hop le ....!\n";
            return dd;
        }
        double checkND(double nd) const {
            if(nd < 0 || nd > 30) throw "Diem ND khong hop le ....!\n";
            return nd;
        }
        void setInfor(double n,double c,double d,double nd){
            NP = checkNP(n);
            CT = checkCT(c);
            DD = checkDD(d);
            ND = checkND(nd);
            GradedActivity :: setScore(NP + CT + DD +ND);
        }
        double getNP() const { return NP;}
        double getCT() const { return CT;}
        double getDD() const { return DD;}
        double getND() const { return ND;}
        void print()const{
            cout << endl;
            cout << "Diem Ngu phap: " << NP<< endl;
            cout << "Diem Chinh Ta: " << CT<< endl;
            cout << "Diem Do Dai: " << DD<< endl;
            cout << "Diem Noi Dung: " << ND<< endl;
            cout << "Tong Diem: " << GradedActivity::getScore() << endl;
            cout << "Muc diem ma ban dat duoc la: " << GradedActivity::getLetterGrade() << endl;
        }
};

int main(){
    // double NP, CT, DD, ND;
    // do{
    //     cout << "Nhap diem Ngu Phap[0-30]: ";
    //     cin >> NP;
    // }
    // while(NP<0||NP>30);

    // do{
    //     cout << "Nhap diem Chinh ta[0-20]: ";
    //     cin >> CT;
    // }
    // while(CT<0||CT>20);

    // do{
    //     cout << "Nhap diem Do dai[0-20]: ";
    //     cin >> DD;
    // }
    //  while(DD<0||DD>20);

    // do{
    //     cout << "Nhap diem Noi dung[0-30]: ";
    //     cin >> ND;
    // }
    // while(ND<0||ND>30);
    // Essay E(NP,CT,DD,ND);
    // E.print();
    try{
        Essay e(30,20,19,25);
        e.print();
    }
    catch (const char* e){
        cout << e;
    }
    return 0;
}