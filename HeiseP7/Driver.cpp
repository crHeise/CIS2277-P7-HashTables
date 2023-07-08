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
 * File: Driver.cpp
 */

#include "Functions.h"
#include "HashTable.h"
#include "SearchableListMgr.h"
#include "HeisePersonGen/Person.h"
#include "HeisePersonGen/PersonGen.h"

#include <iostream>
#include <iomanip>
#include <fstream>
#include <string>

using namespace std;

const string LOADFILE{ "BJ_Persons2000.txt" };
const string SEARCHFILE{ "BJ_42PersonsToFind.txt" };
const int NUM_OF_PERSONS{ 2000 };
const int NUM_OF_BUCKETS{ 100 };

int main()
{
	WriteHeader();

	HashTable* hT = nullptr;
	PersonGen* pg = nullptr;
	PersonGen* pg2 = nullptr;
	Person* p = nullptr;

	try
	{
		hT = new HashTable();
		pg = new PersonGen();
		pg2 = new PersonGen();
		p = new Person();
	}
	catch (bad_alloc ba)
	{
		cout << endl << "Oops! There was an issue allocating memory!" << endl;
		return 0;
	}

	pg->UseFile(LOADFILE);

	// Open a log file to report results
	string filename = GetFilename();
	ofstream output;
	output.open(filename.c_str());
	if (!output.is_open())
	{
		cout << endl << "Oops! There was an error opening the log file named " << filename << "!" << endl;
		return 0;
	}
	output << endl << "Log filename: " << filename << endl << endl
		<< "File for filling the Hash Table: " << LOADFILE << "(" << to_string(NUM_OF_PERSONS) << " Persons)" << endl
		<< "File for searching Hash Table: " << SEARCHFILE << "(42 Persons)" << endl << endl;

	// Fill Hash Table with Person objects
	cout << "Putting names into the Hash Table..." << endl << endl;
	output << "***Putting names into the Hash Table..." << endl << endl;
	for (int i{ 0 }; i < NUM_OF_PERSONS; ++i)
	{
		p = pg->GetNewPerson();
		hT->HashFunction(p);
	}

	// Analyze and display distribution of hashing
	int tableDistribution[NUM_OF_BUCKETS];
	hT->AnalyzeTable(tableDistribution, NUM_OF_BUCKETS);
	output << "***Results of Hash..." << endl << endl
		<< "Distribution:" << endl;

	// Min number of Persons in one bucket
	int distributionMin{ NUM_OF_BUCKETS + 1 };
	for (int i{ 0 }; i < NUM_OF_BUCKETS; ++i)
	{
		if (tableDistribution[i] < distributionMin)
			distributionMin = tableDistribution[i];
	}
	output << "\tMinimum List Length: " << to_string(distributionMin) << endl;

	// Max number of Persons in one bucket
	int distributionMax{ 0 };
	for (int i{ 0 }; i < NUM_OF_BUCKETS; ++i)
	{
		if (tableDistribution[i] > distributionMax)
			distributionMax = tableDistribution[i];
	}
	output << "\tMaximum List Length: " << to_string(distributionMax) << endl << endl;

	for (int i{ 0 }; i < NUM_OF_BUCKETS; i += 5)
	{
		for (int j{ 0 }; j < 5; j++)
		{
			double distributionPercentage{ 100.0 * tableDistribution[i + j] / NUM_OF_PERSONS };

			output.precision(2);
			output.setf(ios::fixed);

			output << "[" << to_string(i + j) << "] " << to_string(tableDistribution[i + j]) << ", " << distributionPercentage << "%\t";
		}

		output << endl;
	}

	// Search Hash Table using given file
	cout << "Searching the Hash Table..." << endl << endl;
	output << endl << "***Searching the Hash Table..." << endl << endl;
	pg2->UseFile(SEARCHFILE);

	for (int i{ 0 }; i < 42; ++i)
	{
		Person p2 = pg2->GetPerson();
		string name{ p2.GetName() };
		int month{ p2.GetBirthDay().GetMonth() };
		int day{ p2.GetBirthDay().GetDay() };
		int year{ p2.GetBirthDay().GetYear() };

		// Search for the Person and report results
		output << "Searching for: " << p2.GetFullDesc() << endl;
		
		Person* wanted = nullptr;	// Pointer of the found person (nullptr while/if not found)

		hT->GetValue(name, month, day, year, &wanted);

		if (wanted == nullptr)
		{
			output << "Not Found" << endl << endl;
		}
		else
		{
			output << "Found: " << wanted->GetFullDesc() << endl << endl;
		}
	}
	
	output << endl << "End log file.";
	output.close();

	if (hT != nullptr)
	{
		delete hT;
		hT = nullptr;
	}
	if (pg != nullptr)
	{
		delete pg;
		pg = nullptr;
	}
	if (pg2 != nullptr)
	{
		delete pg2;
		pg2 = nullptr;
	}
	if (p != nullptr)
	{
		delete p;
		p = nullptr;
	}

	cout << endl << "All finished. Thank you!" << endl;

	return 0;
}