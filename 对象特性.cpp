/*
#include<iostream>
#include<string.h>
using namespace std;
//对象的初始化和清理
class Person {
public://1、构造函数 初始化
	//构造函数没有返回值 不用写void
	//函数名和类名相同
	//可以有参数，可以发生重载
	//创建对象的时候，构造函数会自动调用，而且只调用一次
	//编译器会默认写一个空实现的构造函数
	Person() {
		cout << "Person构造函数的调用" << endl;
		
	}
	//析构函数 进行清理
	//没有返回值 不写void
	//函数名和类名相同 在名称前加~
	//不可以有参数 不可以发生重载
	//对象在销毁前 会自动调用析构函数，而且只会调用一次
	~Person() {
		cout << "Person的析构函数调用" << endl;
	}

};
//构造和析构是必须有的实现，如果自己不提供，编译器会提供空实现
class person {
public:	
	person() {
		cout << "person无参构造函数的调用" << endl;
	}
	person(int a) {
		age = a;
		cout << "person有参构造函数的调用" << endl;
	}
	//拷贝构造函数
	person(const person &p) {
		//将传入的人身上的所有属性拷贝在我身上
		cout << "person拷贝构造函数的调用" << endl;
		age = p.age;
	}
	~person() {
		cout << "person析构函数的调用" << endl;
	}
	int age;
};
void test01() {
	Person p;//在栈上的数据，test01执行完毕后，会自动释放这个对象
}
void test02() {
	//1、括号法
	//person p1;//默认构造函数调用
	//person p2(10);//有参构造函数
	//person p3(p2);//拷贝构造函数

	//cout << "p2的年龄为： " << p2.age<<endl;
	//cout << "p3的年龄为： " << p3.age << endl;
	// 注意事项：调用默认构造函数时候，不要加()
	//person p1();//编译器会认为是一个函数的声明，不会认为在创建对象
	
	//2、显示法
	//person p1;
	//person p2=person(10);//有参
	//person p3 = person(p2);//拷贝

	//person(10);//匿名对象，这行结束后系统会立即回收掉匿名对象,执行析构
	//cout << "aaaa" << endl;
	//注意事项：不要利用拷贝构造函数来初始化匿名对象，编译器会认为person(p3)==person p3
	//person(p3);

	//3、隐式转换法
	person p4 = 10;//相当于person p4=person(10),调用有参构造
	person p5 = p4;//拷贝构造
}
class person1 {
public:
	person1() {
		cout << "person1默认构造函数调用" << endl;

	}
	person1(int age) {
		cout << "person1有参构造函数调用" << endl;
		m_age = age;
	}
	person1(const person1& p) {
		cout << "person1拷贝构造函数调用" << endl;
		m_age = p.m_age;
	}
	~person1() {
		cout << "person1析构函数调用" << endl;

	}
	int m_age;
};
//拷贝构造函数调用时机
//1、使用一个已经创建完毕的对象来初始化一个新对象
void test03() {
	person1 p1(20);
	person1 p2(p1);

	cout << "p2的年龄为： " << p2.m_age << endl;
}
//2、值传递的方式给函数参数传值
void dowork(person1 p) {

}
void test04() {
	person1 p;
	dowork(p);//相当于拷贝构造函数
}
//3、值方式返回局部对象
person1 dowork2() {
	person1 p1;
	cout << (int*)&p1 << endl;
	return p1;
}
void test05() {
	person1 p = dowork2();
	cout << (int*)&p << endl;//p和p1不是同一个对象

}
//构造函数的调用规则
//1、创建一个类，C++编译器会给每个类都添加至少三个函数
//默认构造（空实现）   析构函数（空实现）   拷贝构造（值拷贝）
class people {
public:
	people() {
		cout <<"people的默认构造函数调用" << endl;
	}
	people(int age) {
		cout << "people的有参构造函数调用" << endl;
		m_age = age;
	}
	people(const people& p) {
		cout << "people的拷贝构造函数调用" << endl;
		m_age = p.m_age;
	}
	~people() {
		cout << "people的析构函数调用" << endl;
	}
	int m_age;
};
void test06() {
	people p;
	p.m_age = 18;
	people p2(p);
	cout << "p2的年龄为： " << p2.m_age << endl;
}
//2、如果我们写了有参构造函数，编译器就不再提供默认构造，依然提供拷贝构造
//如果写了拷贝构造函数，编译器就不再提供其他普通构造函数了
void test07() {
	//people p;//不写默认构造会报错
	people p(28);
	people p2(p);
	cout << "p2的年龄为： " << p2.m_age << endl;
}
//深拷贝和浅拷贝
//浅拷贝：简单的赋值拷贝操作
//深拷贝：在堆区重新申请空间，进行拷贝操作
class People {
public:
	People() {
		cout << "People的默认构造函数调用" << endl;
	}
	People(int age,int height) {
		m_age = age;
		m_height=new int(height);
		cout << "People的有参构造函数调用" << endl;
	}
	//自己实现拷贝构造函数 解决浅拷贝带来的问题
	People(const People& p) {
		cout << "People拷贝构造函数的调用" << endl;
		m_age = p.m_age;
		//m_height=p.m_height;编译器默认实现就是这行代码
		//深拷贝操作
		m_height=new int(*p.m_height);
	}
	~People() {
		//析构代码，将堆区开辟数据作释放操作
		if (m_height != NULL) {
			delete m_height;
			m_height = NULL;
		}
		cout<< "People的析构函数调用" << endl;
	}
	int m_age;
	int *m_height;
};
void test08() {
	People p1(18,160);
	cout << "p1的年龄为：" << p1.m_age << "身高为： "<<*p1.m_height<<endl;
	People p2(p1);
	cout << "p2的年龄为：" << p2.m_age << "身高为： " << *p1.m_height<<endl;
}
//初始化列表
class human {
public:
	//传统初始化
	//human(int a, int b, int c) {
	//	m_A = a;
	//	m_B = b;
	//	m_C = c;
	//}
	
	//初始化列表初始化属性
	//human() :m_A(10), m_B(20), m_C(30)//局限赋值
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
//类对象作为类成员
class Phone {
public:
	Phone(string pName) {
		cout << "Phone的构造函数调用" << endl;
		m_PName = pName;
	}
	~Phone() {
		cout << "Phone的析构函数调用" << endl;
	}
	string m_PName;
};
class Human {
public:
	//Phone m_phone=pName 隐式转换法
	Human(string name, string pName) :m_name(name), m_phone(pName) {
		cout << "Human的构造函数调用" << endl;
	}
	~Human() {
		cout << "Human的析构函数调用" << endl;
	}
	string m_name;
	Phone m_phone;
};
//当其他类对象作为本类成员，构造的时候先构造类对象，再构造自身
//析构的顺序与构造相反
void tst02() {
	Human p("张三", "苹果MAX");
	cout << p.m_name << "拿着： " << p.m_phone.m_PName << endl;
}
//静态成员变量
class someone {
public:
	//1、所有对象共享同一份数据
	//2、编译阶段就分配内存
	//3、类内声明，类外初始化
	static int m_A;

	//静态成员变量也有访问权限
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

	cout << p.m_A << endl;//结果为200,p和p2共享同一块数据
}
void tst04() {
	//静态成员变量 不属于某个对象上，所有对象共享同一份数据
	//两种访问方式
	//1、通过对象访问
	//someone p;
	//cout << p.m_A << endl;
	//2、通过类名访问
	cout << someone::m_A << endl;
	//cout << someone::m_B << endl;//类外访问不了私有静态成员变量
}
//静态成员函数
//所有对象共享同一个函数
//静态成员函数只能访问静态成员变量
class ren {
public:

	static void func() {
		m_A = 100;//静态成员函数可以访问 静态成员变量
		//m_B = 200;//报错，不可以访问非静态成员变量，无法区分到底是哪个对象的m_B
		cout << "static void func的调用" << endl;
	}
	static int m_A;
	int m_B;

	//静态成员函数也是有访问权限的
private:
	static void func2() {
		cout << "static void func2的调用" << endl;
	}
};
int ren::m_A = 0;
void tst05() {
	//1、通过对象访问
	ren p;
	p.func();
	//2、通过类名访问
	ren::func();
	//ren::func2();//类外不可访问
}
//成员变量和成员函数分开存储
class ren1 {
	int m_a;//非静态成员变量属于类的对象上
	static int m_B;//静态成员变量不属于类的对象上
	void func() {}//非静态成员函数不属于类的对象上
	static void func2() {}//静态成员函数也是
};
void tet01() {
	ren1 p;
	//空对象占用内存空间为；1
	//C++编译器会给每个空对象也分配一个字节空间，是为了区分空对象占内存的位置
	//每个空对象也应该有一个独一无二的内存地址
	cout << "size of p=" << sizeof(p) << endl;
}
void tet02() {
	ren1 p;
	cout << "size of p=" << sizeof(p) << endl;//int 的字节
}
class renn {
public:
	renn(int age) {
		this->age = age;//指向被调用的成员函数所属的对象
	}
	renn& rennaddage(renn p) {
		this->age += p.age;
		return *this;//this指向p2的指针，*this指向的是p2这个对象本体
	}
	int age;
};
//this指针
//1、解决名称冲突
void tet03() {
	renn p1(18);
	cout << "p1的年龄为： " << p1.age << endl;
}
//2、返回对象本身用*this
void tet04() {
	renn p1(10);
	renn p2(10);
	//链式编程思想
	p2.rennaddage(p1).rennaddage(p1).rennaddage(p1);
	cout << "p2的年龄为： " <<p2.age<< endl;
}
class ren2 {
public:
	void showClassName() {
		cout << "this is ren2 class" << endl;
	}
	void showClassage() {
		//报错是因为传入指针为NULL
		//cout << "age= "<<m_age << endl;
		if (this == NULL) {
			return;
		}//加这行代码预防出错
		cout << "age= " << this->m_age << endl;
	}
	int m_age;
};
void tt01() {
	ren2* p=NULL;
	p->showClassName();
	p->showClassage();
}
//常函数
class ren3 {
public:
	//this指针的本质是一个指针常量，指针的指向不可以修改
	//const ren3 *const this;
	//在成员函数后面加const，修饰的是this指向，让指针指向的值也不可以修改
	void showren3() const{//如果不加const,可以修改
		this->m_B = 100;
		//this->m_A = 100;
		//this = NULL;//THIS指针的指向不可以修改
	}
	void func() {
		m_A = 100;
	}
	int m_A;
	mutable int m_B;//特殊变量，即使在常函数中，也可以修改这个值，加关键字mutable
};
void tt02() {
	ren3 p;
	p.showren3();
}
//常对象
void tt03() {
	const ren3 p;//在对象前加const，变为常对象
	//p.m_A = 100;//不可以修改
	p.m_B = 100;//在常对象也可以修改这个特殊的值
	//常对象只能调用常函数
	p.showren3();
	//p.func();//普通成员函数可以修改属性
}
int main() {
	//test01();//在调用函数里面会释放
	//Person p;
	//system("pause");//这行代码结束后才会释放
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