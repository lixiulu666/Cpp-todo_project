/*
#include<iostream>
using namespace std;
//�Ӻ����������
//1����Ա��������+��
class person {
	friend ostream& operator<<(ostream& cout, person& p);
public:
	person(int a, int b) {
		m_A = a;
		m_B = b;
	}
private:
	//person operator+(person& p) {
	//	person temp;
	//	temp.m_A = this->m_A + p.m_A;
	//	temp.m_B = this->m_B + p.m_B;
	//	return temp;
	//}
	
	//���ó�Ա�������� ���������  p.operator<<(cout) �򻯰汾 p << cout
	//�������ó�Ա��������<<���������Ϊ�޷�ʵ��  cout�����
	//void operator<<() {

	//}
	int m_A;
	int m_B;
};
////2��ȫ�ֺ�������+��
//person operator+(person& p1, person& p2) {
//	person temp;
//	temp.m_A = p1.m_A + p2.m_A;
//	temp.m_B = p1.m_B + p2.m_B;
//	return temp;
//}
////��������+�İ汾
//person operator+(person& p1, int num) {
//	person temp;
//	temp.m_A = p1.m_A + num;
//	temp.m_B = p1.m_B + num;
//	return temp;
//}
//void test01() {
//	person p1;
//	p1.m_A = 10;
//	p1.m_B = 10;
//	person p2;
//	p2.m_A = 10;
//	p2.m_B = 10;
//
//	//��Ա�������ر��ʵ���
//	//person p3 = p1.operator+(p2);
//	//ȫ�ֺ������ر��ʵ���
//	//person p3 = operator+(p1, p2);
//	person p3 = p1 + p2;
//	//��������� Ҳ���Է�����������
//	person p4 = p1 + 100;
//
//	cout << "p3.m_A = " << p3.m_A << endl;
//	cout << "p3.m_B = " << p3.m_B << endl;
//
//	cout << "p4.m_A = " << p4.m_A << endl;
//	cout << "p4.m_B = " << p4.m_B << endl;
//}
//ֻ������ȫ�ֺ����������������
ostream& operator<<(ostream &cout, person &p)//���� operator<< (cout,p) ��cout<<p
{
	cout << "m_A=" << p.m_A << "   m_B=" << p.m_B<<endl;
	return cout;
}
void test02() {
	person p(10,10);
	//p.m_A = 10;
	//p.m_B = 10;
	//��ʽ���
	cout << p<<"hello world"<<endl;
}
//ǰ�õ���
//�Զ�������
class MyInteger {
	friend ostream& operator<<(ostream& cout, MyInteger myint);
public:
	MyInteger() {
		m_Num = 0;
	}
	//����ǰ��++�����  ��������Ϊ��һֱ��һ�����ݽ��е�������
	MyInteger& operator++() {
		m_Num++;
		return *this;
	 }
	//���غ���++�����  
	//void operator++(int)  int����ռλ��������������ǰ�úͺ��õ���
	MyInteger operator++(int) {
		MyInteger temp = *this;
		m_Num++;
		return temp;
	}
private:
	int m_Num;
};
ostream& operator<<(ostream& cout, MyInteger myint) {
	cout << myint.m_Num;
	return cout;
}
void test03() {
	MyInteger myint;
	cout <<++(++myint) << endl;
	cout << myint << endl;
}
void test04() {
	MyInteger myint;

	cout << myint++ << endl;
	cout << myint << endl;
}
//��ֵ���������
class Person {
public:
	Person(int age) {
		m_age = new int(age);
	}
	~Person() {
		if (m_age != NULL) {
			delete m_age;
			m_age = NULL;
		}
	}
	//���ظ�ֵ�����
	Person& operator=(Person& p) {
		//�������ṩ��ǳ����
		//m_age=p.m_age;

		//Ӧ�����ж��Ƿ��������ڶ���������У����ͷŸɾ���Ȼ�������
		if (m_age != NULL) {
			delete m_age;
			m_age = NULL;
		}

		m_age = new int(*p.m_age);//���
		return *this;
	}
	int* m_age;
};
void test05() {
	Person p1(18);
	Person p2(20);
	Person p3(30);

	p3=p2 = p1;//��ֵ
	cout<< "p1������Ϊ�� " << *p1.m_age << endl;
	cout << "p2������Ϊ�� " << *p2.m_age << endl;
	cout << "p3������Ϊ�� " << *p3.m_age << endl;
}
//��ϵ���������
class person1 {
public:
	person1(string name,int age) {
		m_Name = name;
		m_age = age;
	}
	//���� == ��
	bool operator==(person1& p) {
		if (this->m_age == p.m_age && this->m_Name == p.m_Name) {
			return true;
		}
		return false;
	}
	//���� ��= ��
	bool operator!=(person1& p) {
		if (this->m_age == p.m_age && this->m_Name == p.m_Name) {
			return false;
		}
		return true;
	}
	string m_Name;
	int m_age;
};
void tst01() {
	person1 p1("Tom", 18);
	person1 p2("Tom", 18);
	if (p1 == p2) {
		cout << "p1��p2����ȵ�! " << endl;
	}
	else {
		cout << "p1��p2�ǲ���ȵģ�" << endl;
	}
	if (p1 != p2) {
		cout << "p1��p2�ǲ���ȵ�! " << endl;
	}
	else {
		cout << "p1��p2����ȵģ�" << endl;
	}
}
//�����������������
class Myprint {
public:
	void operator()(string test){
		cout << test << endl;
	}
};
void Myprint02(string test) {
	cout << test << endl;
}
void tst02() {
	Myprint myprint;
	myprint("Hello World");//����ʹ�������ǳ������ں������ã����Գ�Ϊ�º���
	Myprint02("Hello World");
}
//�º����ǳ���û�й̶���д��
//�ӷ���
class Myadd {
public:
	int operator()(int num1,int num2) {
		return num1 + num2;
	}
};
void tst03() {
	Myadd myadd;
	int red = myadd(100, 100);
	cout << "red=  " << red<<endl;
	//������������Myadd()
	cout<<Myadd()(100,100)<<endl;

}

int main() {
	//test01();
	//test02();
	//test03();
	//test04();
	//test05();
	//tst01();
	//tst02();
	//tst03();
	system("pause");
	return 0;
}
*/