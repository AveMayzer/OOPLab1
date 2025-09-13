#include "Application.h"
#include "iostream"

using namespace std;

Application::Application() {

}

void Application::exec() {

	setlocale(0, "");
	number newValue;
	int choice, lenChoice, indexChoice;
	bool asc;

	Array *arr = new Array();


	while (true) {
		printMenu();
		cin >> choice;

		switch (choice) {
		case 1: cout << "# | Введите значение размерности массива: " << endl;
			cin >> lenChoice;
			arr->create(lenChoice); break;
		case 2: cout << "# | Сейчас вам предстоит заполнить массив до " << arr->printLen() << " элемента." << endl;
			arr->fill(); break;
		case 3: cout << "# | Массив: "; arr->printAll();
			cout << endl; break;
		case 4: arr->printAvgAndSKO(); break;
		case 5: cout << "# | Введите 1 для сортировки по возрастанию, 0 - по убыванию: ";
			cin >> asc; arr->sort(asc); break;
		case 6: cout << "# | Введите новое значение размерности массива: "; cin >> lenChoice; 
			arr->resize(lenChoice); break;
		case 7: cout << "# | Введите индекс элемента, который хотите изменить: "; cin >> indexChoice;
			cout << "# | Введите новое значение элемента: "; cin >> newValue;
			arr->changeElem(indexChoice, newValue); break;
		
		case 0: return;	

		default: cout << "!| Ошибка! Введите число от 0 до 7." << endl; break;
		}

		cout << endl;
	}
	
	return;
}

void Application::printMenu() {
	cout << "? | Что хотите сделать?" << endl;
	cout << "1 | Создать новый массив n-й размерности." << endl;
	cout << "2 | Заполнить массив своими числами." << endl;
	cout << "3 | Вывести элементы массива." << endl;
	cout << "4 | Вывести среднее значение и СКО элементов массива." << endl;
	cout << "5 | Произвести сортировку массива" << endl;
	cout << "6 | Изменить размерность массива" << endl;
	cout << "7 | Изменить значение любого элемента массива." << endl;
	cout << "0 | Выйти из приложеня." << endl;
}