/**
* @file School.hpp
* @description  :  Okuldaki bir sınıfı temsil eder ve içerisinde öğrenciler dizisi bulunur
* @course Dersi 2C
* @assignment 1.Ödev
* @date 25.10.18
* @author G141210098 Hayyam Islamzade hayyam.islamzade@ogr.sakarya.edu.tr
*/

#ifndef SCHOOL_HPP
#define SCHOOL_HPP

#include <iostream>
#include <fstream>
#include <string>
#include "ArrayList.hpp"
#include "MyClass.hpp"
#include "Overflow.hpp"
#include "NotExist.hpp"

using namespace std;

class School
{
  private:
	ArrayList<MyClass *> *classNames;

  public:
	School()
	{
		classNames = new ArrayList<MyClass *>();
	}

	ArrayList<MyClass *> *getClassNames()
	{
		return classNames;
	}
	void addClass(MyClass *myClass)
	{
		classNames->add(myClass);
	}

	void changeClass(char classOne, char classTwo)
	{
		MyClass *myClassOne = indexOfLabel(classOne);
		MyClass *myClassTwo = indexOfLabel(classTwo);

		int indexOne = classNames->indexOf(myClassOne);
		int indexTwo = classNames->indexOf(myClassTwo);

		classNames->swap(indexOne, indexTwo);
	}

	MyClass *indexOfLabel(const char label) const throw(NotExist)
	{
		for (int i = 0; i < classNames->length(); i++)
		{
			if (*classNames->itemAt(i)->getLabel() == label)
				return classNames->itemAt(i);
		}
		throw NotExist("Eleman bulunamadi");
	}

	~School()
	{
		delete[] classNames;
	}
};
#endif
