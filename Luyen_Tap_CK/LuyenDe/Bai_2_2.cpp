/*Cho lớp trừu tượng MangLoc (mảng lọc) , gồm các thành viên:  
•	Biến private: mô tả mảng (xâu), một mảng chứa nhiều nhất 100 phần tử (mảng số nguyên), số phần tử trong mảng (số nguyên)
•	Hàm khoiTao sẽ cập nhật biến mô tả mảng, đồng thời tự gán biến số phần tử mảng bằng 0
•	Hàm ảo thuần tuý thoaMan nhận vào một số nguyên và trả về số đó có thoả mãn điều kiện thêm vào mảng không, hàm này sẽ được cài 
đặt ở lớp con
•	Hàm them nhận vào một số nguyên, nếu thoả mãn điều kiện thêm vào mảng (dùng hàm thoaMan kiểm tra) thì thêm vào sau phần tử 
mảng cuối cùng và tăng số phần tử mảng thêm 1. 
•	Hàm hienThi in ra mô tả, số phần tử mảng, và toàn bộ mảng
Lớp MangLocUoc (mảng lọc ước) ứng với các mảng chỉ chấp nhận thêm vào các số là ước của một số cho trước. Lớp này kế thừa lớp 
MangLoc, có mô tả mặc định là “Mang loc uoc so” và gồm các thành viên sau:  
•	Một biến số nguyên tên la uoc (ước), để private, được xác định ngay khi tạo đối tượng
•	Ghi đè hàm thoaMan lớp cha để mảng chỉ chấp nhận thêm vào các số là ước của biến uoc
•	Ghi đè hàm hienThi lớp cha để lần lượt in ra mô tả, số phần tử mảng, toàn bộ mảng, và biến uoc
Lớp MangLocNgoaiKhoang (mảng lọc ngoài khoảng) ứng với các mảng chỉ chấp nhận thêm vào các số nằm ngoài một khoảng cho trước. 
Lớp này kế thừa lớp MangLoc, có mô tả mặc định là “Mang loc ngoai khoang” và gồm các thành viên sau:  
•	Hai biến số thực trai và phai, để private, được xác định ngay khi tạo đối tượng
•	Ghi đè hàm thoaMan lớp cha để mảng chỉ chấp nhận thêm vào các số nằm ngoài khoảng [trai, phai) 
(nghĩa là các số nguyên x < trai hoặc x >= phai)
•	Ghi đè hàm hienThi lớp cha để lần lượt in ra mô tả, số phần tử mảng, toàn bộ mảng, biến trai và biến phai
Viết hàm main tạo một mảng arr có tính đa hình gồm 5 phần tử MangLoc, sao cho gồm cả MangLocUoc và MangLocNgoaiKhoang, 
sau đó tạo một mảng gồm 20 số nguyên, rồi với mỗi phần tử của mảng arr, hãy thử thêm vào 20 số nguyên này. 
Cuối cùng in ra thông tin cả mảng arr dùng hàm hienThi
*/
#include<iostream>
using namespace std;

class MangLoc{
    string mota;
    int a[100], size;
    virtual bool thoaman(int a) const = 0;
    protected:
        void khoitao(string m){
            mota = m;
            size = 0;
        }
    public:
        void them(int x){
            if(thoaman(x)){
                a[size] = x;
                size++;
            }
        }
        virtual void Hienthi() const{
            cout << mota << " " << size << endl;
            for(int i = 0; i<size; i++){
                cout << a[i] << endl;
            }
            cout << endl;
        }
        virtual ~MangLoc(){}
};

/*Lớp MangLocUoc (mảng lọc ước) ứng với các mảng chỉ chấp nhận thêm vào các số là ước của một số cho trước. Lớp này kế thừa lớp 
MangLoc, có mô tả mặc định là “Mang loc uoc so” và gồm các thành viên sau:  
•	Một biến số nguyên tên la uoc (ước), để private, được xác định ngay khi tạo đối tượng
•	Ghi đè hàm thoaMan lớp cha để mảng chỉ chấp nhận thêm vào các số là ước của biến uoc
•	Ghi đè hàm hienThi lớp cha để lần lượt in ra mô tả, số phần tử mảng, toàn bộ mảng, và biến uoc*/

class MangLocUoc: public MangLoc{
    int uoc;
    bool thoaman(int a) const{
        return (uoc%a==0);
    }
    public:
        MangLocUoc(int u){
            khoitao("Mang loc uoc.");
            uoc = u;
        }
        void Hienthi() const{
            MangLoc::Hienthi();
            cout << uoc << endl;
        }
};

/*Lớp MangLocNgoaiKhoang (mảng lọc ngoài khoảng) ứng với các mảng chỉ chấp nhận thêm vào các số nằm ngoài một khoảng cho trước. 
Lớp này kế thừa lớp MangLoc, có mô tả mặc định là “Mang loc ngoai khoang” và gồm các thành viên sau:  
•	Hai biến số thực trai và phai, để private, được xác định ngay khi tạo đối tượng
•	Ghi đè hàm thoaMan lớp cha để mảng chỉ chấp nhận thêm vào các số nằm ngoài khoảng [trai, phai) 
(nghĩa là các số nguyên x < trai hoặc x >= phai)
•	Ghi đè hàm hienThi lớp cha để lần lượt in ra mô tả, số phần tử mảng, toàn bộ mảng, biến trai và biến phai
*/

class MangLocNgoaiKhoang: public MangLoc{
    float trai, phai;
    bool thoaman(int a) const{
        return (a<trai || a>=phai);
    }
    public:
        MangLocNgoaiKhoang(float t, float p){
            khoitao("Mang loc Ngoai Khoang.");
            trai = t;
            phai = p;
        }
        void Hienthi() const{
            MangLoc::Hienthi();
            cout << trai << " " << phai << endl;
        }
};
/*Viết hàm main tạo một mảng arr có tính đa hình gồm 5 phần tử MangLoc, sao cho gồm cả MangLocUoc và MangLocNgoaiKhoang, 
sau đó tạo một mảng gồm 20 số nguyên, rồi với mỗi phần tử của mảng arr, hãy thử thêm vào 20 số nguyên này. 
Cuối cùng in ra thông tin cả mảng arr dùng hàm hienThi*/
int main(){
    int n = 5;
    MangLoc *arr[] = {new MangLocUoc(3), new MangLocUoc(4),new MangLocUoc(5),
                    new MangLocNgoaiKhoang(3,6), new MangLocNgoaiKhoang(6,10)};
    int m = 20;
    int b[] = {1,2,3,4,5,6,7,8,9,10,11,12,13,14,15,16,17,18,19,20};
    for(int i = 0; i<n; i++){
        for(int j = 0; j<m; j++){
            arr[i]->them(b[j]);
        }
    }
    for(int i = 0; i<n; i++){
        arr[i]->Hienthi();
    }
    return 0;
}
