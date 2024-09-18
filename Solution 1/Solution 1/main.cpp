#include "vector.h"
#include "func.h"
#include <locale.h>

int main()
{
	int button;
	TVector v1, v2, v3;
	double norma_v1, norma_v2, res;
	setlocale(LC_ALL, "ru");
	std::cin >> v1;
	std::cin >> v2;
	std::cout << v1 << v2;

	do {
		{
			menu();
			std::cin >> button;
			std::cout << std::endl;
			switch (button)
			{
			case 1:
				try
				{
					v3 = v1 + v2;
					std::cout << "Сумма векторов = " << v3 << std::endl;
					break;
				}
				catch (const std::runtime_error& e)
				{
					std::cout << "Произошла ошибка: " << e.what() << std::endl;
					std::cout << std::endl;
					break;
				};
			case 2:
				try
				{
					v3 = v1 - v2;
					std::cout << "Разность векторов = " << v3 << std::endl;
					break;
				}
				catch (const std::runtime_error& e)
				{
					std::cout << "Произошла ошибка: " << e.what() << std::endl;
					std::cout << std::endl;
					break;
				};
			case 3:
				try
				{
					res = v1 * v2;
					std::cout << "Скалярное произведение векторов = " << res << std::endl << std::endl;
					break;
				}
				catch (const std::runtime_error& e)
				{
					std::cout << "Произошла ошибка: " << e.what() << std::endl;
					std::cout << std::endl;
					break;
				};
			case 4:
				norma_v1 = v1.Norma_Vectora();
				norma_v2 = v2.Norma_Vectora();
				std::cout << "Норма v1 = " << norma_v1 << std::endl << "Норма v2 = " << norma_v2 << std::endl;
				std::cout << std::endl;
				break;
			case 5:
				double constant;
				std::cout << "Введите константу: ";
				std::cin >> constant;
				std::cout << "Операции с константой: " << std::endl;
				std::cout << std::endl;
				std::cout << "V1 + " << constant << " = " << v1 + constant << std::endl;
				std::cout << "V1 - " << constant << " = " << v1 - constant << std::endl;
				std::cout << "V1 * " << constant << " = " << v1 * constant << std::endl;
				std::cout << "V2 + " << constant << " = " << v2 + constant << std::endl;
				std::cout << "V2 - " << constant << " = " << v2 - constant << std::endl;
				std::cout << "V2 * " << constant << " = " << v2 * constant << std::endl;
			default:
				break;
			}
		}
	} while (button != 9);
	return 0;
}