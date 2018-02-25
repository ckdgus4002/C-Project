#include <iostream>
using namespace std;

class Shape{
protected:
    int degree1, degree2;
public:
    //Setter
    void setShape(int d1, int d2) {
        degree1 = d1;
        degree2 = d2;
        cout << "degree1: " << degree1 << ", degree2: " << degree2 << endl;
    }

    //Member Function Header
    double area();
};

class Rect : public Shape{
public:
    double area(){
        return degree1*degree2;
    }
    //�����ε��� �Լ��̸��� ������ ������.
    //�������̵��� �θ� ������ ����Լ��� �������� ��,
    //���� �����Ŷ� �޶� ���� ����°� �������̵�.
    /*
    double area(int a, int b) {
        degree1 = a;
        degree2 = b;
        return degree1 * degree2;
    }
    */
};

class Tri : public Shape{
public:
    double area() {
        return (double)degree1 * (double)degree1 / 2.0;
    }
};


class Circle : public Shape{
public:
    double area(){
        return degree1;
    }
};

int main() {
    Rect r;
    Tri t;
    Circle c;

    r.setShape(1,1);
    cout << r.area() << endl;
    cout << t.area() << endl;
    cout << c.area() << endl;
    return 0;
}
