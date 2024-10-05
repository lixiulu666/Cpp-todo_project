
/*
#include<iostream>
using namespace std;

//值传递
void myswap01(int a,int b) {
	int tmp = a;
	a = b;
	b = tmp;
	cout << "swap01 a= " << a << endl;
	cout << "swap01 b= " << b << endl;//形参改变了
}
//地址传递
void myswap02(int *a, int *b) {
	int tmp = *a;
	*a = *b;
	*b = tmp;
}
//引用传递
void myswap03(int &a,int &b) {
	int tmp = a;
	a = b;
	b = tmp;
}

int& test01() {
	int a = 10;//局部变量放在栈区
	return a;
}
int& test02() {
	static int a = 10;//静态变量存放在全局区，程序结束后才释放
	return a;
}

//发现是引用，转换为 int const ref=&a;
void func(int& ref) {
	ref = 1000;//ref是引用，转换为*ref=100;
}

void showvalue(const int& val) {
	//val = 1000;//为了防止值误被修改，上面要加const,修改以后会报错提示
	cout << "val= " << val << endl;
}

int main() {*/
	//引用基本语法
	/*
	int a = 10;
	int& b = a;
	cout <<"a= " << a << endl;
	cout <<"b= " << b << endl;

	b = 100;//会操纵同一块内存
	cout << "a= " << a << endl;
	cout << "b= " << b << endl;
	*/

	/*
	int a = 10;
	//引用必须初始化
	//int &b;//错误
	int& b = a;
	//引用在初始化后不可以改变
	int c = 20;
	b = c;//赋值操作，而不是更改引用,b和a仍操作同一块内存，但值发生了改变
	cout << "a= " << a << endl;
	cout << "b= " << b << endl;
	cout << "c= " << c << endl;
	*/

	/*
	int a = 10;
	int b = 20;
	myswap01(a,b);//值传递，形参不会修饰实参
	cout << "a= " << a << endl;
	cout << "b= " << b << endl;//实参没有发生改变
	myswap02(&a, &b);//地址传递，形参会修饰实参
	cout << "a= " << a << endl;
	cout << "b= " << b << endl;
	myswap03(a, b);//引用传递，形参会修饰实参
	cout << "a= " << a << endl;
	cout << "b= " << b << endl;//再次交换
*/

	/*
	//引用作函数的返回值
	//1、不要返回局部变量的引用
	int& ref = test01();
	cout << ref << endl;//x86,第一次正确，因为编译器做了保留
	cout << ref << endl;//第二次错误，因为a的内存已经释放
	cout << ref << endl;//用x86会不一样，用x64会一样
	//2、函数的调用(返回值是引用）可以作为左值
	int ref2 = test02();
	cout <<"ref2= " << ref2 << endl;
	cout << "ref2= " << ref2 << endl;
	test02() = 1000;//如果函数的返回值是引用，这个函数调用可以作为左值
	//实际上是在修改静态变量a的值，而不是ref2。因此，ref2的值保持不变，仍然是之前从test02返回的值。
	ref2 = test02();
	//总结一下，C++中的引用作为函数返回值时，返回的是对某个变量的直接引用，而不是变量的副本。
	//因此，通过这个引用对变量的任何修改都会直接影响原始变量。
	//但是，如果将这个引用赋值给另一个变量，那么这个新的变量只是存储了引用当时指向的值，它不会自动更新以反映原始变量的后续变化。
	//cout << "ref2= " << ref2 << endl;
	//cout << "ref2= " << ref2 << endl;*/

	/*int a = 10;
	cout << "a: " << a << endl;
	//自动转换为 int *const ref=&a;指针常量是指针指向不可更改，也说明为什么引用不可更改
	int& ref = a;//引用的本质是一个指针常量
	ref = 20;//内部发现ref是引用，自动帮我们转换为：*ref=20;编译器帮我们做

	cout << "a: " << a << endl;
	cout << "ref: " << ref << endl;

	func(a);
	cout << "a: " << a << endl;
	cout << "ref: " << ref << endl;*/

	/*
	//常量引用使用场景：用来修饰形参，防止误操作
	//int a = 10;
	////int& ref = 10;//引用必须引一块合法的内存空间
	//const int& ref = 10;//编译器将代码修改，int tmp=10;const int&ref=tmp;
	//ref = 20;//加入const以后变为只读，不可以修改
	int a = 100;
	showvalue(a);
	*/
/*	system("pause");
	return 0;
}*/