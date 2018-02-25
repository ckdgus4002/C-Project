#include <iostream>
#include <iomanip>
using namespace std;

class Weight {
private:
    int kg;
    double pound;

public:
    void SetKg(int k){
        kg = k;
    }
    double GetPound() {
        return pound;
    }
    void ConvertToPound() {
        pound = kg * 2.2046;
    }
};

int main() {
    Weight weight;
    int kg;
    cout << "ų�α׷� ���Ը� �Ŀ�� ���Է� ȯ���ϴ� ���α׷� �Դϴ�." << endl;
    cout << "ų�α׷�: "; cin >> kg;
    weight.SetKg(kg);
    weight.ConvertToPound();
    cout << "�Ŀ�� = " << setprecision(7) << weight.GetPound();
    return 0;
}
