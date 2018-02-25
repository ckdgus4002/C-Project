#include <iostream>

using namespace std;

struct Question {
    // �����ȣ, ��������.
    int correct, score;
};

//�����ȣ�� �������� �Է�.
void set_quiz(Question[]);
void set_answer(int []);
int check_answer(Question[], int[]);
const int QSIZE = 5;

int main() {

    Question ans[QSIZE];

    //�л��� ������ ������ ���.
    int quiz[QSIZE];
    set_answer(quiz);
    set_quiz(ans);

    //ä���� ����.
    int score = check_answer(ans, quiz);

    cout << "����: " << score << endl;
    return 0;
}

//�Լ��� �Ű������� ���� ������ ũ�⸦ ���� �ʴ´�.
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
        cout << "�����Է�: ";
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
