#include <iostream>

using namespace std;

void Boy(int, int, double&);
void Girl(int, int, double&);

int main() {
    int fatherTall, motherTall;
    double boyTall, girlTall;

    cout << "�ƺ� Ű: "; cin >> fatherTall;
    cout << "���� Ű: "; cin >> motherTall;

    Boy(fatherTall, motherTall, boyTall);
    Girl(fatherTall, motherTall, girlTall);
    cout << "�Ƶ� Ű:" << boyTall << "cm" << endl;
    cout << "��  Ű:" << girlTall << "cm" << endl;
    return 0;
}

void Boy(int fatherTall, int motherTall, double& boyTall){
    boyTall = (motherTall * 13 / 12 + fatherTall ) / 2;
}

void Girl(int fatherTall, int motherTall, double& girlTall){
    girlTall = (fatherTall * 12 / 13 + motherTall ) / 2;
}
