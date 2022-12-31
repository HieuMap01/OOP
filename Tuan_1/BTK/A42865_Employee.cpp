#include <iostream>
#include <iomanip>
#include <cstdlib>
using namespace std;
const int l = 20;
class Employee{
    string name = "";
    int idNumber = 0;
    string department = "";
    string position = "";
public:
    void setName(string n) {name = n;} 
    void setIdNumber(int id) {idNumber = id;}
    void setDepartment(string d) {department = d;}
    void setPosition(string p) {position = p;}
    string getName() const {return name;}
    int getIdNumber() const {return idNumber;}
    string getDepartment() const {return department;}
    string getPosition() const {return position;}

    Employee(){}
    Employee(string n, int id){
        this -> name = n;
        this -> idNumber = id;
        this -> department = "";
        this -> position = "";
    }
    Employee(string n, int id, string d, string p){
        this -> name = n;
        this -> idNumber = id;
        this -> department = d;
        this -> position = p;
    }
};
void Save(Employee & e, string n, int id, string d, string p){
    e.setName(n);
    e.setIdNumber(id);
    e.setDepartment(d);
    e.setPosition(p);
}
void Display(const Employee & e){ 
    cout << left << setw(l) << e.getName() << setw(l) << e.getIdNumber() << setw(l) << e.getDepartment() << setw(l) << e.getPosition() << endl;
}
int main(){
    cout << left << setw(l) << "Name" << setw(l) << "ID Number" << setw(l) << "Department" << setw(l) << "Position" << endl;
    Employee susan, mark, joy;
    Save(susan, "Susan Mayers", 47899, "Accounting", "Vice president");
    Save(mark, "Mark Jones", 39119, "IT", "Programmer");
    Save(joy, "Joy Rogers", 81774, "Manufacturing", "Engineer");
    Display(susan);
    Display(mark);
    Display(joy);
    return 0;
}