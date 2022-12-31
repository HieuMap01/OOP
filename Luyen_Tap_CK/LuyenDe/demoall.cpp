/*
    Xây dựng lớp TaiKhoan mô phỏng một tài khoản gửi tiền tiết kiệm với các thuộc tính và hàm như sau:
	+ Số tiền ban đầu (lớn hơn hoặc bằng không)
	+ Thời hạn gửi tiền (tính theo năm và lớn hơn hoặc bằng không)
	+ mức lãi suất hàng năm (lớn hơn hoặc bằng không)
	+ hàm in ra thông tin của tài khoản (ngoài 3 thông tin trên cần in thêm số tiền dự tính nhận được khi hết kì hạn)
     f(n) = tien_ban_dau * (1+laisuat/100)^n; 
     <Số tiền nhận được > = S x (1 + L / 100) ^ T;  ( ^ là kí hiệu phép lũy thừa)
	Tạo một hàm khởi tạo 3 tham số truyền vào 3 thuộc tính trên
	
    Quá tải toán tử cộng bằng (+=) giữa một đối tượng BankAccount và 1 số nguyên dương, sau khi thực hiện phép toán này 
    thì thuộc tính số tiền ban đầu sẽ tăng thêm một khoảng bằng với số nguyên được cộng vào. Lưu ý cộng với số âm thì 
    sẽ thành trừ, nhưng số tiền ban đầu sẽ chỉ giảm đến 0 là thấp nhất
*/

#include <iostream> 
#include<math.h>
#include<fstream>
using namespace std; 

class TaiKhoan{
    double bandau, laisuat; 
    int nam;
public: 
    TaiKhoan(double start = 0, double lai = 0, int year = 0){
        if (start <0|| lai <0 || year <0) throw "loi\n"; 
        bandau = start; 
        laisuat = lai; 
        nam = year; 
    }
    void print() const{
        double cuoi = bandau * pow(1+laisuat/100, nam); 
        cout << bandau << " " << laisuat << " " << nam << " " << cuoi << endl; 
    }
    TaiKhoan & operator += (int n){ // toán tử duy nhất trả về tham chiếu
        bandau += n;
        if (bandau < 0) bandau = 0; 
        return *this; 
    }
}; 
int main(){
    TaiKhoan o(100, 20); 
    o += 1; 
    o.print(); 
    return 0; 
}

/*
(2 điểm)Xây dựng class DanSo mô phỏng dân số của một quốc giá với các thuộc tính và hàm như sau:
	+ Dân số hiện tại (lớn hơn hoặc bằng không, kí hiệu là D)
	+ Tỉ lệ sinh hàng năm (tính theo phần trăm, lớn hơn không. kí hiệu là S)
	+ Tỉ lệ tử hàng năm (tính theo phần trăm, lớn hơn không, kí hiệu là T)
	+ hàm in ra dân số của quốc gia đó sau n năm, với n là một số nguyên dương được truyền vào hàm. 
    Giả định dân số phải là một số nguyên và tối thiểu là không
	Công thức tính dân số sau n năm giả định là:
	Dân số = D x (1 + (S – T) / 100) ^ n;   ( ^ là kí hiệu phép lũy thừa)

	- (1 điểm)Tạo một hàm khởi tạo 3 tham số truyền vào 3 thuộc tính trên
	- (1 điểm)Quá tải toán tử cộng (+) giữa hai đối tượng DanSo, kết quả trả về sẽ là một đối tượng 
    DanSo có :
		+ dân số hiện tại bằng tổng dân số hiện tại của 2 đối tượng tham gia phép cộng
		+ tỉ lệ sinh và tỉ lệ tử tính bằng cách lấy trung bình cộng tỉ lệ sinh và tỉ lệ tử của 2 đối 
        tượng tham gia phép cộng.
*/
class DanSo{
    int danso; 
    float sinh, tu; 
public: 
    DanSo(int ds, float s, float t){
        if (ds < 0|| s <= 0 ||t <= 0) throw "Loi\n"; 
        danso = ds; 
        sinh = s; 
        tu = t;
    }
    void print(int n) const{
        int tmp = danso * pow (1 + (sinh - tu)/100, n); 
        if (tmp < 0 ) tmp = 0; 
        cout << tmp << endl; 
    }
    DanSo operator + (DanSo r){
        return DanSo(danso + r.danso, (sinh + r.sinh)/2, (tu+r.tu)/2); 
    }
}; 
int main(){
    DanSo a(100, 3, 1), b(200, 5, 3); 
    (a+b).print(2); 
    return 0; 
}

