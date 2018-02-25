#include <iostream>
using namespace std;

class Date {
private:
    int year, month, day;


public:
    Date() {
    }
    Date(int y, int m, int d):year(y), month(m), day(d) {}


    int getYear() {
        return year;
    }
    int getMonth() {
        return month;
    }
    int getDay() {
        return day;
    }
};


class Arbeit {
private:
    Date start_date;
    string name;
    int day, night, hourPay, pay, totalPay;

public:
    //생성자(constructor) : 멤버변수 초기화.
    //생성자를 선언 안하면 클래스는 비어있는 생성자를 자동으로 만들어 실행함. ex) Arebit() {} 실행.
    Arbeit(): start_date(2017, 1, 1), totalPay(0) {
    }
    Arbeit(string n, int hP): totalPay(0), name(n), hourPay(hP) {
    }
    Arbeit(string n, int hP, int y, int m, int d): start_date(y, m, d), totalPay(0), name(n), hourPay(hP) {
    }


    //setter
    void setName(string a) {
        name = a;
    }
    void setHourPay(int a) {
        hourPay = a;
    }
    void setWorkHours(int a, int b) {
        day = a;
        night = b;
    }


    //getter
    string getName() {
        return name;
    }

    int getDay() {
        return day;
    }

    int getNight() {
        return night;
    }

    int getPay() {
        return pay;
    }
    int getTotalPay() {
        return totalPay;
    }
    Date getStartDate() {
        return start_date;
    }


    //member function
    void calcPay() {
        pay = day * hourPay + (int)(night * hourPay * 1.1);
    }

    void paid() {
        totalPay += pay;
        pay = day = night = 0;
    }
};

int main() {
    Arbeit emp1; // emp1객체변수를 생성할 때 자동으로 arebit() 호출.
    Arbeit emp2("Tom", 7000);
    Arbeit emp3("Dorl", 7100, 2017, 10, 2);

    cout << "이름: " << emp3.getName() << endl;;
    cout << "근무시작일자: " << emp3.getStartDate().getYear() << "/" << emp3.getStartDate().getMonth() << "/" << emp3.getStartDate().getDay() << endl;

    emp1.setName("Jenny");
    emp1.setHourPay(6700);
    emp2.setWorkHours(45,21); //주간근무시간, 야간근무시간.
    emp2.calcPay(); //급여계산

    cout << "이름: " << emp2.getName() << endl;
    cout << "일한시간: " << emp2.getDay() << ", " << emp2.getNight() << endl;
    cout << "당월급여: " << emp2.getPay() << endl;

    emp2.paid();
    cout << "총 지불 금액: " << emp2.getTotalPay() << endl;
    return 0;
}
