#include <iostream>
using namespace std;

int main()
{
	const int CHARLIMIT = 30, WORDLIMIT = 30;
	char inputString[WORDLIMIT][CHARLIMIT];
	char inputChar = '?';
	int finalWordIndex = 0;

	for (int i = 0; i < WORDLIMIT; i++)
		for (int j = 0; j < CHARLIMIT; j++)
			inputString[i][j] = '-';

	for (int i = 0; i < WORDLIMIT; i++)
		for (int j = 0; j < CHARLIMIT; j++) {
			finalWordIndex = i;
			inputString[i][j] = ' ';
			cin.get(inputChar);
			if (inputChar == '\n')
				goto outOfLoops;
			inputString[i][j] = inputChar;
			if (inputChar == ' ')
				break;
		}
outOfLoops:

	for (int i = 0; i <= finalWordIndex; i++) 
	{
		cout << "[" << i << "]";
		for (int j = 0; inputString[i][j] != '-'; j++)
			cout << inputString[i][j];
	}

	int firstWordIndex, secondWordIndex;

	cout << "\nEnter the numbers for words to swap (x y): ";
	cin >> firstWordIndex >> secondWordIndex;

	for (int j = 0; j < CHARLIMIT; j++) {
		char tempArray[CHARLIMIT];
		tempArray[j] = inputString[firstWordIndex][j];
		inputString[firstWordIndex][j] = inputString[secondWordIndex][j];
		inputString[secondWordIndex][j] = tempArray[j];
	}


	for (int i = 0; i <= finalWordIndex; i++)
		for (int j = 0; inputString[i][j] != '-'; j++)
			cout << inputString[i][j];

	return 0;
}