/*
- Xây dựng class BaoHiem mô phỏng hoạt động bảo hiểm với các thuộc tính và hàm như sau:
	+ Mức phí bảo hiểm (kí hiệu là P)
	+ Tỉ lệ bồi thường (số thực lớn hơn 1, kí hiệu là B). Mức bồi thường bằng mức phí bảo hiểm nhân tỉ lệ này
	+ Tỉ lệ tai nạn xảy ra (tính theo phần trăm, kí hiệu là R), khi tai nạn xảy ra bảo hiểm mới phải bồi thường
	+ hàm in ra thông tin bảo hiểm gồm 3 thuộc tính trên và dự tính lợi nhuận trung bình của loại hợp đồng bảo hiểm này. Trong đó:
	Lợi nhuận trung bình = P x (1 – B x R / 100)
- Tạo một hàm khởi tạo 3 tham số truyền vào 3 thuộc tính trên
- (1 điểm) Quá tải toán tử so sánh bằng (==) giữa hai đối tượng BaoHiem, kết quả trả về true nếu lợi nhuận trung bình của đối tượng 
thứ nhất bằng lợi nhuận trung bình của đối tượng thứ hai, trả về false nếu ngược lại
*/

class BaoHiem{
    float P, B, R; 
    float trungbinh() const {
        return P * (1 - B * R / 100); 
    }
public: 
    BaoHiem(float p, float b, float r){
        if (b<=1) throw "Loi\n"; 
        P = p; 
        B = b; 
        R = r; 
    }
    void print() const{
        float loinhuan = trungbinh(); 
        cout << P << " " << B << " " << R << " " << loinhuan << endl; 
    }
    bool operator == (BaoHiem r){
        return trungbinh() == r.trungbinh(); 
    }
}; 
int main(){}

/*
    Các chỗ đề bài đã nêu private, virtual cần giữ nguyên. Ở ở các chỗ không nêu rõ, sinh viên được tự lựa chọn virtual, 
    private, protected, public, const hay thêm hàm nếu cần để thể hiện thiết kế tốt.
    Cho lớp trừu tượng HoaDon (hoá đơn) , gồm các thành viên:  
    •	Biến private: tên hoá đơn (xâu), bên A (bên bán - xâu), bên B (bên mua - xâu), số tiền thanh toán (số thực)
    •	Hàm khoiTao sẽ cập nhật các biến tên hoá đơn, bên A, bên B
    •	Hàm ảo thuần tuý tinhTien trả về số tiền thanh toán, hàm này được ghi đè ở lớp con
    •	Hàm capNhatTien cập nhật biến số tiền thanh toán bằng hàm tinhTien
    •	Hàm hienThi in ra tên hoá đơn, bên A, bên B, số tiền thanh toán
    Lớp HoaDonNuoc (hoá đơn nước) kế thừa HoaDon, có tên hoá đơn mặc định là “Hoa don Nuoc”, gồm các thành viên: 
    •	Biến private: tháng tính hoá đơn (số nguyên), số nước (số thực), đơn giá (số thực)
    •	Ghi đè hàm tinhTien lớp cha, trả về số tiền thanh toán = số nước * đơn giá 
    •	Ghi đè hàm hienThi lớp cha để in ra lần lượt tháng tính hoá đơn, tên hoá đơn, bên A, bên B, số tiền thanh toán, số nước, đơn giá 
    Lớp HoaDonNetflix kế thừa HoaDon, có tên hoá đơn mặc định là “Hoa don Netflix”, gồm các thành viên:  
    •	Biến private: số tháng (số nguyên), đơn giá (số thực)
    •	Ghi đè hàm tinhTien lớp cha, trả về số tiền thanh toán = số tháng* đơn giá
    •	Ghi đè hàm hienThi lớp cha để in ra lần lượt tên hoá đơn, bên A, bên B, số tiền thanh toán, số tháng, đơn giá 
    Viết hàm main tạo một mảng có tính đa hình gồm 5 phần tử HoaDon, sao cho gồm cả HoaDonNuoc và HoaDonNetflix, sau đó 
    gọi hàm hienThi trên cả mảng. 
*/

