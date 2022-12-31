/*
2.Number Array (động)
Thiết kế một lớp có các thành viên: 
Một  mảng số thực cấp phát động.
Một hàm tạo nhận một tham số nguyên dù nglàm kích thước cấp phát động mảng.
Hàm huỷ giải phóng bộ nhớ mảng. 
Hàm thiết lập giá trị cho phần tử mảng ở vị trí cho trước
Hàm trả về giá trị phần tử mảng ở vị trí cho trước
Hàm trả về giá trị lớn nhất mảng 
Hàm trả về giá trị nhỏ nhất mảng 
Biểu diễn lớp trên trong một chương trình.
*/

#include<iostream>
using namespace std;

class Number_Array{
    int size;
    double * a;
    public:
        Number_Array(int size = 50): size(size), a(new double [size]){}
        ~Number_Array() { delete [] a; }
        //Hàm thiết lập giá trị cho phần tử mảng ở vị trí cho trước
        void setElement (double e, int i){ a[i] = e;}
        //Hàm trả về giá trị phần tử mảng ở vị trí cho trước
        double getElement(int i) const {return a[i];}
        //Hàm trả về giá trị lớn nhất mảng 
        double getmax(float n) const {
            int max = a[0];
            for(int i = 0; i < n; i++){
                if(a[i] > max) max = a[i];
            }
            return max;
        }
        //Hàm trả về giá trị nhỏ nhất mảng 
        double getmin(float n) const {
            int min = a[0];
            for(int i = 0; i < n; i++){
                if(a[i] < min) min = a[i];
            }
            return min;
        }
};

int main(){
        const int n = 5;
    Number_Array a(n);
    a.setElement(20,0);
    a.setElement(10,1);
    a.setElement(39,2);
    a.setElement(37,3);
    a.setElement(60,4);
    cout << "Gia tri cua mang o vi tri thu 3 la: " << a.getElement(3) << endl;
    cout << "Gia tri lon nhat: " << a.getmax(n) << endl;
    cout << "Gia tri nho nhat: " << a.getmin(n) << endl; 
    return 0;
}
