#include "pch.h"
#include "Human.h"


Human::Human(std::string Name, int age) // конструктор по умолчанию с некоторыми данными, так же принимает данные
{
	this->Name = Name;
	this->age = age;
}

Human::~Human()
{
}

// сеттеры
void Human::set_age(int age)
{
	this->age = age;
}

void Human::set_Name(std::string Name)
{
	this->Name = Name;
}
