#include <iostream>
using namespace std;

void set_answer(int q[]);
int check_answer(int a[], int b[]);
//const�� ������� �������. ���������Ҷ� const��.
const int SIZE = 10;

int main() {
     //���ô�������
    int quiz[10];
    //���亯��.
    int correct[10] = {2,3,0,0,3,0,1,1,0,2};


    //������ ��������(�Լ�ȣ�� ��)������ ������ ������.
    set_answer(quiz);
    int score = check_answer(quiz,correct);

    cout << "����:" << score << endl;
    return 0;
}

void set_answer(int q[]){
    for(int i=0; i<10; i++) {
        cout << i << "�� ������ �Է��ϼ���. ";
        cin >> q[i];
    }
}

//�Ű������� const�� ������ �����Ұ�.
int check_answer(int a[], const int b[]){
    int s = 0;
    for(int i=0; i<10; i++) {
        if(a[i] == b[i]) s += 10;
        //(a = b) ? score += 10 : score += 1 ;
    }
    cout << endl;
    return s;
}
