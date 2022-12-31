/*
Sinh viên có thể tự thêm các hàm, tự chọn danh sách tham số, tự đặt chế độ private protected public hợp lý 
để đảm bảo tính hướng đối tượng (chỉ trừ các thành viên đã nêu rõ private hay protected thì cần giữ nguyên)
Cho lớp trừu tượng Animal, gồm các thành viên sau: 
    •	Các thuộc tính private: cân nặng xuất chuồng, cân nặng hiện tại
    •	Hàm setInfor thiết lập giá trị cho mọi thuộc tính
    •	Hàm ảo thuần tuý Feed, thực hiện hành động cho Animal ăn, truyền vào tham số là loại thức ăn
Lớp Chicken kế thừa Animal, có: 
    •	Thuộc tính private: giống gà
    •	Hàm setInfor thiết lập giá trị cho mọi thuộc tính
    •	Override hàm Feed, biết gà chỉ ăn thóc: 
    o	nếu thực phẩm khác thóc thì in ra cảnh báo “Gà không ăn <giá_trị_truyền_vào>”
    o	nếu thực phẩm là thóc, thì in ra “Gà đã ăn no”, tăng cân nặng hiện tại của gà lên 1, 
    nếu cân nặng >=  mức xuất chuồng thì in ra “Cần cho gà xuất chuồng”
Lớp Cow kế thừa Animal, có: 
    •	Thuộc tính private: hệ số cân nặng
    •	Hàm setInfor thiết lập giá trị cho mọi thuộc tính
    •	Override hàm Feed, biết bò chỉ ăn cỏ: 
    o	nếu thực phẩm khác cỏ thì in ra cảnh báo “Bò không ăn <giá_trị_truyền_vào>”
    o	nếu thực phẩm là cỏ, thì in ra “Bò đã ăn no”, tăng cân nặng hiện tại của bò lên bằng hệ số cân nặng, 
    nếu cân nặng hiện tại lúc này >=  mức xuất chuồng thì in ra “Cần cho bò xuất chuồng”
Hàm main sẽ tạo một đàn 10 Animal có cả Chicken và Cow, sau cùng cho cả đàn ăn 3 lần. 

*/

#include <iostream>
using namespace std;

class Animal{
    double CanNang_XC, CanNang_HT;
    protected:
        void setInfor(double XC, double HT){
            CanNang_XC = XC;  
            CanNang_HT = HT;
        }
    public:
        //Animal(double XC = 0, double HT = 0){setInfor(XC,HT);}
        virtual string Feed() const = 0;
};
/*
Lớp Chicken kế thừa Animal, có: 
    •	Thuộc tính private: giống gà
    •	Hàm setInfor thiết lập giá trị cho mọi thuộc tính
    •	Override hàm Feed, biết gà chỉ ăn thóc: 
    o	nếu thực phẩm khác thóc thì in ra cảnh báo “Gà không ăn <giá_trị_truyền_vào>”
    o	nếu thực phẩm là thóc, thì in ra “Gà đã ăn no”, tăng cân nặng hiện tại của gà lên 1, 
    nếu cân nặng >=  mức xuất chuồng thì in ra “Cần cho gà xuất chuồng”
*/
class Chicken: public Animal{
    string giongga, thucan;
    string Feed()const override{
        if(thucan == "thoc") cout << "Ga an no" << endl;
        else cout << "Ga khong an " << thucan << endl;
    }
    public:
        Chicken(string g,string t, double XC, double HT){setInfor(g,t,XC,HT);}
        void setInfor(string g,string t, double XC, double HT){
            giongga = g;
            thucan = t;
            Animal::setInfor(XC,HT);
        }

};

int main(){
    Animal *a = new Chicken()

}