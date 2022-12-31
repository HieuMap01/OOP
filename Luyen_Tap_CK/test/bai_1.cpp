/*- Xây dựng class BankAccount mô phỏng một tài khoản gửi tiền tiết kiệm với các thuộc tính và hàm như sau:
	+ Số tiền ban đầu (lớn hơn hoặc bằng không, kí hiệu là S)
	+ Thời hạn gửi tiền (tính theo năm và lớn hơn hoặc bằng không, kí hiệu là T)
	+ mức lãi suất hàng năm theo phần trăm (lớn hơn hoặc bằng không, kí hiệu là L)
	+ hàm in ra thông tin của tài khoản (ngoài 3 thông tin trên cần in thêm số tiền dự tính nhận được khi hết kì hạn). 
<Số tiền nhận được > = S x (1 + L / 100) ^ T;  ( ^ là kí hiệu phép lũy thừa)
- Tạo một hàm khởi tạo 3 tham số truyền vào 3 thuộc tính trên
- Quá tải toán tử cộng bằng (+=) giữa một đối tượng BankAccount và 1 số nguyên dương, sau khi thực hiện phép toán này thì 
thuộc tính số tiền ban đầu sẽ tăng thêm một khoảng bằng với số nguyên được cộng vào. Lưu ý cộng với số âm thì sẽ thành trừ, nhưng số tiền ban đầu sẽ chỉ giảm đến 0 là thấp nhất
*/
#include<iostream>
#include<math.h>
using namespace std;

class BankAccount{
    double S;
    int T;
    double L;
    public:
        void print() const{
            double tien = S*pow((1+L/100),T);
            cout << S << " " << T << " " << L << " " << tien << endl;
        }
        BankAccount(double s, int t, double l){
            if(s<0||t<0||l<0) throw "Loi.";
            S = s;
            T = t;
            L = l;
        }
        BankAccount & operator+= (int i){
            S += i;
            if(S<0) S = 0;
            return *this;
        }
};

/*- Xây dựng class DanSo mô phỏng dân số của một quốc giá với các thuộc tính và hàm như sau:
	+ Dân số hiện tại (lớn hơn hoặc bằng không, kí hiệu là D)
	+ Tỉ lệ sinh hàng năm (tính theo phần trăm, lớn hơn không. kí hiệu là S)
	+ Tỉ lệ tử hàng năm (tính theo phần trăm, lớn hơn không, kí hiệu là T)
	+ hàm in ra dân số của quốc gia đó sau n năm, với n là một số nguyên dương được truyền vào hàm. 
    Giả định dân số phải là một số nguyên và tối thiểu là không
	Công thức tính dân số sau n năm giả định là:
	Dân số = D x (1 + (S – T) / 100) ^ n;   ( ^ là kí hiệu phép lũy thừa)
- Tạo một hàm khởi tạo 3 tham số truyền vào 3 thuộc tính trên
- Quá tải toán tử cộng (+) giữa hai đối tượng DanSo, kết quả trả về sẽ là một đối tượng DanSo có :
	+ dân số hiện tại bằng tổng dân số hiện tại của 2 đối tượng tham gia phép cộng
	+ tỉ lệ sinh và tỉ lệ tử tính bằng cách lấy trung bình cộng tỉ lệ sinh và tỉ lệ tử của 2 đối tượng tham gia phép cộng.
*/

class Danso{
    int D;
    float S, T;
    public:
        void print(int n) const{
            cout << D * pow((1+(S-T)/100),n);
        }
        Danso(int d, float s, float t){
            if(d < 0 || s <= 0 || t <= 0) throw "loi";
            D = d;
            S = s;
            T = t;
        }
        Danso operator+(Danso r){
            return Danso(D + r.D, (S+r.S)/2, (T+r.T)/2);
        }
};

/*- Xây dựng class BaoHiem mô phỏng hoạt động bảo hiểm với các thuộc tính và hàm như sau:
	+ Mức phí bảo hiểm (kí hiệu là P)
	+ Tỉ lệ bồi thường (số thực lớn hơn 1, kí hiệu là B). Mức bồi thường bằng mức phí bảo hiểm nhân tỉ lệ này
	+ Tỉ lệ tai nạn xảy ra (tính theo phần trăm, kí hiệu là R), khi tai nạn xảy ra bảo hiểm mới phải bồi thường
	+ hàm in ra thông tin bảo hiểm gồm 3 thuộc tính trên và dự tính lợi nhuận trung bình của loại hợp đồng bảo hiểm này. Trong đó:
	Lợi nhuận trung bình = P x (1 – B x R / 100)
- Tạo một hàm khởi tạo 3 tham số truyền vào 3 thuộc tính trên
- (1 điểm) Quá tải toán tử so sánh bằng (==) giữa hai đối tượng BaoHiem, kết quả trả về true nếu lợi nhuận trung bình của đối tượng thứ nhất bằng lợi nhuận trung bình của đối tượng thứ hai, trả về false nếu ngược lại
*/

class BaoHiem{
    float P, B, R;
    float LoiNhuanTB()const {
        return P*(1-B*R/100);
    }
    public :
        void print() const{
            cout << P << " " << B << " " << R <<" "<< LoiNhuanTB() << endl;
        }
        BaoHiem(float p, float b, float r){
            if(b<=1) throw "loi";
            P = p;
            B = b;
            R = r;
        }
        bool operator== (BaoHiem r){
            return LoiNhuanTB() == r.LoiNhuanTB();
        }
};

class Car{
    string ten, bienso;
    int km;
    public: 
        void print(){
            int haomon = km/5000;
            if(haomon<1) haomon = 0;
            if(haomon>100) haomon = 100;
            cout << ten << " " << bienso << " " << km << " "<< haomon << "%"<< endl;
        }
        Car(string t, string b, int k){
            if(km<0) throw "Loi.";
            ten = t;
            bienso = b;
            km = k;
        }
        Car & operator+= (int a){
            km += a;
            if(km<0) km = 0;
            return *this;
        }
};

int main(){}