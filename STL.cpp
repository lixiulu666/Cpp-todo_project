#include<vector>
#include<algorithm>
#include<iostream>
#include<string>
#include<deque>
#include<stack>
#include<queue>
#include<list>
#include<set>
#include<map>
using namespace std;
//vector���������������
void myPrint(int val) {
	cout<<val << endl;
}
void test01() {
	vector<int> v;
	v.push_back(10);
	v.push_back(20);
	v.push_back(30);
	v.push_back(40);
	//vector<int>::iterator itBegin = v.begin();//��ʼ������ ָ�������е�һ��Ԫ��
	//vector<int>::iterator itEnd = v.end();//���������� ָ�����������һ��Ԫ�ص���һ��λ��
	// ��һ�ֱ�����ʽ
	//while (itBegin != itEnd) {
	//	cout << *itBegin << endl;
	//	itBegin++;
	//}

	//�ڶ��ֱ�����ʽ
	//for (vector<int>::iterator it = v.begin(); it != v.end(); it++) {
	//	cout << *it << endl;
	//}

	//�����ֱ�����ʽ	����STL�ṩ�����㷨
	for_each(v.begin(), v.end(),myPrint);//���ûص�����

}
//vector����Զ�����������
class Person {
public:
	Person(string name, int age) {
		this->m_name = name;
		this->m_age = age;
	}
	string m_name;
	int m_age;
};
void test02() {
	vector<Person>v;
	Person p1("aaa", 10);
	Person p2("bbb", 20);
	Person p3("ccc", 30);
	Person p4("ddd", 40);
	Person p5("eee", 50);
	v.push_back(p1);
	v.push_back(p2);
	v.push_back(p3);
	v.push_back(p4);
	v.push_back(p5);
	for (vector<Person>::iterator it = v.begin(); it != v.end(); it++) {
		//cout << "������" << (*it).m_name << " ���䣺" << (*it).m_age << endl;
		cout << "������" << it->m_name << " ���䣺" << it->m_age << endl;
	}
}
//����Զ�����������ָ��
void test03() {
	vector<Person*>v;
	Person p1("aaa", 10);
	Person p2("bbb", 20);
	Person p3("ccc", 30);
	Person p4("ddd", 40);
	Person p5("eee", 50);
	v.push_back(&p1);
	v.push_back(&p2);
	v.push_back(&p3);
	v.push_back(&p4);
	v.push_back(&p5);
	for (vector<Person*>::iterator it = v.begin(); it != v.end(); it++) {
		cout << "������" << (*it)->m_name << " ���䣺" << (*it)->m_age << endl;
	}
}
//����Ƕ������
void test04() {
	vector<vector<int>>v;
	vector<int>v1;
	vector<int>v2;
	vector<int>v3;
	vector<int>v4;
	for (int i = 0; i < 4; i++) {
		v1.push_back(i + 1);
		v2.push_back(i + 2);
		v3.push_back(i + 3);
		v4.push_back(i + 4);
	}
	v.push_back(v1);
	v.push_back(v2);
	v.push_back(v3);
	v.push_back(v4);
	for (vector<vector<int>>::iterator it = v.begin(); it != v.end(); it++) {
		//(*it)-----����vector<int>
		for (vector<int>::iterator vit = (*it).begin(); vit != (*it).end(); vit++) {
			cout << *vit << " ";
		}
		cout << endl;
	}
}
//string���캯��
void test05() {
	string s1;//Ĭ�Ϲ���
	const char * str= "hello world";
	string s2(str);
	cout << "s2= " << s2 << endl;
	string s3(str);
	cout << "s3= " << s3 << endl;
	string s4(10,'a');
	cout << "s4= " << s4 << endl;
}
//string��ֵ
void test06() {
	string str1;
	str1 = "hello world";
	cout << "str1= " << str1 << endl;

	string str2;
	str2 = str1;
	cout << "str2= " << str2 << endl;

	string str3;
	str3 = 'a';
	cout << "str3= " << str3 << endl;

	string str4;
	str4.assign("hello C++");
	cout << "str4= " << str4 << endl;

	string str5;
	str5.assign("hello C++", 5);
	cout << "str5= " << str5 << endl;

	string str6;
	str6.assign(str5);
	cout << "str6= " << str6 << endl;

	string str7;
	str7.assign(10,'w');
	cout << "str7= " << str7 << endl;
}
//string�ַ���ƴ��
void test07() {
	string str1 = "��";
	str1 += "������Ϸ";
	cout << "str1 = " << str1 << endl;

	str1 += ':';
	cout << "str1 = " << str1 << endl;

	string str2 = "LOL DNF ";
	str1 += str2;
	cout << "str1 = " << str1 << endl;

	string str3 = "I";
	str3.append(" love ");
	cout << "str3 = " << str3 << endl;

	str3.append("game abcde", 4);
	cout << "str3 = " << str3 << endl;

	//str3.append(str2);
	//cout << "str3 = " << str3 << endl;

	str3.append(str2,0,3);
	cout << "str3 = " << str3 << endl;
}
//�ַ������Һ��滻
void test08() {
	string str1 = "abcdefgde";
	int pos=str1.find("de");
	if (pos == -1) {
		cout << "δ�ҵ��ַ���" << endl;
	}
	else {
		cout << "pos="<<pos << endl;
	}
	//rfind����������ң�rfind�������Ҳ���
	int pos1=str1.rfind("de");
	cout << "pos1=" << pos1 << endl;
}
void test09() {
	string str1 = "abcde";
	str1.replace(1, 3, "1111");
	cout << "str1 = " << str1 << endl;
}
//�ַ����Ƚ�
void test10(){
	string str1 = "xello world";
	string str2 = "zello world";
	if (str1.compare(str2) == 0) {
		cout << "str1=str2" << endl;
	}
	else if (str1.compare(str2) > 0) {
		cout << "str1>str2" << endl;
	}
	else {
		cout << "str1<str2" << endl;
	}
}
//�ַ�����ȡ
void test11() {
	string str = "hello";
	cout << "str = " << str << endl;
	for (int i = 0; i < str.size(); i++) {
		cout << str[i] << " ";
	}
	cout << endl;
	for (int i = 0; i < str.size(); i++) {
		cout << str.at(i) << " ";
	}
	cout << endl;

	str[0] = 'x';
	cout << "str = " << str << endl;

	str.at(1) = 'x';
	cout << "str = " << str << endl;
}
//�ַ��������ɾ��
void test12() {
	string str = "hello";
	str.insert(1, "111");
	cout << "str = " << str << endl;
	str.erase(1, 3);
	cout << "str = " << str << endl;
}
//string���Ӵ�
void test13() {
	string str = "abcdf";
	string subStr = str.substr(1, 3);
	cout << "subStr=" << subStr << endl;
}
//ʵ�ò���
void test14() {
	string email = "hello@sina.com";
	//���ʼ���ַ�� ��ȡ �û�����Ϣ
	int pos = email.find("@");
	cout << pos << endl;
	string usrName = email.substr(0, pos);
	cout << usrName << endl;
}
//vector��������
void printVector(vector<int>&v) {
	for (vector<int>::iterator it = v.begin(); it != v.end(); it++) {
		cout << *it << " ";
	}
	cout << endl;
}
void test15() {
	vector<int>v1;//Ĭ�� �޲ι���
	for (int i = 0; i < 10; i++) {
		v1.push_back(i);
	}
	printVector(v1);
	//ͨ�����䷽ʽ����ɨ��
	vector<int>v2(v1.begin(), v1.end());
	printVector(v2);
	//n��elem��ʽ����
	vector<int>v3(10, 100);
	printVector(v3);
	//��������
	vector<int>v4(v3);
	printVector(v4);
}
//vector��ֵ
void test16() {
	vector<int>v1;
	for (int i = 0; i < 10; i++) {
		v1.push_back(i);
	}
	printVector(v1);

	vector <int>v2;
	v2 = v1;
	printVector(v2);

	vector <int>v3;
	v3.assign(v1.begin(), v1.end());
	printVector(v3);

	vector <int>v4;
	v4.assign(10,100);
	printVector(v4);
}
//vector�����������ʹ�С����
void test17() {
	vector<int>v1;
	for (int i = 0; i < 10; i++) {
		v1.push_back(i);
	}
	printVector(v1);
	if (v1.empty()) {
		cout << "v1Ϊ��" << endl;
	}
	else {
		cout << "v1��Ϊ��" << endl;
		cout << "v1������Ϊ��" << v1.capacity() << endl;
		cout << "v1�Ĵ�СΪ��" << v1.size() << endl;
	}
	//����ָ����С
	v1.resize(15,100);
	printVector(v1);//�������ָ���ı�ԭ�����ˣ�Ĭ����0����µ�λ��

	v1.resize(5);
	printVector(v1);////�������ָ���ı�ԭ�����ˣ��������ֻ�ɾ��
}
//vector�����ɾ��
void test18() {
	vector<int>v1;
	for (int i = 1; i <= 5; i++) {
		v1.push_back(i*10);
	}
	printVector(v1);

	v1.pop_back();
	printVector(v1);

	v1.insert(v1.begin(), 100);
	printVector(v1);

	v1.insert(v1.begin(),2, 100);
	printVector(v1);

	v1.erase(v1.begin());
	printVector(v1);

	//v1.erase(v1.begin(),v1.end());
	v1.clear();
	printVector(v1);
}
//vector���ݴ�ȡ
void test19() {
	vector<int>v1;
	for (int i = 0; i <10; i++) {
		v1.push_back(i);
	}

	for (int i = 0; i <10; i++) {
		cout << v1[i] << " ";
	}
	cout << endl;

	for (int i = 0; i < 10; i++) {
		cout << v1.at(i) << " ";
	}
	cout << endl;

	cout << "��һ��Ԫ��Ϊ�� " << v1.front() << endl;
	cout << "���һ��Ԫ��Ϊ��" << v1.back() << endl;
}
//vector����
void test20() {
	vector<int>v1;
	for (int i = 0; i < 10; i++) {
		v1.push_back(i);
	}
	cout << "����ǰ��" << endl;
	printVector(v1);

	vector<int>v2;
	for (int i = 10; i > 0; i--) {
		v2.push_back(i);
	}
	printVector(v2);

	cout << "������" << endl;
	v1.swap(v2);
	printVector(v1);
	printVector(v2);
}
//ʵ��Ӧ��
void test21() {
	vector<int>v1;
	for (int i = 0; i < 100000; i++) {
		v1.push_back(i);
	}
	cout << "v������Ϊ��" <<v1.capacity()<< endl;
	cout << "v�Ĵ�СΪ��" << v1.size()<<endl;
	//printVector(v1);
	v1.resize(3);
	cout << "v������Ϊ��" << v1.capacity() << endl;
	cout << "v�Ĵ�СΪ��" << v1.size() << endl;

	//����swap�����ڴ�
	vector<int>(v1).swap(v1);//�����������󽻻�
	cout << "v������Ϊ��" << v1.capacity() << endl;
	cout << "v�Ĵ�СΪ��" << v1.size() << endl;
}
//vector���� Ԥ���ռ�
void test22() {
	vector<int>v1;

	//����reverseԤ���ռ�
	v1.reserve(100000);
	int num = 0;//ͳ�ƿ��ٴ���
	int* p = NULL;
	for (int i = 0; i < 100000; i++) {
		v1.push_back(i);
		if (p != &v1[0]) {
			p = &v1[0];
			num++;//30��
		}
	}

	cout << "num=  " << num << endl;

}
//deque���� ���캯��
void printDeque(const deque<int>& d) {//�޸�Ϊֻ��
	for (deque<int>::const_iterator it = d.begin(); it != d.end();it++) {
		//*it = 100;//�����е����ݲ������޸���
		cout<<*it<<" ";
	}
	cout << endl;
}
void test23() {
	deque<int>d1;
	for (int i = 0; i < 10; i++) {
		d1.push_back(i);
	}
	printDeque(d1);

	deque<int>d2(d1.begin(),d1.end());
	printDeque(d2);

	deque<int>d3(10,100);
	printDeque(d3);

	deque<int>d4(d3);
	printDeque(d4);

}
//deque������ֵ����
void test24() {
	deque<int>d1;
	for (int i = 0; i < 10; i++) {
		d1.push_back(i);
	}
	printDeque(d1);
	deque<int>d2;
	d2 = d1;
	printDeque(d2);

	deque<int>d3;
	d3.assign(d1.begin(), d1.end());
	printDeque(d3);

	deque<int>d4;
	d4.assign(10,100);
	printDeque(d4);
}
//deque��С����
void test25() {
	deque<int>d1;
	for (int i = 0; i < 10; i++) {
		d1.push_back(i);
	}
	printDeque(d1);

	if (d1.empty()) {
		cout << "d1Ϊ��" << endl;
	}
	else {
		cout << "d1��Ϊ��" << endl;
		cout << "d1�Ĵ�СΪ��" << d1.size() << endl;
	}

	//����ָ����С
	//d1.resize(15);
	d1.resize(15,1);
	printDeque(d1);

	d1.resize(5);
	printDeque(d1);
}
//deque�����ɾ��
//���˲���
void test26() {
	deque<int>d1;
	d1.push_back(10);
	d1.push_back(20);

	d1.push_front(100);
	d1.push_front(200);

	d1.pop_back();
	d1.pop_front();
	printDeque(d1);

}
//����
void test27() {
	deque<int>d1;
	d1.push_back(10);
	d1.push_back(20);
	d1.push_front(100);
	d1.push_front(200);
	d1.insert(d1.begin(), 1000);
	printDeque(d1);

	d1.insert(d1.begin(), 2,10000);
	printDeque(d1);

	deque<int>d2;
	d2.push_back(1);
	d2.push_back(2);
	d2.push_back(3);
	d1.insert(d1.begin(), d2.begin(),d2.end());
	printDeque(d1);
}
//ɾ��
void test28() {
	deque<int>d1;
	d1.push_back(10);
	d1.push_back(20);
	d1.push_front(100);
	d1.push_front(200);

	deque<int>::iterator it = d1.begin();
	it++;
	d1.erase(it);
	printDeque(d1);

	//d1.erase(d1.begin(), d1.end());
	d1.clear();
	printDeque(d1);
}
//deque���ݴ�ȡ
void test29() {
	deque<int>d1;
	d1.push_back(10);
	d1.push_back(20);
	d1.push_back(30);
	d1.push_front(100);
	d1.push_front(200);
	d1.push_front(300);
	for (int i = 0; i < d1.size(); i++) {
		cout << d1[i] << " ";
	}
	cout << endl;

	for (int i = 0; i < d1.size(); i++) {
		cout << d1.at(i) << " ";
	}
	cout << endl;

	cout << "��һ��Ԫ��Ϊ�� " << d1.front()<<endl;
	cout << "���һ��Ԫ��Ϊ�� " << d1.back() << endl;
}
//deque����
void test30() {
	deque<int>d1;
	d1.push_back(10);
	d1.push_back(20);
	d1.push_back(30);
	d1.push_front(100);
	d1.push_front(200);
	d1.push_front(300);
	printDeque(d1);
	sort(d1.begin(), d1.end());//��С����
	cout << "�����" << endl;
	printDeque(d1);

}
//STLʵ��
class person {
public:
	person(string name, int  score) {
		this->m_name = name;
		this->m_score = score;
	}
	string m_name;
	int m_score;
};
void creatperson(vector<person>&v) {
	string nameseed = "ABCDE";
	for (int i = 0; i < 5; i++) {
		string name = "ѡ��";
		name+=nameseed[i];

		int score = 0;
		person p(name, score);
		v.push_back(p);
	}
}
void setscore(vector<person>& v) {
	for (vector<person>::iterator it = v.begin(); it != v.end(); it++) {
		deque<int>d;
		for (int i = 0; i < 10; i++) {
			int score = rand()%40+60;
			d.push_back(score);
		}
		
		sort(d.begin(), d.end());
		d.pop_back();
		d.pop_front();

		int sum = 0;
		for (deque<int>::iterator dit = d.begin(); dit != d.end(); dit++) {
			sum =sum+ *dit;

		}
		int avg = sum / d.size();
		it->m_score = avg;
	}
}
void showscore(vector<person>& v) {
	for (vector<person>::iterator it = v.begin(); it != v.end(); it++) {
		cout << "������ " << it->m_name << "ƽ����" << it->m_score << endl;
	}
}
void test31() {
	srand((unsigned int)time(NULL));
	vector<person>v;
	creatperson(v);
	//for (vector<person>::iterator it = v.begin(); it != v.end(); it++) {
	//	cout << "����"<<(*it).m_name<<"����" << (*it).m_score << endl;
	//}
	setscore(v);
	showscore(v);
}
//stack����
void test32() {
	stack<int>s;
	s.push(10);
	s.push(20);
	s.push(30);
	s.push(40);
	cout << "ջ�Ĵ�СΪ��" << s.size() << endl;
	while (!s.empty()) {
		cout << "ջ��Ԫ��Ϊ��" << s.top()<<endl;
		s.pop();
	}
	cout << "ջ�Ĵ�СΪ��" << s.size() << endl;
}
//queue����
void test33() {
	queue<Person>q;
	Person p1("��ɮ",30);
	Person p2("�����",1000);
	Person p3("��˽�",900);
	Person p4("ɳɮ", 800);

	q.push(p1);
	q.push(p2);
	q.push(p3);
	q.push(p4);
	cout << "���д�СΪ�� " << q.size() << endl;
	while (!q.empty()) {
		cout << "��ͷԪ��---������" << q.front().m_name << "���䣺" << q.front().m_age << endl;
		cout << "��βԪ��---������" << q.back().m_name << "���䣺" << q.back().m_age << endl;
		q.pop();
	}
	cout << "���д�СΪ�� " << q.size() << endl;
}
//list����
void printList(const list<int>& l) {
	for (list<int>::const_iterator it = l.begin(); it != l.end(); it++) {
		cout << *it << " ";
	}
	cout <<endl;
}
//˫��ѭ������
void test34() {
	list<int>l1;
	l1.push_back(10);
	l1.push_back(20);
	l1.push_back(30);
	l1.push_back(40);
	printList(l1);
	list<int>l2(l1.begin(), l1.end());
	printList(l2);
	list<int>l3(l2);
	list<int>l4(10, 1000);
	printList(l4);

}
//list������ֵ�뽻��
void test35() {
	list<int>l1;
	l1.push_back(10);
	l1.push_back(20);
	l1.push_back(30);
	l1.push_back(40);
	printList(l1);
	list<int>l2;
	l2 = l1;
	printList(l2);

	list<int>l3;
	l3.assign(l2.begin(), l2.end());
	printList(l3);

	list<int>l4;
	l4.assign(10, 100);
	printList(l4);
}
void test36() {
	list<int>l1;
	l1.push_back(10);
	l1.push_back(20);
	l1.push_back(30);
	l1.push_back(40);

	list<int>l2;
	l2.assign(10, 100);

	cout << "����ǰ��" << endl;
	printList(l1);
	printList(l2);

	l1.swap(l2);

	cout << "������" << endl;
	printList(l1);
	printList(l2);
}
//list��С����
void test37() {
	list<int>l1;
	l1.push_back(10);
	l1.push_back(20);
	l1.push_back(30);
	l1.push_back(40);
	printList(l1);
	if (l1.empty()) {
		cout << "l1Ϊ��" << endl;
	}
	else {
		cout << "l1��Ϊ��" << endl;
		cout << "l1��Ԫ�ظ���Ϊ��" << l1.size() << endl;
	}
	l1.resize(10);//l1.resize(10,10000);
	printList(l1);

	l1.resize(2);
	printList(l1);
}
//list�����ɾ��
void test38() {
	list<int>l1;
	l1.push_back(10);
	l1.push_back(20);
	l1.push_back(30);
	l1.push_front(100);
	l1.push_front(200);
	l1.push_front(300);
	
	printList(l1);

	l1.pop_back();
	printList(l1);

	l1.pop_front();
	printList(l1);

	list<int>::iterator it = l1.begin();
	//l1.insert(l1.begin(), 1000);
	l1.insert(it++, 1000);
	printList(l1);

	it = l1.begin();
	l1.erase(it);
	printList(l1);

	l1.push_back(10000);
	l1.push_back(10000);
	l1.push_back(10000);
	printList(l1);
	l1.remove(10000);
	printList(l1);

	l1.clear();
	printList(l1);
}
//list���ݴ�ȡ
void test39() {
	list<int>l1;
	l1.push_back(10);
	l1.push_back(20);
	l1.push_back(30);
	l1.push_back(40);

	cout << "��һ��Ԫ��Ϊ��" << l1.front() << endl;
	cout << "���һ��Ԫ��Ϊ��" << l1.back() << endl;

	list<int>::iterator it = l1.begin();
	it++;
	it--;
}
//list��ת������
void test40() {
	list<int>l1;
	l1.push_back(10);
	l1.push_back(20);
	l1.push_back(30);
	l1.push_back(40);
	printList(l1);

	l1.reverse();
	printList(l1);
}
bool myCompare(int v1,int v2) {
	return v1 > v2;
}
void test41() {
	list<int>l1;
	l1.push_back(10);
	l1.push_back(30);
	l1.push_back(20);
	l1.push_back(40);
	printList(l1);

	//���в�֧��������ʵ��������������������ñ�׼�㷨���ڲ��ṩ�㷨
	l1.sort();
	printList(l1);

	l1.sort(myCompare);
	printList(l1);
}
//list������
class student {
public:
	student(string name, int age, int height) {
		this->m_name = name;
		this->m_age = age;
		this->m_height = height;
	}
	string m_name;
	int m_age;
	int m_height;

};
//ָ���������
bool comparestudent(student &p1,student &p2) {
	if (p1.m_age == p2.m_age) {
		return p1.m_height> p2.m_height;
	}
	return p1.m_age < p2.m_age;

}
void test42() {
	list<student>l1;
	student p1("����", 35, 175);
	student p2("�ܲ�", 45, 180);
	student p3("��Ȩ", 40, 170);
	student p4("����", 25, 190);
	student p5("�ŷ�", 35, 160);
	student p6("����", 35, 200);
	l1.push_back(p1);
	l1.push_back(p2);
	l1.push_back(p3);
	l1.push_back(p4);
	l1.push_back(p5);
	l1.push_back(p6);

	for (list<student>::iterator it = l1.begin(); it != l1.end(); it++) {
		cout << "������" << (*it).m_name << " ���䣺" << (*it).m_age << " ��ߣ�" << (*it).m_height << endl;
	}

	cout << "�����" << endl;
	l1.sort(comparestudent);
	for (list<student>::iterator it = l1.begin(); it != l1.end(); it++) {
		cout << "������" << (*it).m_name << " ���䣺" << (*it).m_age << " ��ߣ�" << (*it).m_height << endl;
	}
}
//set��������͸�ֵ
//������ʵ��
void printSet(set<int>& s) {
	for (set<int>::iterator it = s.begin(); it != s.end(); it++) {
		cout << *it << " ";
	}
	cout << endl;
}
void test43() {
	set<int>s1;
	s1.insert(10);
	s1.insert(40);
	s1.insert(30);
	s1.insert(20);
	s1.insert(30);
	//1������ʱ�Զ�������  2������������ظ�ֵ
	printSet(s1);

	set<int>s2(s1);
	printSet(s2);

	set<int>s3;
	s3 = s2;
	printSet(s2);
}
//set��С�ͽ���
void test44() {
	set<int>s1;
	s1.insert(10);
	s1.insert(30);
	s1.insert(20);
	s1.insert(40);

	printSet(s1);

	if (s1.empty()) {
		cout << "s1Ϊ��" << endl;
	}
	else {
		cout << "s1��Ϊ��" << endl;
		cout << "s1�Ĵ�СΪ��" << s1.size() << endl;
	}
	set<int>s2;
	s2.insert(100);
	s2.insert(300);
	s2.insert(200);
	s2.insert(400);

	cout << "����ǰ�� " << endl;
	printSet(s1);
	printSet(s2);

	cout << "������ " << endl;
	s1.swap(s2);
	printSet(s1);
	printSet(s2);

}
//set�����ɾ��
void test45() {
	set<int> s1;
	s1.insert(10);
	s1.insert(30);
	s1.insert(20);
	s1.insert(40);

	printSet(s1);

	s1.erase(s1.begin());
	printSet(s1);

	s1.erase(30);
	printSet(s1);

	//s1.erase(s1.begin(),s1.end());
	s1.clear();
	printSet(s1);
}
//set���Һ�ͳ��
void test46() {
	set<int> s1;
	s1.insert(10);
	s1.insert(30);
	s1.insert(20);
	s1.insert(40);
	set<int>::iterator pos = s1.find(30);
	if (pos != s1.end()) {
		cout << "�ҵ�Ԫ��" <<*pos<< endl;
	}
	else {
		cout << "δ�ҵ�Ԫ��" << endl;
	}

	int num = s1.count(30);
	cout << "num=" << num << endl;

}
//set��multiset����
void test47() {
	set<int>s1;
	pair<set<int>::iterator, bool>ret=s1.insert(10);
	if (ret.second) {
		cout << "��һ�β���ɹ�" << endl;
	}
	else {
		cout << "��һ�β���ʧ��" << endl;
	}

	ret=s1.insert(10);
	if (ret.second) {
		cout << "�ڶ��β���ɹ�" << endl;
	}
	else {
		cout << "�ڶ��β���ʧ��" << endl;
	}

	multiset<int>ms;
	//��������ظ�ֵ
	ms.insert(10);
	ms.insert(10);
	for (multiset<int>::iterator it = ms.begin(); it != ms.end(); it++) {
		cout << *it << " ";
	}
	cout << endl;
}
//pair���鴴��
void test48() {
	pair<string, int>p("Tom", 20);
	cout << "������ " << p.first << " ���䣺" << p.second << endl;

	pair<string, int>p2 = make_pair("Jerry", 30);
	cout << "������ " << p2.first << " ���䣺" << p2.second << endl;
}
//set��������
class MyCompare {
public:
	bool operator()(int v1,int v2)const {
		return v1 > v2;
	}
};
void test49() {
	set<int> s1;
	s1.insert(10);
	s1.insert(30);
	s1.insert(20);
	s1.insert(50);
	s1.insert(40);
	printSet(s1);
	//�Ӵ�С
	//���÷º���
	set<int,MyCompare> s2;
	s2.insert(10);
	s2.insert(30);
	s2.insert(20);
	s2.insert(50);
	s2.insert(40);
	for (set<int, MyCompare>::iterator it = s2.begin(); it != s2.end(); it++) {
		cout << *it << " ";
	}
	cout << endl;
}
//�Զ�����������set����
class human {
public:
	human(string name, int age) {
		this->m_age = age;
		this->m_name = name;
	}
	string m_name;
	int m_age;
};
class comparehuman {
public:
	bool operator()(const human& p1, const human& p2)const{
		return p1.m_age > p2.m_age;
	}
};
void test50() {
	set<human,comparehuman>s;
	//ָ������
	human p1("li", 24);
	human p2("liu", 28);
	human p3("liang",25);
	human p4("zhang", 21);
	s.insert(p1);
	s.insert(p2);
	s.insert(p3);
	s.insert(p4);

	for (set<human,comparehuman>::iterator it = s.begin(); it != s.end(); it++) {
		cout << "������"<<it->m_name<<" ���䣺"<<it->m_age << endl;
	}
}
//map����͸�ֵ
//������ʵ��
void printMap(map<int,int>&m) {
	for (map<int, int>::iterator it = m.begin(); it != m.end(); it++) {
		cout << "key" << (*it).first << " value=" << (*it).second << endl;
	}
	cout << endl;
}
void test51() {
	map<int, int> m;
	m.insert(pair<int, int>(1, 10));//����  ֵ
	m.insert(pair<int, int>(2, 20));
	m.insert(pair<int, int>(3, 30));
	m.insert(pair<int, int>(4, 40));
	printMap(m);

	map<int, int>m2(m);
	printMap(m2);

	map<int, int>m3;
	m3 = m2;
	printMap(m3);
}
//map��С�ͽ���
void test52() {
	map<int, int> m;
	m.insert(pair<int, int>(1, 10));//����  ֵ
	m.insert(pair<int, int>(2, 20));
	m.insert(pair<int, int>(3, 30));
	m.insert(pair<int, int>(4, 40));
	if (m.empty()) {
		cout << endl;
	}
	else {
		cout << "��Ϊ��" << endl;
		cout << "m�Ĵ�Сδ��" << m.size() << endl;
	}

	map<int, int> m2;
	m2.insert(pair<int, int>(5, 50));//����  ֵ
	m2.insert(pair<int, int>(6, 60));
	m2.insert(pair<int, int>(7, 70));
	m2.insert(pair<int, int>(8, 80));

	cout << "������" << endl;
	m.swap(m2);
	printMap(m);
	printMap(m2);
}
//map�����ɾ��
void test53() {
	map<int, int> m;
	m.insert(pair<int, int>(1, 10));//����  ֵ

	m.insert(make_pair(2, 20));

	m.insert(map<int, int>::value_type(3, 30));

	m[4] = 40;
	cout << m[5] << endl;
	printMap(m);

	m.erase(m.begin());
	printMap(m);

	m.erase(3);//����keyɾ��
	printMap(m);

	//m.erase(m.begin(), m.end());
	m.clear();
	printMap(m);
}
//map���Һ�ͳ��
void test54() {
	map<int, int> m;
	m.insert(pair<int, int>(1, 10));//����  ֵ
	m.insert(pair<int, int>(2, 20));
	m.insert(pair<int, int>(3, 30));
	
	map<int, int>::iterator pos = m.find(3);
	if (pos != m.end()) {
		cout << "�鵽��Ԫ��" << (*pos).first << "value=" << pos->second << endl;
	}
	else {
		cout << "δ�ҵ�" << endl;
	}
	int num = m.count(3);
	cout << "num=" << num <<endl;//map�������ظ�����

}
//map����
class MapCompare {
public:
	bool operator()(int v1, int v2)const {
		return v1 > v2;
	}
};
void test55() {
	map<int, int,MapCompare> m;
	m.insert(pair<int, int>(1, 10));//����  ֵ
	m.insert(pair<int, int>(2, 20));
	m.insert(pair<int, int>(3, 30));
	m.insert(pair<int, int>(4, 40));
	m.insert(pair<int, int>(5, 50));
	for (map<int, int,MapCompare>::iterator it = m.begin(); it != m.end(); it++) {
		cout << "key" << (*it).first << " value=" << (*it).second << endl;
	}
	cout << endl;
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
	//test14();
	//test15();
	//test16();
	//test17();
	//test18();
	//test19();
	//test20();
	//test21();
	//test22();
	//test23();
	//test24();
	//test25();
	//test26();
	//test27();
	//test28();
	//test29();
	//test30();
	//test31();
	//test32();
	//test33();
	//test34();
	//test35();
	//test36();
	//test37();
	//test38();
	//test39();
	//test40();
	//test41();
	//test42();
	//test43();
	//test44();
	//test45();
	//test46();
	//test47();
	//test48();
	//test49();
	//test50();
	//test51();
	//test52();
	//test53();
	//test54();
	test55();
	system("pause");
	return 0;
}