#include <iostream>
#include <typeinfo>
//typeid()�Լ� ���.
//typeid(emp[i]) == typeid(Fulltime)
using namespace std;

class Employee {
protected:
    string name;
    int salary;
public:
    Employee(string n) { name = n; }
    int getSalary() { return salary; }
    //���� ���� �Լ�.
    virtual void makeSalary() = 0;
    virtual void setEmp(string n, int b, int bo) = 0;
    virtual void print() = 0;
};

class Fulltime : public Employee {
private:
    int base, bonus; // �⺻�޿�, ���ʽ�(%).
public:
    Fulltime(string n, int b, int bo) : Employee(n){
        base = b; bonus = bo;
    }
    virtual void makeSalary() {
        salary = base + (base * (bonus / 100.0));
    }
    void setEmp(string n, int b, int bo) {
        name = n; base = b; bonus = bo;
    }
    string getName() { return name; }
    int getBase() { return base; }
    int getBonus() { return bonus; }
    void print() {
        cout << name << ":" << base << ":" << bonus << ":" << salary << endl;
    }
};

class Parttime : public Employee {
private:
    int hour_wage, work_hours; // �ñ�,���� �ð�.
public:
    Parttime(string n, int h, int w) : Employee(n) {
        hour_wage = h; work_hours = w;
    }
    virtual void makeSalary() {
        salary = hour_wage * work_hours;
        if(work_hours > 200) salary += salary * 0.1;
    }
    void setEmp(string n, int h, int w) {
        name = n; hour_wage = h; work_hours = w;
    }
    string getName() { return name; }
    int getHourWage() { return hour_wage; }
    int getWorks() { return work_hours; }
    void print() {
        cout << name << ": " << hour_wage << ": " << work_hours << ": " << salary << endl;
    }
};

class Wage {
private:
    Employee **emp; // Fulltime, Parttime�� ������ �迭.
    int max_size; // �迭�� ũ��
    int cnt; // ������ ����
public:
    Wage(int m) {
        emp = new Employee*[m];
        max_size = m;
        cnt = 0;
    }
    void addEmployee(Fulltime f) { // Fulltime ���� ���
        // emp[cnt] = &f �ϸ� ������, �Է� �Ű������� ���������� �Լ� ���� �� emp[cnt]�� null�� �ȴ�.
        emp[cnt] = new Fulltime("",0,0);
        emp[cnt++] -> setEmp(f.getName(), f.getBase(), f.getBonus());
    }
    void addEmployee(Parttime p) { // Parttime  ���� ���
        emp[cnt] = new Parttime("", 0, 0);
        emp[cnt++] -> setEmp(p.getName(), p.getHourWage(), p.getWorks());
    }
    void getSalary() { // ��ü ���� �޿� ���.
        for(int i=0; i<cnt; i++) emp[i]->makeSalary();
    }
    void printAll() { // ��ü ���� ���
        for(int i = 0; i < cnt; i++) emp[i]->print();
    }
    void print(string n) { // Ư�� ���� ���.
    }
};

int main() {
    Wage wage(20); // �ִ� �������� 20.
    Fulltime tom("Tom", 2000000, 25);
    Parttime peter("Peter", 8200, 187);

    wage.addEmployee(tom);
    wage.addEmployee(peter);
    wage.addEmployee(Fulltime("Bob", 2500000, 21));
    wage.addEmployee(Fulltime("Hemry", 2900000, 20));
    wage.addEmployee(Parttime("Sindy", 8900, 140));
    wage.addEmployee(Parttime("Joy", 7900, 252));

    wage.getSalary();
    wage.printAll();
    /*
    tom.makeSalary();
    peter.makeSalary();
    cout << "Tom's salary: " << tom.getSalary() << endl;
    cout << "Peter's salary: " << peter.getSalary() << endl;
    */
    return 0;
}
