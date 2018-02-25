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
        if (result >= 30) index = "����";
        else if (result >= 25) index = "��";
        else if (result >= 23) index = "��ü��";
        else if (result >= 18.6) index = "����";
        else index = "��ü��";
    }
};

int main() {
    BMI bmi;

    double tall;
    double weight;
    cout << "BMI��� ���α׷��Դϴ�." << endl;
    cout << "������(kg)�� Ű(m): "; cin >> weight >> tall;

    bmi.SetTall(tall);
    bmi.SetWeight(weight);
    bmi.BMindex();
    cout << "BMI���� = " << setprecision(4) << bmi.GetResult() << "(" << bmi.GetIndex() << ")";
    return 0;
}
