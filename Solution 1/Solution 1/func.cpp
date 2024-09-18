#include "func.h"
void menu()
{
	setlocale(LC_ALL, "ru");
	std::cout << "Выберите режим: " << std::endl;
	std::cout << "1. Сложение векторов " << std::endl;
	std::cout << "2. Вычитание векторов " << std::endl;
	std::cout << "3. Умножение векторов " << std::endl;
	std::cout << "4. Посчитать норму векторов " << std::endl;
	std::cout << "5. Операции с константой " << std::endl;
	std::cout << "9. Завершить работу" << std::endl;
	std::cout << "=================" << std::endl;
	std::cout << "Введите режим: ";
}
