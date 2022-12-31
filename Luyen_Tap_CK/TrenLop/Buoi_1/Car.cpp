/*
3. Car Class
Viết một lớp có tên Car có các biến thành viên sau:
• yearModel: Một int lưu giữ mẫu xe của năm.
• make: Một sợi dây giữ phần tạo nên chiếc xe.
• speed: Một int giữ tốc độ hiện tại của ô tô. Ngoài ra, lớp phải có hàm tạo sau và các hàm thành viên khác.
• Hàm tạo (cấu tử): Nhà xây dựng nên chấp nhận yearModel của chiếc xe và đưa ra như các đối số. 
Các giá trị này phải được gán cho yearModel của đối tượng và tạo các biến thành viên. Hàm tạo cũng nên 
gán 0 cho các biến thành viên speed.
• Accessor: Hàm truy cập thích hợp để nhận các giá trị được lưu trữ trong các biến thành viên yearModel, 
make và speed của đối tượng.
• accelerate: Hàm accelerate nên thêm 5 vào biến thành viên speed mỗi khi nó được gọi.
• brake: Hàm brake sẽ trừ 5 cho biến speed mỗi khi nó được gọi.
Thể hiện lớp trong chương trình tạo đối tượng Car, sau đó gọi hàm accelerate năm lần. 
Sau mỗi lần gọi đến chức năng tăng tốc, lấy speed hiện tại của xe và hiển thị nó. 
Sau đó, gọi chức năng brake năm lần. Sau mỗi lần gọi đến chức brake, hãy lấy speed hiện tại của xe và hiển thị nó.
*/
#include<iostream>
using namespace std;

class car{
    int yearmodel;
    string make;
    int speed;
    public:
    car(int Y, string M, int S = 0)
    {
        yearmodel = Y;
        make = M;
        speed = S;
    }
    void  Accessor()const{
        cout << yearmodel << endl << make << endl << speed << endl;
    }
    int Accelerate()
    {
        speed += 5;
        return speed;
    }
    int brake()
    {
        speed -= 5;
        return speed;
    }
};

int main(){
    car c(2011,"nhua", 100000);
    for (int i = 0; i < 5; i++){
        c.Accelerate();
        c.Accessor();
    }
    for (int i = 0; i < 5; i++){
        c.brake();
        c.Accessor();
    }
}