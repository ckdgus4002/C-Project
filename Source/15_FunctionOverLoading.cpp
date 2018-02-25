#include <iostream>

using namespace std;

//function_overloading.
//�Լ��̸��� �ߺ�, �Ű����� ���� �Ǵ� Ÿ���� �޶�� ��.
//����Ʈ �Ű����� ����(bool=true) : ȣ�⿡�� ������ ��� ����Ʈ������ ����.
int area_size(int, int, bool = true);
double area_size(int);

int main() {
    cout << "Rect: " << area_size(4,6) << endl;
    cout << "Tri: " << area_size(4,6,false) << endl;
    cout << "Circle: " << area_size(4) << endl;
    return 0;
}

//�簢���� �ﰢ�� ���� ���ϱ�.
int area_size(int a, int b, bool shape) {
    if(shape) return a * b;
    else return a * b / 2;
}

double area_size(int a) {
    return a * a * 3.1415;
}
