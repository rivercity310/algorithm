#include <iostream>
#include <string>
#include <algorithm>
#include <cstring>

#include "Histogram.h"

using namespace std;

char AlphaCount[26] = { 0, };

Histogram::Histogram(string str) {
	this->written = str;
}

void Histogram::put(string putStr) {
	written.append(putStr);
}

void Histogram::putc(char putChar) {
	written.push_back(putChar);
}

void Histogram::print() {
	cout << written << endl;

	// string�� �ҹ���(Ȥ�� �빮��)�� ��ȯ
	transform(written.begin(), written.end(), written.begin(), ::tolower);

	int alphaLength = 0;
	for (int i = 0; i < written.length(); i++) {
		if (isalpha(written[i]) == 2) {
			AlphaCount[(int)written[i] - 97]++;
			alphaLength++;
		}
	}
	cout << "�� ���ĺ� �� " << alphaLength << endl;




	for (int i = 0; i < 26; i++) {
		cout << char(97 + i) << " (" << (int)AlphaCount[i] << ")\t:";
		for (int j = 0; j < AlphaCount[i]; j++) {
			cout << "*";
		}
		cout << endl;
	}
}

void Ex13() {
	Histogram elvisHisto("Wise man say, only fools rush in But I can't help, ");
	elvisHisto.put("falling in love with you");
	elvisHisto.putc('-');
	elvisHisto.put("Elvis Presley");

	elvisHisto.print();
}