#include <iostream>
using namespace std;

int main() {
    int a=5, b=9;
    //p�� ���۷��� ����. �ݵ�� ������ ������ �ʱ�ȭ.
    int& rfr=a;
    int* ptr;

    cout << "a = " << a << endl;
    //���� ����Ǵ� ���� a ������.
    rfr++;
    cout << "rfr = " << rfr << endl;

    //������ ������ ����Ű�� ����� ������ �� ����.
    ptr = &a;
    cout << "ptr = " << *ptr << endl;


    //q�� b������ ����Ŵ.
    ptr = &b;
    cout << "b = " << b << endl;
    (*ptr)--;

    cout << "ptr = " << *ptr << endl;

    //p�� b�� ����Ű�°� �ƴϰ� b�� ���� ������ ��.
    cout << "rfr = " << rfr << endl;
    cout << "a = " << a << endl;

    //���۷��� ������ ����Ű�� ������ ������ �� ����.
    //rfr=&b
    return 0;
}
