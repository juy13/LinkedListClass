// LinkedList.cpp : This file contains the 'main' function. Program execution begins and ends there.
//

#include "pch.h"
#include "LinkedListClass.h"
#include <iostream>
#include "Human.h"



int main()
{
	LinkedListClass<int> a;
	a.addelem(3);
	a.addelem(4);
	a.addelem(7);
	a.addelem(5);
	a.printList();
	a.deletelem(0);
	std::cout << "IIIIIIIIIIIIIIIIIIIIIIIIII" << std::endl;
	a.printList();
	try
	{
		a.deletelem(5);
	}
	catch (const std::exception& ex)
	{
		std::cout << ex.what() << std::endl;
	}
	std::cout << "IIIIIIIIIIIIIIIIIIIIIIIIII" << std::endl;
	a.printList();
	a.deletelem(0);
	std::cout << "IIIIIIIIIIIIIIIIIIIIIIIIII" << std::endl;
	a.printList();
	try
	{
		a.deletelem(2);
	}
	catch (const std::exception& ex)
	{
		std::cout << ex.what() << std::endl;
	}
	std::cout << "IIIIIIIIIIIIIIIIIIIIIIIIII" << std::endl;
	a.printList();

	Human b1("Peter", 32);
	Human b2("Ivan", 4);
	Human b3("Sofia", 8);
	Human b4("Mia", 12);
	Human b5("Dima", 23);
	Human b6("Tim", 55);
	Human b7("Tonya", 70);
	Human b8("Jack", 1);
	LinkedListClass<Human> a2;

	a2.addelem(b1);
	a2.addelem(b2);
	a2.addelem(b3);
	a2.addelem(b4);
	a2.addelem(b5);
	a2.addelem(b6);
	a2.addelem(b7);
	a2.addelem(b8);
	a2.printList();
	std::cout << "IIIIIIIIIIIIIIIIIIIIIIIIII" << std::endl;
	try
	{
		a2.deletelem(-4);
	}
	catch (const std::exception& ex)
	{
		std::cout << ex.what() << std::endl;
	}
	a2.deletelem(4);
	a2.printList();
	std::cout << "IIIIIIIIIIIIIIIIIIIIIIIIII" << std::endl;
	a2.deletelem(1);
	a2.printList();


}

// Run program: Ctrl + F5 or Debug > Start Without Debugging menu
// Debug program: F5 or Debug > Start Debugging menu

// Tips for Getting Started: 
//   1. Use the Solution Explorer window to add/manage files
//   2. Use the Team Explorer window to connect to source control
//   3. Use the Output window to see build output and other messages
//   4. Use the Error List window to view errors
//   5. Go to Project > Add New Item to create new code files, or Project > Add Existing Item to add existing code files to the project
//   6. In the future, to open this project again, go to File > Open > Project and select the .sln file
