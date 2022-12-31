/*
4.Inventory 
Viết struct Inventory mô tả dữ liệu về hàng tồn kho như sau: 
    •Mô tả món hàng
    •Số lượng 
    •Chi phí bán buôn
    •Chi phí bán lẻ
    •Ngày được thêm vào kho
Các thông tin Inventory sau sẽ được lưu vào tệp 
    
    b.Viết chương trình đọc dữ liệu trong tệp Inventory từ đó tính toán và hiển thị các dữ liệu sau:
        •Tổng giá trị bán buôn của hàng tồn kho
        •Tổng giá trị bán lẻ của hàng tồn kho
        •Tổng số lượng của tất cả các mặt hàng trong kho
*/

#include<iostream>
using namespace std;
#include<fstream>

/*
Viết struct Inventory mô tả dữ liệu về hàng tồn kho như sau: 
    •Mô tả món hàng
    •Số lượng 
    •Chi phí bán buôn
    •Chi phí bán lẻ
    •Ngày được thêm vào kho
*/

struct Inventory
{
    char Name[50];
    int quantity;
    int whlCost;
    int rtlCost;
    char day[15];
};
/*
a.Viết chương trình hiển thị menu cho phép người dùng thực hiện các tác vụ sau:
        •Thêm bản ghi Inventory mới vào tệp.
        •Hiển thị bất kỳ bản ghi nào trong tệp.
        •Thay đổi bất kỳ bản ghi nào trong tệp.
*/
int menu()
{
    int choice;
    cout << "-------Menu-------" << endl;
    cout << "1. Them ban ghi moi."<<endl;
    cout << "2. Xem ban ghi."<<endl;
    cout << "3. Thay doi ban ghi"<<endl;
    cout << "4. Exit"<<endl;
    cout << endl;
    cout << "Nhap lua chon(1-4): ";
    cin>>choice;
    while(choice < 1 || choice > 4)
    {
    cout<<"Lua chon khong hop le!"<<endl;
    cout<<"Vui long nhap lai lua chon(1-4): ";cin >> choice;
    }
    cout << endl;
    return choice;
}

void addIn (fstream & file) // hàm thêm thông tin mới vào kho
{
    cout << "Nhap du lieu cho kho sau:" << endl;
    fstream inventory("Inventory.dat", ios :: out | ios :: binary);
    Inventory I;
    // Nhập dữ liệu mới
    cout << "Mo ta: ";
    cin.ignore ();
    cin.getline (I.Name, 51);
    cout <<"So luong: ";cin >> I.quantity;
    cout << "Chi phi ban buon: ";cin >> I.whlCost;
    cout << "Gia ban le: ";cin >> I.rtlCost;
    cout << "Ngay duoc them vao (o dang 00/00/0000): ";
    cin >> I.day;
    if(inventory){
        inventory.write (reinterpret_cast <char *> (& I), sizeof (I));
        cout << "Ban ghi duoc them vao tep." << endl;
        file.close ();
    }
}


void dispIn(fstream &file)  
{  
    fstream inventory ("Inventory.dat", ios::out | ios::binary);  
    Inventory I;  
    long a;  
    cout << "Nhap so ban ghi de xem:";  
    cin >> a;  

    // doc du lieu.  

    inventory.seekg(a * sizeof(I), ios::beg);  
    inventory.read(reinterpret_cast<char *>(&I),sizeof(I));  
    
    cout << "Mo ta: " << I.Name << endl;  
    cout << "So luong: " << I.quantity << endl;  
    cout << "Chi phi ban buon: " << I.whlCost << endl;  
    cout << "Gia ban le: " << I.rtlCost << endl;  
    cout << "Ngay duoc them vao: " << I.day << endl;  
    
    if(file.fail()) file.clear();  
    file.close();  

}

void chgIn(fstream &file)								
{  

    fstream inventory ("InventoryFile.dat", ios::out | ios::binary);  
    Inventory I;   
    long a;  
    cout << "Nhap ban ghi ban muon thay doi: ";  
    cin >> a;										 
    inventory.seekg(a * sizeof(I), ios::beg);  
    inventory.read(reinterpret_cast<char *>(&I),sizeof(I));  

    cout << "Mo ta: " << I.Name << endl;  
    cout << "So luong: " << I.quantity << endl;  
    cout << "Chi phi ban buon: " << I.whlCost << endl;  
    cout << "Gia ban le: " << I.rtlCost << endl;  
    cout << "Ngay duoc them vao: " << I.day << endl;    

    inventory.seekp(a * sizeof(I), ios::beg);  

    inventory.write(reinterpret_cast<char *>(&I),sizeof(I));  

    inventory.close();   
}

 int main()  

 { 
    long selection;									
	int menu();
    fstream inventory ("Inventory.dat", ios::in | ios::out | ios::binary);  
    Inventory record = {" ", 0, 0.0};   
    cout<<"Inventory Managment"<<endl;  
    for (int count = 0; count < 5; count++)  
    {
       inventory.write(reinterpret_cast<char *>(&record),sizeof(record));  
    }  
    inventory.close();  
    inventory.open("Inventory.dat", ios::out | ios::binary);  
		 while (selection != 4) 
    {  
       switch(selection)  
        {  
		case 1:													 
            {  
                addIn(inventory);  
                break;  
            }  
        case 2:													 
            {  
			    dispIn(inventory);  
                break;  
            }  
        case 3:													
            {  
                chgIn(inventory);  
                break;  
            }  
        default:												
            {  
                cout << "Invalid selection" << endl;  
            }  
            selection = menu();  
        }
    }               
    inventory.close();       
    return 0;  

 }  