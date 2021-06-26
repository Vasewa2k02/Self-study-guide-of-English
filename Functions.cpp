#include "stdafx.h"

unsigned short sizeOfList = 0, curCorAnsw = 0, allAnsw = 0;
short choice;
char str[100], str2[100];
string path, pathSet, _str;
fstream fDic, fSet;
dictionary::Word words[list_len];
struct Settings settings;
struct Grammar gram;

void start()
{
	path = "Dictionary.txt";
	pathSet = "Settings.txt";

	fDic.open(path, fstream::in);
	if (fDic.is_open() && fDic.getline(str, sizeof(str)))
	{
		sizeOfList = atoi(str);
		for (int i = 0; i < sizeOfList; i++)
		{
			fDic.getline(words[i].engWord, sizeof(words[i].engWord));
			if (fDic.eof() != 0) break;
			fDic.getline(words[i].rusWord, sizeof(words[i].rusWord));
			fDic.getline(str, sizeof(str));
			words[i].shortPOS = atoi(str);
			switch (words[i].shortPOS)
			{
			case 0:
				fDic.getline(str, sizeof(str));
				words[i].irregularVb = atoi(str);
				if (words[i].irregularVb)
				{
					fDic.getline(words[i]._2ndVerbForm, sizeof(words[i]._2ndVerbForm));
					fDic.getline(words[i]._3rdVerbForm, sizeof(words[i]._3rdVerbForm));
				}
				break;
			case 1:
				fDic.getline(str, sizeof(str));
				words[i].countableNo = atoi(str);
				if (words[i].countableNo)
				{
					fDic.getline(str, sizeof(str));
					words[i].isPlural = atoi(str);
					if (words[i].isPlural) fDic.getline(words[i].plural, sizeof(words[i].plural));
				}
				break;
			default:
				break;
			}
			fDic.getline(words[i].remark, sizeof(words[i].remark));
			fDic.getline(str, sizeof(str));
			words[i].numOfCorAnsw = atoi(str);
		}
	}
	fDic.close();

	settings.numForLearned = 4;
	settings.optionLearning = 3;
	settings.amountCompWords = 0;

	fSet.open(pathSet, fstream::in);
	if (fSet.is_open())
	{
		fSet.getline(str, sizeof(str));
		settings.numForLearned = atoi(str);
		fSet.getline(str, sizeof(str));
		settings.optionLearning = atoi(str);
		fSet.getline(str, sizeof(str));
		settings.amountCompWords = atoi(str);
	}
	fSet.close();

	gram.partOfSpeech[0][0] = "verb";
	gram.partOfSpeech[0][1] = "noun";
	gram.partOfSpeech[0][2] = "adjective";
	gram.partOfSpeech[0][3] = "pronoun";
	gram.partOfSpeech[0][4] = "numerals";
	gram.partOfSpeech[0][5] = "adverb";
	gram.partOfSpeech[1][0] = "глагол";
	gram.partOfSpeech[1][1] = "существительное";
	gram.partOfSpeech[1][2] = "прилагательное";
	gram.partOfSpeech[1][3] = "местоимение";
	gram.partOfSpeech[1][4] = "числительное";
	gram.partOfSpeech[1][5] = "наречие";

	gram.pronoun[0][0] = "I";
	gram.pronoun[0][1] = "you";
	gram.pronoun[0][2] = "we";
	gram.pronoun[0][3] = "they";
	gram.pronoun[0][4] = "he";
	gram.pronoun[0][5] = "she";
	gram.pronoun[0][6] = "it";
	gram.pronoun[1][0] = "я";
	gram.pronoun[1][1] = "ты";
	gram.pronoun[1][2] = "мы";
	gram.pronoun[1][3] = "они";
	gram.pronoun[1][4] = "он";
	gram.pronoun[1][5] = "она";
	gram.pronoun[1][6] = "оно";

	gram.auxiliary[0] = "do";
	gram.auxiliary[1] = "does";
	gram.auxiliary[2] = "will";
	gram.auxiliary[3] = "did";

	gram.rusTimes[0] = "являться";
	gram.rusTimes[1] = "буду";
	gram.rusTimes[2] = "был";

	gram.tobe[0] = "am";
	gram.tobe[1] = "are";
	gram.tobe[2] = "is";
	gram.tobe[3] = "be";
	gram.tobe[4] = "was";
	gram.tobe[5] = "were";

	gram._not[0] = "not";
	gram._not[1] = "не";

	gram.a[0] = 'a';
	gram.a[1] = 'an';

	system("cls");
}

void end()
{
	fDic.open(path, fstream::out);
	if (fDic.is_open())
	{
		fDic << sizeOfList << endl;
		for (int i = 0; i < sizeOfList; i++)
		{
			fDic << words[i].engWord << endl;
			fDic << words[i].rusWord << endl;
			fDic << words[i].shortPOS << endl;
			switch (words[i].shortPOS)
			{
			case 0:
				fDic << words[i].irregularVb << endl;
				if (words[i].irregularVb)
				{
					fDic << words[i]._2ndVerbForm << endl;
					fDic << words[i]._3rdVerbForm << endl;
				}
				break;
			case 1:
				fDic << words[i].countableNo << endl;
				if (words[i].countableNo)
				{
					fDic << words[i].isPlural << endl;
					if (words[i].isPlural) fDic << words[i].plural << endl;
				}
				break;
			default:
				break;
			}
			fDic << words[i].remark << endl;
			fDic << words[i].numOfCorAnsw << endl;
		}
	}
	fDic.close();

	fSet.open(pathSet, fstream::out);
	if (fSet.is_open())
	{
		fSet << settings.numForLearned << endl;
		fSet << settings.optionLearning << endl;
		fSet << settings.amountCompWords << endl;
	}
	fSet.close();
}

int comparisonStr(char* word1, char* word2)
{
	int n1 = strlen(word1), n2 = strlen(word2);
	if (n1 == n2 || n1 + 1 == n2)
	{
		for (int i = 0; i < n1; i++)
		{
			if ((word1[i] >= 'A' && word1[i] <= 'Z') || (word1[i] >= 'А' && word1[i] <= 'Я')) word1[i] += 32;
			if ((word2[i] >= 'A' && word2[i] <= 'Z') || (word2[i] >= 'А' && word2[i] <= 'Я')) word2[i] += 32;
			if (word1[i] != word2[i]) return 0;
		}
		if ((n1 == n2) || ((n1 != n2) && (word2[n2 - 1] == '.' || word2[n2 - 1] == '?' || word2[n2 - 1] == '!'))) return 1;
		else return 0;
	}
	else return 0;
}