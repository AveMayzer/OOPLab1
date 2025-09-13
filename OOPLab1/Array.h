#pragma once
#include "number.h"
class Array
{
public:
	void create(int newLen);
	void printAll();
	void fill();
	void printAvgAndSKO();
	void sort(bool ascending);
	void changeElem(int index, number newValue);
	void resize(int newLen);
	int printLen();

private:
	int len = 0;
	number* arr;
};

