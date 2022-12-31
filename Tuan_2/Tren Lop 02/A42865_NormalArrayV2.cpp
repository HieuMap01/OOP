/*2. Number Array (động):
Thiết kế một lớp có các thành viên:
- Một mảng số thực cấp phát động.
- Một hàm tạo nhận một tham số nguyên dùng làm kích thước cấp phát động mảng.
- Hàm huỷ giải phóng bộ nhớ mảng.
- Hàm thiết lập giá trị cho phần tử mảng ở vị trí cho trước.
- Hàm trả về giá trị phần tử mảng ở vị trí cho trước.
- Hàm trả về giá trị lớn nhất mảng.
- Hàm trả về giá trị nhỏ nhất mảng.
Biểu diễn lớp trên trong một chương trình.
*/

#include <iostream>
using namespace std;
class Array{
    float *a;
public:
    Array(int n){a = new float[n];}

    ~Array(){delete [] a;}
    
    void setNumbers(float num, int index) {a[index] = num;}
    float getNumberber(int index) {return a[index];}
    float findHighest(int n){
        int max = a[0];
        for(int i = 0; i< n; i++){
            if(a[i] > max) max = a[i];
        }
        return max;
    }
    float findLowest(int n){
        int min = a[0];
        for(int i = 0; i < n; i++){
            if(a[i] < min) min = a[i];
        }
        return min;
    }
};
int main(){
    const int n = 5;
    Array a(5);
    a.setNumbers(23,0);
    a.setNumbers(12,1);
    a.setNumbers(86,2);
    a.setNumbers(68,3);
    a.setNumbers(100,4);
    a.setNumbers(1,5);
    cout << "Gia tri cua mang o vi tri thu 5 la: " << a.getNumberber(5) << endl;
    cout << "Gia tri lon nhat: " << a.findHighest(n) << endl;
    cout << "Gia tri nho nhat: " << a.findLowest(n) << endl; 
    return 0;
}