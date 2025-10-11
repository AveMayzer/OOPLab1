#pragma once
#include "array.h"
#include "Polynom.h"
#include "number.h"

class Application
{
public:
	Application();
	void exec();
private:
	void printMainMenu();
	void printArrayMenu();
	void printPolynomMenu();
	void execArrayMode();
	void execPolynomMode();
};

