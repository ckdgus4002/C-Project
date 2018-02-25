#include <iostream>
using namespace std;

class Circle {
private:
    float r;
public:
    Circle() {
        r = 0;
    }
    Circle(float a) {
        r = a;
    }
    void setRadius(float a) {
        r = a;
    }
    float getArea() {
        return r * r * 3.1415;
    }
};

int main() {
    Circle c(4); // ������ 4
    Circle *pc; // pc��  circle��ü�� ����Ű�� �����ͺ���.

    pc = &c;
    cout << "���� = " << pc->getArea() << endl; // �����ͺ����� �� ����� ȭ��ǥ.
    pc = new Circle(7); // ���� 7�� �� ��ü�� �� ������ ����.

    delete pc;

    int a = 5, b = 7;
    int *p, *q;

    p = &a; // p-> a (����)
    (*p)++; // ������.
    cout << "a: " << a << endl;

    // �����ڸ��� ���� ����� ���ڸ��� q �� �־��.
    // �� ������ �޸� �Ҵ�
    // q�� 1���� �迭�� �ȴ�.
    cout << "�迭 ����?"; cin >> b;
    q = new int[b]; // ���� �迭


    cout << "q: " << q << endl;
    q[0] = b;
    (*q)++;


    cout << "b: " << b << endl;
    cout << "*p: " << *p << endl;
    cout << "*q: " << *q << endl;
    cout << "q: " << q << endl;

    // ���� �Ҵ�� �޸𸮸� ����.
    // new�� ���������� delete ���ϸ� ������� ����.
    // �迭 �������  delete�ڿ� [] �ٿ�����.
    delete[] q;
    return 0;
}
