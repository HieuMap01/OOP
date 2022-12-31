/*1.DivSales
Một công ty có nhiều bộ phận bán hàng, mỗi bộ phận đóng ở vị trí địa lý khác nhau. 
Viết lớp DivSales lưu số liệu bán hàng của một bộ phận công ty. 
Lớp gồm các thành viên sau:
    - mảng 4 phần tử lưu số liệu bán hàng của bộ phận đó trong 4 quý 
    - biến static và private lưu tổng doanh số bán hàng của cả công ty và trong cả năm.
    - hàm nhận 4 đối số là số liệu bán hàng trong 4 quý và sẽ copy các giá trị này vào mảng số liệu bán hàng,
    sau đó cộng dồn 4 đối số này vào biến static lưu doanh số của cả công ty trong cả năm.
    - hàm nhận một đối số số nguyên nằm trong khoảng 0-3. Hàm sẽ trả về số liệu bán hàng của bộ 
    phận trong quý có chỉ số tương ứng. 
Giả sử công ty có 6 bộ phận. Viết chương trình tạo mảng 6 đối tượng DivSales.
Yêu cầu người dùng nhập doanh số bán hàng trong bốn quý cho mỗi bộ phận.
Sau đó, hiển thị một bảng thể hiện doanh số bán hàng của các bộ phận này 
theo các quý. Cuối cùng hiển thị tổng doanh số bán hàng cả năm của cả công ty.
    Xácthực đầu vào: Chỉ chấp nhận số liệu bán hàng dương
*/

#include<iostream>
#include<iomanip>
using namespace std;


class Divsales{
    //mảng 4 phần tử lưu số liệu bán hàng của bộ phận đó trong 4 quý 
    double a[4];
    //biến static và private lưu tổng doanh số bán hàng của cả công ty và trong cả năm.
    static double Tong_ds;
    public:
    //hàm nhận 4 đối số là số liệu bán hàng trong 4 quý và sẽ copy các giá trị này vào mảng số liệu bán hàng,
    //sau đó cộng dồn 4 đối số này vào biến static lưu doanh số của cả công ty trong cả năm.
        void setInfor(double q1, double q2, double q3, double q4){
            //Xácthực đầu vào: Chỉ chấp nhận số liệu bán hàng dương
            if(q1 < 0 || q2 < 0 || q3 < 0 || q4 < 0 ){
                cout << "So lieu khong hop le. \n";
                return;
            }
                a[0] = q1;
                a[1] = q2;
                a[2] = q3;
                a[3] = q4;
                for(int i = 0; i < 4; i++){
                    Tong_ds += a[i];
                }
            
        }

    //- hàm nhận một đối số số nguyên nằm trong khoảng 0-3. Hàm sẽ trả về số liệu bán hàng của bộ 
    //phận trong quý có chỉ số tương ứng.
        double getsale(int i){
            return a[i];
        }
        double getTong(){
            return Tong_ds;
        }
};

double Divsales :: Tong_ds = 0;
/*
Giả sử công ty có 6 bộ phận. Viết chương trình tạo mảng 6 đối tượng DivSales.
Yêu cầu người dùng nhập doanh số bán hàng trong bốn quý cho mỗi bộ phận.
Sau đó, hiển thị một bảng thể hiện doanh số bán hàng của các bộ phận này 
theo các quý. Cuối cùng hiển thị tổng doanh số bán hàng cả năm của cả công ty.
*/

void salesByDiv(Divsales d[])
{
   for (int div = 0; div < 6; div++)
   {
        cout << "Bo phan thu ";
        cout << (div + 1) << endl;
      for (int qtr = 0; qtr < 4; qtr++)
      {
        cout << "\tQuy " << (qtr + 1) << ": $";
        cout << d[div].getsale(qtr) << endl;
      }
   }
}

int main(){
    int so_bp = 6;
    int so_quy = 4;
    Divsales Part[so_bp];
    double quy[so_quy];
    for(int i = 0; i < so_bp; i++){
        cout << "Du lieu ban hang cho bo phan thu " << i+1 << ": " << endl;
        for(int q = 0; q < so_quy; q++){
            cout << "Quy " << q+1 << ": "; cin >> quy[q];
            while(quy[q] < 0){
                cout << "Nhap lai quy " << q+1 << ": "; cin >> quy[q];
            }
            Part[i].setInfor(quy[0], quy[1], quy[2], quy[3]);
        }
    }
    cout << fixed << showpoint << setprecision(2);
    salesByDiv(Part);
    cout << "\nTong doanh so ban hang cua ca cong ty: $" << Part[0].getTong() << endl;
    return 0;
}
