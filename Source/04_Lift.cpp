#include <iostream>
using namespace std;

int main() {
    int lift, people, pay = 0, total = 0;
    while(true) {
        cout << "종류( 1.전일, 2.반일, 3.야간 0.끝) :"; cin >> lift;
        if(lift == 0) break;
        cout << "인원: "; cin >> people;

        if(lift == 1) pay = people * 65000;
        else if (lift == 2) pay = people * 45000;
        else if (lift == 2) pay = people * 28000;
        else {
            cout << "종류 선택 오류입니다.!!";
            continue;
        }
        total += pay;
    }
    cout << "요금은 " << total << "입니다." << endl;

    int coupon, saved;
    cout << "쿠폰: "; cin >> coupon;
    if(coupon > 3) coupon = 3;
    saved = total + coupon / 10.0;
    cout << ( coupon * 10) << "%할인액 = " << saved << endl;
    cout << "결제금액 = " << (total - saved) << endl;
    return 0;
}
