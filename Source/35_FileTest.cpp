/*�������
Ŭ����,�����ε�,�������̵�,���,������,�迭,�����迭,������
�����Ĳ��� ���� �ּ� �����ϱ�.
������� �������̵� �ڵ带 ������� ����.*/

#include <iostream>
#include <fstream> // ���� ����� ó�� �������.
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


    infile.open("food.txt"); // ������ ������ �б� ���� ����.
    if(infile.fail()) { //���� ������ fail.
        cout << "ERROR1: Can't open file: indata.txt"; return 0;
    }



    // ���Ͽ��� �Է¹ް� food �迭�� �ֱ�.
    infile >> name >> price >> qty;
    while(!infile.eof()) { //������ ���� ���� �ʾ����� while�� ����.
        Food f(name, price, qty);
        food[cnt++] = f;
        infile >> name >> price >> qty;
    }
    cout << "�����б�Ϸ�: ���ڵ��(" << cnt + 1 << "��)" << endl;
    infile.close(); // ���� �ݱ�



    // Ű���忡�� �Է¹ް� food �迭�� �����ϱ�.
    for (int i = 0; i < 2; i++) {
        cout << "Food name: "; cin >> name;
        cout << "Food price: "; cin >> price;
        cout << "Food qty: "; cin >> qty;
        Food f(name, price, qty);
        food[cnt++] = f;
    }



    // ���Ͽ� ������ ����ϱ� ���� ����.
    // ������ ������ ����� ���� ����, ������ ���� �����.
    outfile.open("food.txt");
    if(outfile.fail()) {
        cout << "ERROR2: Can't open file: outdata.txt"; return 0;
    }


    // Food �迭 ȭ�鿡 ����ϱ�.
    // food�迭�� food.txt ���Ͽ� ����ϱ�.
    for(int i = 0; i < cnt; i++) {
        outfile/*cout*/ << food[i].GetName() << " " << food[i].GetPrice()
        << " " << food[i]. GetQty() << endl;
    }
    outfile.close(); //���� �ݱ�.

    return 0;
}
