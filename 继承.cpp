
/*
#include<iostream>
using namespace std;
//��ͨʵ��ҳ��
//javaҳ��
//class java {
//public:
//	void header() {
//		cout << "��ҳ�������Ρ���¼��ע��...(����ͷ��)" << endl;
//	}
//	void footer() {
//		cout << "�������ġ�����������վ�ڵ�ͼ...(�����ײ�)" << endl;
//	}
//	void left() {
//		cout << "java��python��c++...(���������б�)" << endl;
//	}
//	void content() {
//		cout << "javaѧ����Ƶ" << endl;
//	}
//};
//�̳�ʵ��ҳ��
//����ҳ����
class BasePage {
public:
	void header() {
		cout << "��ҳ�������Ρ���¼��ע��...(����ͷ��)" << endl;
	}
	void footer() {
		cout << "�������ġ�����������վ�ڵ�ͼ...(�����ײ�)" << endl;
	}
	void left() {
		cout << "Java��Python��C++...(���������б�)" << endl;
	}
};
//�̳еĺô��������ظ�����
//�﷨��class ����:  �̳з�ʽ  ����
//����Ҳ��������
//����Ҳ�л���
class Java :public BasePage {
public:
	void content() {
		cout << "Javaѧ����Ƶ" << endl;
	}
};
class Python :public BasePage {
public:
	void content() {
		cout << "Pythonѧ����Ƶ" << endl;
	}
};
class Cpp :public BasePage {
public:
	void content() {
		cout << "C++ѧ����Ƶ" << endl;
	}
};
void test01() {
	cout << "Java������Ƶҳ�����£�  " << endl;
	Java ja;
	ja.header();
	ja.footer();
	ja.left();
	ja.content();
	cout << "----------------------------" << endl;
	cout << "Python������Ƶҳ�����£�  " << endl;
	Python py;
	py.header();
	py.footer();
	py.left();
	py.content();
	cout << "----------------------------" << endl;
	cout << "C++������Ƶҳ�����£�  " << endl;
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
//�����̳�
class Son1 :public Base1 {
public:
	void func() {
		m_A = 10;//�����еĹ���Ȩ�޳�Ա ��������Ȼ�ǹ���Ȩ��
		m_B = 10;//�����еı���Ȩ�޳�Ա ��������Ȼ�Ǳ���Ȩ��
		//m_C = 10;//�����е�˽��Ȩ�޳�Ա ������ʲ���
	}
};
void test02() {
	Son1 s1;
	s1.m_A = 100;
	//s1.m_B = 100;//��son1���Ǳ���Ȩ�� ������ʲ���
}
//�����̳�
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
		m_A = 100;//�����еĹ���Ȩ�޳�Ա �������Ǳ���Ȩ��
		m_B = 100;//�����еı���Ȩ�޳�Ա �������Ǳ���Ȩ��
		//m_C = 100;//�����е�˽��Ȩ�޳�Ա ������ʲ���
	}
};
void test03() {
	Son2 s2;
	//s2.m_A = 100;//��son2���Ǳ���Ȩ�� ������ʲ���
	//s2.m_B = 100;//��son2���Ǳ���Ȩ�� ������ʲ���
}
//˽�м̳�
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
		m_A = 100;//�����еĹ���Ȩ�޳�Ա ��������˽��Ȩ��
		m_B = 100;//�����еı���Ȩ�޳�Ա ��������˽��Ȩ��
		//m_C = 100;//�����е�˽��Ȩ�޳�Ա ������ʲ���
	}
};
class GrandSon3 :public Son3 {
public:
	void func() {
		//m_A = 100;//��son3��m_A��Ϊ˽�У���ʹ�Ƕ���Ҳ���ʲ���
		//m_B = 100;//��son3��m_B��Ϊ˽�У���ʹ�Ƕ���Ҳ���ʲ���
	}
};
void test04() {
	Son3 s3;
	//s3.m_A = 100;//��son2����˽�г�Ա ������ʲ���
	//s3.m_B = 100;//��son2����˽�г�Ա ������ʲ���
}
//�̳��еĶ���ģ��
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
//���ÿ�����Ա������ʾ���߲鿴����ģ��
//��ת�̷� F��
//��ת�ļ�·�� cd ����·����
//�鿴����
//c1/dl reportSingleClassLayout���� �ļ���
void test05() {
	//���������ԷǾ�̬��Ա���Զ��ᱻ����̳���ȥ
	//������˽�г�Ա���� �Ǳ��������������ˣ�����Ƿ��ʲ���������ȷʵ���̳���ȥ��
	cout << "size of son=" << sizeof(Son) << endl;
}
//�̳��еĹ��������˳��
class base {
public:
	base() {
		cout << "base�Ĺ��캯����" << endl;
	}
	~base() {
		cout << "base������������" << endl;
	}
};
class son:public base {

public:
	son() {
		cout << "son�Ĺ��캯����" << endl;
	}
	~son() {
		cout << "son������������" << endl;
	}
};
void tst01() {
	//base b;
	//���죬�ȸ����ӣ��������Ӻ�
	son s;
}
//�̳���ͬ����Ա����
class base1 {
public:
	base1() {
		m_A = 100;
	}
	void func() {
		cout << "base1--func()����" << endl;
	}
	void func(int a) {
		cout << "base1--func(int a)����" << endl;
	}
	int m_A;
};
class son1 :public base1 {
public:
	son1() {
		m_A = 1000;
	}
	void func() {
		cout << "son1--func()����" << endl;
	}
	int m_A;
};
//ͬ����Ա���Դ���
void tst02() {
	son1 s;
	cout << "son1��m_A=" << s.m_A << endl;
	cout << "base1��m_A=" << s.base1::m_A << endl;//���ͨ��������� ���ʵ�������ͬ����Ա����Ҫ��������
}
//ͬ����Ա��������
void tst03() {
	son1 s;
	s.func();//ֱ�ӵ��������ͬ����Ա����
	s.base1::func();
	//��������г��ֺ͸���ͬ���ĳ�Ա�����������ͬ����Ա���������ص�����������ͬ����Ա����
	//�������ʵ������б����ص�ͬ����Ա��������Ҫ��������
	s.base1::func(100);
}
//�̳��е�ͬ����̬��Ա����ʽ
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
 //ͬ����̬��Ա����
 void tt01() {
	 //1��ͨ���������
	 cout << "ͨ��������ʣ� " <<  endl;
	 sonn s;
	 cout << "sonn�µ�m_A=" << s.m_A << endl;
	 cout << "base2�µ�m_A=" << s.base2::m_A << endl;
	//2��ͨ����������
	 cout << "ͨ���������ʣ� " << endl;
	 cout << "sonn�µ�m_A=" << sonn:: m_A << endl;
	 cout << "base2�µ�m_A=" << sonn::base2::m_A << endl;
	 //��һ��::����������ʽ���� �ڶ���::��������������
 }
 //ͬ����̬��Ա����
 void tt02() {
	 //1��ͨ���������
	 cout << "ͨ���������" << endl;
	 sonn s;
	 s.func();
	 s.base2::func();
	 //ͨ����������
	 cout << "ͨ����������" << endl;
	 sonn::func();
	 sonn::base2::func();
 }
 //��̳��﷨
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
 //����̳�bse1��bse2
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
	 //�������г���ͬ����Ա����Ҫ������������
	 cout << "bse1::m_A=" << s.bse1::m_A << endl;
	 cout << "bse2::m_A=" << s.bse2::m_A << endl;
 }
 //���μ̳�
 //������
 class animal {//�����
 public:
	 int m_age;
 };
 //������̳н�����μ̳�����

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
	 //�����μ̳У�������������ͬ���ݣ���Ҫ��������������
	 cout << "st.sheep::m_age=" << st.sheep::m_age << endl;
	 cout << "st.tuo::m_age=" << st.tuo::m_age << endl;
	 cout << "st.m_age=" << st.m_age << endl;
	 //�������ֻҪ��һ�ݾͿ��ԣ����μ̳е������������ݣ���Դ�˷�
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