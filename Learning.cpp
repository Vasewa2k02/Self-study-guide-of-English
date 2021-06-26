#include "stdafx.h"

bool learningWord(char* mainWord, char* secondWord, short numOfWord)
{
	while (true)
	{
		menu_3_1();
		cout << " " << mainWord << " - ";
		cin.getline(str, sizeof(str));
		switch (atoi(str))
		{
		case 1:
			cout << " Пометки: " << words[numOfWord].remark << endl << endl;
			break;

		case 2:
			cout << " Часть речи слова - " << gram.partOfSpeech[1][words[numOfWord].shortPOS] << "(" << gram.partOfSpeech[0][words[numOfWord].shortPOS] << ")" << endl << endl;
			break;

		case 3:
			cout << " Общая статистика: Правильных ответов - " << curCorAnsw << "/" << allAnsw << " | Выучено слов - " << settings.amountCompWords << "/" << sizeOfList << endl << endl;
			break;

		case 0:
			if (str[0] == '0') return 0;
			else
			{
				if (comparisonStr(str, secondWord))
				{
					words[choice].numOfCorAnsw++;
					if (words[choice].numOfCorAnsw == settings.numForLearned) settings.amountCompWords++;
					curCorAnsw++;
					cout << " Верно! Количество верных ответов подряд: " << words[choice].numOfCorAnsw << "/" << settings.numForLearned << endl;
				}
				else
				{
					words[choice].numOfCorAnsw = 0;
					cout << " Вы ввели неверный вариант! Правильно - " << secondWord << endl;
				}
				allAnsw++;
				return 1;
			}
			break;

		default:
			cout << " Этот вариант отсутствует!" << endl << endl;
			break;
		}
		cout << " "; system("pause");
		system("cls");
	}
	return 1;
}

void learningWordCall()
{
	bool work = true;
	curCorAnsw = 0;
	allAnsw = 0;

	cin.ignore();
	while (work)
	{
		if (settings.amountCompWords == sizeOfList)
		{
			cout << " Добавьте слова в словарь!" << endl;
			break;
		}
		else
		{
			do
			{
				choice = rand() % sizeOfList;
			} while (words[choice].numOfCorAnsw == settings.numForLearned);
		}
		switch (settings.optionLearning)
		{
		case 1:
			work = learningWord(words[choice].engWord, words[choice].rusWord, choice);
			break;

		case 2:
			work = learningWord(words[choice].rusWord, words[choice].engWord, choice);
			break;

		case 3:
			if (rand() % 2) work = learningWord(words[choice].engWord, words[choice].rusWord, choice);
			else work = learningWord(words[choice].rusWord, words[choice].engWord, choice);
			break;
		}
		cout << " "; system("pause");
		system("cls");
	}
}

string correctEnding(int idWord, int idPr, int learningTime)
{
	if (!words[idWord].countableNo) return words[idWord].engWord;
	string word = words[idWord].engWord;
	int n = size(word);

	switch (learningTime)
	{
	case 1:
		if (words[idWord].shortPOS == 1)
		{
			if (idPr != 2 && idPr != 3) return words[idWord].engWord;
			if (words[idWord].isPlural) return words[idWord].plural;
		}
		if (word[n - 1] == 's' || word[n - 1] == 'x' || word[n - 1] == 'o' || (word[n - 2] == 's' && word[n - 1] == 's') || (word[n - 2] == 's' && word[n - 1] == 'h') || (word[n - 2] == 'c' && word[n - 1] == 'h'))
		{
			return word = word + "es";
		}
		else if (word[n - 1] == 'y' && (word[n - 2] != 'a' && word[n - 2] != 'e' && word[n - 2] != 'y' && word[n - 2] != 'u' && word[n - 2] != 'i' && word[n - 2] != 'o'))
		{
			word += "es";
			return word.replace(n - 3, 1, "i");
		}
		else if (words[idWord].shortPOS == 1 && (word[n - 1] == 'f' || (word[n - 2] == 'f' && word[n - 1] == 'e')))
		{
			word += "es";
			return word.replace(n - 3, 1, "v");
		}
		else return word += "s";
		break;
	case 3:
		if (words[idWord].irregularVb) return words[idWord]._2ndVerbForm;
		else if (word[n - 1] == 'e') return word += "d";
		else if (word[n - 1] == 'y' && (word[n - 2] != 'a' && word[n - 2] != 'e' && word[n - 2] != 'y' && word[n - 2] != 'u' && word[n - 2] != 'i' && word[n - 2] != 'o'))
		{
			word += "ed";
			return word.replace(n - 3, 1, "i");
		}
		else if (word[n - 1] == 'l') return word += "led";
		else return word += "ed";
		break;
	}
}

