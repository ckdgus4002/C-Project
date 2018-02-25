#include <iostream>

using namespace std;

// 구조체 정의.
struct Data {
    int year, month, day;
};

// 구조체형 변수 하나를 받겠다.
void f(Data dd, Data* dp) {
    cout << "Date: " << dd.year << "." << dd.month << "." << dd.day << endl;
    dd.year = 2016;
    dd.month = 12;
    dd.day = 21;
    // CallByReferences 로 보내면 ->, Value로 보내면 . 으로.
    dp->year = 2015;
    dp->month = 8;
    dp->day = 12;
    cout << "Date: " << dd.year << "." << dd.month << "." << dd.day << endl;

    // 구조체변수는 반환 가능.
    return dd;
}


int main() {
    // 구조체변수 선언과 초기화.
    Data d1 = {2017,  9, 12};
    Data d2 = {2017, 11, 11};

    // CallByReferences (d2 -> dp)
    // CallByValue (d1 -> dd)
    d1 = f(d1, &d2);


    // 멤버변수 접근할려면 점(.)연산자로 접근.
    cout << "D1: " << d1.year << "." << d1.month << "." << d1.day << endl;
    cout << "D2: " << d2.year << "." << d2.month << "." << d2.day << endl;
    return 0;
}
