#include <iostream>
#include <cmath>

using namespace std;

void Wind(float, float, float&);


int main() {
    float v, t, w;
    cout << "ǳ��(m/sec): "; cin >> v;
    cout << "���(C) :"; cin >> t;

    Wind(v, t, w);
    cout << "�ٶ��ñ� : " << Wind(v,t) << endl;
    return 0;
}

//�Լ�����
//�ּҸ� �ְ�޴� ����:���۷���.
//w�� ���۷��� ������ ��.
//�ݹ��̹��,�ݹ��̷��۷��� �Լ����� 2���� ���?
//���� �Ű�����(�Է°�)�� ���� ������ ���� �޴°���.
//float w �Լ������� �ּ�ȭ�� ������ ���� �Լ����� ���۷��������� �����ؼ�. ���п� return ���� �����.

void float Wind(float v, float t, float& w) { 
    w = 33 - (10 * sqrt(v) - v + 10.5) * (33 - t) / 23.1;
}
