#include <iostream>

using namespace std;

struct Question {
    // 정답번호, 문항점수.
    int correct, score;
};

//정답번호와 문항점수 입력.
void set_quiz(Question[]);
void set_answer(int []);
int check_answer(Question[], int[]);
const int QSIZE = 5;

int main() {

    Question ans[QSIZE];

    //학생이 선택한 문항의 답안.
    int quiz[QSIZE];
    set_answer(quiz);
    set_quiz(ans);

    //채점한 점수.
    int score = check_answer(ans, quiz);

    cout << "점수: " << score << endl;
    return 0;
}

//함수의 매개변수로 갖는 변수는 크기를 적지 않는다.
void set_quiz(Question a[]) {

    //0,1,2,0,4
    //X,O,O,X,O
    a[0].correct = 0;
    a[1].correct = 1;
    a[2].correct = 2;
    a[3].correct = 0;
    a[4].correct = 4;
    for(int i = 0; i < 5; i++) {
        a[i].score = 0;
        a[i].score = 10 * i;
    }
};



void set_answer(int q[]) {
    for(int i = 0; i < 5; i++) {
        cout << "정답입력: ";
        cin >> q[i];
    }
};

int check_answer(Question a[], int q[]) {
    int s = 0;
    for (int i = 0; i < 5; i++) {
        if(a[i].correct == q[i]) s += a[i].score;
    }
    return s;
};
