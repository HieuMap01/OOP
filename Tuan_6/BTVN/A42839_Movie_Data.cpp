/*
1.Dữ liệu phim -Movie Data
a)
    Viết structMovieData để lưu trữ thông tin sau về phim:
        •Tiêu đề 
        •Đạo diễn
        •Năm phát hành 
        •Thời gian chạy (tính bằng phút) 
    Viết 1 hàm truyền vào 1 tham số kiểu Movie Data và hiển thị các nội dung của tham số này.
    Trong hàm main khai báo 2 biến kiểu MovieDatavà khởi tạo giá tr ịcho chúng. 
    Sau đó sử dụng hàm đã viết ở trên để hiển thị nội dung của từng biến vừa nhập.
b) 
    Bổ sung cấu trúc MovieData trên thêm 2 thành viên để lưu thông tin về chi phí sản xuất(cost)và doanh thu của phim trong năm đầu tiên ra mắt (sale). 
    Sửa đổi hàm hiển thị dữ liệu viết ở câu a, để inra:
        tiêu đề, đạo diễn, năm phát hành, thời gian chạy và số lãi của năm đầu tiên(tính từ sale –cost).
*/

//------------A------------

// #include<iostream>
// using namespace std;

// struct Movie_data{
//     string tieude, daodien;
//     int year_PH, TG;
// };

// void output(Movie_data m){
//     cout << "Tieu de: " << m.tieude << endl << "Dao dien: " << m.daodien << endl << "Nam phat hanh: " << m.year_PH << endl << "Thoi gian chay: " << m.TG<< endl;
// }

// int main(){
//     Movie_data m{"one piece","Hieu",2012,120};
//     output(m);
//     return 0;

//---------------B----------------
#include<iostream>
using namespace std;

struct Movie_data{
    string tieude, daodien;
    int year_PH, TG;
    float cost,sale;
};

void output(Movie_data m){
    cout << "Tieu de: " << m.tieude << endl << "Dao dien: " << m.daodien << endl << "Nam phat hanh: " << m.year_PH << endl << "Thoi gian chay: " << m.TG<< endl
         << "So lai nam dau tien: " << m.sale - m.cost;
}

int main(){
    Movie_data m{"one piece","Hieu",2012,120,1000,123400};
    output(m);
    return 0;
}