#include <iostream>
using namespace std;

class Item{
private:
    string name; // �̸�.
    int price, qty; // ����, ����.
public:
    //constructor
    Item(string n, int p, int q) {
        name = n;
        price = p;
        qty = q;
    }
    //setter
    void setName(string n) {
        name = n;
    }
    void setPrcie(int p) {
        price = p;
    }
    void setQty(int q) {
        qty = q;
    }
    //getter
    string getName() {
        return name;
    }
    int getPrice() {
        return price;
    }
    int getQty() {
        return qty;
    }
};

class Cart{
private:
    int maxcnt; // items�� �� ����.
    int delivery; // ��ۺ�.
    int total, cnt; // �����Ѿ�, ��ǰ����,
    Item **items;
public:
    //constructor
    Cart(int m) {
        cnt = 0;
        maxcnt = m;
        items = new Item*[maxcnt]; // maxcnt ��ŭ�� Item* �迭 ����
    }

    // ��ǰ �߰��ϰ� �߰��� ��ġ ��ȯ
    int addItem(string n, int p, int q) {
        int c = cnt;
        items[cnt++] = new Item(n,p,q);
        return c;
    }
    int addItem(Item m) {
        int c = cnt;
        items[cnt++] = new Item(m);
        return c;
    }

    // ��ǰ������ �˻� �� ��ġ ��ȯ
    int position(string n) {
        for(int i = 0; i < cnt; i++)
            if(items[i]->getName() == n)
                return i;
        return -1;
    }

    // ��ǰ ���� �� true(����), false(����)
    bool delItem(string n) {
        int p = position(n);
        if (p < 0) return false;
        else if (p < cnt)
            for(int i = p; i < cnt; i++)
                items[i] = items[i+1];
        cnt--;
        return true;
    }

    bool delItem(int p) {
        if(p < 0) return false;
        else if(p < cnt) for (int i = p; i < cnt; i++) items[i] = items[i+1];
        cnt--;
        return true;
    }

    // ��� �� ��ۺ�, �����Ѿ� ���
    // ��ۺ�. 5���� ������ ����. �⺻ 3,000��.
    void listItems() {
        total = 0;
        for(int i = 0; i < cnt; i++) {
            cout << i << ". " << items[i]->getName() << ", \\" << items[i]->getPrice() << ", " << items[i]->getQty() << "��" << endl;
            total += items[i]->getPrice() * items[i]->getQty();
        }
        if(total >= 50000 ) delivery = 0;
        else delivery = 3000;
        cout << "��ۺ�: " << delivery << "��, �����Ѿ�: " << total << "��" << endl;
    }
};

int main() {
    Cart myCart(10);
    int n = 5;  // ��ٱ��Ͽ� ���� ��ǰ ����
    // ��ٱ��Ͽ� ��ǰ ���
    for(int i = 0; i < n; i++) {
        string name;
        int price, qty;
        // �Է� �� ��ٱ��Ͽ� ����ϴ� ���� �ۼ�
        cout << i << ". �̸��� �Է��Ͽ� �ֽʽÿ�: "; cin >> name;
        cout << i << ". ���ݸ� �Է��Ͽ� �ֽʽÿ�: "; cin >> price;
        cout << i << ". ������ �Է��Ͽ� �ֽʽÿ�: "; cin >> qty;
        myCart.addItem(name, price, qty);
        Item item(name, price, qty);
        myCart.addItem(item);
        //myCart.addItem(new item(name, price, qty));
    }

    myCart.listItems();  // ��ٱ��� ���


    // ��ǰ ����. ������ ��ǰ�� �Է�
    cout << "���ݺ��� �Ŷ���� �����ϱ� ���� myCart.delItem(""�Ŷ��"")�� �����ϰڽ��ϴ�." << endl;
    myCart.delItem("�Ŷ��");
    myCart.listItems();  // ��ٱ��� ���
    cout << "���ݺ��� �Ŷ���� �����ϱ� ���� myCart.delItem(""�Ŷ��"")�� �����ϰڽ��ϴ�." << endl;
    myCart.delItem("�Ŷ��");
    myCart.listItems();  // ��ٱ��� ���
    return 0;
}
