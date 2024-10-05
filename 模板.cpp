
/*#include<iostream>
using namespace std;
#include<string>
//第一种解决方式，直接包含 源文件
#include"Pperson.cpp"
//第二种解决方式
// 将.h和.cpp中的内容写在一起，将后缀名改为.hpp文件
#include"Pperson.hpp"

#include"MyArray.hpp"
//函数模板
template<class T1, class T2>
class People;
template<class T1, class T2>
void printPeople2(People<T1, T2> p) {
	cout << "类外实现--姓名：  " << p.m_name << "年龄：   " << p.m_age << endl;
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

template<typename T> //声明一个模板，告诉编译器后面代码中紧跟的T不要报错，T是一个通用数据类型
//typename可以替换成class

void mySwap(T& a, T& b) {
	T tmp = a;
	a = b;
	b = tmp;
}

void test01() {
	int a = 10;
	int b = 20;
	char c = 'c';
	//mySwap(a, c);//错误
	//函数模板注意事项//1、自动类型推导，必须推导出一致的数据类型T才可以使用
	swapInt(a, b);
	//利用函数模板方法
	//1、自动类型推导
	mySwap(a, b);
	//2、显示指定类型
	mySwap<int>(a, b);
	cout << "a= " <<a<< endl;
	cout << "b= " << b<<endl;
	//double c = 1.1;
	//double d = 2.2;
	//swapDouble(c,d);
	//cout << "c= " << c << endl;
	//cout << "d= " << d << endl;
}
 
//函数模板注意事项//2、模板必须要确定出T的数据类型，才可以使用
template<class T>
void func() {
	cout << "func 调用" << endl;
}
void test02() {
	//func();//错误
	func<int>();
}

//实现通用 对数组进行排序的函数
//从大到小
//算法 选择排序
//测试 char int 数组

//排序算法
template<class T>
void mySort(T arr[], int len) {
	for (int i = 0; i < len; i++) {
		int max = i;
		for (int j = i + 1; j < len; j++) {
			if (arr[max] < arr[j]) {
				max = j;//更新最大值的下标
			}
		}
		if (max != i) {
			//交换
			mySwap(arr[max], arr[i]);
		}
	}
}
//提供打印数组模板
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
//普通函数和函数模板区别
//1、普通函数调用可以发生隐式类型转换
//2、函数模板 用自动类型推导，不可以发生隐式类型转换
//3、函数模板用显示指定类型，可以发生隐式类型转换

//普通函数
int myAdd01(int a,int b) {
	return a + b;
}
void test05() {
	int a = 10;
	int b = 20;
	char c = 'c';//转换成ACLL码
	cout << myAdd01(a, c) << endl;
}
//函数模板
template<class T>
int myAdd02(T a, T b) {
	return a + b;
}
void test06() {
	int a = 10;
	int b = 20;
	char c = 'c';//转换成ACLL码
	//cout << myAdd02(a, c) << endl;//错误    用自动类型推导，不可以发生隐式类型转换
	cout << myAdd02<int>(a, c) << endl ;//用显示指定类型，可以发生隐式类型转换
}
//普通函数与函数模板的调用规则
//1、如果函数模板和普通函数都可以调用，优先调用普通函数
//2、可以通过空模板参数列表 强制调用 函数模板
//3、函数模板可以发生函数重载
//4、如果函数模板可以产生更好的匹配，优先调用函数模板

void myPrint(int a, int b) {
	cout << "调用的普通函数" << endl;
}
template<class T>
void myPrint(T a, T b) {
	cout << "调用的函数模板" << endl;
}
template<class T>
void myPrint(T a, T b,T c) {
	cout << "调用的函数重载模板" << endl;
}
void test07() {
	int a = 10; int b = 20;
	//myPrint(a, b);//如果函数模板和普通函数都可以调用，优先调用普通函数
	//通过空模板参数列表 强制调用 函数模板
	//myPrint<>(a, b);
	//myPrint(a, b, 100);
	//如果函数模板可以产生更好的匹配，优先调用函数模板
	char c1 = 'a';
	char c2 = 'b';
	myPrint(c1, c2);//这个案例中，调用普通函数得转换，麻烦点，调用模板直接推导
}
//模板的局限性
//模板不是万能的，有些特定的数据类型，需要用具体化方式做特殊实现
class Person {
public:
	Person(string name, int age) {
		this->m_name = name;
		this->m_age = age;
	}
	string m_name;
	int m_age;
};
//对比两个数据是否相等函数
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
}//利用具体化person的版本实现代码，具体优化调用
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
//类模板
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
	person<string, int>p1("孙悟空", 999);
	p1.showPerson();
}
//类模板和函数模板的区别
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
//1、类模板没有自动类型推导使用方式
void test11() {
	//person1 p("孙悟空", 100);//错误
	person1<string, int>p("孙悟空", 1000);//正确
	p.showPerson();
}
//2、类模板在模板参数列表中可以有默认参数
void test12() {
	person1<string>p("猪八戒", 1000);
	p.showPerson();
}
//类模板中成员函数创建时机
//类模板中成员函数在调用时才去创建
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
	//类模板中的成员函数
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
//类模板对象做函数参数
template<class T1,class T2>
class person3 {
public:
	person3(T1 name, T2 age) {
		this->m_name = name;
		this->m_age = age;
	}
	void showperson3() {
		cout << "姓名： " << this->m_name<<" 年龄： "<<this->m_age<<endl;
	}
	T1 m_name;
	T2 m_age;
};
//1、指定传入类型	最广泛
void printperson1(person3<string, int>&p) {
	p.showperson3();
}
void tst01() {
	person3<string, int>p("孙悟空", 100);
	printperson1(p);
}
//2、参数模板化
template<class T1,class T2>
void printperson2(person3<T1,T2>&p) {
	p.showperson3();
	cout << "T1的类型为：" << typeid(T1).name() << endl;
	cout << "T2的类型为：" << typeid(T2).name() << endl;
}
void tst02() {
	person3<string, int>p("猪八戒", 90);
	printperson2(p);
}
//3、整个类模板化
template<class T>
void printperson3(T &p) {
	p.showperson3();
	cout << "T的数据类型为： " << typeid(T).name() << endl;
}
void tst03() {
	person3<string, int>p("唐僧", 30);
	printperson3(p);
}
//类模板与继承
template<class T>
class Base {
	T m;
};
//class Son :public Base {//错误，必须知道父类中的T类型，才能继承给子类
class Son :public Base<int> {

};

void tst04() {
	Son s1;
}
//如果想灵活指定父类中T类型，子类也需要变类模板
template<class T1,class T2>
class Son2 :public Base<T2> {
public:
	Son2() {
		cout << "T1的数据类型为： " << typeid(T1).name()<<endl;
		cout << "T2的数据类型为： " << typeid(T2).name() << endl;
	}
	T1 obj;
};
void tst05() {
	Son2<int, char>s2;
}
//类模板成员函数类外实现
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
	//	cout << "姓名：" << this->m_name << " 年龄：" << this->m_age << endl;
	//}
	T1 m_name;
	T2 m_age;
};
//构造函数类外实现
template<class T1,class T2>
people<T1, T2>::people(T1 name, T2 age) {
	this->m_name=name;
	this->m_age=age;
}
//成员函数类外实现
template<class T1, class T2>
void people<T1, T2>::showpeople() {
	cout << "姓名：" << this->m_name << " 年龄：" << this->m_age << endl;
}
void tst07() {
	people<string, int>p("Tom", 20);
	p.showpeople();
}
//类模板分文件编写问题以及解决
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
//	cout << "姓名：" << this->m_name << " 年龄：" << this->m_age << endl;
//}
void test1() {
	Pperson<string, int>p1("Jerry", 18);
	p1.showPpeople();
}
//类模板和友元
//通过全局函数打印People信息

template<class T1,class T2>
class People {
	//全局函数类内实现
	friend void printPeople(People<T1, T2> p) {
		cout << "姓名：  " << p.m_name << "年龄：   " << p.m_age << endl;
	}
	//全局函数类外实现
	//加空模板参数列表
	//如果全局函数是类外实现 需要让编译器提前知道这个函数的存在
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
//	cout << "类外实现--姓名：  " << p.m_name << "年龄：   " << p.m_age << endl;
//}

//1、全局函数类内实现
void test2() {
	People<string, int>p("Tom", 20);
	printPeople(p);
}
//2、全局函数类外实现
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
	cout << "arr1的打印输出为：" << endl;
	printIntArray(arr1);
	cout << "arr1的容量为：" <<arr1.getCapacity()<< endl;
	cout << "arr1的大小为：" << arr1.getSize()<<endl;

	MyArray<int>arr2(arr1);
	cout << "arr2的打印输出为：" << endl;
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