//自己的通用数组类
#pragma once
#include<iostream>
using namespace std;

template<class T>
class MyArray {
public:
	MyArray(int capacity) {
		//cout << "MyArray有参构造调用" << endl;
		this->m_Capacity = capacity;
		this->m_size = 0;
		this->pAddress = new T[this->m_Capacity];
	}
	//拷贝构造
	MyArray(const MyArray& arr) {
		//cout << "MyArray拷贝构造调用" << endl;
		this->m_Capacity = arr.m_Capacity;
		this->m_size = arr.m_size;
		this->pAddress = arr.pAddress;
		//深拷贝
		this->pAddress = new T[arr.m_Capacity];
		//将arr中的数据都拷贝过来
		for (int i = 0; i < this->m_size; i++) {
			this->pAddress[i] = arr.pAddress[i];
		}
	}
	//operator= 防止浅拷贝问题
	MyArray& operator=(const MyArray& arr) {
		//cout << "MyArray的operator=调用" << endl;
		//先判断原来堆区是否有数据，如果有先释放
		if (this->pAddress != NULL) {
			delete[] this->pAddress;
			this->pAddress = NULL;
			this->m_Capacity = 0;
			this->m_size = 0;
		}
		this->m_Capacity = arr.m_Capacity;
		this->m_size = arr.m_size;
		this->pAddress = new T[arr.m_Capacity];
		for (int i = 0; i < this->m_size; i++) {
			this->pAddress[i] = arr.pAddress[i];
		}
		return *this;
	}
	//尾插法
	void Push_Back(const T & val) {
		//判断容量满没有
		if (this->m_Capacity == this->m_size) {
			return;
		}
		this->pAddress[this->m_size] = val;
		this->m_size++;
	}
	//尾删法
	void Pop_Back() {
		if (this->m_size == 0) {
			return;
		}
		this->m_size--;
	}
	//通过下标方式访问数组中的元素
	T& operator[](int index) {
		return this->pAddress[index];
	}
	//返回数组容量
	int getCapacity() {
		return this->m_Capacity;
	}
	int getSize() {
		return this->m_size;
	}
	//返回数组大小
	~MyArray() {
		if (this->pAddress != NULL) {
			//cout << "MyArray析构函数调用" << endl;
			delete[] this->pAddress;
			this->pAddress=NULL;
		}
	}
private:
	T* pAddress;
	int m_Capacity;
	int m_size;
};