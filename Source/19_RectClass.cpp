#include <iostream>
using namespace std;

//클래스 = 멤버변수 + 멤버함수, 데이터와 일을 함께 정의.
//좌표 위에 있는 사각형 정의.
class Rect {
private:

    // 멤버변수, 속성(attribute, property)
    // private처럼 변수를 막는것. 캡슐화. 캡슐화는 왜하는가? 정보은닉. 보안때문에.
    int x, y;
    int w, h;

public:

    // Setter, 변경자, Mutator?.
    void setX(int a) { x = a; }
    void setY(int a) { y = a; }
    void setW(int a) { w = a; }
    void setH(int a) { h = a; }

    //Getter. 접근자 . Accessor?
    int getX() { return x; }
    int getY() { return y; }

    //멤버함수, 메소드(method, operation)
    //사각형을 처리 하는 함수(해야 하는 일).
    int area();
    void move(int, int);
};

class Circle {
public:
    int x, y;
    int r;
    double area();
    void move(int, int);
};


int main() {
    // r 변수는 Rect 클래스 타입의 변수. 객체(object) 클래스는 모양이고. 메모리할당은 변수를 통해서.
    // 클래스 내부의 변수는 '클래스 변수' 라고 부름.
    Rect r;

    Circle c; // Circle 객체변수 선언.
    int x, y, w, h;
    cout << "사각형 구성(int x): "; cin >> x;
    cout << "사각형 구성(int y): "; cin >> y;
    cout << "사각형 구성(int w): "; cin >> w;
    cout << "사각형 구성(int h): "; cin >> h;

    //r클래스 내부에 선언된 setx함수를 통해서 x값을 전달함.
    //직접접근은 private 로 인해 막혔으므로 이와 같은 방법으로 간접접근 한다
    r.setX(x);
    r.setY(y);
    r.setW(w);
    r.setH(h);
    cout << "사각형 면적:  " << r.area() << endl;

    int dx, dy;
    cout << "사각형 이동거리(int dx) : "; cin >> dx;
    cout << "사각형 이동거리(int dy) : "; cin >> dy;

    r.move(dx, dy);
    cout << "사각형 위치 " << "(" << r.getX() << "," << r.getY() << ")" << endl;


    cout << "원 구성(Circle r.x): "; cin >> c.x;
    cout << "원 구성(Circle r.y): "; cin >> c.y;
    cout << "원 구성(Circle r.r): "; cin >> c.r;
    cout << "원 면적:  " << c.area() << endl;

    cout << "원 이동거리(int dx) : "; cin >> dx;
    cout << "원 이동거리(int dy) : "; cin >> dy;

    c.move(dx, dy);
    cout << "원 위치 " << "(" << c.x << "," << c.y << ")" << endl;

    return 0;
}

//Rect 클래스의 멤버함수 area를 정의.
int Rect::area() {
    return w * h;
}

//Rect 클래스의 멤버함수 move를 정의.
void Rect::move(int x, int y) {

    // this->멤버변수를 가리킨다.
    this->x += x;
    this->y += y;
}

double Circle::area() {
    return r * r * 3.1415;
}

void Circle::move(int x, int y) {
    this->x += x;
    this->y += y;
}
