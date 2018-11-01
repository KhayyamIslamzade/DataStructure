
/**
* @file MyClass.hpp
* @description  : Okulu temsil eden ve içerisinde sınıflar dizisi bulunan bir class
* @course Dersi 2C
* @assignment 1.Ödev
* @date 25.10.18
* @author G141210098 Hayyam Islamzade hayyam.islamzade@ogr.sakarya.edu.tr
*/
#ifndef MYCLASS_HPP
#define MYCLASS_HPP

#include <iostream>
#include "Student.hpp"
#include "ArrayList.hpp"
#include "Overflow.hpp"
#include "NotExist.hpp"
using namespace std;

class MyClass
{
  private:
	char *label;
	ArrayList<Student *> *studentNames;

  public:
	MyClass()
	{
		studentNames = new ArrayList<Student *>();
	}
	void setLabel(char label)
	{
		this->label = new char(label);
	}
	char *getLabel()
	{
		return label;
	}

	ArrayList<Student *> *getStudentNames()
	{
		return studentNames;
	}
	void addStudent(Student *student)
	{
		studentNames->add(student);
	}
	void swapStudent(Student *student, int index)
	{
		studentNames->swapByAdress(student, index);
	}

	Student *indexOfLabel(const char label) const throw(NotExist)
	{
		for (int i = 0; i < studentNames->length(); i++)
		{
			if (*studentNames->itemAt(i)->getLabel() == label)
				return studentNames->itemAt(i);
		}
		throw NotExist("Eleman bulunamadi");
	}

	~MyClass()
	{
		delete[] studentNames;
		delete label;
	}
};

#endif