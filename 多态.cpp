/*
#include<iostream>
#include<string.h>
using namespace std;

class Animal {
public:
	//虚函数
	virtual void speak() {
		cout << "动物在说话" << endl;
	}
};
class Cat :public Animal {
public://重写 函数返回值 函数名 参数列表 完全相同
	virtual void speak() {
		cout << "小猫在说话" << endl;
	}
};
//地址早绑定，在编译阶段确定函数地址
//如果想执行猫在说话，那么这个地址就不能提前绑定，需要在运行阶段进行绑定，地址晚绑定
//动态多态满足条件
//1、有继承关系
//2、子类要重写父类的虚函数
//动态多态使用
//父类的指针或引用 指向子类对象
class Dog :public Animal {
public:
	
	void speak() {
		cout << "小狗在说话" << endl;
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
//分别利用普通写法和多态技术实现计算器
//普通写法
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
		//如果想扩展新功能，需要修改源码
		//在真实开发中，提倡 开闭原则
		//对扩展进行开放，对修改进行关闭

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
//利用多态实现计算器
//多态好处
// 1、组织结构清晰
// 2、可读性强
// 3、对于前期和后期扩展维护性高
//实现计算器抽象类
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
	//多态使用条件
	//父类指针或者引用指向子类对象

	AbstractCaculator* abc = new AddCaculator;
	abc->m_num1 = 10;
	abc->m_num2 = 10;

	cout << abc->m_num1 << "+" << abc->m_num2 << "=" << abc->getResult() << endl;
	//用完记得销毁
	delete abc;
	//减法
	abc = new SubCaculator;
	abc->m_num1 = 10;
	abc->m_num2 = 10;

	cout << abc->m_num1 << "-" << abc->m_num2 << "=" << abc->getResult() << endl;
	delete abc;
	//乘法
	abc = new MulCaculator;
	abc->m_num1 = 10;
	abc->m_num2 = 10;

	cout << abc->m_num1 << "*" << abc->m_num2 << "=" << abc->getResult() << endl;
}
class Base {
public:
	//纯虚函数
	//只要有一个纯虚函数，这个类称为抽象类
	//特点：1、无法实例化对象
	//2、抽象类的子类 必须要重写父类的纯虚函数，否则也属于抽象类
	virtual void func() = 0;
};
class Son :public Base {
public:
	virtual void func() {
		cout << "func函数调用" << endl;
	};//重写
};
void tst01() {
	//Base b;//抽象类无法实例化对象
	//new Base;
	//Son s;//抽象类的子类 必须要重写父类的纯虚函数，否则也属于抽象类
	Base* base = new Son;
	base->func();
}
//多态案例2，制作饮品
class AbstractDrinking {
public:
	//煮水
	virtual void Boil() = 0;
	//冲泡
	virtual void Brew() = 0;
	//倒入杯中
	virtual void PourInCup() = 0;
	//加入辅料
	virtual void AddSomething() = 0;
	//制作饮品
	void makeDrink() {
		Boil();
		Brew();
		PourInCup();
		AddSomething();
	}
};
//制作咖啡
class Coffee :public AbstractDrinking {
public:
	//煮水
	virtual void Boil() {
		cout << "煮水" << endl;
	}
	//冲泡
	virtual void Brew() {
		cout << "冲泡咖啡" << endl;
	}
	//倒入杯中
	virtual void PourInCup() {
		cout << "倒入杯中" << endl;
	}
	//加入辅料
	virtual void AddSomething() {
		cout << "加入糖和牛奶" << endl;
	}
};
//制作茶叶
class Tea :public AbstractDrinking {
public:
	//煮水
	virtual void Boil() {
		cout << "煮开水" << endl;
	}
	//冲泡
	virtual void Brew() {
		cout << "冲泡茶叶" << endl;
	}
	//倒入杯中
	virtual void PourInCup() {
		cout << "倒入杯中" << endl;
	}
	//加入辅料
	virtual void AddSomething() {
		cout << "加入枸杞" << endl;
	}
};
void dowork(AbstractDrinking* abs) {
	abs->makeDrink();
	delete abs;//释放
}
void tt01() {
	dowork(new Coffee);//AbstractDrinking* abs=new Coffee
	cout << "------------" << endl;
	dowork(new Tea);
}
//虚析构和纯虚析构
class animal {
public:
	animal() {
		cout << "animal构造函数调用" << endl;
	}
	////利用虚析构可以解决 父类指针释放子类对象时不干净的问题
	//virtual ~animal() {
	//	cout << "animal虚析构函数调用" << endl;
	//}
	
	//纯虚析构	需要声明，也需要实现
	//有了纯虚析构之后，这个类也属于抽象类，无法实例化对象
	virtual ~animal() = 0;
	//纯虚函数
	virtual void speak() = 0;
};
animal:: ~animal() {
	cout << "animal纯虚析构函数调用" << endl;
}
class cat :public animal {
public://重写 函数返回值 函数名 参数列表 完全相同
	cat(string name) {
		cout << "cat构造函数调用" << endl;
		m_name=new string(name);
	}
	virtual void speak() {
		cout << *m_name<<"小猫在说话" << endl;
	}
	~cat() {
		if (m_name != NULL) {
			cout << "cat析构函数调用" << endl;
			delete m_name;
			m_name = NULL;
		}
	}
	string *m_name;
};
void tt02() {
	animal* animal1 = new cat("Tom");
	animal1->speak();
	//父类指针在析构时候 不会调用子类中析构函数，导致子类如果有堆区属性，出现内存泄漏
	delete animal1;
}
//抽象CPU类
class CPU {
public:
	//抽象的计算函数
	virtual void calculate() = 0;
};
//抽象显卡类
class VideoCard {
public:
	//抽象的显示函数
	virtual void display() = 0;
};
//抽象内存条类
class Memory {
public:
	//抽象的存储函数
	virtual void storage() = 0;
};
class Computer {
public:
	Computer(CPU* cpu, VideoCard* vc, Memory* mem) {
		m_cpu = cpu;
		m_vc = vc;
		m_mem = mem;
	}
	//提供工作的函数
	void work() {
		//让零件工作起来，调用接口
		m_cpu->calculate();
		m_vc->display();
		m_mem->storage();
	}
	//提供析构函数 释放3个电脑零件
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
//具体厂商
//Intel厂商
class IntelCPU :public CPU {
public:
	virtual void calculate() {
		cout << "Intel的CPU开始计算了！" << endl;
	}
};
class IntelVideoCard :public VideoCard {
public:
	virtual void display() {
		cout << "Intel的显卡开始显示了！" << endl;
	}
};
class IntelMemory :public Memory {
public:
	virtual void storage() {
		cout << "Intel的内存条开始存储了！" << endl;
	}
};
//Lenovo厂商
class LenovoCPU :public CPU {
public:
	virtual void calculate() {
		cout << "Lenovo的CPU开始计算了！" << endl;
	}
};
class LenovoVideoCard :public VideoCard {
public:
	virtual void display() {
		cout << "Lenovo的显卡开始显示了！" << endl;
	}
};
class LenovoMemory :public Memory {
public:
	virtual void storage() {
		cout << "Lenovo的内存条开始存储了！" << endl;
	}
};
void Test01() {
	//第一台电脑零件
	cout << "第一台电脑开始工作：" << endl;
	CPU* intelCpu = new IntelCPU;
	VideoCard* intelCard = new IntelVideoCard;
	Memory* intelMem = new IntelMemory;
	//创建第一台电脑
	Computer* computer1 = new Computer(intelCpu, intelCard, intelMem);
	computer1->work();
	delete computer1;
	cout << "-------------------------" << endl;
	//创建第二台电脑
	cout << "第二台电脑开始工作：" << endl;
	Computer* computer2 = new Computer(new LenovoCPU, new LenovoVideoCard, new LenovoMemory);
	computer2->work();
	delete computer2;
	cout << "-------------------------" << endl;
	//创建第三台电脑
	cout << "第三台电脑开始工作：" << endl;
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