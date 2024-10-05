#pragma once
#include<iostream>
using namespace std;
#include<string>

template<class T1, class T2>
class Pperson {
public:

	Pperson(T1 name, T2 age);
	void showPpeople();
	T1 m_name;
	T2 m_age;
};
template<class T1, class T2>
Pperson<T1, T2>::Pperson(T1 name, T2 age) {
	this->m_name = name;
	this->m_age = age;
}
template<class T1, class T2>
void Pperson<T1, T2>::showPpeople() {
	cout << "ÐÕÃû£º" << this->m_name << " ÄêÁä£º" << this->m_age << endl;
}
