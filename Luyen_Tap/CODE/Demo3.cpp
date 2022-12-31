/*Hãy thiết kế một lớp có tên là NumberArray cho phép thể hiện một mảng số thực được khai báo động. Với những yêu cầu sau: 
- Hàm hủy (Hủy tử) sẽ giải phóng bộ nhớ được giữ bởi mảng. 
- Hàm tạo cho phép nhập 2 đối số lần lượt là 1 số nguyên thể hiện kích thước của mảng và 1 số thực thể hiện giá trị mặc định của mảng 
(mỗi phần tử của mảng sau khi tạo có mang giá trị này).
Ngoài ra, lớp này có phải có những hàm thành viên (public) để thực hiện những công việc sau: 
- getSize: trả về kích thước của mảng. 
- get: truyền vào 1 đối số là số nguyên i và trả về giá trị của phần tử thứ i của mảng. Lưu ý, i tính từ 0. 
  Thông báo cho người dùng và trả về -1 nếu i không hợp lệ. 
- set: truyền vào 2 đối số lần lượt là vị trí i(số nguyên) và số thực x. Hàm sẽ thay thế giá trị thứ i của mảng thành x. 
  Lưu ý, i tính từ 0. Thông báo cho người dùng và không thay thế nếu i không hợp lệ. 
- getMax: trả về giá trị lớn nhất trong mảng. 
- print: Hiển thị ra màn hình số lượng phần tử và giá trị của mỗi phần tử có trong mảng.
Viết chương trình thể hiện vài chức năng của lớp trên.
*/
#include <iostream>
using namespace std;
class NumberArray{
    int size;
    double *arr;
    int check (int i) const{
        if (i < 0 || i >= size) throw "Chi so sai\n"; 
        return i;
    }
public:
    NumberArray(int n){
        if(n <= 0) throw "Co cua mang phai lon hon 0.\n";
        size = n;
        arr = new double[size];
    }

    ~NumberArray(){delete [] arr;}
    
    void setNumbers(int index, double x) {arr[index] = x;}
    double getNumbers(int index) const{
        return arr[check(index)];
    }
    double getMax(){
        double max = arr[0];
        for(int i = 0; i < size; i++){
            if(arr[i] > max) max = arr[i];
        }
        return max;
    }
    void Print() const{
        cout << "So luong phan tu cua mang: " << size << endl;
        for(int i = 0; i < size; i++)
            cout << arr[i] << "   ";
        cout << endl;
    }
};
int main(){
    try{
        int N;
        cout << "Nhap kich thuoc cua mang: "; cin >> N;
        NumberArray obj(N);
        for(int i = 0; i < N; i++){
            double x;
            cout << i + 1 << ": ";
            cin >> x;
            obj.setNumbers(i, x);
            obj.Print();
            cout << "Gia tri lon nhat cua mang la: " << obj.getMax() << endl;
        }
    }catch (const char * e){
        cout << e << endl; 
    }
    return 0;
}