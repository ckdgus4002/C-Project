#include <iostream>
#include <fstream>
#include <string> // 파일을 읽어올때 string형 변수에 저장하기 위해 선언
using namespace std;

class Schedule {
protected:
	int type, month, day; // 자식클래스 구분을 위한 type, 월, 일
	string dotw; // 요일
	string text; // 일정내용
public:
	Schedule(int t, int m, int d, string dot, string te) {
		type = t;
		month = m;
		day = d;
		dotw = dot;
		text = te;
	}
	virtual void showList() = 0;
	virtual void savaData(ofstream&) = 0;
};

class SiSchedule : public Schedule {
private:
	string time; // 약속시간
public:
	SiSchedule(int t, int m, int d, string dot, string ti, string te) : Schedule(t, m, d, dot, te) {
		time = ti;
	}
	void showList() {
		cout << month << "월." << day << "일." << dotw << "요일." << time << "." << text << endl;
	}
	void savaData(ofstream& out) {
		out << 1 << " " << month << " " << day << " " << dotw << " " << time << " " << text << endl;
	}
};

class IlSchedule : public Schedule {
private:
	string notes; // 참고사항
public:
	IlSchedule(int t, int m, int d, string dot, string n, string te) : Schedule(t, m, d, dot, te) {
		notes = n;
	}
	void showList() {
		cout << month << "월." << day << "일." << dotw << "요일." << notes << "." << text << endl;
	}
	void savaData(ofstream& out) {
		out << 2 << " " << month << " " << day << " " << dotw << " " << notes << " " << text << endl;
	}
};

class ScheduleMgr {
private:
	Schedule **schedules; // *schedules 를 가리키는 포인터 변수.
	int max_cnt, cnt;
public:
	ScheduleMgr() {
		schedules = new Schedule*[99];
		max_cnt = 99;
		cnt = 0;
	}

	~ScheduleMgr() {
		delete[] schedules;
	}

	void loadData() {
		ifstream in;
		int type, month, day;
		string dotw;
		string time, notes, text;

		in.open("schedule.txt");
		if (in.fail()) cout << endl << "[ERROR_1] 파일이 없습니다: schedule.txt" << endl << endl;
		else { // 파일 읽기 성공했을 때.
			in >> type;
			while (!in.eof()) { // 공백파일이 아닐때.
				if (type == 1) {
					in >> month >> day >> dotw >> time >> text;
					schedules[cnt++] = new SiSchedule(type, month, day, dotw, time, text);
				}
				else { // type이 2일 때.
					in >> month >> day >> dotw >> notes >> text;
					schedules[cnt++] = new IlSchedule(type, month, day, dotw, notes, text);
				}
				in >> type;
			}
		}
	}

	void showLists() {
		for (int i = 0; i < cnt; i++) {
			cout << i + 1 << ") ";
			schedules[i]->showList();
		}
	}

	void saveData() {
		ofstream out;
		out.open("schedule.txt");
		for (int i = 0; i < cnt; i++) schedules[i]->savaData(out);
		out.close();
	}

	void add(SiSchedule *s) {
	schedules[cnt++] = s;
	}

	void add(IlSchedule *i) {
	schedules[cnt++] = i;
	}
};

void printIntro();
int main() {
	ScheduleMgr mgr;
	mgr.loadData();
	printIntro();

	while (true) {
		int month, day, menu; // 몇월, 며칠, switch함수 제어를 위한 int형 변수.
		string dotw, time, notes, text; // dayOfTheWeek, 시간, 몇시부터 몇시까지, 일정내용
		cout << endl << "메뉴> "; cin >> menu;
		switch (menu) {
		case 1: {
			cout << "몇월/며칠/무슨요일/몇시시작/일정내용 : "; cin >> month >> day >> dotw >> time >> text;
			SiSchedule *s = new SiSchedule(1, month, day, dotw, time, text);
			mgr.add(s);
			cout << "신규 시간 일정 등록 완료(" << text << ")" << endl;
			break;
		}
		case 2: {
			cout << "몇월/며칠/무슨요일/몇시부터 몇시까지/일정내용 : "; cin >> month >> day >> dotw >> notes >> text;
			IlSchedule *i = new IlSchedule(2, month, day, dotw, notes, text);
			mgr.add(i);
			cout << "신규 하루 일정 등록 완료(" << text << ")" << endl;
			break;
		}
		case 3:
			mgr.showLists();
			break;
		default:
			mgr.saveData(); cout << "성공적인 저장 완료";
			cout << "프로그램을 종료합니다." << endl << endl; return 0;
		}
	}
}

void printIntro() {
	cout << ">>>>>>   창현 Schedule Manager   <<<<<<" << endl;
	cout << "     간편하게 일정을 관리해보세요.     " << endl;
	cout << "         1. 시간일정등록" << endl;
	cout << "         2. 하루일정등록" << endl;
	cout << "         3. 일정목록" << endl;
	cout << "         0. 종료(저장)" << endl;
	cout << "---------------------------------------" << endl;
}