class HoaDon{
    string ten, A, B; 
    float sotien;
    virtual float tinhTien() const = 0; // const 
protected: 
    void khoiTao(string tenhd, string benA, string benB){
        ten = tenhd; 
        A = benA; 
        B = benB;
    }
    void capNhatTien(){
        sotien = tinhTien(); 
    }
public: 
    virtual void hienThi() const {
        cout << ten << endl << A << endl << B << endl << sotien << endl; 
    }
    virtual ~HoaDon(){} // huỷ ảo
}; 

class HoaDonNuoc: public HoaDon{
    int thang; 
    float sonuoc, dongia;
    float tinhTien() const { return sonuoc * dongia; }; // const 
public: 
    HoaDonNuoc(string benA, string benB, int thang, float nuoc, float gia){
        khoiTao("Hoa don Nuoc", benA, benB); // tên mặc định 
        this->thang = thang; 
        sonuoc = nuoc; 
        dongia = gia; 
        capNhatTien(); 
    }
    void hienThi() const { // thứ tự in ra 
        cout << thang << endl; 
        HoaDon::hienThi(); 
        cout << sonuoc << endl << dongia << endl; 
    }
};

class HoaDonNetflix: public HoaDon{
    int thang; 
    float dongia;
    float tinhTien() const { return thang * dongia; }; 
public: 
    HoaDonNetflix(string benA, string benB, int thang, float gia){
        khoiTao("Hoa don Netflix", benA, benB); 
        this->thang = thang; 
        dongia = gia; 
        capNhatTien(); 
    }
    void hienThi() const {
        HoaDon::hienThi(); 
        cout << thang << endl << dongia << endl; 
    }
};

int main(){
    int n = 5; 
    HoaDon * a[] = {new HoaDonNetflix ("Netflix", "A", 3, 200), new HoaDonNuoc("Nuoc HN", "B", 5, 20, 10), 
                    new HoaDonNetflix ("Netflix", "A", 3, 200), new HoaDonNuoc("Nuoc HCM", "B", 5, 20, 10),
                    new HoaDonNetflix ("HBO", "A", 3, 200)}; 
    for (int i = 0; i<n; i++)
        a[i]->hienThi(); 
    return 0; 
}

/*
    Cho lớp trừu tượng MangLoc (mảng lọc) , gồm các thành viên:  
    •	Biến private: mô tả mảng (xâu), một mảng chứa nhiều nhất 100 phần tử (mảng số nguyên), số phần tử trong mảng(số nguyên)
    •	Hàm khoiTao sẽ cập nhật biến mô tả mảng, đồng thời tự gán biến số phần tử mảng bằng 0
    •	Hàm ảo thuần tuý thoaMan nhận vào một số nguyên và trả về số đó có thoả mãn điều kiện thêm vào mảng không, hàm này sẽ 
    được cài đặt ở lớp con
    •	Hàm them nhận vào một số nguyên, nếu thoả mãn điều kiện thêm vào mảng (dùng hàm thoaMan kiểm tra) thì thêm vào sau phần 
    tử mảng cuối cùng và tăng số phần tử mảng thêm 1. 
    •	Hàm hienThi in ra mô tả, số phần tử mảng, và toàn bộ mảng
    Lớp MangLocUoc (mảng lọc ước) ứng với các mảng chỉ chấp nhận thêm vào các số là ước của một số cho trước. Lớp này kế thừa 
    lớp MangLoc, có mô tả mặc định là “Mang loc uoc so” và gồm các thành viên sau:  
    •	Một biến số nguyên tên la uoc (ước), để private, được xác định ngay khi tạo đối tượng
    •	Ghi đè hàm thoaMan lớp cha để mảng chỉ chấp nhận thêm vào các số là ước của biến uoc
    •	Ghi đè hàm hienThi lớp cha để lần lượt in ra mô tả, số phần tử mảng, toàn bộ mảng, và biến uoc
    Lớp MangLocNgoaiKhoang (mảng lọc ngoài khoảng) ứng với các mảng chỉ chấp nhận thêm vào các số nằm ngoài một khoảng cho trước. 
    Lớp này kế thừa lớp MangLoc, có mô tả mặc định là “Mang loc ngoai khoang” và gồm các thành viên sau:  
    •	Hai biến số thực trai và phai, để private, được xác định ngay khi tạo đối tượng
    •	Ghi đè hàm thoaMan lớp cha để mảng chỉ chấp nhận thêm vào các số nằm ngoài khoảng [trai, phai) (nghĩa là các số nguyên x < trai 
    hoặc x >= phai)
    •	Ghi đè hàm hienThi lớp cha để lần lượt in ra mô tả, số phần tử mảng, toàn bộ mảng, biến trai và biến phai
    Viết hàm main tạo một mảng arr có tính đa hình gồm 5 phần tử MangLoc, sao cho gồm cả MangLocUoc và MangLocNgoaiKhoang, sau đó 
    tạo một mảng gồm 20 số nguyên, rồi với mỗi phần tử của mảng arr, hãy thử thêm vào 20 số nguyên này. Cuối cùng in ra thông tin 
    cả mảng arr dùng hàm hienThi
*/

