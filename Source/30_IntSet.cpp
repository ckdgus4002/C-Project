#include <iostream>
using namespace std;

class IntList {
private:
    int **list;
    int cnt, length;
public:
    //Constructor
    IntList(int s) {
        list = new int*[s];
        for(int i=0; i<s; i++) list[i] = NULL;
        cnt = 0;
        length = s;
    }
    //const�� �ٿ��� �� ��Ȯ�ѵ�, �Լ����忡���� ������ ������ �Ϸ��°���,
    //���� �ٲٷ��°� �ƴϱ� �����̴�.
    IntList(const IntList& from) {
        cnt = 0;
        length = from.getLength();
        list = new int*[length];
        for(int i = 0; i < from.size(); i++)
            add(from.get(i));
    }

    //�Ҹ���(Distructor). ��ü�� �޸𸮿��� ���ŵǱ� ���� ����.
    ~IntList() {
        //list�� �迭�� ��������� ������ delete �ڿ� []�� ���δ�.
        delete[] list;
    }

    //���⼭�� const�� getLenght�� ���� �ٲ��� �ʴ´ٴ°��� ǥ���ϴ� �뵵��.
    int getLength() const {
        return length;
    }
    //���⼭�� const�� getLenght�� ���� �ٲ��� �ʴ´ٴ°��� ǥ���ϴ� �뵵��.
    int size() const {
        return cnt;
    }

    //add(), get(), set() �Լ��� ���� ª�� �ζ���(InLine) �Լ���� �θ���.
    //�ζ��� �Լ��� ��� �� �Լ��� �״�� �����ؼ� �������Ѵ�. �� �Լ�ȣ���� ���� ������
    //�ð��� �����̳��� ������. but�ڵ尡 ������� ������ �ִ�.
    void add(int n) {
        if(cnt < length) {
            list[cnt] = new int; // ���� �Ѱ� ������ ����.
            *list[cnt++] = n;
        }
    }
    int get (int i) const {
        if((i >= 0 && i < cnt) && list[i] != NULL )
            return *list[i];
    }
    int set(int i, int n) {
        if(( i>=0 && i < cnt) && list[i] != NULL)
            *list[i] = n;
    }
    //Member Function
    //Member Function Header
    void copyTo(IntList& to);
};

//void IntList::copyTo(IntList& to) {
void IntList::copyTo(IntList& to) {
    for(int i = 0; i < cnt; i++) to.add(get(i));
}

int main() {
    IntList mylist(5), list2(5); //5���� �� ����Ʈ.

    mylist.add(3);
    mylist.add(5);

    //����Ʈ�� 0��°�� 1��° ���.
    cout << mylist.get(0) << " " << mylist.get(1) << endl;

    // list2 = mylist; // ���� ����. (shallow copy)
    mylist.copyTo(list2); // ���� ����. (deep copy)

    mylist.set(0,21);
    cout << list2.get(0) << " " << list2.get(1) << endl;

    IntList list3(mylist);
    cout << list3.get(0) << " " << list3.get(1) << endl;
    return 0;
}
