#include <iostream>

using namespace std;

void Boy(int, int, double&);
void Girl(int, int, double&);

int main() {
    int fatherTall, motherTall;
    double boyTall, girlTall;

    cout << "아빠 키: "; cin >> fatherTall;
    cout << "엄마 키: "; cin >> motherTall;

    Boy(fatherTall, motherTall, boyTall);
    Girl(fatherTall, motherTall, girlTall);
    cout << "아들 키:" << boyTall << "cm" << endl;
    cout << "딸  키:" << girlTall << "cm" << endl;
    return 0;
}

void Boy(int fatherTall, int motherTall, double& boyTall){
    boyTall = (motherTall * 13 / 12 + fatherTall ) / 2;
}

void Girl(int fatherTall, int motherTall, double& girlTall){
    girlTall = (fatherTall * 12 / 13 + motherTall ) / 2;
}
