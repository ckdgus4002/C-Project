#include <iostream>
using namespace std;

//자판기의 동전 거스름기를 만들려고 한다.
//투입금액과 구매금액의 입력받고 거스름돈을 계산한 다음
//500원, 100원, 50원, 10원 동전의 개수를 산출한다.
//main 함수를 보고 CoinChanger 클래스를 완성한다.

class CoinChanger {
private:
    int fH, oH, fT, oT;
    int paid, buyed, change;
public:
//constructor
    CoinChanger(int fh, int oh, int ft, int t): fH(fh), oH(oh), fT(ft), oT(t) {
    }
//setter
    void setPaid(int p) {
        paid = p;
    }
    void setBuyed(int b) {
        buyed = b;
        change = paid - buyed; // 투입금액 - 구매금액
    }
//getter
    int getChange() {
        return change;
    }
//memberFunction
    bool is_changable() {
        if(change > fH*500 + oH*100 + fT*50 + oT*10) return false;
        else return true;
    }

    void coinChange() {
        // 거스름돈의 동전 종류별 개수를 산출하여 출력한다. 이때 남은 동전 수를 거스름돈 만큼 감소시킨다.
        cout << change / 500 << " / "; fH -= change/500; change -= (change/500) * 500;
        cout << change / 100 << " / "; oH -= change/100; change -= (change/100) * 100;
        cout << change /  50 << " / "; fT -= change/50; change -= (change/50) * 50;
        cout << change /  10;          oT -= change/10; change -= (change/10) * 10;
    }
};

int main() {
    CoinChanger cc(5,10,7,20);  // 동전 종류의 개수로 초기화 한다.
    int paid, buyed; // 투입금액과 구매금액 입력 변수

    cout << "투입금액과 구매금액 : "; cin >> paid >> buyed;
    cc.setPaid(paid);
    cc.setBuyed(buyed);  // 구매금액을 저장하고 거스름돈을 계산해 둔다.
    cout << "거스름돈 : " << cc.getChange() << "원" << endl;

    // 남은 동전 개수로 거스름돈을 지불할 수 있는지 아닌지 판단한다. // true or false
    if(cc.is_changable()) {
        cout << "[500/100/50/10] : ";
        cc.coinChange();
    }
    else cout << "동전이 충분하지 않습니다.";
    return 0;
}
