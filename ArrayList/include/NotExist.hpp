/**
* @file NotExist.hpp
* @description  : Eleman bulunamadiginda firlatilan hata
* @course Dersi 2C
* @assignment 1.Ödev
* @date 25.10.18
* @author G141210098 Hayyam Islamzade hayyam.islamzade@ogr.sakarya.edu.tr
*/

#ifndef NOTEXIST_HPP
#define NOTEXIST_HPP

#include "Error.hpp"

class NotExist : public Error
{
public:
  NotExist(const string &msg) : Error(msg) {}
};
#endif