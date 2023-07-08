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
 * File: ListMgr.cpp
 */

#include "ListMgr.h"
#include <sstream>

void ListMgr::Push_front(Person* p)
{
	PersonNode* np = new PersonNode();
	np->SetPerson(p);

	// Check if np is first Node to be added to the list
	if (count == 0)
	{
		// Set np to be first and last
		first = np;
		last = np;
	}
	else
	{
		np->SetNext(first);
		first->SetPrev(np);
		first = np;
		first->SetPrev(nullptr);
	}

	count++;
}

void ListMgr::Push_back(Person* p)
{
	PersonNode* np = new PersonNode();
	np->SetPerson(p);

	// Check if np is first Node to be added to the list
	if (count == 0)
	{
		// Set np to be first and last
		first = np;
		last = np;
	}
	else
	{
		np->SetPrev(last);
		last->SetNext(np);
		last = np;
		last->SetNext(nullptr);
	}

	count++;
}

void ListMgr::Pop_front()
{
	if (count == 0)
	{
		return;
	}
	
	PersonNode* np = new PersonNode();
	np = first->GetNext();
	delete first;

	if (count == 1)
	{
		count = 0;
		return;
	}

	first = np;
	first->SetPrev(nullptr);
	count--;
}

void ListMgr::Pop_back()
{
	if (count == 0)
	{
		return;
	}

	PersonNode* np = new PersonNode();
	np = last->GetPrev();
	delete last;

	if (count == 1)
	{
		count = 0;
		return;
	}

	last = np;
	last->SetNext(nullptr);
	count--;
}

Person* ListMgr::Front()
{
	if (count == 0)
	{
		return nullptr;
	}
	
	return first->GetPerson();
}

Person* ListMgr::Back()
{
	if (count == 0)
	{
		return nullptr;
	}

	return last->GetPerson();
}

bool ListMgr::Empty()
{
	if (count == 0)
	{
		return true;
	}

	return false;
}

void ListMgr::Remove(string n)
{
	PersonNode* temp = first;

	// Make sure list isn't empty
	if (count == 0)
	{
		return;
	}

	// Search throught the list for n
	while (temp != nullptr)
	{
		Person* p = temp->GetPerson();
		string fullname = p->GetName();
		string name = n;

		int pos = fullname.find(name, 0);

		// n is found
		if (pos != -1)
		{
			if (temp == first)
			{
				temp = first->GetNext();
				delete first;
				first = temp;
				first->SetPrev(nullptr);
			}
			else if (temp == last)
			{
				temp = last->GetPrev();
				delete last;
				last = temp;
				last->SetNext(nullptr);
			}
			else
			{
				PersonNode* before, * after;
				before = temp->GetPrev();
				after = temp->GetNext();
				before->SetNext(after);
				after->SetPrev(before);
				delete temp;
				temp = after;
			}
			count--;
		}

		temp = temp->GetNext();
	}
}

void ListMgr::Erase(int pos)
{
	// Check that pos is not outside of count
	if (pos > count || pos < 1 || count == 0)
	{
		return;
	}

	// Search for the position pos
	PersonNode* temp;
	temp = first;

	for (int i{ 1 }; i <= count; i++)
	{
		if (i == pos)
		{
			// Check if pos is first
			if (i == 1)
			{
				Pop_front();
			}
			// Check if pos is last
			else if (i == count)
			{
				Pop_back();
			}
			else
			{
				PersonNode* before, * after;
				before = temp->GetPrev();
				after = temp->GetNext();
				before->SetNext(after);
				after->SetPrev(before);
				delete temp;
				temp = after;


				count--;
			}

			// Element at pos found and deleted, so exit loop
			break;
		}
		else
		{
			// Not at pos yet, continue iterating through list
			temp = temp->GetNext();
		}
	}
}

void ListMgr::Clear()
{
	if (count == 0)
	{
		return;
	}

	if (count == 1)
	{
		delete first;
		last = nullptr;
		first = nullptr;
		return;
	}

	PersonNode* temp;

	for (int i{ 1 }; i <= count; i++)
	{
		// Check if it's the last one
		if (i == count)
		{
			delete last;
		}
		else
		{
			// Delete first node
			temp = first->GetNext();
			delete first;
			first = temp;
			first->SetPrev(nullptr);
		}
	}

	count = 0;
}

void ListMgr::Show()
{
	if (count == 0)
	{
		cout << to_string(count) << endl;
		return;
	}

	PersonNode* temp = first;
	Person* p;
	stringstream ssList;

	ssList << "There are " << to_string(count) << " number of Persons in the list." << endl;
	for (int i{ 1 }; i <= count; ++i)
	{
		p = temp->GetPerson();
		ssList << p->GetName() << "::";
		temp = temp->GetNext();
	}

	cout << ssList.str();
}

string ListMgr::ShowString()
{
	if (count == 0)
	{
		return "There is no person in the list.";
	}

	stringstream ssList;
	PersonNode* temp = first;
	Person* p;

	ssList << "There are " << to_string(count) << " number of Persons in the list." << endl;
	for (int i{ 1 }; i <= count; ++i)
	{
		p = temp->GetPerson();
		ssList << p->GetName() << "::";
		temp = temp->GetNext();
	}

	return ssList.str();
}

ListMgr::~ListMgr()
{
	Clear();
}
