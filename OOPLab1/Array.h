#pragma once
#include "number.h"
class Array
{
public:
	void createArr(int newLen);
	void printArr();
	void fillArr();
	void printAvgAndSKO();
	void sortArr(bool ascending);
	void changeElem(int index, number newValue);
	void resizeArr(int newLen);
	int printLen();

private:
	int len = 0;
	number* arr;
};

