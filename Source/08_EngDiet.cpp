#include <iostream>
#include <algorithm>
using namespace std;

int main() {
    string eng[30][2]; //2���� �迭 (30�� 2��)
    int i, cnt = 0;
    string insertWord1, insertWord2;

    cout << "This is dictionry program." <<
    endl << "�ܾ �Է��ϸ� ����ǰ�, #�� ������ �����մϴ�." <<
    endl << "�� �ܿ� �ൿ�� �ƹ� ����� ��ȯ���� �ʽ��ϴ�." <<
    endl <<
    endl;

    for(i=0; i<30; i++) {
        cout << "�ܾ �Է��ϼ���."; cin >> insertWord1;
        if(insertWord1 == "#") break;
        else cin >> insertWord2;

        if (insertWord2 == "#") break;


        eng[i][0] = insertWord1;
        eng[i][1] = insertWord2;


        cout << "[";
        for(int j=0; j<=i; j++) {
                cout << eng[j][0] << "(" << eng[j][1] << ")" <<" ";
        }
        cout << "]";
    }


    cnt = i; //���� �Էµ� �ܾ��� ����
    //����ܾ� �����ϱ�


    sort(eng[0],eng[0]+cnt);
    for (int i=0; i<cnt; i++)cout << eng[i][0] << " ";
    cout << endl;



    string Word;
    bool found = false;

    cout << "ã�� �ܾ �Է����ּ���"; cin >> insertWord1;
    for(i=0; i<cnt; i++) {
        if(eng[i][0] == insertWord1) {
            cout << eng[i][1] << endl;
            found = true;
            break;
        }
    }

    if(!found) cout << "�ܾ����!!" << endl;
    cout <<  endl << "���α׷��� �������ϴ�." << endl;
  /*for (int i=0; i<30; i++) {
        cout << i << ". " << eng[i] << endl;
    }
  */
    return 0;
}
