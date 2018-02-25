#include <iostream>
#include <math.h>
using namespace std;

class Calculator {
private:
    double Operand1, Operand2;
    char Operator;
public:
    //setter
    void setEquation(double a, double b, char c) {
        Operand1 = a;
        Operand2 = b;
        Operator = c;
    }

    //getter
    double getOperand1() {
        return Operand1;
    }
    double getOperand2() {
        return Operand2;
    }
    char getOperator() {
        return Operator;
    }

    //member function
    double calc() {
        switch (Operator) {
            case '+':
                return Operand1 + Operand2;
            case '-':
                return Operand1 - Operand2;
            case '/':
                return Operand1 / Operand2;
            case '*':
                return Operand1 * Operand2;
            case '^':
                return pow(Operand1,Operand2);
            default:
                break;
        }
    }
};

int main() {
    Calculator cal;
    double a, b;
    char c;

    cout << "��� ������ ó���ϴ� Calculator ���α׷��Դϴ�. " << endl;
    while(1) {
        cout << "���� �Է�(a * b): "; cin >> a >> c >> b;
        cal.setEquation(a, b, c);
        cout << cal.getOperand1() << " " << cal.getOperator() << " " << cal.getOperand2() << " = " << cal.calc() << endl;
    }
    return 0;
}
