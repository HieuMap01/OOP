#include<iostream>
#include<fstream>
using namespace std;
struct sach{
    char name_B[30], name_tg[20];
    int year_xb, trang;
};

int main(){
    //-----A--------
    // sach s = {"No Name", "Hieu", 2022, 1096};
    // ofstream out("SinhVien.dat", ios::binary);
    // if(out)
    // {
    //     out.write(reinterpret_cast <char *> (&s), sizeof(s));
    //     out.close();
    // }
    // sach s2;
    // ifstream in("SinhVien.dat", ios::binary);
    // if(in)
    // {
    //     in.read(reinterpret_cast <char *> (&s2), sizeof(s2));
    //     in.close();
    // }
    // cout << s2.name_B << " " << s2.name_tg << " " << s2.year_xb << " " << s2.trang << endl;

    // //------B------

    // const int n = 10;
    // sach s[] = {{"No Name 1", "Hieu", 2022, 1096},{"No Name 2", "Hieu", 2023, 102},
    //             {"No Name 3", "Hieu", 2062, 1026},{"No Name 4", "Hieu", 2020, 16},
    //             {"No Name 5", "Hieu", 2052, 1046},{"No Name 6", "Hieu", 2028, 196},
    //             {"No Name 7", "Hieu", 2042, 1066},{"No Name 8", "Hieu", 2021, 109},
    //             {"No Name 9", "Hieu", 2012, 1036},{"No Name 10", "Hieu", 2024, 126},};
    // ofstream out("Sach.dat", ios::binary);
    // if(out)
    // {
    //     out.write(reinterpret_cast <char *> (s), n*sizeof(sach));
    //     out.close();
    // }
    // sach s2[n];
    // ifstream in("Sach.dat", ios::binary);
    // if(in)
    // {
    //     in.read(reinterpret_cast <char *> (s2), n*sizeof(sach));
    //     in.close();
    // }
    // for(int i = 0; i<10 ; i++){
    //     cout << s2[i].name_B << " " << s2[i].name_tg << " " << s2[i].year_xb << " " << s2[i].trang << endl;
    // }
    
    // câu c
    int n; 
    cout << "n: "; cin >> n; 
    sach a[n]; 
    for (int i = 0; i<n;i++){
        cout << i << ": "; 
        cin.ignore();   // cin >> n ở trên sẽ để lại enter mà cin.getline ở sau lại nuốt được enter
        cin.getline(a[i].name_B, 100); // cin.getline(tên mảng, kích thước mảng) sẽ đọc xâu chứa dấu cách mà kiểu char[]; 
        cin.getline(a[i].name_tg, 40);  
        cin >> a[i].year_xb >> a[i].trang; 
    }
    ofstream out ("sach2.dat", ios::binary); 
    if (out){
        out.write(reinterpret_cast<char*> (a), n * sizeof(sach)); 
        out.close(); 
        sach b[n]; 
        ifstream in ("sach2.dat", ios::binary); 
        in.read(reinterpret_cast <char*> (b), n * sizeof(sach)); 
        in.close(); 
        int count = 0; 
        for (int i = 0; i<n; i++){
            cout << b[i].name_B << endl << b[i].name_tg << endl << b[i].year_xb << endl << b[i].trang << endl; 
            if (b[i].year_xb == 2022) count++; 
        }
        cout << "So sach xuat ban nam 2022: " << count << endl; 
    }
    return 0;
}