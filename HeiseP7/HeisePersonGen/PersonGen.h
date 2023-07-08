/*
 * Programmer: Chris Heise
 * Email: cheise3@cnm.edu
 * Course: CIS 2277-R01
 * Program: P2 The PersonGen Class
 * File: PersonGen.h
 */

#ifndef  _PERSONGEN_H
#define  _PERSONGEN_H

#include <string>
#include "Person.h"
#include <fstream>
#include <random>

class PersonGen
{
private:
	ifstream input;
	default_random_engine engine;
	int fileCount{ 0 }, linesRead{ 0 };
	int youngAge{ 4 }, oldAge{ 85 };
	int month{ 0 }, day{ 0 }, year{ 0 };
	string name;
	bool bUseFile{ false };
	bool bFilesRead[3]{ false, false, false };
	string firstFemaleNames[300];
	string firstMaleNames[300];
	string lastNames[300];

	bool ReadFile(string filename, string vn[]);
	void NameGen();
	void BirthdayGen(int youngAge, int oldAge);
	void ReadUseFile();

public:
	//default creation, alternate male, female, age range toddler to elderly
	PersonGen();

	//overloaded constructor, specify age range of persons
	PersonGen(int youngAge, int oldAge);

	//returns a Person object, created locally in class, not using new
	Person GetPerson();

	//return a Person created via the new operator
	Person* GetNewPerson();

	//return a bool indicating that the text files were correctly opened
	//and read.  Returns false if any file was not opened and read.
	bool IsTextFileRead();	//she made this const in the workflow...should I change it here?


	//createFile creates a file with number of persons, 
	//return true if file successfully written, false if not.
	bool   CreateFile(string filename, int numOfPersons);

	//useFile directs the generator to use the person data that is 
	//stored in the file instead of random creation. 
	//Return true indicates it was able to locate and open the file. 
	//Returns false file not found. 
	//When this method is called, the generator will only read the file 
	//line-by-line to pull out person data AS NEEDED. It DOES NOT read 
	//the entire file and store the data. If the file runs out of names, 
	//begin generating the persons randomly. 
	bool  UseFile(string filename);
};
#endif
