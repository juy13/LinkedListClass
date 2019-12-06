// LinkedList.cpp : This file contains the 'main' function. Program execution begins and ends there.
//

#include "pch.h"
#include "LinkedListClass.h"
#include "ISorter.h"
#include <iostream>
#include "Human.h"
#include <time.h> 

void testing_sorts()
{
	std::cout << "Starting tests of sorting methods" << std::endl;
	time_t start, end;
	ISorter B;
	LinkedListClass<int> a;
	for (int i = 0; i < 10000; i++)
	{
		a.addelem(rand() % 50 - rand() % 50);
	}
	std::cout << "Testing bublesort on 10000 elements" << std::endl;
	time(&start);
	B.bubleSort(a, a.getLength(), [](LinkedListClass<int> &a, int i, int j) -> bool
	{
		if (a[i] < a[j])
			return true;
		else
			return false;
	});
	time(&end);
	double seconds = difftime(end, start);
	std::cout << "The time: " << seconds << " seconds" << std::endl;
	LinkedListClass<int> b;
	std::cout << "Testing insert_sort on 10000 elements" << std::endl;
	for (int i = 0; i < 10000; i++)
	{
		b.addelem(rand() % 50 - rand() % 50);
	}
	time(&start);
	B.insert_sort(b, b.getLength(), [](LinkedListClass<int> &a, int i, int j) -> bool
	{
		if (a[i] < a[j])
			return true;
		else
			return false;
	});
	time(&end);
	seconds = difftime(end, start);
	std::cout << "The time: " << seconds << " seconds" << std::endl;

	LinkedListClass<int> a1;
	for (int i = 0; i < 25000; i++)
	{
		a1.addelem(rand() % 50 - rand() % 50);
	}
	std::cout << "Testing bubleSort on 25000 elements" << std::endl;
	time(&start);
	B.bubleSort(a1, a1.getLength(), [](LinkedListClass<int> &a, int i, int j) -> bool
	{
		if (a[i] < a[j])
			return true;
		else
			return false;
	}); // (a1, a1.getLength(), a1.is_smaller);
	time(&end);
	seconds = difftime(end, start);
	std::cout << "The time: " << seconds << " seconds" << std::endl;
	std::cout << "Testing insert_sort on 25000 elements" << std::endl;
	LinkedListClass<int> b1;
	for (int i = 0; i < 25000; i++)
	{
		b1.addelem(rand() % 50 - rand() % 50);
	}
	time(&start);
	B.insert_sort(b1, b1.getLength(), [](LinkedListClass<int> &a, int i, int j) -> bool
	{
		if (a[i] < a[j])
			return true;
		else
			return false;
	});
	time(&end);
	seconds = difftime(end, start);
	std::cout << "The time: " << seconds << " seconds" << std::endl;

	std::cout << "Testing bubleSort on 50000 elements" << std::endl;
	LinkedListClass<int> a2;
	for (int i = 0; i < 50000; i++)
	{
		a2.addelem(rand() % 50 - rand() % 50);
	}
	time(&start);
	B.bubleSort(a2, a2.getLength(), [](LinkedListClass<int> &a, int i, int j) -> bool
	{
		if (a[i] < a[j])
			return true;
		else
			return false;
	});
	time(&end);
	seconds = difftime(end, start);
	std::cout << "The time: " << seconds << " seconds" << std::endl;
	std::cout << "Testing insert_sort on 50000 elements" << std::endl;
	LinkedListClass<int> b2;
	for (int i = 0; i < 50000; i++)
	{
		b2.addelem(rand() % 50 - rand() % 50);
	}
	time(&start);
	B.insert_sort(b2, b2.getLength(), [](LinkedListClass<int> &a, int i, int j) -> bool
	{
		if (a[i] < a[j])
			return true;
		else
			return false;
	});
	time(&end);
	seconds = difftime(end, start);
	std::cout << "The time: " << seconds << " seconds" << std::endl;
}


//template<typename TElement>
int main()
{
	testing_sorts();
	ISorter B;
	LinkedListClass<int> a;
	a.addelem(-3);
	a.addelem(100);
	a.addelem(4);
	a.addelem(37);
	a.addelem(25);
	B.insert_sort(a, a.getLength(), [](LinkedListClass<int> &a, int i, int j) -> bool
	{
		if (a[i] < a[j])
			return true;
		else
			return false;
	});
	B.bubleSort(a, a.getLength(), [](LinkedListClass<int> &a, int i, int j) -> bool
	{
		if (a[i] > a[j])
			return true;
		else
			return false;
	});
	std::cout << "Len : " << a.getLength() << "Full: " << a.getIsEmpty() << std::endl;
	a.printList();
	a.deletelem(0);
	std::cout << "IIIIIIIIIIIIIIIIIIIIIIIIII" << std::endl;
	
	std::cout << "Element by operator " << a[2] << std::endl;
	a[1] = 0;
	a.printList();
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
	std::cout << "Len : " << a.getLength() << std::endl;
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
	std::cout << "Len : " << a.getLength() << std::endl;
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

	B.insert_sort(a2, a2.getLength(), [](LinkedListClass<int> &a, int i, int j) -> bool
	{
		if (a[i] < a[j])
			return true;
		else
			return false;
	});
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
	std::cout << "Len : " << a2.getLength() << "Full: " << a2.getIsEmpty() << std::endl;
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
