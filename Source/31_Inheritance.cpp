#include <iostream>
using namespace std;
/* is - A ����
�ڽ��� �θ�����.


dot �Ʒ��� color dot
dot <----- color dot
 specialized ����.
 */

class Dot {
//�ڽ��� �θ���� ������� �� �� �ְ� �ϴ°�. protected// �Լ��� ���.
protected:
    int x, y; // ��ǥ
    int border; // �׵θ� �β�
public:
    Dot() {
        x = y = 0;
        border = 0;
    }
    void setLocation(int a, int b) {
        x = a;
        y = b;
    }
    //��ǥ �̵�
    void move(int dx, int dy) {
        x += dx;
        y += dy;
    }

    //d���ٰ� �� ���� �����Ѵ�.
    void copy(Dot& d) {
    }
};



//�ڽ�Ŭ����
// color Dot Ŭ������ dot���� ���� �����޴´�.
class ColorDot : public Dot {
private:
    int red, green, blue; // 0 ~ 255 ������ ��.
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

    c.setLocation(3,5); // ���� 3,5 ��ǥ�� ��ġ.
    c.changeColor(25,108,115);
    c.move(-2,7); // -2,7 ��ŭ �̵�.

    c.print();
    return 0;
}
