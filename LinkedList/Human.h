#pragma once
#include <string>
#include <sstream>
#include <iostream>

class Human
{
private:
	std::string Name;
	int age;

public:
	Human(std::string Name = "Unknown", int age = 0);
	~Human();

	void set_age(int age);
	void set_Name(std::string Name);

	friend std::ostream& operator<< (std::ostream &out, const Human &hm)// перегруженный оператор вывода
	{																	// 
		out << "Name: " << hm.Name << ", age: " << hm.age;				// 
																		// 
		return out;
	}

	friend bool operator>(const Human &lft, const Human &rgt);
	friend bool operator<(const Human &lft, const Human &rgt);
};

