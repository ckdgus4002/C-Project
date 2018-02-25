#include <iostream>
#include <iomanip>
using namespace std;

class BMI {
private:
    double tall;
    double weight;
    double result;
    string index;
public:
    //setter
    void SetTall(double t) {
        tall = t;
    }
    void SetWeight(int w) {
        weight = w;
    }


    //getter
    double GetResult() {
        return result;
    }
    string GetIndex() {
        return index;
    }

    //member function

    void BMindex(){
        result = weight / (tall * tall);
        if (result >= 30) index = "고도비만";
        else if (result >= 25) index = "비만";
        else if (result >= 23) index = "과체중";
        else if (result >= 18.6) index = "정상";
        else index = "저체중";
    }
};

int main() {
    BMI bmi;

    double tall;
    double weight;
    cout << "BMI계산 프로그램입니다." << endl;
    cout << "몸무게(kg)와 키(m): "; cin >> weight >> tall;

    bmi.SetTall(tall);
    bmi.SetWeight(weight);
    bmi.BMindex();
    cout << "BMI지수 = " << setprecision(4) << bmi.GetResult() << "(" << bmi.GetIndex() << ")";
    return 0;
}
