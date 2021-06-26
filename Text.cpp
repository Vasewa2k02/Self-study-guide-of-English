#include "stdafx.h"

int menu()
{
	cout << "\t����:" << endl;
	cout << "1. �������" << endl;
	cout << "2. ����������" << endl;
	cout << "3. �������� ������" << endl;
	cout << "4. ���������" << endl;
	cout << "0. ��������� ������" << endl;
	cout << "(�������� �����) ";
	cin >> choice;
	system("cls");
	return choice;
}

int menu_1()
{
	cout << "\t����:" << endl;
	cout << "1. �������� �����" << endl;
	cout << "2. ���������� �������" << endl;
	cout << "3. ��������� �����" << endl;
	cout << "4. ������� �����" << endl;
	cout << "0. �����" << endl;
	cout << "(�������� �����) ";
	cin >> choice;
	system("cls");
	return choice;
}

int menu_2()
{
	cout << "\t����:" << endl;
	cout << "1. Present Simple" << endl;
	cout << "2. Future Simple" << endl;
	cout << "3. Past Simple" << endl;
	cout << "0. �����" << endl;
	cout << "(�������� �����) ";
	cin >> choice;
	system("cls");
	return choice;
}

int menu_3()
{
	cout << "\t����:" << endl;
	cout << "1. ��������� �����" << endl;
	cout << "2. ����������" << endl;
	cout << "0. �����" << endl;
	cout << "(��������, ��� ������ �����) ";
	cin >> choice;
	system("cls");
	return choice;
}

void menu_3_1()
{
	cout << "\t����:" << endl;
	cout << "1. ���������� ������� �����" << endl;
	cout << "2. ���������� ����� ���� �����" << endl;
	cout << "3. ���������� ����� ����������" << endl;
	cout << "0. ��������� �������� ������" << endl << endl;
	cout << " ������� ������� ���������� ����� ��� ������ ������� ����: " << endl;
}

int menu_3_2()
{
	cout << "\t����:" << endl;
	cout << "1. Present Simple" << endl;
	cout << "2. Future Simple" << endl;
	cout << "3. Past Simple" << endl;
	cout << "0. �����" << endl;
	cout << "(�������� ����� ��� ��������) ";
	cin >> choice;
	system("cls");
	return choice;
}

void menu_3_2_1(int time)
{
	system("cls");
	cout << " ��������� �����: ";
	switch (time)
	{
	case 1:
		cout << "Present Simple";
		break;
	case 2:
		cout << "Future Simple";
		break;
	case 3:
		cout << "Past Simple";
		break;
	}
	cout << endl << endl;
	cout << "\t����:" << endl;
	cout << " 0. ��������� �������� ������" << endl << endl;
	cout << " ������� ������� ���������� �����������(�������� ��������� ����� � ����� ����������������) ��� ������ ����� ����:" << endl;
}

int menu_4()
{
	cout << "\t����:" << endl;
	cout << "1. �������� ���-�� ���������� ����� ��� ������������ ��� �� ������ ���������(������ " << settings.numForLearned << ")" << endl;
	cout << "2. ������� ������� ��������(��� �������)" << endl;
	cout << "0. �����" << endl;
	cout << "(�������� �����) ";
	cin >> choice;
	system("cls");
	return choice;
}

