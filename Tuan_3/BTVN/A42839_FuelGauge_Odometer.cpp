/*
4. FuelGauge & Odometer: 
Ở bài này, bạn sẽ thiết kế các lớp để mô phỏng đồng hồ đo nhiên liệu và đồng hồ đo đường đi của ô tô. 
Các lớp cần xây dựng là: 
Lớp FuelGauge mô phỏng đồng hồ đo nhiên liệu và có thể làm những việc sau: 
    •	Mô phỏng một đồng hồ đo với một lượng nhiên liệu hiện tại nào đó, đơn vị gallon. 
    •	Báo cáo lượng nhiên liệu còn lại của xe theo thời gian, bằng đơn vị gallon. 
    •	Tăng lượng nhiên liệu hiện tại thêm 1 gallon, mô phỏng việc đổ nhiên liệu vào cho xe ô tô. 
    (Với khả năng chứa tối đa của xe ô tô là 15 gallon.) 
    •	Giảm lượng nhiên liệu hiện tại đi 1 gallon, nếu lượng nhiên liệu còn lại trong xe lớn hơn 0 gallon. 
    Điều này mô phỏng việc đốt cháy nhiên liệu khi xe ô tô chạy. 
Lớp Odometer mô phỏng đồng hồ đo đường đi của ô tô và có nhiệm vụ sau:  
    •	Mô phỏng một đồng hồ với số dặm hiện tại nào đó. 
    •	Báo cáo số dặm hiện tại theo thời gian 
    •	Tăng số dặm hiện tại lên 1. Giá trị tối đa của số dặm có khả năng hiển thị là 999,999 dặm. 
    Khi đạt được số dặm ở mức này, đồng hồ sẽ chuyển về hiện thị số dặm bằng 0. 
    •	Có khả năng tương tác với đối tượng FuelGauge. Nó sẽ làm giảm số nhiên liệu hiện tại 
của đối tượng FuelGauge đi 1 gallon mỗi khi xe đi được 24 dặm, ứng với xe ô tô đi 24 dặm sẽ tiêu tốn 1 gallon. 
Mô phỏng các lớp trên bằng việc tạo ra các thể hiện của mỗi lớp. Mô phỏng việc đổ nhiên liệu cho ô tô, 
và sau đó chạy một vòng lặp để tăng số dặm xe chạy được cho đến khi hết sạch nhiên liệu. 
rong khi mỗi vòng lặp được thực hiện, hãy in ra số dặm hiện tại của xe và lượng nhiên liệu mà nó chứa.  
*/

#include<iostream>
#include<string>
using namespace std;

/*Lớp FuelGauge mô phỏng đồng hồ đo nhiên liệu và có thể làm những việc sau: 
    •	Mô phỏng một đồng hồ đo với một lượng nhiên liệu hiện tại nào đó, đơn vị gallon. 
    •	Báo cáo lượng nhiên liệu còn lại của xe theo thời gian, bằng đơn vị gallon. 
    •	Tăng lượng nhiên liệu hiện tại thêm 1 gallon, mô phỏng việc đổ nhiên liệu vào cho xe ô tô. 
    (Với khả năng chứa tối đa của xe ô tô là 15 gallon.) 
    •	Giảm lượng nhiên liệu hiện tại đi 1 gallon, nếu lượng nhiên liệu còn lại trong xe lớn hơn 0 gallon. 
    Điều này mô phỏng việc đốt cháy nhiên liệu khi xe ô tô chạy. */

class FuelGauge{
	double fuel;
public:
	FuelGauge(double=0);
	FuelGauge operator++();
	FuelGauge operator++(int);
	FuelGauge operator--();
	FuelGauge operator--(int);
	bool isFull();
	bool isEmpty();
	double* getFuel();
	void showFuel();
};
FuelGauge::FuelGauge(double n){
	while(n > 15 || n < 0){
		cout << "Invalid value, enter again(0-15): ";
		cin >> n;
	}
	fuel = n;
}
FuelGauge FuelGauge::operator++(){
	if(!isFull()) this->fuel++;
	return *this;
}
FuelGauge FuelGauge::operator++(int){
	FuelGauge temp = *this;
	++*this;
	return temp;
}
FuelGauge FuelGauge::operator--(){
	if(!isEmpty()) this->fuel--;
	return *this;
}
FuelGauge FuelGauge::operator--(int){
	FuelGauge temp = *this;
	--*this;
	return temp;
}
bool FuelGauge::isFull(){
	if(fuel >= 15) return true;
	return false;
}
bool FuelGauge::isEmpty(){
	if(fuel <= 0) return true;
	return false;
}
double* FuelGauge::getFuel(){
	return &fuel;
}
void FuelGauge::showFuel(){
	cout << "Current amount of fuel is " << fuel << " gallons." << endl;
}

/*Lớp Odometer mô phỏng đồng hồ đo đường đi của ô tô và có nhiệm vụ sau:  
    •	Mô phỏng một đồng hồ với số dặm hiện tại nào đó. 
    •	Báo cáo số dặm hiện tại theo thời gian 
    •	Tăng số dặm hiện tại lên 1. Giá trị tối đa của số dặm có khả năng hiển thị là 999,999 dặm. 
    Khi đạt được số dặm ở mức này, đồng hồ sẽ chuyển về hiện thị số dặm bằng 0. 
    •	Có khả năng tương tác với đối tượng FuelGauge. Nó sẽ làm giảm số nhiên liệu hiện tại 
của đối tượng FuelGauge đi 1 gallon mỗi khi xe đi được 24 dặm, ứng với xe ô tô đi 24 dặm sẽ tiêu tốn 1 gallon. */

class Odometer{
	int milage;
	FuelGauge fuel;
public:
	Odometer(double=0, FuelGauge=(15));
	Odometer operator++();
	Odometer operator++(int);
	bool isMax();
	double getMilage();
	FuelGauge* getFuelCar();
	void showMilage();
};
Odometer::Odometer(double n, FuelGauge f){
	fuel = f;
	while(n > 999999){
		cout << "Invalid value, enter again(0-999999): ";
		cin >> n;
	}
	milage = n;
}
Odometer Odometer::operator++(){
	if(!isMax()){
		this->milage++;
	}
	else{
		this->milage = 0;
	}
	return *this;
}
Odometer Odometer::operator++(int){
	Odometer temp = *this;
	++*this;
	return temp;
}
bool Odometer::isMax(){
	if(milage > 999999) return true;
	return false;
}
double Odometer::getMilage(){
	return milage;
}
FuelGauge* Odometer::getFuelCar(){
	return &fuel;
}
void Odometer::showMilage(){
	cout << "Current milage: " << milage << endl;
}

int main(){
	int mileCount = 0;
	FuelGauge fuel(15);
	Odometer mile = Odometer(0, fuel);
	while(!mile.getFuelCar()->isEmpty()){
		mile++;
		mileCount++;
		mile.showMilage();
		mile.getFuelCar()->showFuel();
		if(mileCount == 24){
			(*mile.getFuelCar())--;
			mileCount = 0;
		}
	}
	cout << "Fuel is out!" << endl;
	return 0;
}