
/*
#include<iostream>
using namespace std;
//普通实现页面
//java页面
//class java {
//public:
//	void header() {
//		cout << "首页、公开课、登录、注册...(公共头部)" << endl;
//	}
//	void footer() {
//		cout << "帮助中心、交流合作、站内地图...(公共底部)" << endl;
//	}
//	void left() {
//		cout << "java、python、c++...(公共分类列表)" << endl;
//	}
//	void content() {
//		cout << "java学科视频" << endl;
//	}
//};
//继承实现页面
//公共页面类
class BasePage {
public:
	void header() {
		cout << "首页、公开课、登录、注册...(公共头部)" << endl;
	}
	void footer() {
		cout << "帮助中心、交流合作、站内地图...(公共底部)" << endl;
	}
	void left() {
		cout << "Java、Python、C++...(公共分类列表)" << endl;
	}
};
//继承的好处：减少重复代码
//语法：class 子类:  继承方式  父类
//子类也叫派生类
//父类也叫基类
class Java :public BasePage {
public:
	void content() {
		cout << "Java学科视频" << endl;
	}
};
class Python :public BasePage {
public:
	void content() {
		cout << "Python学科视频" << endl;
	}
};
class Cpp :public BasePage {
public:
	void content() {
		cout << "C++学科视频" << endl;
	}
};
void test01() {
	cout << "Java下载视频页面如下：  " << endl;
	Java ja;
	ja.header();
	ja.footer();
	ja.left();
	ja.content();
	cout << "----------------------------" << endl;
	cout << "Python下载视频页面如下：  " << endl;
	Python py;
	py.header();
	py.footer();
	py.left();
	py.content();
	cout << "----------------------------" << endl;
	cout << "C++下载视频页面如下：  " << endl;
	Cpp c;
	c.header();
	c.footer();
	c.left();
	c.content();
}
class Base1 {
public:
	int m_A;
protected:
	int m_B;
private:
	int m_C;
};
//公共继承
class Son1 :public Base1 {
public:
	void func() {
		m_A = 10;//父类中的公共权限成员 到子类依然是公共权限
		m_B = 10;//父类中的保护权限成员 到子类依然是保护权限
		//m_C = 10;//父类中的私有权限成员 子类访问不到
	}
};
void test02() {
	Son1 s1;
	s1.m_A = 100;
	//s1.m_B = 100;//到son1中是保护权限 类外访问不到
}
//保护继承
class Base2 {
public:
	int m_A;
protected:
	int m_B;
private:
	int m_C;
};
class Son2 :protected Base2 {
public:
	void func() {
		m_A = 100;//父类中的公共权限成员 到子类是保护权限
		m_B = 100;//父类中的保护权限成员 到子类是保护权限
		//m_C = 100;//父类中的私有权限成员 子类访问不到
	}
};
void test03() {
	Son2 s2;
	//s2.m_A = 100;//到son2中是保护权限 类外访问不到
	//s2.m_B = 100;//到son2中是保护权限 类外访问不到
}
//私有继承
class Base3 {
public:
	int m_A;
protected:
	int m_B;
private:
	int m_C;
};
class Son3 :private Base3 {
public:
	void func() {
		m_A = 100;//父类中的公共权限成员 到子类是私有权限
		m_B = 100;//父类中的保护权限成员 到子类是私有权限
		//m_C = 100;//父类中的私有权限成员 子类访问不到
	}
};
class GrandSon3 :public Son3 {
public:
	void func() {
		//m_A = 100;//到son3中m_A变为私有，即使是儿子也访问不到
		//m_B = 100;//到son3中m_B变为私有，即使是儿子也访问不到
	}
};
void test04() {
	Son3 s3;
	//s3.m_A = 100;//到son2中是私有成员 类外访问不到
	//s3.m_B = 100;//到son2中是私有成员 类外访问不到
}
//继承中的对象模型
class Base {
public:
	int m_A;
protected:
	int m_B;
private:
	int m_C;
};
class Son :public Base {
public:
	int m_D;
};
//利用开发人员命令提示工具查看对象模型
//跳转盘符 F：
//跳转文件路径 cd 具体路径下
//查看命名
//c1/dl reportSingleClassLayout类名 文件名
void test05() {
	//父类中所以非静态成员属性都会被子类继承下去
	//父类中私有成员属性 是被编译器给隐藏了，因此是访问不到，但是确实被继承下去了
	cout << "size of son=" << sizeof(Son) << endl;
}
//继承中的构造和析构顺序
class base {
public:
	base() {
		cout << "base的构造函数！" << endl;
	}
	~base() {
		cout << "base的析构函数！" << endl;
	}
};
class son:public base {

public:
	son() {
		cout << "son的构造函数！" << endl;
	}
	~son() {
		cout << "son的析构函数！" << endl;
	}
};
void tst01() {
	//base b;
	//构造，先父后子，析构先子后父
	son s;
}
//继承中同名成员处理
class base1 {
public:
	base1() {
		m_A = 100;
	}
	void func() {
		cout << "base1--func()调用" << endl;
	}
	void func(int a) {
		cout << "base1--func(int a)调用" << endl;
	}
	int m_A;
};
class son1 :public base1 {
public:
	son1() {
		m_A = 1000;
	}
	void func() {
		cout << "son1--func()调用" << endl;
	}
	int m_A;
};
//同名成员属性处理
void tst02() {
	son1 s;
	cout << "son1下m_A=" << s.m_A << endl;
	cout << "base1下m_A=" << s.base1::m_A << endl;//如果通过子类对象 访问到父类中同名成员，需要加作用域
}
//同名成员函数处理
void tst03() {
	son1 s;
	s.func();//直接调用子类的同名成员函数
	s.base1::func();
	//如果子类中出现和父类同名的成员函数，子类的同名成员函数会隐藏掉父类中所有同名成员函数
	//如果想访问到父类中被隐藏的同名成员函数，需要加作用域
	s.base1::func(100);
}
//继承中的同名静态成员处理方式
class base2 {
public:
	static int m_A;
	static void func() {
		cout << "base2-static void func()" << endl;
	}
};
 int base2:: m_A=100;
 class sonn :public base2 {
 public:
	 static void func() {
		 cout << "sonn-static void func()" << endl;
	 }
	 static int m_A;
 };
 int sonn::m_A = 200;
 //同名静态成员属性
 void tt01() {
	 //1、通过对象访问
	 cout << "通过对象访问： " <<  endl;
	 sonn s;
	 cout << "sonn下的m_A=" << s.m_A << endl;
	 cout << "base2下的m_A=" << s.base2::m_A << endl;
	//2、通过类名访问
	 cout << "通过类名访问： " << endl;
	 cout << "sonn下的m_A=" << sonn:: m_A << endl;
	 cout << "base2下的m_A=" << sonn::base2::m_A << endl;
	 //第一个::代表类名方式访问 第二个::代表父类作用域下
 }
 //同名静态成员函数
 void tt02() {
	 //1、通过对象访问
	 cout << "通过对象访问" << endl;
	 sonn s;
	 s.func();
	 s.base2::func();
	 //通过类名访问
	 cout << "通过类名访问" << endl;
	 sonn::func();
	 sonn::base2::func();
 }
 //多继承语法
 class bse1 {
 public:
	 bse1() {
		 m_A = 100;
	 }
	 int m_A;
 };
 class bse2 {
 public:
	 bse2() {
		 m_A = 200;
	 }
	 int m_A;
 };
 //子类继承bse1和bse2
 class soon :public bse1, public bse2 {
 public:
	 soon() {
		 m_C = 300;
		 m_D = 400;
	 }
	 int m_C;
	 int m_D;
 };
 void Test01() {
	 soon s;
	 cout << "sizeof soon =" << sizeof(s) << endl;
	 //当父类中出现同名成员，需要加作用域区分
	 cout << "bse1::m_A=" << s.bse1::m_A << endl;
	 cout << "bse2::m_A=" << s.bse2::m_A << endl;
 }
 //菱形继承
 //动物类
 class animal {//虚基类
 public:
	 int m_age;
 };
 //利用虚继承解决菱形继承问题

 class sheep :virtual public animal {

 };
 class tuo :virtual public animal {

 };
 class caonima :public sheep, public tuo {

 };
 void Tst01() {
	 caonima st;
	 st.sheep::m_age = 18;
	 st.tuo::m_age = 28;
	 //当菱形继承，两个父类有相同数据，需要加以作用域区分
	 cout << "st.sheep::m_age=" << st.sheep::m_age << endl;
	 cout << "st.tuo::m_age=" << st.tuo::m_age << endl;
	 cout << "st.m_age=" << st.m_age << endl;
	 //这份数据只要有一份就可以，菱形继承导致数据有两份，资源浪费
 }
int main() {
	//test01();
	//test05();
	//tst01();
	//tst02();
	//tst03();
	//tt01();
	//tt02();
	//Test01();
	Tst01();
	system("pause");
	return 0;
}
*/