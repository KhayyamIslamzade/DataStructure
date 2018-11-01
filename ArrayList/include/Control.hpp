/**
* @file Control.hpp
* @description  Program menüsündeki işlemleri yönetir
* @course Dersi 2C
* @assignment 1.Ödev
* @date 25.10.18
* @author G141210098 Hayyam Islamzade hayyam.islamzade@ogr.sakarya.edu.tr
*/

#ifndef CONTROL_HPP
#define CONTROL_HPP

#include <iostream>
#include <fstream>
#include <string>
#include <windows.h>
#include <locale>
#include "School.hpp"
#include "MyClass.hpp"
#include "ArrayList.hpp"
#include "Overflow.hpp"
#include "NotExist.hpp"

using namespace std;

class Control
{
  private:
	int choice = 0;
	char label;
	char classOne, classTwo;
	char studentOne, studentTwo;
	short x = 1, y = 1, maxY = 1;
	string line;

	MyClass *myClass;
	Student *student;
	School *school;

	void setCursorPosition(int x, int y)
	{
		COORD pos = {x, y};
		HANDLE output = GetStdHandle(STD_OUTPUT_HANDLE);
		SetConsoleCursorPosition(output, pos);
	}

	void readFile(string fileName)
	{
		ifstream fileReader;
		fileReader.open(fileName);

		while (!fileReader.eof())
		{

			getline(fileReader, line);

			myClass = new MyClass();
			for (unsigned int i = 0; i < line.size(); i++)
			{

				if (line[i] != ' ')
				{

					label = line[i];

					if (i == 0) //class name
					{

						myClass->setLabel(label);
					}
					else //student name
					{

						student = new Student();
						student->setLabel(label);

						myClass->addStudent(student);
					}
				}
			}
			school->addClass(myClass);
		}
		fileReader.close();
	}
	void printSchool()
	{
		x = 1;
		y = 1;
		system("cls");
		for (unsigned int i = 0; i < school->getClassNames()->length(); i++)
		{

			MyClass *tmpMyClass = school->getClassNames()->itemAt(i);
			char *className = tmpMyClass->getLabel();
			setCursorPosition(x, y);
			cout << "Class :" << *className;

			for (unsigned int j = 0; j < tmpMyClass->getStudentNames()->length(); j++)
			{

				Student *student = tmpMyClass->getStudentNames()->itemAt(j);
				char *studenname = student->getLabel();
				y++;
				setCursorPosition(x, y);
				cout << *studenname << " (" << (void *)studenname << ")" << endl;
			}
			if (y > maxY)
				maxY = y + 2;
			y = 1;
			x += 15;
		}
	}
	void swapStudent(char student1, char student2)
	{
		Student *studentOne = findStudent(student1);
		Student *studentTwo = findStudent(student2);
		char *tmpStudent = studentTwo->getLabel();
		// cout << tmpStudent;

		// cin.ignore();
		// cin.get();
		studentTwo->changeAdress(studentOne->getLabel());
		studentOne->changeAdress(tmpStudent);

		// delete studentOne, studentTwo, tmpStudent;
	}

	Student *findStudent(char label)
	{
		for (short i = 0; i < school->getClassNames()->length(); i++)
		{
			MyClass *tmpClass = school->getClassNames()->itemAt(i);

			for (short j = 0; j < tmpClass->getStudentNames()->length(); j++)
			{
				Student *student = tmpClass->getStudentNames()->itemAt(j);
				if (*student->getLabel() == toupper(label) || *student->getLabel() == tolower(label))
				{
					return student;
				}
			}
		}
	}

  public:
	Control()
	{
		myClass = new MyClass();
		student = new Student();
		school = new School();
		readFile("Okul.txt");
	}

	void getMenu()
	{

		do
		{
			system("CLS");

			printSchool();
			setCursorPosition(0, maxY);
			cout << "1.Change Class" << endl;
			cout << "2.Change Student" << endl;
			cout << "0.Exit" << endl;
			cout << "\nChoice : ";
			cin >> choice;
			// system("CLS");
			switch (choice)
			{
			case 1:

				cout << "Class 1:";
				cin >> classOne;
				cout << endl;
				cout << "Class 2:";
				cin >> classTwo;
				school->changeClass(classOne, classTwo);
				cout << "Success...!" << endl;
				cin.ignore();
				cin.get();
				// cout<<"Class Name:";
				// cin.ignore();
				// getline(cin,isim);
				// isimler->add(isim);
				break;
			case 2:
				cout << "Student 1:";
				cin >> studentOne;
				cout << endl;
				cout << "Student 2:";
				cin >> studentTwo;
				swapStudent(studentOne, studentTwo);
				// cout<<"Isim:";
				// cin.ignore();
				// getline(cin,isim);
				// try{
				// isimler->remove(isim);
				// }
				// catch(ElemanYok &elemanYok){
				// cout<<endl<<elemanYok.Mesaj()<<endl;
				// cin.get();
				// }
				break;

			case 0:
				cout << endl
					 << "Exited...!" << endl;
				cin.ignore();
				cin.get();
				break;
			default:
				cout << endl
					 << "Wrong Choice...!" << endl;
				cin.ignore();
				cin.get();
				break;
			}
			system("CLS");
		} while (choice != 0);
	}

	~Control()
	{
		delete myClass;
		delete student;
		delete school;
	}
};
#endif
