#include "stdafx.h"

namespace dictionary
{
	void checkDictionary()
	{
		for (int i = 0; i < sizeOfList; i++)
		{
			cout << i + 1 << ". ";
			cout << words[i].engWord;
			if (words[i].isPlural) cout << " (" << words[i].plural << ")";
			if (words[i].irregularVb) cout << " (2nd form - " << words[i]._2ndVerbForm << ", 3rd form - " << words[i]._3rdVerbForm << ")";
			cout << " - " << words[i].rusWord << " (";
			cout << gram.partOfSpeech[1][words[i].shortPOS] << "; пометка: ";
			cout << words[i].remark << ")" << endl;
		}
	}

	void addWord(int n)
	{
		cout << "Введите англиский вариант слова(например: 'pen'): ";
		cin.ignore(); cin.getline(words[n].engWord, sizeof(words[n].engWord));
		cout << "Введите русский вариант слова(например: 'ручка'): ";
		cin.getline(words[n].rusWord, sizeof(words[n].rusWord));
		cout << "К какой части речи относится это слово?" << endl;
		for (int i = 0; i < 6; i++)
		{
			cout << i + 1 << ". " << gram.partOfSpeech[1][i] << endl;
		}
		cout << "(Выберите пунк) ";
		cin >> words[n].shortPOS;
		words[n].shortPOS--;
		switch (words[n].shortPOS)
		{
		case 0:
			cout << "Этот глагол правильный? 1. Да | 0. Нет; (Введите выбор): ";
			cin >> words[n].irregularVb;
			words[n].irregularVb = !words[n].irregularVb;
			if (words[n].irregularVb)
			{
				cout << "Введите вторую форму глагола: ";
				cin >> words[n]._2ndVerbForm;
				cout << "Введите третью форму глагола: ";
				cin >> words[n]._3rdVerbForm;
			}
			break;
		case 1:
			cout << "Это существительное исчисляемое? 1. Да | 0. Нет; (Введите выбор): ";
			cin >> words[n].countableNo;
			if (words[n].countableNo)
			{
				cout << "Множественное число этого существительного слово исключение(в английском языке)? 1. Да | 0. Нет; (Введите выбор): ";
				cin >> words[n].isPlural;
				if (words[n].isPlural)
				{
					cout << "Введите множественное число этого существительного(на английском языке): ";
					cin >> words[n].plural;
				}
			}
			break;
		default:
			break;
		}
		cout << "Введите пометки(например: 'для письма'; если пометок нет, введите '-'): ";
		cin.ignore(); cin.getline(words[n].remark, sizeof(words[n].remark));
		words[n].numOfCorAnsw = 0;
		system("cls");
	}

	void delWord(int n)
	{
		for (int i = n; i < sizeOfList; i++)
		{
			words[i] = words[i + 1];
		}
		sizeOfList--;
	}
}