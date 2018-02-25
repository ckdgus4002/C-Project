/*시험범위
클래스,오버로딩,오버라이딩,상속,다형성,배열,동적배열,포인터
예제꼼꼼히 보고 주석 이해하기.
예를들어 오버라이딩 코드를 적으라고 나옴.*/

#include <iostream>
#include <fstream> // 파일 입출력 처리 헤더파일.
using namespace std;

class Food{
private:
    string name;
    int price, qty;
public:
    Food() {}
    Food(string n, int p, int q) {
        name = n; price = p; qty = q;
    }
    string GetName() { return name; }
    int GetPrice() { return price; }
    int GetQty() { return qty; }
};

int main() {
    Food food[10];
    ifstream infile;
    ofstream outfile;
    string name;
    int price, qty, cnt = 0;


    infile.open("food.txt"); // 파일의 내용을 읽기 위해 열기.
    if(infile.fail()) { //파일 없으면 fail.
        cout << "ERROR1: Can't open file: indata.txt"; return 0;
    }



    // 파일에서 입력받고 food 배열에 넣기.
    infile >> name >> price >> qty;
    while(!infile.eof()) { //파일의 끝을 읽지 않았으면 while문 실행.
        Food f(name, price, qty);
        food[cnt++] = f;
        infile >> name >> price >> qty;
    }
    cout << "파일읽기완료: 레코드수(" << cnt + 1 << "개)" << endl;
    infile.close(); // 파일 닫기



    // 키보드에서 입력받고 food 배열에 저장하기.
    for (int i = 0; i < 2; i++) {
        cout << "Food name: "; cin >> name;
        cout << "Food price: "; cin >> price;
        cout << "Food qty: "; cin >> qty;
        Food f(name, price, qty);
        food[cnt++] = f;
    }



    // 파일에 내용을 기록하기 위해 열기.
    // 파일이 있으면 지우고 새로 쓰고, 없으면 새로 만든다.
    outfile.open("food.txt");
    if(outfile.fail()) {
        cout << "ERROR2: Can't open file: outdata.txt"; return 0;
    }


    // Food 배열 화면에 출력하기.
    // food배열을 food.txt 파일에 기록하기.
    for(int i = 0; i < cnt; i++) {
        outfile/*cout*/ << food[i].GetName() << " " << food[i].GetPrice()
        << " " << food[i]. GetQty() << endl;
    }
    outfile.close(); //파일 닫기.

    return 0;
}
