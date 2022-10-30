

//персональный шаблон проекта C++
#include<iostream>
#include <string>
#include <vector>//динамический массив

//статические поля и методы
class Fruit {
public:
	Fruit() {
		count_ += 1;
		std::cout << this << "fruit constructor" << "\n";
	}



	Fruit(const Fruit& obj):Fruit() {
		name_ = obj.name();
		
		//предварительный вызов конструктора
		//count_ += 1;//константная ссылка конструктора копирования
	}

	Fruit(std::string name) :Fruit() {
		name_ = name;
	
	}

	~Fruit() {
		count_-=1;
		std::cout << this << "fruit destructor" << "\n";
	}
	static int count() {
		return count_;
	}
	std::string name()const {
		return name_;
	}
	void name(std::string name) {
		name_= name;
	}
private:
	std::string name_;
	static int count_;
};

int Fruit::count_{ 0 };//такой принцип инициализации 

void F00() {
	Fruit a("pear");
	std::cout << a.count() << "\n"<<a.name()<<"\n";
}
void F01() {
	std::cout << Fruit::count() << "\n";
}
void F02(Fruit fruit) {
	std::cout << Fruit::count() << "\n" << fruit.name() << "\n";
}


Fruit* F03() {
	Fruit* result = new Fruit("pinneapple");//calling for constructor
	std::cout << Fruit::count() << "\n" << result->name() << "\n";//-> маркер для работы с указателями
	return result;
}
void Example();
int main() {
	setlocale(LC_ALL, "Russian");
	/*F01();
	Fruit a("apple");
	F02(a);
	std::cout << a.count() << "\n"<<a.name()<<"\n";
	F00();
	auto f_name = a.name();
	auto p_fruit1 = F03();
	auto p_fruit2 = F03();
	p_fruit1->name("qumqwat");
	std::cout << p_fruit1->count() << "\n" << p_fruit1->name() << "\n";
	delete p_fruit1;//calling for destructor
	F01();
	delete p_fruit2;
	F01();*/
	Example();
	return 0;
}

void Example() {
	std::vector<Fruit> name_array{
		std::string("apple"),
		std::string("pear"),
		std::string("pineapple")
	};
	name_array.reserve(10);
	name_array.push_back(Fruit("orange"));//создает временные объекты - медленно
	name_array.emplace_back(Fruit("pine"));//быстрее
	for (const auto& el : name_array) {
		std::cout << el.name() << "\n";

	}
	return;
	
}