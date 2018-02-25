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

    void deposit(int t, int f, int o) { // �Ա�.
        int save;
        save = 10000 * t + 5000 * f + 1000 * o;
        money += save;
        ten += t;
        five += f;
        one += o;
    }
    void withdraw(int t, int f, int o) { // ���.
        int save;
        save = 10000 * t + 5000 * f + 1000 * o;
        if(money >= save) {
            money -= save;
            ten -= t;
            five -= f;
            one -= o;
        }
        else cout << "Error: ���� �����մϴ�.";
    }
};

int main() {
    cout << "�� ���α׷��� �����ϴ� ���α׷��Դϴ�." << endl;

    Pig pig; // pig Ŭ����, pig ��ü ����.

    pig.setZero(); // 0���� �ʱ�ȭ
    pig.deposit(1, 3, 8);
    pig.deposit(0, 1, 6);
    cout << "���ݾ� = " << pig.getMoney() << "��" << endl;

    pig.withdraw(0, 0, 3);
    cout << "���ݾ�(pig) = " << pig.getMoney() << "��" << endl;
    cout << "10000 : " << pig.getTen() << endl;
    cout << " 5000 : " << pig.getFive() << endl;
    cout << " 1000 : " << pig.getOne() << endl;


    Pig pink_pig;
    pink_pig = pig;
    //Pig& pink_pig = pig; // ���۷����� ����.
    pink_pig.deposit(2, 1, 0);
    cout << "���ݾ�(pink_pig) = " << pink_pig.getMoney() << "��" << endl;
    cout << "10000 : " << pink_pig.getTen() << endl;
    cout << " 5000 : " << pink_pig.getFive() << endl;
    cout << " 1000 : " << pink_pig.getOne() << endl;


    return 0;

}
