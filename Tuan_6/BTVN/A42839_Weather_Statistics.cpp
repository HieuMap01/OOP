/*2.Thống kê thời tiết -Weather Statistics
Viết struct ThoiTiet mô tả dữ liệu thời tiết cho một tháng như sau:
    •Tổng lượng mưa
    •Nhiệt độ cao
    •Nhiệt độ thấp
    •Nhiệt độ trung bình
Main tạo 1 mảng gồm 12 phần tử sẽ lưu trữ dữ liệu thời tiết trong cả năm.
Chương trình yêu cầu người dùng nhập dữ liệu cho mỗi tháng. Nhiệt độ trung bình không cần nhập mà sẽ được tính toántừ nhiệt độ cao và thấp.
Sau khi nhập dữ liệu cho tất cả các tháng, chương trình sẽ tính toán và hiển thị tổng lượng mưa trong năm, lượng mưa trung bình hàng tháng,
trung bình tất cả các nhiệt độ trung bình của 12 tháng, cuối cùng in ra nhiệt độ cao nhất và thấp nhất trong năm và chỉ rõ thuộc về tháng nào.
Xác thực đầu vào: Chỉ chấp nhận nhiệt độ trong phạm vi từ -73 đến 60 độ C.Chỉ cần dùng kiểm tra do ... while thông thường ở hàm main, không cần dùng ngoại lệ.
*/

// #include<iostream>
// using namespace std;

// const int n = 12;

// struct Weather_Statistics{
//     double sum_lm, t_cao, t_thap, t_TB;
// };

// void input(Weather_Statistics  w[]){
//     const int max = 60, min = -73;
//     for(int i = 0; i < n; i++){
//         cout << "NHap luong mua thang "<< i + 1 << ": "; cin >> w[i].sum_lm;
//         do
//         {
//             do{
//                 cout << "Nhap nhiet do cao trong thang " << i+1 << ": "; cin >> w[i].t_cao;
//             }
//             while(w[i].t_cao > max || w[i].t_cao < min);
//             do{
//                 cout << "Nhap nhiet do thap trong thang " << i+1 << ": "; cin >> w[i].t_thap;
//             }
//             while(w[i].t_thap > max || w[i].t_thap < min);
//         }
//         while (w[i].t_cao < w[i].t_thap);

//         w[i].t_TB = (w[i].t_cao + w[i].t_thap)/2;
//         cout << endl;
//     }
// }

// void output(Weather_Statistics  w[]){
//     float sum, T_TB;
//     double t_c = w[0].t_cao, t_t = w[0].t_thap;
//     int Thang_C, Thang_T;

//     for(int i = 0; i < n; i++){
//         sum += w[i].sum_lm;
//         T_TB += w[i].t_TB;
//         if (t_c < w[i].t_cao){
//             t_c = w[i].t_cao;
//             Thang_C = i+1;
//         }
//         if (t_t > w[i].t_thap){
//             t_t = w[i].t_thap;
//             Thang_T = i+1;
//         }
//     }


//     cout << endl <<  "Tong luong mua ca nam: " << sum << endl
//          << "Luong mua TB hang thang: " << sum/n << endl
//          << "Nhiet do TB 12 thang: " << T_TB/n << endl
//          << "Nhiet do cao nhat thuoc ve thang " << Thang_C << " voi muc nhiet la: " << t_c << endl
//          << "Nhiet do thap nhat thuoc ve thang " << Thang_T << " voi muc nhiet la: " << t_t << endl;
// }

// int main(){
//     Weather_Statistics w[n];
//     input(w);
//     output(w);
// }

#include <iostream>
using namespace std;
const int n = 12; 

enum {January, Febuary, March, April, May, June, July, August, September, October, November, December};

struct ThoiTiet {
    float rain, highTemp, lowTemp, avgTemp; 
}; 

void calc(const ThoiTiet t[]) {
    double sum = 0, avgT = 0;
    for (int i = January; i < December; i++) {
        sum += t[i].rain;
        avgT += t[i].avgTemp;
    }
    avgT /= n;
    int iMax = January, iMin = January;
    for (int i = Febuary; i < December; i++){
        if (t[iMax].highTemp < t[i].highTemp) iMax = i;
        if (t[iMin].lowTemp > t[i].lowTemp) iMin = i;
    }
    cout << "Tong luong mua 1 nam: " << sum << endl
        << "Luong mua trung binh hang thang: " << sum/n << endl
        << "Nhiet do trung binh hang thang: " << avgT << endl;
    cout << "Thang " << iMax + 1 << " co nhiet do cao nhat nam voi " << t[iMax].highTemp << " do" << endl
        << "Thang " << iMin + 1 << " co nhiet do thap nhat nam voi " << t[iMin].lowTemp << " do" << endl;
}
void input(ThoiTiet &t){
    const int max = 60, min = -73;
    cout << "Nhap tong luong mua: "; cin >> t.rain;
    do {
        cout << "Nhiet do cao nhat: "; cin >> t.highTemp;
    } while (t.highTemp < min || t.highTemp > max);
    do {
        cout << "Nhiet do thap nhat: "; cin >> t.lowTemp;
    } while (t.lowTemp < min || t.lowTemp > max);
    t.avgTemp = (t.lowTemp + t.highTemp) / 2;

}
void output (const ThoiTiet t[]) {
    for (int i = Febuary; i < December; i++) {
    cout << "Thang " << i + 1 << endl 
        << "Luong mua: " << t[i].rain << endl
        << "Nhiet do cao nhat: " << t[i].highTemp << endl
        << "Nhiet do thap nhat: " << t[i].lowTemp << endl
        << "Nhiet do trung binh: " << t[i].avgTemp << endl;
    }
    calc(t);
}
void input(ThoiTiet t[]) {
    for (int i = Febuary; i < December; i++) {
        input(t[i]);
    }
}

// void inputAll (ThoiTiet a[], int n){
//     for (int i = 0; i<n; i++){
//         cout << i << ": \n"; 
//         cin >> a[i].rain >> a[i].highTemp >> a[i].lowTemp; 
//         a[i].avgTemp = (a[i].highTemp + a[i].lowTemp)/2; 
//     }
// }
// void outputAll (const ThoiTiet a[], int n){
//     for (int i = 0; i<n; i++){
//         cout << i << ": \n"; 
//         cout  << a[i].rain << " " << a[i].highTemp << " " 
//             <<  a[i].lowTemp << " " << a[i].avgTemp << endl;
//     }
// }
int main() {
    ThoiTiet t[n];
    input(t);
    output(t);
    return 0; 
}