/*
1.NormalArray
Thiết kế lớp NormalArraychophép biểu diễn một mảng số thực có thể lưu trữ nhiều nhất 100 phần tử.
với những thành viên sau:
Hàm tạo mặc định, không lưu trữ phần tử nào (số phần tử lúc tạo là 0). Gợi ý: cần thêm 1 biến 
thành viên lưu trữ  kích thước của mảng
getSize: trả về kích thước của mảng. 
get:truyền vào 1 đối số là số nguyên 𝑖 và trả về giá trị của phần tử thứ 𝑖 của mảng. 
Lưu ý, 𝑖 tính từ 0. Thông báo cho người dùng và trả về -1 nếu 𝑖 không hợp lệ. 
set: truyền vào 2 đối số lần lượt là vịtrí 𝑖 (sốnguyên) và số thực 𝑥. 
Hàm sẽ thay thế giá trị thứ 𝑖 của mảng thành 𝑥. Lưu ý, 𝑖 tính từ 0. 
Thông báo cho người dùng và không thay thế nếu 𝑖không hợp lệ. 
append: truyền vào 1 đối số là 1 số thực, hàm sẽ thêm vào cuối của mảng số thực 
đó nếu còn không gian lưu trữ. Thông báo nếu không thể lưu trữđược nữa. 
Hàm trả về tổng mảng 
Hàm trả về giá trị trung bình của mảng 
print:Hiển thị ra màn hình 
số lượng phần tử và giá trị của mỗi phần tử có trong mảng.Viết chương trình thể hiện 
một vài chức năngcủa lớp trên.
*/

#include<iostream>
using namespace std;

class NormalArray
{
    float a[100];
    int Size;
    public:
    //Hàm tạo mặc định, không lưu trữ phần tử nào (số phần tử lúc tạo là 0). Gợi ý: cần thêm 1 biến 
    //thành viên lưu trữ  kích thước của mảng
        NormalArray() {
            Size = 0;
        }
        //getSize: trả về kích thước của mảng. 
        int getSize() const {
            return Size;
        }
        //get:truyền vào 1 đối số là số nguyên 𝑖 và trả về giá trị của phần tử thứ 𝑖 của mảng.
        //Lưu ý, 𝑖 tính từ 0. Thông báo cho người dùng và trả về -1 nếu 𝑖 không hợp lệ. 
        int get(int i){
            if(i<Size){
            return a[i];
            }
            else{
                return -1;
            }
        }
        //set: truyền vào 2 đối số lần lượt là vịtrí 𝑖 (sốnguyên) và số thực 𝑥.
        void set(int i, float x){
            a[i] = x;
            Size++;
        }
        //append: truyền vào 1 đối số là 1 số thực, hàm sẽ thêm vào cuối của mảng số thực 
        //đó nếu còn không gian lưu trữ. Thông báo nếu không thể lưu trữ được nữa. 
        void append(float x) {
            if(Size < sizeof(a)/sizeof(a[0])) {
                set(Size, x);	
            } else {
                cout << "Khong luu tru duoc" << endl;
            }
        }
        // Hàm trả về tổng mảng 
        void sum(){
            int sum = 0;
            for (int k = 0; k < Size; k++){
                sum += a[k];
            }
            cout << "Tong cua mang: " << sum << endl;
        }
        // Hàm trả về giá trị trung bình của mảng 
        void TB(){
            int sum = 0;
            for (int k = 0; k < Size; k++){
                sum += a[k];
            }
            int TB = sum / Size;
            cout << "Gia tri TB: " << TB << endl;
        }
        void print() const {
            for(int i = 0; i < Size; i++){
                cout << a[i] <<" ";
            }
            cout << endl;
        }
        
};



int main(){
    int x;
    cout << "Nhap vi tri cua mang can tim: "; cin >> x;
    NormalArray a;
    a.set(0,12);
    a.set(1,23);
    a.set(2,45);
    a.set(3,43);
    a.set(4,34);
    a.set(5,13);
    a.set(6,2);

    cout << "Size: " << a.getSize() << endl;
    cout << "Gia tri can tim: " << a.get(3) << endl;
    //cout << (a.get(x)< a.getSize() ? "TRUE" : "FALSE") << endl;
    cout << a.get(x) << endl;
    a.sum();
    a.TB();
    a.append(5);
    a.print();
    return 0;
}


