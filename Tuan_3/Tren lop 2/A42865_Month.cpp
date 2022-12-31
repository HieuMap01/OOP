/*2. Month:
Thiết kế một lớp Month gồm các thành viên sau:
• name: Một chuỗi chứa tên của một tháng, như là “January”, “February”,...
• monthNumber: Một biến số nguyên chứa số đại diện cho tháng. Ví dụ, January là số 1,
February là số 2,.. Các giá trị hợp lệ cho biến này là từ 1 đến 12.
• Hàm tạo mặc định để đặt monthNumber bằng 1 và name bằng “January”.
• Hàm tạo nhận vào tên của tháng như đối số. Nó sẽ đặt cho biến name giá trị được
truyền vào và tính toán đặt biến monthNumber giá trị phù hợp.
• Hàm tạo nhận vào một số của tháng như đối số. Nó sẽ đặt cho biến monthNumber giá
trị truyền vào và tính toán đặt biến name giá trị phù hợp.
• Các hàm set và get thích hợp cho các biến name và monthNumber.
• Toán tử ++ tiền tố và hậu tố để tăng số tháng lên 1 và cập nhật tên tháng tương ứng.
Nếu monthNumber đang là 12 thì khi cộng 1, monthNumber sẽ là 1, và name sẽ là
“January”.
• Toán tử -- tiền tố và hậu tố để tăng số tháng lên 1 và cập nhật tên tháng tương ứng. Nếu
monthNumber đang là 1 thì khi trừ 1, monthNumber sẽ là 12, và name sẽ là
“December”.
• Toán tử << để in ra thông tin một đối tượng Month và toán tử >> để vớt từ dòng nhập
thông tin gán cho các biến của Month.
Viết chương trình demo các hàm thành viên trên.
*/

#include <iostream>
#include <cstdlib>
#include <iomanip>
using namespace std;

class Month{
    private:
        string name;
        int monthNumber;
    public:
        Month(){
            name = "January";
            monthNumber = 1;
        }
        Month(string monthName) {setName(monthName);}
        Month(int num) {setMonthNumber(num);}
        void setName(string n){
            name = n;
            if(n == "January") monthNumber = 1;
            else if(n == "February") monthNumber = 2;
            else if(n == "March") monthNumber = 3;
            else if(n == "April") monthNumber = 4;
            else if(n == "May") monthNumber = 5;
            else if(n == "June") monthNumber = 6;
            else if(n == "July") monthNumber = 7;
            else if(n == "August") monthNumber = 8;
            else if(n == "September") monthNumber = 9;
            else if(n == "October") monthNumber = 10;
            else if(n == "November") monthNumber = 11;
            else if(n == "December") monthNumber = 12;
        }
        void setMonthNumber(int m){
            monthNumber = m;
            switch(monthNumber)
            {
            case 1: name = "January"; break;
            case 2: name = "February"; break;
            case 3: name = "March"; break;
            case 4: name = "April"; break;
            case 5: name = "May"; break;
            case 6: name = "June"; break;
            case 7: name = "July"; break;
            case 8: name = "August"; break;
            case 9: name = "September"; break;
            case 10: name = "October"; break;
            case 11: name = "November"; break;
            case 12: name = "December"; break;
            }
        }
        string getName() const {return name;}
        int getMonthNumber() const {return monthNumber;}
        Month & operator++(){ // Toan tu ++ dang tien to.
            Month temp(monthNumber);
            monthNumber++;
            if(monthNumber == 13) monthNumber = 1;
            temp.setMonthNumber(monthNumber);
            name = temp.getName();
            return *this;
        }
        Month & operator++ (int){ //Toan tu ++ dang hau to.
            Month temp = *this;
            monthNumber++;
            if(monthNumber == 13) monthNumber = 1;
            temp.setMonthNumber(monthNumber);
            name = temp.getName();
            return temp;
        }
        Month & operator--(){ // Toan tu -- dang tien to.
            Month temp(monthNumber);
            monthNumber--;
            if(monthNumber == 0) monthNumber = 12;
            temp.setMonthNumber(monthNumber);
            name = temp.getName();
            return *this;
        }
        Month & operator-- (int){ //Toan tu -- dang hau to.
            Month temp = *this;
            monthNumber--;
            if(monthNumber == 0) monthNumber = 12;
            temp.setMonthNumber(monthNumber);
            name = temp.getName();
            return temp;
        }
        friend istream & operator >> (istream & fin, Month & r){
            int x;
            cout << "Enter the month number: ";
            fin >> x;
            r.setMonthNumber(x);
            return fin;
        }
        friend ostream & operator << (ostream & fout, Month & r){
            fout << r.getMonthNumber() << "  -  " << r.getName() << endl;
            return fout;
        }
};  
int main(){
    Month m("October");
    cout << m.getMonthNumber() << "  " << m.getName() << endl;

    m.setName("July");
    cout << m.getMonthNumber() << "  " << m.getName() << endl;

    m.setMonthNumber(8);
    cout << m.getMonthNumber() << "  " << m.getName() << endl;

    Month m1("December"), m2("September"), m3("January"), m4("May");

    // cout << (++m1).getMonthNumber() << "  " << m1.getName() << endl;
    cout << (m2++).getMonthNumber() << "  " << m2.getName() << endl;

    // cout << (--m3).getMonthNumber() << "  " << m3.getName() << endl;
    cout << (m4--).getMonthNumber() << "  " << m4.getName() << endl;

}