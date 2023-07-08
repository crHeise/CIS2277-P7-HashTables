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
 * File: Functions.cpp
 */

#include "Functions.h"

void WriteHeader()
{
	cout << "Programmer: Chris Heise" << endl
		<< "Email: cheise3@cnm.edu" << endl
		<< "Course: CIS 2277-R01" << endl
		<< "Program: P7 Hash Table and Searchable Linked List" << endl
		<< "Purpose: use a Hash Table and Searchable Linked List" << endl
		<< "to store and search for Person objects." << endl
		<< endl;
}

string GetFilename()
{
	string filename;

	cout << endl << "Please enter a name for the Log File (without '.txt') ==> ";
	getline(cin, filename);

	return filename + ".txt";
}
