/*
#include<iostream>
#include<string.h>
using namespace std;

class Animal {
public:
	//�麯��
	virtual void speak() {
		cout << "������˵��" << endl;
	}
};
class Cat :public Animal {
public://��д ��������ֵ ������ �����б� ��ȫ��ͬ
	virtual void speak() {
		cout << "Сè��˵��" << endl;
	}
};
//��ַ��󶨣��ڱ���׶�ȷ��������ַ
//�����ִ��è��˵������ô�����ַ�Ͳ�����ǰ�󶨣���Ҫ�����н׶ν��а󶨣���ַ���
//��̬��̬��������
//1���м̳й�ϵ
//2������Ҫ��д������麯��
//��̬��̬ʹ��
//�����ָ������� ָ���������
class Dog :public Animal {
public:
	
	void speak() {
		cout << "С����˵��" << endl;
	}
};
void dospeak(Animal& animal) {//Animal& animal
	animal.speak();
}
void test01() {
	Cat cat;
	dospeak(cat);

	Dog dog;
	dospeak(dog);
}
void test02() {
	cout << "size of Animal=" << sizeof(Animal) << endl;
}
//�ֱ�������ͨд���Ͷ�̬����ʵ�ּ�����
//��ͨд��
class Caculator {
public:
	int getResult(string oper) {
		if (oper == "+") {
			return m_num1 + m_num2;
		}
		else if (oper == "-") {
			return m_num1 - m_num2;
		}
		else if (oper == "*") {
			return m_num1 * m_num2;
		}
		//�������չ�¹��ܣ���Ҫ�޸�Դ��
		//����ʵ�����У��ᳫ ����ԭ��
		//����չ���п��ţ����޸Ľ��йر�

	}
	int m_num1;
	int m_num2;
};
void test03() {
	Caculator c;
	c.m_num1 = 10;
	c.m_num2 = 10;
	cout << c.m_num1 << "+" << c.m_num2 << "=" << c.getResult("+") << endl;
	cout << c.m_num1 << "-" << c.m_num2 << "=" << c.getResult("-") << endl;
	cout << c.m_num1 << "*" << c.m_num2 << "=" << c.getResult("*") << endl;
}
//���ö�̬ʵ�ּ�����
//��̬�ô�
// 1����֯�ṹ����
// 2���ɶ���ǿ
// 3������ǰ�ںͺ�����չά���Ը�
//ʵ�ּ�����������
class AbstractCaculator {
public:
	virtual int getResult() {
		return 0;
	}
	int m_num1;
	int m_num2;
};
class AddCaculator :public AbstractCaculator {
	int getResult() {
		return m_num1 + m_num2;
	}
};
class SubCaculator :public AbstractCaculator {
	int getResult() {
		return m_num1 - m_num2;
	}
};
class MulCaculator :public AbstractCaculator {
	int getResult() {
		return m_num1 * m_num2;
	}
};
void test04() {
	//��̬ʹ������
	//����ָ���������ָ���������

	AbstractCaculator* abc = new AddCaculator;
	abc->m_num1 = 10;
	abc->m_num2 = 10;

	cout << abc->m_num1 << "+" << abc->m_num2 << "=" << abc->getResult() << endl;
	//����ǵ�����
	delete abc;
	//����
	abc = new SubCaculator;
	abc->m_num1 = 10;
	abc->m_num2 = 10;

	cout << abc->m_num1 << "-" << abc->m_num2 << "=" << abc->getResult() << endl;
	delete abc;
	//�˷�
	abc = new MulCaculator;
	abc->m_num1 = 10;
	abc->m_num2 = 10;

	cout << abc->m_num1 << "*" << abc->m_num2 << "=" << abc->getResult() << endl;
}
class Base {
public:
	//���麯��
	//ֻҪ��һ�����麯����������Ϊ������
	//�ص㣺1���޷�ʵ��������
	//2������������� ����Ҫ��д����Ĵ��麯��������Ҳ���ڳ�����
	virtual void func() = 0;
};
class Son :public Base {
public:
	virtual void func() {
		cout << "func��������" << endl;
	};//��д
};
void tst01() {
	//Base b;//�������޷�ʵ��������
	//new Base;
	//Son s;//����������� ����Ҫ��д����Ĵ��麯��������Ҳ���ڳ�����
	Base* base = new Son;
	base->func();
}
//��̬����2��������Ʒ
class AbstractDrinking {
public:
	//��ˮ
	virtual void Boil() = 0;
	//����
	virtual void Brew() = 0;
	//���뱭��
	virtual void PourInCup() = 0;
	//���븨��
	virtual void AddSomething() = 0;
	//������Ʒ
	void makeDrink() {
		Boil();
		Brew();
		PourInCup();
		AddSomething();
	}
};
//��������
class Coffee :public AbstractDrinking {
public:
	//��ˮ
	virtual void Boil() {
		cout << "��ˮ" << endl;
	}
	//����
	virtual void Brew() {
		cout << "���ݿ���" << endl;
	}
	//���뱭��
	virtual void PourInCup() {
		cout << "���뱭��" << endl;
	}
	//���븨��
	virtual void AddSomething() {
		cout << "�����Ǻ�ţ��" << endl;
	}
};
//������Ҷ
class Tea :public AbstractDrinking {
public:
	//��ˮ
	virtual void Boil() {
		cout << "��ˮ" << endl;
	}
	//����
	virtual void Brew() {
		cout << "���ݲ�Ҷ" << endl;
	}
	//���뱭��
	virtual void PourInCup() {
		cout << "���뱭��" << endl;
	}
	//���븨��
	virtual void AddSomething() {
		cout << "�������" << endl;
	}
};
void dowork(AbstractDrinking* abs) {
	abs->makeDrink();
	delete abs;//�ͷ�
}
void tt01() {
	dowork(new Coffee);//AbstractDrinking* abs=new Coffee
	cout << "------------" << endl;
	dowork(new Tea);
}
//�������ʹ�������
class animal {
public:
	animal() {
		cout << "animal���캯������" << endl;
	}
	////�������������Խ�� ����ָ���ͷ��������ʱ���ɾ�������
	//virtual ~animal() {
	//	cout << "animal��������������" << endl;
	//}
	
	//��������	��Ҫ������Ҳ��Ҫʵ��
	//���˴�������֮�������Ҳ���ڳ����࣬�޷�ʵ��������
	virtual ~animal() = 0;
	//���麯��
	virtual void speak() = 0;
};
animal:: ~animal() {
	cout << "animal����������������" << endl;
}
class cat :public animal {
public://��д ��������ֵ ������ �����б� ��ȫ��ͬ
	cat(string name) {
		cout << "cat���캯������" << endl;
		m_name=new string(name);
	}
	virtual void speak() {
		cout << *m_name<<"Сè��˵��" << endl;
	}
	~cat() {
		if (m_name != NULL) {
			cout << "cat������������" << endl;
			delete m_name;
			m_name = NULL;
		}
	}
	string *m_name;
};
void tt02() {
	animal* animal1 = new cat("Tom");
	animal1->speak();
	//����ָ��������ʱ�� �����������������������������������ж������ԣ������ڴ�й©
	delete animal1;
}
//����CPU��
class CPU {
public:
	//����ļ��㺯��
	virtual void calculate() = 0;
};
//�����Կ���
class VideoCard {
public:
	//�������ʾ����
	virtual void display() = 0;
};
//�����ڴ�����
class Memory {
public:
	//����Ĵ洢����
	virtual void storage() = 0;
};
class Computer {
public:
	Computer(CPU* cpu, VideoCard* vc, Memory* mem) {
		m_cpu = cpu;
		m_vc = vc;
		m_mem = mem;
	}
	//�ṩ�����ĺ���
	void work() {
		//������������������ýӿ�
		m_cpu->calculate();
		m_vc->display();
		m_mem->storage();
	}
	//�ṩ�������� �ͷ�3���������
	~Computer() {
		if (m_cpu != NULL) {
			delete m_cpu;
			m_cpu = NULL;
		}
		if (m_vc != NULL) {
			delete m_vc;
			m_vc = NULL;
		}
		if (m_mem != NULL) {
			delete m_mem;
			m_mem = NULL;
		}
	}
private:
	CPU* m_cpu;
	VideoCard* m_vc;
	Memory* m_mem;
};
//���峧��
//Intel����
class IntelCPU :public CPU {
public:
	virtual void calculate() {
		cout << "Intel��CPU��ʼ�����ˣ�" << endl;
	}
};
class IntelVideoCard :public VideoCard {
public:
	virtual void display() {
		cout << "Intel���Կ���ʼ��ʾ�ˣ�" << endl;
	}
};
class IntelMemory :public Memory {
public:
	virtual void storage() {
		cout << "Intel���ڴ�����ʼ�洢�ˣ�" << endl;
	}
};
//Lenovo����
class LenovoCPU :public CPU {
public:
	virtual void calculate() {
		cout << "Lenovo��CPU��ʼ�����ˣ�" << endl;
	}
};
class LenovoVideoCard :public VideoCard {
public:
	virtual void display() {
		cout << "Lenovo���Կ���ʼ��ʾ�ˣ�" << endl;
	}
};
class LenovoMemory :public Memory {
public:
	virtual void storage() {
		cout << "Lenovo���ڴ�����ʼ�洢�ˣ�" << endl;
	}
};
void Test01() {
	//��һ̨�������
	cout << "��һ̨���Կ�ʼ������" << endl;
	CPU* intelCpu = new IntelCPU;
	VideoCard* intelCard = new IntelVideoCard;
	Memory* intelMem = new IntelMemory;
	//������һ̨����
	Computer* computer1 = new Computer(intelCpu, intelCard, intelMem);
	computer1->work();
	delete computer1;
	cout << "-------------------------" << endl;
	//�����ڶ�̨����
	cout << "�ڶ�̨���Կ�ʼ������" << endl;
	Computer* computer2 = new Computer(new LenovoCPU, new LenovoVideoCard, new LenovoMemory);
	computer2->work();
	delete computer2;
	cout << "-------------------------" << endl;
	//��������̨����
	cout << "����̨���Կ�ʼ������" << endl;
	Computer* computer3 = new Computer(new LenovoCPU, new IntelVideoCard, new LenovoMemory);
	computer3->work();
	delete computer3;
}
int main() {
	//test01();
	//test02();
	//test03();
	//test04();
	//tst01();
	//tt01();
	//tt02();
	Test01();
	system("pause");
	return 0;
}
*/