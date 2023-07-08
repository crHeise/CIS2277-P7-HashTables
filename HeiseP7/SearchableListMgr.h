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
 * File: SearchableListMgr.h
 */

#ifndef SEARCHABLE_LIST_MGR_H
#define SEARCHABLE_LIST_MGR_H

#include "ListMgr.h"
#include "PersonNode.h"
#include "HeisePersonGen/Person.h"

#include <string>

class SearchableListMgr : public ListMgr
{
public:
	SearchableListMgr() = default;
	bool IsPresent(string name, int mm, int dd, int yy, Person** per);
};

#endif