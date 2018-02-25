#include <iostream>
using namespace std;

class Drive{
private:
    int speed, dist, hour, price, milePrice;
    double minute, mileage;
public:
    void setSpeed(int s) {
        speed = s;
    }
    void setDist(int d) {
        dist = d;
    }
    void setMileage(double m) {
        mileage = m;
    }
    void setPrice(int p) {
        price = p;
    }


    int getHour() {
        return hour;
    }
    int getMinute() {
        return minute;
    }
    double getMilePrice() {
        return milePrice;
    }


    void time() {
        hour = dist / speed;
        minute = ((double)dist / (double)speed - hour) * 60;
    }

    void MilePrice() {
        milePrice = (double)dist / mileage * price;
    }
};



int main() {
    Drive drive;
    int speed, dist;

    cout << "여행 소요시간과 연료비용을 산출하는 프로그램 입니다." << endl;
    cout << "평균속도와 여행거리: "; cin >> speed >> dist;
    drive.setSpeed(speed);
    drive.setDist(dist);
    drive.time();
    cout << "소요시간 = " << drive.getHour() << "시간 " << drive.getMinute() << "분" << endl;

    double mileage;
    int price;
    cout << "연비와 연료가격: "; cin >> mileage >> price;
    drive.setMileage(mileage);
    drive.setPrice(price);
    drive.MilePrice();
    cout << "소요 연료비(거리/연비*연료가격) = " << drive.getMilePrice() << "원";
    return 0;
}