void creatingSentence(int n, int idPr, int idVb, int idNo)
{
	string a = (words[idNo].engWord[0] == 'a' || words[idNo].engWord[0] == 'e' || words[idNo].engWord[0] == 'y' || words[idNo].engWord[0] == 'u' || words[idNo].engWord[0] == 'i' || words[idNo].engWord[0] == 'o') ? "an" : "a";
	switch (n)
	{
	case 11:
		if (idPr <= 3) _str = gram.pronoun[0][idPr] + " " + words[idVb].engWord;
		else _str = gram.pronoun[0][idPr] + " " + correctEnding(idVb, idPr, 1);
		break;
	case 12:
		_str = (idPr <= 3) ? gram.auxiliary[0] : gram.auxiliary[1];
		_str += " " + gram.pronoun[0][idPr] + " " + words[idVb].engWord;
		break;
	case 13:
		_str = gram.pronoun[0][idPr] + " ";
		_str += (idPr <= 3) ? gram.auxiliary[0] : gram.auxiliary[1];
		_str += " " + gram._not[0] + " " + words[idVb].engWord;
		break;
	case 14:
		_str = gram.pronoun[0][idPr] + " ";
		_str += (idPr == 0) ? gram.tobe[0] : (idPr >= 1 && idPr <= 3) ? gram.tobe[1] : gram.tobe[2];
		_str += " ";
		if (words[idNo].countableNo && (idPr != 2 && idPr != 3)) _str += a + " ";
		_str += correctEnding(idNo, idPr, 1);
		break;
	case 15:
		_str = (idPr == 0) ? gram.tobe[0] : (idPr >= 1 && idPr <= 3) ? gram.tobe[1] : gram.tobe[2];
		_str += " " + gram.pronoun[0][idPr] + " ";
		if (words[idNo].countableNo && (idPr != 2 && idPr != 3)) _str += a + " ";
		_str += correctEnding(idNo, idPr, 1);
		break;
	case 16:
		_str = gram.pronoun[0][idPr] + " ";
		_str += (idPr == 0) ? gram.tobe[0] : (idPr >= 1 && idPr <= 3) ? gram.tobe[1] : gram.tobe[2];
		_str += " " + gram._not[0];
		if (words[idNo].countableNo && (idPr != 2 && idPr != 3)) _str += " " + a;
		_str += " " + correctEnding(idNo, idPr, 1);
		break;
	case 21:
		 _str = gram.pronoun[0][idPr] + " " + gram.auxiliary[2] + " " + words[idVb].engWord;
		break;
	case 22:
		_str = gram.auxiliary[2] + " " + gram.pronoun[0][idPr] + " " + words[idVb].engWord;
		break;
	case 23:
		_str = gram.pronoun[0][idPr] + " " + gram.auxiliary[2] + " " + gram._not[0] + " " + words[idVb].engWord;
		break;
	case 24:
		_str = gram.pronoun[0][idPr] + " " + gram.auxiliary[2] + " " + gram.tobe[3] + " ";
		if (words[idNo].countableNo && (idPr != 2 && idPr != 3)) _str += a + " ";
		_str += correctEnding(idNo, idPr, 1);
		break;
	case 25:
		_str = gram.auxiliary[2] + " " + gram.pronoun[0][idPr] + " " + gram.tobe[3] + " ";
		if (words[idNo].countableNo && (idPr != 2 && idPr != 3)) _str += a + " ";
		_str += correctEnding(idNo, idPr, 1);
		break;
	case 26:
		_str = gram.pronoun[0][idPr] + " " + gram.auxiliary[2] + " " + gram._not[0] + " " + gram.tobe[3] + " ";
		if (words[idNo].countableNo && (idPr != 2 && idPr != 3)) _str += a + " ";
		_str += correctEnding(idNo, idPr, 1);
		break;
	case 31:
		_str = gram.pronoun[0][idPr] + " " + correctEnding(idVb, idPr, 3);
		break;
	case 32:
		_str = gram.auxiliary[3] + " " + gram.pronoun[0][idPr] + " " + words[idVb].engWord;
		break;
	case 33:
		_str = gram.pronoun[0][idPr] + " " + gram.auxiliary[3] + " " + gram._not[0] + " " + words[idVb].engWord;
		break;
	case 34:
		_str = gram.pronoun[0][idPr] + " ";
		_str += (idPr >= 1 && idPr <= 3) ? gram.tobe[5] : gram.tobe[4];
		_str += " ";
		if (words[idNo].countableNo && (idPr != 2 && idPr != 3)) _str += a + " ";
		_str += correctEnding(idNo, idPr, 1);
		break;
	case 35:
		_str = (idPr >= 1 && idPr <= 3) ? gram.tobe[5] : gram.tobe[4];
		_str += " " + gram.pronoun[0][idPr] + " ";
		if (words[idNo].countableNo && (idPr != 2 && idPr != 3)) _str += a + " ";
		_str += correctEnding(idNo, idPr, 1);
		break;
	case 36:
		_str = gram.pronoun[0][idPr] + " ";
		_str += (idPr >= 1 && idPr <= 3) ? gram.tobe[5] : gram.tobe[4];
		_str += " " + gram._not[0] + " ";
		if (words[idNo].countableNo && (idPr != 2 && idPr != 3)) _str += a + " ";
		_str += correctEnding(idNo, idPr, 1);
		break;
	}
}

