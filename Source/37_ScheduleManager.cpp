#include <iostream>
#include <fstream>
#include <string> // ������ �о�ö� string�� ������ �����ϱ� ���� ����
using namespace std;

class Schedule {
protected:
	int type, month, day; // �ڽ�Ŭ���� ������ ���� type, ��, ��
	string dotw; // ����
	string text; // ��������
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
	string time; // ��ӽð�
public:
	SiSchedule(int t, int m, int d, string dot, string ti, string te) : Schedule(t, m, d, dot, te) {
		time = ti;
	}
	void showList() {
		cout << month << "��." << day << "��." << dotw << "����." << time << "." << text << endl;
	}
	void savaData(ofstream& out) {
		out << 1 << " " << month << " " << day << " " << dotw << " " << time << " " << text << endl;
	}
};

class IlSchedule : public Schedule {
private:
	string notes; // �������
public:
	IlSchedule(int t, int m, int d, string dot, string n, string te) : Schedule(t, m, d, dot, te) {
		notes = n;
	}
	void showList() {
		cout << month << "��." << day << "��." << dotw << "����." << notes << "." << text << endl;
	}
	void savaData(ofstream& out) {
		out << 2 << " " << month << " " << day << " " << dotw << " " << notes << " " << text << endl;
	}
};

class ScheduleMgr {
private:
	Schedule **schedules; // *schedules �� ����Ű�� ������ ����.
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
		if (in.fail()) cout << endl << "[ERROR_1] ������ �����ϴ�: schedule.txt" << endl << endl;
		else { // ���� �б� �������� ��.
			in >> type;
			while (!in.eof()) { // ���������� �ƴҶ�.
				if (type == 1) {
					in >> month >> day >> dotw >> time >> text;
					schedules[cnt++] = new SiSchedule(type, month, day, dotw, time, text);
				}
				else { // type�� 2�� ��.
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
		int month, day, menu; // ���, ��ĥ, switch�Լ� ��� ���� int�� ����.
		string dotw, time, notes, text; // dayOfTheWeek, �ð�, ��ú��� ��ñ���, ��������
		cout << endl << "�޴�> "; cin >> menu;
		switch (menu) {
		case 1: {
			cout << "���/��ĥ/��������/��ý���/�������� : "; cin >> month >> day >> dotw >> time >> text;
			SiSchedule *s = new SiSchedule(1, month, day, dotw, time, text);
			mgr.add(s);
			cout << "�ű� �ð� ���� ��� �Ϸ�(" << text << ")" << endl;
			break;
		}
		case 2: {
			cout << "���/��ĥ/��������/��ú��� ��ñ���/�������� : "; cin >> month >> day >> dotw >> notes >> text;
			IlSchedule *i = new IlSchedule(2, month, day, dotw, notes, text);
			mgr.add(i);
			cout << "�ű� �Ϸ� ���� ��� �Ϸ�(" << text << ")" << endl;
			break;
		}
		case 3:
			mgr.showLists();
			break;
		default:
			mgr.saveData(); cout << "�������� ���� �Ϸ�";
			cout << "���α׷��� �����մϴ�." << endl << endl; return 0;
		}
	}
}

void printIntro() {
	cout << ">>>>>>   â�� Schedule Manager   <<<<<<" << endl;
	cout << "     �����ϰ� ������ �����غ�����.     " << endl;
	cout << "         1. �ð��������" << endl;
	cout << "         2. �Ϸ��������" << endl;
	cout << "         3. �������" << endl;
	cout << "         0. ����(����)" << endl;
	cout << "---------------------------------------" << endl;
}