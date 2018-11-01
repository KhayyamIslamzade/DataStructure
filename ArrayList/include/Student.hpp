
/**
* @file Student.hpp
* @description  :  Sınıftaki bir öğrenciyi temsil eder
* @course Dersi 2C
* @assignment 1.Ödev
* @date 25.10.18
* @author G141210098 Hayyam Islamzade hayyam.islamzade@ogr.sakarya.edu.tr
*/

#ifndef STUDENT_HPP
#define STUDENT_HPP

#include <iostream>
#include "School.hpp"
#include "Overflow.hpp"
#include "NotExist.hpp"
using namespace std;

class Student
{
  private:
	char *label;

  public:
	void setLabel(char label)
	{
		this->label = new char(label);
	}
	void changeAdress(void *label)
	{
		this->label = (char *)label;
	}
	char *getLabel()
	{
		return label;
	}
	~Student()
	{
		delete label;
	}
};

#endif