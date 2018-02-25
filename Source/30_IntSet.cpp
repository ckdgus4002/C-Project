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
    //const를 붙여야 더 정확한데, 함수입장에서는 꺼내서 참조만 하려는거지,
    //값을 바꾸려는게 아니기 때문이다.
    IntList(const IntList& from) {
        cnt = 0;
        length = from.getLength();
        list = new int*[length];
        for(int i = 0; i < from.size(); i++)
            add(from.get(i));
    }

    //소멸자(Distructor). 객체가 메모리에서 제거되기 전에 실행.
    ~IntList() {
        //list가 배열로 만들어졌기 때문에 delete 뒤에 []를 붙인다.
        delete[] list;
    }

    //여기서의 const는 getLenght는 값을 바꾸지 않는다는것을 표시하는 용도다.
    int getLength() const {
        return length;
    }
    //여기서의 const는 getLenght는 값을 바꾸지 않는다는것을 표시하는 용도다.
    int size() const {
        return cnt;
    }

    //add(), get(), set() 함수는 줄이 짧은 인라인(InLine) 함수라고 부른다.
    //인라인 함수는 사용 시 함수를 그대로 복붙해서 컴파일한다. 즉 함수호출이 없기 때문에
    //시간이 조금이나마 빠르다. but코드가 길어지는 단점이 있다.
    void add(int n) {
        if(cnt < length) {
            list[cnt] = new int; // 정수 한개 공간을 생성.
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
    IntList mylist(5), list2(5); //5개가 들어갈 리스트.

    mylist.add(3);
    mylist.add(5);

    //리스트의 0번째와 1번째 출력.
    cout << mylist.get(0) << " " << mylist.get(1) << endl;

    // list2 = mylist; // 얕은 복사. (shallow copy)
    mylist.copyTo(list2); // 깊은 복사. (deep copy)

    mylist.set(0,21);
    cout << list2.get(0) << " " << list2.get(1) << endl;

    IntList list3(mylist);
    cout << list3.get(0) << " " << list3.get(1) << endl;
    return 0;
}
