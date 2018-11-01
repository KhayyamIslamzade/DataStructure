/**
* @file Error.hpp
* @description Hata firlatir
* @course Dersi 2C
* @assignment 1.Ödev
* @date 25.10.18
* @author G141210098 Hayyam Islamzade hayyam.islamzade@ogr.sakarya.edu.tr
*/

#ifndef HATA_HPP
#define HATA_HPP

#include <iostream>
using namespace std;

class Error
{
  private:
	string message;

  public:
	Error(const string &msg) : message(msg) {}
	string Message();
};
#endif