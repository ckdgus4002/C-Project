#include <iostream>
#include <algorithm>
using namespace std;

int main() {
    string eng[30][2]; //2차원 배열 (30행 2열)
    int i, cnt = 0;
    string insertWord1, insertWord2;

    cout << "This is dictionry program." <<
    endl << "단어를 입력하면 저장되고, #을 누르면 종료합니다." <<
    endl << "이 외에 행동은 아무 결과를 반환하지 않습니다." <<
    endl <<
    endl;

    for(i=0; i<30; i++) {
        cout << "단어를 입력하세요."; cin >> insertWord1;
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


    cnt = i; //현재 입력된 단어의 개수
    //영어단어 정렬하기


    sort(eng[0],eng[0]+cnt);
    for (int i=0; i<cnt; i++)cout << eng[i][0] << " ";
    cout << endl;



    string Word;
    bool found = false;

    cout << "찾을 단어를 입력해주세요"; cin >> insertWord1;
    for(i=0; i<cnt; i++) {
        if(eng[i][0] == insertWord1) {
            cout << eng[i][1] << endl;
            found = true;
            break;
        }
    }

    if(!found) cout << "단어없음!!" << endl;
    cout <<  endl << "프로그램이 끝났습니다." << endl;
  /*for (int i=0; i<30; i++) {
        cout << i << ". " << eng[i] << endl;
    }
  */
    return 0;
}
