/*
2.Array/File Functions
Viết một hàm có tên là arrayToFile. Hàm phải nhận ba đối số: tên của tệp, con trỏ đến mảng int 
và kích thước của mảng. Hàm sẽ mở tệp được chỉ định ở chế độ nhị phân, ghi nội dung của mảng vào tệp, 
sau đó đóng tệp.

Viết một hàm khác có tên fileToArray. Hàm này phải chấp nhận ba đối số: tên của tệp, con trỏ đến mảng int 
và kích thước của mảng. Hàm sẽ mở tệp được chỉ định ở chế độ nhị phân, đọc nội dung của nó vào mảng, 
sau đó đóng tệp.

Viết một chương trình hoàn chỉnh democác hàm này bằng cách sử dụng hàm arrayToFile để ghi một mảng vào một tệp, 
sau đó sử dụng hàm fileToArray để đọc dữ liệu từ chính tệp đó. Sau khi dữ liệu được đọc từ tệp vào mảng, 
hãy hiển thị nội dung của mảng trên màn hình. 
*/

#include<iostream>
using namespace std;
#include<fstream>

void ArrayToFile(string namefile, int *array, int size){
    ofstream out(namefile, ios::binary);
    if(out){
        out.write(reinterpret_cast< char*> (array), sizeof(array));
        out.close();
    }
    else cout << "Loi";
}

void FileToArray(string namefile, int *array, int size){
    ifstream in(namefile, ios::binary);
    if(in){
        in.read(reinterpret_cast< char*> (array), sizeof(array));
        in.close();
        for(int i = 0; i<size ; i++){
        cout << array[i] << " ";
    }
    }
    else cout << "Loi";
}

int main(){
    int size = 3;
    int a[size] = {2,6,20};
    string namefile;
    cout << "Nhap ten File: "; cin >> namefile;
    ArrayToFile(namefile,a,size);
    FileToArray(namefile,a,size);
    return 0;
}