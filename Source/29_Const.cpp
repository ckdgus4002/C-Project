#include <iostream>
using namespace std;

class Test {
private:
    int a;
public:
    void setValue(const int& k) {
        a = k;
    }

    // �̷� ������ read�� �����ϴ�.
    int getValue() const {
        return a;
        //return ++a;
    }
};

int main() {
    int a = 5, b= 6;
    const int * const p = &b; // a�� ����̱� ����. ����� �޸��ּ� ����.
    a = 11;
    //*p = 9;
    //p = &a;
    Test t;
    t.setValue(b);
    cout << "Hello world!" << endl;
    return 0;
}
