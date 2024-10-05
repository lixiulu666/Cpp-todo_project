//封装
/*
#include<iostream>
#include<string.h>
#include"Point.h"
#include"circle.h"
using namespace std;

const double PI = 3.14;

class Circle
{
	//访问权限

public:

	//属性
	int m_r;
	//行为
	double caculateZC() {
		return 2 * PI * m_r;
	}
};
class Student {
public:
	string m_name;
	int m_id;
	void showStudent() {
		cout << "姓名：" << m_name << "  学号：" << m_id << endl;
	}
	//赋值行为
	void setname(string name) {
		m_name = name;
	}
	void setID(int id) {
		m_id = id;
	}
};
//三种访问权限
//public	成员 类内可以访问，类外可以访问
//protected	成员 类内可以访问，类外不可以访问，儿子可以访问父亲中的保护内容
//private	成员 类内可以访问，类外不可以访问，儿子不可以访问父亲中的私有内容
class person {

public:
	string m_name;

protected:
	string m_car;

private:
	int m_password;
public:
	void func() {
		m_name = "张三";
		m_car = "拖拉机";
		m_password = 123456;
	}

};
class C1 {
	int m_a;
};
struct C2 {
	int m_a;
};
//成员属性设置私有
//1、可以自己控制读写权限
//2、对于写可以检测数据有效性
class Person {
public:
	void setname(string name) {
		m_name = name;
	}
	string getname() {
		return m_name;
	}
	int getage() {
		return m_age;
	}
	void setidol(string idol) {
		m_idol = idol;
	}
private:
	string m_name;//可读可写
	int m_age;//只读
	string m_idol;//只写
};

class Cube {
public:
	void setL(int l) {
		m_L = l;
	}
	int getL() {
		return m_L;
	}

	void setW(int w) {
		m_W = w;
	}
	int getW() {
		return m_W;
	}

	void setH(int h) {
		m_H = h;
	}
	int getH() {
		return m_H;
	}

	int caculateS() {
		return 2 * m_L * m_W + 2 * m_W * m_H + 2 * m_L * m_H;
	}
	int caculateV() {
		return  m_L * m_W * m_H ;
	}

	bool issamebyclass(Cube &c) {
		if (m_L == c.getL() || m_W == c.getW() || m_H == c.getH()) {
			return true;
		}
		return false;
	}
private:
	int m_L;
	int m_W;
	int m_H;
};

bool issame(Cube &c1, Cube &c2) {
	if (c1.getL() == c2.getL() || c1.getW() == c2.getW() || c1.getH() == c2.getH()) {
		return true;
	}
	return false;
}

//class Point {
//public:
//	void setx(int x) {
//		m_x = x;
//	}
//	int getx() {
//		return m_x;
//	}
//	void sety(int y) {
//		m_y = y;
//	}
//	int gety() {
//		return m_y;
//	}
//private:
//	int m_x;
//	int m_y;
//};

//class circle {
//public:
//	void setr(int r) {
//		m_r = r;
//	}
//	int getr() {
//		return m_r;
//	}
//	void setcenter(Point center) {
//		m_center = center;
//	}
//	Point getcenter() {
//		return m_center;
//	}
//private:
//	int m_r;
//	Point m_center;
//};
void isincircle(circle& c, Point& p) {
	double distance =
		(c.getcenter().getx() - p.getx()) * (c.getcenter().getx() - p.getx()) +
		(c.getcenter().gety() - p.gety()) * (c.getcenter().gety() - p.gety());
	double rdistance = c.getr() * c.getr();
	if (distance == rdistance) {
		cout << "点在圆上" << endl;
	}else if (distance > rdistance) {
		cout << "点在圆外" << endl;
	}else {
		cout << "点在圆内" << endl;
	}
}
int main() {
	//Circle c1;
	//c1.m_r = 10;
	//cout << "圆的周长为：" << c1.caculateZC() << endl;
	//Student s1,s2;
	//s1.m_name = "张三";
	//s1.setname("张三");
	//s1.m_id = 1;
	//s1.setID(1);
	//s2.m_name = "李四";
	//s2.m_id = 2;
	//s1.showStudent();
	//s2.showStudent();
	//person p1;
	//p1.m_name = "李四";
	////p1.m_car = "奔驰";//保护权限，类外访问不到
	////p1.password = "123";//私有权限，类外访问不到
	//p1.func(); 

	////struct和class区别
	////struct默认权限是公有
	////class默认权限是私有
	//C1 c1;
	////c1.m_a = 100;//私有成员不可访问
	//C2 c2;
	//c2.m_a = 100;//可以访问

	//Person p;
	////p.m_name = "张三";//不可访问
	//p.setname("张三");
	//cout << "姓名: " << p.getname() << endl;
	////p.m_age=20;//不可访问
	//cout << "年龄: " << p.getage() << endl;//获取可以
	//p.setidol("小明");//只写的状态
	//Cube c1;
	//c1.setL(10);
	//c1.setW(10);
	//c1.setH(10);

	//cout << "c1的面积为： " << c1.caculateS() << endl;
	//cout << "c1的体积为： " << c1.caculateV() << endl;
	//Cube c2;
	//c2.setL(10);
	//c2.setW(10);
	//c2.setH(10);
	////利用全局函数判断
	//bool ret = issame(c1, c2);
	//if (ret) {
	//	cout << "相等" << endl;
	//}
	//else {
	//	cout << "不相等" << endl;
	//}
	////利用成员函数判断
	//ret = c1.issamebyclass(c2);
	//if (ret) {
	//	cout << "成员函数判断：相等" << endl;
	//}
	//else {
	//	cout << "成员函数判断：不相等" << endl;
	//}
	
	//circle c;
	//c.setr(10);
	//Point center;
	//center.setx(10);
	//center.sety(0);
	//Point p;
	//p.setx(10);
	//p.sety(10);

	//isincircle(c, p);
	system("pause");
	return 0;
}*/