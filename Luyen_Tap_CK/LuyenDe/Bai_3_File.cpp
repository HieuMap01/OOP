/*Loại bài 3: Viết hàm nhận vào tên file và một số n, tạo mảng n số theo quy luật cho trước, ghi vào file kia dưới dạng nhị phân.  
Viết tiếp hàm đọc từ file cho trước vào mảng cho trước. Main gọi lần lượt 2 hàm, sau đó duyệt mảng kết quả để đếm, in ra,…
- Viết một hàm có tên là fibonaciToFile. Hàm nhận hai đối số: tên của file và một số nguyên n. Hàm làm nhiệm vụ ghi n số 
fibonaci đầu tiên xuống file nhị phân (không dùng file text). 
- Viết một hàm khác có tên fileToArray. Hàm này nhận ba đối số: tên của file, con trỏ đến mảng kiểu int và một số nguyên 
count đại diện cho kích thước của mảng. Hàm này làm nhiệm vụ đọc count số nguyên đầu tiên bên trong file rồi đưa vào mảng. 
- Viết một chương trình hoàn chỉnh sử dụng các hàm trên bằng cách dùng hàm fibonaciToFile để ghi n số fibonaci đầu tiên xuống 
file, sau đó sử dụng hàm fileToArray để đọc dữ liệu từ chính file đó vào một mảng. Sau đó hãy hiển thị nội dung của mảng lên màn hình. 
Biết rằng: 
- Dãy Fibonaci được tính toán như sau:
f1 =1; 		f2 =1; 		fn  = fn-1 +fn-2 
*/

#include<iostream>
#include<fstream>
using namespace std;

void fibonaciToFile(string ten, int n){
    int a[n];
    if(n>0) a[0] = 1;
    if(n>1) a[1] = 1;
    for(int i = 2; i < n; i++){
        a[i] = a[i-1] + a[i-2];
    }
    ofstream out (ten,ios::binary);
    if(!out) cout << "Loi";
    else{
        out.write(reinterpret_cast<char*> (a), n*sizeof(int));
        out.close();
    }

}
void fileToArray(string ten,int *a, int n){
    ifstream in (ten,ios::binary);
    if(!in) cout << "Loi";
    else{
        in.read(reinterpret_cast<char*> (a), n*sizeof(int));
        in.close();
    }
}

int main(){
    int n = 5; 
    string s = "data.dat";
    fibonaciToFile(s, n); 
    int a[n]; 
    fileToArray(s, a, n);
    for (int i = 0; i<n; i++) cout << a[i] << " "; 
    cout << endl; 
}