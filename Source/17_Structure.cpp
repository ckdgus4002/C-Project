#include <iostream>

using namespace std;

// ����ü ����.
struct Data {
    int year, month, day;
};

// ����ü�� ���� �ϳ��� �ްڴ�.
void f(Data dd, Data* dp) {
    cout << "Date: " << dd.year << "." << dd.month << "." << dd.day << endl;
    dd.year = 2016;
    dd.month = 12;
    dd.day = 21;
    // CallByReferences �� ������ ->, Value�� ������ . ����.
    dp->year = 2015;
    dp->month = 8;
    dp->day = 12;
    cout << "Date: " << dd.year << "." << dd.month << "." << dd.day << endl;

    // ����ü������ ��ȯ ����.
    return dd;
}


int main() {
    // ����ü���� ����� �ʱ�ȭ.
    Data d1 = {2017,  9, 12};
    Data d2 = {2017, 11, 11};

    // CallByReferences (d2 -> dp)
    // CallByValue (d1 -> dd)
    d1 = f(d1, &d2);


    // ������� �����ҷ��� ��(.)�����ڷ� ����.
    cout << "D1: " << d1.year << "." << d1.month << "." << d1.day << endl;
    cout << "D2: " << d2.year << "." << d2.month << "." << d2.day << endl;
    return 0;
}
