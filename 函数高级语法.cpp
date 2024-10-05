/*
#include<iostream>
using namespace std;
//函数默认参数
int fuc1(int a,int b=20,int c=30) {//没有传自己的数据，就用缺省参数
	return a + b + c;
}
//注意事项：1、如果某个位置已经有了默认参数，那么从这个位置往后，从左到右都必须有默认值
//int fuc2(int a, int b=10, int c,int d) {
//	return a + b + c;
//}
//2、如果函数声明有默认参数，函数实现就不能有默认参数
//声明和实现只能有一个有默认参数，二异性
//int fuc2(int a=10, int b=10);
// int fuc2(int a=20,int b=20) {
//	return a + b;
//}
//占位参数
void func(int a,int) {//第二个占位
	cout << "this is func " << endl;
}
//占位参数可以有默认参数
void func1(int a, int = 10) {

}
//函数重载
//可以让函数名相同，提高复用性
//1、同一作用域下
//2、函数名相同
//3、函数类型、个数、顺序不同
void funcc() {
	cout << "funcc的调用" << endl;
}
void funcc(int a) {
	cout << "funcc(int a)的调用!" << endl;
}
void funcc(double a) {
	cout << "funcc(double a)的调用!" << endl;
}
void funcc(int a,double b) {
	cout << "funcc(int a,double b)的调用!" << endl;
}
void funcc(double a,int b) {
	cout << "funcc(double a,int b)的调用!" << endl;
}
//注意事项：函数的返回值不可以作为函数重载的条件
//int funcc(double a, int b) {
//	cout << "funcc(double a,int b)的调用!" << endl;
//}

//函数重载的注意事项
//1、引用作为重载的条件
void fun(int& a) {
	cout << "fun(int &a)的调用" << endl;

}
void fun(const int& a) {
	cout << "fun(const int &a)的调用" << endl;

}

//2、函数重载碰到默认参数
//void fun2(int a,int b=10)//当函数重载碰到默认参数，出现二义性，报错，尽量避免这种情况
void fun2(int a, int b ) {
	cout << "fun2(int a,int b)的调用" << endl;

}
void fun2(int a) {
	cout << "fun2(int a)的调用" << endl;

}*/
/*
int main() {
	//cout << fuc1(10) << endl;//60
	//cout << fuc1(10,30) << endl;//70，传自己的数据
	//cout << fuc2(10, 10)<<endl;
	//func(10,10);
	//funcc(10);
	//funcc(3.14);
	//funcc(10, 3.14);
	//int a = 10;
	//fun(a);
	//fun(10);
	//fun2(10,20);
	system("pause");
	return 0;
}*/