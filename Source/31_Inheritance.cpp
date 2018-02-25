#include <iostream>
using namespace std;
/* is - A 관계
자식은 부모관계다.


dot 아래의 color dot
dot <----- color dot
 specialized 관계.
 */

class Dot {
//자식은 부모것을 마음대로 쓸 수 있게 하는것. protected// 함수만 대상.
protected:
    int x, y; // 좌표
    int border; // 테두리 두께
public:
    Dot() {
        x = y = 0;
        border = 0;
    }
    void setLocation(int a, int b) {
        x = a;
        y = b;
    }
    //좌표 이동
    void move(int dx, int dy) {
        x += dx;
        y += dy;
    }

    //d에다가 내 것을 복사한다.
    void copy(Dot& d) {
    }
};



//자식클래스
// color Dot 클래스는 dot으로 부터 물려받는다.
class ColorDot : public Dot {
private:
    int red, green, blue; // 0 ~ 255 사이의 값.
public:
    ColorDot() {
        red = 0;
        green = 0;
        blue = 0;
    }
    void changeColor(int r, int g, int b) {
        red = r;
        green = g;
        blue = b;
    }

    void print() { // ColorDot : (x,y):(r,g,b)
        cout << "(" << x << ", " << y  << ") : (" << red << ", " << green << ", " << blue << ")" << endl;
    }
};

int main() {
    ColorDot c;

    c.setLocation(3,5); // 점을 3,5 좌표에 위치.
    c.changeColor(25,108,115);
    c.move(-2,7); // -2,7 만큼 이동.

    c.print();
    return 0;
}
