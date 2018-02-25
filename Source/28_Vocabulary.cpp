#include <iostream>
#include <string>
using namespace std;
class KorWord {
private:
	string wordclass;
	string word;
public:
	KorWord() {
		wordclass = "ǰ��";
		word = "�ѱ۴ܾ�";
	}


	void set_wordclass(string wc) {
		wordclass = wc;
	}
	void set_word(string w) {
		word = w;
	}


	string get_word() {
		return word;
	}
	string get_wordclass() {
		return wordclass;
	}
};


class EngWord {
private:
	KorWord *kwords;
	string word;
	int no_of_kwords; //EngWord.no_of_ewords
public:
	EngWord() {
		word = "����ܾ�";
	}


	void set_word(string eword) {
		word = eword;
	}
	void set_no_of_kwords(int n) {
		no_of_kwords = n;
	}

	int get_no_of_kwords() {
		return no_of_kwords;
	}


	string get_word() {
		return word;
	}
	KorWord get_kwords(int cnt_of_kwords) {
		return kwords[cnt_of_kwords];
	}
	string get_kword(int cnt_of_kwords) {
		return kwords[cnt_of_kwords].get_word();
	}
	string get_wordclass(int cnt_of_kwords) {
		return kwords[cnt_of_kwords].get_wordclass();
	}


	void make_kwords(int no_of_kwords) {
		set_no_of_kwords(no_of_kwords);
		kwords = new KorWord[no_of_kwords]; for (int i = 0; i < no_of_kwords; i++) kwords[i] = KorWord();
	}

	
	void add_kword(int cnt_of_kwords) {
		string word_class;
		string kword;
		cout << "[�ܾ� " << cnt_of_kwords + 1 << "] ǰ�� : "; getline(cin, word_class);
		cout << "[�ܾ� " << cnt_of_kwords + 1 << "]   �� : "; getline(cin, kword);
		kwords[cnt_of_kwords].set_wordclass(word_class);
		kwords[cnt_of_kwords].set_word(kword);
	}
};

class Vocabulary {
private:
	EngWord *ewords;
	int no_of_ewords; //Voca.no_of_ewords

public:
	void set_no_of_ewords(int n) {
		no_of_ewords = n;
	}
	string eword;
	void make_ewords(int no_of_ewords) {
		set_no_of_ewords(no_of_ewords);
		ewords = new EngWord[no_of_ewords]; for (int i = 0; i < no_of_ewords; i++) ewords[i] = EngWord();
	}

	int cnt_of_ewords = 0;
	void add_eword() {
		cout << "����� ����ܾ�? ";                       getline(cin, eword); ewords[cnt_of_ewords].set_word(eword);
		int no_of_kwords;
		cout << eword << "�� ���� �ѱ۴ܾ��� ��� ����? "; cin >> no_of_kwords; ewords[cnt_of_ewords].make_kwords(no_of_kwords); cin.ignore();

		for (int cnt_of_kwords = 0; cnt_of_kwords < no_of_kwords; cnt_of_kwords++) {
			ewords[cnt_of_ewords].add_kword(cnt_of_kwords);
		}
		cnt_of_ewords++;
	}

	void search_eword() {
		bool search = false;
		cout << "�˻��� ����ܾ�? "; getline(cin, eword);
		cout << "�˻����........." << endl;
		for (int cnt_of_ewords = 0; cnt_of_ewords < no_of_ewords; cnt_of_ewords++) {
			if (eword == ewords[cnt_of_ewords].get_word()) {
				search = true;
				for(int cnt_of_kwords = 0; cnt_of_kwords < ewords[cnt_of_ewords].get_no_of_kwords(); cnt_of_kwords++)
					cout << "(" << ewords[cnt_of_ewords].get_wordclass(cnt_of_kwords) << ", " << ewords[cnt_of_ewords].get_kword(cnt_of_kwords) << ")" << endl;
			}
			else if ("����ܾ�" == ewords[cnt_of_ewords].get_word() && search == false) {
				cout << "�˻���� ����" << endl;
				break;
			}
		}
	}

