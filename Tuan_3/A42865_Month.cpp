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
    void setName(string name){
        string n[] = {"January", "February", "March", "April", "May", "June", "July", "August", "September", "October", "November", "December"};
        this -> name = n[0];
        monthNumber = 1;
        for (int i = 0; i < 12; i++){
            if (name == n[i]){
                this -> name = n[i];
                monthNumber = i + 1;
                break;
            }
        }
    }
    void setMonthNumber(int m){
        string n[] = {"January", "February", "March", "April", "May", "June", "July", "August", "September", "October", "November", "December"};
        if(m < 1 || m > 12){
            monthNumber = 1;
            name = n[0];
        }
        else{
            monthNumber = m;
            name = n[m - 1];
        }
    }
    string getName() const {return name;}
    int getMonthNumber() const {return monthNumber;}
    Month & operator++(){
        ++monthNumber;
        if(monthNumber == 13){
            monthNumber = 1;
            name = "January";
        }
        setName(name);
        return *this;
    }
    Month operator++ (int){
        Month temp = *this;
        monthNumber++;
        if(monthNumber == 13){
            monthNumber = 1;
            name = "January";
        }
        setName(name);
        return temp;
    }
    Month & operator--(){
        --monthNumber;
        if(monthNumber == 0){
            monthNumber = 12;
            name = "December";
        }
        setName(name);
        return *this;
    }
    Month operator-- (int){
        Month temp = *this;
        monthNumber++;
        if(monthNumber == 0){
            monthNumber = 12;
            name = "December";
        }
        setName(name);
        return temp;
    }
    friend istream & operator >> (istream & fin, Month & r){
        int x;
        cout << "Enter the month number(1 - 12): ";
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
    cout << "---------------------------------------------" << endl;
    Month m1("December"), m2("September"), m3("January"), m4("May");
    cout << "Demo toan tu ++, -- dang tien to va hau to.\n";
    cout << (++m1).getMonthNumber() << "  " << m1.getName() << endl;
    cout << (m2++).getMonthNumber() << "  " << m2.getName() << endl;

    cout << (--m3).getMonthNumber() << "  " << m3.getName() << endl;
    cout << (m4--).getMonthNumber() << "  " << m4.getName() << endl;
    cout << (--m2).getMonthNumber() << "  " << m2.getName() << endl;

    Month m5;
    cin >> m5;
    cout << m5;
}