/*Viết chương trình có cấu trúc CourseGrade gồm các thành viên sau:
    Tên thành viên      Mô tả 
    name                Tên học sinh
    id                  Số ID sinh viên 
    tests               Con trỏ đến một mảng các điểm kiểm tra 
    average             Điểm trung bình dạng số của các bài kiểm tra 
    grade               Điểm dạng chữ -sẽ coi là điểm khoá học
Main sẽ tạo ra một danh sách các điểm kiểm tra cho một nhóm học sinh bằng cách đầu tiên hỏi có bao nhiêu học sinh 
và có bao nhiêu điểm kiểm tra cho mỗi học sinh, rồi từ đó cấp phát động một mảng các biến strucr, 
mỗi phần tử dành cho một học sinh. Trong mỗi phần tử này, thành viên tests lại trỏ đến một mảng cấp phát động chứa các điểm của học sinh đó. 
Sau khi các mảng đều đã được cấp phát, chương trình sẽ lần lượt hỏi thông tin của từng học sinh: id, tên, và các điểm kiểm tra. 
Tiếp đó, điểm kiểm tra trung bình được tính toán để lưu vào thành viên average của cấu trúc. Từ thành viên average lại tính ra thành viên 
grade theo cách sau:
    Điểm bài kiểm tra trung bình    Điểm khóa học
    91–100                          A
    81–90                           B
    71–80                           C
    61–70                           D 
    60 trở xuống                    F
Sau khi tất cả dữ liệu trên đã được nhập hoặc tính toán, chương trình sẽ hiển thị thông tin của tất cả sinh viên gồm : 
tên, số ID sinh viên, điểm kiểm tra trung bình và điểm của từng sinh viên.
Xác thực đầu vào:Đảm bảo mọi dữ liệu của mỗi sinh viên đều được nhập. Không chấp nhận điểm thi âm.
(Chỉ cần dùng kiểm tra do ... while thông thường ở hàm main, không cần dùng ngoại lệ. )
*/

#include<iostream>
using namespace std;
struct Course_Grade{
    string name;
    string ID;
    double *tests;
    double average;
    char grade;
    void setAverage(int size){
        double sum;
        for(int i = 0; i<size; i++) sum += tests[i];
        average=sum/size;
    }
    void setGrade(){
        if(average>90) grade = 'A';
        else if(average>80) grade ='B';
        else if(average>70) grade = 'C';
        else if(average>60) grade ='D';
        else grade ='F';
    }
    void print()const{
        cout << "Ten HS: "<< name << endl
             << "Diem TB: "<< average << endl << "Diem khoa hoc: "<< grade <<endl;
    }
};
int main(){ 
    int So_HS, So_diemKT;
    cout<<"Nhap so luong hoc sinh: "; cin >> So_HS;
    cout<<"Nhap so luong diem kiem tra: "; cin >> So_diemKT;
    Course_Grade *C = new Course_Grade[ So_HS ];
    for(int i = 0; i < So_HS; i++){
        cout<<"STT: "<< i+1 <<endl;
        cin.ignore();
        cout << "Nhap ten: "; getline(cin,C[i].name);
        cout << "Nhap ID: "; cin >> C[i].ID;
        C[i].tests= new double[So_diemKT];

        for(int j = 0; j < So_diemKT; j++){
            do{
                cout<<"Nhap diem thu " << j+1 << ": ";
                cin>>C[i].tests[j];
            }
            while(C[i].tests[j]<0);
            C[i].setAverage(So_diemKT);
        }
        C[i].setGrade();
    }
    for(int i = 0; i<So_HS; i++){ 
        C[i].print();
    }
    return 0;
}