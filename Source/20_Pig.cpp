#include <iostream>
using namespace std;

class Pig {
private:
    int money;
    int ten, five, one;
public:
    void setZero() {
        money = ten = five = one = 0;
    }

    int getMoney() { return money; }
    int getTen() { return ten; }
    int getFive() { return five; }
    int getOne() { return one; }

    void deposit(int t, int f, int o) { // 입금.
        int save;
        save = 10000 * t + 5000 * f + 1000 * o;
        money += save;
        ten += t;
        five += f;
        one += o;
    }
    void withdraw(int t, int f, int o) { // 출금.
        int save;
        save = 10000 * t + 5000 * f + 1000 * o;
        if(money >= save) {
            money -= save;
            ten -= t;
            five -= f;
            one -= o;
        }
        else cout << "Error: 돈이 부족합니다.";
    }
};

int main() {
    cout << "이 프로그램은 저금하는 프로그램입니다." << endl;

    Pig pig; // pig 클래스, pig 객체 변수.

    pig.setZero(); // 0으로 초기화
    pig.deposit(1, 3, 8);
    pig.deposit(0, 1, 6);
    cout << "저금액 = " << pig.getMoney() << "원" << endl;

    pig.withdraw(0, 0, 3);
    cout << "저금액(pig) = " << pig.getMoney() << "원" << endl;
    cout << "10000 : " << pig.getTen() << endl;
    cout << " 5000 : " << pig.getFive() << endl;
    cout << " 1000 : " << pig.getOne() << endl;


    Pig pink_pig;
    pink_pig = pig;
    //Pig& pink_pig = pig; // 래퍼런스로 선언.
    pink_pig.deposit(2, 1, 0);
    cout << "저금액(pink_pig) = " << pink_pig.getMoney() << "원" << endl;
    cout << "10000 : " << pink_pig.getTen() << endl;
    cout << " 5000 : " << pink_pig.getFive() << endl;
    cout << " 1000 : " << pink_pig.getOne() << endl;


    return 0;

}
