/* Programmer: Chris Heise (crheise@icloud.com)
 * School: Central New Mexico Community College
 * Course: CIS 2277 C++ Programming III
 * Instructor: Ivonne Nelson
 * Date: 2 April 2022
 *
 * Program: P7 Hash Table and Searchable Linked List
 * Purpose: Use a hash table and searchable linked list to
 *			store Person objects and search for them.
 */

/*Barbara Johnston
 *for CIS 2277 Fall 2013
 *File: ListMgr.h
 */

#ifndef _LIST_MGR_H
#define _LIST_MGR_H

#include "PersonNode.h"
#include <string>
using namespace std;

class ListMgr
{
protected:
   int count{0};	// The number of PersonNodes in the list
   PersonNode* first{ nullptr }, * last{ nullptr };

public:
   ListMgr() = default;

   //Person* input, added to the front of the list
   void Push_front(Person *p);

   //Person* input, added to the end of the list
   void Push_back(Person *p);

   //Removes from the front of the list
   void Pop_front();

   //Removes from the end of the list
   void Pop_back();

   //Returns the number of PersonNodes in the list
   int Size(){return count;}

   //Returns a pointer to the first Person
   Person* Front();

   //Returns a pointer to the last Person
   Person* Back();

   //Returns true if the list is empty, false if not
   bool Empty();

   //Removes any (and all) PersonNode from the list that contains "n" in name
   //n could be full or partial name
   void Remove(string n);

   //Removes the PersonNode at position pos.
   //Note: first string is #1
   void Erase( int pos);

   //Clears all PersonNodes from the list
   void Clear();

   //Shows the list, names only. First line states number in list
   //Second, 3rd, + lines shows names of people in the list. 
   //Place several names on one line. 
   //Separate names using obvious symbol, such as --> or :: 
   void Show();

   //This show function returns a string that has the same features
   //of the show(), except it has been stringstreamed into a string
   string ShowString();

   //Destructor, clears the list
   ~ListMgr();

};

#endif