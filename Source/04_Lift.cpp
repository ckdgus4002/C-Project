#include <iostream>
using namespace std;

int main() {
    int lift, people, pay = 0, total = 0;
    while(true) {
        cout << "����( 1.����, 2.����, 3.�߰� 0.��) :"; cin >> lift;
        if(lift == 0) break;
        cout << "�ο�: "; cin >> people;

        if(lift == 1) pay = people * 65000;
        else if (lift == 2) pay = people * 45000;
        else if (lift == 2) pay = people * 28000;
        else {
            cout << "���� ���� �����Դϴ�.!!";
            continue;
        }
        total += pay;
    }
    cout << "����� " << total << "�Դϴ�." << endl;

    int coupon, saved;
    cout << "����: "; cin >> coupon;
    if(coupon > 3) coupon = 3;
    saved = total + coupon / 10.0;
    cout << ( coupon * 10) << "%���ξ� = " << saved << endl;
    cout << "�����ݾ� = " << (total - saved) << endl;
    return 0;
}