void grammarAid(int a)
{
	switch (a)
	{
	case 1:
		cout << "   ����� Present Simple ���������� �������� � ��������� � ������� ������ �����. ��� ������������� ��� ����������� ����-" << endl;
		cout << " ���, ��������� ������������� ��� ���������� ��������, ��������, ����� �� ������� � ����-���� ���������, ������ ���," << endl;
		cout << " ���������� � �. �., �. �. Present Simple ���������� ��������, ������� ���������� � ��������� �����, �� �� ��������� " << endl;
		cout << " ������ � ������� ����." << endl;
		cout << "   ���������� ������ �� ��������� ����� Present Simple ����� ������ ��������� �� ����� ���������, �� ���� ��������� �" << endl;
		cout << " �������, ������ ��� ������� to. ���� � 3-�� ���� ������������� ����� � ��� ����� ��������� ��������� -s: I work � he" << endl;
		cout << " works. ���� ������ ������������ �� -s, -ss, -sh, -ch, -x, -o, �� � ���� ������������ ��������� -es: I wish � he wishes." << endl;
		cout << " � �������� �� -y � �������������� ��������� ���� ������������ ��������� -es, � -y ���������� �� -i-: I try � he tries." << endl;
		cout << "   ��� ����, ����� ��������� �������������� �����������, ����� ���������� ����� ��������� ��������������� ������: Do you" << endl;
		cout << " like rock?(���� �������� ���?); Does he speak Spanish?(�� ������� ��-��������?)." << endl;
		cout << "   � ������������� ������������ ���� ������������ ��������������� ������ do/does, �� �� ����� ����������, � ����� ���-" << endl;
		cout << " �����. ����� ���� ������������ ������������� ������� not: I do not like black coffee(� �� ����� ������ ����); She does" << endl;
		cout << " not smoke(��� �� �����)." << endl;
		cout << "   ������ to be (����) ������ �������� ��������� � ��� ������������ �� ������� Present Simple ������� �� �����������." << endl;
		cout << " �� ����� 3 ������ �����: am(��� 1-�� ���� ������������� ����� : I), is(��� 3-�� ���� ������������� �����: she/he/it)," << endl;
		cout << " are(��� 1-��, 2-�� � 3-�� ���� �������������� ����� : we/you/they): I am ready � � �����; She is ready � ��� ������;" << endl;
		cout << " We are ready � �� ������." << endl;
		cout << " �����������: I, you, we, they(he, she, it) + verb(+ -s)\tI(you, we, they)(he, she, it) + am(are)(is) + noun" << endl;
		cout << " ������: Do(does) + I, you, we, they(he, she, it) + verb?\tAm(are)(is) + I(you, we, they)(he, she, it) + noun" << endl;
		cout << " ���������: I,you,we,they(he,she,it) + do(does) not + verb\tI(you,we,they)(he,she,it) + am(are)(is) not + noun" << endl << endl;
		break;
	case 2:
		cout << "   Future Simple Tense (��� ������ Future Simple) � ��� ������� ������� ����� � ���������� �����. �� ���������� Future" << endl;
		cout << " Simple, ����� ��������� ������������� � ������� ��� � ��������, ������� ����� ���������� � �� ������� �� �� �����" << endl;
		cout << " ��������. �����, ��� ��������, �����, �������������� � ���������������." << endl;
		cout << "   Future Simple ���������� ��� ������ ������ ���������������� ������� will. �� ������������� �� ����� ������� � ������." << endl;
		cout << " �� �����, ������� �� � 1-� ���� ������������� ����� (I), � 3-� ���� ������������� ����� (She / He / It) ��� �� ��� ����" << endl;
		cout << " ����� �������������� ����� (We / You / They) � �� ���� ������� ����������� ��������������� ������ will." << endl;
		cout << "   ��� ����, ����� ��������� �������������� ����������� � Future Simple � ����� �������� ������ will ����� �����������," << endl;
		cout << " �� ����� ��������� �������� ��� ������� to: I will read - � ���� ������; He will play - �� ����� ������." << endl;
		cout << "   ������������� ����������� ������� Future Simple ���������� ��� ������ ���������� ������� not ����� ����������������" << endl;
		cout << " ������� will: You will not write - �� �� ������ ������;  We will not work - �� �� ����� ������." << endl;
		cout << "   � �������������� ����������� ��������������� ������ will ����������� � ������ �����������, �� ��� ������� ����������" << endl;
		cout << " � ��������� ������ ��� ������� to: Will you buy? - �� ������? Will she call - ��� ��������?" << endl;
		cout << "   ������ ������ to be (am / is / are) � ������� ������� ������� ����������� ����� will be. � �������� ���������� ��� ��" << endl;
		cout << " ���������� ����� ��� �����: Will you be a teacher? - �� ������ ��������? I will be a doctor - � ���� ��������." << endl;
		cout << " She will not be a mother - ��� �� ����� �������" << endl;
		cout << " �����������: I, you, we, they, he, she, it + will + verb\tI, you, we, they, he, she, it + will be + noun" << endl;
		cout << " ������: Will + I, you, we, they, he, she, it + verb?\t\tWill + I, you, we, they, he, she, it + be + noun" << endl;
		cout << " ���������: I, you, we, they, he, she, it + will not + verb\tI, you, we, they, he, she, it + will not be + noun" << endl << endl;
		break;
	case 3:
		cout << "   Past Simple Tense - ��� ������� ��������� �����. �� ������������, ���� ������� ��������� � ������������ ����� �" << endl;
		cout << " ������� � �� ������������ � ���������. Past Simple ��������� �� ������� �������� � �������, ���������� ��� ��������-" << endl;
		cout << " ����� �������� � ������� ��� ������������ ������������� �������� � �������." << endl;
		cout << "   ����� ���������� Past Simple, ����� ���������� ������ ����� �������. � ����������� �������� ��� ���������� �����" << endl;
		cout << " ���������� ��������� �-ed� � ����������, �� ���� � ������������ �������. �� ����� ������ ���������. ���� ������ �����-" << endl;
		cout << " �������� �� �e�, ����������� ������ �d�, ���� ������ ������������� �y�, �� ��� ���������� �� �i� ����� ): to walk �>" << endl;
		cout << " walked; to smile �> smiled; to cry �> cried." << endl;
		cout << "   ������������� � �������������� ����������� � Past Simple �������� � ������� ���������� ����� ���������� ������� ���-" << endl;
		cout << " ���� �to do � did� � ���������� ���������� �������: Did you read? - �� �����? We did not work - �� �� ��������." << endl;
		cout << "   ������ to be (am / is / are) � ������� ��������� ������� ����� ��� �����, ��� ��� �� �������� ������������. ���" << endl;
		cout << " I, he she, it - was; ��� you, we, they - were: I was a teacher - � ��� ��������. Were you a doctor? - �� ��� ��������?" << endl;
		cout << " She was not a mother - ��� �� ���� �����" << endl;
		cout << " �����������: I, you, we, they, he, she, it + verb(2nd form)\tI, he, she, it(you, we, they) + was(were) + noun" << endl;
		cout << " ������: Did + I, you, we, they, he, she, it + verb?\t\tWas(were) + I, he, she, it(you, we, they) + noun" << endl;
		cout << " ���������: I, you, we, they, he, she, it + did not + verb\tI, he, she, it(you, we, they) + was(were) not + noun" << endl << endl;
		break;
	default:
		break;
	}
	cout << " "; system("pause");
	system("cls");
}