/*
3.	ProductionWorkder & TeamLeader 
•	Xây dựng class TeamLeader (trưởng nhóm) kế thừa class ProductionWorker ở bài 1. 
Lớp này có thêm các thuộc tính như số giờ đào tạo tối thiểu hằng năm, số giờ đào tạo mà anh ta đã tham gia,  
số tiền thưởng hàng tháng. Quy tắc là nếu số giờ đào tạo trưởng nhóm tham gia >= 
số giờ đào tạo tối thiểu hằng năm thì anh ta nhận tiền thưởng hàng tháng là 5% lương thực lĩnh, 
nếu không thì tiền thưởng hàng tháng là 0. Hãy viết một hoặc nhiều hàm khởi tạo, các hàm set/get phù hợp 
•	Viết một chương trình minh họa sử dụng class trên. 
*/

#include<iostream>
using namespace std;

enum calam {
    AM = 1,
    PM
};
class ProductionWorker{
        int ca = AM, luong_h = 0, h_thang = 0;
    public:
        ProductionWorker(){}
        ProductionWorker( int c, int lh, int ht){
            setInfor(c,lh,ht);
        }
        int compute() const{
            return (ca == PM ? 1.5 : 1) * luong_h * h_thang;
        }
        void setInfor(int c, int lh, int ht){
            ca = c;
            luong_h = lh;
            h_thang = ht;
            compute();
        }
        int getCa() const {return ca;}
        int getLuong_h() const {return luong_h;}
        int getH_thang() const {return h_thang;}
        void print(){
            //ProductionWorker s;
            cout << "Ca: " << ca << endl
                 << "Luong theo gio: " << luong_h << endl
                 << "So gio lam viec trong thang: " << h_thang << endl
                 << "Tien luong thuc linh: " << compute()
                 << endl;
        }
};

/*
    Xây dựng class TeamLeader (trưởng nhóm) kế thừa class ProductionWorker ở bài 1. 
    Lớp này có thêm các thuộc tính như:
        số giờ đào tạo tối thiểu hằng năm, số giờ đào tạo mà anh ta đã tham gia, số tiền thưởng hàng tháng. 
        Quy tắc là nếu số giờ đào tạo trưởng nhóm tham gia >= số giờ đào tạo tối thiểu hằng năm 
        thì anh ta nhận tiền thưởng hàng tháng là 5% lương thực lĩnh, nếu không thì tiền thưởng hàng tháng là 0. 
        Hãy viết một hoặc nhiều hàm khởi tạo, các hàm set/get phù hợp 
*/
class Teamleader: public ProductionWorker {
    int gioDT_TT, gioDT_TG, tien_thuong;
    public:
        Teamleader(){}
        Teamleader(int c, int lh, int ht ,int g_tt, int g_tg){
            setInfor(c,lh,ht,g_tt,g_tg);
        }
        void setInfor(int c, int lh, int ht ,int g_tt, int g_tg){
            gioDT_TT =  g_tt;
            gioDT_TG = g_tg;
            ProductionWorker :: setInfor(c,lh,ht);
            if(g_tg>g_tt){
                tien_thuong = ProductionWorker :: compute() * 0.05;
            }
            else{
                tien_thuong = 0;
            }
        }

        int getGioDT_TT() const {return gioDT_TT;}
        int getGioDT_TG() const {return gioDT_TG;}
        int getTienthuong() const {return tien_thuong;}
        void print(){
            ProductionWorker::print();
            cout << "Gio dao tao toi thieu hang nam: " << gioDT_TT << endl
                 << "Gio dao tao da tham gia: " << gioDT_TG << endl
                 << "Tien Thuong hang thang: " << tien_thuong << endl;
        }

};

int main(){
    // ProductionWorker P( AM, 10, 200);
    // ProductionWorker C( PM, 10, 200);
    // P.print();
    // C.print();
    Teamleader T(PM, 10, 200, 13, 15);
    T.print();
    Teamleader Te(PM, 10, 200, 15, 13);
    Te.print();
    return 0;
    
}