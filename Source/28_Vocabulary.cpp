#include <iostream>
#include <string>
using namespace std;
class KorWord {
private:
	string wordclass;
	string word;
public:
	KorWord() {
		wordclass = "품사";
		word = "한글단어";
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
		word = "영어단어";
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
		cout << "[단어 " << cnt_of_kwords + 1 << "] 품사 : "; getline(cin, word_class);
		cout << "[단어 " << cnt_of_kwords + 1 << "]   뜻 : "; getline(cin, kword);
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
		cout << "등록할 영어단어? ";                       getline(cin, eword); ewords[cnt_of_ewords].set_word(eword);
		int no_of_kwords;
		cout << eword << "에 대한 한글단어의 등록 개수? "; cin >> no_of_kwords; ewords[cnt_of_ewords].make_kwords(no_of_kwords); cin.ignore();

		for (int cnt_of_kwords = 0; cnt_of_kwords < no_of_kwords; cnt_of_kwords++) {
			ewords[cnt_of_ewords].add_kword(cnt_of_kwords);
		}
		cnt_of_ewords++;
	}

	void search_eword() {
		bool search = false;
		cout << "검색할 영어단어? "; getline(cin, eword);
		cout << "검색결과........." << endl;
		for (int cnt_of_ewords = 0; cnt_of_ewords < no_of_ewords; cnt_of_ewords++) {
			if (eword == ewords[cnt_of_ewords].get_word()) {
				search = true;
				for(int cnt_of_kwords = 0; cnt_of_kwords < ewords[cnt_of_ewords].get_no_of_kwords(); cnt_of_kwords++)
					cout << "(" << ewords[cnt_of_ewords].get_wordclass(cnt_of_kwords) << ", " << ewords[cnt_of_ewords].get_kword(cnt_of_kwords) << ")" << endl;
			}
			else if ("영어단어" == ewords[cnt_of_ewords].get_word() && search == false) {
				cout << "검색결과 없음" << endl;
				break;
			}
		}
	}

	void test_eword() {
		int number, correct, incorrect; number = correct = incorrect = 0;
		while (1) {
			string kword;
			cout << "테스트할 영어단어? "; getline(cin, eword);
			if (eword == "q") {
				cout << "테스트를 종료합니다." << endl;
				cout << "테스트 횟수 : " << number << "  정답 : " << correct << "  오답 : " << incorrect << endl;
				break;
			}
			else {
				
				cout << "한글단어 입력? "; getline(cin, kword);
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
							cout << "=>오답입니다." << endl; incorrect++;
						}
						else if (bool_correct == true) {
							cout << "=>정답입니다." << endl; correct++;
						}
					}
					else if ("영어단어" == ewords[cnt_of_ewords].get_word() && search == false) {
						cout << "=>영어단어가 없습니다." << endl;
						break;
					}
				}
			}
		}
		
	}

	void out_eword() {
		cout << "단어장을 출력합니다." << endl;
		for (int cnt_of_ewords = 0; cnt_of_ewords < no_of_ewords && ewords[cnt_of_ewords].get_word() != "영어단어"; cnt_of_ewords++) {
			cout << "[" << cnt_of_ewords + 1 << "] " << ewords[cnt_of_ewords].get_word() << endl;
			for (int cnt_of_kwords = 0; cnt_of_kwords < ewords[cnt_of_ewords].get_no_of_kwords(); cnt_of_kwords++) {
				cout << "   [단어 " << cnt_of_kwords + 1 << "] 품사 : " << ewords[cnt_of_ewords].get_wordclass(cnt_of_kwords) << endl;
				cout << "   [단어 " << cnt_of_kwords + 1 << "]   뜻 : " << ewords[cnt_of_ewords].get_kword(cnt_of_kwords) << endl;
			}
		}
	}
};


int main() {
	Vocabulary voca;
	int no_of_ewords = 0;
	cout << "+-------------------------+ " << endl << endl;
	cout << "   >> 단어장 프로그램 <<    " << endl;
	cout << " created by 20121291 이창현 " << endl << endl;
	cout << "+-------------------------+ " << endl;
	cout << "단어장 프로그램을 시작합니다......." << endl;
	cout << "단어장의 크기(등록할 영어단어의 개수)를 입력하세요. "; cin >> no_of_ewords; cin.ignore();
	cout << no_of_ewords << "개의 단어를 등록할 단어장이 생성되었습니다." << endl; voca.make_ewords(no_of_ewords);
	cout << "###########################" << endl;
	cout << "    1) 단어 등록" << endl;
	cout << "    2) 단어 검색" << endl;
	cout << "    3) 암기테스트" << endl;
	cout << "    4) 단어장출력" << endl;
	cout << "    0) 종료" << endl;
	while (1) {
		int function_select;
		cout << endl << "# 기능 선택? "; cin >> function_select; cin.ignore();
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
