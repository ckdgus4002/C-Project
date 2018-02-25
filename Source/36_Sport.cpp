#include <iostream>
#include <fstream>
using namespace std;

class Member {
protected:
    string name, tel;
    int type;
public:
    Member(int ty, string n, string te) {
        type = ty;
        name = n;
        tel = te;
    }
    string getName() {
        return name;
    }
    virtual void showMember(int i) = 0;
    virtual void print(ofstream&) = 0;
    virtual void visit() = 0;
};

class PaidMember : public Member {
private:
    int date, fee, point;
public:
    PaidMember(int ty, string n, string te, int d, int f, int p) : Member(ty, n, te) {
        date = d;
        fee = f;
        point = p;
    }
    void showMember(int i) {
        if(i == 3) cout << name << " / " << tel << " / " << date << "ȸ / " << fee << "�� / " << point << "p" << endl;
        else cout <<   "��ȸ�� / " << tel << " / " << date << "ȸ / " << fee << "�� / " << point << "p" << endl;
    }
    void print(ofstream& out) {
        out << 1 << " " << name << " " << tel << " " << date << " " << fee << " " << point << endl;
    }
    void visit() {
        cout << date << "ȸ���� 1ȸ �����մϴ�."; date--; cout << "���� Ƚ�� = " << date << "ȸ" << endl;
        cout << "ȸ��Ż�� �� ��ȯ ����ݾ�(����Ƚ�� * 1ȸ�̿��) = " << date*8000 << "��";
    }
};

class TrialMember : public Member {
private:
    int coupon;
public:
    TrialMember(int ty, string n, string te, int c) : Member(ty, n, te) {
        coupon = c;
    }
    void showMember(int i) {
        if(i == 3) cout << name << " / " << tel << " / " << coupon << "��" << endl;
        else cout << "�ӽ�ȸ�� / " << tel << " / " << coupon << "��" << endl;
    }
    void print(ofstream& out) {
        out << 2 << " " << name << " " << tel << " " << coupon << endl;
    }
    void visit() {
        cout << coupon << "�忡�� 1�� �����մϴ�."; coupon--; cout << "���� ���� = " << coupon << "��" << endl;
    }
};

class MemberMgr{
private:
    Member * *members; // *Member �� ����Ű�� ������ ����.
    int max_cnt, cnt;
public:
    MemberMgr() {
        members = new Member*[100]; // 100��ŭ Member* �迭�� ����.
        max_cnt = 100;
        cnt = 0;
    }

    void loadData() {
        ifstream in;
        int type, date, fee, point, coupon;
        string name, tel;

        in.open("sports.txt");
        if(in.fail()) cout << "���Ͽ������: sports.txt" << endl << endl << endl;
        else { // ���� �б� �������� ��.
            in >> type;
            while(!in.eof()){ // ���������� �ƴҶ�.
                if(type == 1) {
                    in >> name >> tel >> date >> fee >> point;
                    members[cnt++] = new PaidMember(type,name,tel,date,fee,point);
                }
                else { // type�� 2�� ��.
                    in >> name >> tel >> coupon;
                    members[cnt++] = new TrialMember(type,name,tel,coupon);
                }
                in >> type;
            }
        }
    }

    void showMembers() {
        for(int i = 0; i < cnt; i++) {
            cout << i + 1 << ") ";
            members[i]->showMember(3);
        }
    }

    void saveData() {
        ofstream out;
        out.open("sports.txt");
        for(int i = 0; i < cnt; i ++) members[i]->print(out);
        out.close();
    }

    void addMember(PaidMember *p) {
        members[cnt++] = p;
    }

    void addMember(TrialMember *t) {
        members[cnt++] = t;
    }

    void findMember(string name) {
        for(int i = 0; i < cnt; i++) {
            if(name == members[i]->getName()) {
                members[i]->showMember(4);
            }
        }
    }
    void visitCenter(string name) {
        for(int i = 0; i < cnt; i++) {
            if(name == members[i]->getName()) {
                members[i]->visit();
            }
        }
    }
};

int main() {
    string name, tel;
    int coupon, date, fee, point/*type*/;
    MemberMgr mgr;
    mgr.loadData();

    cout << ">>>> DJ Sports Center <<<<" << endl;
    cout << "     1. ��ȸ�����" << endl;
    cout << "     2. �ӽ�ȸ�����" << endl;
    cout << "     3. ȸ�����" << endl;
    cout << "     4. ȸ���˻�" << endl;
    cout << "     5. ȸ���湮" << endl;
    cout << "     0. ����(����)" << endl;
    cout << "--------------------------" << endl;;
    while(true) {
        cout << "menu> "; int menu; cin >> menu;
        switch(menu) {
        case 1: {
            cout << "�̸�/��ȭ��ȣ/�Ⱓ(��)/ȸ��/����Ʈ : "; cin >> name >> tel >> date >> fee >> point;
            PaidMember *p = new PaidMember(1, name, tel, date, fee, point);
            mgr.addMember(p);
            cout << "�ű� ��ȸ�� ��� �Ϸ�(" << name << ")" ;
            break;
        }
        case 2: {
            cout << "�̸�/��ȭ��ȣ/���� : "; cin >> name >> tel >> coupon;
            TrialMember *t = new TrialMember(2, name, tel, coupon);
            mgr.addMember(t);
            cout << "�ű� �ӽ�ȸ�� ��� �Ϸ�(" << name << ")" ;
            break;
        }
        case 3:
            mgr.showMembers();
            break;
        case 4:
            cout << "ȸ���� : "; cin >> name;
            mgr.findMember(name);
            break;
        case 5:
            cout << "ȸ���� : "; cin >> name;
            mgr.visitCenter(name);
            break;
        default:
            mgr.saveData();
            cout << "�������� ���� �Ϸ�. ���α׷��� �����մϴ�." << endl;
            return 0;
        }
        cout << endl << endl;
    }
}
