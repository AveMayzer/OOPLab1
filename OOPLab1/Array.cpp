#include "Array.h"
#include <iostream>

using namespace std;

void Array::createArr(int newLen) { 

	if (len < 0) {
		cout << "! | Размерность массива можно создать только из неотрицательных чисел!" << endl;
		this->len = 0;
	}



	this->len = newLen;
	arr = new number[len];


}

void Array::printArr() {
	for (int i = 0; i < len; i++) {
		cout << *(arr + i) << " ";

	}
}

void Array::printAvgAndSKO() {
	number sum = 0;
	number avg = 0;
	number sko = 0;

	for (int i = 0; i < len; i++) {
		sum += *(arr + i);
	}

	avg = sum / this->len;

	for (int i = 0; i < len; i++) {
		sko += pow(*(arr + i) - avg, 2);
	}

	sko /= len - 1;
	sko = pow(sko, 0.5);

	cout << "# | Среднее значение массива: " << avg << " СКО равен: " << sko;
}

int Array::printLen() {
	return this->len;
}

void Array::fillArr() {
	for (int i = 0; i < len; i++) {
		cin >> *(arr + i);
	}
}

void Array::sortArr(bool ascending) {
	for (int i = 0; i < len - 1; ++i) {
		for (int j = 0; j < len - i - 1; ++j) {
			if ((ascending && arr[j] > arr[j + 1]) ||
				(!ascending && arr[j] < arr[j + 1])) {
				std::swap(arr[j], arr[j + 1]);
			}
		}
	}
}
void Array::changeElem(int index, number newValue) {
	if (index < 0 || index >= len) {
		cout << "! | Индекс выходит за границы массива!" << endl;
		return;
	}
	arr[index] = newValue;
}

void Array::resizeArr(int newLen) {
	if (newLen < 0) {
		cout << "! | Размерность массива можно создать только из неотрицательных чисел!" << endl;
		return;
	}
	number* newArr = new number[newLen];
	int minLen = (newLen < len) ? newLen : len;

	for (int i = 0; i < minLen; ++i) {
		newArr[i] = arr[i];
	}
	for (int i = minLen; i < newLen; ++i) { 
		newArr[i] = 0;
	}

	delete[] arr;
	arr = newArr;

}