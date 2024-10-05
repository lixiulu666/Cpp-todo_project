/*
#include<iostream>
using namespace std;

//new的基本语法
int* func() {
	//在堆区创建整型数据
	//new返回的是 该数据类型的指针
	int *p = new int(10);
	return p;
}

void test01() {
	int* p = func();
	cout << *p << endl;
	cout << *p << endl;
	cout << *p << endl;
	//堆区的数据，由管理员开辟和释放
	delete p;
	//cout << *p << endl;//内存已被释放，再次访问就是非法操作会报错
}
//在堆区开辟数组
void test02() {
	int *arr=new int[10];

	for (int i = 0; i < 10; i++) {
		arr[i] = i + 100;
	}
	for (int i = 0; i < 10; i++) {
		cout << arr[i] << endl;
	}
	//释放
	delete[] arr;

}
int main() {
	test01();
	test02();
	system("pause");
	

	return 0;
}
*/