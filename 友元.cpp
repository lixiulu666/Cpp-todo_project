/*
#include<iostream>
#include<string.h>
using namespace std;
//全局函数做友元
class Building {
	//goodGay全局函数是Building好朋友，可以访问Building中私有成员
	friend void goodGay(Building* building);
public:
	Building() {
		m_SittingRoom = "客厅";
		m_BedRoom = "卧室";
	}
public:
	string m_SittingRoom;//客厅
private:
	string m_BedRoom;//卧室
};
//全局函数
void goodGay(Building* building) {
	cout << "好基友全局函数 正在访问： " << building->m_SittingRoom << endl;
	cout << "好基友全局函数 正在访问： " << building->m_BedRoom << endl;
}
void test01() {
	Building building;
	goodGay(&building);
}
//类做友元
class Building1;
class GoodGay {
public:
	GoodGay();

	void visit();//参观函数，访问Building1中的属性
	Building1* building;
};
class Building1 {
	//GoodGay类是本类的好朋友，可以访问本类中私有成员
	friend class GoodGay;
public:
	Building1();
public:
	string m_settingRoom;
private:
	string m_bedRoom;
};
//类外写成员函数
Building1::Building1() {
	m_settingRoom = "客厅";
	m_bedRoom = "卧室";
}
GoodGay::GoodGay() {
	//创建建筑物对象
	building = new Building1;
}
void GoodGay::visit() {
	cout << "好基友类正在访问： " << building->m_settingRoom << endl;
	cout << "好基友类正在访问： " << building->m_bedRoom << endl;
}
void test02() {
	GoodGay gg;
	gg.visit();
}
//成员函数做友元
class Building2;
class Goodgay {
public:
	Goodgay();
	
	void visit();//让visit函数可以访问building中私有成员
	void visit2();//让visit函数不可以访问building中私有成员

	Building2* building;
};
class Building2 {
	//告诉编译器 Goodgay类下的visit成员函数作为本类的好朋友，可以访问私有成员
	friend void Goodgay::visit();
public:
	Building2();
public:
	string m_sittingRoom;
private:
	string m_bedRoom;
};
//类外实现成员函数
Building2::Building2() {
	m_sittingRoom = "客厅";
	m_bedRoom = "卧室";
}
Goodgay::Goodgay() {
	building = new Building2;
}
void Goodgay::visit() {
	cout << "visit函数正在访问： " << building->m_sittingRoom << endl;
	cout << "visit函数正在访问： " << building->m_bedRoom << endl;
}
void Goodgay::visit2() {
	cout << "visit2函数正在访问： " << building->m_sittingRoom << endl;
	//cout << "visit2函数正在访问： " << building->m_bedRoom << endl;
}
void test03() {
	Goodgay gg;
	gg.visit();
	gg.visit2();
}
int main() {
	//test01();
	//test02();
	test03();
	system("pause");
	return 0;
}
*/