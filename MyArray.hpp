//�Լ���ͨ��������
#pragma once
#include<iostream>
using namespace std;

template<class T>
class MyArray {
public:
	MyArray(int capacity) {
		//cout << "MyArray�вι������" << endl;
		this->m_Capacity = capacity;
		this->m_size = 0;
		this->pAddress = new T[this->m_Capacity];
	}
	//��������
	MyArray(const MyArray& arr) {
		//cout << "MyArray�����������" << endl;
		this->m_Capacity = arr.m_Capacity;
		this->m_size = arr.m_size;
		this->pAddress = arr.pAddress;
		//���
		this->pAddress = new T[arr.m_Capacity];
		//��arr�е����ݶ���������
		for (int i = 0; i < this->m_size; i++) {
			this->pAddress[i] = arr.pAddress[i];
		}
	}
	//operator= ��ֹǳ��������
	MyArray& operator=(const MyArray& arr) {
		//cout << "MyArray��operator=����" << endl;
		//���ж�ԭ�������Ƿ������ݣ���������ͷ�
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
	//β�巨
	void Push_Back(const T & val) {
		//�ж�������û��
		if (this->m_Capacity == this->m_size) {
			return;
		}
		this->pAddress[this->m_size] = val;
		this->m_size++;
	}
	//βɾ��
	void Pop_Back() {
		if (this->m_size == 0) {
			return;
		}
		this->m_size--;
	}
	//ͨ���±귽ʽ���������е�Ԫ��
	T& operator[](int index) {
		return this->pAddress[index];
	}
	//������������
	int getCapacity() {
		return this->m_Capacity;
	}
	int getSize() {
		return this->m_size;
	}
	//���������С
	~MyArray() {
		if (this->pAddress != NULL) {
			//cout << "MyArray������������" << endl;
			delete[] this->pAddress;
			this->pAddress=NULL;
		}
	}
private:
	T* pAddress;
	int m_Capacity;
	int m_size;
};