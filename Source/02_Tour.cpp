#include <iostream>

using namespace std;

int main() {
    cout << "ȯ���մϴ� ���� �������� ���� ����ð��� ����ϴ� ���α׷� �Դϴ�." << endl;
    int dist, speed;

    cout << "�Ÿ��� ������ �Է����ֽʽÿ�."; cin >> dist;
    cout << "�ӷ��� ������ �Է����ֽʽÿ�."; cin >> speed;
    double hours = (double)dist / (double)speed;

    int h = hours;
    int m = (hours - h) * 60;
    cout << "����ҿ�ð�:" << h << "�ð� �Դϴ�." << endl;
    cout << "����ҿ�ð�:" << m << "�� �Դϴ�." << endl;

    double gasRate = 10.8; //km/L
    int gasPrice = 1420;   //1420/L
    int gasTotal;

    gasTotal = dist / gasRate * gasPrice;
    cout << "�����: " << gasTotal << endl;

    return 0;
}
