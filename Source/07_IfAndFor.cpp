#include <iostream>

using namespace std;

int main() {

    string insertWord;
    char searchWord;
    unsigned int i=0;

    cout << "�ܾ �Է��ϼ���: "; cin >> insertWord;
    cout << "ã�� ���ڴ� ��������? "; cin >> searchWord;

    while(insertWord.size() > i) {
        if(insertWord.at(i) == searchWord) cout << "��ġ: " << ++i;
        i++;
    }


    /*---------------------------------------------------------



    -----------------------------------------------------------
    int a, sum = 0;

    while(a != -1) {
        cout << "����: "; cin >> a;
        sum += a;
    }

    cout << sum;
    return 0;
    ---------------------------------------------------------*/
}
