#include <iostream>
#include <algorithm>

using namespace std;
struct term {
    string engWord; //����ܾ�
    string wordClass; //ǰ��
    string korWord[10]; //�ѱ۴ܾ�
    int kcnt = 0; //�ѱ۴ܾ��� ����
};
struct term dict[30];


//�� �Լ� ����
bool cmp(struct term a, struct term b) {
    return a.engWord < b.engWord;
}

//�Լ� ���� ����(function prototype ����) :�Ʒ��� �Լ� ���Ǹ� �̸� �˷���.

void AddWord();
void ListWord();
void FindWord();


string insertEngWord, insertKorWord, insertWordClass;
int i;
int cnt = i;


int main() {
    int a;

    cout << "This is dictionry2 program." <<
    endl << "�ܾ �Է��ϸ� ����ǰ�, #�� ������ �����մϴ�." <<
    endl << "�� �ܿ� �ൿ�� �ƹ� ����� ��ȯ���� �ʽ��ϴ�." <<
    endl <<
    endl;

    while(1) {
        cout << "��ư�� �����ּ���. 1=addWord, 2=listword, 3=searchWord, 0=����";
        cin >> a;
        switch(a) {
            case 1:
                AddWord();
                break;
            case 2:
                ListWord();
                break;
            case 3:
                FindWord();
                break;
            case 0:
                cout << "Bye!" << endl;
                break;
        }
        if( a== 0) break;
    }

    return 0;
}

void AddWord() {
    //�ܾ��Է�
    for(i=0; i<30; i++) {
        cout << "�����ܾ �Է�: ";
        cin >> insertEngWord;
        if(insertEngWord == "#") break;
        else dict[i].engWord = insertEngWord;

        cout << "ǰ�������� �Է�: ";
        cin >> insertWordClass;
        if(insertWordClass == "#") break;
        else dict[i].wordClass = insertWordClass;

        int j;
        for(j=0; j<10; j++) {
            cout << "�ѱ۶��� �Է�: ";
            cin >> insertKorWord;
            if(insertKorWord == "#") break;
            else dict[i].korWord[j] = insertKorWord;
        }
        dict[i].kcnt = j;
    }
    //�ܾ�����
    //sort(�迭, �����ּ�+����, ���Һ񱳹��)
    sort(dict, dict+cnt, cmp);
    //for(i=0; i<cnt; i++) cout << dict[i].engWord << "(" << dict[i].korWord << ")" << ", ";
}

//�ܾ� ���
void ListWord() {
    for(i=0; i<cnt; i++) {
        cout << "[ " << dict[i].engWord << " / " << dict[i].wordClass;
        for(int j=0; j < dict[i].kcnt; j++)
            cout << " " << dict[i].korWord[j];
        cout << " ]" << endl;
    }
}

void FindWord() {
    //�ܾ�˻�
    string insertSearchWord;
    cout << "ã���ܾ�: "; cin >> insertSearchWord;
    bool found = false;
    for(i=0; i<cnt; i++) {
        if(dict[i].engWord == insertSearchWord) {
            found = true;
            cout << "[ " << dict[i].wordClass << " / ";
            for(int j=0; j<dict[i].kcnt; j++ )
                cout << dict[i].korWord[j] << " ";
            cout << "] " << endl;
            break;
        }
    }
    if(!found) cout << "�ܾ����!";
}















