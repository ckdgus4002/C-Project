#include <iostream>
using namespace std;

void rect(int,int,int&,int&);

int main() {
    int width;
    int height;
    int periphery, area;

    cout << "width? "; cin >> width;
    cout << "height? "; cin >> height;
    rect(width,height, periphery, area);


    cout << periphery << "," << area << endl;
    return 0;
}

void rect(int width, int height, int& periphery, int& area){
    periphery = width * 2 + height * 2;
    area = width * height;
}
