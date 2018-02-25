#include <iostream>
using namespace std;

class Item{
private:
    string name; // 이름.
    int price, qty; // 가격, 수량.
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
    int maxcnt; // items의 총 개수.
    int delivery; // 배송비.
    int total, cnt; // 구매총액, 상품갯수,
    Item **items;
public:
    //constructor
    Cart(int m) {
        cnt = 0;
        maxcnt = m;
        items = new Item*[maxcnt]; // maxcnt 만큼의 Item* 배열 생성
    }

    // 상품 추가하고 추가한 위치 반환
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

    // 상품명으로 검색 후 위치 반환
    int position(string n) {
        for(int i = 0; i < cnt; i++)
            if(items[i]->getName() == n)
                return i;
        return -1;
    }

    // 상품 삭제 후 true(성공), false(실패)
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

    // 목록 및 배송비, 구매총액 출력
    // 배송비. 5만원 넘으면 무료. 기본 3,000원.
    void listItems() {
        total = 0;
        for(int i = 0; i < cnt; i++) {
            cout << i << ". " << items[i]->getName() << ", \\" << items[i]->getPrice() << ", " << items[i]->getQty() << "개" << endl;
            total += items[i]->getPrice() * items[i]->getQty();
        }
        if(total >= 50000 ) delivery = 0;
        else delivery = 3000;
        cout << "배송비: " << delivery << "원, 구매총액: " << total << "원" << endl;
    }
};

int main() {
    Cart myCart(10);
    int n = 5;  // 장바구니에 담을 상품 개수
    // 장바구니에 상품 담기
    for(int i = 0; i < n; i++) {
        string name;
        int price, qty;
        // 입력 후 장바구니에 등록하는 구문 작성
        cout << i << ". 이름을 입력하여 주십시오: "; cin >> name;
        cout << i << ". 가격를 입력하여 주십시오: "; cin >> price;
        cout << i << ". 수량을 입력하여 주십시오: "; cin >> qty;
        myCart.addItem(name, price, qty);
        Item item(name, price, qty);
        myCart.addItem(item);
        //myCart.addItem(new item(name, price, qty));
    }

    myCart.listItems();  // 장바구니 출력


    // 상품 삭제. 삭제할 상품명 입력
    cout << "지금부터 신라면을 삭제하기 위해 myCart.delItem(""신라면"")을 실행하겠습니다." << endl;
    myCart.delItem("신라면");
    myCart.listItems();  // 장바구니 출력
    cout << "지금부터 신라면을 삭제하기 위해 myCart.delItem(""신라면"")을 실행하겠습니다." << endl;
    myCart.delItem("신라면");
    myCart.listItems();  // 장바구니 출력
    return 0;
}
