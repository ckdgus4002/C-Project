// 강의자료를 참고하여 꼭 이해할 것!
#include <iostream>
using namespace std;

// 추상 클래스(최소 1개의 순수 가상 함수를가지고있는 클래스, 객체생성을 못함.)
class Base {
protected:
    int *x;
public:
    //Constructor
    Base(int a) {
        x = new int[5]; // 동적 배열.
        for(int i = 0; i < 5; i++) x[i] = a;
    }

    //Destructor
    ~Base() {
        delete[] x;
    }
    int getBase(int i) {
        return x[i];
    }
    //순수 가상 함수. 추상 함수.
    //자식클래스가 오버라이딩하기위해 필요없지만 존재함.
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
    // Base() 먼저 실행하고 몸체 부분 실행. Child가 a값을 받고 Base로 a를 보냄.
    Child(int a, int b) : Base(a) {
        y = new int[5];
        for(int i = 0; i < 5; i++) y[i] = b * 2;
    }

    //Destructor
    //자기가 만든것만 지우면 됌.
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
    void print() { // 오버라이딩.(재정의).
        cout << "Child class ...." << endl;
        Base::print();
        for(int i = 0; i < 5; i++)cout << " y:" << y[i];
        cout <<endl;
    } */
    //가상함수.
    virtual void print() { // 오버라이딩.(재정의).
        cout << "Child class.....";
        //Base::print();
        for(int i = 0; i < 5; i++) cout << "x: " << x[i];
        cout << endl;
        for(int i = 0; i < 5; i++) cout << "y: " << y[i];
        cout << endl;
    }

    //연산자(=) 재(or중복)정의.
    //얕은 복사를 깊은 복사를 할때 사용함.
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
    //순수 가상 함수는 실행해야할 내용이 없다. becuase print()=0 으로 끝내서.
    //또한 순수 가상함수는 객체화를 못한다. Base안의 print밖에 없으니까.
    //순수 가상 함수는 반드시 재정의를 해서 다형성을 구현해야 한다.
    //Base b(1);
    Base *p[3];
    // Child() 생성자 호출. 자식객체에서 부모객체 생성에 필요한 값을 같이 받아야됨.
    Child c(2,3);
    Child c2(1,1);
    Child2 ch(5);


    p[0] = &c;
    p[1] = &ch;
    p[2] = &c2;

    // 다형성. Polymorphism. 여러 뜻이 있다는 얘기.
    for(int i = 0; i < 3; i++) p[i]->print();
    /*
    //p가 c를 가리킨다. 근데 p는 base타입이니까 p에있는 base타입의 print를 실행한다.
    p = &c;
    p -> print();
    p = &ch;
    p -> print();
    //p -> getValue(0,10); // ERROR. Base클래스에 getValue() 없음.
    //but child를 가상함수화 하여 p가 가리키는 대상(c)의 print를 하게 바뀜.


    //b = c;
        // b = c; 하고 옆의 문장을 실행하면 b가 출력됌. 왜나하면 basc의 자리에는
        // base민 들어갔으니까.
    // b.print();
    //c = b; // 이것은 에러.


    /*
    c.print();
    c2.print();

    // 동적배열의 경우는 주소를 복사한다. (죽소를 복사한다: 얕은 복사)
    // 정적배열의 경우는 값을 복사한다. (값을 복사한다: 깊은 복사)
    // c2.=(c);
    c2 = c;
    c.setValue(0,9);
    c.print();
    c2.print();
    */
    return 0;
}
