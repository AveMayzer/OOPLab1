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
		case 1: cout << "# | ������� �������� ����������� �������: " << endl;
			cin >> lenChoice;
			arr->createArr(lenChoice); break;
		case 2: cout << "# | ������ ��� ��������� ��������� ������ �� " << arr->printLen() << " ��������." << endl;
			arr->fillArr(); break;
		case 3: cout << "# | ������: "; arr->printArr();
			cout << endl; break;
		case 4: arr->printAvgAndSKO(); break;
		case 5: cout << "# | ������� 1 ��� ���������� �� �����������, 0 - �� ��������: ";
			cin >> asc; arr->sortArr(asc); break;
		case 6: cout << "# | ������� ����� �������� ����������� �������: "; cin >> lenChoice; 
			arr->resizeArr(lenChoice); break;
		case 7: cout << "# | ������� ������ ��������, ������� ������ ��������: "; cin >> indexChoice;
			cout << "# | ������� ����� �������� ��������: "; cin >> newValue;
			arr->changeElem(indexChoice, newValue); break;
		
		case 0: return;	

		default: cout << "!| ������! ������� ����� �� 0 �� 7." << endl; break;
		}

		cout << endl;
	}
	
	return;
}

void Application::printMenu() {
	cout << "? | ��� ������ �������?" << endl;
	cout << "1 | ������� ����� ������ n-� �����������." << endl;
	cout << "2 | ��������� ������ ������ �������." << endl;
	cout << "3 | ������� �������� �������." << endl;
	cout << "4 | ������� ������� �������� � ��� ��������� �������." << endl;
	cout << "5 | ���������� ���������� �������" << endl;
	cout << "6 | �������� ����������� �������" << endl;
	cout << "7 | �������� �������� ������ �������� �������." << endl;
	cout << "0 | ����� �� ���������." << endl;
}