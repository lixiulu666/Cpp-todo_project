/*
#include<iostream>
using namespace std;
#include<fstream>
#include<string>
//�ı��ļ� д�ļ�
void test01() {
	//1������ͷ�ļ� fstream
	//2������������
	ofstream ofs;
	//3��ָ���򿪷�ʽ
	ofs.open("test.txt", ios::out);
	//4��д����
	ofs << "����������" << endl;
	ofs << "�Ա���" << endl;
	ofs << "���䣺18" << endl;
	//5���ر��ļ�
	ofs.close();

}
//�ı��ļ� ���ļ�
void test02() {
	//1������ͷ�ļ�

	//2������������
	ifstream ifs;
	//3�����ļ� �����ж��Ƿ�򿪳ɹ�
	ifs.open("test.txt", ios::in);

	if (!ifs.is_open()) {
		cout << "�ļ���ʧ��" << endl;
		return;
	}
	//4��������
	//��һ��
	//char buf[1024] = { 0 };
	//while (ifs>>buf) {
	//	cout << buf << endl;
	//}
	
	//�ڶ���
	//char buf[1024] = { 0 };
	//while (ifs.getline(buf,1024)) {//sizeof(buf)
	//	cout << buf << endl;
	//}

	//������
	//string buf;
	//while (getline(ifs, buf)) {
	//	cout << buf << endl;
	//}

	//������
	char c;
	while ((c = ifs.get()) != EOF) {//end of file
		cout << c;
	}

	//5���ر��ļ�
	ifs.close();
}
//�������ļ� д�ļ�
class Person {
public:
	char m_name[64];
	int m_age;
};
void test03() {
	//ofstream ofs;
	//ofs.open("person.txt", ios::out | ios::binary);
	ofstream ofs("person.txt", ios::out | ios::binary);
	Person p = { "����",18 };
	ofs.write((const char*)&p,sizeof(Person));
	ofs.close();
}
//�������ļ� ���ļ�
void test04() {
	ifstream ifs;
	ifs.open("person.txt", ios::in | ios::binary);
	if (!ifs.is_open()) {
		cout << "�ļ���ʧ��" << endl;
		return;
	}
	Person p;
	ifs.read((char*)&p, sizeof(Person));
	cout << "������  " << p.m_name << "   ���䣺  " << p.m_age << endl;
	ifs.close();
}
int main() {
	//test01();
	//test02();
	//test03();
	test04();
	system("pause");
	return 0;
}
*/