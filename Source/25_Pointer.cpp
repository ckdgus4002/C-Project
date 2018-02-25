#include <iostream>
using namespace std;

class Circle {
private:
    float r;
public:
    Circle() {
        r = 0;
    }
    Circle(float a) {
        r = a;
    }
    void setRadius(float a) {
        r = a;
    }
    float getArea() {
        return r * r * 3.1415;
    }
};

int main() {
    Circle c(4); // 반지름 4
    Circle *pc; // pc는  circle객체를 가리키는 포인터변수.

    pc = &c;
    cout << "면적 = " << pc->getArea() << endl; // 포인터변수는 점 안찍고 화살표.
    pc = new Circle(7); // 길이 7인 원 객체가 힙 공간에 생성.

    delete pc;

    int a = 5, b = 7;
    int *p, *q;

    p = &a; // p-> a (참조)
    (*p)++; // 역참조.
    cout << "a: " << a << endl;

    // 정수자리를 새로 만들고 그자리에 q 를 넣어라.
    // 힙 공간에 메모리 할당
    // q는 1차원 배열이 된다.
    cout << "배열 길이?"; cin >> b;
    q = new int[b]; // 동적 배열


    cout << "q: " << q << endl;
    q[0] = b;
    (*q)++;


    cout << "b: " << b << endl;
    cout << "*p: " << *p << endl;
    cout << "*q: " << *q << endl;
    cout << "q: " << q << endl;

    // 힙에 할당된 메모리를 해제.
    // new로 생성했을때 delete 안하면 쓰레기로 남음.
    // 배열 지우려면  delete뒤에 [] 붙여야함.
    delete[] q;
    return 0;
}
