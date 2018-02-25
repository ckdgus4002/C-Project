#include <iostream>
using namespace std;

void set_answer(int q[]);
int check_answer(int a[], int b[]);
//const는 상수변수 변경못함. 변수선언할땐 const로.
const int SIZE = 10;

int main() {
     //선택답지변수
    int quiz[10];
    //정답변수.
    int correct[10] = {2,3,0,0,3,0,1,1,0,2};


    //보내는 곳에서는(함수호출 쪽)무조건 변수명만 보내기.
    set_answer(quiz);
    int score = check_answer(quiz,correct);

    cout << "점수:" << score << endl;
    return 0;
}

void set_answer(int q[]){
    for(int i=0; i<10; i++) {
        cout << i << "번 정답을 입력하세요. ";
        cin >> q[i];
    }
}

//매개변수에 const가 들어오면 수정불가.
int check_answer(int a[], const int b[]){
    int s = 0;
    for(int i=0; i<10; i++) {
        if(a[i] == b[i]) s += 10;
        //(a = b) ? score += 10 : score += 1 ;
    }
    cout << endl;
    return s;
}
