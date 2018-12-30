
#ifndef ERRORS_HPP
#define ERRORS_HPP
#include "Error.hpp"
class EndList : public Error
{
public:
  EndList(string msg = "End Of The List") : Error(msg) {}
};

class NullReferance : public Error
{
public:
  NullReferance(string msg = "NULL Referance Error") : Error(msg) {}
};

class EmptyList : public Error
{
public:
  EmptyList(string msg = "List is Empty") : Error(msg) {}
};

class Overflow : public Error
{
public:
  Overflow(const string msg = "OverFlow") : Error(msg) {}
};
class NotExist : public Error
{
public:
  NotExist(const string msg = "Not Exist") : Error(msg) {}
};
#endif