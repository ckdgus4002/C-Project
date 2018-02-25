#include <iostream>
#include <algorithm>

using namespace std;
struct term {
    string engWord; //영어단어
    string wordClass; //품사
    string korWord[10]; //한글단어
    int kcnt = 0; //한글단어의 개수
};
struct term dict[30];


//비교 함수 정의
bool cmp(struct term a, struct term b) {
    return a.engWord < b.engWord;
}

//함수 원형 선언(function prototype 선언) :아래에 함수 정의를 미리 알려줌.

void AddWord();
void ListWord();
void FindWord();


string insertEngWord, insertKorWord, insertWordClass;
int i;
int cnt = i;


int main() {
    int a;

    cout << "This is dictionry2 program." <<
    endl << "단어를 입력하면 저장되고, #을 누르면 종료합니다." <<
    endl << "이 외에 행동은 아무 결과를 반환하지 않습니다." <<
    endl <<
    endl;

    while(1) {
        cout << "버튼을 눌러주세요. 1=addWord, 2=listword, 3=searchWord, 0=종료";
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
    //단어입력
    for(i=0; i<30; i++) {
        cout << "영문단어를 입력: ";
        cin >> insertEngWord;
        if(insertEngWord == "#") break;
        else dict[i].engWord = insertEngWord;

        cout << "품사종류를 입력: ";
        cin >> insertWordClass;
        if(insertWordClass == "#") break;
        else dict[i].wordClass = insertWordClass;

        int j;
        for(j=0; j<10; j++) {
            cout << "한글뜻을 입력: ";
            cin >> insertKorWord;
            if(insertKorWord == "#") break;
            else dict[i].korWord[j] = insertKorWord;
        }
        dict[i].kcnt = j;
    }
    //단어정렬
    //sort(배열, 시작주소+개수, 원소비교방법)
    sort(dict, dict+cnt, cmp);
    //for(i=0; i<cnt; i++) cout << dict[i].engWord << "(" << dict[i].korWord << ")" << ", ";
}

//단어 출력
void ListWord() {
    for(i=0; i<cnt; i++) {
        cout << "[ " << dict[i].engWord << " / " << dict[i].wordClass;
        for(int j=0; j < dict[i].kcnt; j++)
            cout << " " << dict[i].korWord[j];
        cout << " ]" << endl;
    }
}

void FindWord() {
    //단어검색
    string insertSearchWord;
    cout << "찾을단어: "; cin >> insertSearchWord;
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
    if(!found) cout << "단어없음!";
}















