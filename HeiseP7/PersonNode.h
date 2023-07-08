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
 *File: PersonNode.h
 */

// This is the linked list node class used by the ListMgr class.

#ifndef _PERSON_NODE_H
#define _PERSON_NODE_H

#include <iostream>
#include "HeisePersonGen/Person.h"
using namespace std;

class PersonNode
{
   private:
      PersonNode *prev, *next;
      Person* person;

   public:
      PersonNode() { next = prev = nullptr; }

      ~PersonNode()
      {
         cout << "\nIn PersonNode destructor.  " << person->GetName() << endl;
      }

      void SetPrev(PersonNode *p) { prev = p; }
      void SetNext(PersonNode *n) { next = n; }
      void SetPerson(Person* p) { person = p; }

      PersonNode *GetPrev() { return prev; }
      PersonNode *GetNext() { return next; }
      Person* GetPerson() { return person; }
};

#endif
