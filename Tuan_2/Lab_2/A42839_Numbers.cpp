/*
2.Numbers 
Viết lớp Numbers giúp chuyển các số từ 0 cho đến 9999 thành dạng chuỗi tiếng Anh. 
Ví dụ, số 713 sẽ được chuyển thành một chuỗi “seven hundred thirteen” 
hay số 8203 sẽ được chuyển thành “eight thousand two hundred three”. 
Lớp gồm các thành viên: 
    - một biến number kiểu nguyên:
    - một mảng tĩnh các string lưu các chuỗi sẽ giúp tạo thành chuỗi kết quả. 
        + Ví dụ, có thể dùng các chuỗi tĩnh sau:
        string lessThan20[20] = {“zero”, “one”, ...., “eighteen”, “nineteen”}; 
        string hundred = “hundred”;
        string thousand = “thousand”;
    - hàm tạo nhận vào một số nguyên không âm để khởi tạo biến number.
    - hàm print() in ra dạng chuỗi tiếng Anh của biến number. 
Demo lớp bằng cách viết hàm main nhập vào một số không âm,sau đó in ra số đó ở dạngchữ.
*/
#include<iostream>
using namespace std;

class Numbers{
    int Number;
    static string lessThan20[20];
    static string hundred ;
    static string thousand;
    public:
        void setNumber(int N){
            Number = N;
        }
        // void setHundred(string hundred = "hundred"){
        //     hundred = hundred;
        // }
        // void setThousand(string thousand = "thousand"){
        //     thousand = thousand;
        // }
        int getNumber(){
            return Number;
        }
        string getHundred(){
            return hundred;
        }
        string getThousand(){
            return thousand;
        }

        //0 = Zero, 1 = One, 2 = Two, 3 = Three, 4 = Four, 5 = Five, 6 = Six, 7 = Seven, 8 = Eight, 
        //9 = Nine, 10 = Ten, 11 = Eleven, 12 = Twelve, 13 = Thirteen, 14 = Fourteen, 15 = Fifteen,
        //16 = Sixteen, 17 = Seventeen, 18 = Eighteen, 19 = Nineteen, 20 = Twenty.
        string getlessThan20(int a)
        {
            string Number_string[20] = {
                "zero",
                "one",
                "two",
                "three",
                "four",
                "five",
                "six",
                "seven",
                "eight",
                "nine",
                "ten",
                "eleven",
                "twelve",
                "thirteen",
                "fourteen",
                "fifteen",
                "sixteen",
                "seventeen",
                "eighteen",
                "nineteen",
            };
            return Number_string[a];
        }
        string getNumber(int a)
        {
            string Number_string[8] = {
                "twenty",
                "thirty",
                "forty",
                "fifty",
                "sixty",
                "seventy",
                "eighty",
                "ninety",
            };
            return Number_string[a-2];
        }
        void print(){
            if(Number == 0) cout << getlessThan20(Number);

            if ((Number / 1000) != 0)
            { 
                cout << getlessThan20(Number / 1000) << " " <<getThousand() << " ";
            }
            Number -= (Number / 1000) * 1000;
            if ((Number / 100) != 0)
            {
                cout << getlessThan20(Number / 100) << " " << getHundred() << " ";
            }
            Number -= (Number / 100) * 100;
            if (Number < 100 && Number > 20)
            {   
                int c = Number / 10 ;
                cout << getNumber(c);
                Number -= (Number / 10) * 10;
                if(Number!=0){
                    cout << " - " << getlessThan20(Number);
                    Number -= Number;
                }
                
            }
            if(Number < 20 && Number > 0)
            {
                cout << getlessThan20(Number);
            }
        }
};
string Numbers :: lessThan20[20];
string Numbers :: hundred = "hundred";
string Numbers :: thousand = "thousand";

int main(){
    Numbers N;
    int Number;
    do
    {
        cout << "Nhap so muon chuyen sang tieng Anh[0-9999]: "; cin >> Number;
    }
    while(Number < 0 || Number > 9999);
    N.setNumber(Number);
    cout << N.getNumber() << " : ";
    N.print();
    
    return 0;
}