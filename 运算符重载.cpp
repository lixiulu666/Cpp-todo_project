/*
#include<iostream>
using namespace std;
//加号运算符重载
//1、成员函数重载+号
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
	
	//利用成员函数重载 左移运算符  p.operator<<(cout) 简化版本 p << cout
	//不会利用成员函数重载<<运算符，因为无法实现  cout在左侧
	//void operator<<() {

	//}
	int m_A;
	int m_B;
};
////2、全局函数重载+号
//person operator+(person& p1, person& p2) {
//	person temp;
//	temp.m_A = p1.m_A + p2.m_A;
//	temp.m_B = p1.m_B + p2.m_B;
//	return temp;
//}
////函数重载+的版本
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
//	//成员函数重载本质调用
//	//person p3 = p1.operator+(p2);
//	//全局函数重载本质调用
//	//person p3 = operator+(p1, p2);
//	person p3 = p1 + p2;
//	//运算符重载 也可以发生函数重载
//	person p4 = p1 + 100;
//
//	cout << "p3.m_A = " << p3.m_A << endl;
//	cout << "p3.m_B = " << p3.m_B << endl;
//
//	cout << "p4.m_A = " << p4.m_A << endl;
//	cout << "p4.m_B = " << p4.m_B << endl;
//}
//只能利用全局函数重载左移运算符
ostream& operator<<(ostream &cout, person &p)//本质 operator<< (cout,p) 简化cout<<p
{
	cout << "m_A=" << p.m_A << "   m_B=" << p.m_B<<endl;
	return cout;
}
void test02() {
	person p(10,10);
	//p.m_A = 10;
	//p.m_B = 10;
	//链式编程
	cout << p<<"hello world"<<endl;
}
//前置递增
//自定义整型
class MyInteger {
	friend ostream& operator<<(ostream& cout, MyInteger myint);
public:
	MyInteger() {
		m_Num = 0;
	}
	//重载前置++运算符  返回引用为了一直对一个数据进行递增操作
	MyInteger& operator++() {
		m_Num++;
		return *this;
	 }
	//重载后置++运算符  
	//void operator++(int)  int代表占位参数，可以区分前置和后置递增
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
//赋值运算符重载
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
	//重载赋值运算符
	Person& operator=(Person& p) {
		//编译器提供的浅拷贝
		//m_age=p.m_age;

		//应该先判断是否有属性在堆区，如果有，先释放干净，然后再深拷贝
		if (m_age != NULL) {
			delete m_age;
			m_age = NULL;
		}

		m_age = new int(*p.m_age);//深拷贝
		return *this;
	}
	int* m_age;
};
void test05() {
	Person p1(18);
	Person p2(20);
	Person p3(30);

	p3=p2 = p1;//赋值
	cout<< "p1的年龄为： " << *p1.m_age << endl;
	cout << "p2的年龄为： " << *p2.m_age << endl;
	cout << "p3的年龄为： " << *p3.m_age << endl;
}
//关系运算符重载
class person1 {
public:
	person1(string name,int age) {
		m_Name = name;
		m_age = age;
	}
	//重载 == 号
	bool operator==(person1& p) {
		if (this->m_age == p.m_age && this->m_Name == p.m_Name) {
			return true;
		}
		return false;
	}
	//重载 ！= 号
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
		cout << "p1和p2是相等的! " << endl;
	}
	else {
		cout << "p1和p2是不相等的！" << endl;
	}
	if (p1 != p2) {
		cout << "p1和p2是不相等的! " << endl;
	}
	else {
		cout << "p1和p2是相等的！" << endl;
	}
}
//函数调用运算符重载
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
	myprint("Hello World");//由于使用起来非常类似于函数调用，所以称为仿函数
	Myprint02("Hello World");
}
//仿函数非常灵活，没有固定的写法
//加法类
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
	//匿名函数对象Myadd()
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