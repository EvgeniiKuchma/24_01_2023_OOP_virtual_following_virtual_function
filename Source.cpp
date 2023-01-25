#include <iostream>
#include <vector>
#include "Person.h"
//API Application Programming Interface
class IMovable {//абстрактный класс - все методы которого абстрактны
public:
	virtual void move() = 0;
	virtual int getSpeed() = 0; 
};
class IVehicale {//(IVehicale) интерфейс - это некий класс у которого не определены функции, 
	//у интерфейсов нет полей у С# и JavaScript / классы в С++ весят не меньше 1байта
public:
	virtual ~IVehicale() {
		std::cout << "Destructor work IVehicale" << std::endl;
	}
	virtual void printName() {
		std::cout << "IVehicale" << std::endl;
	}
	//чистый виртуальный метод
	virtual int getSpeed() = 0;//абстрактный метод которы должны реализовать потомки класса(еще одна подсказка что это интерфейс)после его создания мы не можем создавать обьекты интерфейса ---->>> IVehicale* a = new IVehicale();
};
class Car : public IVehicale {
public:
	Car(int speed) : _speed(speed) {}
	void printName() override {
		std::cout << "Car" << std::endl;
	}
	int getSpeed() override {
		return _speed;
	}
	~Car() {
		std::cout << "Destructor work Car" << std::endl;
	}
private:
	int _speed;
};
class Van : public Car {
public:
	Van(int speed) : Car(speed), _speed(speed) {}
	void printName() override {
		std::cout << "Van" << std::endl;
	}
	int getSpeed() override {
		return _speed;
	}
	~Van() {
		std::cout << "Destructor work Van" << std::endl;
	}
private:
	int _speed;
};
class HouseVan : public Van {
public:
	HouseVan(int speed) : Van(speed), _speed(speed) {}
	void printName() override {
		std::cout << "Van" << std::endl;
	}
	int getSpeed() override {
		return _speed;
	}
	~HouseVan() {
		std::cout << "Destructor work HouseVan" << std::endl;
	}
private:
	int _speed;
};
class Motocycle : public IVehicale {
public:
	Motocycle(int speed) : _speed(speed) {}
	void printName() override {
		std::cout << "Motocycle" << std::endl;
	}
	int getSpeed() override {
		return _speed;
	}
	~Motocycle() {
		std::cout << "Destructor work Motocycle" << std::endl;
	}
private:
	int _speed;
};
void printer(IVehicale* vehicle) {
	vehicle->printName();//(* vehicle).printName();
		std::cout << vehicle->getSpeed() << std::endl;
}
int main() 
{
	setlocale(LC_ALL, "Russian");
	//IVehicale* a = new IVehicale();
	IVehicale* b = new Car(50);
	IVehicale* c = new Motocycle(70);
	IVehicale* d = new Van(80);
	IVehicale* e = new HouseVan(90);
	std::vector<IVehicale*> vehicles;//складывание в 1 вектор дают приемущества динамического полиморфизма

	//vehicles.push_back(a);
	vehicles.push_back(b);
	vehicles.push_back(c);
	vehicles.push_back(d);
	vehicles.push_back(e);
	std::cout << "Traversing vehicles" << std::endl;
	////a -> b() == (*a).d(), vihecles[0] ==*a; a -> printName();1 я операция [i] взять по индексу затем указатель
	//}
	for (size_t i = 0; i < vehicles.size(); i++) {
		printer(vehicles[i]);
	}

	/*Person p("Alex");
	p.fight();*/

	IPerson* p = new Person("Alex");
	p->fight();

	delete b;
	delete c;
	delete d;
	delete e;
	delete p;

	//виды компиляторов MSVC, GCC(G++), Clang
	//text.cpp -> assembler -> native (binaric code)
	//стандарт компилятора это набор правил в результате которого не должно быть допущенно UB unfind behevior которому необходимо строго следовать
		return 0;
}