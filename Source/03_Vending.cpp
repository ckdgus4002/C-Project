#include <iostream>
using namespace std;

int main() {
    int sellMoney, insertMoney, change, change_1000won, change_100won;

    cout << "��¥���� ���Ǳ⿡�� �����Ͻǲ�����?"; cin >> sellMoney;
    cout << "�󸶸� ���Ǳ⿡ �����̽��ϱ�?"; cin >>insertMoney;

    //cout << sellMoney << "," << insertMoney << endl;

    change = insertMoney - sellMoney;
    change_1000won = change / 1000;
    cout << "1,000��¥�� �ܵ��� " << change_1000won << "�� �Դϴ�." << endl;

    change = change - change_1000won*1000;

    //cout << "�̹�ȯ �Ž��� ����" << change << "�� �Դϴ�." << endl;
    change_100won = change / 100;
    cout << " 100��¥�� �ܵ��� " << change_100won << "�� �Դϴ�." << endl << "�����Ϸ� �Ǽ���.";
    return 0;
}
