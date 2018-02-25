#include <iostream>

using namespace std;

int main() {

    string insertWord;
    char searchWord;
    unsigned int i=0;

    cout << "단어를 입력하세요: "; cin >> insertWord;
    cout << "찾을 글자는 무엇이죠? "; cin >> searchWord;

    while(insertWord.size() > i) {
        if(insertWord.at(i) == searchWord) cout << "위치: " << ++i;
        i++;
    }


    /*---------------------------------------------------------



    -----------------------------------------------------------
    int a, sum = 0;

    while(a != -1) {
        cout << "숫자: "; cin >> a;
        sum += a;
    }

    cout << sum;
    return 0;
    ---------------------------------------------------------*/
}
