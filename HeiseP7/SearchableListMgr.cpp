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
 * File: SearchableListMgr.cpp
 */

#include "SearchableListMgr.h"

bool SearchableListMgr::IsPresent(string name, int mm, int dd, int yy, Person** per)
{
	if (count == 0)
		return false;

	PersonNode* temp;
	temp = first;

	for (int i{ 0 }; i < count; ++i)
	{
		Person* pPer = temp->GetPerson();

		// Check name
		if (pPer->GetName() == name)
		{
			// Check birthday
			int pMonth{ pPer->GetBirthDay().GetMonth() };
			int pDay{ pPer->GetBirthDay().GetDay() };
			int pYear{ pPer->GetBirthDay().GetYear() };

			if (pMonth == mm && pDay == dd && pYear == yy)
			{
				*(per) = pPer;
				return true;
			}
		}
		else
		{
			// Keep searching linked list
			temp = temp->GetNext();
		}
	}
	
	return false;
}