	void test_eword() {
		int number, correct, incorrect; number = correct = incorrect = 0;
		while (1) {
			string kword;
			cout << "�׽�Ʈ�� ����ܾ�? "; getline(cin, eword);
			if (eword == "q") {
				cout << "�׽�Ʈ�� �����մϴ�." << endl;
				cout << "�׽�Ʈ Ƚ�� : " << number << "  ���� : " << correct << "  ���� : " << incorrect << endl;
				break;
			}
			else {
				
				cout << "�ѱ۴ܾ� �Է�? "; getline(cin, kword);
				bool search; search = false;
				for (int cnt_of_ewords = 0; cnt_of_ewords < no_of_ewords; cnt_of_ewords++) {
					if (eword == ewords[cnt_of_ewords].get_word()) {
						number++;
						search = true;
						bool bool_correct; bool_correct = false;
						for (int cnt_of_kwords = 0; cnt_of_kwords < ewords[cnt_of_ewords].get_no_of_kwords(); cnt_of_kwords++) {
							if (kword == ewords[cnt_of_ewords].get_kword(cnt_of_kwords))
								bool_correct = true;
						}
						if (bool_correct == false) {
							cout << "=>�����Դϴ�." << endl; incorrect++;
						}
						else if (bool_correct == true) {
							cout << "=>�����Դϴ�." << endl; correct++;
						}
					}
					else if ("����ܾ�" == ewords[cnt_of_ewords].get_word() && search == false) {
						cout << "=>����ܾ �����ϴ�." << endl;
						break;
					}
				}
			}
		}
		
	}

	void out_eword() {
		cout << "�ܾ����� ����մϴ�." << endl;
		for (int cnt_of_ewords = 0; cnt_of_ewords < no_of_ewords && ewords[cnt_of_ewords].get_word() != "����ܾ�"; cnt_of_ewords++) {
			cout << "[" << cnt_of_ewords + 1 << "] " << ewords[cnt_of_ewords].get_word() << endl;
			for (int cnt_of_kwords = 0; cnt_of_kwords < ewords[cnt_of_ewords].get_no_of_kwords(); cnt_of_kwords++) {
				cout << "   [�ܾ� " << cnt_of_kwords + 1 << "] ǰ�� : " << ewords[cnt_of_ewords].get_wordclass(cnt_of_kwords) << endl;
				cout << "   [�ܾ� " << cnt_of_kwords + 1 << "]   �� : " << ewords[cnt_of_ewords].get_kword(cnt_of_kwords) << endl;
			}
		}
	}
};


int main() {
	Vocabulary voca;
	int no_of_ewords = 0;
	cout << "+-------------------------+ " << endl << endl;
	cout << "   >> �ܾ��� ���α׷� <<    " << endl;
	cout << " created by 20121291 ��â�� " << endl << endl;
	cout << "+-------------------------+ " << endl;
	cout << "�ܾ��� ���α׷��� �����մϴ�......." << endl;
	cout << "�ܾ����� ũ��(����� ����ܾ��� ����)�� �Է��ϼ���. "; cin >> no_of_ewords; cin.ignore();
	cout << no_of_ewords << "���� �ܾ ����� �ܾ����� �����Ǿ����ϴ�." << endl; voca.make_ewords(no_of_ewords);
	cout << "###########################" << endl;
	cout << "    1) �ܾ� ���" << endl;
	cout << "    2) �ܾ� �˻�" << endl;
	cout << "    3) �ϱ��׽�Ʈ" << endl;
	cout << "    4) �ܾ������" << endl;
	cout << "    0) ����" << endl;
	while (1) {
		int function_select;
		cout << endl << "# ��� ����? "; cin >> function_select; cin.ignore();
		switch (function_select) {
		case 1:
			voca.add_eword();
			break;
		case 2:
			voca.search_eword();
			break;
		case 3:
			voca.test_eword();
			break;
		case 4:
			voca.out_eword();
			break;
		default:
			return 0;
		}
	}
	return 0;
}