#include <iostream> 
using namespace std; 

class MangLoc{
    string mota; 
    int a[100]; 
    int size; 
    virtual bool thoaMan(int) const = 0;
protected: 
    void khoiTao(string mt){
        mota = mt; 
        size = 0; 
    }
public: 
    void them(int x){
        if (thoaMan(x)){
            a[size] = x; 
            size++; 
        }
    }
    virtual void hienThi() const {
        cout << mota << endl << size << endl; 
        for (int i = 0; i<size; i++) cout << a[i] << " "; 
        cout << endl; 
    }
    virtual ~MangLoc(){}
}; 

class MangLocUoc: public MangLoc{ 
    int uoc; 
    virtual bool thoaMan(int x) const { return uoc % x == 0; };
public: 
    MangLocUoc(int uoc): uoc(uoc) {
        khoiTao("Mang loc uoc so"); 
    }
    void hienThi() const {
        MangLoc::hienThi(); 
        cout << uoc << endl; 
    }
}; 

class MangLocNgoaiKhoang: public MangLoc{ 
    float trai, phai; 
    virtual bool thoaMan(int x) const { return x < trai || x >= phai; };
public: 
    MangLocNgoaiKhoang(float trai, float phai): trai(trai), phai(phai) {
        khoiTao("Mang loc ngoai khoang"); 
    }
    void hienThi() const {
        MangLoc::hienThi(); 
        cout << trai << endl << phai << endl; 
    }
}; 


int main(){
    int n = 5; 
    MangLoc * arr[] = {new MangLocUoc(5), new MangLocNgoaiKhoang (2, 7),
                    new MangLocUoc(5), new MangLocNgoaiKhoang (2, 7),
                    new MangLocUoc(5) }; 

    int m = 20; 
    int b[] = {1, 2, 3, 4, 5, 6, 7, 8, 9, 10, 11, 12, 13, 14, 15, 16, 17, 18, 19, 20}; 
    for (int i = 0; i<n; i++)
        for (int j = 0; j<m; j++)
            arr[i]->them (b[j]); 
    
    for (int i = 0; i<n; i++)
        arr[i]->hienThi();

    return 0; 
}

/*
    Cho lớp trừu tượng MangBienDoi (mảng biến hình) , gồm các thành viên:  
    •	Biến private: biến ten chỉ tên mảng, mảng số nguyên a chứa nhiều nhất 100 phần tử, biến size chỉ số phần tử mảng
    •	Hàm ganTen sẽ cập nhật biến ten
    •	Hàm ảo thuần tuý bienDoi nhận một số nguyên, trả về giá trị được biến đổi từ số đó, hàm sẽ được cài ở lớp con.
    •	Hàm ganMang nhận một mảng số nguyên b  kích thước n, và gán n phần tử đầu mảng b này cho mảng a như sau: 
    void ganMang(int b[], int n){ // gán mảng
        size = n;
        if (size > 100)
            size = 100; 
        for (int i = 0; i < size; i++)
            a[i] = b[i];
    }
    •	Hàm lamBienDoi sẽ gọi hàm bienDoi trên từng phần tử mảng a để biến đổi cả mảng 
    •	Hàm hienThi in ra tên mảng, số phần tử, và toàn bộ mảng
    Lớp MangTinhTien (mảng tịnh tiến) ứng với các mảng được biến đổi nhờ tăng mọi phần tử thêm một số cho trước. Lớp này 
    kế thừa lớp MangBienDoi, có tên mảng mặc định là “Mang tinh tien” và gồm các thành viên sau:  
    •	Một biến số nguyên x, để private, được xác định ngay khi tạo đối tượng
    •	Ghi đè hàm bienDoi lớp cha để nhận vào một số, trả về số đó cộng x. 
    •	Ghi đè hàm hienThi lớp cha để lần lượt in ra tên mảng, số phần tử, toàn bộ mảng và biến x
    Lớp MangNhiPhan (mảng nhị phân) ứng với các mảng được biến đổi nhờ thay mọi giá trị chẵn thành 0 và mọi giá trị lẻ 
    thành 1. Lớp này kế thừa MangBienDoi, có tên mảng mặc định là “Mang nhi phan” và gồm các thành viên sau:  
    •	Ghi đè hàm bienDoi lớp cha để nhận vào một số nguyên, trả về 0 nếu số đó chẵn, 1 nếu số đó lẻ
    Viết hàm main tạo mảng arr có tính đa hình gồm 5 phần tử MangBienDoi, sao cho gồm cả MangTinhTien và MangNhiPhan. 
    Sau đó tạo một mảng gồm 20 số nguyên, rồi với từng phần tử của mảng arr, dùng hàm ganMang gán mảng 20 số vào bên 
    trong phần tử, sau đó biến đổi các mảng nhờ hàm lamBienDoi. Cuối cùng, in ra thông tin cả mảng arr dùng hàm hienThi
*/

