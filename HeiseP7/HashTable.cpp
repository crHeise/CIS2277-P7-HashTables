/*
 * Programmer: Chris Heise (crheise@icloud.com)
 * School: Central New Mexico Community College
 * Course: CIS 2277 C++ Programming III
 * Instructor: Ivonne Nelson
 * Date: 2 April 2022
 * 
 * Program: P7 Hash Table and Searchable Linked List
 * Purpose: Use a hash table and searchable linked list to
 *			store Person objects and search for them.
 * File: HashTable.cpp
 */

#include "HashTable.h"

int HashTable::Hash(Person* p)
{
	// Hash Algorithm/Scheme: 
		// Use the integers Month, Day, & Year from the Person's birthday as well as the string length of their name
		// Start with what will be the largest value (Year) and multiply it by two
		// Continue with each value (starting from what has the potential to be larger and continuing to what has the potential to be smaller)
		// Increase the factor (by 1) that each data point is multiplied by compared to the previous data point
		// Add all multiplied data points together
		// Finally, return the remainder of the result when divided by 100 (which ensures it will be between 0 and 99) as the Hash index

	// Hash Algorithm Example 1:
		// Name: JOBS, STEVE ; Bday: 2/24/1955
		// index = ((Year * 2) + (Day * 3) + (Name.length() * 4) + (Month * 5)) % 100
		// index = (1955 * 2) + (24 * 3) + (11 * 4) + (2 * 5)
		// index = 3910 + 72 + 44 + 10
		// index = 4036 % 100
		// index = 36
	// Hash Algorithm Example 2:
		// Name: THUNBERG, GRETA ; Bday: 1/3/2003
		// index = ((Year * 2) + (Day * 3) + (Name.length() * 4) + (Month * 5)) % 100
		// index = (2003 * 2) + (3 * 3) + (15 * 4) + (1 * 5)
		// index = 4006 + 9 + 60 + 5
		// index = 4080 % 100
		// index = 80

	int index{ 0 };

	index = (p->GetBirthDay().GetYear() * 2) + (p->GetBirthDay().GetDay() * 3) + (p->GetName().length() * 4) + (p->GetBirthDay().GetMonth() * 5);

	return index % 100;	// Ensures the returned index is between 0 and 99
}

void HashTable::HashFunction(Person* p)
{
	table[Hash(p)].Push_back(p);
}

int HashTable::GetValue(string name, int mm, int dd, int yy, Person** value)
{
	Person* p = new Person(name, mm, dd, yy);
	int index = Hash(p);
	if (p != nullptr)
	{
		delete p;
		p = nullptr;
	}

	bool found = table[index].IsPresent(name, mm, dd, yy, value);

	if (found)
	{
		return index;
	}

	return -1;
}

void HashTable::AnalyzeTable(int distribution[], int total)
{
	for (int i{ 0 }; i < total; ++i)
	{
		distribution[i] = table[i].Size();
	}
}

HashTable::~HashTable()
{
	if (table != nullptr)
	{
		delete[] table;
		table = nullptr;
	}
}
