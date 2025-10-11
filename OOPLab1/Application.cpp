#include "Application.h"
#include "iostream"

using namespace std;

Application::Application() {

}

void Application::exec() {
	setlocale(0, "");
	int choice;

	while (true) {
		printMainMenu();
		cin >> choice;

		switch (choice) {
		case 1: 
			execArrayMode(); 
			break;
		case 2: 
			execPolynomMode(); 
			break;
		case 0: 
			return;
		default: 
			cout << "! | Ошибка! Введите число от 0 до 2." << endl; 
			break;
		}
		cout << endl;
	}
}

void Application::printMainMenu() {
	cout << "? | Выберите режим работы:" << endl;
	cout << "1 | Работа с массивом" << endl;
	cout << "2 | Работа с полиномом" << endl;
	cout << "0 | Выйти из приложения" << endl;
}

void Application::execArrayMode() {
	number newValue;
	int choice, lenChoice, indexChoice;
	bool asc;

	Array *arr = new Array();

	while (true) {
		printArrayMenu();
		cin >> choice;

		switch (choice) {
		case 1: 
			cout << "# | Введите значение размерности массива: " << endl;
			cin >> lenChoice;
			arr->create(lenChoice); 
			break;

		case 2: 
			cout << "# | Сейчас вам предстоит заполнить массив до " << arr->printLen() << " элемента." << endl;
			cout << "# | Для каждого элемента вводите действительную и мнимую части через пробел:" << endl;
			arr->fill();
			cout << "Массив: "; 
			arr->printAll(); 
			break;

		case 3: 
			cout << "# | Массив: "; 
			arr->printAll(); 
			break;

		case 4: 
			arr->printAvgAndSKO(); 
			break;

		case 5: 
			cout << "# | Введите 1 для сортировки по возрастанию, 0 - по убыванию: ";
			cin >> asc;
			arr->sort(asc);
			cout << "Массив: "; 
			arr->printAll(); 
			break;

		case 6: 
			cout << "# | Введите новое значение размерности массива: "; 
			cin >> lenChoice; 
			arr->resize(lenChoice); 
			arr->printAll(); 
			break;

		case 7: 
			cout << "# | Введите индекс элемента, который хотите изменить: "; 
			cin >> indexChoice;
			cout << "# | Введите новое значение элемента (действительная и мнимая части): "; 
			cin >> newValue;
			arr->changeElem(indexChoice, newValue);
			cout << "Массив: "; 
			arr->printAll(); 
			break;

		case 0: 
			delete arr;
			return;

		default: 
			cout << "! | Ошибка! Введите число от 0 до 7." << endl; 
			break;
		}
		cout << endl;
	}
}

void Application::execPolynomMode() {
	int choice, indexChoice, newDegree;
	number newValue, x;

	Polynom *polynom = new Polynom();

	while (true) {
		printPolynomMenu();
		cin >> choice;

		switch (choice) {
		case 1:
			polynom->inputPolynomial();
			break;

		case 2:
			cout << "# | Введите новый ведущий коэффициент an (действительная и мнимая части): ";
			cin >> newValue;
			polynom->changeLeadingCoefficient(newValue);
			cout << "# | Ведущий коэффициент изменен." << endl;
			break;

		case 3:
			if (polynom->getDegree() == 0) {
				cout << "! | У 0-полинома нет корней для изменения!" << endl;
				break;
			}
			cout << "# | Введите индекс корня (0-" << (polynom->getDegree() - 1) << "): ";
			cin >> indexChoice;
			cout << "# | Введите новое значение корня (действительная и мнимая части): ";
			cin >> newValue;
			polynom->changeRoot(indexChoice, newValue);
			break;

		case 4:
			cout << "# | Введите точку x для вычисления P(x) (действительная и мнимая части): ";
			cin >> x;
			cout << "# | P(" << x << ") = " << polynom->calculateValue(x) << endl;
			break;

		case 5:
			cout << "# | Введите новую степень полинома: ";
			cin >> newDegree;
			polynom->resize(newDegree);
			cout << "# | Размерность изменена." << endl;
			break;

		case 6:
			cout << "# | Полином в стандартной форме:" << endl;
			polynom->printStandardForm();
			break;

		case 7:
			cout << "# | Полином в факторной форме:" << endl;
			polynom->printFactorForm();
			break;

		case 0:
			delete polynom;
			return;

		default:
			cout << "! | Ошибка! Введите число от 0 до 7." << endl;
			break;
		}
		cout << endl;
	}
}

void Application::printArrayMenu() {
	cout << "? | Что хотите сделать с массивом?" << endl;
	cout << "1 | Создать новый массив n-й размерности." << endl;
	cout << "2 | Заполнить массив своими числами." << endl;
	cout << "3 | Вывести элементы массива." << endl;
	cout << "4 | Вывести среднее значение и СКО элементов массива." << endl;
	cout << "5 | Произвести сортировку массива" << endl;
	cout << "6 | Изменить размерность массива" << endl;
	cout << "7 | Изменить значение любого элемента массива." << endl;
	cout << "0 | Вернуться в главное меню." << endl;
}

void Application::printPolynomMenu() {
	cout << "? | Что хотите сделать с полиномом?" << endl;
	cout << "1 | Ввести новый полином (степень, коэффициент an и корни)" << endl;
	cout << "2 | Изменить ведущий коэффициент an" << endl;
	cout << "3 | Изменить корень по индексу" << endl;
	cout << "4 | Вычислить значение полинома в точке" << endl;
	cout << "5 | Изменить степень полинома" << endl;
	cout << "6 | Вывести полином в стандартной форме" << endl;
	cout << "7 | Вывести полином в факторной форме" << endl;
	cout << "0 | Вернуться в главное меню." << endl;
}