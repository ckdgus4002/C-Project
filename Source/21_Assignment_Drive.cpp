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

    cout << "���� �ҿ�ð��� �������� �����ϴ� ���α׷� �Դϴ�." << endl;
    cout << "��ռӵ��� ����Ÿ�: "; cin >> speed >> dist;
    drive.setSpeed(speed);
    drive.setDist(dist);
    drive.time();
    cout << "�ҿ�ð� = " << drive.getHour() << "�ð� " << drive.getMinute() << "��" << endl;

    double mileage;
    int price;
    cout << "����� ���ᰡ��: "; cin >> mileage >> price;
    drive.setMileage(mileage);
    drive.setPrice(price);
    drive.MilePrice();
    cout << "�ҿ� �����(�Ÿ�/����*���ᰡ��) = " << drive.getMilePrice() << "��";
    return 0;
}
