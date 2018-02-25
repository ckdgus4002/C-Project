#include <iostream>
using namespace std;

void ChangeTime(int&, int, char&);

int main() {
    int hour;
    int minute;
    char ap = 'a';

    cout << "hour? minute? "; cin >> hour >> minute;
    ChangeTime(hour, minute, ap);
    cout << hour << ":" << minute << ap << endl;

    return 0;
}

void ChangeTime(int& hour, int minute, char& ap) {
    if(hour >= 12) {
        hour -= 12;
        ap = 'p';
    }
}
