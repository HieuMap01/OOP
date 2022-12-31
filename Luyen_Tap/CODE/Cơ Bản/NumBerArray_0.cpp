/*
NumberArray (0)
Hãy thiết kế một lớp có tên là NumberArray cho phép thể hiện một mảng số thực được khai báo động. Với những yêu cầu sau: 
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

#include<iostream>
using namespace std;

class NumberArray{
    float *a;
    int size;
    int checkI(int i) const {
        if(i < 0 || i > size) throw "-1";
        return i;
    }
    public:
        // Ham Huy 
        ~NumberArray() {delete []a;}
        // Ham tao
        NumberArray(int s, float x){
            if(s <= 0 ) throw"size > 0";
            size = s;
            a = new float [size];
            for(int i = 0; i < size; i++){
                a[i] = x;
            }
        }
        int getsize() const{return size;}
        float get(int i) const {return a[checkI(i)];}
        void set(int i, float x){a[checkI(i)] = x;}
        float getMax() const {
            float max = a[0];
            for(int i = 0; i < size; i++){
                if(max <= a[i]){max = a[i];}
            }
            return max;
        }
        // bonus them tim Min nho dau vao

        float getMin() const {
            float min = a[0];
            for(int i = 0; i < size; i++){
                if(min >= a[i]){min = a[i];}
            }
            return min;
        }
        //- print: Hiển thị ra màn hình số lượng phần tử và giá trị của mỗi phần tử có trong mảng.
        void print() const {
            cout << "So luong phan tu: " << size << endl;
            cout << "Gia tri cua moi phan tu:\n";
            for(int i = 0; i < size; i++){
                cout << i << ": " << a[i] << endl;
            }
        }
};

int main(){
    try{
        int size;
        cout << "Nhap co cua mang: "; cin >> size;
        float f;
        cout << "nhap 1 so thuc the hien gia tri mac dinh cua mang: "; cin >> f;
        NumberArray N(size,f);
        cout << "Nhap phan tu cho mang: \n";
        for(int i = 0; i < size; i++){
            cout << i << ": "; float a; cin >> a;
            N.set(i,a);
        }
        cout << "Gia tri lon nhat: " << N.getMax() << endl;
        cout << "Gia tri nho nhat: " << N.getMin() << endl;
        N.print();
    }
    catch(const char* e){
        cout << e << endl;
    }
    return 0;
}