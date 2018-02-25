#include <iostream>

using namespace std;

int main() {
    cout << "환영합니다 저는 여행지에 도착 예상시간을 계산하는 프로그램 입니다." << endl;
    int dist, speed;

    cout << "거리를 정수로 입력해주십시오."; cin >> dist;
    cout << "속력을 정수로 입력해주십시오."; cin >> speed;
    double hours = (double)dist / (double)speed;

    int h = hours;
    int m = (hours - h) * 60;
    cout << "예상소요시간:" << h << "시간 입니다." << endl;
    cout << "예상소요시간:" << m << "분 입니다." << endl;

    double gasRate = 10.8; //km/L
    int gasPrice = 1420;   //1420/L
    int gasTotal;

    gasTotal = dist / gasRate * gasPrice;
    cout << "연료비: " << gasTotal << endl;

    return 0;
}
