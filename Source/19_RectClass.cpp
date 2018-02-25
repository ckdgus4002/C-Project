#include <iostream>
using namespace std;

//Ŭ���� = ������� + ����Լ�, �����Ϳ� ���� �Բ� ����.
//��ǥ ���� �ִ� �簢�� ����.
class Rect {
private:

    // �������, �Ӽ�(attribute, property)
    // privateó�� ������ ���°�. ĸ��ȭ. ĸ��ȭ�� ���ϴ°�? ��������. ���ȶ�����.
    int x, y;
    int w, h;

public:

    // Setter, ������, Mutator?.
    void setX(int a) { x = a; }
    void setY(int a) { y = a; }
    void setW(int a) { w = a; }
    void setH(int a) { h = a; }

    //Getter. ������ . Accessor?
    int getX() { return x; }
    int getY() { return y; }

    //����Լ�, �޼ҵ�(method, operation)
    //�簢���� ó�� �ϴ� �Լ�(�ؾ� �ϴ� ��).
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
    // r ������ Rect Ŭ���� Ÿ���� ����. ��ü(object) Ŭ������ ����̰�. �޸��Ҵ��� ������ ���ؼ�.
    // Ŭ���� ������ ������ 'Ŭ���� ����' ��� �θ�.
    Rect r;

    Circle c; // Circle ��ü���� ����.
    int x, y, w, h;
    cout << "�簢�� ����(int x): "; cin >> x;
    cout << "�簢�� ����(int y): "; cin >> y;
    cout << "�簢�� ����(int w): "; cin >> w;
    cout << "�簢�� ����(int h): "; cin >> h;

    //rŬ���� ���ο� ����� setx�Լ��� ���ؼ� x���� ������.
    //���������� private �� ���� �������Ƿ� �̿� ���� ������� �������� �Ѵ�
    r.setX(x);
    r.setY(y);
    r.setW(w);
    r.setH(h);
    cout << "�簢�� ����:  " << r.area() << endl;

    int dx, dy;
    cout << "�簢�� �̵��Ÿ�(int dx) : "; cin >> dx;
    cout << "�簢�� �̵��Ÿ�(int dy) : "; cin >> dy;

    r.move(dx, dy);
    cout << "�簢�� ��ġ " << "(" << r.getX() << "," << r.getY() << ")" << endl;


    cout << "�� ����(Circle r.x): "; cin >> c.x;
    cout << "�� ����(Circle r.y): "; cin >> c.y;
    cout << "�� ����(Circle r.r): "; cin >> c.r;
    cout << "�� ����:  " << c.area() << endl;

    cout << "�� �̵��Ÿ�(int dx) : "; cin >> dx;
    cout << "�� �̵��Ÿ�(int dy) : "; cin >> dy;

    c.move(dx, dy);
    cout << "�� ��ġ " << "(" << c.x << "," << c.y << ")" << endl;

    return 0;
}

//Rect Ŭ������ ����Լ� area�� ����.
int Rect::area() {
    return w * h;
}

//Rect Ŭ������ ����Լ� move�� ����.
void Rect::move(int x, int y) {

    // this->��������� ����Ų��.
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
