#include <iostream>
using namespace std;

int main() {
    string hitterName;
    int seatNumber, hitNumber;
    double hitRate;

    //�̱� ����ǥ(')�� ����, ���� ����ǥ(")�� ���ڿ��̴�.
    char c = 'P';
    hitterName = "Lee";
    bool ok = true;


    cout << "hitterName: ";
    cin >> hitterName;
    cout << "seatNumber And hitNumber: ";
    cin >> seatNumber >> hitNumber;

    //��ǻ�ʹ� ��� ���� ������Ÿ���� ���� ����. ������/�������� �Ǽ������� ����Ǳ� ���� ���������� �����Ѵ�.
    hitRate = hitNumber / seatNumber;
    cout << "hitRate is hitNumber/seatNumber." << endl;
    cout << "hitRate of " << hitterName << ": " << hitRate << "%" << endl;
    cout << "���α׷� ������!!\n";
    return 0;
}
