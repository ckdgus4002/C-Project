#include <iostream>
using namespace std;

class Box {
private:
    int a, b, c, w;
public:
    //setter

    //getter
    int GetWeight() {
        return w;
    }

    //member function
    void SetZero() {
        a = b = c = w = 0;
    }
    void InBox(int weight) {
        w += weight;
    }
    void OutBox(int weight) {
        w -= weight;
    }
};

int main() {
    Box box;
    box.SetZero();
    cout << "������ ���� �� �ִ� Box ���α׷� �Դϴ�." << endl;

    int weight;
    cout << "��� ���� : "; cin >> weight;
    box.InBox(weight);
    cout << "��� ���� : "; cin >> weight;
    box.InBox(weight);
    cout << "�ڽ� ���� = " << box.GetWeight() << "g" << endl;
    cout << "���� ���� : "; cin >> weight;
    box.OutBox(weight);
    cout << "�ڽ� ���� = " << box.GetWeight() << "g";

    return 0;
}
