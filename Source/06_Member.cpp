#include <iostream>

using namespace std;

int main() {
    string name, tel, mail;


    cout << "�̸�: "; cin >> name;
    cout << "��ȭ��ȣ: "; cin >> tel;
    cout << "�����ּ�: "; cin >> mail;


    if(tel.length() != 13) cout << "��ȭ��ȣ�� 13�ڸ� �̸� �Դϴ�." << endl;
    if(mail.find('@') > mail.length()) cout << "���Ͽ� @ǥ�ð� �������ϴ�." << endl;

    if (tel.length() != 13 && mail.find('@') > mail.length()) {
        cout << "ȸ������ ���:����!!";
        return 0;
    }
    cout << "ȸ������ ���:����!!" << endl;
    return 0;
}
