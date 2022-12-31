#include<iostream>
using namespace std;

class FeetInches 
{
    int feet = 0;
    int inches = 0;
    void simplify(){ // hàm chuẩn hoá để inches luôn trong khoảng [0, 11] 
        if (inches >= 12)
        { 
            feet += inches / 12;
            inches %= 12;
        }
        else if (inches < 0)
        {
            feet -= abs(inches) / 12 + 1;
            inches = 12 - abs(inches) % 12;
        }
    }
    public:
    // chỉ setInches có khả năng phá hỏng sự toàn vẹn, nên cần gọi thêm simplify()
    void setFeet(int f) { feet = f; }
    void setInches(int i) { inches = i; simplify(); }
    void setAll (int f, int i) {
        feet = f; 
        inches = i; 
        simplify(); 
    }

    // nếu việc nhập dữ liệu từ ngoài cho biến đòi hỏi xử lý tinh vi thì
    // hàm tạo rất nên gọi setter; chỉ cần viết setter đúng đắn, hàm tạo sẽ đúng theo
    FeetInches(int f = 0, int i = 0) { 
        setAll(f, i); 
    }

    int getFeet() const { return feet; }
    int getInches() const { return inches; } 

    // nên viết thêm một hàm print() hoặc một toán tử xuất << (~ bài sau sẽ học) đ
    // để in ra thông tin sau này dễ test các toán tử: 
    void print()const { 
    cout << feet << " " << inches << endl; 
    }
    /*
    Viết toán tử > 
    toán tử - 2 FeetInches trả về một FEetInches 
    toán tử -- kiểu tiền tố 
    */
    FeetInches operator-(FeetInches & r){
        return FeetInches(feet - r.feet, inches - r.inches);
    }
    FeetInches & operator-- (){
        setAll(feet, inches - 1);
        return *this;
    }
    /*
    toán từ += một FeetInches với: 
    FeetInches 
    số nguyên, nghĩa tăng số inches lên số đó
    */
    FeetInches operator+= (int i){
        inches += i;
        return *this;
    }
};