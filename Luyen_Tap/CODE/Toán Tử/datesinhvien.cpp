#include<iostream>
using namespace std ; 

class Date {
	private:
		int day, month, year;
		void temp(){
			if(day > 30) {
				month++ ; 
				day = day - 30 ;
			}
			if(month > 12 ) year++ ; 
			month = month - 12 ; 
		}
	public:
		Date() { };
		Date(int _day, int _month, int _year) {
			day = _day;
			month = _month;
			year = _year;
			temp();
		}
		Date operator+(const int &x){
			day += x ; 
			temp(); 
			return *this ; 
		}
		void print() const {
			cout << day << "/" << month << "/" << year << endl;
		}
};

class SinhVien{
    string id , name ; 
    Date p ;
	static int sum ; 
public:
	SinhVien(string masv , string ten, Date ngay){
		id= masv ; 
		name = ten ; 
		p = ngay ; 
		sum++ ; 
	}
	void print() const {
		cout << id << " " << name <<  " "  << endl ;
		p.print() ;  
	}
};
int SinhVien :: sum = 0 ; 
int main(){
	Date a(35 , 12 , 2022) ;
	// a.print() ; 
	SinhVien b("12434" , "aadsa" , a) ; 
	b.print() ;  
}