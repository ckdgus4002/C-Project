#include <iostream>

using namespace std;

int main() {
    string name, tel, mail;


    cout << "이름: "; cin >> name;
    cout << "전화번호: "; cin >> tel;
    cout << "메일주소: "; cin >> mail;


    if(tel.length() != 13) cout << "전화번호가 13자리 미만 입니다." << endl;
    if(mail.find('@') > mail.length()) cout << "메일에 @표시가 빠졌습니다." << endl;

    if (tel.length() != 13 && mail.find('@') > mail.length()) {
        cout << "회원가입 결과:실패!!";
        return 0;
    }
    cout << "회원가입 결과:성공!!" << endl;
    return 0;
}
