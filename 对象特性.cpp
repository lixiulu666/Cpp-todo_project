/*
#include<iostream>
#include<string.h>
using namespace std;
//����ĳ�ʼ��������
class Person {
public://1�����캯�� ��ʼ��
	//���캯��û�з���ֵ ����дvoid
	//��������������ͬ
	//�����в��������Է�������
	//���������ʱ�򣬹��캯�����Զ����ã�����ֻ����һ��
	//��������Ĭ��дһ����ʵ�ֵĹ��캯��
	Person() {
		cout << "Person���캯���ĵ���" << endl;
		
	}
	//�������� ��������
	//û�з���ֵ ��дvoid
	//��������������ͬ ������ǰ��~
	//�������в��� �����Է�������
	//����������ǰ ���Զ�������������������ֻ�����һ��
	~Person() {
		cout << "Person��������������" << endl;
	}

};
//����������Ǳ����е�ʵ�֣�����Լ����ṩ�����������ṩ��ʵ��
class person {
public:	
	person() {
		cout << "person�޲ι��캯���ĵ���" << endl;
	}
	person(int a) {
		age = a;
		cout << "person�вι��캯���ĵ���" << endl;
	}
	//�������캯��
	person(const person &p) {
		//������������ϵ��������Կ�����������
		cout << "person�������캯���ĵ���" << endl;
		age = p.age;
	}
	~person() {
		cout << "person���������ĵ���" << endl;
	}
	int age;
};
void test01() {
	Person p;//��ջ�ϵ����ݣ�test01ִ����Ϻ󣬻��Զ��ͷ��������
}
void test02() {
	//1�����ŷ�
	//person p1;//Ĭ�Ϲ��캯������
	//person p2(10);//�вι��캯��
	//person p3(p2);//�������캯��

	//cout << "p2������Ϊ�� " << p2.age<<endl;
	//cout << "p3������Ϊ�� " << p3.age << endl;
	// ע���������Ĭ�Ϲ��캯��ʱ�򣬲�Ҫ��()
	//person p1();//����������Ϊ��һ��������������������Ϊ�ڴ�������
	
	//2����ʾ��
	//person p1;
	//person p2=person(10);//�в�
	//person p3 = person(p2);//����

	//person(10);//�����������н�����ϵͳ���������յ���������,ִ������
	//cout << "aaaa" << endl;
	//ע�������Ҫ���ÿ������캯������ʼ���������󣬱���������Ϊperson(p3)==person p3
	//person(p3);

	//3����ʽת����
	person p4 = 10;//�൱��person p4=person(10),�����вι���
	person p5 = p4;//��������
}
class person1 {
public:
	person1() {
		cout << "person1Ĭ�Ϲ��캯������" << endl;

	}
	person1(int age) {
		cout << "person1�вι��캯������" << endl;
		m_age = age;
	}
	person1(const person1& p) {
		cout << "person1�������캯������" << endl;
		m_age = p.m_age;
	}
	~person1() {
		cout << "person1������������" << endl;

	}
	int m_age;
};
//�������캯������ʱ��
//1��ʹ��һ���Ѿ�������ϵĶ�������ʼ��һ���¶���
void test03() {
	person1 p1(20);
	person1 p2(p1);

	cout << "p2������Ϊ�� " << p2.m_age << endl;
}
//2��ֵ���ݵķ�ʽ������������ֵ
void dowork(person1 p) {

}
void test04() {
	person1 p;
	dowork(p);//�൱�ڿ������캯��
}
//3��ֵ��ʽ���ؾֲ�����
person1 dowork2() {
	person1 p1;
	cout << (int*)&p1 << endl;
	return p1;
}
void test05() {
	person1 p = dowork2();
	cout << (int*)&p << endl;//p��p1����ͬһ������

}
//���캯���ĵ��ù���
//1������һ���࣬C++���������ÿ���඼���������������
//Ĭ�Ϲ��죨��ʵ�֣�   ������������ʵ�֣�   �������죨ֵ������
class people {
public:
	people() {
		cout <<"people��Ĭ�Ϲ��캯������" << endl;
	}
	people(int age) {
		cout << "people���вι��캯������" << endl;
		m_age = age;
	}
	people(const people& p) {
		cout << "people�Ŀ������캯������" << endl;
		m_age = p.m_age;
	}
	~people() {
		cout << "people��������������" << endl;
	}
	int m_age;
};
void test06() {
	people p;
	p.m_age = 18;
	people p2(p);
	cout << "p2������Ϊ�� " << p2.m_age << endl;
}
//2���������д���вι��캯�����������Ͳ����ṩĬ�Ϲ��죬��Ȼ�ṩ��������
//���д�˿������캯�����������Ͳ����ṩ������ͨ���캯����
void test07() {
	//people p;//��дĬ�Ϲ���ᱨ��
	people p(28);
	people p2(p);
	cout << "p2������Ϊ�� " << p2.m_age << endl;
}
//�����ǳ����
//ǳ�������򵥵ĸ�ֵ��������
//������ڶ�����������ռ䣬���п�������
class People {
public:
	People() {
		cout << "People��Ĭ�Ϲ��캯������" << endl;
	}
	People(int age,int height) {
		m_age = age;
		m_height=new int(height);
		cout << "People���вι��캯������" << endl;
	}
	//�Լ�ʵ�ֿ������캯�� ���ǳ��������������
	People(const People& p) {
		cout << "People�������캯���ĵ���" << endl;
		m_age = p.m_age;
		//m_height=p.m_height;������Ĭ��ʵ�־������д���
		//�������
		m_height=new int(*p.m_height);
	}
	~People() {
		//�������룬�����������������ͷŲ���
		if (m_height != NULL) {
			delete m_height;
			m_height = NULL;
		}
		cout<< "People��������������" << endl;
	}
	int m_age;
	int *m_height;
};
void test08() {
	People p1(18,160);
	cout << "p1������Ϊ��" << p1.m_age << "���Ϊ�� "<<*p1.m_height<<endl;
	People p2(p1);
	cout << "p2������Ϊ��" << p2.m_age << "���Ϊ�� " << *p1.m_height<<endl;
}
//��ʼ���б�
class human {
public:
	//��ͳ��ʼ��
	//human(int a, int b, int c) {
	//	m_A = a;
	//	m_B = b;
	//	m_C = c;
	//}
	
	//��ʼ���б��ʼ������
	//human() :m_A(10), m_B(20), m_C(30)//���޸�ֵ
	human(int a,int b,int c):m_A(a),m_B(b),m_C(c)
	{

	}
	int m_A;
	int m_B;
	int m_C;
};
void tst01() {
	//human p(10, 20, 30);
	//human p;
	human p(30, 20, 10);
	cout << "m_A=" << p.m_A << endl;
	cout << "m_B=" << p.m_B << endl;
	cout << "m_C=" << p.m_C << endl;
}
//�������Ϊ���Ա
class Phone {
public:
	Phone(string pName) {
		cout << "Phone�Ĺ��캯������" << endl;
		m_PName = pName;
	}
	~Phone() {
		cout << "Phone��������������" << endl;
	}
	string m_PName;
};
class Human {
public:
	//Phone m_phone=pName ��ʽת����
	Human(string name, string pName) :m_name(name), m_phone(pName) {
		cout << "Human�Ĺ��캯������" << endl;
	}
	~Human() {
		cout << "Human��������������" << endl;
	}
	string m_name;
	Phone m_phone;
};
//�������������Ϊ�����Ա�������ʱ���ȹ���������ٹ�������
//������˳���빹���෴
void tst02() {
	Human p("����", "ƻ��MAX");
	cout << p.m_name << "���ţ� " << p.m_phone.m_PName << endl;
}
//��̬��Ա����
class someone {
public:
	//1�����ж�����ͬһ������
	//2������׶ξͷ����ڴ�
	//3�����������������ʼ��
	static int m_A;

	//��̬��Ա����Ҳ�з���Ȩ��
private:
	static int m_B;

};
int someone::m_A = 100;
int someone::m_B = 200;
void tst03() {
	someone p;
	cout << p.m_A << endl;
	someone p2;
	p2.m_A = 200;

	cout << p.m_A << endl;//���Ϊ200,p��p2����ͬһ������
}
void tst04() {
	//��̬��Ա���� ������ĳ�������ϣ����ж�����ͬһ������
	//���ַ��ʷ�ʽ
	//1��ͨ���������
	//someone p;
	//cout << p.m_A << endl;
	//2��ͨ����������
	cout << someone::m_A << endl;
	//cout << someone::m_B << endl;//������ʲ���˽�о�̬��Ա����
}
//��̬��Ա����
//���ж�����ͬһ������
//��̬��Ա����ֻ�ܷ��ʾ�̬��Ա����
class ren {
public:

	static void func() {
		m_A = 100;//��̬��Ա�������Է��� ��̬��Ա����
		//m_B = 200;//���������Է��ʷǾ�̬��Ա�������޷����ֵ������ĸ������m_B
		cout << "static void func�ĵ���" << endl;
	}
	static int m_A;
	int m_B;

	//��̬��Ա����Ҳ���з���Ȩ�޵�
private:
	static void func2() {
		cout << "static void func2�ĵ���" << endl;
	}
};
int ren::m_A = 0;
void tst05() {
	//1��ͨ���������
	ren p;
	p.func();
	//2��ͨ����������
	ren::func();
	//ren::func2();//���ⲻ�ɷ���
}
//��Ա�����ͳ�Ա�����ֿ��洢
class ren1 {
	int m_a;//�Ǿ�̬��Ա����������Ķ�����
	static int m_B;//��̬��Ա������������Ķ�����
	void func() {}//�Ǿ�̬��Ա������������Ķ�����
	static void func2() {}//��̬��Ա����Ҳ��
};
void tet01() {
	ren1 p;
	//�ն���ռ���ڴ�ռ�Ϊ��1
	//C++���������ÿ���ն���Ҳ����һ���ֽڿռ䣬��Ϊ�����ֿն���ռ�ڴ��λ��
	//ÿ���ն���ҲӦ����һ����һ�޶����ڴ��ַ
	cout << "size of p=" << sizeof(p) << endl;
}
void tet02() {
	ren1 p;
	cout << "size of p=" << sizeof(p) << endl;//int ���ֽ�
}
class renn {
public:
	renn(int age) {
		this->age = age;//ָ�򱻵��õĳ�Ա���������Ķ���
	}
	renn& rennaddage(renn p) {
		this->age += p.age;
		return *this;//thisָ��p2��ָ�룬*thisָ�����p2���������
	}
	int age;
};
//thisָ��
//1��������Ƴ�ͻ
void tet03() {
	renn p1(18);
	cout << "p1������Ϊ�� " << p1.age << endl;
}
//2�����ض�������*this
void tet04() {
	renn p1(10);
	renn p2(10);
	//��ʽ���˼��
	p2.rennaddage(p1).rennaddage(p1).rennaddage(p1);
	cout << "p2������Ϊ�� " <<p2.age<< endl;
}
class ren2 {
public:
	void showClassName() {
		cout << "this is ren2 class" << endl;
	}
	void showClassage() {
		//��������Ϊ����ָ��ΪNULL
		//cout << "age= "<<m_age << endl;
		if (this == NULL) {
			return;
		}//�����д���Ԥ������
		cout << "age= " << this->m_age << endl;
	}
	int m_age;
};
void tt01() {
	ren2* p=NULL;
	p->showClassName();
	p->showClassage();
}
//������
class ren3 {
public:
	//thisָ��ı�����һ��ָ�볣����ָ���ָ�򲻿����޸�
	//const ren3 *const this;
	//�ڳ�Ա���������const�����ε���thisָ����ָ��ָ���ֵҲ�������޸�
	void showren3() const{//�������const,�����޸�
		this->m_B = 100;
		//this->m_A = 100;
		//this = NULL;//THISָ���ָ�򲻿����޸�
	}
	void func() {
		m_A = 100;
	}
	int m_A;
	mutable int m_B;//�����������ʹ�ڳ������У�Ҳ�����޸����ֵ���ӹؼ���mutable
};
void tt02() {
	ren3 p;
	p.showren3();
}
//������
void tt03() {
	const ren3 p;//�ڶ���ǰ��const����Ϊ������
	//p.m_A = 100;//�������޸�
	p.m_B = 100;//�ڳ�����Ҳ�����޸���������ֵ
	//������ֻ�ܵ��ó�����
	p.showren3();
	//p.func();//��ͨ��Ա���������޸�����
}
int main() {
	//test01();//�ڵ��ú���������ͷ�
	//Person p;
	//system("pause");//���д��������Ż��ͷ�
	//test02();
	//test03();
	//test04();
	//test05();
	//test06();
	//test07();
	//test08();
	//tst01();
	//tst02();
	//tst03();
	//tst04();
	//tst05();
	//tet01();
	//tet02();
	//tet03();
	//tet04();
	//tt01();
	system("pause");
	return 0;
}
*/