/*
#include<iostream>
using namespace std;

//new�Ļ����﷨
int* func() {
	//�ڶ���������������
	//new���ص��� ���������͵�ָ��
	int *p = new int(10);
	return p;
}

void test01() {
	int* p = func();
	cout << *p << endl;
	cout << *p << endl;
	cout << *p << endl;
	//���������ݣ��ɹ���Ա���ٺ��ͷ�
	delete p;
	//cout << *p << endl;//�ڴ��ѱ��ͷţ��ٴη��ʾ��ǷǷ������ᱨ��
}
//�ڶ�����������
void test02() {
	int *arr=new int[10];

	for (int i = 0; i < 10; i++) {
		arr[i] = i + 100;
	}
	for (int i = 0; i < 10; i++) {
		cout << arr[i] << endl;
	}
	//�ͷ�
	delete[] arr;

}
int main() {
	test01();
	test02();
	system("pause");
	

	return 0;
}
*/