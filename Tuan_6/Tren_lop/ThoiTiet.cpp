/*
2.Thống kê thời tiết - Weather Statistics
Viết struct ThoiTiet môtả dữ liệu thời tiết cho một như sau:
    •Tổng lượng mưa
    •Nhiệt độ cao
    •Nhiệt độ thấp
    •Nhiệt độ trung bình
Main tạo 1 mảng gồm 12 phần tử sẽ lưu trữ dữ liệu thời tiết trong cả năm. 
Chương trình yêu cầu người dùng nhập dữ liệu cho mỗi tháng. Nhiệt độ trung bình khôngcần nhập mà sẽ được tính toán từ nhiệt độ cao và thấp.
Sau khi nhập dữ liệu cho tất cả các tháng, chương trình sẽ tính toán và hiển thị tổng lượng mưa trong năm, lượng mưa trung bình hàng tháng, 
trung bình tất cả các nhiệt độ trung bình của 12 tháng, cuối cùng in ra nhiệt độ cao nhất và thấp nhất trong năm và chỉ rõ thuộc về nào.
    Xác thực đầu vào: Chỉ chấp nhận nhiệt độ trong phạm vi từ -73 đến 60 độ C.
    Chỉ cần dùng kiểm tra do ... while thông thường ở hàm main, không cần dùng ngoại lệ. 
*/

#include <iostream>
using namespace std;

const int n = 3; 

enum Thang{January, February, March, April, May, June, July, August, September, October, November, December};

struct ThoiTiet{
    float  rain, highTemp, lowTemp, avgTemp; // = (highTemp + lowTemp)/2; 
    // phần này chỉ demo tạo hàm tạo và dùng nó để khởi tạo biến struct
    // ThoiTiet(int r = 0, int h = 0, int l = 0)
    // : rain(r), highTemp (h), lowTemp(l), avgTemp((lowTemp + highTemp)/2){}
}; 
void input (ThoiTiet & a){


        cout << "Nhap luong mua  : " ; cin >> a.rain;
        do{
            cout << "Nhap nhiet do cao va nhiet do thap : "; cin >> a.highTemp >> a.lowTemp; 
        }
        while (a.highTemp < -73 || a.highTemp > 60 || a.lowTemp < -73 || a.lowTemp > 60);

        a.avgTemp = (a.highTemp + a.lowTemp)/2; 
    
    
}

//Sau khi nhập dữ liệu cho tất cả các tháng, chương trình sẽ tính toán và hiển thị tổng lượng mưa trong năm, lượng mưa trung bình hàng tháng, 
//trung bình tất cả các nhiệt độ trung bình của 12 tháng, cuối cùng in ra nhiệt độ cao nhất và thấp nhất trong năm và chỉ rõ thuộc về nào.
void output (const ThoiTiet a[]){
    float Sum_r = 0, sum_t = 0, t_max = a[0].highTemp,t_min=a[0].lowTemp;
    for(int i = 0; i < n; i++){
        Sum_r += a[i].rain;
        sum_t += a[i].avgTemp;
        if(t_max <= a[i].highTemp){
            t_max = a[i].highTemp;
        }
        if(t_min <= a[i].lowTemp){
            t_min = a[i].lowTemp;
        }
    }
    cout << Sum_r << " " <<  Sum_r/n << " " 
        <<  sum_t/n << " " << t_max << " " << t_min << endl;  
}
void inputAll (ThoiTiet a[], int n){
    for (int i = 0; i<n; i++){
        cout << i << ": \n"; 
        cin >> a[i].rain >> a[i].highTemp >> a[i].lowTemp; 
        a[i].avgTemp = (a[i].highTemp + a[i].lowTemp)/2; 
    }
}
void outputAll (const ThoiTiet a[], int n){
    for (int i = 0; i<n; i++){
        cout << i << ": \n"; 
        cout  << a[i].rain << " " << a[i].highTemp << " " 
            <<  a[i].lowTemp << " " << a[i].avgTemp << endl;
    }
}
int main(){
    // //câu a
    // ThoiTiet a1[] = {{3, 4, 5}, {3, 2, 5}, {3, 4, 6}}; 
    // for (int i = 0; i<n; i++)
    //     a1[i].avgTemp = (a1[i].highTemp + a1[i].lowTemp)/2; 

    // //câu b
    // ThoiTiet a2[n]; 
    // for (int i = 0; i<n; i++){
    //     cout << i << ": "; 
    //     cin >> a2[i].rain >> a2[i].highTemp >> a2[i].lowTemp; 
    //     a2[i].avgTemp = (a2[i].highTemp + a2[i].lowTemp)/2; 
    // }
    // for (int i = 0; i<n; i++){
    //     cout << i << ": "; 
    //     cout <<  a2[i].rain << " " << a2[i].highTemp << " " << a2[i].lowTemp 
    //         << " " << a2[i].avgTemp << endl; 
    // }

    //câu c
    ThoiTiet a3[n];
    inputAll(a3, n); 
    outputAll(a3); 

    // câu test thêm khởi tạo struct kiểu dùng hàm tạo
    // ThoiTiet a4[] = {ThoiTiet(3, 4, 5), ThoiTiet(3, 2, 5), ThoiTiet(3, 4, 6)};
    // outputAll(a4, n); 

    return 0; 
}