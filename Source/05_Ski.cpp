#include <iostream>
using namespace std;

/*
    종일권      반일권     야간권
성인 65,000   45,000   28,000

1. 종류(전일권, 반일권, 야근권
2. 인원:3일
3. 금액 = ?
*/

int main() {
    string liftList;
    int cache = 0;
    int people;

    cout << "몇 명이서 오셨어요?"; cin >> people;

    for(int i = 0; i < people; i ++) {
        cout << "종일권,반일권,야간권 중에 선택하세요."; cin >> liftList;

        if(liftList == "종일권") cache = 650000 + cache;
        else if (liftList == "반일권") cache = 450000 + cache;
        else if (liftList == "야간권") cache = 280000 + cache;
        else {
            cout << "종류 선택 오류입니다.";
            return 0;
        }
    }

    cout << "금액은: " << cache << "원 입니다.";
    return 0;
}
