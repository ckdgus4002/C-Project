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
        if(i == 3) cout << name << " / " << tel << " / " << date << "회 / " << fee << "원 / " << point << "p" << endl;
        else cout <<   "정회원 / " << tel << " / " << date << "회 / " << fee << "원 / " << point << "p" << endl;
    }
    void print(ofstream& out) {
        out << 1 << " " << name << " " << tel << " " << date << " " << fee << " " << point << endl;
    }
    void visit() {
        cout << date << "회에서 1회 차감합니다."; date--; cout << "남은 횟수 = " << date << "회" << endl;
        cout << "회원탈퇴 시 반환 예상금액(남은횟수 * 1회이용료) = " << date*8000 << "원";
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
        if(i == 3) cout << name << " / " << tel << " / " << coupon << "장" << endl;
        else cout << "임시회원 / " << tel << " / " << coupon << "장" << endl;
    }
    void print(ofstream& out) {
        out << 2 << " " << name << " " << tel << " " << coupon << endl;
    }
    void visit() {
        cout << coupon << "장에서 1장 차감합니다."; coupon--; cout << "남은 쿠폰 = " << coupon << "장" << endl;
    }
};

class MemberMgr{
private:
    Member * *members; // *Member 를 가리키는 포인터 변수.
    int max_cnt, cnt;
public:
    MemberMgr() {
        members = new Member*[100]; // 100만큼 Member* 배열을 생성.
        max_cnt = 100;
        cnt = 0;
    }

    void loadData() {
        ifstream in;
        int type, date, fee, point, coupon;
        string name, tel;

        in.open("sports.txt");
        if(in.fail()) cout << "파일열기실패: sports.txt" << endl << endl << endl;
        else { // 파일 읽기 성공했을 때.
            in >> type;
            while(!in.eof()){ // 공백파일이 아닐때.
                if(type == 1) {
                    in >> name >> tel >> date >> fee >> point;
                    members[cnt++] = new PaidMember(type,name,tel,date,fee,point);
                }
                else { // type이 2일 때.
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
    cout << "     1. 정회원등록" << endl;
    cout << "     2. 임시회원등록" << endl;
    cout << "     3. 회원목록" << endl;
    cout << "     4. 회원검색" << endl;
    cout << "     5. 회원방문" << endl;
    cout << "     0. 종료(저장)" << endl;
    cout << "--------------------------" << endl;;
    while(true) {
        cout << "menu> "; int menu; cin >> menu;
        switch(menu) {
        case 1: {
            cout << "이름/전화번호/기간(일)/회비/포인트 : "; cin >> name >> tel >> date >> fee >> point;
            PaidMember *p = new PaidMember(1, name, tel, date, fee, point);
            mgr.addMember(p);
            cout << "신규 정회원 등록 완료(" << name << ")" ;
            break;
        }
        case 2: {
            cout << "이름/전화번호/쿠폰 : "; cin >> name >> tel >> coupon;
            TrialMember *t = new TrialMember(2, name, tel, coupon);
            mgr.addMember(t);
            cout << "신규 임시회원 등록 완료(" << name << ")" ;
            break;
        }
        case 3:
            mgr.showMembers();
            break;
        case 4:
            cout << "회원명 : "; cin >> name;
            mgr.findMember(name);
            break;
        case 5:
            cout << "회원명 : "; cin >> name;
            mgr.visitCenter(name);
            break;
        default:
            mgr.saveData();
            cout << "성공적인 저장 완료. 프로그램을 종료합니다." << endl;
            return 0;
        }
        cout << endl << endl;
    }
}
