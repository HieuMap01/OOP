/*
Sử dụng cấu trúc sau để lưu trữ thông tin về một loại thực phẩm cụ thể: 
- Mã số thực phẩm (là một số nguyên)
- Số gram chất béo (là một số nguyên, tính theo gram)
- Tổng lượng calo (là một số nguyên) df
- Tỷ lệ calo (là một số thực) 
Trong chương trình, xây dựng một mảng cấu trúc của 5 loại thực phẩm. Chương trình yêu cầu thực hiện các công việc sau:
- Nhập dữ liệu (mã số thực phẩm, số gram chất béo và tổng lượng calo) cho tất cả 5 loại thực phẩm rồi đưa vào cấu trúc 
trên (tỷ lệ calo được tính toán tự động dựa trên số gram chất béo và tổng lượng calo). 
- In ra màn hình Mã số thực phẩm của loại thực phẩm có tỷ lệ calo thấp nhất và loại thực phẩm có tỷ lệ calo cao nhất. 
Biết rằng: 
- Tỷ lệ calo = (Số gram chất béo * 9) / Tổng lượng calo 
*/

#include<iostream>
using namespace std;

struct thucpham
{
    string ms;
    int gram, calo;
    float tyle;
};

int main(){
    int n = 5;
    thucpham a[n];
    for(int i = 0; i<n; i++){
        cout << "Nhap MS, so gram, tong luong calo: "; cin >> a[i].ms >> a[i].gram >> a[i].calo;
        a[i].tyle = (a[i].gram * 9)/a[i].calo;
    }
    float max = a[0].tyle, min = a[0].tyle;
    int i_max = 0, i_min = 0;
    for(int i = 0; i<n; i++){
        if(max <= a[i].tyle){
            max = a[i].tyle;
            i_max = i;
        }
        if(min >= a[i].tyle){
            min = a[i].tyle;
            i_min = i;
        }
    }
    cout << "MS thuc pham cua loai co chi so thap nhat: " << a[i_min].ms << endl;
    cout << "MS thuc pham cua loai co chi so cao nhat: " << a[i_max].ms << endl;

}