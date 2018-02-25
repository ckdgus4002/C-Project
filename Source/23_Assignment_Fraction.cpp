#include <iostream>
using namespace std;

//분수의 산술연산(덧셈, 뺄셈)을 처리하는 프로그램이다.
//main 함수의 내용을 보고 두 클래스(Bunsu, BunsuHandler)를 구현한다.

class Bunsu {
private:
    int bm,bj;
public:
//constructor
    Bunsu() {
    }
    Bunsu(int j, int m): bj(j), bm(m) {
    }
//setter
    void setBunsu(int m, int j) {
        bm = m;
        bj = j;
    }
    void setJa(int j) {
        bj = j;
    }
    void setMo(int m) {
        bm = m;
    }
//getter
    int getJa() {
        return bj;
    }
    int getMo() {
        return bm;
    }
    double getValue() {
        return (double)bj / (double)bm;
    }
};

class BunsuHandler {
private:
//분수 2개.
    Bunsu op1, op2;
public:
    //setter
    //getter
    //member function
    void setOperands(Bunsu b1, Bunsu b2) {
        op1 = b1;
        op2 = b2;
    }

    Bunsu add() {
        int op1ja = op1.getJa();
        int op1mo = op1.getMo();

        op1.setJa(op1ja * op2.getMo());
        op1.setMo(op1mo * op2.getMo());

        op2.setJa(op2.getJa() * op1mo);
        op2.setMo(op2.getMo() * op1mo);

        op1.setJa(op1.getJa() + op2.getJa());
        return op1;
    }

    Bunsu sub() {
        int op1ja = op1.getJa();
        int op1mo = op1.getMo();
        int op2ja = op2.getJa();

        op1.setJa(op1ja * op2.getMo());
        op1.setMo(op1mo * op2.getMo());
        op2.setJa(op2.getJa() * op1mo);
        op2.setMo(op2.getMo() * op1mo);

        op1.setJa(op1.getJa() - op2.getJa());
        return op1;
    }
};

int main() {
   Bunsu b1, b2, b3;
   BunsuHandler handler;
   int m, j;
   cout << "분수1(분모와 분자를 입력) : "; cin >> m >> j;
   b1.setBunsu(m,j);
   cout << "분수2(분모와 분자를 입력) : "; cin >> m >> j;
   b2.setBunsu(m,j);
   handler.setOperands(b1,b2);
   b3 = handler.add();
   cout << b1.getJa() << "/" << b1.getMo() << " + " <<
            b2.getJa() << "/" << b2.getMo() << " = " <<
            b3.getJa() << "/" << b3.getMo() << " = " << b3.getValue() << endl;

   Bunsu b4(1,3), b5(2,5), b6;
   handler.setOperands(b4,b5);
   b6 = handler.sub();
   cout << b4.getJa() << "/" << b4.getMo() << " - " <<
           b5.getJa() << "/" << b5.getMo() << " = " <<
           b6.getJa() << "/" << b6.getMo() << " = " << b6.getValue() << endl;

   return 0;
}
