
/*
#include<iostream>
using namespace std;

//ֵ����
void myswap01(int a,int b) {
	int tmp = a;
	a = b;
	b = tmp;
	cout << "swap01 a= " << a << endl;
	cout << "swap01 b= " << b << endl;//�βθı���
}
//��ַ����
void myswap02(int *a, int *b) {
	int tmp = *a;
	*a = *b;
	*b = tmp;
}
//���ô���
void myswap03(int &a,int &b) {
	int tmp = a;
	a = b;
	b = tmp;
}

int& test01() {
	int a = 10;//�ֲ���������ջ��
	return a;
}
int& test02() {
	static int a = 10;//��̬���������ȫ�����������������ͷ�
	return a;
}

//���������ã�ת��Ϊ int const ref=&a;
void func(int& ref) {
	ref = 1000;//ref�����ã�ת��Ϊ*ref=100;
}

void showvalue(const int& val) {
	//val = 1000;//Ϊ�˷�ֵֹ���޸ģ�����Ҫ��const,�޸��Ժ�ᱨ����ʾ
	cout << "val= " << val << endl;
}

int main() {*/
	//���û����﷨
	/*
	int a = 10;
	int& b = a;
	cout <<"a= " << a << endl;
	cout <<"b= " << b << endl;

	b = 100;//�����ͬһ���ڴ�
	cout << "a= " << a << endl;
	cout << "b= " << b << endl;
	*/

	/*
	int a = 10;
	//���ñ����ʼ��
	//int &b;//����
	int& b = a;
	//�����ڳ�ʼ���󲻿��Ըı�
	int c = 20;
	b = c;//��ֵ�����������Ǹ�������,b��a�Բ���ͬһ���ڴ棬��ֵ�����˸ı�
	cout << "a= " << a << endl;
	cout << "b= " << b << endl;
	cout << "c= " << c << endl;
	*/

	/*
	int a = 10;
	int b = 20;
	myswap01(a,b);//ֵ���ݣ��ββ�������ʵ��
	cout << "a= " << a << endl;
	cout << "b= " << b << endl;//ʵ��û�з����ı�
	myswap02(&a, &b);//��ַ���ݣ��βλ�����ʵ��
	cout << "a= " << a << endl;
	cout << "b= " << b << endl;
	myswap03(a, b);//���ô��ݣ��βλ�����ʵ��
	cout << "a= " << a << endl;
	cout << "b= " << b << endl;//�ٴν���
*/

	/*
	//�����������ķ���ֵ
	//1����Ҫ���ؾֲ�����������
	int& ref = test01();
	cout << ref << endl;//x86,��һ����ȷ����Ϊ���������˱���
	cout << ref << endl;//�ڶ��δ�����Ϊa���ڴ��Ѿ��ͷ�
	cout << ref << endl;//��x86�᲻һ������x64��һ��
	//2�������ĵ���(����ֵ�����ã�������Ϊ��ֵ
	int ref2 = test02();
	cout <<"ref2= " << ref2 << endl;
	cout << "ref2= " << ref2 << endl;
	test02() = 1000;//��������ķ���ֵ�����ã�����������ÿ�����Ϊ��ֵ
	//ʵ���������޸ľ�̬����a��ֵ��������ref2����ˣ�ref2��ֵ���ֲ��䣬��Ȼ��֮ǰ��test02���ص�ֵ��
	ref2 = test02();
	//�ܽ�һ�£�C++�е�������Ϊ��������ֵʱ�����ص��Ƕ�ĳ��������ֱ�����ã������Ǳ����ĸ�����
	//��ˣ�ͨ��������öԱ������κ��޸Ķ���ֱ��Ӱ��ԭʼ������
	//���ǣ������������ø�ֵ����һ����������ô����µı���ֻ�Ǵ洢�����õ�ʱָ���ֵ���������Զ������Է�ӳԭʼ�����ĺ����仯��
	//cout << "ref2= " << ref2 << endl;
	//cout << "ref2= " << ref2 << endl;*/

	/*int a = 10;
	cout << "a: " << a << endl;
	//�Զ�ת��Ϊ int *const ref=&a;ָ�볣����ָ��ָ�򲻿ɸ��ģ�Ҳ˵��Ϊʲô���ò��ɸ���
	int& ref = a;//���õı�����һ��ָ�볣��
	ref = 20;//�ڲ�����ref�����ã��Զ�������ת��Ϊ��*ref=20;��������������

	cout << "a: " << a << endl;
	cout << "ref: " << ref << endl;

	func(a);
	cout << "a: " << a << endl;
	cout << "ref: " << ref << endl;*/

	/*
	//��������ʹ�ó��������������βΣ���ֹ�����
	//int a = 10;
	////int& ref = 10;//���ñ�����һ��Ϸ����ڴ�ռ�
	//const int& ref = 10;//�������������޸ģ�int tmp=10;const int&ref=tmp;
	//ref = 20;//����const�Ժ��Ϊֻ�����������޸�
	int a = 100;
	showvalue(a);
	*/
/*	system("pause");
	return 0;
}*/