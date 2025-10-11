#pragma once
#include "number.h"
class Array
{
public:
	Array();
	~Array();
	void create(int newLen);
	void printAll();
	void fill();
	void printAvgAndSKO();
	void sort(bool ascending);
	void changeElem(int index, number newValue);
	void resize(int newLen);
	int printLen();
	number getElement(int index) const;
private:
	int len = 0;
	number* arr;
};

