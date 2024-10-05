
/*#include<iostream>
using namespace std;
#include<string>
//��һ�ֽ����ʽ��ֱ�Ӱ��� Դ�ļ�
#include"Pperson.cpp"
//�ڶ��ֽ����ʽ
// ��.h��.cpp�е�����д��һ�𣬽���׺����Ϊ.hpp�ļ�
#include"Pperson.hpp"

#include"MyArray.hpp"
//����ģ��
template<class T1, class T2>
class People;
template<class T1, class T2>
void printPeople2(People<T1, T2> p) {
	cout << "����ʵ��--������  " << p.m_name << "���䣺   " << p.m_age << endl;
}
void swapInt(int& a, int& b) {
	int tmp;
	tmp = a;
	a = b;
	b = tmp;
}

void swapDouble(double& a, double& b) {
	double tmp;
	tmp = a;
	a = b;
	b = tmp;
}

template<typename T> //����һ��ģ�壬���߱�������������н�����T��Ҫ����T��һ��ͨ����������
//typename�����滻��class

void mySwap(T& a, T& b) {
	T tmp = a;
	a = b;
	b = tmp;
}

void test01() {
	int a = 10;
	int b = 20;
	char c = 'c';
	//mySwap(a, c);//����
	//����ģ��ע������//1���Զ������Ƶ��������Ƶ���һ�µ���������T�ſ���ʹ��
	swapInt(a, b);
	//���ú���ģ�巽��
	//1���Զ������Ƶ�
	mySwap(a, b);
	//2����ʾָ������
	mySwap<int>(a, b);
	cout << "a= " <<a<< endl;
	cout << "b= " << b<<endl;
	//double c = 1.1;
	//double d = 2.2;
	//swapDouble(c,d);
	//cout << "c= " << c << endl;
	//cout << "d= " << d << endl;
}
 
//����ģ��ע������//2��ģ�����Ҫȷ����T���������ͣ��ſ���ʹ��
template<class T>
void func() {
	cout << "func ����" << endl;
}
void test02() {
	//func();//����
	func<int>();
}

//ʵ��ͨ�� �������������ĺ���
//�Ӵ�С
//�㷨 ѡ������
//���� char int ����

//�����㷨
template<class T>
void mySort(T arr[], int len) {
	for (int i = 0; i < len; i++) {
		int max = i;
		for (int j = i + 1; j < len; j++) {
			if (arr[max] < arr[j]) {
				max = j;//�������ֵ���±�
			}
		}
		if (max != i) {
			//����
			mySwap(arr[max], arr[i]);
		}
	}
}
//�ṩ��ӡ����ģ��
template<class T>
void printArray(T arr[], int len) {
	for (int i = 0; i < len; i++) {
		cout << arr[i] << " ";
	}
	cout << endl;
}
void test03() {
	char charArr[] = "badcfe";
	int num = sizeof(charArr)/sizeof(char);
	mySort(charArr, num);
	printArray(charArr, num);
}
void test04() {
	int intArr[] = { 7,5,1,3,9,2,4,6,8 };
	int num = sizeof(intArr) / sizeof(int);
	mySort(intArr, num);
	printArray(intArr, num);
}
//��ͨ�����ͺ���ģ������
//1����ͨ�������ÿ��Է�����ʽ����ת��
//2������ģ�� ���Զ������Ƶ��������Է�����ʽ����ת��
//3������ģ������ʾָ�����ͣ����Է�����ʽ����ת��

//��ͨ����
int myAdd01(int a,int b) {
	return a + b;
}
void test05() {
	int a = 10;
	int b = 20;
	char c = 'c';//ת����ACLL��
	cout << myAdd01(a, c) << endl;
}
//����ģ��
template<class T>
int myAdd02(T a, T b) {
	return a + b;
}
void test06() {
	int a = 10;
	int b = 20;
	char c = 'c';//ת����ACLL��
	//cout << myAdd02(a, c) << endl;//����    ���Զ������Ƶ��������Է�����ʽ����ת��
	cout << myAdd02<int>(a, c) << endl ;//����ʾָ�����ͣ����Է�����ʽ����ת��
}
//��ͨ�����뺯��ģ��ĵ��ù���
//1���������ģ�����ͨ���������Ե��ã����ȵ�����ͨ����
//2������ͨ����ģ������б� ǿ�Ƶ��� ����ģ��
//3������ģ����Է�����������
//4���������ģ����Բ������õ�ƥ�䣬���ȵ��ú���ģ��

void myPrint(int a, int b) {
	cout << "���õ���ͨ����" << endl;
}
template<class T>
void myPrint(T a, T b) {
	cout << "���õĺ���ģ��" << endl;
}
template<class T>
void myPrint(T a, T b,T c) {
	cout << "���õĺ�������ģ��" << endl;
}
void test07() {
	int a = 10; int b = 20;
	//myPrint(a, b);//�������ģ�����ͨ���������Ե��ã����ȵ�����ͨ����
	//ͨ����ģ������б� ǿ�Ƶ��� ����ģ��
	//myPrint<>(a, b);
	//myPrint(a, b, 100);
	//�������ģ����Բ������õ�ƥ�䣬���ȵ��ú���ģ��
	char c1 = 'a';
	char c2 = 'b';
	myPrint(c1, c2);//��������У�������ͨ������ת�����鷳�㣬����ģ��ֱ���Ƶ�
}
//ģ��ľ�����
//ģ�岻�����ܵģ���Щ�ض����������ͣ���Ҫ�þ��廯��ʽ������ʵ��
class Person {
public:
	Person(string name, int age) {
		this->m_name = name;
		this->m_age = age;
	}
	string m_name;
	int m_age;
};
//�Ա����������Ƿ���Ⱥ���
template<class T>
bool myCompare(T& a, T& b) {
	if (a == b) {
		return true;
	}
	else {
		return false;
	}
}
void test08() {
	int a = 10;
	int b = 20;
	bool ret=myCompare(a, b);
	if (ret) {
		cout << "a=b" << endl;
	}
	else {
		cout << "a!=b" << endl;
	}
}//���þ��廯person�İ汾ʵ�ִ��룬�����Ż�����
template <> bool myCompare(Person& p1, Person& p2) {
	if (p1.m_name == p2.m_name && p1.m_age == p2.m_age) {
		return true;
	}
	else {
		return false;
	}
}
void test09() {
	Person p1("Tom", 10);
	Person p2("Tom", 10);
	bool ret = myCompare(p1, p2);
	if (ret) {
		cout << "p1=p2" << endl;
	}
	else {
		cout << "p1!=p2" << endl;
	}
}
//��ģ��
template<class NameType,class AgeType>
class person {
public:
	person(NameType name, AgeType age) {
		this->m_name=name;
		this->m_age = age;
	}
	void showPerson() {
		cout << "name: " << this->m_name << " age: " << this->m_age << endl;
	}
	AgeType m_age;
	NameType m_name;
};
void test10() {
	person<string, int>p1("�����", 999);
	p1.showPerson();
}
//��ģ��ͺ���ģ�������
template<class NameType, class AgeType=int>
class person1 {
public:
	person1(NameType name, AgeType age) {
		this->m_name = name;
		this->m_age = age;
	}
	void showPerson() {
		cout << "name: " << this->m_name << " age: " << this->m_age << endl;
	}
	AgeType m_age;
	NameType m_name;
};
//1����ģ��û���Զ������Ƶ�ʹ�÷�ʽ
void test11() {
	//person1 p("�����", 100);//����
	person1<string, int>p("�����", 1000);//��ȷ
	p.showPerson();
}
//2����ģ����ģ������б��п�����Ĭ�ϲ���
void test12() {
	person1<string>p("��˽�", 1000);
	p.showPerson();
}
//��ģ���г�Ա��������ʱ��
//��ģ���г�Ա�����ڵ���ʱ��ȥ����
class Person1 {
public:
	void showPerson1() {
		cout << "Person1 show" << endl;
	}
};
class Person2 {
public:
	void showPerson2() {
		cout << "Person2 show" << endl;
	}
};

template<class T>
class MyClass {
public:
	T obj;
	//��ģ���еĳ�Ա����
	void func1() {
		obj.showPerson1();
	}
	void func2() {
		obj.showPerson2();
	}
};
void test13() {
	MyClass<Person1>m;
	m.func1();
	//m.func2();
}
//��ģ���������������
template<class T1,class T2>
class person3 {
public:
	person3(T1 name, T2 age) {
		this->m_name = name;
		this->m_age = age;
	}
	void showperson3() {
		cout << "������ " << this->m_name<<" ���䣺 "<<this->m_age<<endl;
	}
	T1 m_name;
	T2 m_age;
};
//1��ָ����������	��㷺
void printperson1(person3<string, int>&p) {
	p.showperson3();
}
void tst01() {
	person3<string, int>p("�����", 100);
	printperson1(p);
}
//2������ģ�廯
template<class T1,class T2>
void printperson2(person3<T1,T2>&p) {
	p.showperson3();
	cout << "T1������Ϊ��" << typeid(T1).name() << endl;
	cout << "T2������Ϊ��" << typeid(T2).name() << endl;
}
void tst02() {
	person3<string, int>p("��˽�", 90);
	printperson2(p);
}
//3��������ģ�廯
template<class T>
void printperson3(T &p) {
	p.showperson3();
	cout << "T����������Ϊ�� " << typeid(T).name() << endl;
}
void tst03() {
	person3<string, int>p("��ɮ", 30);
	printperson3(p);
}
//��ģ����̳�
template<class T>
class Base {
	T m;
};
//class Son :public Base {//���󣬱���֪�������е�T���ͣ����ܼ̳и�����
class Son :public Base<int> {

};

void tst04() {
	Son s1;
}
//��������ָ��������T���ͣ�����Ҳ��Ҫ����ģ��
template<class T1,class T2>
class Son2 :public Base<T2> {
public:
	Son2() {
		cout << "T1����������Ϊ�� " << typeid(T1).name()<<endl;
		cout << "T2����������Ϊ�� " << typeid(T2).name() << endl;
	}
	T1 obj;
};
void tst05() {
	Son2<int, char>s2;
}
//��ģ���Ա��������ʵ��
template<class T1,class T2>
class people {
public:
	people(T1 name, T2 age);
		//{
		//		this->m_name=name;
		//		this->m_age=age;
		//}
		void showpeople();
	//{
	//	cout << "������" << this->m_name << " ���䣺" << this->m_age << endl;
	//}
	T1 m_name;
	T2 m_age;
};
//���캯������ʵ��
template<class T1,class T2>
people<T1, T2>::people(T1 name, T2 age) {
	this->m_name=name;
	this->m_age=age;
}
//��Ա��������ʵ��
template<class T1, class T2>
void people<T1, T2>::showpeople() {
	cout << "������" << this->m_name << " ���䣺" << this->m_age << endl;
}
void tst07() {
	people<string, int>p("Tom", 20);
	p.showpeople();
}
//��ģ����ļ���д�����Լ����
//template<class T1,class T2>
//class Pperson {
//public:
//
//	Pperson(T1 name, T2 age);
//	void showPpeople();
//	T1 m_name;
//	T2 m_age;
//};
//template<class T1,class T2>
//Pperson<T1, T2>::Pperson(T1 name, T2 age) {
//	this->m_name = name;
//	this->m_age = age;
//}
//template<class T1, class T2>
//void Pperson<T1, T2>::showPpeople() {
//	cout << "������" << this->m_name << " ���䣺" << this->m_age << endl;
//}
void test1() {
	Pperson<string, int>p1("Jerry", 18);
	p1.showPpeople();
}
//��ģ�����Ԫ
//ͨ��ȫ�ֺ�����ӡPeople��Ϣ

template<class T1,class T2>
class People {
	//ȫ�ֺ�������ʵ��
	friend void printPeople(People<T1, T2> p) {
		cout << "������  " << p.m_name << "���䣺   " << p.m_age << endl;
	}
	//ȫ�ֺ�������ʵ��
	//�ӿ�ģ������б�
	//���ȫ�ֺ���������ʵ�� ��Ҫ�ñ�������ǰ֪����������Ĵ���
	friend void printPeople2<>(People<T1, T2> p);
public:
	People(T1 name, T2 age) {
		this->m_name = name;
		this->m_age = age;
	}

private:
	T1 m_name;
	T2 m_age;
};
//template<class T1,class T2>
//void printPeople2(People<T1, T2> p) {
//	cout << "����ʵ��--������  " << p.m_name << "���䣺   " << p.m_age << endl;
//}

//1��ȫ�ֺ�������ʵ��
void test2() {
	People<string, int>p("Tom", 20);
	printPeople(p);
}
//2��ȫ�ֺ�������ʵ��
void test3() {
	People<string, int>p("Jerry", 20);
	printPeople2(p);
}
void printIntArray(MyArray<int>& arr) {
	for (int i = 0; i < arr.getSize(); i++) {
		cout << arr[i] << endl;
	}
}
void test4() {
	MyArray <int>arr1(5);
	for (int i = 0; i < 5; i++) {
		arr1.Push_Back(i);
	}
	cout << "arr1�Ĵ�ӡ���Ϊ��" << endl;
	printIntArray(arr1);
	cout << "arr1������Ϊ��" <<arr1.getCapacity()<< endl;
	cout << "arr1�Ĵ�СΪ��" << arr1.getSize()<<endl;

	MyArray<int>arr2(arr1);
	cout << "arr2�Ĵ�ӡ���Ϊ��" << endl;
	printIntArray(arr2);
	arr2.Pop_Back();
	printIntArray(arr2);
	//MyArray <int>arr3(100);
	//arr3 = arr1;
}
int main() {
	//test01();
	//test02();
	//test03();
	//test04();
	//test05();
	//test06();
	//test07();
	//test08();
	//test09();
	//test10();
	//test11();
	//test12();
	//test13();
	//tst01();
	//tst02();
	//tst03();
	//tst05();
	//tst07();
	//test1();
	//test2();
	//test3();
	test4();
	system("pause");
	return 0;
}
*/