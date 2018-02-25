#include <iostream>
using namespace std;


class Book {
    string title;  // 책 제목
    int price;     // 책 가격
    int weight;    // 책 무게
public:
    Book(){} // 디폴트생성자. 인자없이 객체 생성.
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
    Book **books; // Book*를 가리키는 포인터 변수
    int cnt, maxnum; //cnt - 현재 보관된 권수 maxnum - 최대 보관 가능 권수.
    int max_weight, weight; // 최대허용무게, 현재무게
public:
    BookBox(int w, int s) {
        cnt = 0;
        weight = 0;
        max_weight = w;

        books = new Book*[s];//s크기 만큼 book* 배열을 생성.
        maxnum = s; //최대크기
    }
    void setMaxWeight(int w){ max_weight = w; }
    // 책제목과 가격을 입력받고 책 하나를 박스에 담기.
    bool isAvalable() {
        return (cnt < maxnum) ? true : false; //()? : ; 조건 연산자.
    }
    void addBook(){
        string t;
        int p, w;
        if(!isAvalable()) {
            cout << " 책 보관자리가 부족함 " <<endl;
            return;
        }
        cout << "제목 : "; cin >> t;
        cout << "가격 : "; cin >> p;
        cout << "무게 : "; cin >> w;
        if((weight+w) > max_weight) {
            cout << "무게 초과!!" << endl;
            return;
        }
        books[cnt++] = new Book(t,p,w);
        weight += w;
    }

    void addBook(string t, int p, int w){
        if(!isAvalable()) {
            cout << " 책 보관자리가 부족함 " <<endl;
            return;
        }
        if((weight+w) > max_weight) {
            cout << "무게 초과!!" << endl;
            return;
        }
        //(books+cnt)->setTitle(t); // 주소를 계산 하고 찾아가기
        //(*(book+cnt)).setPrice(p);//위에랑 같은 뜻
        books[cnt++] = new Book(t,p,w);
        weight += w;
    }
    void addBook(Book b){
        if(!isAvalable()) {
            cout << " 책 보관자리가 부족함 " <<endl;
            return;
        }
        if((weight+b.getWeight()) > max_weight) {
            cout << "무게 초과!!" << endl;
            return;
        }
        books[cnt++] = new Book(b.getTitle(), b.getPrice(), b.getWeight());
        weight += b.getWeight();
    }
    void listBook(){
        for(int i=0; i<cnt; i++)
            cout << i+1 << ":" << books[i]->getTitle() << "("
                 << books[i]->getPrice() << "원) - " << books[i]->getWeight() << endl;
    }
    int getAmount(){
        int sum = 0;
        for(int i=0; i<cnt; i++) sum += books[i]->getPrice();
        return sum;
    }
    int position(string t){  // 책제목의 책의 위치 반환
        for(int i=0; i<cnt; i++)
            if(books[i]->getTitle() == t) return i;
        return -1;
    }
    bool isExist(string t){  // 책제목으로 그 책이 있는지 없는지 알려줌.
        if(position(t) == -1) return false;
        else return true;
    }
    Book getBook(string t){  // 책제목의 해당 책을 반환
        int p;
        if((p = position(t)) >= 0) return *books[p];
        else {
            Book b("", 0, 0); // 비어있는 책
            return b;
        }
    }
    Book getBook(int p){ return *books[p]; }
    int getWeight(){ return weight; }
    Book pickBook(int p){
        Book pick = *books[p]; // 꺼낼 책을 따로 보관.
        for(int i=p; i<cnt; i++) books[i] = books[i+1]; // 한칸 뒤에 있는 것을 여기에 복사.
        cnt--;
        return pick;
    }
};

int main()
{
    BookBox box(25, 8), box2(40, 15);
    box.setMaxWeight(30);

    box.addBook();

    string t = "메이플스토리";
    int p = 12500;
    int w = 6;
    box.addBook(t,p,w);

    t = "해리포터";
    p = 21000;
    w = 7;
    Book b(t,p,w);
    box.addBook(b);

    box.listBook();
    cout << "책 전체 가격 = " << box.getAmount() << "원" << endl;

    if(box.isExist("메이플스토리"))
        cout << "위치 : " << box.position("메이플스토리")+1 << endl;
    else cout << "책이 없음. \n";
    b = box.getBook("해리포터");
    cout << b.getTitle() << "("
         << b.getPrice() << "원)" << endl;
    b = box.getBook(box.position("메이플스토리"));

    b = box.pickBook(box.position("메이플스토리"));
    box2.addBook(b);
    cout << "책 이동 결과 : " << endl;
    box.listBook();
    box2.listBook();

    return 0;
}













