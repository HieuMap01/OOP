/*
Viết lại các toán tử từng viết sau nhưng lần này như hàm bạn bè:
Lớp Cat,

*/
#include<iostream>
using namespace std;

class dog{
    string name;
    int age;
    double weight;
    public:
       dog(string name, int age, double weight):name(name), age(age), weight(weight){}
       

    
};

class Cat{
    string name;
    int age;
    float weight;
    bool chase() const { return rand() % 2; }
    static int count;
    public:
        Cat(){
        setInfor("Bibi", 1, 2);
        count++;
        }
        Cat(string n, int a){
        setInfor(n, a, 2);
        count++;
        }
        Cat(string n, int a, float w){
        setInfor(n, a, w);
        count++;
        }
        Cat (const Cat & r)
        {
        setInfor (r.name, r.age, r.weight);
        count++;
        }
        void setInfor(string n, int a, float w){
        name = n;
        age = a;
        weight = w;
        }
        string getName() const { return name; }
        int getAge() const { return age; }
        float getWeight() const { return weight; }
        void print() const{
        cout << name << " " << age << " " << weight << endl;
        }
        void meow() const {}
        int chaseMouse(int n) const;
        static int getCount() {return count; }
        //Toán tử + 2  conmèo cho ra một con mèo có tên, tuổi trùng con thứ nhất và cân bằng tổng cân 2 mèo
        friend Cat operator+(Cat l, Cat r){
            return Cat(l.name, l.age, l.weight + r.weight);
        }
        // Toán tử + một con mèo với số thực trả về một con mèo có tên tuổi trùng con mèo kia và cân bằng
        // số cân mèo đó cộng với số thực
        friend Cat operator+(Cat l, double a){
            return Cat(l.name, l.age, l.weight + a);
        }
        //Toán tử gán một con mèo bằng y hệt một con mèo khác
        friend Cat operator==(Cat l, Cat r){
            l.name = r.name;
            l.age = r.age;
            l.weight = r.weight;
            return l;
        }
        //Toán tử ==so sánh 2 con mèo có bằng tuổi
        friend bool operator==(Cat &l, Cat &r){
            return(l.age == r.age);
        }
        //Toán tử ++ tiền tố, hậu tố khiến một con mèo béo lên gấp đôi
        friend Cat & operator++(Cat &l){
            l.weight*=2;
            return l;
        }
        // friend Cat & operator++(Cat &l, int){
        //     Cat tmp = l;
        //     l.weight*=2;
        //     return tmp;
        // }
        /*
        >> một con mèo: sẽ vớt từ dòng nhập lần lượt một xâu, một số thực, một số nguyên
        rồi lưu vào các biến name, age, weight của con mèo đó
        << một con mèo: sẽ in ra lời giới thiệu nó tên gì, bao tuổi, bao cân
        */
        // friend istream & operator >> (istream & in, Cat & r){
        // in >> r.name >> r.age >> r.weight;
        // return in;
        // }
        // friend ostream & operator << (ostream & out, const Cat & r){
        // out << "Meo ten la: " << r.name << " " << r.age << " " << r.weight << endl;
        /*
         >> một con mèo: sẽ vớt từ dòng nhập một xâu lưu vào biến name, còn lại tự gán mèo 1 tuổi và nặng 2 kg.
        << một con mèo: sẽ in ra tên kèm tuyên bố mèo không có nghĩa vụ phải nói tuổi và cân của nó ở nơi công cộng.
        */
        friend istream & operator >> (istream & in, Cat & r){
            in >> r.name;
            r.age = 1;
            r.weight = 2;
            return in;
        }
        friend ostream & operator << (ostream & out, const Cat & r){
            out << "Meo ten la: " << r.name <<" va toi khong noi tuoi va can nang loi cong cong." <<endl;
            return out;
        }
                    //toan tu chuyen kieu
        // Ép một con mèo thành số nguyên chính là tuổi của nó
        // Ép một con mèo thành xâu chính là tên của nó
        operator int(){return age;}
        operator string(){return name;}
        operator dog(){
            // return dog(name, age+1, weight*2);
        }

        // Lớp Cat: Viết thêm các hàm tạo chuyển kiểu sau:
        // Ép kiểu string thành một con mèo tên đó, tuổi 1, cân là 2
        // Ép kiểu int thành một con mèo tuổi đó, tên Bibi, cân là 2
        // Ép kiểu float thành một con mèo cân đó, tên Bibi, tuổi 1
        Cat (string n): name(n), age(1), weight(2){}
        Cat (int n): name("BILI"), age(n), weight(2){}
        Cat (float n): name("bibi"), age(1), weight(n){}

};
int Cat::count = 0;

// Viết một lớp Dog có thành viên là tên, tuổi, hàm tạo 2 tham số,
// Rồi viết hàm ép kiểu một con mèo thành một con chó cùng tên, tuổi thêm 1, cân gấp đôi.


int main(){
    Cat a("bili",5,12);
    // cout << "Nhap vao 1 con meo: "; cin >> a;
    // cout << a << endl;
    cout << int(a);
    cout << string(a);
    
    return 0;
}