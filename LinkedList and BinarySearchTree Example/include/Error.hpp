

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