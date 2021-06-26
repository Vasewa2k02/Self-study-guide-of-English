#include "stdafx.h"

int main()
{
	setlocale(LC_ALL, "Rus");
	srand(time(NULL));
	system("chcp 1251");
	start();
	bool work = true;

	while (work)
	{
		switch (menu())
		{
		case(1):
			while (work)
			{
				switch (menu_1())
				{
				case(1):
					dictionary::addWord(sizeOfList++);
					break;

				case(2):
					dictionary::checkDictionary();
					break;

				case(3):
					dictionary::checkDictionary();
					cout << " Введите номер слова, которое хотите исправить(назад - '0'): ";
					cin >> choice;
					if (choice == 0) break;
					dictionary::addWord(--choice);
					break;

				case(4):
					dictionary::checkDictionary();
					cout << " Введите номер слова, которое хотите удалить(назад - '0'): ";
					cin >> choice;
					if (choice == 0) break;
					dictionary::delWord(--choice);
					break;

				case(0):
					work = false;
					break;

				default:
					cout << " Этот вариант отсутствует!" << endl << endl;
					break;
				}
			}
			work = true;
			break;

		case(2):
			grammarAid(menu_2());
			break;

		case(3):
			while (work)
			{
				switch (menu_3())
				{
				case(1):
					learningWordCall();
					break;

				case(2):
					learningGram();
					break;

				case(0):
					work = false;
					break;

				default:
					cout << " Этот вариант отсутствует!" << endl << endl;
					break;
				}
			}
			work = true;
			break;

		case(4):
			while (work)
			{
				switch (menu_4())
				{
				case(1):
					choice = 0;
					while (choice < 1)
					{
						cout << " Введите приемлемое количество повторений слова для запоминания: ";
						cin >> choice;
						system("cls");
					}
					settings.numForLearned = choice;
					break;

				case(2):
					choice = 0;
					cout << " 1. Нужно ввести русский перевод\n 2. Нужно ввести английский перевод\n 3. Комбинированный вариант\n 0. Назад\n(Введите выбор) ";
					cin >> choice;
					if (choice == 0) break;
					else
					{
						while (choice < 1 || choice > 3)
						{
							system("cls");
							cout << " 1. Нужно ввести русский перевод\n 2. Нужно ввести английский перевод\n 3. Комбинированный вариант\n 0. Назад\n(Введите выбор) ";
							cin >> choice;
							if (choice == 0) break;
						}
						if (choice >= 1 && choice <= 3) settings.optionLearning = choice;
					}
					break;

				case(0):
					work = false;
					break;

				default:
					cout << " Этот вариант отсутствует!" << endl << endl;
					break;
				}
				system("cls");
			}
			work = true;
			break;

		case(0):
			end();
			work = false;
			break;

		default:
			cout << " Этот вариант отсутствует!" << endl << endl;
			break;
		}
	}
}
