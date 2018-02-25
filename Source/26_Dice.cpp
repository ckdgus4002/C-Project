#include <iostream>
#include <stdlib.h> // srand(), rand()
#include <time.h> // time()
using namespace std;

class Dice{
private:
    int num;
public:
    int roll() {
        return rand() % 6 + 1;
    }
};

class Tong{
private:
     int score, cnt;
     Dice *dices;
public:
    Tong(){
    }
    Tong(int c) {
        cnt = c;
        dices = new Dice[c];
        score = 0;
    }
    int Play() {
        for(int i = 0; i < cnt; i++) {
            score += dices[i].roll();
        }
        return score;
    }
};

int main() {
    Tong t1(3), t2(3);
    srand(time(NULL));
    cout << "Tong1 : " << t1.Play() << endl;
    cout << "Tong2 : " << t2.Play() << endl;
    return 0;
}
