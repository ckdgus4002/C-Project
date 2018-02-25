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
    cout << "킬로그램 무게를 파운드 무게로 환산하는 프로그램 입니다." << endl;
    cout << "킬로그램: "; cin >> kg;
    weight.SetKg(kg);
    weight.ConvertToPound();
    cout << "파운드 = " << setprecision(7) << weight.GetPound();
    return 0;
}
