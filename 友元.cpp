/*
#include<iostream>
#include<string.h>
using namespace std;
//ȫ�ֺ�������Ԫ
class Building {
	//goodGayȫ�ֺ�����Building�����ѣ����Է���Building��˽�г�Ա
	friend void goodGay(Building* building);
public:
	Building() {
		m_SittingRoom = "����";
		m_BedRoom = "����";
	}
public:
	string m_SittingRoom;//����
private:
	string m_BedRoom;//����
};
//ȫ�ֺ���
void goodGay(Building* building) {
	cout << "�û���ȫ�ֺ��� ���ڷ��ʣ� " << building->m_SittingRoom << endl;
	cout << "�û���ȫ�ֺ��� ���ڷ��ʣ� " << building->m_BedRoom << endl;
}
void test01() {
	Building building;
	goodGay(&building);
}
//������Ԫ
class Building1;
class GoodGay {
public:
	GoodGay();

	void visit();//�ιۺ���������Building1�е�����
	Building1* building;
};
class Building1 {
	//GoodGay���Ǳ���ĺ����ѣ����Է��ʱ�����˽�г�Ա
	friend class GoodGay;
public:
	Building1();
public:
	string m_settingRoom;
private:
	string m_bedRoom;
};
//����д��Ա����
Building1::Building1() {
	m_settingRoom = "����";
	m_bedRoom = "����";
}
GoodGay::GoodGay() {
	//�������������
	building = new Building1;
}
void GoodGay::visit() {
	cout << "�û��������ڷ��ʣ� " << building->m_settingRoom << endl;
	cout << "�û��������ڷ��ʣ� " << building->m_bedRoom << endl;
}
void test02() {
	GoodGay gg;
	gg.visit();
}
//��Ա��������Ԫ
class Building2;
class Goodgay {
public:
	Goodgay();
	
	void visit();//��visit�������Է���building��˽�г�Ա
	void visit2();//��visit���������Է���building��˽�г�Ա

	Building2* building;
};
class Building2 {
	//���߱����� Goodgay���µ�visit��Ա������Ϊ����ĺ����ѣ����Է���˽�г�Ա
	friend void Goodgay::visit();
public:
	Building2();
public:
	string m_sittingRoom;
private:
	string m_bedRoom;
};
//����ʵ�ֳ�Ա����
Building2::Building2() {
	m_sittingRoom = "����";
	m_bedRoom = "����";
}
Goodgay::Goodgay() {
	building = new Building2;
}
void Goodgay::visit() {
	cout << "visit�������ڷ��ʣ� " << building->m_sittingRoom << endl;
	cout << "visit�������ڷ��ʣ� " << building->m_bedRoom << endl;
}
void Goodgay::visit2() {
	cout << "visit2�������ڷ��ʣ� " << building->m_sittingRoom << endl;
	//cout << "visit2�������ڷ��ʣ� " << building->m_bedRoom << endl;
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