/*
NumberArray (3)
Hãy thiết kế một lớp có tên là NumberArray cho phép thể hiện một mảng số thực có thể lưu trữ nhiều nhất 100 phần tử. 
Với những hàm thành viên sau: 
    - Hàm tạo mặc định, không lưu trữ phần tử nào (kích thước lúc tạo là 0). (Gợi ý: cần 1 biến thành viên lưu trữ kích thước của mảng) 
    - getSize: trả về kích thước của mảng. 
    - get: truyền vào 1 đối số là số nguyên i và trả về giá trị của phần tử thứ i của mảng. Lưu ý, i tính từ 0. 
Thông báo cho người dùng và trả về -1 nếu i không hợp lệ. 
    - set: truyền vào 2 đối số lần lượt là vị trí i(số nguyên) và số thực x. Hàm sẽ thay thế giá trị thứ i của mảng thành x. 
Lưu ý, i tính từ 0. Thông báo cho người dùng và không thay thế nếu i không hợp lệ. 
    - append: truyền vào 1 đối số là 1 số thực, hàm sẽ thêm vào cuối của mảng số thực đó nếu còn không gian lưu trữ. 
Thông báo nếu không thể lưu trữ được nữa. 
    - getMax: trả về giá trị lớn nhất trong mảng. 
    - getMin: trả về giá trị nhỏ nhất trong mảng. 
    - print: Hiển thị ra màn hình số lượng phần tử và giá trị của mỗi phần tử có trong mảng.
Viết chương trình thể hiện vài chức năng của lớp trên.

*/

#include <iostream> 
using namespace std;
const int MAX = 100;

class NormalArray
{
    int size;
    double a[MAX];
    int checkI(int i) const {
        if(i < 0 || i > size) throw "-1";
        return i;
    }
public:
    NormalArray(){size = 0;}
    int getSize() const {return size;}

    // lưu ý size chứ không phải MAX mới là số phần tử thật sự 
    // của mảng (gồm các phần tử đã được truyền giá trị)
    void set(int i, double x) 
    { 
        if (i >= 0 && i < size) a[i] = x;  
        else cout << "Chi so khong hop le!\n"; 
    }
    double get(int i) const
    {
        if (i >= 0 && i < size) return a[i]; 
        cout << "Chi so khong hop le\n"; 
        return -1;
    }
    void append(double v)
    {
        if (size < MAX)
        { 
            a[size] = v; 
            size++;
        }
        else cout<<"Mang da day!\n";
    }
    double getMax() const {
            double max = a[0];
            for(int i = 0; i < size; i++){
                if(max <= a[i]){max = a[i];}
            }
            return max;
        }
    double getMin() const {
        double min = a[0];
        for(int i = 0; i < size; i++){
            if(min >= a[i]){min = a[i];}
        }
        return min;
    }
    void print() const {
            cout << "So luong phan tu: " << size << endl;
            cout << "Gia tri cua moi phan tu:\n";
            for(int i = 0; i < size; i++){
                cout << i << ": " << a[i] << endl;
            }
        }
};

int main()
{
	NormalArray temp;
	temp.append(1);
	temp.append(2);
	temp.append(3);
	temp.append(4);
	temp.append(5);
	temp.append(6);
	cout << "Kich co: " << temp.getSize() << endl;
	cout << "Gia tri thu 4: " << temp.get(3) << endl;
	cout << "Gia tri thu 101: " << temp.get(101) << endl;
	temp.set(3,100);
	cout << "Gia tri thu 4 sau khi thay: " << temp.get(3) << endl;
	return 0;
}