void learningGram()
{
	if (settings.amountCompWords == sizeOfList)
	{
		cout << " Добавьте слова в словарь!" << endl;
		return;
	}
	bool pass = 0, pass2 = 0;
	for (int i = 0; i < sizeOfList; i++)
	{
		if (words[i].shortPOS == 0) pass = 1;
		if (words[i].shortPOS == 1) pass2 = 1;
		if (pass && pass2) break;
		if (sizeOfList - 1 == i)
		{
			cout << " Для обучения граматике, в словаре должны быть глаголы и существительные" << endl;
			return;
		}
	}

	int idPr, idVb, idNo;
	curCorAnsw = 0;
	allAnsw = 0;
	int whichTimeLearning = menu_3_2();
	if (!whichTimeLearning) return;
	whichTimeLearning--;
	cin.ignore();

	while (true)
	{
		idPr = rand() % 7;
		do
		{
			idVb = rand() % sizeOfList;
		} while (words[idVb].shortPOS != 0);
		do
		{
			idNo = rand() % sizeOfList;
		} while (words[idNo].shortPOS != 1);

		menu_3_2_1(whichTimeLearning + 1);
		choice = rand() % 6 + 1;
		creatingSentence((whichTimeLearning + 1) * 10 + choice, idPr, idVb, idNo);
		cout << " " << gram.pronoun[1][idPr] << " ";
		switch (choice)
		{
		case 1:
			if (whichTimeLearning != 0) cout << gram.rusTimes[whichTimeLearning] << " ";
			cout << words[idVb].rusWord << " - ";
			break;
		case 2:
			if (whichTimeLearning != 0) cout << gram.rusTimes[whichTimeLearning] << " ";
			cout << words[idVb].rusWord << "? - ";
			break;
		case 3:
			cout << gram._not[1] << " ";
			if (whichTimeLearning != 0) cout << gram.rusTimes[whichTimeLearning] << " ";
			cout << words[idVb].rusWord << " - ";
			break;
		case 4:
			cout << gram.rusTimes[whichTimeLearning] << " " << words[idNo].rusWord << " - ";
			break;
		case 5:
			cout << gram.rusTimes[whichTimeLearning] << " " << words[idNo].rusWord << "? - ";
			break;
		case 6:
			cout << gram._not[1] << " " << gram.rusTimes[whichTimeLearning] << " " << words[idNo].rusWord << " - ";
			break;
		}

		cin.getline(str2, sizeof(str2));
		allAnsw++;
		if (str2[0] == '0')
		{
			system("cls");
			break;
		}
		else
		{
			int n = size(_str);
			for (int i = 0; i < n; i++)
			{
				str[i] = _str[i];
			}
			str[n] = '\0';
			if (comparisonStr(str, str2))
			{
				curCorAnsw++;
				cout << " Верно! Правильных ответов - " << curCorAnsw << "/" << allAnsw << endl;
			}
			else cout << " Не верно! Правильно - " << _str << endl;
			cout << " "; system("pause");
		}
		system("cls");
	}
}