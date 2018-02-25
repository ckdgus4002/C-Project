#include <iostream>
using namespace std;


class Book {
    string title;  // å ����
    int price;     // å ����
    int weight;    // å ����
public:
    Book(){} // ����Ʈ������. ���ھ��� ��ü ����.
    Book(string t, int p, int w) {
        title = t;
        price = p;
        weight = w;
    }
    void setTitle(string t) {
        title = t;
    }
    void setPrice(int p) {
        price = p;
    }
    void setWeight(int w) {
        weight = w;
    }
    string getTitle(){ return title; }
    int getPrice(){ return price; }
    int getWeight(){ return weight; }
};


class BookBox {
    Book **books; // Book*�� ����Ű�� ������ ����
    int cnt, maxnum; //cnt - ���� ������ �Ǽ� maxnum - �ִ� ���� ���� �Ǽ�.
    int max_weight, weight; // �ִ���빫��, ���繫��
public:
    BookBox(int w, int s) {
        cnt = 0;
        weight = 0;
        max_weight = w;

        books = new Book*[s];//sũ�� ��ŭ book* �迭�� ����.
        maxnum = s; //�ִ�ũ��
    }
    void setMaxWeight(int w){ max_weight = w; }
    // å����� ������ �Է¹ް� å �ϳ��� �ڽ��� ���.
    bool isAvalable() {
        return (cnt < maxnum) ? true : false; //()? : ; ���� ������.
    }
    void addBook(){
        string t;
        int p, w;
        if(!isAvalable()) {
            cout << " å �����ڸ��� ������ " <<endl;
            return;
        }
        cout << "���� : "; cin >> t;
        cout << "���� : "; cin >> p;
        cout << "���� : "; cin >> w;
        if((weight+w) > max_weight) {
            cout << "���� �ʰ�!!" << endl;
            return;
        }
        books[cnt++] = new Book(t,p,w);
        weight += w;
    }

    void addBook(string t, int p, int w){
        if(!isAvalable()) {
            cout << " å �����ڸ��� ������ " <<endl;
            return;
        }
        if((weight+w) > max_weight) {
            cout << "���� �ʰ�!!" << endl;
            return;
        }
        //(books+cnt)->setTitle(t); // �ּҸ� ��� �ϰ� ã�ư���
        //(*(book+cnt)).setPrice(p);//������ ���� ��
        books[cnt++] = new Book(t,p,w);
        weight += w;
    }
    void addBook(Book b){
        if(!isAvalable()) {
            cout << " å �����ڸ��� ������ " <<endl;
            return;
        }
        if((weight+b.getWeight()) > max_weight) {
            cout << "���� �ʰ�!!" << endl;
            return;
        }
        books[cnt++] = new Book(b.getTitle(), b.getPrice(), b.getWeight());
        weight += b.getWeight();
    }
    void listBook(){
        for(int i=0; i<cnt; i++)
            cout << i+1 << ":" << books[i]->getTitle() << "("
                 << books[i]->getPrice() << "��) - " << books[i]->getWeight() << endl;
    }
    int getAmount(){
        int sum = 0;
        for(int i=0; i<cnt; i++) sum += books[i]->getPrice();
        return sum;
    }
    int position(string t){  // å������ å�� ��ġ ��ȯ
        for(int i=0; i<cnt; i++)
            if(books[i]->getTitle() == t) return i;
        return -1;
    }
    bool isExist(string t){  // å�������� �� å�� �ִ��� ������ �˷���.
        if(position(t) == -1) return false;
        else return true;
    }
    Book getBook(string t){  // å������ �ش� å�� ��ȯ
        int p;
        if((p = position(t)) >= 0) return *books[p];
        else {
            Book b("", 0, 0); // ����ִ� å
            return b;
        }
    }
    Book getBook(int p){ return *books[p]; }
    int getWeight(){ return weight; }
    Book pickBook(int p){
        Book pick = *books[p]; // ���� å�� ���� ����.
        for(int i=p; i<cnt; i++) books[i] = books[i+1]; // ��ĭ �ڿ� �ִ� ���� ���⿡ ����.
        cnt--;
        return pick;
    }
};

int main()
{
    BookBox box(25, 8), box2(40, 15);
    box.setMaxWeight(30);

    box.addBook();

    string t = "�����ý��丮";
    int p = 12500;
    int w = 6;
    box.addBook(t,p,w);

    t = "�ظ�����";
    p = 21000;
    w = 7;
    Book b(t,p,w);
    box.addBook(b);

    box.listBook();
    cout << "å ��ü ���� = " << box.getAmount() << "��" << endl;

    if(box.isExist("�����ý��丮"))
        cout << "��ġ : " << box.position("�����ý��丮")+1 << endl;
    else cout << "å�� ����. \n";
    b = box.getBook("�ظ�����");
    cout << b.getTitle() << "("
         << b.getPrice() << "��)" << endl;
    b = box.getBook(box.position("�����ý��丮"));

    b = box.pickBook(box.position("�����ý��丮"));
    box2.addBook(b);
    cout << "å �̵� ��� : " << endl;
    box.listBook();
    box2.listBook();

    return 0;
}













