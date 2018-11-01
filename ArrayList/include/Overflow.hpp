/**
* @file Overfloü.hpp
* @description  : tasma oldugunda firlatilan hata
* @course Dersi 2C
* @assignment 1.Ödev
* @date 25.10.18
* @author G141210098 Hayyam Islamzade hayyam.islamzade@ogr.sakarya.edu.tr
*/

#ifndef OVERFLOW_HPP
#define OVERFLOW_HPP

#include "Error.hpp"

class Overflow : public Error
{
  public:
	Overflow(const string &msg) : Error(msg) {}
};
#endif