/**
* @file Test.cpp
* @description Test işlemlerini gerçekleştirecek
* @course Dersi 2C
* @assignment 1.Ödev
* @date 25.10.18
* @author G141210098 Hayyam Islamzade hayyam.islamzade@ogr.sakarya.edu.tr
*/


#include <iostream>
#include "Control.hpp"
using namespace std;

int main()
{

	Control *control = new Control();
	control->getMenu();

	// ArrayList<Class> *schoolNames = new ArrayList<Class>();

	// string line;
	// string label;

	// Class *_class	= new Class();
	// Student *student = new Student();

	// ifstream fileReader;
	// fileReader.open("Okul.txt");

	// while (!fileReader.eof()) // To get you all the lines.
	// {

	// getline(fileReader, line); // Saves the line in STRING.

	// // tmp = new string(STRING);

	// // line = string(*tmp);

	// _class = new Class();
	// for (unsigned int i = 0; i < line.size(); i++)
	// {

	// if (line[i] != ' ')
	// {

	// label = line[i];

	// if (i == 0) //class name
	// {

	// _class->setLabel(label);

	// }
	// else //student name
	// {

	// student = new Student();
	// student->setLabel(label);

	// _class->studentNames->add(*student);
	// }
	// }
	// }
	// schoolNames->add(*_class);
	// }
	// fileReader.close();

	// short x = 1, y = 1;
	// system("CLS");
	// for (unsigned int i = 0; i < schoolNames->length(); i++)
	// {

	// School school = schoolNames->get(i);
	// string *schoolName = school.getLabel();
	// gotoxy(x, y);
	// cout << "Class:" << *schoolName;

	// for (unsigned int j = 0; j < school.studentNames->length(); j++)
	// {

	// Student student = school.studentNames->get(j);
	// string *studenName = student.getLabel();
	// y++;
	// gotoxy(x, y);
	// cout << *studenName << endl;
	// }
	// y = 1;
	// x += 10;

	// }
	// cin.get();

	return 0;
}
