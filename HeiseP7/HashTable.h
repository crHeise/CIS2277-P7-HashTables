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
 * File: HashTable.h
 */

#ifndef HASH_TABLE_H
#define HASH_TABLE_H

#include "SearchableListMgr.h"
#include "HeisePersonGen/Person.h"

class HashTable
{
private:
	SearchableListMgr* table;	//pointer for an array of ListMgrs (Linked Lists)
	int Hash(Person* p);
public:
	HashTable(){ table = new SearchableListMgr[100]; }
	void HashFunction(Person* p);
	int GetValue(string name, int mm, int dd, int yy, Person** value);
	void AnalyzeTable(int distribution[], int total);
	~HashTable();
};

#endif