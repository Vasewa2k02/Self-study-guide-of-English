#pragma once

#include <iostream>
#include <fstream>
#include <ctime>
#include <string>
#include "Dictionary.h"
using namespace std;

extern unsigned short sizeOfList, curCorAnsw, allAnsw;
extern short choice;
extern char str[100], str2[100];
extern string path, pathSet, _str;
extern fstream fDic, fSet;
extern dictionary::Word words[list_len];

struct Settings {
	short numForLearned;
	short optionLearning;
	short amountCompWords;
};
extern struct Settings settings;

struct Grammar {
	string partOfSpeech[2][6];
	string pronoun[2][7];
	string auxiliary[4];
	string rusTimes[3];
	string tobe[6];
	string _not[2];
	string a[2];
};
extern struct Grammar gram;

int menu();
int menu_1();
int menu_2();
int menu_3();
void menu_3_1();
int menu_3_2();
void menu_3_2_1(int time);
int menu_4();
void grammarAid(int a);

void start();
void end();
int comparisonStr(char* word1, char* word2);

void learningWordCall();
void learningGram();
string correctEnding(int idWord, int idPr, int learningTime);
bool learningWord(char* mainWord, char* secondWord, short numOfWord);

