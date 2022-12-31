/* 
3.FeetInches
Viết lớp FeetInches để lưu thông tin khoảng cách đo theo feet vàinches. 
Lớp gồm các thành viên: 
    - biến feet và inches là hai số nguyên. 
    - hàm tạo nhận 2 tham số để cập nhật các biến thành viên trên sau đó quy về dạng chuẩn 12 inches 
    đổi thành 1 feet. Ví dụ nếu nhận vào 3 feet 14 inchessẽ tạo đối tượng có thông tin 4 feet 2 inches, 
    nhập vào 5 feet -2 inches (âm hai inches) sẽ tạo ra đối tượng chứa 4 feet 10 inches. 
    - Các hàm nạp chồng toán tử sau: 
        + Toán tử 2 ngôi: phép +, =, +=, ==
        + Toán tử 1 ngôi: phép ++ kiểu tiền tố và kiểu hậu tố
Viết một chương trình đơn giản demo các khả năng trên. Khung mã gợi ý cho lớp FeetInches ở dưới đã có 
sẵn hàm tiện ích simplify() để chuẩn hoá feet vài nch, cũng sẵn cài đặt cho toán tử +, sinh viên cần 
tự viết thêm các toán tử còn lại.
*/

#ifndef FEETINCHES_H
#define FEETINCHES_H
class FeetInches {
    private:
        int feet;
        int inches;
        void simplify(); //sẽ được cài đặt trong FeetInches.cpp
        int *p;
    public:
        //hàm tạo 
        FeetInches() 
        { 
            feet = 0; 
            inches = 0; 
            simplify(); 
        }

        FeetInches(int i, int j) 
        { 
            feet = i; 
            inches = j; 
            simplify(); 
        }
        // ham tao sao chep
        // FeetInches
        FeetInches(FeetInches & n) 
        { 
            feet = n.feet; 
            inches = n.inches; 
            simplify(); 
        }
        //các setters
        void setFeet(int f) { 
            feet = f; 
        }
        void setInches(int i) { 
            inches = i; simplify(); 
        }
        //các getters
        int getFeet() const{ return feet; }
        int getInches() const{ return inches; }
        //các hàm nạp chồng toán tử 2 ngôi
        FeetInches operator+ (const FeetInches &); //nạp chồng toán tử + 
        FeetInches operator= (const FeetInches &); //nạp chồng toán tử =
        FeetInches operator+= (const FeetInches &); //nạp chồng toán tử += 
        bool operator== (const FeetInches &); //nạp chồng toán tử ==
        
        // các hàm nạp chồng toán tử 1 ngôi:
        FeetInches operator++ (); // kiểu tiền tố
        FeetInches operator++ (int); // kiểu hậu tố

        FeetInches operator*(const FeetInches & right);

};
#endif
