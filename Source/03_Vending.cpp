#include <iostream>
using namespace std;

int main() {
    int sellMoney, insertMoney, change, change_1000won, change_100won;

    cout << "얼마짜리를 자판기에서 구매하실껀가요?"; cin >> sellMoney;
    cout << "얼마를 자판기에 넣으셨습니까?"; cin >>insertMoney;

    //cout << sellMoney << "," << insertMoney << endl;

    change = insertMoney - sellMoney;
    change_1000won = change / 1000;
    cout << "1,000원짜리 잔돈은 " << change_1000won << "장 입니다." << endl;

    change = change - change_1000won*1000;

    //cout << "미반환 거스름 돈은" << change << "원 입니다." << endl;
    change_100won = change / 100;
    cout << " 100원짜리 잔돈은 " << change_100won << "개 입니다." << endl << "좋은하루 되세요.";
    return 0;
}
