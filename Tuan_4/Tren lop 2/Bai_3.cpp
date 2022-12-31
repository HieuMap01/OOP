/*
- Thế hệ Boomer sinh vào những năm 50s, 60s. Gen X sinh từ 1965 đến 1980. 
Gen Y/Millenial sinh từ 1981 đến 1996. Gen Z sinh từ 1997 đến 2012.
    - Hoàn toàn giả định, coi là các thế hệ này có thái độ khác nhau về thịt chó.
        + Với Boomer, mọi người đều ăn, mọi người đều thích
        + Với Gen X, mọi người đều ăn, nhưng thích thì ngẫu nhiên tuỳ người.
        + Với Gen Y, ăn thì ngẫu nhiên tuỳ người, không ai thích
        + Với gen Z, không ai ăn lẫn thích thịt chó.
        + Thiết kế các lớp Boomer, GenX, GenY, GenZ thể hiện sự biến đổi quan niệm (giả định) trên
- Lớp Boomer:
    + hàm eatDog in ra “I eat dogs”; hàm likeEatingDog in “I like eating dogs”;
- GenX kế thừa Boomer, bổ sung:
    + Hằng tên like, có 1 hàm tạo sẽ khởi tạo nó bằng một số ngẫu nhiên 1/0
    + Tái định likeEatingDog sẽ tuỳ like là 0/1 mà in ra “I like eating dogs”, hay “I dont like eating dogs”.
- GenY kế thừa genX:
    + Hằng tên eat, có 1 hàm tạo khởi tạo like là 0, còn eat bằng ngẫu nhiên 0/1
    + tái định eatDog sẽ tuỳ hằng eat mà in ra “I eat dogs” hay “I dont eat dogs”.
    + tái định likeEatingDog để không đối tượng genY nào gọi được hàm này
- GenZ kế thừa genY
    + Tái định eatDog để không genZ nào gọi được hàm này.
- Tự bổ sung setter getter và các hàm tạo khác nếu thấy cần thiết, rồi demo các lớp trên
*/

#include<iostream>
#include <cstdlib>
#include <time.h>
using namespace std;

class Boomer{
    public:
        void eadDog(){
            cout << "I eat dogs\n";
        }
        void likeEatingDog(){
            cout << "I like eating dogs\n";
        }
};
class GenX: public Boomer{
    public:
    int like = rand() % (1 - 0 + 1) + 0;
    void likeEatingdog(){
        if(like == 0) cout << "I like eating dogs\n";
        else cout << "I dont like eating dogs\n";
    }
};
class GenY: public GenX{
    int eat;
    void ngaunhien(){
        int like = 0;
        eat = rand() % (1 - 0 + 1) + 0;
    }
    void eadDog(){
        if(eat == 0) cout << "I eat dogs\n";
        else cout << "I dont eat dogs\n";
    }
    void likeEatingdog(){}
};

int main()
{
	srand(time(NULL));
}