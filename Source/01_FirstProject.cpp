#include <iostream>
using namespace std;

int main() {
    string hitterName;
    int seatNumber, hitNumber;
    double hitRate;

    //싱글 따옴표(')는 문자, 더블 따옴표(")는 문자열이다.
    char c = 'P';
    hitterName = "Lee";
    bool ok = true;


    cout << "hitterName: ";
    cin >> hitterName;
    cout << "seatNumber And hitNumber: ";
    cin >> seatNumber >> hitNumber;

    //컴퓨터는 계산 전에 데이터타입을 먼저 본다. 정수형/정수형은 실수형으로 저장되기 전에 정수형으로 저장한다.
    hitRate = hitNumber / seatNumber;
    cout << "hitRate is hitNumber/seatNumber." << endl;
    cout << "hitRate of " << hitterName << ": " << hitRate << "%" << endl;
    cout << "프로그램 종료함!!\n";
    return 0;
}
