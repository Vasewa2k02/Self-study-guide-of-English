#pragma once

#define word_len 30
#define remark_len 60
#define list_len 10000

namespace dictionary
{
	struct Word {
		char engWord[word_len];
		char rusWord[word_len];
		unsigned short shortPOS;
		char remark[remark_len];
		unsigned short numOfCorAnsw : 6;
		bool countableNo;
		bool isPlural;
		char plural[word_len];
		bool irregularVb;
		char _2ndVerbForm[word_len];
		char _3rdVerbForm[word_len];
	};

	void checkDictionary();
	void delWord(int n);
	void addWord(int n);
}