class MangBienDoi{
    string ten; 
    int a[100]; 
    int size; 
    virtual int bienDoi(int) const = 0; // xem lại cú pháp hàm thuần tuý ảo; nhận int và trả về int 
protected: 
    void ganTen(string t){ten = t; }
public: 
    void ganMang(int b[], int n){ // gán mảng
        size = n;
        if (size > 100)
            size = 100; 
        for (int i = 0; i < size; i++)
            a[i] = b[i];
    }
    void lamBienDoi(){
        for (int i = 0; i<size; i++)
            a[i] = bienDoi(a[i]); // không phải chỉ là bienDoi(a[i])
    }
    virtual void hienThi() const{
        cout << ten << endl << size << endl; 
        for (int i = 0; i<size; i++) cout << a[i] << " "; 
        cout << endl; 
    }
    virtual ~MangBienDoi(){}
}; 


class MangTinhTien : public MangBienDoi{ 
    int x; 
    virtual int bienDoi(int n) const {return n + x; }; 
public: 
    MangTinhTien (int x): x(x) { ganTen("Mang tinh tien");} // nó có tên/mô tả/kiểu mặc định, nghĩa là không nhập đối số mà tự truyền
    virtual void hienThi() const{
        MangBienDoi::hienThi(); 
        cout << x << endl; 
    }
};
class MangNhiPhan: public MangBienDoi{ 
    virtual int bienDoi(int n) const { 
        if (n%2==0) return 0; 
        return 1; 
    }; 
    // cách dưới bị sai, không dùng cách này
    // virtual int bienDoi(int n) const { 
    //     return n%2; // -1 số dư lại là -1 => error
    // }; 
public: 
    MangNhiPhan() { ganTen("Mang nhi phan ");}
    // đọc kỹ đề, đề có thể không yêu cầu viết hàm hienThi, thì ko viết
};

int main(){
    int n = 5; 
    MangBienDoi * arr[] = {new MangNhiPhan(), new MangTinhTien (4), 
                        new MangNhiPhan(), new MangTinhTien (2), 
                        new MangNhiPhan()}; 
    int m = 20; 
    int b[] = {1, 2, 3, 4, 5, 1, 2, 3, 4, 5, 1,2, 3, 4,5, 1, 2, 3, 4,5 }; 

    for (int i = 0; i<n; i++){
        arr[i]->ganMang(b, m); // hàm ganMang gán cả mảng nên chỉ gọi 1 lần, không cần vòng lặp bên trong
        arr[i]->lamBienDoi();  // ham lamBienDoi sẽ biến đổi cả mảng nên chỉ gọi 1 lần, không cần vòng lặp bên trong
    }
    for (int i = 0; i<n; i++)
        arr[i]->hienThi(); 

    return 0; 
}

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

struct ThucPham{
    int ma, beo, calo; 
    float tyle; 
};

void nhap(ThucPham & a){
    cout << "nhap ma, beo, calo: ";
    cin >> a.ma >> a.beo >> a.calo;
    a.tyle = a.beo * 9.0 /a.calo; 
}
int main(){
    int n = 2; 
    ThucPham a[n]; 
    int iMin = 0, iMax = 0; 
    for (int i = 0; i<n; i++)
    {
        cout << i << ": "; 
        nhap (a[i]); 
        if (a[i].tyle < a[iMin].tyle) iMin = i; 
        if (a[i].tyle > a[iMax].tyle) iMax = i; 
    }
    cout << "Ma lon nhat: " << a[iMax].ma << endl
         << "Ma nho nhat: " << a[iMin].ma << endl; 
    return 0; 
}

