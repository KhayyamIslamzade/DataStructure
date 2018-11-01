/**
* @file Arraylist.hpp
* @description Liste sınıfı
* @course Dersi 2C
* @assignment 1.Ödev
* @date 25.10.18
* @author G141210098 Hayyam Islamzade hayyam.islamzade@ogr.sakarya.edu.tr
*/

#ifndef ARRAYLIST_HPP
#define ARRAYLIST_HPP

#include <iostream>
#include "Overflow.hpp"
#include "NotExist.hpp"
using namespace std;

template <typename T>
class ArrayList
{
  private:
	int arrayCount;
	int capacity;

	T *items;

	void reserve(int capacity)
	{
		if (this->capacity >= capacity)
			return; // O kadar yer zaten var
		T *tmp = new T[capacity];
		for (int j = 0; j < arrayCount; j++)
			tmp[j] = items[j];
		if (items != NULL)
			delete[] items;
		items = tmp;
		this->capacity = capacity;
	}

  public:
	ArrayList() //Varsay�lan Yap�c� metot
	{
		arrayCount = 0;
		capacity = 0;
		items = NULL;
	}
	ArrayList(const ArrayList &sag) // Copy constructor
	{
		arrayCount = 0;
		items = new T[sag->length()];
		for (int i = 0; i < sag.size(); i++)
		{
			insert(i, sag.at(i));
		}
		arrayCount = arrayCount;
	}
	void add(const T &label) //En sona ekler
	{

		// cout << label;
		add(arrayCount, label);
	}
	// void deneme(const T *label)
	// {
	// 	cout << label;
	// }
	void add(int i, const T &label) throw(Overflow)
	{
		if (i < 0 || i > arrayCount)
			throw Overflow("Indeks sinirlar disinda");

		if (arrayCount >= capacity)
		{
			reserve(max(1, 2 * capacity)); //Yer yoksa 2 kat yer ay�r.
		}

		for (int j = arrayCount - 1; j >= i; j--)
		{
			items[j + 1] = items[j];
		}

		items[i] = label;
		// cout << "Add:" << label;
		arrayCount++;
	}

	const T &itemAt(int i) const throw(NotExist)
	{
		if (i < 0 || i >= arrayCount)
			throw NotExist("Eleman bulunamadi");
		return items[i];
	}
	void remove(const T &item) throw(NotExist)
	{
		for (int i = 0; i < arrayCount; i++)
		{
			if (items[i] == item)
			{
				removeAt(i);
				return;
			}
		}
		throw NotExist("Eleman bulunamadi");
	}
	void removeAt(int i) throw(NotExist)
	{
		if (i < 0 || i >= arrayCount)
			throw NotExist("Eleman bulunamadi");
		for (int j = i + 1; j < arrayCount; j++)
			items[j - 1] = items[j];
		arrayCount--;
	}
	void swap(int first, int second)
	{
		if (first < 0 || first >= arrayCount || second < 0 || second >= arrayCount)
			throw NotExist("Eleman bulunamadi");
		T temp = items[first];
		items[first] = items[second];
		items[second] = temp;
	}
	void swapByAdress(T item, int index)
	{
		items[index] = item;
	}
	bool isEmpty() const
	{
		return length() == 0;
	}
	int indexOf(const T &item) const throw(NotExist)
	{
		for (int i = 0; i < arrayCount; i++)
		{
			if (items[i] == item)
				return i;
		}
		throw NotExist("Eleman bulunamadi");
	}

	int length() const
	{
		return arrayCount;
	}
	// T get(int i) const
	// {
	// 	return items[i];
	// }
	~ArrayList()
	{
		delete[] items;
	}
};

#endif