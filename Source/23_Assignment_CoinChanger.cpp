#include <iostream>
using namespace std;

//���Ǳ��� ���� �Ž����⸦ ������� �Ѵ�.
//���Աݾװ� ���űݾ��� �Է¹ް� �Ž������� ����� ����
//500��, 100��, 50��, 10�� ������ ������ �����Ѵ�.
//main �Լ��� ���� CoinChanger Ŭ������ �ϼ��Ѵ�.

class CoinChanger {
private:
    int fH, oH, fT, oT;
    int paid, buyed, change;
public:
//constructor
    CoinChanger(int fh, int oh, int ft, int t): fH(fh), oH(oh), fT(ft), oT(t) {
    }
//setter
    void setPaid(int p) {
        paid = p;
    }
    void setBuyed(int b) {
        buyed = b;
        change = paid - buyed; // ���Աݾ� - ���űݾ�
    }
//getter
    int getChange() {
        return change;
    }
//memberFunction
    bool is_changable() {
        if(change > fH*500 + oH*100 + fT*50 + oT*10) return false;
        else return true;
    }

    void coinChange() {
        // �Ž������� ���� ������ ������ �����Ͽ� ����Ѵ�. �̶� ���� ���� ���� �Ž����� ��ŭ ���ҽ�Ų��.
        cout << change / 500 << " / "; fH -= change/500; change -= (change/500) * 500;
        cout << change / 100 << " / "; oH -= change/100; change -= (change/100) * 100;
        cout << change /  50 << " / "; fT -= change/50; change -= (change/50) * 50;
        cout << change /  10;          oT -= change/10; change -= (change/10) * 10;
    }
};

int main() {
    CoinChanger cc(5,10,7,20);  // ���� ������ ������ �ʱ�ȭ �Ѵ�.
    int paid, buyed; // ���Աݾװ� ���űݾ� �Է� ����

    cout << "���Աݾװ� ���űݾ� : "; cin >> paid >> buyed;
    cc.setPaid(paid);
    cc.setBuyed(buyed);  // ���űݾ��� �����ϰ� �Ž������� ����� �д�.
    cout << "�Ž����� : " << cc.getChange() << "��" << endl;

    // ���� ���� ������ �Ž������� ������ �� �ִ��� �ƴ��� �Ǵ��Ѵ�. // true or false
    if(cc.is_changable()) {
        cout << "[500/100/50/10] : ";
        cc.coinChange();
    }
    else cout << "������ ������� �ʽ��ϴ�.";
    return 0;
}
