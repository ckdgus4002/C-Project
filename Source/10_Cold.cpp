#include <iostream>
#include <cmath>

using namespace std;

void Wind(float, float, float&);


int main() {
    float v, t, w;
    cout << "풍속(m/sec): "; cin >> v;
    cout << "기온(C) :"; cin >> t;

    Wind(v, t, w);
    cout << "바람냉기 : " << Wind(v,t) << endl;
    return 0;
}

//함수정의
//주소를 주고받는 변수:래퍼런스.
//w는 래퍼런스 변수가 됨.
//콜바이밸루,콜바이래퍼런스 함수선언 2가지 방법?
//형식 매개변수(입력값)을 만들어서 들어오는 값을 받는것임.
//float w 함수선언을 주석화한 이유는 위에 함수에서 래퍼런스변수로 선언해서. 덕분에 return 문도 사라짐.

void float Wind(float v, float t, float& w) { 
    w = 33 - (10 * sqrt(v) - v + 10.5) * (33 - t) / 23.1;
}
