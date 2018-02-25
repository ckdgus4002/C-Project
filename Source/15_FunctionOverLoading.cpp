#include <iostream>

using namespace std;

//function_overloading.
//함수이름은 중복, 매개변수 개수 또는 타입이 달라야 됨.
//디폴트 매개변수 설정(bool=true) : 호출에서 생략한 경우 디폴트값으로 동작.
int area_size(int, int, bool = true);
double area_size(int);

int main() {
    cout << "Rect: " << area_size(4,6) << endl;
    cout << "Tri: " << area_size(4,6,false) << endl;
    cout << "Circle: " << area_size(4) << endl;
    return 0;
}

//사각형과 삼각형 면적 구하기.
int area_size(int a, int b, bool shape) {
    if(shape) return a * b;
    else return a * b / 2;
}

double area_size(int a) {
    return a * a * 3.1415;
}
