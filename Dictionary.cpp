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
			cout << gram.partOfSpeech[1][words[i].shortPOS] << "; �������: ";
			cout << words[i].remark << ")" << endl;
		}
	}

	void addWord(int n)
	{
		cout << "������� ��������� ������� �����(��������: 'pen'): ";
		cin.ignore(); cin.getline(words[n].engWord, sizeof(words[n].engWord));
		cout << "������� ������� ������� �����(��������: '�����'): ";
		cin.getline(words[n].rusWord, sizeof(words[n].rusWord));
		cout << "� ����� ����� ���� ��������� ��� �����?" << endl;
		for (int i = 0; i < 6; i++)
		{
			cout << i + 1 << ". " << gram.partOfSpeech[1][i] << endl;
		}
		cout << "(�������� ����) ";
		cin >> words[n].shortPOS;
		words[n].shortPOS--;
		switch (words[n].shortPOS)
		{
		case 0:
			cout << "���� ������ ����������? 1. �� | 0. ���; (������� �����): ";
			cin >> words[n].irregularVb;
			words[n].irregularVb = !words[n].irregularVb;
			if (words[n].irregularVb)
			{
				cout << "������� ������ ����� �������: ";
				cin >> words[n]._2ndVerbForm;
				cout << "������� ������ ����� �������: ";
				cin >> words[n]._3rdVerbForm;
			}
			break;
		case 1:
			cout << "��� ��������������� �����������? 1. �� | 0. ���; (������� �����): ";
			cin >> words[n].countableNo;
			if (words[n].countableNo)
			{
				cout << "������������� ����� ����� ���������������� ����� ����������(� ���������� �����)? 1. �� | 0. ���; (������� �����): ";
				cin >> words[n].isPlural;
				if (words[n].isPlural)
				{
					cout << "������� ������������� ����� ����� ����������������(�� ���������� �����): ";
					cin >> words[n].plural;
				}
			}
			break;
		default:
			break;
		}
		cout << "������� �������(��������: '��� ������'; ���� ������� ���, ������� '-'): ";
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