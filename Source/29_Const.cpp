#include <iostream>
using namespace std;

class Test {
private:
    int a;
public:
    void setValue(const int& k) {
        a = k;
    }

    // 이런 구문은 read만 가능하다.
    int getValue() const {
        return a;
        //return ++a;
    }
};

int main() {
    int a = 5, b= 6;
    const int * const p = &b; // a가 상수이기 때문. 상수는 메모리주소 없음.
    a = 11;
    //*p = 9;
    //p = &a;
    Test t;
    t.setValue(b);
    cout << "Hello world!" << endl;
    return 0;
}