/*
    Bài tập 1: Xây dựng lớp template TamGiac dùng để định nghĩa tổng quát đối với các kiểu dữ liệu bên trong lớp. 
    Trong lớp này có chứa 3 thuộc tính dạng số và có cùng kiểu dữ liệu với nhau, đại diện cho 3 cạnh của tam giác.
    - Viết các cấu tử, các phương thức đặt và lấy giá trị thuộc tính.
    - Viết hai phương thức lấy chu vi và lấy diện tích của hình tam giác với kiểu giá trị trả về của hai phương thức 
    này có thể khác với kiểu dữ liệu của thuộc tính.
    - Viết hàm main minh họa bằng các sử dụng lớp template TamGiac với các kiểu dữ liệu khác nhau.
    Chú ý: Để tính diện tích tam giác dựa trên 3 cạnh, ta sử dụng công thức Heron như sau:
*/

template <class T, class U> 
class TamGiac{
    T a, b, c; 
public: 
    TamGiac (T a, T b, T c): a(a), b(b), c(c){}
    void setA(T a1){a = a1;}
    void setB(T b1){ b = b1;}
    void setC(T c1){ c = c1;}
    void set (T a1, T b1, T c1) { a= a1; b = b1; c = c1 }
    T getA() const {return a;}
    T getB() const {return b;}
    T getC() const {return c;}

    U getChuvi() const {return a + b + c;}
    U getDientich1() const {
        return U(sqrt ((a+b+c)* (a+b-c) *(a+c-b) * (b+c-a)))/ U(4); 
    }
    // U getDientich2() const {
    //     U p = U(a+b+c)/U(2); 
    //     return sqrt (p * (p-a) * (p-b)*(p-c)); 
    // }
   
}; 
int main(){
    TamGiac<int, float> a(3,4,6); 
    cout << a.getChuvi() << " " << a.getDientich1() << endl; // " " << a.getDientich2() << endl; 
    TamGiac<float, double> b(3.5,4.5,5.5); 
    cout << b.getChuvi() << " " << b.getDientich1() << endl; // " " << b.getDientich2() << endl; 
    return 0; 
}

/*
    Viết một hàm có tên là numberToFile. Hàm nhận hai đối số: tên của file và một số nguyên n. 
    Hàm làm nhiệm vụ ghi n số của dãy số có quy luật cho dưới đây vào file nhị phân (không dùng file text). 
    Dãy số được tính toán như sau:
    f1 = 1;  	f2 = 1; 	fn = fn-1 + fn-2 
    - Viết một hàm khác có tên fileToNumber. Hàm này nhận ba đối số: tên của file, con trỏ 
    đến mảng kiểu int và một số nguyên count đại diện cho kích thước của mảng. Hàm này làm 
    nhiệm vụ đọc count số nguyên đầu tiên bên trong file rồi đưa vào mảng. 
    - Viết một chương trình hoàn chỉnh sử dụng các hàm trên bằng cách dùng hàm numberToFile 
    để ghi n số đầu tiên trong dãy f ở trên xuống file; sau đó sử dụng hàm fileToNumber để 
    đọc dữ liệu từ chính file đó vào một mảng. Sau đó hãy hiển thị nội dung của mảng lên 
    màn hình. 
*/

void numberToFile(string s, int n){
    int a[n]; 
    if (n > 0) a[0] = 1;
    if (n > 1) a[1] = 1; 
    for (int i = 2; i < n; i++)
        a[i] = a[i-1] + a[i-2]; 

    ofstream out (s, ios::binary); 
    if (!out) cout << "Loi\n"; 
    else{
        out.write(reinterpret_cast<char*> (a), n * sizeof(int)); 
        out.close(); 
    }
}
void fileToArray(string s, int * a, int n){
    ifstream in (s, ios::binary); 
    if (!in) cout << "Loi\n"; 
    else{
        in.read(reinterpret_cast<char*> (a), n*sizeof(int)); 
        in.close(); 
    }
}
int main(){
    int n = 5; 
    string s = "data.dat";
    numberToFile(s, n); 

    int a[n]; 
    fileToArray(s, a, n);

    for (int i = 0; i<n; i++) cout << a[i] << " "; 
    cout << endl; 

    return 0; 
}

