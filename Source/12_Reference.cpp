#include <iostream>
using namespace std;

int main() {
    int a=5, b=9;
    //p는 래퍼런스 변수. 반드시 참조할 변수로 초기화.
    int& rfr=a;
    int* ptr;

    cout << "a = " << a << endl;
    //실제 변경되는 것은 a 변수임.
    rfr++;
    cout << "rfr = " << rfr << endl;

    //포인터 변수는 가리키는 대상을 변경할 수 없다.
    ptr = &a;
    cout << "ptr = " << *ptr << endl;


    //q가 b변수를 가리킴.
    ptr = &b;
    cout << "b = " << b << endl;
    (*ptr)--;

    cout << "ptr = " << *ptr << endl;

    //p가 b를 가리키는게 아니고 b의 값을 가지는 것.
    cout << "rfr = " << rfr << endl;
    cout << "a = " << a << endl;

    //래퍼런스 변수는 가리키는 변수를 변경할 수 없다.
    //rfr=&b
    return 0;
}
