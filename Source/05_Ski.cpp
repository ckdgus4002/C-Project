#include <iostream>
using namespace std;

/*
    ���ϱ�      ���ϱ�     �߰���
���� 65,000   45,000   28,000

1. ����(���ϱ�, ���ϱ�, �߱ٱ�
2. �ο�:3��
3. �ݾ� = ?
*/

int main() {
    string liftList;
    int cache = 0;
    int people;

    cout << "�� ���̼� ���̾��?"; cin >> people;

    for(int i = 0; i < people; i ++) {
        cout << "���ϱ�,���ϱ�,�߰��� �߿� �����ϼ���."; cin >> liftList;

        if(liftList == "���ϱ�") cache = 650000 + cache;
        else if (liftList == "���ϱ�") cache = 450000 + cache;
        else if (liftList == "�߰���") cache = 280000 + cache;
        else {
            cout << "���� ���� �����Դϴ�.";
            return 0;
        }
    }

    cout << "�ݾ���: " << cache << "�� �Դϴ�.";
    return 0;
}
