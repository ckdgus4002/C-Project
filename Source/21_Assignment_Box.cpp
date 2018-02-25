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
    cout << "물건을 담을 수 있는 Box 프로그램 입니다." << endl;

    int weight;
    cout << "담는 무게 : "; cin >> weight;
    box.InBox(weight);
    cout << "담는 무게 : "; cin >> weight;
    box.InBox(weight);
    cout << "박스 무게 = " << box.GetWeight() << "g" << endl;
    cout << "빼는 무게 : "; cin >> weight;
    box.OutBox(weight);
    cout << "박스 무게 = " << box.GetWeight() << "g";

    return 0;
}
