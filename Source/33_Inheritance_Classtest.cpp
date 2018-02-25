// �����ڷḦ �����Ͽ� �� ������ ��!
#include <iostream>
using namespace std;

// �߻� Ŭ����(�ּ� 1���� ���� ���� �Լ����������ִ� Ŭ����, ��ü������ ����.)
class Base {
protected:
    int *x;
public:
    //Constructor
    Base(int a) {
        x = new int[5]; // ���� �迭.
        for(int i = 0; i < 5; i++) x[i] = a;
    }

    //Destructor
    ~Base() {
        delete[] x;
    }
    int getBase(int i) {
        return x[i];
    }
    //���� ���� �Լ�. �߻� �Լ�.
    //�ڽ�Ŭ������ �������̵��ϱ����� �ʿ������ ������.
    virtual void print() = 0;
    /*
    void pirnt() {
        cout << "Base class....." <<endl;
        for(int i = 0; i < 5; i++) cout << "x: " << x[i];
        cout << endl;
    }*/
};

class Child : public Base {
private:
    int *y;
public:
    // Base() ���� �����ϰ� ��ü �κ� ����. Child�� a���� �ް� Base�� a�� ����.
    Child(int a, int b) : Base(a) {
        y = new int[5];
        for(int i = 0; i < 5; i++) y[i] = b * 2;
    }

    //Destructor
    //�ڱⰡ ����͸� ����� ��.
    ~Child() {
        delete[] y;
    }
    void setValue(int i, int b) {
        y[i] = b;
    }
    int getValue(int i) {
        return y[i];
    }
    /*
    void print() { // �������̵�.(������).
        cout << "Child class ...." << endl;
        Base::print();
        for(int i = 0; i < 5; i++)cout << " y:" << y[i];
        cout <<endl;
    } */
    //�����Լ�.
    virtual void print() { // �������̵�.(������).
        cout << "Child class.....";
        //Base::print();
        for(int i = 0; i < 5; i++) cout << "x: " << x[i];
        cout << endl;
        for(int i = 0; i < 5; i++) cout << "y: " << y[i];
        cout << endl;
    }

    //������(=) ��(or�ߺ�)����.
    //���� ���縦 ���� ���縦 �Ҷ� �����.
    void operator=(Child& ch) {
        for(int i = 0; i < 5; i++) {
            x[i] = ch.getBase(i);
            y[i] = ch.getValue(i);
        }
    }
};

class Child2 : public Base {
public:
    Child2(int a) : Base(a) {
    }
    virtual void print() {
        cout << "Child2 class ...." << endl;
    }
};

int main() {
    //���� ���� �Լ��� �����ؾ��� ������ ����. becuase print()=0 ���� ������.
    //���� ���� �����Լ��� ��üȭ�� ���Ѵ�. Base���� print�ۿ� �����ϱ�.
    //���� ���� �Լ��� �ݵ�� �����Ǹ� �ؼ� �������� �����ؾ� �Ѵ�.
    //Base b(1);
    Base *p[3];
    // Child() ������ ȣ��. �ڽİ�ü���� �θ�ü ������ �ʿ��� ���� ���� �޾ƾߵ�.
    Child c(2,3);
    Child c2(1,1);
    Child2 ch(5);


    p[0] = &c;
    p[1] = &ch;
    p[2] = &c2;

    // ������. Polymorphism. ���� ���� �ִٴ� ���.
    for(int i = 0; i < 3; i++) p[i]->print();
    /*
    //p�� c�� ����Ų��. �ٵ� p�� baseŸ���̴ϱ� p���ִ� baseŸ���� print�� �����Ѵ�.
    p = &c;
    p -> print();
    p = &ch;
    p -> print();
    //p -> getValue(0,10); // ERROR. BaseŬ������ getValue() ����.
    //but child�� �����Լ�ȭ �Ͽ� p�� ����Ű�� ���(c)�� print�� �ϰ� �ٲ�.


    //b = c;
        // b = c; �ϰ� ���� ������ �����ϸ� b�� ���. �ֳ��ϸ� basc�� �ڸ�����
        // base�� �����ϱ�.
    // b.print();
    //c = b; // �̰��� ����.


    /*
    c.print();
    c2.print();

    // �����迭�� ���� �ּҸ� �����Ѵ�. (�׼Ҹ� �����Ѵ�: ���� ����)
    // �����迭�� ���� ���� �����Ѵ�. (���� �����Ѵ�: ���� ����)
    // c2.=(c);
    c2 = c;
    c.setValue(0,9);
    c.print();
    c2.print();
    */
    return 0;
}
